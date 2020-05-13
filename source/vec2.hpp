//Without these "include guards" the project wouldn't build due to an attempted redefenition of the struct Vec2
#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2 {
	float x = 0;
	float y = 0;
};

#endif