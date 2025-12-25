cmake_minimum_required(VERSION 3.21)

# Dependencies
find_package(CLI11 CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(libedit REQUIRED IMPORTED_TARGET libedit)

# CLI executable
add_executable(bad_cli
    main.cpp
)

target_link_libraries(bad_cli
    PRIVATE
        bad::bad
        CLI11::CLI11
        PkgConfig::libedit
)

set_target_properties(bad_cli PROPERTIES
    OUTPUT_NAME bad
)

# Installation
include(GNUInstallDirs)
install(TARGETS bad_cli
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
