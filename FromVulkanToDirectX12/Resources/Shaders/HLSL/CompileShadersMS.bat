@echo off
setlocal

:: Paths - adapte si besoin
set SHADER_PATH=MeshShader.hlsl
set OUTPUT_PATH=MeshShader.cso
set DXC_PATH=dxc.exe

:: Compilation params
set ENTRY_POINT=mainMS
set PROFILE=ms_6_5

echo === Compiling Mesh Shader ===
%DXC_PATH% -T %PROFILE% -E %ENTRY_POINT% -Fo %OUTPUT_PATH% -Zpr %SHADER_PATH%

if %ERRORLEVEL% NEQ 0 (
    echo Compilation FAILED!
    pause
    exit /b 1
)

echo Compilation succeeded: %OUTPUT_PATH%
pause 