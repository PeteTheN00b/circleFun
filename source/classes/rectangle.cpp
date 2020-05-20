#include "rectangle.hpp"

myShapes::Rectangle::Rectangle() :
	min_{0, 0},
	max_{0, 0} {}

myShapes::Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color) :
	min_{min},
	max_{max},
	color_{ color } {}

float myShapes::Rectangle::perimeter() const
{
	return 2 * (max_.x - min_.x + max_.y - min_.y);
}

void myShapes::Rectangle::draw(Window* win) const
{
	draw(win, 1);
}

void myShapes::Rectangle::draw(Window* win, float thickness) const
{
	win->draw_line(min_.x, min_.y, max_.x, min_.y,
		color_.r / 255.f, color_.g / 255.f, color_.b / 255.f,
		thickness);
	win->draw_line(min_.x, min_.y, min_.x, max_.y,
		color_.r / 255.f, color_.g / 255.f, color_.b / 255.f,
		thickness);
	win->draw_line(max_.x, min_.y, max_.x, max_.y,
		color_.r / 255.f, color_.g / 255.f, color_.b / 255.f,
		thickness);
	win->draw_line(min_.x, max_.y, max_.x, max_.y,
		color_.r / 255.f, color_.g / 255.f, color_.b / 255.f,
		thickness);
}