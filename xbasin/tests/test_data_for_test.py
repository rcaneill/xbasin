import os
from pathlib import Path

TESTPATH = Path(os.path.dirname(os.path.abspath(__file__)))

import xarray as xr


def test_t_and_s_are_present():
    ds = xr.open_dataset(TESTPATH / "data/nemo_full_dataset.nc")
    assert "thetao" in ds
    assert "so" in ds


def test_depth_present():
    ds = xr.open_dataset(TESTPATH / "data/nemo_full_dataset.nc")
    assert "gdept_0" in ds
