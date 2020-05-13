#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m)
{
	Mat2 temp = *this;

	e_00 = temp.e_00 * m.e_00 + temp.e_10 * m.e_01;
	e_10 = temp.e_00 * m.e_10 + temp.e_10 * m.e_11;
	e_01 = temp.e_01 * m.e_00 + temp.e_11 * m.e_01;
	e_11 = temp.e_01 * m.e_10 + temp.e_11 * m.e_11;

	return temp;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 temp;
	temp.e_00 = m1.e_00 * m2.e_00 + m1.e_10 * m2.e_01;
	temp.e_10 = m1.e_00 * m2.e_10 + m1.e_10 * m2.e_11;
	temp.e_01 = m1.e_01 * m2.e_00 + m1.e_11 * m2.e_01;
	temp.e_11 = m1.e_01 * m2.e_10 + m1.e_11 * m2.e_11;

	return temp;
}