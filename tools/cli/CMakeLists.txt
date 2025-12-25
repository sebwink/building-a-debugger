cmake_minimum_required(VERSION 3.21)

# Dependencies
find_package(CLI11 CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(libedit REQUIRED IMPORTED_TARGET libedit)

# CLI executable
add_executable(dbg_cli
    main.cpp
)

target_link_libraries(dbg_cli
    PRIVATE
        dbg::dbg
        CLI11::CLI11
        PkgConfig::libedit
)

set_target_properties(dbg_cli PROPERTIES
    OUTPUT_NAME dbg
)

# Installation
include(GNUInstallDirs)
install(TARGETS dbg_cli
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
