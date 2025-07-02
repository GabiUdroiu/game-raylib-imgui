cmake_minimum_required(VERSION 3.21)

project(raygame CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp main.cpp)

# ImGui + rlImGui sources
file(GLOB IMGUI_SOURCES external/imgui/*.cpp external/imgui/*.c)
file(GLOB RLIMGUI_SOURCES external/rlimgui/*.cpp external/rlimgui/*.c)

set(ALL_SOURCES ${SOURCES})

# Add imgui sources only for Debug or RelWithDebInfo
if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    list(APPEND ALL_SOURCES ${IMGUI_SOURCES} ${RLIMGUI_SOURCES})
endif()

add_executable(raygame ${ALL_SOURCES})

target_include_directories(raygame PRIVATE 
    external/imgui 
    external/rlimgui 
    external/rlimgui/extras
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(raygame PROPERTIES WIN32_EXECUTABLE TRUE)  # Hide console on Windows
endif()

target_compile_definitions(raygame PRIVATE
    $<$<CONFIG:Release>:RELEASE_BUILD>
)

target_link_libraries(raygame PRIVATE raylib)

add_custom_command(TARGET raygame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:raygame>/assets)
