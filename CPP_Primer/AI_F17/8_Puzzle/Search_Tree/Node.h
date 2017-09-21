//AUTHOR: AU
//DATE: 09/18/17
//FILE: Node.h
//DESC: Define all 8-puzzle search elements

#ifndef TREE_SEARCH_NODE_H
#define TREE_SEARCH_NODE_H

#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>

struct Node{

    // MEMBER FUNCTIONS //
    Node() = default;

    Node(Node *parent_arg, std::string state_arg, std::string action_arg, int path_cost_arg) : parent(parent_arg), state(state_arg), action(action_arg), path_cost(path_cost_arg){ }

    bool operator>(const Node& rhs) const
    {
        return this->path_cost > rhs.path_cost;
    }

    // DATA MEMBERS //
    Node *parent = nullptr;
    std::string state;
    std::string action = "none";
    unsigned path_cost = UINT_MAX;
};

class SearchTree{

    public:

    // TYPE MEMBERS //
    using queue_type = std::priority_queue<Node, std::vector<Node>, std::greater<Node>>;
    using hash_type = std::unordered_map<std::string, Node>;

    // MEMBER FUNCTIONS //
    SearchTree() = default;
    queue_type* get_frontier_set() { return &frontier_set; }
    hash_type* get_explored_set() { return &explored_set; }

    private:

    // DATA MEMBERS //
    queue_type frontier_set;
    hash_type explored_set;
};

class EightPuzzle {
    public:

    // MEMBER FUNCTIONS //
    EightPuzzle() = default;
    Node move(const Node &node);
    bool goal_test(std::string goal_state, std::string test_state);
    double search_time();
    unsigned manhattan_heuristic(const Node &node);
    unsigned misplaced_tile_heuristic(const Node &node);
    void a_star_search(Node &result);
    void ida_search(Node &result);
    void df_branch_bound_search(Node &result);

    private:
    std::vector<int> heuristic_table;
    char *time = nullptr;
    
    // DATA MEMBERS //
};
#endif
