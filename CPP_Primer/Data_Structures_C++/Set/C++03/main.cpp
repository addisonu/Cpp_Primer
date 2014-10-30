//Test set class

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Set.h"

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

typedef double value_type;
typedef std::size_t size_type;
static const size_type CAPACITY = 15;

int main()
{
std::string div(40, '=');
cout << "Testing DEFAULT CONSTRUCTOR" << endl;
cout << div << endl;
cout << "Expected output : { } " << endl;
//Test code
Set s1;
cout << s1 << endl;
cout << div << endl;
cout << "Testing COPY CONSTRUCTOR" << endl;
cout << div << endl;
cout << "Expected output : {9.87, }" << endl;
//Test code
double val1 = 9.87;
s1.insert(val1);
Set s2(s1);
cout << "s2" << '\n' << (s2) << endl;
cout << div << endl;
cout << "Testing ISFULL" << endl;
cout << div << endl;
cout << "Expected output : s1 = false, s5 = {1, 1, 1, ...}, s5 = true" << endl;
//Test code
cout << "s1 is full: " << s1.isFull() << endl;
Set s5;
value_type val3(7);
for(int n = 0; n < 5; ++n){
    s5.insert(val3);
}
cout << "s5 = " << (s5) << endl;
cout << "s5 is full: " << s5.isFull() << endl;
cout << div << endl;
cout << "Testing ISEMPTY" << endl;
cout << div << endl;
cout << "Expected output : s6 = true, s2 = false" << endl;
//Test code
Set s6;
cout << s6 << endl;
cout << "s6 is empty: " << s6.isEmpty() << endl;
cout << "s2 is empty: " << s2.isEmpty() << endl;
cout << div << endl;
cout << "Testing INSERT" << endl;
cout << div << endl;
cout << "Expected output : s1 = {7.77, }" << endl;
//Test code
double val2(7.77);
cout << s1 << endl;
s1.insert(val2);
cout << s1 << endl;
cout << div << endl;
cout << "Testing REMOVE" << endl;
cout << div << endl;
cout << "Expected output : s1 = { }" << endl;
//Test code
Set s7;
for(double i = 0; i < CAPACITY; i++){
s7.insert(i);
}
cout << "s7 = " << (s7) << endl;
s7.remove(14);
cout << "s7 = " << (s7) << endl;
cout << s1 << endl;
cout << div << endl;
cout << "Testing CONTAINS" << endl;
cout << div << endl;
cout << "Expected output : s2 = { 7.77, } 7.77 => true, 4.44 => false  " << endl;
//Test code
value_type val4(4.44);
s2.insert(val2);
cout << s2 << endl;
cout << "s2 contains 7.77 : " << s2.contains(val2) << endl;
cout << "s2 contains 4.44 : " << s2.contains(val4) << endl;
cout << div << endl;
cout << "Testing SUBSET" << endl;
cout << div << endl;
cout << "Expected output : s8 = { }, s2 = {7.77}, s1 = { 7.77, 9.87, 4.44} \ns8 > s2 => false \ns8 < s2 => true \ns2 > s1 => false \ns2 < s1 => true" << endl;
//Test code
Set s8;
s1.insert(val4);
cout << "s8 = " << (s8) << endl;
cout << "s2 = " << (s2) << endl;
cout << "s1 = " << (s1) << endl;
cout << "s8 contains the subset s2 : " << s8.subset(s2) << endl;
cout << "s2 contains the subset s8 : " << s2.subset(s8) << endl;
cout << "s2 contains the subset s1 : " << s2.subset(s1) << endl;
cout << "s1 contains the subset s2 : " << s1.subset(s2) << endl;
cout << div << endl;
cout << "Testing  AUNION" << endl;
cout << div << endl;
cout << "Expected output : s1 = { 9.87, 7.77, 4.44, }, s2 = { 9.87, 7.77, 5.55, 6.66,} s3 = {9.87, 7.77, 4.44, 5.55, 6.66}" << endl;
//Test code
value_type val5(5.55), val6(6.66);
s2.insert(val5);
s2.insert(val6);
cout << "s1 = " << (s1) << endl;
cout << "s2 = " << (s2) << endl;
Set s3(s1.aUnion(s2));
cout << "s3 = " << (s3) << endl;
cout << div << endl;
cout << "Testing INTERSECTION" << endl;
cout << div << endl;
cout << "Expected output : s1 = { 9.87, 7.77, 4.44, } s2 = { 9.87, 7.77, 5.55, 6.66, } s4 = {9.87, 7.77}" << endl;
//Test code
cout << "s1 = " << (s1) << endl;
cout << "s2 = " << (s2) << endl;
Set s4(s1.intersection(s2));
cout << "s4 = " << (s4) << endl;
cout << div << endl;
cout << "Testing OPERATOR==" << endl;
cout << div << endl;
cout << "Expected output : s1 = { 9.87, 7.77, 4.44, } s2 = { 9.87, 7.77, 5.55, 6.66, } s9 = { 9.87, 7.77, 4.44, } \ns1 == s2 => false \ns1 == s9 => true " << endl;
//Test code
Set s9(s1);
cout << "s1 = " << (s1) << endl;
cout << "s2 = " << (s2) << endl;
cout << "s9 = " << (s9) << endl;
cout << "s1 == s2 : " << (s1 == s2) << endl;
cout << "s1 == s9 : " << (s1 == s9) << endl;
cout << div << endl;
cout << "Testing OPERATOR<<" << endl;
cout << div << endl;
cout << "Expected output : s2 = {9.87, }" << endl;
//Test code
cout << "s2" << '\n' << s2 << endl;
cout << div << endl;
return 0;
}
