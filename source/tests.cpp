#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("Vec2Tests")
{
	Vec2 a{ 1, 3 };
	Vec2 b{ 2, 4 };
	a += b; //(1 + 2, 3 + 4), a should be (3, 7)

	REQUIRE(a.x == Approx(3.0f));
	REQUIRE(a.y == Approx(7.0f));

	b -= a; //(2 - 3, 4 - 7), b should be (-1, -3)

	REQUIRE(b.x == Approx(-1.0f));
	REQUIRE(b.y == Approx(-3.0f));

	a *= 6; //a should be (18, 42)

	REQUIRE(a.x == Approx(18.0f));
	REQUIRE(a.y == Approx(42.0f));

	a /= 2; //a should be (9, 21)

	REQUIRE(a.x == Approx(9.0f));
	REQUIRE(a.y == Approx(21.0f));



	//a should be 9,21, b should be -1, -3
	Vec2 c = a + b;

	REQUIRE(c.x == 8);
	REQUIRE(c.y == 18);

	c = a - b;

	REQUIRE(c.x == 10);
	REQUIRE(c.y == 24);

	c = b * -5;

	REQUIRE(c.x == 5);
	REQUIRE(c.y == 15);

	c = -5 * b;

	REQUIRE(c.x == 5);
	REQUIRE(c.y == 15);

	c = a / 3;

	REQUIRE(c.x == 3);
	REQUIRE(c.y == 7);
}

TEST_CASE("Mat2Tests")
{
	Mat2 m1;
	Mat2 m2{ 1, 3, 3, 1 };

	m1 *= m2; //m1 should become:
	//1, 3
	//3, 1, like m2 because its an identity matrix

	REQUIRE(m1.e_00 == 1);
	REQUIRE(m1.e_10 == 3);
	REQUIRE(m1.e_01 == 3);
	REQUIRE(m1.e_11 == 1);
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}