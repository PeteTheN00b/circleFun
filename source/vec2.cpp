#include <catch.hpp>
#include "vec2.hpp"
#include "vec2.hpp" //done a second time for the sake of testing include guards, not to serve any functionality

TEST_CASE("Vec2Test", "{Vec2Tests}")
{
	Vec2 a;
	Vec2 b{ 5.1f, -9.3f };

	REQUIRE(a.x == 0);
	REQUIRE(a.y == 0);

	REQUIRE(b.x == Approx(5.1f));
	REQUIRE(b.y == Approx(-9.3f));
}