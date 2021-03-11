# xbasin
Python package to compute diagnostics of idealized basin global circulation models. NEMO oriented for now. Deals with terrain-following coordinates.

2020-11-02: The vertical transformation function should not be used anymore, see the [xgcm](https://github.com/xgcm/xgcm) package that is the new reference.

## What's new

### v0.0.5
* Bug fix in surface buoyancy fluxes nemo wrap
* Add option to choose T, S, and depth names in eos nemo_wrap