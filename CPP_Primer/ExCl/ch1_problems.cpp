//Programming problems for ch1

#include <iostream>
#include <string>

int main()
{
//1.6 - write a program that prints the first sentence of the Gettysburg Address or fave quote
    const char quote[]{'I', ' ', 'l', 'o', 'v', 'e', ' ', 'b', 'u', 'b', 'b', 'l', 'e', 's', '\0'};
    
    std::cout << quote << std::endl;

    std::cout << "I love bubbles" << std::endl;

//1.7 - write a program that prints the block letter "B" in a 7x6 grid of stars like this:

    std::cout << " **** " << std::endl;
    std::cout << "*    *" << std::endl;
    std::cout << "*    *" << std::endl;
    std::cout << "**** " << std::endl;
    std::cout << "*    *" << std::endl;
    std::cout << "*    *" << std::endl;
    std::cout << " **** " << std::endl;

//1.8 - write a program that prints the first letter of your last name a block letter in 7x7 grid of stars

    std::cout << "   *   " << std::endl;
    std::cout << "  * *  " << std::endl;
    std::cout << " *   * " << std::endl;
    std::cout << "*******" << std::endl;
    std::cout << "*     *" << std::endl;
    std::cout << "*     *" << std::endl;
    std::cout << "*     *" << std::endl;

//1.9 - write a program that shows what happens when each of the following ten "escape seuences " is printed: \a \b \n \r \t \v \' \" \\ \?
    std::string first("beg"), last("end");
    std::cout << "\\a " << first << "\a" << last << std::endl;
    std::cout << "\\b " << first << "\b" << last << std::endl;
    std::cout << "\\n " << first << "\n" << last << std::endl;
    std::cout << "\\\r " << first << "\r" << last << std::endl;
    std::cout << "\\t " << first << "\t" << last << std::endl;
    std::cout << "\\v " << first << "\v" << last << std::endl;
    std::cout << "\\' " << first << "\'" << last << std::endl;
    std::cout << "\\\" " <<first << "\"" << last << std::endl;
    std::cout << "\\? " << first << "\?" << last << std::endl;

//1.10 - write a program that prints the sum, difference, product, quotient, and remaind of two integers. Initialize the integers with the values 60 and 7.
    int val1 = 60, val2 = 7;
    std::cout << val1 + val2 << std::endl;
    std::cout << val1 - val2 << std::endl;
    std::cout << val1 * val2 << std::endl;
    std::cout << val1 / val2 << std::endl;
    std::cout << val1 % val2 << std::endl;

//1.11 - Write a program that prints the sum, difference, product, quotient, and remainder of two integers that are input interactively
    int inval1(0), inval2(0);
    
    std::cout << "Enter the two integers.\n";
    std::cin >> inval1 >> inval2;
    
    std::cout << "sum = " << inval1 + inval2 << std::endl;
    std::cout << "difference = " << inval1 - inval2 << std::endl;
    std::cout << "product = " << inval1 * inval2 << std::endl;
    std::cout << "quotient = " << inval1 / inval2 << std::endl;
    std::cout << "remainder = " << inval1 % inval2 << std::endl;


//1.12 - Write a test program that shows how your system handles unitialized variables
//Result indicates that each integarl type is set to the maximum value in its range and char is set to ' ' and wchar_t is set to 0
    short s;
    std::cout << "s = " << s << std::endl;
    int i;
    std::cout << "i = " << i << std::endl;
    long l;
    std::cout << "l = " << l << std::endl;
    long long ll;
    std::cout << "ll = " << ll << std::endl;
    float f;
    std::cout << "f = " << f << std::endl;
    double d;
    std::cout << "d = " << d << std::endl;
    char c;
    std::cout << "c = " << c << std::endl;
    bool b;
    std::cout << "b = " << b << std::endl;
    wchar_t wtc;
    std::cout << "wtc = " << wtc << std::endl;

//1.13 - Write a program that causes negative overflow of a variable of type short
    short n = 0;
    n -= 52000;
    std::cout << "n = " << n << std::endl;
    n += 170000;
    std::cout << "n = " << n << std::endl;

//1.14 - Write a program that demostrates round-off error by executing the following steps: 1) initialize a variable of type float with the value 666666, 2) initialize a variable b of type float with the value 1 - 1/a, 3) initialize a variable c of type float with the value 1/b - 1, 4) initialize a variable d of type float with the value 1/c + 1, 5) print all four var, show that d = a, but isn't printed
    float a = 666666, b = (1 - 1/a), c = ( 1/b - 1), d = (1/c + 1);
    std::cout << "a = " << a << '\n' << "b = " << b << '\n' << "c = " << c << '\n' << "d = " << d << std::endl;
    return 0;
}
