import xarray as xr

rho0 = 1026
g = 9.81
Cp = 3991.86795711963


def compute_buoyancy_surface_flux_heat(qt, alpha):
    """
    Return the buoyancy flux induced by the heat flux
    """
    F_b_heat = g / rho0 * alpha / Cp * qt
    return F_b_heat


def compute_buoyancy_surface_flux_salt(saltflx, beta):
    """
    Return the buoyancy flux induced by the salt flux
    """
    F_b_salt = -g / rho0 * beta * saltflx
    return F_b_salt


def compute_buoyancy_surface_flux(qt, saltflx, alpha, beta):
    """
    Return the surface buoyancy flux
    """
    F_b = compute_buoyancy_surface_flux_heat(
        qt, alpha
    ) + compute_buoyancy_surface_flux_salt(saltflx, beta)
    return F_b


def compute_buoyancy_spicyness_surface_flux(qt, saltflx, alpha, beta):
    """
    Return the surface buoyancy 'spicyness' flux F_b_heat - F_b_salt
    """
    F_b_spicy = compute_buoyancy_surface_flux_heat(
        qt, alpha
    ) - compute_buoyancy_surface_flux_salt(saltflx, beta)
    return F_b_spicy


def compute_fci(qt, saltflx, alpha, beta):
    """
    Compute the forcing control index defined as:

    fci = (F_b_heat - F_b_salt) / (F_b_heat + F_b_salt)
    """
    fci = (
        compute_buoyancy_surface_flux_heat(qt, alpha)
        - compute_buoyancy_surface_flux_salt(saltflx, beta)
    ) / (
        compute_buoyancy_surface_flux_heat(qt, alpha)
        + compute_buoyancy_surface_flux_salt(saltflx, beta)
    )
    return fci


def nemo_wrap(ds, heat=True, salt=True, b=True, spicyness=True, fci=True):
    """
    Using the xarray dataset ds and the common NEMO notations,
    compute all the different analyzes and return a new dataset containing these analyzes.
    """
    out = xr.Dataset()

    qt = ds["qt"]
    alpha = ds["alpha"]
    if "p_ref" in alpha.dims:
        alpha = alpha.isel(p_ref=0)
    saltflx = ds["saltflx"]
    beta = ds["beta"]
    if "p_ref" in beta.dims:
        beta = beta.isel(p_ref=0)

    if heat:
        out["F_b_heat"] = compute_buoyancy_surface_flux_heat(qt, alpha)
        out["F_b_heat"].attrs.update(
            {
                "standard_name": "surface_buoyancy_flux_heat",
                "long_name": "surface buoyancy flux due to heat",
                "units": "m2/s",
            }
        )
    if salt:
        out["F_b_salt"] = compute_buoyancy_surface_flux_salt(saltflx, beta)
        out["F_b_salt"].attrs.update(
            {
                "standard_name": "surface_buoyancy_flux_salt",
                "long_name": "surface buoyancy flux due to salt",
                "units": "m2/s",
            }
        )
    if b:
        out["F_b"] = compute_buoyancy_surface_flux(qt, saltflx, alpha, beta)
        out["F_b"].attrs.update(
            {
                "standard_name": "surface_buoyancy_flux",
                "long_name": "surface buoyancy flux",
                "units": "m2/s",
            }
        )
    if spicyness:
        out["F_b_spicy"] = compute_buoyancy_spicyness_surface_flux(
            qt, saltflx, alpha, beta
        )
        out["F_b_spicy"].attrs.update(
            {
                "standard_name": "surface_buoyancy_flux_spicy",
                "long_name": "surface buoyancy flux due to spicyness",
                "units": "m2/s",
            }
        )
    if fci:
        out["fci"] = compute_fci(qt, saltflx, alpha, beta)
        out["fci"].attrs.update(
            {
                "standard_name": "forcing_control_index",
                "long_name": "forcing control index",
                "units": "",
            }
        )
    return out
