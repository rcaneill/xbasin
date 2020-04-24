# TODO docstrings

import xarray as xr
import numpy as np
from ._interpolation import interp_new_vertical

"""
For the moment will maybe only work with the NEMO output data
=> To be adapted to a general case later
"""


def _add_dims(z_fr, z_to):
    dims_fr = set(z_fr.dims)
    dims_to = set(z_to.dims)

    if dims_fr == dims_to:
        return (z_fr, z_to)

    # take all dims that are in z_to but not in z_fr
    for dim in dims_to - dims_fr:
        z_fr = z_fr.expand_dims({dim: z_to[dim]})
    # take all dims that are in z_fr but not in z_to
    for dim in dims_fr - dims_to:
        z_to = z_to.expand_dims({dim: z_fr[dim]})
    return (z_fr, z_to)


def remap_vertical(
    da,
    grid_fr,
    grid_to,
    axis="Z",
    scale_factor_fr=None,
    scale_factor_to=None,
    z_fr=None,
    z_to=None,
):
    """
    Interpolate the dataset on the new grid grid dept_1d, only for T point vars for the moment


    Parameters
    ----------
    scale_factor_fr: None or dataarray
        If None, will use the scale factor from grid_fr => constant scale factors in time
        If a dataarray, will use it for the integration
    """
    # 1. integrate on W points
    # 2. interpolate on the W points of the new grid
    # 3. Differenciate on the T points of the new grid

    if axis != "Z":
        raise (
            NotImplementedError(
                "Only interpolation along the 'Z' axis is implemented yet"
            )
        )

    if not isinstance(da, xr.core.dataarray.DataArray):
        raise (
            TypeError(
                "da must be a xarray.DataArray, {} is not allowed".format(type(da))
            )
        )

    if z_fr is None:
        z_fr = grid_fr._ds["gdepw_0"]
    if z_to is None:
        z_to = grid_to._ds["gdepw_0"]

    # add dimensions if necessary, so they match
    (z_fr, z_to) = _add_dims(z_fr, z_to)

    ax = grid_fr.axes[axis]
    (position_fr, coord_nme_fr) = ax._get_axis_coord(da)  # e.g. ('center', 'z_c')
    if position_fr != "center":
        raise (
            NotImplementedError(
                "Only interpolation from T, U, and V points is possible for now"
            )
        )

    # pos_nme_fr = xgcm_tools.mtc_nme(coord_nme_fr)  # e.g. 'z_c_pos'
    position_intermediate = ax._default_shifts[position_fr]  # e.g. 'left' W point
    coord_nme_intermediate = ax.coords[position_intermediate]  # e:g. 'z_f'
    # pos_nme_intermediate = xgcm_tools.mtc_nme(coord_nme_intermediate)  # e.f. 'z_f_pos'

    ##############################
    #   Integration
    ##############################
    # TODO use xgcm integration cumsum
    # integration => will shift the position of the coordinate          # e.g. fr 'center' to 'left'
    # e.g. 'z_c_dif' e3t scale factor
    # Should use the xgcm internal way to get the metrics
    if scale_factor_fr is None:
        scale_factor_fr = grid_fr.get_metric(array=da, axes=axis)
    if scale_factor_to is None:
        scale_factor_to = grid_to.get_metric(array=da, axes=axis)
    da_integrate = integrate(
        da=da,
        grid=grid_fr,
        scale_factor=scale_factor_fr,
        axis=axis,
        position_fr=position_fr,
        position_to=position_intermediate,
    )
    # print('*********', da_integrate.isel({'x_c':0,'y_c':0}))

    ##############################
    #   Interpolation
    ##############################
    # interpolation : no position shifting                              # e.g. stay at 'left'

    da_interpolate = interpolate(
        da_fr=da_integrate, z_fr=z_fr, z_to=z_to, coord_nme=coord_nme_intermediate,
    )
    # print('*********', da_interpolate.isel({'x_c':0,'y_c':0}))

    ##############################
    # Derivation
    ##############################
    # TODO use xgcm derivative
    # differentiation => shift the position of the coordinate
    # e.g. from 'left' back to 'center'
    # e.g. 'z_c_diff' e3t scale factor
    """
    scale_factor_nme = xgcm_tools.mtc_nme(coord_nme_fr, diff=True)
    scale_factor = grid_to._ds[scale_factor_nme]
    """
    # scale_factor = grid_to._ds[e3t_0]
    # here positions will be inverted because we go back on the initial position
    # print('------', scale_factor.isel({'x_c':0,'y_c':0}))
    da_derivative = derivative(
        da=da_interpolate,
        grid=grid_to,
        scale_factor=scale_factor_to,
        axis=axis,
        position_fr=position_intermediate,
        position_to=position_fr,
    )
    da_derivative.name = da.name
    # print('!!!!!!!!',da_derivative.isel({'x_c':0,'y_c':0}))
    return da_derivative.transpose(*da.dims, transpose_coords=False)


