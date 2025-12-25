cmake_minimum_required(VERSION 3.21)

# Forced re-configuration for GLOB

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(bad
    ${SOURCES}
)

target_include_directories(bad
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#target_link_libraries(bad
#  PRIVATE
#    PkgConfig::libedit
#)

set_target_properties(bad PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME bad
)

add_library(bad::bad ALIAS bad)

# ============================================================================
# Installation
# ============================================================================

include(GNUInstallDirs)

install(TARGETS bad
    EXPORT badTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT badTargets
    FILE badTargets.cmake
    NAMESPACE bad::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/bad
)
