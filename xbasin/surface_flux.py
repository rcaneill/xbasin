def compute_buoyancy_surface_flux(qt, saltflx, alpha, beta):
    """
    Return the surface buoyancy flux
    """
    F_b = compute_buoyancy_surface_flux_heat(
        qt, alpha
    ) + compute_buoyancy_surface_flux_salt(saltflx, beta)
    return F_b


def compute_buoyancy_surface_flux_heat(qt, alpha):
    """
    Return the buoyancy flux induced by the heat flux
    """
    F_b_heat = g / rho0 * alpha / Cp * qt


def compute_buoyancy_surface_flux_salt(saltflx, beta):
    """
    Return the buoyancy flux induced by the salt flux
    """
    F_b_salt = -g / rho0 * beta * saltflx
