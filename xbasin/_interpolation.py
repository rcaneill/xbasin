import numpy as np


def _bisect(a, x):
    """
    
    """
    hi = len(a)
    lo = 0
    while lo < hi:
        mid = (lo + hi) // 2
        if x < a[mid]:
            hi = mid
        else:
            lo = mid + 1
    return lo - 1


# pythran export interp_new_vertical_from_fortran_pythran(float32[][][] or float64[][][], float32[][][] or float64[][][], float32[][][][] or float64[][][][])
def interp_new_vertical(z_old, z_new, V_old):
    """
      !========================================
      ! Compute the interpolation of the data
      ! The depths must be sorted increasingly
      ! Extend the value outside the depth range (i.e. above the surface or below the bathymetry)
      REAL(8), INTENT(in   ), DIMENSION(jpk_old, jpj, jpi)      ::   z_old   ! old vertical positions
      REAL(8), INTENT(in   ), DIMENSION(jpk_new, jpj, jpi)      ::   z_new   ! new vertical positions
      REAL(8), INTENT(in   ), DIMENSION(jpk_old, jpj, jpi, jpt) ::   V_old   ! old variable values
      REAL(8), INTENT(  out), DIMENSION(jpk_new, jpj, jpi, jpt) ::   V_new   ! new variable values (interpolated)
      !!
      INTEGER ::   ji, jj, jk   ! Loop indices
      INTEGER ::   ind   ! smallest index of the element to the left (previous) so that z_old(ind) <= z <= z_old(ind+1)
      !!----------------------------------------
    """
    (jpk_new, jpj, jpi) = z_new.shape
    (jpk_old, jpj, jpi, jpt) = V_old.shape
    V_new = np.empty((jpk_new, jpj, jpi, jpt))
    # omp parallel for collapse(3)
    for ji in range(jpi):
        for jj in range(jpj):
            for jk in range(jpk_new):
                # Chek if the new depth is inside the old depths
                if z_new[jk, jj, ji] <= z_old[0, jj, ji]:
                    # outside of the range: above the surface, fill with the first value of V
                    for jt in range(jpt):
                        V_new[jk, jj, ji, jt] = V_old[0, jj, ji, jt]
                elif z_new[jk, jj, ji] >= z_old[jpk_old - 1, jj, ji]:
                    # outside of the range: below the bathymetry, fill with last value of V
                    for jt in range(jpt):
                        V_new[jk, jj, ji, jt] = V_old[jpk_old - 1, jj, ji, jt]
                else:
                    # Inside the range of the array => compute the interpolation
                    ind = _bisect(z_old[:, jj, ji], z_new[jk, jj, ji])
                    if z_new[jk, jj, ji] == z_old[ind, jj, ji]:
                        # No need to interpolate as we are in an old grid point
                        for jt in range(jpt):
                            V_new[jk, jj, ji, jt] = V_old[ind, jj, ji, jt]
                    else:
                        # Interpolation
                        for jt in range(jpt):
                            V_new[jk, jj, ji, jt] = V_old[ind, jj, ji, jt] + (
                                z_new[jk, jj, ji] - z_old[ind, jj, ji]
                            ) * (
                                V_old[ind + 1, jj, ji, jt] - V_old[ind, jj, ji, jt]
                            ) / (
                                z_old[ind + 1, jj, ji] - z_old[ind, jj, ji]
                            )
    return V_new
