"""
Simplified equation of state
"""

import xarray as xr
import numpy as np

# Reference values used in NEMO
rn_a0 = 1.655e-1
rn_b0 = 7.6554e-1
rn_lambda1 = 5.9520e-2
rn_lambda2 = 5.4914e-4
rn_nu = 2.4341e-3
rn_mu1 = 1.4970e-4
rn_mu2 = 1.1090e-5
T0 = 10
S0 = 35

rho0 = 1026
g = 9.81
Cp = 3991.86795711963


def compute_rho(
    T,
    S,
    z,
    rn_lambda1=rn_lambda1,
    rn_lambda2=rn_lambda2,
    rn_a0=rn_a0,
    rn_b0=rn_b0,
    rn_mu1=rn_mu1,
    rn_mu2=rn_mu2,
    rn_nu=rn_nu,
):
    """
    Compute the density using the simplified EOS
    """
    Ta = T - T0
    Sa = S - S0
    rho = (
        rho0
        - rn_a0 * (1 + 0.5 * rn_lambda1 * Ta + rn_mu1 * z) * Ta
        + rn_b0 * (1 - 0.5 * rn_lambda2 * Sa - rn_mu2 * z) * Sa
        - rn_nu * Ta * Sa
    )
    return rho


def compute_sigma0(
    T,
    S,
    **kwargs,
):
    """
    compute the density anomaly referenced to the surface
    """
    return compute_rho(T, S, 0, **kwargs) - 1000


def compute_sigma(
    T,
    S,
    z,
    **kwargs,
):
    """
    compute the density anomaly referenced to *z*
    """
    return compute_rho(T, S, z, **kwargs) - 1000


def compute_b(T, S, z, **kwargs):
    """
    Compute the buoyancy
    """
    return g * (rho0 - compute_rho(T, S, z, **kwargs)) / rho0


def compute_alpha(
    T, S, z, rn_lambda1=rn_lambda1, rn_a0=rn_a0, rn_mu1=rn_mu1, rn_nu=rn_nu, **_
):
    """
    Compute the thermal expansion
    """
    Ta = T - T0
    Sa = S - S0
    alpha = 1 / rho0 * (rn_a0 * (1 + rn_lambda1 * Ta + rn_mu1 * z) - rn_nu * Sa)
    return alpha


def compute_beta(T, S, z, rn_b0=rn_b0, rn_lambda2=rn_lambda2, rn_mu2=rn_mu2, **_):
    """
    Compute the haline contraction
    """
    Ta = T - T0
    Sa = S - S0
    beta = 1 / rho0 * rn_b0 * (1 - rn_lambda2 * Sa - rn_mu2 * z)
    return beta


def nemo_wrap(ds, rho=True, b=True, alpha=True, beta=True, sigma=True):
    """
    Using the xarray dataset ds and the common NEMO notations,
    compute all the different analyzes and return a new dataset containing these analyzes.

    If not present, will add a 'p_ref' dimension that contains
    the values of 0, 1000, 2000, 3000 and 4000 dbar, used for the
    potential density, buoyancy, etc.
    """
    nameos = dict(
        rn_lambda1=ds.get("rn_lambda1", default=rn_lambda1),
        rn_lambda2=ds.get("rn_lambda2", default=rn_lambda2),
        rn_a0=ds.get("rn_a0", default=rn_a0),
        rn_b0=ds.get("rn_b0", default=rn_b0),
        rn_mu1=ds.get("rn_mu1", default=rn_mu1),
        rn_mu2=ds.get("rn_mu2", default=rn_mu2),
        rn_nu=ds.get("rn_nu", default=rn_nu),
    )

    T = ds.thetao
    S = ds.so
    z = ds.gdept_0

    out = xr.Dataset()

    if not "p_ref" in ds:
        reference_levels = np.arange(5) * 1000
        p_ref = xr.DataArray(
            reference_levels,
            coords=(reference_levels,),
            dims="p_ref",
            name="reference pressure for the potential quantities",
            attrs={
                "standard_name": "reference_pressure",
                "long_name": "reference pressure",
                "units": "dbar",
            },
        )
        out = out.expand_dims({"p_ref": p_ref})

    if rho:
        out["rho"] = compute_rho(T, S, z=out.p_ref, **nameos)
        out["rho"].attrs.update(
            {
                "standard_name": "potential_density",
                "long_name": "potential density",
                "units": "kg/m3",
            }
        )
    if b:
        out["buoyancy"] = compute_b(T, S, z=out.p_ref, **nameos)
        out["buoyancy"].attrs.update(
            {
                "standard_name": "potential_buoyancy",
                "long_name": "potential buoyancy",
                "units": "m/s2",
            }
        )
    if alpha:
        out["alpha"] = compute_alpha(T, S, z=out.p_ref, **nameos)
        out["alpha"].attrs.update(
            {
                "standard_name": "potential_thermal_expansion",
                "long_name": "potential thermal expansion",
                "units": "1/degC",
            }
        )
    if beta:
        out["beta"] = compute_beta(T, S, z=out.p_ref, **nameos)
        out["beta"].attrs.update(
            {
                "standard_name": "potential_haline_contraction",
                "long_name": "potential haline contraction",
                "units": "1/(g/kg)",
            }
        )
    if sigma:
        out["sigma"] = compute_sigma(T, S, z=out.p_ref, **nameos)
        out["sigma"].attrs.update(
            {
                "standard_name": "potential_density_anomaly",
                "long_name": "potential density anomaly",
                "units": "kg/m3",
            }
        )
    return out
