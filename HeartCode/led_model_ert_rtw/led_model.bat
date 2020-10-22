cd .

if "%1"=="" ("D:\Softwares\MATLAB\bin\win64\gmake"  -f led_model.mk all) else ("D:\Softwares\MATLAB\bin\win64\gmake"  -f led_model.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
