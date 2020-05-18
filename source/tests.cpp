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

	REQUIRE(m1 == m2); //same check as above, just want to make sure both work


	Mat2 m3{ 10, 6, 6, 10 }; //product of m1 and m2

	REQUIRE((m1 * m2) == m3); //catch2 doesn't run without the internal bracket


	Mat2 m4{ 3, 4, 2, 1 };
	Mat2 m5{ 1, 5, 3, 7 };
	Mat2 m6{ 15, 43, 5, 17 };

	REQUIRE((m4 * m5) == m6);
}

TEST_CASE("Mat2FurtherTests2.6")
{
	Mat2 i; //Identity matrix
	Mat2 m1{ 2, 5, 7, 3 };
	Vec2 v{ 1, 2 };

	Vec2 m1v{ 12, 13 };

	REQUIRE((m1 * v).x == m1v.x);
	REQUIRE((m1 * v).y == m1v.y);

	REQUIRE(m1.det() == Approx(-29.f));

	REQUIRE((m1 * inverse(m1)) == i); //any matrix, multiplied by its inverse, should return the identity matrix

	Mat2 t_m1{ 2, 7, 5, 3 };
	REQUIRE(transpose(m1) == t_m1);
}

TEST_CASE("Rotation Matrix")
{
	Vec2 v{ -3, 1 };
	Vec2 r90_v{1 , 3}; //should be the result of rotating the vector by 90 degrees

	REQUIRE((v * make_rotation_mat2(90)).x == Approx(r90_v.x));
	REQUIRE((v * make_rotation_mat2(90)).y == Approx(r90_v.y));
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}