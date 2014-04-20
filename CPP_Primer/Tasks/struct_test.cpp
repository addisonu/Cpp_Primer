#include <iostream>
#include <string>
#include <cstring>
#include <new>

struct highscore{
	int score = 0;
	size_t namesz = 0;
	char *pnt_name;

};

int main(){

	std::string name;
	highscore test;
	
	std::cout << "What's the name" << std::endl;
	std::cin >> name;
	
	test.pnt_name = new char[name.length() + 1];
	strcpy(test.pnt_name, name.c_str());

	std::cout << "Then name length is " << strlen(test.pnt_name) << std::endl;
	return 0;
}
