//CircleProgram.cpp
//Test circle class in main() function

#include "circle.h"
#include <iostream>
#include <cmath>
#include <string>
#include <new>

int main()
{
        circle circ4;

        circle circ1;
	circle circ2(14.0);
	circle circ3(7.0, 8.0, 12.0);

        double val(0);

        circle *pntcirc = &circ4;
        std::cout << "\nSet values for circ4:\n";
        std::cout << "What is the x value?\n";
        std::cin >> val;
        (*pntcirc).setX(val);
        std::cout << "What is the y value?\n";
        std::cin >> val;
        (*pntcirc).setY(val);
        std::cout << "What is the radius?\n";
        std::cin >> val;
        (*pntcirc).setRadius(val);

        circle circarr[3];

        circarr[0].setX(1);
        circarr[0].setY(3);
        circarr[0].setRadius(5);

        circarr[1].setX(2);
        circarr[1].setY(4);
        circarr[1].setRadius(6);

        circarr[2].setX(3);
        circarr[2].setY(5);
        circarr[2].setRadius(7);

        circle *pntcirc2 = new circle[3];
        std::cout << "\nSet values for circle pointed to by pntcirc2:\n";
        std::cout << "What is the x value?\n";
        std::cin >> val;
        pntcirc2[2].setX(val);
        std::cout << "What is the y value?\n";
        std::cin >> val;
        pntcirc2[2].setY(val);
        std::cout << "What is the radius?\n";
        std::cin >> val;
        pntcirc2[2].setRadius(val);

        std::cout << std::boolalpha << std::endl;

	std::cout << "The area of circ1 is " << circ1.getArea() << std::endl;
        std::cout << "Is the point (" << circ1.getX() << ", " << circ1.getY() << ") in the circ1 that has radius = " << circ1.getRadius() << "?\n" << circ1.containsPoint(circ1.getX(), circ1.getY()) << "\n" << std::endl;

	std::cout << "The area of circ2 is " << circ2.getArea() << std::endl;
        std::cout << "Is the point (" << circ2.getX() << ", " << circ2.getY() << ") in the circ2 that has radius = " << circ2.getRadius() << "?\n" << circ2.containsPoint(circ2.getX(), circ2.getY()) << "\n" << std::endl;

        std::cout << "The area of circ3 is " << circ3.getArea() << std::endl;
        std::cout << "Is the point (" << circ3.getX() << ", " << circ3.getY() << ") in the circ3 that has radius = " << circ3.getRadius() << "?\n" << circ3.containsPoint(circ3.getX(), circ3.getY()) << "\n" << std::endl;

        std::cout << "The area of circ4 is " << pntcirc-> getArea() << std::endl;
        std::cout << "Is the point (" << pntcirc-> getX() << ", " << pntcirc-> getY() << ") in the circ4 that has radius = " << circ4.getRadius() << "?\n" << circ4.containsPoint(pntcirc-> getX(), pntcirc-> getY()) << "\n" << std::endl;


        std::cout << "The area of circarr[1] is " << circarr[1].getArea() << std::endl;
        std::cout << "Is the point (" << circarr[1].getX() << ", " << circarr[1].getY() << ") in the circarr[1] that has radius = 6?\n" << circarr[1].containsPoint(circarr[1].getX(), circarr[1].getY()) << "\n" << std::endl;

        std::cout << "The area of pntcirc2[2] is " << pntcirc2[2].getArea() << std::endl;
        std::cout << "Is the point (" << pntcirc2[2].getX() << ", " << pntcirc2[2].getY() << ") in the circ3 that has radius = " << pntcirc2[2].getRadius() << "?\n" << pntcirc2[2].containsPoint(pntcirc2[2].getX(), pntcirc2[2].getY()) << "\n" << std::endl;

	std::cout << "Do the two circles overlap?" << std::endl << circ2.overlaps(circ3) << std::endl;

        delete [] pntcirc2;
        return 0;
}

