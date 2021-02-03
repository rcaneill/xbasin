import numpy as np
import xarray as xr


def compute_moc(v, grid, X="X", Z="Z"):
    psi = _compute_moc_with_v_at_cst_depth(v, grid, X="X", Z="Z")
    return psi


def _compute_moc_with_v_at_cst_depth(v, grid, X="X", Z="Z"):
    """
    Compute the meridional overturning streamfunction.
    """
    v_x_dx = grid.integrate(v, axis=X)  # (vo_to * domcfg_to['y_f_dif']).sum(dim='x_c')
    # integrate from top to bot
    psi = grid.cumint(v_x_dx, axis=Z, boundary="fill", fill_value=0) * 1e-6
    # convert -> from bot to top
    psi = psi - psi.isel({grid.axes[Z]._get_axis_coord(psi)[1]: -1})
    return psi


def _compute_moc_in_density_coordinates(v, rho, density_levels, grid, X="X", Z="Z"):
    """
    Compute the meridional overturning streamfunction in density coordinates.

    $$\psi_{C y}=- \iint_{C^{\prime} \geq C} v d x d z$$

    Arguments
    ---------
    v : xarray.DataArray
        meridional (along y) velocity field
    rho : xarray.DataArray
        density field (e.g. sigma0, sigma1, in situ density, etc), *must* be situated at the same
        point as the velocity field (e.g. V point instead of T point).
        rho must increase with depth (it can be constant, but never decrease) => be careful with regards of thermobaric effects.
    density_levels : 1-D xarray.DataArray
        the density levels (1 dimension, along vertical), e.g. 100 levels between 21 and 28
        The vertical coordinate must have the same name than the *rho* vertical coordinate and be
        at the same grid position
    grid : xgcm.Grid
        the grid used for the calculations
    X : str (default 'X')
        the name of the zonal axis
    Z : str (default 'Z')
        the name of the vertical axis
    """
    mask = rho >= density_levels
    psi = -grid.integrate(grid.integrate(v * mask, axis=Z), axis=X) * 1e-6
    return psi


def create_density_grid(ds, s_min=None, s_max=None, dd=0.05, rho=None):
    """
    Create the density axis

    If s_min and s_max are not provided, you can provide rho to compute them.
    """
    if s_min is None or s_max is None:
        if rho is None:
            s_min = 20
            s_max = 40
        else:
            rhomax = rho.max()
            s_min = np.int(xr.where(rho < 18, rhomax, rho).min())
            s_max = np.int(rhomax) + 1

    # Vertical (density)
    N = np.floor((s_max - s_min) / dd) + 1

    s_c = np.arange(N)
    s_c = xr.DataArray(s_c, coords=[("s_c", s_c)])
    s_c.attrs = ds.z_c.attrs
    s_c.attrs["axis"] = "S"
    s_f = np.arange(N) - 0.5
    s_f = xr.DataArray(s_f, coords=[("s_f", s_f)])
    s_f.attrs = ds.z_f.attrs
    s_f.attrs["axis"] = "S"

    grhot_0 = s_c * dd + s_min
    grhow_0 = s_f * dd + s_min

    e3t_1d = xr.DataArray(dd)
    e3w_1d = xr.DataArray(dd)

    ds["e3t_s_1d"] = e3t_1d
    ds["e3w_s_1d"] = e3w_1d
    ds["grhot_0"] = grhot_0
    ds["grhow_0"] = grhow_0
    ds["s_c"] = s_c
    ds["s_f"] = s_f

    return ds


def compute_zonal_mean_depth_isopycnal(
    rho, density_levels, depth, grid, X="X", z_c="z_c", s_f="s_f"
):
    max_index = rho.coords[z_c].shape[0] - 1  # start at 0

    mean_depth_isopycnal = (
        density_levels * grid.average(rho, axis=X).min(dim=z_c) * np.NaN
    )  # dirty way of doing

    for (i, sigma) in enumerate(density_levels):
        rho_less_sigma = rho <= sigma
        upper_t_point_index = xr.where(
            rho_less_sigma.sum(dim=z_c) > max_index,
            max_index,
            rho_less_sigma.sum(dim=z_c),
        )
        upper_t_point_index = xr.where(
            sigma < rho.isel({z_c: slice(None, -1)}).min(dim=z_c),
            0,
            upper_t_point_index,
        )
        upper_t_point_index = xr.where(
            sigma > rho.isel({z_c: slice(None, -1)}).max(dim=z_c),
            max_index,
            upper_t_point_index,
        )

        rho_greater_sigma = rho >= sigma
        lower_t_point_index = xr.where(
            max_index - rho_greater_sigma.sum(dim=z_c) < 0,
            0,
            max_index - rho_greater_sigma.sum(dim=z_c),
        )
        lower_t_point_index = xr.where(
            sigma < rho.isel({z_c: slice(None, -1)}).min(dim=z_c),
            0,
            lower_t_point_index,
        )
        lower_t_point_index = xr.where(
            sigma > rho.isel({z_c: slice(None, -1)}).max(dim=z_c),
            max_index,
            lower_t_point_index,
        )

        depth_up = depth.isel({z_c: upper_t_point_index})
        depth_down = depth.isel({z_c: lower_t_point_index})

        mean_depth_isopycnal[{s_f: i}] = grid.average(
            (depth_up + depth_down) / 2, axis=X
        )
    return mean_depth_isopycnal


def compute_barotropic_stream_function(u, grid, Y="Y", Z="Z"):
    u_barotropic = grid.integrate(u, axis=Z)
    psi = grid.cumint(-u_barotropic, axis=Y) * 1e-6
    psi = psi - psi[{"y_f": -1}]
    psi.attrs.update(
        {
            "long_name": "barotropic stream function",
            "standard_name": "barotropic_stream_function",
            "units": "Sv",
        }
    )
    return psi
