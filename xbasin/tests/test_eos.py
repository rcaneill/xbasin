import os
from pathlib import Path

TESTPATH = Path(os.path.dirname(os.path.abspath(__file__)))

from math import isclose
import numpy as np

import xbasin.eos as eos
import xarray as xr


def test_default_values():
    """
    Tests that default values seem to have a physical meaning,
    e.g. rho decreases with T, increases with S
    """
    T_ref = 10
    S_ref = 35

    assert isclose(eos.compute_rho(T=T_ref, S=S_ref, z=0), 1026)

    all_T = np.linspace(-1, 30, 10)
    all_S = np.linspace(31, 37, 10)

    for (t1, t2) in zip(all_T[:-1], all_T[1:]):
        # t1 < t2
        assert eos.compute_rho(T=t1, S=S_ref, z=0) > eos.compute_rho(T=t2, S=S_ref, z=0)
    for (s1, s2) in zip(all_S[:-1], all_S[1:]):
        # s1 < s2
        assert eos.compute_rho(T=T_ref, S=s1, z=0) < eos.compute_rho(T=T_ref, S=s2, z=0)

    # alpha should increase with the temperature
    for (t1, t2) in zip(all_T[:-1], all_T[1:]):
        # t1 < t2
        assert eos.compute_alpha(T=t1, S=S_ref, z=0) < eos.compute_alpha(
            T=t2, S=S_ref, z=0
        )


def test_nemo_wrap():
    ds = xr.open_dataset(TESTPATH / "data/nemo_full_dataset.nc")
    # without the namelist
    assert "rn_lambda1" not in ds
    assert "rn_lambda2" not in ds
    assert "rn_a0" not in ds
    assert "rn_b0" not in ds
    assert "rn_mu1" not in ds
    assert "rn_mu2" not in ds
    assert "rn_nu" not in ds

    out = eos.nemo_wrap(ds)
    assert "p_ref" in out.dims

    assert "rho" in out
    assert np.allclose(out.rho, eos.compute_rho(ds.thetao, ds.so, out.p_ref))

    assert "buoyancy" in out
    assert np.allclose(out.buoyancy, eos.compute_b(ds.thetao, ds.so, out.p_ref))

    assert "alpha" in out
    assert np.allclose(out.alpha, eos.compute_alpha(ds.thetao, ds.so, out.p_ref))

    assert "beta" in out
    assert np.allclose(out.beta, eos.compute_beta(ds.thetao, ds.so, out.p_ref))

    assert "sigma" in out
    assert np.allclose(out.sigma, eos.compute_sigma(ds.thetao, ds.so, out.p_ref))
