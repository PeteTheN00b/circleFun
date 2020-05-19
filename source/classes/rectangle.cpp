#include "rectangle.hpp"

myShapes::Rectangle::Rectangle() :
	min_{0, 0},
	max_{0, 0} {}

myShapes::Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) :
	min_{min},
	max_{max} {}

float myShapes::Rectangle::perimeter() const
{
	return 2 * (max_.x - min_.x + max_.y - min_.y);
}