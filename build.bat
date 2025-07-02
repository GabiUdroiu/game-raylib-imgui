@echo off

REM Check if an argument was passed, default to debug if not
if "%1"=="" (
    set BUILD_TYPE=Debug
    set BUILD_DIR=build-debug
) else (
    if /I "%1"=="release" (
        set BUILD_TYPE=Release
        set BUILD_DIR=build-release
    ) else if /I "%1"=="debug" (
        set BUILD_TYPE=Debug
        set BUILD_DIR=build-debug
    ) else (
        echo Invalid argument: %1
        echo Usage: build.bat [release|debug]
        exit /b 1
    )
)

echo Building %BUILD_TYPE% in %BUILD_DIR%

REM Create build directory if it doesn't exist and configure
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
    cd %BUILD_DIR%
    cmake .. -G Ninja -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_TOOLCHAIN_FILE=C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake
    cd ..
)

cd %BUILD_DIR%

ninja

raygame.exe

cd ..