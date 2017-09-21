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
