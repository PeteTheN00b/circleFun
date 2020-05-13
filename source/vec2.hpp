//Without these "include guards" the project wouldn't build due to an attempted redefenition of the struct Vec2
#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2 {
	//Order is important for aggregate init
	float x = 0;
	float y = 0;

	Vec2& operator+=(Vec2 const& v);
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float s);
	Vec2& operator/=(float s);
};

Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& vs);

#endif