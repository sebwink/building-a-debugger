cmake_minimum_required(VERSION 3.21)

# Dependencies
find_package(CLI11 CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(libedit REQUIRED IMPORTED_TARGET libedit)

# CLI executable
add_executable(aidbg_cli
    main.cpp
)

target_link_libraries(aidbg_cli
    PRIVATE
        aidbg::aidbg
        CLI11::CLI11
        PkgConfig::libedit
)

set_target_properties(aidbg_cli PROPERTIES
    OUTPUT_NAME aidbg
)

# Installation
include(GNUInstallDirs)
install(TARGETS aidbg_cli
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
