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
#include <algorithm>
#include <cmath>
#include "Node.h"

Node EightPuzzle::move(/*const*/ Node &node, MOVE move/*const std::string &move*/)
{
    // create new node to hold new state
    Node new_node;
    auto state = node.state;

    // get position of blank tile to move in puzzle
    auto blank_pos = state.find('b');

    // check that move is possible and determine new state
    if(move == MOVE::LEFT && (blank_pos != 0 && blank_pos != 3 && blank_pos != 6)){
        auto neighbor_tile = state[blank_pos - 1];
        state[blank_pos - 1] = 'b';
        state[blank_pos] = neighbor_tile;

        try{
            // check if new state is reversal of previous move
            tree.get_explored_set()->at(state);
            // node has already been generated, fall through to return statement
            //new_node.parent = node.parent;// debugging: fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            // new_node hasn't been generated before, update new node
            new_node.parent = &node;
            new_node.state = state;
            new_node.action = "left";
            new_node.path_cost = node.path_cost;
        }
    }
    else if(move == MOVE::UP && (blank_pos != 0 && blank_pos != 1 && blank_pos != 2)){
        auto neighbor_tile = state[blank_pos - 3];
        state[blank_pos - 3] = 'b';
        state[blank_pos] = neighbor_tile;

        try{
            // check if new state is reversal of previous move
            tree.get_explored_set()->at(state);
            // node has already been generated, fall through to return statement
            //new_node.parent = node.parent;// debugging: fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            // new_node hasn't been generated before, update new node
            new_node.parent = &node;
            new_node.state = state;
            new_node.action = "up";
            new_node.path_cost = node.path_cost;
        }
    }
    else if(move == MOVE::RIGHT && (blank_pos != 2 && blank_pos != 5 && blank_pos != 8)){
        auto neighbor_tile = state[blank_pos + 1];
        state[blank_pos + 1] = 'b';
        state[blank_pos] = neighbor_tile;

        try{
            // check if new state is reversal of previous move
            tree.get_explored_set()->at(state);
            // node has already been generated, fall through to return statement
            //new_node.parent = node.parent;// debugging: fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            // new_node hasn't been generated before, update new node
            new_node.parent = &node;
            new_node.state = state;
            new_node.action = "right";
            new_node.path_cost = node.path_cost;
        }
    }
    else if(move == MOVE::DOWN && (blank_pos != 6 && blank_pos != 7 && blank_pos != 8)){
        auto neighbor_tile = state[blank_pos + 3];
        state[blank_pos + 3] = 'b';
        state[blank_pos] = neighbor_tile;

        try{
            // check if new state is reversal of previous move
            tree.get_explored_set()->at(state);
            // node has already been generated, fall through to return statement
            //new_node.parent = node.parent;// debugging: fix to avoid creating new node
        }
        catch(const std::out_of_range& oor){
            // new_node hasn't been generated before, update new node
            new_node.parent = &node;
            new_node.state = state;
            new_node.action = "down";
            new_node.path_cost = node.path_cost;
        }
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
    // the sum of the horizontal and vertical distances of the tiles from their goal positions
    // will return the h(n) portion of f(n)
    unsigned ver_dis(0);
    unsigned hor_dis(0);

    // pos / 3 will give row, pos % 3 will give col
    for(std::size_t pos = 0; pos != goal_state.size(); ++pos){
        if(goal_state[pos] != node.state[pos]){
            // find col and row of goal state
            auto goal_row = pos / 3;
            auto goal_col = pos % 3;

            // find col and row of node state
            std::size_t node_pos = node.state.find(goal_state[pos]);
            auto node_row = node_pos / 3;
            auto node_col = node_pos % 3;

            ver_dis += std::abs(static_cast<double>(goal_row - node_row));
            hor_dis += std::abs(static_cast<double>(goal_col - node_col));
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

// NOTE: need to generate real g(n) not use from heuristic
void EightPuzzle::a_star_search(const std::string &initial_state, Node &result)
{
    /*// add roo to frontier_set
    Node root;
    root.state = initial_state;
    tree.get_frontier_set()->push(root);

    // get top node and start searching for goal
    Node *current = nullptr;
    while(!tree.get_frontier_set().empty() && (current = tree.get_frontier_set()->top().state)) && goal_test(goal_state, current.state){
        if(current.state == initial_state){
            continue; // don't process root node
        }
        //Node current_node = tree.get_frontier_set()->top();
        tree.get_frontier_set()->pop();

        // if the node isn't the goal generate it's successors and check 3 cases:
        for(int i = 0; i != 4; ++i)// 4 is because there are four moves to generate a child: left, up, right, down
            auto child = move(current, i);
            Node former_child;
            bool found(false);
            for(auto ele : tree.get_frontier_set()){
                if(ele.state == child.state){
                    found = true;
                    former_child = ele;
                    break;
                }
            }
        if(found && former_child.path_cost > child.path_cost){
        // child is in frontier_set with greater path_cost, update child
            former_child = child;
        }
        else{
            try{
                auto former_child = get_tree()->get_explored_set()->at(state);

                // child is in the explored_set with greater path_cost
                // update child and move to frontier_set
                if(former_child.path_cost > child.path_cost){
                    former_child = child;
                }
            }
            catch(const std::out_of_range& oor){
                // child is in neither frontier_set nor explored_set
                // add child to frontier
                tree.get_frontier_set()->push(child);
            }
        }
        // add current node to explored_set
        explored_set[current.state] = current;
    }
    result = tree.get_frontier_set()->top();
*/
}

void EightPuzzle::ida_search(const std::string &initial_state, Node &result)
{
    Node root;
    //root.state;
}

void EightPuzzle::df_branch_bound_search(const std::string &initial_state, Node &result)
{

}
