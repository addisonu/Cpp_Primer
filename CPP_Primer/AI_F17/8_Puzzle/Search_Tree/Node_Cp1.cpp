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
//#include <algorithm>
#include <iostream> // debug
#include <stdlib.h> // debug
#include <cmath>
#include "Node_Cp.h"

// update to take different heuristics
Node EightPuzzle::move(/*const*/ Node &node, MOVE move)
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
//unsigned EightPuzzle::manhattan_heuristic(const Node &node)
{
    std::cout << "in manhattan!" << std::endl;//debug
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

// NOTE: need to generate actual g(n) not use from heuristic
//void EightPuzzle::a_star_search(const std::string &initial_state, Node &result)
void EightPuzzle::a_star_search(const std::string &initial_state, Node &result, heuristic_type funct_pnt)
{
    std::cout << "Starting A* search" << std::endl;//debug
    // give root initial state and add to tree
    Node root;
    root.state = initial_state;
    tree.get_all_nodes()->insert(root);
    tree.get_frontier_set()->push(&root);

    std::cout << "Completed root node setup" << std::endl;//debug
    // get top node and start searching for goal
    Node current = *(tree.get_frontier_set()->top());
    auto cnt(0);// debug
    while(++cnt <= 10 && !tree.get_frontier_set()->empty() && !goal_test(goal_state, current.state)){
        /*
        if(current.state == initial_state){
    std::cout << "in intial state block" << std::endl;//debug
            continue; // don't process root node
        }
        */
        //Node current_node = tree.get_frontier_set()->top();

        // if the node isn't the goal generate it's successors and check 3 cases:
        //for(int i = 0; i != 4; ++i){// 4 is because there are four moves to generate a child: left, up, right, down
            // update for loop to generat_successor function call
            // add code to skip checking action equal to current node action
            //auto child = move(current, static_cast<MOVE>(i));//remove

    std::cout << "Generating successors" << std::endl;//debug
        auto successors = generate_successor(current, funct_pnt);
        for(auto child : successors){
    std::cout << "searching for former child" << std::endl;//debug
            Node *former_child = nullptr;
            bool found(false);

/*
            std::iterator<std::priority_queue<Node, std::vector<Node>, std::greater<Node>>> it;
            for(auto ele : tree.get_frontier_set()){
                if(ele.state == child.state){
                    found = true;
                    former_child = ele;
                    break;
                }
            }
*/
            for(auto ele : *(tree.get_all_nodes())){
                if(ele.state == child.state){
    std::cout << "former child found" << std::endl;//debug
                    found = true;
                    former_child = &ele;
                    break;
                }
            }
            if(!found){// && former_child.path_cost > child.path_cost){
                // child is in neither frontier_set nor explored_set
                // add child to tree
    std::cout << "adding new child to tree" << std::endl;//debug
                tree.get_all_nodes()->insert(child);
                tree.get_frontier_set()->push(&child);
                //print_node(child);//debug
            }
            else{
                try{
                    /*auto former_child = */get_tree()->get_explored_set()->at(child.state);

                    // child is in the explored_set with greater path_cost
                    // update child and move to frontier_set
                    if(former_child->path_cost > child.path_cost){
    std::cout << "moving former child from explored set to frontier set" << std::endl;//debug
                //print_node(child);//debug
                        *former_child = child;
                        tree.get_explored_set()->erase(former_child->state);
                        tree.get_frontier_set()->push(former_child);
                    }
                }
                catch(const std::out_of_range& oor){
                // child is in frontier_set with greater path_cost, update child
                    if(former_child->path_cost > child.path_cost){
    std::cout << "former child is in frontier, update" << std::endl;//debug
                        *former_child = child;
                    }
                }
            }
        }
        // add current node to explored_set
        //tree.get_all_nodes()->insert(cu
    std::cout << "current node state: " << current.state << std::endl; //debug
        (*tree.get_explored_set())[current.state] = tree.get_frontier_set()->top();
        tree.get_frontier_set()->pop();
        current = *(tree.get_frontier_set()->top());
        print_node(current);//debug
        ++num_nodes_expanded;
    std::cout << "at the end of while loop" << std::endl;//debug
    }
    result = *(tree.get_frontier_set()->top());
    std::cout << "Ending A* search" << std::endl;//debug
}

void EightPuzzle::a_star_search_manhattan(const std::string &initial_state, Node &result, Node &node)
{
    //heuristic_type man_func = &EightPuzzle::manhattan_heuristic;
    a_star_search(initial_state, result, man_func);
}

void EightPuzzle::a_star_search_misplaced_tile(const std::string &initial_state, Node &result, Node &node)
{
    //heuristic_type mis_tile_func = &EightPuzzle::misplaced_tile_heuristic;
    a_star_search(initial_state, result, mis_tile_func);
}

/*
void EightPuzzle::ida_search(const std::string &initial_state, Node &result)
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
        //    auto successor = generate_successor(current);

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

void EightPuzzle::df_branch_bound_search(const std::string &initial_state, Node &result)
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
            //auto successor = generate_successor(current);

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
