from math import isclose

import xbasin.surface_flux as flx


def test_heat():
    """
    Some easy tests, e.g. if q=0 no buoyancy flux
    """
    alpha = 2e-4
    assert isclose(0.0, flx.compute_buoyancy_surface_flux_heat(qt=0, alpha=alpha))
    assert flx.compute_buoyancy_surface_flux_heat(qt=1, alpha=alpha) > 0
    assert flx.compute_buoyancy_surface_flux_heat(qt=-1, alpha=alpha) < 0


def test_salt():
    """
    Some easy tests, e.g. if saltflx=0 no buoyancy flux
    """
    beta = 7e-4
    assert isclose(0.0, flx.compute_buoyancy_surface_flux_salt(saltflx=0, beta=beta))
    assert flx.compute_buoyancy_surface_flux_salt(saltflx=-1, beta=beta) > 0
    assert flx.compute_buoyancy_surface_flux_salt(saltflx=1, beta=beta) < 0
