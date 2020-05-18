#include "mat2.hpp"
#include <catch.hpp>

#define _USE_MATH_DEFINES //have to do this to get access to pi constant
#include <math.h>

Mat2& Mat2::operator*=(Mat2 const& m)
{
	Mat2 temp = *this;

	e_00 = temp.e_00 * m.e_00 + temp.e_10 * m.e_01;
	e_10 = temp.e_00 * m.e_10 + temp.e_10 * m.e_11;
	e_01 = temp.e_01 * m.e_00 + temp.e_11 * m.e_01;
	e_11 = temp.e_01 * m.e_10 + temp.e_11 * m.e_11;

	return temp;
}

float Mat2::det() const
{
	return e_00 * e_11 - e_01 * e_10;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 temp{ m1 };
	temp *= m2;

	return temp;
}

bool operator==(Mat2 const& m1, Mat2 const& m2)
{
	return m1.e_00 == Approx(m2.e_00) && m1.e_10 == Approx(m2.e_10) && m1.e_01 == Approx(m2.e_01) && m1.e_11 == Approx(m2.e_11);
}

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
	Vec2 newVec;
	newVec.x = m.e_00 * v.x + m.e_10 * v.y;
	newVec.y = m.e_01 * v.x + m.e_11 * v.y;

	return newVec;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m)
{
	return m * v;
}

Mat2 inverse(Mat2 const& m)
{
	Mat2 inv{m.e_11, -m.e_10, -m.e_01, m.e_00};
	inv.e_00 /= m.det();
	inv.e_10 /= m.det();
	inv.e_01 /= m.det();
	inv.e_11 /= m.det();

	return inv;
}

Mat2 transpose(Mat2 const& m)
{
	return Mat2{ m.e_00, m.e_01, m.e_10, m.e_11 }; //flipped
}

Mat2 make_rotation_mat2(float phi)
{
	return Mat2{ cos(phi * float(M_PI) / 180), sin(phi * float(M_PI) / 180), -sin(phi * float(M_PI) / 180), cos(phi * float(M_PI) / 180) };
}