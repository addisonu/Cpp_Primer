//poker_outcome.cpp
//User can play a simple poker game

#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>

bool containsPair(int hand[]);
bool containsTwoPair(int hand[]);
bool containsThreeOfaKind(int hand[]);
bool containsStraight(int hand[]);
bool containsFullHouse(int hand[]);
bool containsFourOfaKind(int hand[]);

int main()
{	
	short card(0);
	int hand[5];
	
	std::cout << "Enter five numeric card numbers between 2 and 9. Don't enter face cards." << std::endl;
	
	for(int n = 0; n < 5; n++){
		std::cout << "Card " << n + 1 << " :";
		std::cin >> card;

		if(std::cin.good() && card >= 2 && card <= 9){
		hand[n] = card;
		}
		else if(std::cin.good() && (card < 2 || card > 9)){
                        std::cout << "Please enter an integer between 2 and 9." << std::endl;
                        n--;
                }
		else if(!(std::cin >> card)){
			std::cout << "Please enter an integer between 2 and 9. To continue entering numbers, press the return key." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			n--;
		}
		/*else if(std::cin.good() && (card < 2 || card > 9)){
			std::cout << "Please enter an integer between 2 and 9." << std::endl;
			n--;
		}*/
	}
	
	
		if(containsFourOfaKind(hand)){
	        	std::cout << "Four of a kind!!" << std::endl;      
                }
		else if(containsFullHouse(hand)){ 
                	std::cout << "Full house!!" << std::endl;
                }
		else if(containsStraight(hand)){
			std::cout << "Straight!!" << std::endl;
                }
		else if(containsThreeOfaKind(hand)){
			std::cout << "Three of a kind!!" << std::endl;
                }
		else if(containsTwoPair(hand)){
			std::cout << "Two pair!!" << std::endl;
                }
		else if(containsPair(hand)){
                	std::cout << "Pair!!" << std::endl;
                }
		else{
			std::cout << "High card!!" << std::endl;
		}
	
	return 0;
}

bool containsFourOfaKind(int hand[]){
	bool outcome(0);
	int count(0), card(0), nhand(5), number(4); 
	int freq(nhand - number);

	for(int m = 0; m <= freq; m++){
		if(count < number){
			count = 1;
			card = hand[m];
			for(int n = m + 1; n < nhand; n++){
				if(hand[n] == card){
					count++;
				}
			}	
		}	
	}
		if(count >= number){
                        outcome = 1;
                }
	return outcome;
}

bool containsFullHouse(int hand[]){
	bool outcome(0);
        int count(0), card(0), pair(0), trpl(0), nhand(5), number(2), prcard(0), trcard(0);
        int freq(nhand - number);

        for(int m = 0; m <= freq; m++){
                if(count < number){
                        count = 1;
                        card = hand[m];
                        for(int n = m + 1; n < nhand; n++){
                                if(hand[n] == card){
                                        count++;
                                }
                        }
                        if(count == number && card != trcard){
                                count = 0;
				prcard = card;
                                pair++;
                        }
			else if(count == (number + 1) && card != prcard){
				count = 0;
				trcard = card;
				trpl++;
			}
			else if(card == trcard || card == prcard){
				count = 0;
			}
                }
	}
                if(pair == 1 && trpl == 1){
                        outcome = 1;
                }
        return outcome;
}

bool containsStraight(int hand[]){
	bool outcome(0);
	int count(0), nhand = 5;
	std::vector<int> vsort(hand, hand + nhand);

	std::sort(vsort.begin(), vsort.end());

	for(int n = 0; n < nhand - 1; n++){
		if(vsort[n + 1] == vsort[n] + 1){
		count++;
		}
	} 
		if(count == 4){
			outcome = true;
		}
	return outcome;
}

bool containsThreeOfaKind(int hand[]){
        bool outcome(0);
        int count(0), card(0), nhand(5), number(3);
        int freq(nhand - number);

        for(int m = 0; m <= freq; m++){
                if(count < number){
                        count = 1;
                        card = hand[m];
                        for(int n = m + 1; n < nhand; n++){
                                if(hand[n] == card){
                                        count++;
                                }
                        }
                }
        }
                if(count == number){
                        outcome = 1;
                }
        return outcome;
}

bool containsPair(int hand[]){
        bool outcome(0);
        int count(0), card(0), pair(0), nhand(5), number(2);
        int freq(nhand - number);

        for(int m = 0; m <= freq; m++){
                if(count < number){
                        count = 1;
                        card = hand[m];
                        for(int n = m + 1; n < nhand; n++){
                                if(hand[n] == card){
                                        count++;
                                }
                        }
			if(count == number){
				count = 0;
				pair++;
			}
                }
	}
                if(pair == 1){
                        outcome = 1;
                }
        return outcome;
}

bool containsTwoPair(int hand[]){
        bool outcome(0);
        int count(0), card(0), pair(0), nhand(5), number(2);
        int freq(nhand - number);

        for(int m = 0; m <= freq; m++){
                if(count < number){
                        count = 1;
                        card = hand[m];
                        for(int n = m + 1; n < nhand; n++){
                                if(hand[n] == card){
                                        count++;
                                }
                        }
                        if(count == number){
                                count = 0;
                                pair++;
                        }
                }
        }
                if(pair == 2){
                        outcome = 1;
                }
        return outcome;
}
