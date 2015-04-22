// DATE : 04/18/15
// FILE : cat_vs_dog.cpp
// DESC : Finds the maximum number of satisfied voters for each testcase
// INPUT //
// n testcases, n < = 100
// per testcase:
// c, d, v (1 ≤ c, d ≤ 100 and 0 ≤ v ≤ 500): the number of cats, dogs, and voters.
// v lines with two pet identifiers : C# || D#, wher the firt identifier is the pet to keep and second is pet release
// OUTPUT //
// Per testcase: One line with the maximum possible number of satisfied voters for the show.

// LEFT OFF //
/*
 * Working out how to set the frequency of pets to keep and dismis, single set freq needs to be changed to two sets keep and dis
 * Implementing incorrect solution in attempt to better understand problem
 */

// BUGS //
/*
 * Current implementation will not give solution; try maximum spanning graph
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <exception>
#include <utility>

int main()
{
// Create var : testcases (n), voters (v), cats (c), dogs (d)
    unsigned n(0), v(0), c(0), d(0);

// Take user input for : number of testcases (n), voters (v), cats (c), dogs (d)
    std::cout << "How many testcases will be run?\n";
    std::cin >> n;

// Create set to hold frequency of each request to keep or dismiss an animal, size n
    using pet = std::pair<std::string, unsigned>;
    typedef std::pair<unsigned, unsigned> vote;
    std::map<std::string, vote> freq;

// For each test case:
    for(unsigned i = 0; i != n; ++i){
        std::vector<std::pair<pet, pet>> testcase;

// Get values for testcase
        std::cout << "How many cats are there?\n";
        std::cin >> c;
        std::cout << "How many dogs are there?\n";
        std::cin >> d;
        std::cout << "How many voters are there?\n";
        std::cin >> v;

// Store testcase in vector
        std::pair<pet, pet> test;

        for(unsigned j = 0; j != v; ++j){
            std::cout << "Enter the pet the voter wants to keep.\n";
            std::cin >> test.first.first;

            std::cout << "Enter the pet the voter wants to dismiss.\n";
            std::cin >> test.second.first;

            testcase.push_back(test);

// Increment frequency for pet to be kept
            try{
                ++(freq.at(test.first.first).first);
            }
            catch(std::out_of_range e){
                freq.insert(std::pair<std::string, vote>(test.first.first, vote(1,0)));
            }
// Increment frequency for pet to be dismissed
           try{
                ++(freq.at(test.second.first).second);
            }
            catch(std::out_of_range e){
                freq.insert(std::pair<std::string, vote>(test.second.first, vote(0,1)));
            }
        }
// Get the number of times a pet is kept/dismissed
// Transfer frequency of each pet to testcase
        for(auto &ele : testcase){
            ele.first.second += freq[ele.first.first].first;
            ele.second.second += freq[ele.second.first].second;
        }
/*      std::cout << "Votes for this testcase :\n";
        for(auto ele : testcase)
            std::cout << ele.first.first << " : " << ele.first.second << ", " << ele.second.first << " : " << ele.second.second << std::endl;
*/
// Create vector<vector> eq_freq to hold pets kept/dismiessed equal number of times
    using pet_freq = decltype(freq.begin());
    std::vector<std::pair<std::string, vote>> eq_freq;

// Create var to hold max number of happy voters
    std::size_t happy(0);

    for(auto ele : testcase){

// If pet1.kept > pet1.dismiss && pet2.kept < pet2.dismiss increment happy
        std::pair<std::string, vote> check = std::pair<std::string, vote>(ele.first.first, freq[ele.first.first]);
        if(check.second.first > check.second.second)
            ++happy;

// Else if pet1.kept == pet1.dismiss || pet2.kept == pet2.dismiss
        else if(check.second.first == check.second.second)
           // eq_freq.push_back(check);
        else if()
    }
    for(auto ele : eq_freq){
        if(

    }
    }
// IMP1 : sort vector, print max number of happy voters
        /*std::cout << "The max number of voters who get their choices satisfied " << max_vt << std::endl;*/
}
// --- pet1.kept == pet1.dismiss && (pet2.kept < pet2.dismiss || pet2.kept == pet2.dismiss)
// ---- add to pet1 eq_freq, then add pet2 to: ==, dismiss, or keep subvector
// --- (pet1.kept > pet1.dismiss || pet1.kept == pet1.dismiss) && pet2.kept == pet2.dismiss
// ---- add pet2 to eq_freq, then add pet1 to: ==, dismiss, or keep subvector
// - for each == pet, sum how many edges will be kept/dismissed/==, based ono above rules
// -- if kept sum > dismiss sum, kept, else dismiss
// --- add kept or dismissed sum to happy
// -- else if == > (kept && dismiss), push into another vector, still_equal
// - sort still_equal
// -- continue until still_equlal.size() == 0
