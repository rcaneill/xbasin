#!/usr/bin/env python
# encoding: UTF-8


from setuptools import setup, find_packages, dist

DISTNAME = "xbasin"
VERSION = "0.0.4"
LICENSE = "MIT"
AUTHOR = "Romain Caneill"
AUTHOR_EMAIL = "romain.caneill@gu.se"
URL = "https://github.com/rcaneill/xbasin"
CLASSIFIERS = [
    # How mature is this project? Common values are
    #   3 - Alpha
    #   4 - Beta
    #   5 - Production/Stable
    "Development Status :: 3 - Alpha",
    "Programming Language :: Python",
    "Programming Language :: Python :: 3",
    "Intended Audience :: Science/Research",
    "License :: OSI Approved :: MIT License",
]
INSTALL_REQUIRES = ["xarray", "dask", "numpy"]
DESCRIPTION = "TODO"
PYTHON_REQUIRES = ">=3.6"
# SETUP_REQUIRES = ['pytest-runner']
# TESTS_REQUIRE = ['pytest']
# ZIP_SAFE = False
# INCLUDE_PACKAGE_DATA = True


def readme():
    with open("README.md") as f:
        return f.read()


# Main setup:
setup(
    name=DISTNAME,
    version=VERSION,
    license=LICENSE,
    author=AUTHOR,
    author_email=AUTHOR_EMAIL,
    description=DESCRIPTION,
    long_description=readme(),
    long_description_content_type="text/markdown",
    url=URL,
    classifiers=CLASSIFIERS,
    install_requires=INSTALL_REQUIRES,
    packages=find_packages(),
    python_requires=PYTHON_REQUIRES,
)
"""
    ext_modules=EXT_MODULES,
    package_dir=PACKAGE_DIR,
    package_data=PACKAGE_DATA,
    include_package_data=INCLUDE_PACKAGE_DATA,
    setup_requires=SETUP_REQUIRES,
    tests_require=TESTS_REQUIRE,
    zip_safe=ZIP_SAFE)
"""

"""
setup(packages=[DISTNAME])
"""
