def compute_strati_ratio(T, S, alpha, beta, grid):
    """
    Compute the stratification ratio
    
    R = (alpha * dT/dz + beta * dS/dz) / (alpha * dT/dz - beta * dS/dz)
    """
    dT_dz = -grid.derivative(
        T, axis="Z", boundary="extend"
    )  # - sign to take z in the right direction
    dS_dz = -grid.derivative(S, axis="Z", boundary="extend")

    R = (alpha * dT_dz + beta * dS_dz) / (alpha * dT_dz - beta * dS_dz)
    return R
