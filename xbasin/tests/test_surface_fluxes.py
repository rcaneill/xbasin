from math import isclose
import numpy as np
import xbasin.surface_flux as flx
import xarray as xr
from pathlib import Path
import os

TESTPATH = Path(os.path.dirname(os.path.abspath(__file__)))


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


def test_nemo_wrap():
    ds = xr.open_dataset(TESTPATH / "data/nemo_full_dataset.nc")
    ds["alpha"] = 2e-4 * xr.DataArray(data=[1, 1], dims=["p_ref"], coords=[[0, 1000]])
    ds["beta"] = 7e-4
    ds["qt"] = 40  # Need to create new test data
    ds["saltflx"] = -1  # Need to create new test data

    out = flx.nemo_wrap(ds)
    assert "p_ref" not in out.dims

    for i in ["F_b_heat", "F_b_salt", "F_b", "F_b_spicy", "fci"]:
        assert i in out

    assert np.allclose(out["F_b"], out["F_b_heat"] + out["F_b_salt"])
    assert np.allclose(out["F_b_spicy"], out["F_b_heat"] - out["F_b_salt"])
    assert np.allclose(
        out["fci"],
        (out["F_b_heat"] - out["F_b_salt"]) / (out["F_b_heat"] + out["F_b_salt"]),
    )
