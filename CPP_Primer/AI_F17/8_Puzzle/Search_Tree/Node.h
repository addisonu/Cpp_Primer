//AUTHOR: NA
//DATE: 09/18/17
//FILE: Node.h
//DESC: Define all 8-puzzle search elements

#ifndef TREE_SEARCH_NODE_H
#define TREE_SEARCH_NODE_H

#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <climits>
#include <map>//debug

struct Node{

    // MEMBER FUNCTIONS //
    Node() = default;

    Node(Node *parent_arg, std::string state_arg, std::string action_arg, int path_cost_arg) : parent(parent_arg), state(state_arg), action(action_arg), path_cost(path_cost_arg){ }

    // overloaded for set container
    bool operator<(const Node &rhs) const
    {
        return this->state < rhs.state;
      //  return this->path_cost < rhs.path_cost;
    }

    // DATA MEMBERS //
    Node *parent = nullptr;
    std::string state;
    std::string action = "none";
    unsigned path_cost = UINT_MAX;// may change to g(n) and h(n)
    unsigned act_path_cost = 0;
};

// represent 8-puzzle actions
enum class MOVE{
    LEFT = 0,
    UP,
    RIGHT,
    DOWN,
};

// Custom compare function for priority_queue
struct CompareNode{
    bool operator()(const Node lhs, const Node rhs) const{
        return (lhs.path_cost + lhs.act_path_cost) > (rhs.path_cost + rhs.path_cost);//debug
    }

    bool operator()(const Node *lhs, const Node *rhs) const{
        return (lhs->path_cost + lhs->act_path_cost) > (rhs->path_cost + rhs->path_cost);
    }
};

// Collection of containers to hold Nodes
class SearchTree{

    public:

    // TYPE MEMBERS //
    using set_type = std::set<Node>;
    using queue_type2 = std::priority_queue<Node, std::vector<Node>, CompareNode>;
    using queue_type = std::priority_queue<Node*, std::vector<Node*>, CompareNode>;
    using hash_type = std::unordered_map<std::string, Node*>;
    using hash_type2 = std::set<Node>;

    // MEMBER FUNCTIONS //
    SearchTree() = default;
    set_type* get_all_nodes() { return &all_nodes; }
    queue_type* get_frontier_set() { return &frontier_set; }
    hash_type* get_explored_set() { return &explored_set; }

    queue_type2 openlist;//debug
    hash_type2 closedlist;//debug
    std::map<std::string, Node*> openlist_ref;//debug
    private:

    // DATA MEMBERS //
    set_type all_nodes;
    queue_type frontier_set;
    hash_type explored_set;
};

// Plays the game
class EightPuzzle {

    public:

    // TYPE MEMBERS //
    using heuristic_type = unsigned (EightPuzzle::*)(const std::string &node_state);

    // MEMBER FUNCTIONS //
    EightPuzzle() = default;
    EightPuzzle(std::string goal_state_arg, std::string initial_state_arg) : goal_state(goal_state_arg), initial_state(initial_state_arg)
    {
        man_func = &EightPuzzle::manhattan_heuristic;
        mis_tile_func = &EightPuzzle::misplaced_tile_heuristic;
    }

    // helper functions
    SearchTree* get_tree() { return &tree; }
    Node move(Node &node, MOVE move);
    bool goal_test(std::string goal_state, std::string test_state);
    std::vector<Node> generate_successor(Node &parent, heuristic_type funct_pnt);
    void set_goal_state(std::string goal_arg);
    std::string get_goal_state();
    std::vector<std::string> get_action_sequence() { return action_sequence; }// debug
    void set_action_sequence(std::vector<std::string> seq) { action_sequence = seq; }// debug
    void print_node(Node &node);
    std::vector<std::string> generate_action_sequence(Node &node); // will return sequence of actions to reach a node
    //void add_node(Node &node);

    // heuristic functions

    // the sum of the horizontal and vertical distances of the tiles from their goal positions. Will return the h(n) portion of f(n)
    unsigned manhattan_heuristic(const std::string &node_state);
    // the number of misplaced tiles
    unsigned misplaced_tile_heuristic(const std::string &node_state);

    // search algorithms
    void a_star_search(const std::string &initial_state, Node &result, heuristic_type funct_pnt);
    void a_star_search_manhattan(const std::string &initial_state, Node &result);
    void a_star_search_misplaced_tile(const std::string &initial_state, Node &result);
    void ida_search(const std::string &initial_state, Node &result, heuristic_type funct_pnt);
    void df_branch_bound_search(const std::string &initial_state, Node &result/*, heuristic_type funct_pnt*/);

    private:

    // DATA MEMBERS //
    SearchTree tree;
    std::string goal_state;
    std::string initial_state;
    unsigned num_nodes_expanded = 0;
    std::vector<int> heuristic_table;
    std::vector<std::pair<Node, clock_t> > search_result; // will hold goal state with search time for each algorithm
    std::vector<std::string> action_sequence;//debugging
    heuristic_type man_func;
    heuristic_type mis_tile_func;
};
#endif
