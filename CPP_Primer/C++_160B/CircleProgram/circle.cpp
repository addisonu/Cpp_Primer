//circle.cpp
//circle class interface

#include "circle.h"
#include <iostream>
#include <cmath>
#include <string>
#include <new>

//Constructors

	circle::circle (double radiusValue):radius(radiusValue){ }
	circle::circle (double xValue, double yValue, double radiusValue): x(xValue), y(yValue), radius(radiusValue){ }

//Member functions
	
	void circle::setRadius(double r)
        {
                radius = r;
        }
        void circle::setX(double value)
        {
                x = value;
        }
        void circle::setY(double value)
        {
                y = value;
        }
        double circle::getArea()
        {
                return pow(radius, 2)*pi;
        }
        bool circle::containsPoint(double xValue, double yValue)
        {
                double distance(0);

                distance = sqrt(pow(xValue, 2) + pow(yValue, 2));
                if(distance <= radius){
                        return true;
                }
                else{
                        return false;
                }
        }
	bool circle::overlaps(circle::circle c)
	{
		return (radius == c.radius) ? true : false;
	}
