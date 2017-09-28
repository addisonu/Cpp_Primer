//AUTHOR: NA
//DATE: 09/19/17
//FILE: Node.cpp
//DESC: Implement all 8-puzzle search elements

#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <climits>
#include <exception>
#include <algorithm>
#include <iostream> // debug
#include <stdlib.h> // debug
#include <cmath>
#include "Node.h"

// update to take different heuristics
Node EightPuzzle::move(Node &node, MOVE move)
{
    // create new node to hold new state
    Node new_node;
    std::string state = node.state;

    // get position of blank tile to move in puzzle
    auto blank_pos = state.find('b');

    // check that move is possible and determine new state
    if(move == MOVE::LEFT && (blank_pos != 0 && blank_pos != 3 && blank_pos != 6)){
        auto neighbor_tile = state[blank_pos - 1];
        state[blank_pos - 1] = 'b';
        state[blank_pos] = neighbor_tile;

        // update new node
        new_node.parent = &node;
        new_node.state = state;
        new_node.action = "left";
        new_node.act_path_cost = node.act_path_cost + 1;
//        new_node.path_cost = manhattan_heuristic(state);
    }
    else if(move == MOVE::UP && (blank_pos != 0 && blank_pos != 1 && blank_pos != 2)){
        auto neighbor_tile = state[blank_pos - 3];
        state[blank_pos - 3] = 'b';
        state[blank_pos] = neighbor_tile;

        // update new node
        new_node.parent = &node;
        new_node.state = state;
        new_node.action = "up";
        new_node.act_path_cost = node.act_path_cost + 1;
  //      new_node.path_cost = manhattan_heuristic(state);
    }
    else if(move == MOVE::RIGHT && (blank_pos != 2 && blank_pos != 5 && blank_pos != 8)){
        auto neighbor_tile = state[blank_pos + 1];
        state[blank_pos + 1] = 'b';
        state[blank_pos] = neighbor_tile;

        // update new node
        new_node.parent = &node;
        new_node.state = state;
        new_node.action = "right";
        new_node.act_path_cost = node.act_path_cost + 1;
    //    new_node.path_cost = manhattan_heuristic(state);
    }
    else if(move == MOVE::DOWN && (blank_pos != 6 && blank_pos != 7 && blank_pos != 8)){
        auto neighbor_tile = state[blank_pos + 3];
        state[blank_pos + 3] = 'b';
        state[blank_pos] = neighbor_tile;

        // update new node
        new_node.parent = &node;
        new_node.state = state;
        new_node.action = "down";
        new_node.act_path_cost = node.act_path_cost;
      //  new_node.path_cost = manhattan_heuristic(state);
    }
    return new_node;
}

bool EightPuzzle::goal_test(std::string goal_state, std::string test_state)
{
    //std::cout << "goal_state: " << goal_state << std::endl;
    //std::cout << "test_state: " << test_state << std::endl;
    return goal_state == test_state;
}

std::vector<Node> EightPuzzle::generate_successor(Node &parent, heuristic_type funct_pnt)
{
    std::vector<Node> successor;
    for(int i = 0; i != 4; ++i){// 4 is because there are four moves to generate a child: left, up, right, down
        // add code to skip checking action equal to current node action
        auto new_child = move(parent, static_cast<MOVE>(i));
        if(new_child.action != "none"){
            new_child.path_cost = (this->*funct_pnt)(new_child.state);
            successor.push_back(new_child);
        }
    }
    return successor;
}

void EightPuzzle::set_goal_state(std::string goal_arg)
{
    goal_state = goal_arg;
}

std::string EightPuzzle::get_goal_state()
{
    return goal_state;
}

void EightPuzzle::print_node(Node &node)
{
    if(node.parent){

        std::cout << "\nparent pointer: " << node.parent
        << "\nparent state: " << node.parent->state << std::endl;
    }
    else{
        std::cout << "\nparent pointer: " << "null"
        << "\nparent state: " << "no state" << std::endl;
    }
        std::cout << "\npointer: " << &node
        << "\naction: " << node.action
        << "\nstate: " << node.state
        << "\npath_cost: " << node.path_cost
        << "\nact_path_cost: " << node.act_path_cost << std::endl;
}

std::vector<std::string> EightPuzzle::generate_action_sequence(Node &node)
{
    std::vector<std::string> sequence;
    Node *parent = &node;

    while(parent){
        sequence.push_back(parent->action);
        parent = parent->parent;
    }
    std::reverse(sequence.begin(), sequence.end());

    return sequence;
}
/*void EightPuzzle::add_node(const std::string &key_state, const Node &val_node)
{
    std::string state(key_state);
    Node node(val_node);
    //std::pair<std::string, Node> pair = std::make_pair<std::string, Node>(std::string(state), Node(node));
    tree.get_all_nodes()->insert(std::make_pair<std::string, Node>(std::string(state), Node(node)));
}
*/
/*
double EightPuzzle::search_time()
{
// use <ctime> clock function
    return 0;
}
*/
unsigned EightPuzzle::manhattan_heuristic(const std::string &node_state)
{
    //std::cout << "in manhattan!" << std::endl;//debug
    unsigned ver_dis(0);
    unsigned hor_dis(0);

    // (pos / 3) will give row, (pos % 3) will give col
    for(std::size_t pos = 0; pos != goal_state.size(); ++pos){
        if(goal_state[pos] != node_state[pos]){

            // find col and row of node state
            auto node_row(0);
            auto node_col(0);
            if(pos < 3){
                node_row = pos / 3;
                node_col = pos;
            }
            else{
                node_row = pos / 3;
                node_col = pos % 3;
            }
            // find col and row of goal state
            std::size_t goal_pos = goal_state.find(node_state[pos]);
            auto goal_row = goal_pos / 3;
            auto goal_col = goal_pos % 3;

            ver_dis += std::abs(static_cast<int>(goal_row - node_row));
            hor_dis += std::abs(static_cast<int>(goal_col - node_col));
        }
    }
    return ver_dis + hor_dis;
}

