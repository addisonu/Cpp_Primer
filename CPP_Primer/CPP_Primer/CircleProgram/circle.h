//circle.h
//Contains class definition of Circle type

#ifndef CIRCLE_H
#define CIRCLE_H
class circle {
	double x = 0;
	double y = 0;
	double radius = 1;
	const double pi = 3.14; 

public:
	circle() = default;
	circle(double radiusValue);
	circle(double xValue, double yValue, double radiusValue);
	double getX() { return x; }
	double getY() { return y; }
	double getRadius() { return radius; }

	void setX(double value);
	void setY(double value);
	void setRadius(double value);

	double getArea();
	bool containsPoint(double xValues, double yValue);
	bool overlaps(circle c);
	


};
#endif
