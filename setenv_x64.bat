@echo off
set FCC_ROOT=E:\dyl_project
echo Using %FCC_ROOT% as Bitshares root directory

set OPENSSL_ROOT=%FCC_ROOT%\OpenSSL.x64
set OPENSSL_ROOT_DIR=%OPENSSL_ROOT%
set OPENSSL_INCLUDE_DIR=%OPENSSL_ROOT%\include
set DBROOTDIR=%FCC_ROOT%\BerkeleyDB.x64
set QTDIR=%FCC_ROOT%\QT.x64
set ICUROOT=%FCC_ROOT%\ICU.x64
set BOOST_ROOT=%FCC_ROOT%\boost_1.55.x64
set TCL_ROOT=%FCC_ROOT%\tcl.x64
set NPM_INSTALL_PREFIX=%FCC_ROOT%\npm

set PATH=%NPM_INSTALL_PREFIX%;"%APPDATA%"\npm;%QTDIR%\bin;%ICUROOT%\bin;%ICUROOT%\lib;%FCC_ROOT%\bin;%TCL_ROOT%\bin;%FCC_ROOT%\Cmake\bin;%BOOST_ROOT%\stage\lib;%PATH%
set CMAKE_PREFIX_PATH=%QTDIR%
set QT_QPA_PLATFORM_PLUGIN_PATH=%QTDIR%\plugins\platforms

echo Setting up VS2013 environment...
call "%VS120COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
