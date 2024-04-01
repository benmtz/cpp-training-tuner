#include <catch2/catch_test_macros.hpp>
#include "adder.h"

TEST_CASE("Adder adds", "[adder]") {
  REQUIRE(Adder(1, 1) == 2);
}
