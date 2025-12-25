cmake_minimum_required(VERSION 3.21)

# Find test dependencies
find_package(Catch2 CONFIG REQUIRED)

# ============================================================================
# Catch2 Tests
# ============================================================================

file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(bad_tests
    ${TEST_SOURCES}
)

target_include_directories(bad_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(bad_tests
    PRIVATE
        bad::bad
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(bad_tests)
