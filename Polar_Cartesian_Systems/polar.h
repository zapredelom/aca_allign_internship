#ifndef POLAR_H
#define POLAR_H

class Cartesian;
class Polar
{
public:
	Polar();
	Polar(double a, double d);
	Polar(const Cartesian& op2);
	void setCoords(double a, double d);
	void printCoords();
	Polar operator+(const Polar& rhs);
	Polar operator-(const Polar& rhs);
	Polar operator=(const Polar& rhs);
	double getAngle() const;
	double getDist() const;
private:

	double angle;
	double dist;

};

#endif
