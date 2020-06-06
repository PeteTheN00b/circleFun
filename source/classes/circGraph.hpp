#ifndef CIRCGRAPH_HPP
#define CIRCGRAPH_HPP

#include "circPoint.hpp"
#include "../window.hpp"

#include "../vec2.hpp"
#include "../mat2.hpp"

#include <vector>

class circGraph
{
	float baseStrength_ = 30;

	std::vector<circPoint> points_;

public:
	float pointStrength(float angle);
	void generatePoint(float angle, float dmg); //generates a point at the targeted location, by offsetting the current point strength at that location
	void generateFixedPoint(float angle, float strength); //generates a point with a fixed strength at the target location, regardless of previous point strength
	void damage(float angle, float dmg, float angleSpace = 10);

	void draw(Window const& win);
};

#endif