"""
Simplified equation of state
"""

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


def compute_rho(
    T,
    S,
    z,
    lambda1=rn_lambda1,
    lambda2=rn_lambda2,
    rn_a0=rn_a0,
    rn_b0=rn_b0,
    rn_mu1=rn_mu1,
    rn_mu2=rn_mu2,
    rn_nu=rn_nu,
):

    Ta = T - T0
    Sa = S - S0
    rho = (
        rho0
        - rn_a0 * (1 + 0.5 * lambda1 * Ta + rn_mu1 * z) * Ta
        + rn_b0 * (1 - 0.5 * lambda2 * Sa - rn_mu2 * z) * Sa
        - rn_nu * Ta * Sa
    )
    return rho


def compute_b(T, S, z, **kwargs):
    return g * (rho0 - compute_rho(T, S, z, **kwargs)) / rho0


def compute_alpha(
    T, S, z, lambda1=rn_lambda1, rn_a0=rn_a0, rn_mu1=rn_mu1, rn_nu=rn_nu, **_
):
    Ta = T - T0
    Sa = S - S0
    alpha = 1 / rho0 * (rn_a0 * (1 + lambda1 * Ta + rn_mu1 * z) - rn_nu * Sa)
    return alpha


def compute_beta(T, S, z, rn_b0=rn_b0, lambda2=rn_lambda2, rn_mu2=rn_mu2, **_):
    Ta = T - T0
    Sa = S - S0
    beta = 1 / rho0 * rn_b0 * (1 - lambda2 * Sa - rn_mu2 * z)
    return beta
