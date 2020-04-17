#include "catch2/single_include/catch2/catch.hpp"
#include "tver.hpp"

TEST_CASE("Simple expressions") {
	REQUIRE(tver::Parser("1").parse() == 1);
	REQUIRE(tver::Parser("1 + 1").parse() == 2);
	REQUIRE(tver::Parser("1 + 2 * 3").parse() == 7);
	REQUIRE(tver::Parser("1 + 2 / 2").parse() == 2);
	REQUIRE(tver::Parser("8 * 9 / 3 - 2 / 4").parse() == 23.5);
}
