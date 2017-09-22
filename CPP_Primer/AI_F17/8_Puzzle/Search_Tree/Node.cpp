//AUTHOR: NA
//DATE: 09/19/17
//FILE: Node.cpp
//DESC: Implement all 8-puzzle search elements

#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
#include <exception>
#include "Node.h"

Node move(const &Node node, const std::string &move)
{
    Node new_node;
    auto state = node.state;
    auto blank_pos = state.find('b');

    // check that move is possible and determine new state
    if(move == "left" && (pos != 0 && pos != 3 && pos != 6)){
        auto neighbor = state[pos - 1];
        state[pos - 1] = 'b';
        state[pos] = neighbor;

        try{
            // check if node is sibling or child of current node
            get_tree()->get_explored_set()->at(state);
            new_node.parent = node.parent;// fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            new_node.parent = &node;
        }
        // update new node
        new_node.state = state;
        new_node.action = "left";
    }
    else if(move == "up" && (pos != 0 && pos != 1 && pos != 2)){
        auto neighbor = state[pos - 3];
        state[pos - 3] = 'b';
        state[pos] = neighbor;

        try{
            // check if node is sibling or child of current node
            get_tree()->get_explored_set()->at(state);
            new_node.parent = node.parent;// fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            new_node.parent = &node;
        }
        // update new node
        new_node.state = state;
        new_node.action = "up";
    }
    else if(move == "right" && (pos != 2 && pos != 5 && pos !- 8)){
        auto neighbor = state[pos + 1];
        state[pos + 1] = 'b';
        state[pos] = neighbor;

        try{
            // check if node is sibling or child of current node
            get_tree()->get_explored_set()->at(state);
            new_node.parent = node.parent;// fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            new_node.parent = &node;
        }
        // update new node
        new_node.state = state;
        new_node.action = "right";
    }
    else if(move == "down" && (pos != 6 && pos != 7 && pos != 8)){
        auto neighbor = state[pos + 3];
        state[pos + 3] = 'b';
        state[pos] = neighbor;

        try{
            // check if node is sibling or child of current node
            get_tree()->get_explored_set()->at(state);
            new_node.parent = node.parent;// fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            new_node.parent = &node;
        }
        // update new node
        new_node.state = state;
        new_node.action = "down";
    }
    else{
        return node;
    }
    return node;
}

bool goal_test(std::string goal_state, std::string test_state)
{
    return goal_state == test_state;
}
/*
double EightPuzzle::search_time()
{
// use <ctime> clock function
    return 0;
}
*/
unsigned EightPuzzle::manhattan_heuristic(const Node &node)
{
    // the sum of the distances of the tiles from their goal positions. Because tiles
    // cannot move along diagonals, the distance we will count is the sum of the horizontal
    // and vertical distances
    unsigned ver_dis(0);
    unsigned hor_dis(0);

    for(std::size_t i = 0; i != goal_state.size(); ++i){
        if(goal_state[i] != node.state[i]){
            ver_dis += pos / 3;
            hor_dis += pos % 3;
        }
    }
    return ver_dis + hor_dis;
}

unsigned EightPuzzle::misplaced_tile_heuristic(const Node &node)
{
    // the number of misplaced tiles
    unsigned misplaced_tile(0);
    for(std::size_t i = 0; i != goal_state.size(); ++i){
        if(goal_state[i] != node.state[i]){
            ++misplaced_tile;
        }
    }
    return misplaced_tile;
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
