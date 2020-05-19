#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "..\vec2.hpp"

namespace myShapes{ //prevents naming conflict with stdcall library in tests.cpp
	class Rectangle //parallel to axis, no rotation
	{
		Vec2 min_;
		Vec2 max_;

	public:

		Rectangle();
		Rectangle(Vec2 const& min, Vec2 const& max);

		float perimeter() const;
	};
}



#endif