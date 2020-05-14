#ifndef MAT2_HPP
#define MAT2_HPP

struct Mat2
{
	//e00 e10
	//e01 e11

	float e_00 = 1.0f;
	float e_10 = 0.0f;
	float e_01 = 0.0f;
	float e_11 = 1.0f;

	Mat2& operator*=(Mat2 const& m);
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
bool operator==(Mat2 const& m1, Mat2 const& m2); //Used to simplify tests

#endif