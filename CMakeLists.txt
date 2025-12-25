cmake_minimum_required(VERSION 3.21)

# Build options (must be before project() for vcpkg feature detection)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BAD_BUILD_CLI "Build command-line interface" ON)
option(BAD_BUILD_TESTS "Build tests" ON)

# Configure vcpkg manifest features based on build options
set(VCPKG_MANIFEST_FEATURES "")
if(BAD_BUILD_CLI)
  list(APPEND VCPKG_MANIFEST_FEATURES "cli")
endif()
if(BAD_BUILD_TESTS)
  list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()

project(libbad
    VERSION 0.0.42
    DESCRIPTION "AI-native debugger"
    LANGUAGES CXX
)

# C++20 standard requirement
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# vcpkg integration
if(DEFINED CMAKE_TOOLCHAIN_FILE)
  message(STATUS "Using vcpkg toolchain: ${CMAKE_TOOLCHAIN_FILE}")
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)

add_subdirectory(tools)

if(BAD_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

# Installation
include(GNUInstallDirs)
install(DIRECTORY include/bad
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)
