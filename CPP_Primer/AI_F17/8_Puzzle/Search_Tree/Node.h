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

    Node() = default;

    Node(Node *parent_arg, std::string state_arg, std::string action_arg, int path_cost_arg) : parent(parent_arg), state(state_arg), action(action_arg), path_cost(path_cost_arg){ }

    bool operator>(const Node& rhs) const
    {
        return this->path_cost > rhs.path_cost;
    }

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
    queue_type * get_frontier_set() { return &frontier_set; }

    private:

    // DATA MEMBERS //
    queue_type frontier_set;
    hash_type explored_set;
};
#endif
