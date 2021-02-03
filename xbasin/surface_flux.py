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
