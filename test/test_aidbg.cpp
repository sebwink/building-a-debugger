#include <catch2/catch_test_macros.hpp>

#include <aidbg/aidbg.hpp>

TEST_CASE("Check message") {
  std::string expected_message = "AIDBG.";
  std::string message = aidbg::get_message();
  CHECK(message == expected_message);
}
