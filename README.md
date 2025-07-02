
# raygame

A simple Raylib C++ project built with CMake, vcpkg, and Ninja.

---

## Setup & Prerequisites

1. **Install a C++ compiler:**

   - On Windows, install MSYS2 for `g++` (or use Visual Studio compiler):
     - https://www.msys2.org/
     - Update and install gcc:  
       ```
       pacman -Syu
       pacman -S mingw-w64-x86_64-gcc
       ```

2. **Install Ninja build system:**

   - Download Ninja: https://ninja-build.org/
   - Add Ninja to your system PATH.

3. **Install vcpkg for dependencies:**

   - Clone and bootstrap vcpkg:
     ```
     git clone https://github.com/microsoft/vcpkg.git
     cd vcpkg
     .\bootstrap-vcpkg.bat
     ```
   - Add vcpkg to your PATH or reference it explicitly in CMake.

---

## Project Structure

```
raygame/
├── assets/               # Game assets (images, sounds, etc.)
├── build-debug/          # Debug build output folder
├── build-release/        # Release build output folder
├── src/                  # Source code (.cpp, .h)
│   └── main.cpp
├── CMakeLists.txt
├── vcpkg.json            # Dependency manifest
└── .gitignore
```

---

## Build Instructions

From the project root folder:

```bash
# Create build folder and enter
mkdir build-debug
cd build-debug

# Configure for Debug
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake

# Build
cmake --build .

# Run debug build
./raygame.exe
```

Or for Release:

```bash
mkdir build-release
cd build-release

cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake

cmake --build .

./raygame.exe
```

---

## Notes

- **Distributing the game:**  
  Copy `raygame.exe` along with required DLLs (e.g. `raylib.dll`, `glfw3.dll`) and the `assets/` folder.  
  You can package these files for release on GitHub or elsewhere.

- **No console window on Windows for Release:**  
  This is set by the `WIN32_EXECUTABLE` property in CMakeLists.txt.

---
