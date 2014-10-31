//Update high scores to use structs

#include <iostream>
#include <string>
#include <new>

struct highscore{
        int score = 0;
        char *pnt_name = nullptr;
};

void initializeData(highscore *pnt_hs, int size);
void sortData(highscore *pnt_hs, int size);
void displayData(highscore *pnt_hs, int size);

int main()
{
	int size(0);

	std::cout << "How many scores will you enter?\n";
	std::cin >> size;

	highscore *pnt_hs = new highscore[size];
	
        initializeData(pnt_hs, size);
        sortData(pnt_hs, size);
        displayData(pnt_hs, size);

	delete [] pnt_hs;

        return 0;
}

void initializeData(highscore *pnt_hs, int size)
{
	std::string name;
	
        for(int i = 0; i < size; i++){
                std::cout << "Enter the name for score #" << i + 1 << ": ";
                std::cin >> name;

		pnt_hs[i].pnt_name = new char[name.length() + 1];
		strcpy(pnt_hs[i].pnt_name, name.c_str());		
		
                std::cout << "Enter the score for score #" << i + 1 << ": ";
                std::cin >> pnt_hs[i].score;
	}
	      
}

void sortData(highscore *pnt_hs, int size)
{
        int tmps(0), cnt(1);
        std::string tmpn;
	char *pnt_tmpn = nullptr;

        while(cnt != 0){
                cnt = 0;
                for(int i = 0; i < size - 1; i++){
                        if(pnt_hs[i].score < pnt_hs[i + 1].score){              
				tmps = pnt_hs[i].score;
				pnt_hs[i].score = pnt_hs[i + 1].score;
				pnt_hs[i + 1].score = tmps;
				pnt_tmpn = new char[strlen(pnt_hs[i].pnt_name) + 1];
				strcpy(pnt_tmpn, pnt_hs[i].pnt_name);
				pnt_hs[i].pnt_name = pnt_hs[i + 1].pnt_name;
				pnt_hs[i + 1].pnt_name = pnt_tmpn;
				cnt++;
                        }
                }
        }
	delete [] pnt_tmpn;
}

void displayData(highscore *pnt_hs, int size)
{
        std::cout << "Top Scorers:" << std::endl;
        for(int i = 0; i < size; i++){
                std::cout << pnt_hs[i].pnt_name << ": " << pnt_hs[i].score << std::endl;
        }
}
