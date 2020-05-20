#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"

#include "classes/circle.hpp"
#include "classes/rectangle.hpp"

#define _USE_MATH_DEFINES //have to do this to get access to pi constant
#include <math.h>

TEST_CASE("Vec2ConstructorTests")
{
	Vec2 a;
	Vec2 b{ 5.1f, -9.3f };

	REQUIRE(a.x == 0);
	REQUIRE(a.y == 0);

	REQUIRE(b.x == Approx(5.1f));
	REQUIRE(b.y == Approx(-9.3f));
}

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

	a /= 0; //should print message and leave a unchanged

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

TEST_CASE("Color Storage")
{
	Color c{ 200, 50, 0 };
	REQUIRE(c.r == 200);
	REQUIRE(c.g == 50);
	REQUIRE(c.b == 0);
}

TEST_CASE("Circle Circumference")
{
	myShapes::Circle c{ {1,2}, 5 , {1, 0, 0} };

	REQUIRE(c.circumference() == Approx(10 * M_PI));
}

TEST_CASE("Rectangle Perimeter")
{
	myShapes::Rectangle r{ {1,4}, {3, 7}, {1, 1, 1} };

	REQUIRE(r.perimeter() == Approx(10.0f));
}

TEST_CASE("Inside Shapes")
{
	myShapes::Circle c{ {300, 300}, 100, {1, 1, 1} };

	REQUIRE(c.is_inside({350, 320})); //magnitude of 53.85, contained in circle
	REQUIRE(!c.is_inside({ 400, 400 })); //100 units in both directions, magnitude difference larger than 100, shouldn't be contained in circle

	myShapes::Rectangle r{ {100, 200}, {200, 300}, {1, 1, 1} }; //basically a square from (100, 200) to (200, 300)

	REQUIRE(r.is_inside({ 150, 250 }));
	REQUIRE(!r.is_inside({ 150, 350 })); //check that all 4 fail conditions work properly (x > max_.x, x < max_.x, etc...)
	REQUIRE(!r.is_inside({ 250, 250 }));
	REQUIRE(!r.is_inside({ 50, 250 }));
	REQUIRE(!r.is_inside({ 150, 150 }));
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}