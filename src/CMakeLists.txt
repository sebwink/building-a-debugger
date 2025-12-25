cmake_minimum_required(VERSION 3.21)

# Forced re-configuration for GLOB

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(dbg
    ${SOURCES}
)

target_include_directories(dbg
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#target_link_libraries(dbg
#  PRIVATE
#    PkgConfig::libedit
#)

set_target_properties(dbg PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME dbg
)

add_library(dbg::dbg ALIAS dbg)

# ============================================================================
# Installation
# ============================================================================

include(GNUInstallDirs)

install(TARGETS dbg
    EXPORT dbgTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT dbgTargets
    FILE dbgTargets.cmake
    NAMESPACE dbg::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dbg
)
