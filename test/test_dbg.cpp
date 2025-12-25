#include <catch2/catch_test_macros.hpp>

#include <dbg/dbg.hpp>

TEST_CASE("Check message") {
  std::string expected_message = "DBG.";
  std::string message = dbg::get_message();
  CHECK(message == expected_message);
}
