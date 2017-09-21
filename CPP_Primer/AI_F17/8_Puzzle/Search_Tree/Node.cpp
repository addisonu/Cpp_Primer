//AUTHOR: NA
//DATE: 09/19/17
//FILE: Node.cpp
//DESC: Implement all 8-puzzle search elements

#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
#include "Node.h"

Node move(const &Node node)
{
    Node node;
    return node;
}

bool goal_test(std::string goal_state, std::string test_state)
{
    return false;
}

double EightPuzzle::search_time()
{

    return 0;
}

unsigned EightPuzzle::manhattan_heuristic(const Node &node)
{

    return 0;
}

unsigned EightPuzzle::misplaced_tile_heuristic(const Node &node)
{

    return 0;
}

void EightPuzzle::a_star_search(Node &result)
{

}

void EightPuzzle::ida_search(Node &result)
{

}

void EightPuzzle::df_branch_bound_search(Node &result)
{

}
