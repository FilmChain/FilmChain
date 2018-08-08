echo Available processor count: %NUMBER_OF_PROCESSORS%
echo Starting build # %BUILD_NUMBER%
cd mccshares
rem git reset --hard
rem git pull
rem reset and pull not needed because we assume
rem that mccshares was just cloned fresh
git submodule init || exit /b 21
git submodule update || exit /b 22

cd %WORKSPACE%
call mccshares/setenv.bat || exit /b 26

call npm install grunt
call npm install lineman -g --prefix=%NPM_INSTALL_PREFIX%
call npm install lineman-angular
call npm install lineman-less

if exist build (
  rmdir /Q /S build || exit /b 27
)
mkdir build
cd build
cmake -DINCLUDE_QT_WALLET=TRUE -DINCLUDE_CRASHRPT=TRUE -G "Visual Studio 12" -T "v120_xp" ../mccshares || exit /b 28
msbuild.exe /M:%NUMBER_OF_PROCESSORS% /p:Configuration=RelWithDebInfo /p:Platform=Win32 /target:BitShares:rebuild /v:diag BitShares.sln || exit /b 30
msbuild.exe /M:%NUMBER_OF_PROCESSORS% /p:Configuration=RelWithDebInfo /p:Platform=Win32 /target:mccshares_client:rebuild /v:diag BitShares.sln || exit /b 30
