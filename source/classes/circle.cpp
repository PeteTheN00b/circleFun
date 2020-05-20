#include "circle.hpp"

#define _USE_MATH_DEFINES //have to do this to get access to pi constant
#include <math.h>

myShapes::Circle::Circle() :
	centre_{ 0, 0 },
	radius_{ 1.0f } {}

myShapes::Circle::Circle(Vec2 const& centre, float radius, Color const& color) :
	centre_{centre},
	radius_{radius},
	color_{ color } {}

float myShapes::Circle::circumference() const
{
	return 2 * M_PI * radius_;
}

void myShapes::Circle::draw(Window* win, int accuracy) const
{
	draw(win, accuracy, 1);
}

void myShapes::Circle::draw(Window* win, int accuracy, float thickness) const //I'd like to leave this comment as a reminder to my stupid self that passing an argument through means you should use a god damn pointer
{
	for (int i = 0; i < accuracy; i++)
	{
		//r cos(theta) gives you the x offset of a point on the circle, by using (i / accuracy * 2pi) we can target several points along the circumference of the circle
		Vec2 lineCentre;
		lineCentre.x += radius_ * cos(2 * M_PI * (float)i / (float)accuracy); //i forgot that this was integer division the first time, this caused me a lot of headaches
		lineCentre.y += radius_ * sin(2 * M_PI * (float)i / (float)accuracy);

		Vec2 lineOffset{ -lineCentre.y, lineCentre.x}; //A perpendicular vector to where our radius is.
		lineOffset *= M_PI; //blah blah math, blah blah circumference divided by radius, blah blah 2 PI, blah blah extends in 2 directions so only PI
		lineOffset /= accuracy;
		//A higher accuracy should translate to more smaller segments
		//A higher radius should translate to larger segments (lineCentre is already based off of radius

		lineCentre += centre_;

		win->draw_line(lineCentre.x + lineOffset.x, lineCentre.y + lineOffset.y,
			lineCentre.x - lineOffset.x, lineCentre.y - lineOffset.y,
			color_.r / 255.f, color_.g / 255.f, color_.b / 255.f,
			thickness);
	}
}