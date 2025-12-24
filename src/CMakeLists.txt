cmake_minimum_required(VERSION 3.21)

# Forced re-configuration for GLOB
# Find dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(libedit REQUIRED IMPORTED_TARGET libedit)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(aidbg
    ${SOURCES}
)

target_include_directories(aidbg
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(aidbg
  PRIVATE
    PkgConfig::libedit
)

set_target_properties(aidbg PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME aidbg
)

add_library(aidbg::aidbg ALIAS aidbg)

# ============================================================================
# Installation
# ============================================================================

include(GNUInstallDirs)

install(TARGETS aidbg
    EXPORT aidbgTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT aidbgTargets
    FILE aidbgTargets.cmake
    NAMESPACE aidbg::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/aidbg
)
