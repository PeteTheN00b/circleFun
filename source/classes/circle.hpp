#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../vec2.hpp"
#include "../color.hpp"

//The difference between const-correctness in a Method and a Free Function, is that a const Method promises not to alter the object you are acting upon,
//while a Free Function isn't part of any object in the first place

namespace myShapes { //only necessary to prevent naming conflicts for the rectangle, but it can't hurt to group my shape classes in a namespace
	class Circle
	{
		Vec2 centre_;
		float radius_;
		Color color_;

	public:

		Circle();
		Circle(Vec2 const& centre, float radius, Color const& color);

		float circumference() const;
	};
}

#endif