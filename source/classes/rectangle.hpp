#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "..\vec2.hpp"
#include "../color.hpp" //is there any difference between using / and \ ?

#include "../window.hpp"

namespace myShapes{ //prevents naming conflict with stdcall library in tests.cpp
	class Rectangle //parallel to axis, no rotation
	{
		Vec2 min_;
		Vec2 max_;
		Color color_;

	public:

		Rectangle();
		Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);

		float perimeter() const;
		void draw(Window* win);
	};
}



#endif