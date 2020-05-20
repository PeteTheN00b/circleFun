#include <catch.hpp>
#include "vec2.hpp"
#include "vec2.hpp" //done a second time for the sake of testing include guards, not to serve any functionality

#include <iostream>

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
	if (s == 0)
	{
		std::cout << "Division by 0 detected!" << std::endl;
		return *this;
	}

	x /= s;
	y /= s;

	return *this;
}


Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
	Vec2 temp;
	temp += u;
	temp += v;
	return temp;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
	Vec2 temp;
	temp += u;
	temp -= v;
	return temp;
}

Vec2 operator*(Vec2 const& v, float s)
{
	Vec2 temp;
	temp += v;
	temp *= s;
	return temp;
}

Vec2 operator/(Vec2 const& v, float s)
{
	Vec2 temp;
	temp += v;
	temp /= s;
	return temp;
}

Vec2 operator*(float s, Vec2 const& v)
{
	return v * s;
}