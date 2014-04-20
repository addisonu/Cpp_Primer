//rev_bi.cpp
//reverse binary represenation of a decimal number, then prints the new number

/*
*Algorithm:
*Create variable to hold N, the user's input int
*Store binary representation of N in a string
*Reverse string/vect
*Convert back to decimal rep
*Print int
*/

#include <iostream>
#include <vector>
#include <cmath>

int main()
{

int n(0), m(0), i(0), powr(0), conv_num(0);
std::vector<int> conv;
std::vector<int> conv_bi;

std::cout << "Please enter an integer n, with 1 ≤ n ≤ 1000000000.\n";
std::cin >> n;
conv_num = n;

	if(n != 1 && n != 0){
		//find length of binary number
			while(n > (pow(2, i))){
				i++;
			}
			i--;
			powr = i;

		//load conv with powers of 2
			for(; i >= 0; i--){
				conv.push_back(pow(2, i));
				conv_bi.push_back(7);//load with arbitray int != 1 || != 0
			}
				std::cout << std::endl;
		//find binary number with decimal to binary transformation
			
			for(m = 0; m <= powr; m++){
				if((conv_num - conv[m]) >= 0){
					conv_bi[m] = 1;
					conv_num -= conv[m]; 
				}
				else{
					conv_bi[m] = 0;
				}
			}
		//reverse conv_bi
			std::reverse(conv_bi.begin(), conv_bi.end());
		//convert binary number back to decimal
			for(m = 0; m <= powr; m++){
				conv_num += (conv[m]*conv_bi[m]);		
			}
	}
	else{
		conv_bi.push_back(n);
	}
	
	std::cout << "The decimal integer resulting from the binary transformation is "<< conv_num << std::endl;

return 0;
} 
