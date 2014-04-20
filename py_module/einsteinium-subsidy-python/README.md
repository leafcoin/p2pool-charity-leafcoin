linux:
install:
	python setup.py install --record files.txt
uninstall:
	cat files.txt | xargs rm -rf

windows:
Make sure you have the 32bit version of python installed!
- install python27     		!!! 32 bit !!!				http://www.python.org/ftp/python/2.7.6/python-2.7.6.msi 
- install mingw        		!!! 32 bit !!!				http://sourceforge.net/projects/mingwbuilds/files/host-windows/releases/4.8.1/32-bit/threads-posix/dwarf/x32-4.8.1-release-posix-dwarf-rev5.7z/download
- add python dir and mingw/bin to path variables

Download Boost and build boost_python:
- cd into boost dir and execute:
	bootstrap.bat mingw
- build boost_python:
	b2 --build-type=complete --toolset=gcc --link=shared --with-python stage
	
ALL targets should build correctly. if not, create user-config.jam as described here:
http://stackoverflow.com/questions/15881771/boost-1-53-python-fatal-error-lnk1104-boost-python-vc110-mt-gd-1-53-lib
and replace "<toolset>msvc" with "<toolset>gcc" and add --user-config=user-config.jam to the b2 invocation line

edit indlude_dirs and library_dirs in setup-win.py to point to the corresponding folders on your system. after that build with:
	python setup-win.py install
	
	
Build einsteinium module:
-edit py_module\einsteinium-subsidy-python\setup-win.py to your needs
- build module
	cd py_module\einsteinium-subsidy-python
	C:\Python27\python.exe setup.py build --compile=mingw32 install
