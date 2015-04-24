//Review problems for Schaum's ch2
//LEFT OFF : last problem print "nan"
#include <iostream>
#include <cmath>

int main()
{
//2.0 - Write a statement that print "Too many" if the variable count exceeds 100
    unsigned cnt(0);
    while(cnt <= 101){
        ++cnt;
        if(cnt > 100)
            std::cout << "Too many" << std::endl;
    }
//2.1 - Write a program to print the ASCII code for upper case and lower case vowels
    std::cout << int('a') << std::endl;
    std::cout << static_cast<int>('e') << std::endl;
    std::cout << static_cast<int>('i') << std::endl;
    std::cout << static_cast<int>('o') << std::endl;
    std::cout << static_cast<int>('u') << std::endl;
    std::cout << static_cast<int>('A') << std::endl;
    std::cout << static_cast<int>('E') << std::endl;
    std::cout << static_cast<int>('I') << std::endl;
    std::cout << static_cast<int>('O') << std::endl;
    std::cout << static_cast<int>('U') << std::endl;

//2.2 - modify the program on pg. 28 so that it uses type double instead of float. Then compare the difference of the output
    double a, b, c;
    std::cout << "Enter the coefficients of a quadratic equation : " << std::endl;
    std::cout << "\ta : ";
    std::cin >> a;
    std::cout << "\tb : ";
    std::cin >> b;
    std::cout << "\tc : ";
    std::cin >> c;
    std::cout << "The equation is : " << a << "x*x + " << b << "*x + " << c << " = 0" << std::endl;
    double d = b*b - 4*a*c; //discriminant
    double sqrtd = sqrt(d);
    double x1 = (-b + sqrtd)/(2*a);
    double x2 = (-b - sqrtd)/(2*a);
    std::cout << "The solutions are : " << std::endl;
    std::cout << "\tx1 = " << x1 << std::endl;
    std::cout << "\tx2 = " << x2 << std::endl;
    std::cout << "Check : " << std::endl;
    std::cout << "\ta*x1*x1 + b*x1 + c = " << a*x1*x1 + b*x1 + c << std::endl;
    std::cout << "\ta*x2*x2 + b*x2 + c = " << a*x2*x2 + b*x2 + c << std::endl;

//2.3 - Write a program to find which, if any, arithmetic operations can be applied to a variable that will change its value from any of the three numeric constants inf, -inf, and nan to something else
    double c = sqrt(-4);
    double d = ((2 - 3)/0.0);
    double e = ((3 - 2)/0.0);

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    c *= 1;
    d *= 1;
    e *= 1;

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

//2.4 - Write a program that converts inches to centimeters. One inche equals 2.54 centimeters
    double inches(0);
    double cent(2.54);

    std::cout << "What is the value of inches you want to convert to centimeters?\n";
    std::cin >> inches;
    std::cout << "The number of centimeters is " << inches * cent << std::endl;

    return 0;
}
