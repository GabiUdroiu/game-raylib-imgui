@echo off
REM Usage: build.bat [debug|release]
REM Default is debug

setlocal

if "%~1"=="" (
    set BUILD_TYPE=debug
) else (
    if /I "%~1"=="release" (
        set BUILD_TYPE=release
    ) else if /I "%~1"=="debug" (
        set BUILD_TYPE=debug
    ) else (
        echo Invalid argument: %1
        echo Usage: build.bat [release|debug]
        exit /b 1
    )
)

set BUILD_DIR=build-%BUILD_TYPE%

echo Building %BUILD_TYPE% in %BUILD_DIR%

REM Delete existing build directory if it exists
if exist "%BUILD_DIR%" (
    echo Deleting existing build directory...
    rmdir /s /q "%BUILD_DIR%"
)

mkdir "%BUILD_DIR%"
pushd "%BUILD_DIR%"
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_TOOLCHAIN_FILE=C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake
popd

pushd "%BUILD_DIR%"
ninja
if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b %ERRORLEVEL%
)

echo Running raygame...
raygame.exe
popd

endlocal
