#include "circle.hpp"

#define _USE_MATH_DEFINES //have to do this to get access to pi constant
#include <math.h>

myShapes::Circle::Circle() :
	centre_{ 0, 0 },
	radius_{ 1.0f } {}

myShapes::Circle::Circle(Vec2 const& centre, float radius) :
	centre_{centre},
	radius_{radius} {}

float myShapes::Circle::circumference() const
{
	return 2 * M_PI * radius_;
}