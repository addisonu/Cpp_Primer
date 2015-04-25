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
 * Testing and Debugging
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

// ALIAS //
    using pet = std::string;
    using freq = std::size_t;
    using edge = std::pair<std::pair<pet, freq>, std::pair<pet, freq>>;
    using vote = std::pair<pet, freq>;
    //using wgt_ele = 

bool is_circuit(const edge &edg, std::pair<freq, freq> **graph, const std::map<pet, std::vector<pet>> &edge_set);
std::size_t max(freq freq1, freq freq2);

int main()
{
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
        std::pair<freq, freq> **graph = new std::pair<freq, freq>*[c];
        for(auto k = graph; k != graph + c; ++k)
            *k = new std::pair<freq, freq>[d]();

// -- create edge frequency vector, weight
        std::vector<edge> weight;

// -- get user input for each vote
        for(unsigned j = 0; j != v; ++j){

            edge vote;
            std::cout << "You must vote to keep one pet and to dismiss one pet. Vote for one cat and one dog.\n";
            std::cout << "Enter the pet you would like to stay.\n";
            std::cin >> vote.first.first;
            std::cout << "Enter the pet you would like to dismiss.\n";
            std::cin >> vote.second.first;

// --- store each vote in graph
            pet cat, dog;
            std::size_t cat_idx(0);
            std::size_t dog_idx(0);
 
            if(vote.first.first[0] == tolower('c')){
                cat = vote.first.first;
                dog = vote.second.first;
                cat_idx = atoi(cat.substr(1).c_str());
                dog_idx = atoi(dog.substr(1).c_str());
                ++graph[cat_idx][dog_idx].first;
            }
            else if(vote.first.first[0] == tolower('d')){
                dog = vote.first.first;
                cat = vote.second.first;
                cat_idx = atoi(cat.substr(1).c_str());
                dog_idx = atoi(dog.substr(1).c_str());
                ++graph[cat_idx][dog_idx].second;
            }
        }
// -- store each vote in weight
            for(std::size_t l = 0; l != c; ++l){
                for(std::size_t m = 0; m != d; ++m){
                    std::stringstream ss;
                    ss << (l + 1);
                    pet wcat = "c" + ss.str();
                    ss << (m + 1);
                    pet wdog = "d" + ss.str();
                    edge edg(vote(wcat, graph[l + 1][m + 1].first), vote(wdog, graph[l + 1][m + 1].second));
                    weight.push_back(edg);
                }
            }

// -- sort weight in descending order
        std::sort(weight.begin(), weight.end(), [ ](edge p1, edge p2) -> bool { return max(p1.first.second, p1.second.second) > max(p2.first.second, p2.second.second); });

// -- create connections map of edges, first element is a cat, second element of all dogs that an edge is shared with
        std::map<pet, std::vector<pet>> edge_set;

// -- add edge to edges, continue while there are < (c + d) - 1 elements in edges
        auto wgt_it = weight.begin();
        while(wgt_it != weight.end() && edge_set.size() < (c + d - 1)){

// --- check if edge will make a circuit if yes => don't add edge, no => add adge
            if(!is_circuit(*wgt_it, graph, edge_set)){
                //try{
                    if(edge_set.find(wgt_it->first.first) == edge_set.end()){
                        std::vector<pet> dog_edg{wgt_it->second.first};
                        edge_set.insert(std::pair<pet,std::vector<pet>>(wgt_it->first.first, dog_edg));
                    }
                    else
                        edge_set[wgt_it->first.first].push_back(wgt_it->second.first);
                    
                //}
                //catch(std::out_of_range e){
                  //  edge_set.insert(wgt);
                //}
// ----- add edge weight to happy
                happy += max(wgt_it->first.second, wgt_it->second.second);
                ++wgt_it;
            }
        }
    }
    return 0;
}

bool is_circuit(const edge &edg, std::pair<freq, freq> **graph, const std::map<pet, std::vector<pet>> &edge_set)
{
    pet cat = edg.first.first;
    std::size_t cat_idx = atoi(cat.substr(1).c_str());
    pet dog = edg.second.first;
    std::size_t dog_idx = atoi(dog.substr(1).c_str());

    for(auto ele : edge_set){
        std::size_t ecat_idx = atoi(ele.first.substr(1).c_str());

        if(graph[ecat_idx][dog_idx].first || graph[ecat_idx][dog_idx].second){

            for(auto edog : ele.second){
                std::size_t edog_idx = atoi(edog.substr(1).c_str());

                if(graph[cat_idx][edog_idx].first || graph[cat_idx][edog_idx].second)
                    return true;
            }
        }
    }
    return false;
}

std::size_t max(freq freq1, freq freq2)
{
    if(freq1 > freq2)
        return freq1;
    else
        return freq2;
}
