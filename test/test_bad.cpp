#include <catch2/catch_test_macros.hpp>

#include <bad/bad.hpp>

TEST_CASE("Check message") {
  std::string expected_message = "BAD.";
  std::string message = bad::get_message();
  CHECK(message == expected_message);
}
