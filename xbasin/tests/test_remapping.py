import xarray as xr
import xgcm
from xbasin import remap_vertical
import numpy as np
import warnings

_error = 1e-10
_metrics = {
    ("X",): ["e1t", "e1u", "e1v", "e1f"],  # X distances
    ("Y",): ["e2t", "e2u", "e2v", "e2f"],  # Y distances
    ("Z",): ["e3t_0", "e3u_0", "e3v_0", "e3f_0", "e3w_0"],  # Z distances
}


def warning0(fr, to, error):
    N0 = (to != fr).sum().data
    N1 = (to == fr).sum().data
    m = np.abs(to - fr).max().data
    w0 = f"Number of points that are not equal: {N0}, maximum value of the absolute difference: {m}"
    w1 = f"Number of points that are     equal: {N1}"
    w2 = (
        f"v_to not perfectly equal to v_fr, testing with an authorized error of {error}"
    )
    warnings.warn(w2 + "\n" + w0 + "\n" + w1)


def _assert_same_domcfg(v_fr, v_to, error=_error):
    try:
        assert (v_to == v_fr).all()
    except AssertionError:
        warning0(v_fr, v_to, error=error)
        assert (v_to - v_fr < error).all()


def _assert_same_integrated_value(v_fr, v_to, e3_fr, e3_to, error=_error):
    int_fr = (v_fr * e3_fr).sum(dim="z_c")
    int_to = (v_to * e3_to).sum(dim="z_c")
    print(int_to)
    print(int_fr)
    # import matplotlib.pyplot as plt
    # (int_fr-int_to).plot()
    # plt.show()
    try:
        assert (int_to == int_fr).all()
    except AssertionError:
        warning0(int_fr, int_to, error=error)
        assert (int_to - int_fr < error).all()


def open_domcfg_to():
    domcfg_to = xr.open_dataset("data/xnemogcm.domcfg_to.nc")
    return domcfg_to


def open_domcfg_fr():
    domcfg_fr = xr.open_dataset("data/xnemogcm.domcfg_fr.nc")
    domcfg_fr.load()
    # correct error in domcfg
    domcfg_fr["gdept_0"] = domcfg_fr["gdept_0"].transpose("x_c", "y_c", "z_c")
    domcfg_fr["gdept_0"][0] = domcfg_fr["gdept_0"][1]
    domcfg_fr["gdept_0"][-1] = domcfg_fr["gdept_0"][-2]
    domcfg_fr["gdept_0"][:, 0] = domcfg_fr["gdept_0"][:, 1]
    domcfg_fr["gdept_0"][:, -1] = domcfg_fr["gdept_0"][:, -2]
    domcfg_fr["gdepw_0"] = domcfg_fr["gdepw_0"].transpose("x_c", "y_c", "z_f")
    domcfg_fr["gdepw_0"][0] = domcfg_fr["gdepw_0"][1]
    domcfg_fr["gdepw_0"][-1] = domcfg_fr["gdepw_0"][-2]
    domcfg_fr["gdepw_0"][:, 0] = domcfg_fr["gdepw_0"][:, 1]
    domcfg_fr["gdepw_0"][:, -1] = domcfg_fr["gdepw_0"][:, -2]
    domcfg_fr["e3w_0"] = domcfg_fr["e3w_0"].transpose("x_c", "y_c", "z_f")
    domcfg_fr["e3w_0"][0] = domcfg_fr["e3w_0"][1]
    domcfg_fr["e3w_0"][-1] = domcfg_fr["e3w_0"][-2]
    domcfg_fr["e3w_0"][:, 0] = domcfg_fr["e3w_0"][:, 1]
    domcfg_fr["e3w_0"][:, -1] = domcfg_fr["e3w_0"][:, -2]
    return domcfg_fr


def test_T_0_same_fr_and_to():
    domcfg_fr = open_domcfg_fr()

    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = domcfg_fr

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["thetao"] * 0 * domcfg_fr.tmask
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3t_0,
        scale_factor_to=domcfg_to.e3t_0,
    )
    _assert_same_domcfg(v_fr, v_to)


def test_W_0_same_fr_and_to():
    domcfg_fr = open_domcfg_fr()

    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = domcfg_fr

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["woce"] * 0
    try:
        v_to = remap_vertical(
            v_fr,
            grid_fr,
            grid_to,
            axis="Z",
            scale_factor_fr=domcfg_fr.e3t_0,
            scale_factor_to=domcfg_to.e3t_0,
        )
    except NotImplementedError:
        return 0
    _assert_same_domcfg(v_fr, v_to)


