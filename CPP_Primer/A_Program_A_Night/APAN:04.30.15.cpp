// DATE : 04/30/15
// FILE : APAN.04.30.15.cpp
// DESC : Process grades of students, test, and set using bitwise operations
// Make use of built-in:
// - operator|
// - operator&
// - operator<<

#include <iostream>

int main()
{
// - Create var to process grades
    unsigned long grades(0);
    unsigned int score(0), students(10);

    for(unsigned i = 0; i != students; ++i){

// -- Read grades
        std::cout << "Enter an integer between 0 - 100 inclusive for the student's score.\n";
        std::cin >> score;

// - Use conditional operator to determine if student passed/failed and set grade using bitwise operators
        grades |= (score > 59 ? (1UL << i) : 0UL);
    }

// Print student grades
    std::cout << std::boolalpha;
    for(unsigned j = 0; j != students; ++j){
        std::cout << "student #" << j << " passed? " << static_cast<bool>(grades & (1UL << j)) << std::endl;
    }
    return 0;
}
