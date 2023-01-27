#ifndef CARTESIAN_H
#define CARTESIAN_H
class Polar;
class Cartesian
{

public:
	Cartesian();
	Cartesian(double xCor, double yCor);
	Cartesian(const Polar& op2);
	void setCoords(double xCor, double yCor);
	void printCoords();
	Cartesian operator+(const Cartesian& rhs);
	Cartesian operator-(const Cartesian& rhs);
	double module() const;
	double getX() const;
	double getY() const;

private:

	double x;
	double y;

};
#endif
