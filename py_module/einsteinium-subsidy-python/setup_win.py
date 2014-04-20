from distutils.core import setup
from distutils.extension import Extension

# edit include_dirs and library_dirs to point to the corresponding folders on your system
# change lib name, if you used another verion of boost

setup(name="einsteinium_subsidys",
    ext_modules=[
        Extension("einsteinium_subsidy", ["einsteinium_GetBlockBaseValue.cpp"],
        libraries = ["boost_python-mgw48-1_55.dll"],
        include_dirs = ["c:/boost_1_55_0"],
        library_dirs = ["c:/boost_1_55_0/stage\lib"])])
