/*
*Algorithm:
*Create two variables, one for holding input of asterisks number, the other to let user continue program
*Loop to run program until user is finished
*Loop to print out specified number of asterisks
*Prompt user to continue/end program
*/

#include <iostream>

int main()
{
	int number(0);
	char cont_prog('y');
		while(cont_prog == 'y'){	
			std::cout << "How many asterisks would you like to print?\n";
			std::cin >> number;
				for(int n = 0; n < number; n++){
					std::cout << "*";	
				}
			std::cout << std::endl;	
			std::cout << "Would you like to continue the program? Enter the letter 'y' to continue or any other key to exit the program.\n";
			std::cin >> cont_prog; 
		}	
	return 0;
}