def test_T_0():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["thetao"] * 0 * domcfg_fr.tmask
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3t_0,
        scale_factor_to=domcfg_to.e3t_0,
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3t_0, e3_to=domcfg_to.e3t_0
    )


def create_depth_from_e3(domcfg, grid, point="T"):
    depthw = grid.cumsum(domcfg.e3t_0, axis="Z", boundary="fill", fill_value=0)
    depthuw = grid.cumsum(domcfg.e3u_0, axis="Z", boundary="fill", fill_value=0)
    depthvw = grid.cumsum(domcfg.e3v_0, axis="Z", boundary="fill", fill_value=0)
    depthfw = grid.cumsum(domcfg.e3f_0, axis="Z", boundary="fill", fill_value=0)
    #
    deptht = grid.cumsum(
        domcfg.e3w_0, axis="Z", boundary="fill", fill_value=0
    ) - 0.5 * domcfg.e3w_0.isel({"z_f": 0})
    print(deptht)
    print(np.abs((deptht - domcfg.gdept_0)[:, 1:-1, 1:-1]).max())
    sdfg


def test_U_0():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["uo"] * 0
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3u_0,
        scale_factor_to=domcfg_to.e3u_0,
        z_fr=grid_fr.interp(domcfg_fr.gdepw_0, "X", boundary="extend"),
        z_to=domcfg_to.gdepw_0.isel({"x_c": 1, "y_c": 1}).drop_vars(["x_c", "y_c"]),
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3u_0, e3_to=domcfg_to.e3u_0
    )


def test_U_1():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["uo"] * 1
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3u_0,
        scale_factor_to=domcfg_to.e3u_0,
        z_fr=grid_fr.interp(domcfg_fr.gdepw_0, "X", boundary="extend"),
        z_to=domcfg_to.gdepw_0.isel({"x_c": 1, "y_c": 1}).drop_vars(["x_c", "y_c"]),
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3u_0, e3_to=domcfg_to.e3u_0
    )


def test_U():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["uo"]
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3u_0,
        scale_factor_to=domcfg_to.e3u_0,
        z_fr=grid_fr.interp(domcfg_fr.gdepw_0, "X", boundary="extend"),
        z_to=domcfg_to.gdepw_0.isel({"x_c": 1, "y_c": 1}).drop_vars(["x_c", "y_c"]),
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3u_0, e3_to=domcfg_to.e3u_0
    )


def test_T_1_auto_get_scale_factor_to():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False, metrics=_metrics)

    v_fr = (nemo_ds["thetao"] * 0 + 1) * domcfg_fr.tmask
    v_to = remap_vertical(
        v_fr, grid_fr, grid_to, axis="Z", scale_factor_fr=domcfg_fr.e3t_0
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3t_0, e3_to=domcfg_to.e3t_0
    )


def test_T_1():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = (nemo_ds["thetao"] * 0 + 1) * domcfg_fr.tmask
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3t_0,
        scale_factor_to=domcfg_to.e3t_0,
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3t_0, e3_to=domcfg_to.e3t_0
    )


def test_T_theta():
    domcfg_fr = open_domcfg_fr()
    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = open_domcfg_to()

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["thetao"] * domcfg_fr.tmask
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3t_0,
        scale_factor_to=domcfg_to.e3t_0,
    )
    _assert_same_integrated_value(
        v_fr, v_to, e3_fr=domcfg_fr.e3t_0, e3_to=domcfg_to.e3t_0
    )


def test_T_1_same_fr_and_to():
    domcfg_fr = open_domcfg_fr()

    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = domcfg_fr

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = (nemo_ds["thetao"] * 0 + 1) * domcfg_fr.tmask
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3t_0,
        scale_factor_to=domcfg_to.e3t_0,
    )
    _assert_same_domcfg(v_fr, v_to)


def test_T_theta_same_fr_and_to():
    domcfg_fr = open_domcfg_fr()

    nemo_ds = xr.open_dataset("data/xnemogcm.nemo.nc")
    nemo_ds.load()
    domcfg_to = domcfg_fr

    grid_fr = xgcm.Grid(domcfg_fr, periodic=False)
    grid_to = xgcm.Grid(domcfg_to, periodic=False)

    v_fr = nemo_ds["thetao"] * domcfg_fr.tmask
    v_fr.data = v_fr.data.astype(np.float16)
    v_fr.data = v_fr.data.astype(np.float128)
    v_to = remap_vertical(
        v_fr,
        grid_fr,
        grid_to,
        axis="Z",
        scale_factor_fr=domcfg_fr.e3t_0,
        scale_factor_to=domcfg_to.e3t_0,
    )

    _assert_same_domcfg(v_fr, v_to)


if __name__ == "__main__":
    pass
