#include "circGraph.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

float cosD(float phi)
{
	return cos(phi / 180.f * M_PI);
}

float sinD(float phi)
{
	return sin(phi / 180.f * M_PI);
}

bool circ_a2_dist_shorter(float aRef, float a1, float a2) //check if a2 has a shorter distance from aRef on the unit circle compared to a1
{
	float a1dif = a1 - aRef;
	if (aRef > a1)
		a1dif += 360;
	float a2dif = a2 - aRef;
	if (aRef > a2)
		a2dif += 360;

	return a2dif < a1dif;

	/*return
		pow(sinD(a2) - sinD(aRef), 2) + pow(cosD(a2) - cosD(aRef), 2)
		<
		pow(sinD(a1) - sinD(aRef), 2) + pow(cosD(a1) - cosD(aRef), 2);*/

		/*pow(sinD(a2), 2) + pow(cosD(a2), 2) - (pow(sinD(aRef), 2) + pow(cosD(aRef), 2))
		<
		pow(sinD(a1), 2) + pow(cosD(a1), 2) - (pow(sinD(aRef), 2) + pow(cosD(aRef), 2));*/
}

float circGraph::pointStrength(float angle)
{
	if (points_.size() >= 2)
	{
		circPoint const* minPt = &points_[0];
		circPoint const* maxPt = &points_[0];

		for (circPoint &point : points_)
		{

			float minPtDist = angle - minPt->angle_;
			float newMinPtDist = angle - point.angle_;
			float maxPtDist = maxPt->angle_ - angle;
			float newMaxPtDist = point.angle_ - angle;

			if (minPt->angle_ > angle) minPtDist += 360;
			if (point.angle_ > angle) newMinPtDist += 360;
			if (maxPt->angle_ < angle) maxPtDist += 360;
			if (point.angle_ < angle) newMaxPtDist += 360;

			/*std::cout << angle << std::endl;
			std::cout << minPt->angle_ << ": min: " << minPtDist << std::endl;
			std::cout << point.angle_ << ": newmin: " << newMinPtDist << std::endl;
			std::cout << (newMinPtDist < minPtDist) << std::endl;
			std::cout << maxPt->angle_ << ": max: " << maxPtDist << std::endl;
			std::cout << point.angle_ << ": newmax: " << newMaxPtDist << std::endl;
			std::cout << (newMaxPtDist < maxPtDist) << std::endl;
			std::cout << std::endl;*/

			if (newMinPtDist < minPtDist) minPt = &point;
			if (newMaxPtDist < maxPtDist) maxPt = &point;
		}

		float minPtDist = angle - minPt->angle_;
		float maxPtDist = maxPt->angle_ - angle;

		if (minPt->angle_ > angle) minPtDist += 360;
		if (maxPt->angle_ < angle) maxPtDist += 360;

		float minPtStrength = minPt->strength_ > 0 ? minPt->strength_ : 0;
		float maxPtStrength = maxPt->strength_ > 0 ? maxPt->strength_ : 0;

		float ptStrength = minPtStrength + (maxPtStrength - minPtStrength) * minPtDist / (maxPtDist + minPtDist);

		//std::cout << minPt->angle_<< std::endl;
		//std::cout << maxPt->angle_ << std::endl;
		
		return ptStrength;
	}
	else
		return baseStrength_;
}

void circGraph::generatePoint(float angle, float dmg)
{
	points_.push_back(circPoint{ angle, pointStrength(angle) - dmg });
}

void circGraph::generateFixedPoint(float angle, float strength)
{
	if (strength < 0) strength = 0;

	points_.push_back(circPoint{ angle, strength });
}

void circGraph::damage(float angle, float dmg, float angleSpace)
{
	float baseStrMin = pointStrength(fmod(angle - angleSpace, 360.f));
	float baseStrMax = pointStrength(fmod(angle + angleSpace, 360.f));

	for (circPoint& point : points_)
	{
		if (fmod(angle - angleSpace - 1.f, 360.f) < point.angle_ && point.angle_ < fmod(angle + angleSpace + 1.f, 360.f)) point.strength_ -= dmg;

		//points_.erase to delete excess points
	}

	generateFixedPoint(fmod(angle - angleSpace - 1.f, 360.f), baseStrMin);
	generateFixedPoint(fmod(angle - angleSpace, 360.f), baseStrMin - dmg);
	generateFixedPoint(fmod(angle + angleSpace, 360.f), baseStrMax - dmg);
	generateFixedPoint(fmod(angle + angleSpace + 1.f, 360.f), baseStrMax);
}

bool circGraph::is_inside(Vec2 const& point)
{
	float pointAngle = atan((point.y - centre_.y) / (point.x - centre_.x)) * 180.f / (float)M_PI;

	//quadrant stuff
	pointAngle += 90;
	if (point.x < 400) pointAngle += 180;

	Vec2 dist = point - centre_;
	float distVal = sqrt(dist.x * dist.x + dist.y * dist.y);
	return distVal <= pointStrength(pointAngle) + ringSize_ && distVal > ringSize_;
}

void circGraph::draw(Window const& win, float thickness)
{
	int const accuracy = 100;
	//Vec2 const centre{ 400, 400 };

	for (int i = 0; i <= accuracy; ++i) //why is 360 always so weird? its like there's a massive value at point strength 0
	{
		Vec2 lineCentre{ 0,  -pointStrength((float)i / (float)accuracy * 360.f)};
		lineCentre = lineCentre * transpose(make_rotation_mat2((float)i / (float)accuracy * 360.f));

		Vec2 lineOffset{-lineCentre.y, lineCentre.x};
		lineOffset *= M_PI;
		lineOffset /= accuracy;

		Vec2 minCentre{ 0, -ringSize_ };
		minCentre = minCentre * transpose(make_rotation_mat2((float)i / (float)accuracy * 360.f));
		minCentre += centre_;

		lineCentre += minCentre;


		/*win.draw_line(lineCentre.x + lineOffset.x, lineCentre.y + lineOffset.y,
			lineCentre.x - lineOffset.x, lineCentre.y - lineOffset.y,
			255.f / 255.f, 0.f / 255.f, 0.f / 255.f,
			1);*/

		win.draw_line(lineCentre.x, lineCentre.y,
			minCentre.x, minCentre.y,
			255.f / 255.f, 0.f / 255.f, 0.f / 255.f,
			thickness);

		int jMax = (int)(pointStrength((float)i / (float)accuracy * 360.f) / 8);
		for (int j = 1; j <= jMax; j++) //for every 8 units of the radius, draw 2 more lines
		{
			win.draw_line(lineCentre.x + (float)j / (float)jMax * lineOffset.x, lineCentre.y + (float)j / (float)jMax * lineOffset.y,
				minCentre.x, minCentre.y,
				255.f / 255.f, 0.f / 255.f, 0.f / 255.f,
				thickness);
			win.draw_line(lineCentre.x - (float)j / (float)jMax * lineOffset.x, lineCentre.y - (float)j / (float)jMax * lineOffset.y,
				minCentre.x, minCentre.y,
				255.f / 255.f, 0.f / 255.f, 0.f / 255.f,
				thickness);
		}
	}
}