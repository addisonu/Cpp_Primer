//triangle.cpp
//output triangle shape using loops

#include <iostream>

void triangle(int rows);
int main()
{

	triangle(7);
return 0;
}

void triangle(int rows)
{
	for(int i = rows; i >= 1; i--){
		for(int j = i; j >= 1; j--){
			std::cout << "*";
		}
		std::cout << std::endl;
	}

}
