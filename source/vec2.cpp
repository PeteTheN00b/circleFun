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

Vec2& Vec2::operator+=(Vec2 const& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vec2& Vec2::operator*=(float s)
{
	x *= s;
	y *= s;

	return *this;
}

Vec2& Vec2::operator/=(float s)
{
	x /= s;
	y /= s;

	return *this;
}