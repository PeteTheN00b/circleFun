#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("Vec2Tests")
{
	Vec2 a{ 1, 3 };
	Vec2 b{ 2, 4 };
	a += b; //(1 + 2, 3 + 4), A should be (3, 7)

	REQUIRE(a.x == Approx(3.0f));
	REQUIRE(a.y == Approx(7.0f));

	b -= a; //(2 - 3, 4 - 7), B should be (-1, -3)

	REQUIRE(b.x == Approx(-1.0f));
	REQUIRE(b.y == Approx(-3.0f));

	a *= 6; //A should be (18, 42)

	REQUIRE(a.x == Approx(18.0f));
	REQUIRE(a.y == Approx(42.0f));

	a /= 2; //A should be (9, 21)

	REQUIRE(a.x == Approx(9.0f));
	REQUIRE(a.y == Approx(21.0f));
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}