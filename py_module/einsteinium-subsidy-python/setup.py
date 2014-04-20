from distutils.core import setup
from distutils.extension import Extension

setup(name="einsteinium_subsidys",
    ext_modules=[
        Extension("einsteinium_subsidy", ["einsteinium_GetBlockBaseValue.cpp"],
        libraries = ["boost_python"])
    ])