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
    
    $$\psi_{C y}=\iint_{C^{\prime} \leq C} v d x d z$$

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
    mask = rho <= density_levels
    psi = grid.integrate(grid.integrate(v * mask, axis=Z), axis=X) * 1e-6
    return psi


def create_density_grid(ds, s_min=23, s_max=28, dd=0.05):
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
