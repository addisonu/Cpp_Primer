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
 * Debugging
 */

// BUGS //
/*
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <exception>
#include <utility>

int main()
{
// ALIAS //
    using pet = std::string;
    using freq = std::size_t;
    using edge = std::pair<std::pair<pet, pet>, freq>;
    using vote_info = std::pair<pet, pet>;

// INPUT var //
    std::size_t n(0), v(0), c(0), d(0);

// - get user input for n, c, d, v
    std::cout << "Enter the number of testcase.\n";
    std::cin >> n;
    std::cout << "Enter the number of voters.\n";
    std::cin >> v;
    std::cout << "Enter the number of cats.\n";
    std::cin >> c;
    std::cout << "Enter the number of dogs.\n";
    std::cin >> d;

// - for each test case
    for(unsigned i = 0; i != n; ++i){

// -- create var happy to hold max number of happy voters
        unsigned happy(0);

// -- create adjacency matrix, graph
        //typedef std::size_t (*ptc)[c];
        std::size_t **graph = new std::size_t*[c];
        for(auto k = graph; k != graph + c; ++k)
            *k = new std::size_t[d]();

// -- create edge frequency vector, weight
        std::vector<edge> weight;

// -- get user input for each vote
        for(unsigned j = 0; j != v; ++j){

            vote_info vote;
            std::cout << "You must vote to keep one pet and to dismiss one pet. Vote for one cat and one dog.\n";
            std::cout << "Enter the pet you would like to stay.\n";
            std::cin >> vote.first;
            std::cout << "Enter the pet you would like to dismiss.\n";
            std::cin >> vote.second;

// --- store each vote in graph
            pet cat, dog;
            std::size_t cat_idx(0);
            std::size_t dog_idx(0);
 
            if(vote.first[1] == tolower('c')){
                cat = vote.first;
                dog = vote.second;
                cat_idx = atoi(cat.substr(1).c_str());
                dog_idx = atoi(cat.substr(1).c_str());
            }
            else{
                cat_idx = atoi(vote.second.substr(1).c_str());
                dog_idx = atoi(vote.first.substr(1).c_str());
            }
            ++graph[cat_idx][dog_idx];
        }
// -- store each vote in weight
            for(std::size_t l = 0; l != c; ++l){
                for(std::size_t m = 0; m != d; ++m){
                    std::stringstream ss;
                    ss << (l + 1);
                    pet wcat = "c" + ss.str();
                    ss << (m + 1);
                    pet wdog = "d" + ss.str();
                    edge edg(vote_info(wcat, wdog), graph[l + 1][m + 1]);
                    weight.push_back(edg);
                }
            }

// -- sort weight in descending order
        std::sort(weight.begin(), weight.end(), [ ](edge p1, edge p2) -> bool { return p1.second > p2.second; });

// -- create connections map of edges
        std::map<pet, std::pair<std::vector<pet>, std::size_t>> edge_set;
        auto wgt = weight.begin();
// -- add edge to edges, continue while there are (c + d) - 1 elements in edges
        while(edge_set.size() < (c + d - 1)){

// --- check if edge will make a circuit
            try{
                if(edge_set.at(wgt.first)){
                    for(auto ele : edge_set){
                        edge check;
                        if((check = ele.second.find(wgt.first.second)) != ele.second.end())

// ---- yes => don't add edge
                            if(ele.first.find(check.second.first) == ele.end())
// ---- no => add adge
                                edge_set.insert(wgt);
                    }
                }
            }
            catch(std::out_of_range e){
                edge_set.insert(wgt);
            }
// ----- add edge weight to happy
            happy += wgt.second.second;
        }
    }
    return 0;
}
