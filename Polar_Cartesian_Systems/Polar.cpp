#include <vector>
#include <iostream>
#include "polar.h"
#include "cartesian.h"
#include <cmath>

Polar::Polar() {}

Polar::Polar(double a, double d)
:	angle{a}, dist{d}
{}

Polar::Polar(const Cartesian& op2)
	:Polar(atan(op2.getY() / op2.getX()),
	       op2.module()) {}

void Polar::setCoords(double a, double d)
{
	angle = a;
	dist = d;
}

void Polar::printCoords()
{
	std::cout << "angle    : " << angle << std::endl;
	std::cout << "distance : " << dist << std::endl;
}

Polar Polar::operator+(const Polar& rhs)
{
	Polar pol(angle + rhs.angle, dist + rhs.dist);
	return pol;
}

Polar Polar::operator-(const Polar& rhs)
{
	Polar pol(angle - rhs.angle, dist - rhs.dist);
	return pol;
}

Polar Polar::operator=(const Polar& rhs)
{
	angle = rhs.angle;
	dist = rhs.dist;
	return *this;
}

double Polar::getAngle() const
{
	return angle;
}

double Polar::getDist() const
{
	return dist;
}
