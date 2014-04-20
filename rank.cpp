#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//using namespace std;

int main()
{
/*	vector<string> strsort;
	
	strsort.push_back("21 food");
	strsort.push_back("21 ask");
	strsort.push_back("21 back");

	sort(strsort.begin(), strsort.end());

	for(int i = 0; i < strsort.size(); i++){
		cout << strsort[i] << endl;
	}*/
	int n(0), m(0), cnt(0), tmp_freq(0);
	
	
	struct song_data {
		double freq = 0;
		std::string name;
	};

	//std::vector<song_data> data(n);

	std::cout << "Please enter the number of songs on the album.\n";
	std::cin >> n;
	std::cout << "Please enter the number of songs to rank.\n";
	std::cin >> m;
	std::cout << "Please enter each song title preceeded by the number"
	<< " of times it was played. There should be white space between the"
	<< " frequency of a song and its title.\n";
	
	
	std::vector<song_data> data(n);
	song_data tmp_data;
	//if(cin){		
	while(std::cin >> data[cnt].freq >> data[cnt].name){
		//std::cout << "freq =" << data[cnt].freq << std::endl;
		//std::cout << "name =" << data[cnt].name << std::endl;
		cnt++;
	}
	//}
	for( int i = 0; i < data.size(); i++){
		data[i].freq /= (i + 1.0);
		std::cout << "freq = " << data[i].freq << std::endl;
	}
	
	while(cnt != 0){
		cnt = 0;
		for(int i = 0; i < data.size() - 1; i++){
			if(data[i].freq < data[i + 1].freq){
				tmp_data = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp_data;
				cnt++;
			}
		}	
	}
	for(int i = 0; i < data.size(); i++){
		std::cout << "freq = " << data[i].freq << std::endl;
		std::cout << "name = " << data[i].name << std::endl;	
	}
	return 0;
}
