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
#include "Node.h"

Node move(const &Node node, MOVE move/*const std::string &move*/)
{
    //const std::string &move;
    Node new_node;
    auto state = node.state;
    auto blank_pos = state.find('b');

    // check that move is possible and determine new state
    if(move == MOVE::LEFT && (pos != 0 && pos != 3 && pos != 6)){
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
    else if(move == MOVE::UP && (pos != 0 && pos != 1 && pos != 2)){
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
    else if(move == MOVE::RIGHT && (pos != 2 && pos != 5 && pos !- 8)){
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
    else if(move == MOVE::DOWN && (pos != 6 && pos != 7 && pos != 8)){
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

void EightPuzzle::a_star_search(std::string initial_state, Node &result)
{
    // add roo to frontier_set
    Node root;
    root.state = initial_state;
    tree.get_frontier_set()->push(root);

    // get top node and start searching for goal
    Node *current = nullptr;
    //while(!goal_test(goal_state, tree.get_frontier_set()->top().state) && !tree.get_frontier_set().empty()){
    while(!tree.get_frontier_set().empty() && (current = tree.get_frontier_set()->top().state)) && goal_test(goal_state, current.state){
        //Node current_node = tree.get_frontier_set()->top();
        tree.get_frontier_set()->pop();

        // if the node isn't the goal generate it's successors and check 3 cases:
        for(int i = 0; i != 4; ++i)// 4 is because there are four moves to generate a child: left, up, right, down
            auto child = move(current, i);
        if(tree.get_frontier_set()){
        // child is in frontier_set with greater path_cost
        // update child
        }
        else{
            try{
                get_tree()->get_explored_set()->at(state);

                // child is in the explored_set with greater path_cost
                // update child and move to frontier_set
                //child.path_cost
            }
            catch(const std::out_of_range& oor){
                // child is in neither frontier_set nor explored_set
                // add child to frontier
            }
        }
        // add current node to explored_set
        explored_set[current.state] = current;
    }
    result = tree.get_frontier_set()->top();
}

void EightPuzzle::ida_search(Node &result)
{

}

void EightPuzzle::df_branch_bound_search(Node &result)
{

}
