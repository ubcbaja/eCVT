set "VSCMD_START_DIR=%CD%"

call "setup_msvc150.bat"

call "%VS150COMNTOOLS%..\..\VC\Auxiliary\Build\VCVARSALL.BAT" AMD64


call  "\\safetybearMk2\D$\MATLAB 2019\bin\win64\checkMATLABRootForDriveMap.exe" "\\safetybearMk2\D$\MATLAB 2019"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n
cd .

if "%1"=="" (nmake MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f PotTest.mk all) else (nmake MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f PotTest.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1