def interpolate(da_fr, z_fr, z_to, coord_nme):
    """
    Compute the linear interpolation of *da* on the new vertical coordinates.

    Parameters
    ---------
    da_fr : xarray.DataArray
        The data to interpolate
    coords_fr / coords_to : empty dataset with all coordinates
        Contain the physical position of the old / new coordinates
    axis_nme_fr : str
        The coordinate base for the interpolation (axisension of *da*). A dimension
        coord_fr+"_pos" must be provided in *coords_fr*. This coordinate contains the physical position
        of the coordinate (e.g. coord_fr can contain integers, representing the number
        of the points, and coord_fr+"_pos" will contain there position along an axis in meters)
    axis_nme_to : str
        coordinate where to go
    """
    ####################
    #   Initialisation
    ####################

    # For the call of interp_new_vertical, we need to shape the arrays as:
    # z_old : (z, y, x   )
    # z_new : (z, y, x   )
    # v_old : (z, y, x, t)
    # At least, we need to have z as first dimension and all extra dimensions at the end

    # arrays z_fr and z_to
    if len(z_fr.dims) != 3 or len(z_to.dims) != 3:
        raise (ValueError("The vertical coordinates must be 3D (x, y, z) arrays"))
    # transpose the arrays in the order (z, y, x)

    dims_fr = list(z_fr.dims)
    dims_to = list(z_to.dims)
    dims_fr.sort()
    dims_to.sort()
    # dims_fr and dims_to should be the same
    if dims_fr != dims_to:
        raise (
            ValueError(
                f"The dimensions of the coordinates from and to should match. Got {dims_fr} and {dims_to}"
            )
        )
    # remove coord_nme from the dims
    dims_fr.remove(coord_nme)
    dims_fr.insert(0, coord_nme)

    z_fr = z_fr.transpose(*dims_fr, transpose_coords=False)
    z_to = z_to.transpose(*dims_fr, transpose_coords=False)

    # gets coords of da_fr that are not present in dims_fr
    coords_da_fr = [i for i in da_fr.coords if i not in dims_fr]
    da_fr = da_fr.transpose(*dims_fr, *coords_da_fr, transpose_coords=False)
    # We have the 3 necessary arrays:
    # z_fr, z_to, and da_fr
    # we interpolate
    v_to = interp_new_vertical(z_fr.values, z_to.values, da_fr.values)

    # we create a new dataset containing the interpolated values
    # dropping all coordinates of da_fr that are not necessary
    """
    for coord in da_fr.coords.keys():
        if coord not in da_fr.dims:
            da_fr = da_fr.drop(coord)
    """

    da_to = xr.DataArray(
        data=v_to,
        coords=[
            *[(i, z_to.coords[i]) for i in dims_fr],
            *[(i, da_fr.coords[i]) for i in coords_da_fr],
        ],
        attrs=da_fr.attrs,
        name=da_fr.name,
    )

    return da_to


def integrate(da, grid, scale_factor, axis, position_fr, position_to):
    """
    Integrate *da* as a cumsum
    """
    # Goal : find which boundary condition wee need
    #    from T to W point => boundary='fill', fill_value = 0
    #    from W to T point => boundary='extend'   => so the derivative on the T earth points will be 0
    if (position_fr, position_to) == ("center", "left"):
        # T to W point
        boundary = "fill"
        fill_value = 0
    elif (position_fr, position_to) == ("left", "center"):
        # W to T point
        boundary = "extend"
        fill_value = None
    else:
        raise (
            NotImplementedError(
                "Boundary conditions for {} are not implemented yet.".format(
                    (position_fr, position_to)
                )
            )
        )
    return grid.cumsum(
        da * scale_factor, axis, boundary=boundary, fill_value=fill_value
    )


def derivative(da, grid, scale_factor, axis, position_fr="left", position_to="center"):
    """
    Take the derivative of *da* as a finite difference
    """
    # from W to T : 'fill', 0
    # from T to W : 'fill', first value at T point
    if (position_fr, position_to) == ("center", "left"):
        # T to W point
        # boundary is on the surface W point
        boundary = "fill"
        # we add a 0 to make the difference (because the integral starts from 0 at the surface)
        fill_value = 0
    elif (position_fr, position_to) == ("left", "center"):
        # W to T point
        # boundary is on the last earth T point
        boundary = "extend"
        fill_value = None
    else:
        raise (
            NotImplementedError(
                "Boundary conditions for {} are not implemented yet.".format(
                    (position_fr, position_to)
                )
            )
        )
    return grid.diff(da, axis, boundary=boundary, fill_value=fill_value) / scale_factor
