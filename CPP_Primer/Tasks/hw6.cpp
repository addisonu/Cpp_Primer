//Update high scores to use dynamic arrays

#include <iostream>
#include <string>
#include <new>

void initializeData(std::string n[], int s[], int size);
void sortData(std::string n[], int s[], int size);
void displayData(std::string n[], int s[], int size);

int main()
{
	int size(0);

	std::cout << "How many scores will you enter?\n";
	std::cin >> size;
	
	std::string *pname = new std::string[size];
	int *pscore = new int[size];	
	
        initializeData(pname, pscore, size);
        sortData(pname, pscore, size);
        displayData(pname, pscore, size);

	delete [] pname;
	delete [] pscore;

        return 0;
}

void initializeData(std::string name[], int score[], int size)
{
        for(int i = 0; i < size; i++){
                std::cout << "Enter the name for score #" << i + 1 << ": ";
                std::cin >> name[i];
                std::cout << "Enter the score for score #" << i + 1 << ": ";
                std::cin >> score[i];
        }
}

void sortData(std::string name[], int score[], int size)
{
        int tmps(0), cnt(1);
        std::string tmpn;
        while(cnt != 0){
                cnt = 0;
                for(int i = 0; i < size - 1; i++){
                        if(score[i] < score[i + 1]){
                                tmps = score[i];
                                score[i] = score[i + 1];
                                score[i + 1] = tmps;
                                tmpn = name[i];
                                name[i] = name[i + 1];
                                name[i + 1] = tmpn;
                                cnt++;

                        }
                }

        }
}

void displayData(std::string name[], int score[], int size)
{
        std::cout << "Top Scorers:" << std::endl;
        for(int i = 0; i < size; i++){
                std::cout << name[i] << ": " << score[i] << std::endl;
        }
}
