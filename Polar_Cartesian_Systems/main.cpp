#include <iostream>
#include <cmath>

#include "cartesian.h"
#include "polar.h"

Polar toPolar(Cartesian& obj);

Cartesian toCartesian(Polar& pol);

int main()
{
	// create two cartesian points;
	Cartesian c1(1,2);
	Cartesian c2(2,2);
	
	// check + operation
	Cartesian sum;
	sum = c1 + c2;
	sum.printCoords();
	std::cout << std::endl;
	
	// represent them in polar coordinates
	Polar p1;
	p1 = toPolar(sum);
	p1.printCoords();
	
}

Polar toPolar(Cartesian& obj)
{
        Polar pol(atan((obj.getY() / obj.getX())), obj.module());
        return pol;
}

Cartesian toCartesian(Polar& pol)
{
        Cartesian cart(pol.getDist() * cos(pol.getAngle()), pol.getDist() * sin(pol.getAngle()));
        return cart;
}

