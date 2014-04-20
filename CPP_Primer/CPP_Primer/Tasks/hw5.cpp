#include <iostream>
#include <string>

void initializeData(std::string n[], int s[], int size);
void sortData(std::string n[], int s[], int size);
void displayData(std::string n[], int s[], int size);

int main()
{
        const int size(5);
        std::string name[size];
        int score[size];

        initializeData(name, score, size);
        sortData(name, score, size);
        displayData(name, score, size);

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