unsigned EightPuzzle::misplaced_tile_heuristic(const std::string &node_state)
{
    unsigned misplaced_tile(0);
    for(std::size_t i = 0; i != goal_state.size(); ++i){
        if(goal_state[i] != node_state[i]){
            ++misplaced_tile;
        }
    }
    return misplaced_tile;
}

void EightPuzzle::a_star_search(const std::string &initial_state, Node &result, heuristic_type funct_pnt)
{
    //create root node and add it to the list
    Node root;
    root.state = initial_state;
    tree.openlist.push(root);
    tree.openlist_ref[root.state] = &root;

    num_nodes_expanded = 0;
    // loop through openlist
    while(!tree.openlist.empty()){
        Node current = tree.openlist.top();
        tree.openlist_ref.erase(tree.openlist.top().state);
        tree.openlist.pop();
        ++num_nodes_expanded;

        if(tree.closedlist.find(current) != tree.closedlist.end()){
            continue;
        }
        // get sucessors
        auto successors = generate_successor(current, funct_pnt);
        for(auto child : successors){
            if(goal_test(goal_state, child.state)){
                std::cout << "goal found!!!" << std::endl;
                result = child;
                //action_sequence = generate_action_sequence(child);
                std::cout << "num_nodes_expanded" << num_nodes_expanded << std::endl;
                return;
            }

            tree.openlist.push(child);
            tree.openlist_ref[child.state] = &child;
            //std::cout << "new_child.state: " << child.state << std::endl;
            std::cout << child.action << ", ";
        }
        tree.closedlist.insert(current);
    }
    //std::vector<std::string> empty_result;
    //return empty_result;
}

void EightPuzzle::a_star_search_manhattan(const std::string &initial_state, Node &result)
{
    // start timer
    auto tick = clock();
    a_star_search(initial_state, result, man_func);
    // stop time
    tick = clock() - tick;
    std::cout << "time: " << (static_cast<double>(tick) / 1000) << "ms" << std::endl;
}

void EightPuzzle::a_star_search_misplaced_tile(const std::string &initial_state, Node &result)
{
    // start timer
    auto tick = clock();
    a_star_search(initial_state, result, mis_tile_func);
    // stop time
    tick = clock() - tick;
    std::cout << "time: " << (static_cast<double>(tick) / 1000) << "ms" << std::endl;
}

void EightPuzzle::ida_search(const std::string &initial_state, Node &result, heuristic_type funct_pnt)
{
    // create root node and add to tree
    Node root;
    root.state = initial_state;
    tree.get_all_nodes()->insert(root);
    tree.get_frontier_set()->push(&root);

    // set score of best solution L, to max
    decltype(root.path_cost) min_f(UINT_MAX);
    unsigned L = min_f;

    // loop until frontier_set is empty
    Node current = *(tree.get_frontier_set()->top());

    while(!tree.get_frontier_set()->empty()){

        // get top element from frontier_set
        // check if element is the goal
        if(goal_test(goal_state, current.state)){
            // yes => L = min(element.path_cost, L)
            L = L <= current.path_cost ? L : current.path_cost;
        }
        else{
            // no => generate sucessors
            auto successor = generate_successor(current, funct_pnt);

            for(auto &child : successor){
                if(child.path_cost >= L){
                    continue;
                }
                else{
                    // sucessor.path_cost < L, add to tree and frontier
                    tree.get_all_nodes()->insert(child);
                    tree.get_frontier_set()->push(&child);
                }
                if(child.path_cost > L && child.path_cost < min_f){
                    min_f = child.path_cost;
                }
            }
        }
        L = min_f;// update L to next contour
    }
}

void EightPuzzle::df_branch_bound_search(const std::string &initial_state, Node &result/*, heuristic_type funct_pnt*/)
{

}
/*
{
    // create root node and add to tree
    Node root;
    root.state = initial_state;
    tree.get_all_nodes()->insert(root);
    tree.get_frontier_set()->push(&root);

    // set score of best solution L, to max
    unsigned L = UINT_MAX;

    // loop until frontier_set is empty
    Node current = *(tree.get_frontier_set()->top());

    while(!tree.get_frontier_set()->empty()){

        // get top element from frontier_set
        // check if element is the goal
        if(goal_test(goal_state, current.state)){
            // yes => L = min(element.path_cost, L)
            L = L <= current.path_cost ? L : current.path_cost;
        }
        else{
            // no => generate sucessors
            auto successor = generate_successor(current, man_func);

            for(auto &child : successor){
                if(child.path_cost >= L){
                    continue;
                }
                else{
                    // sucessor.path_cost < L, add to tree and frontier
                    tree.get_all_nodes()->insert(child);
                    tree.get_frontier_set()->push(&child);
                }
            }
        }
    }
}
*/
