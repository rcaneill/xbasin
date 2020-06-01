"""
Simplified equation of state
"""

a0 = 1.655e-1
b0 = 7.6554e-1
l1 = 5.9520e-2
l2 = 0  # 5.4914e-4
nu = 0  # 2.4341e-3
mu1 = 1.4970e-4
mu2 = 0  # 1.1090e-5
T0 = 10
S0 = 35
rho0 = 1026
g = 9.81


def compute_rho(T, S, z, lambda1=5.9520e-2):
    if lambda1 is not None:
        l1 = lambda1
    Ta = T - T0
    Sa = S - S0
    rho = (
        rho0
        - a0 * (1 + 0.5 * l1 * Ta + mu1 * z) * Ta
        + b0 * (1 - 0.5 * l2 * Sa - mu2 * z) * Sa
        - nu * Ta * Sa
    )
    return rho


def compute_b(T, S, z, lambda1=5.9520e-2):
    return g * (rho0 - compute_rho(T, S, z, lambda1=lambda1)) / rho0


def compute_alpha(T, S, z, lambda1=5.9520e-2):
    if lambda1 is not None:
        l1 = lambda1
        print(l1)
    Ta = T - T0
    Sa = S - S0
    alpha = 1 / rho0 * (a0 * (1 + l1 * Ta + mu1 * z) - nu * Sa)
    return alpha


def compute_beta(T, S, z):
    Ta = T - T0
    Sa = S - S0
    beta = 1 / rho0 * b0 * (1 - l2 * Sa - mu2 * z)
    return beta
