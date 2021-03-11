# xbasin
Python package to compute diagnostics of idealized basin global circulation models. NEMO oriented for now. Deals with terrain-following coordinates.

## Installation

Installation via pip:
```bash
pip3 install xbasin
```

## Requirements for dev

We use *pipenv* to set up a virtual environment containing all
needed packages to run xnemogcm and the tests.
To install all the dependencies, type `pipenv install --dev`
after cloning the directory. This will create a new virtual environment.
Typing `pipenv shell` in the package directory will activate the virtual environment.

## What's new

### v0.0.5
* Bug fix in surface buoyancy fluxes nemo wrap
* Add option to choose T, S, and depth names in eos nemo_wrap

## Notes

2020-11-02: The vertical transformation function should not be used anymore, see the [xgcm](https://github.com/xgcm/xgcm) package that is the new reference.