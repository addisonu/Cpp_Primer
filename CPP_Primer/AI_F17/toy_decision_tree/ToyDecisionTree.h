//AUTHOR: NA
//DATE: 11/05/17
//FILE: ToyDecisionTree.h
//DESC: Class definition

#ifndef TOY_DECISION_TREE_H
#define TOY_DECISION_TREE_H

#include <vector>
#include <string>
//#include <utility>
#include <tuple>
#include <stdlib.h>
#include <cmath>

struct Neuron{
    std::vector<double> weights;
    double output = 0;
    double delta = 0;
};

class ToyDecisionTree{

    public:
        // CONSTRUCTORS //
        ToyDecisionTree();

        // UTILITY //
        // INITIALIZE NETWORK //
        //std::vector<std::vector<std::pair<std::string, double> > > initialize_network(unsigned n_inputs, unsigned n_hidden, unsigned n_outputs);
        std::vector<std::vector<Neuron> > initialize_network(unsigned n_inputs, unsigned n_hidden, unsigned n_outputs);

        // FORWARD PROPAGATE //
        double activate(std::vector<double> weights, std::vector<double> inputs);// |weights| == |inputs| + 1
        double transfer(double activation);
        std::vector<double> forward_propagate(std::vector<std::vector<Neuron> > &network, std::vector<double> row);

        // BACK PROPAGATE ERROR //
        double transfer_derivative(double output);
        void backward_propagate_error(std::vector<std::vector<Neuron> > &network, std::vector<double> expected);

        // TRAIN NETWORK //
        void update_weights(std::vector<std::vector<Neuron> > &network, std::vector<double> row, double l_rate);
        void train_network(std::vector<std::vector<Neuron> > &network, const std::vector<std::vector<double> > &train, double l_rate, unsigned n_epoch, unsigned n_outputs);
        // PREDICT //
        // SEEDS DATASET CASE STUDY //

    private:
        double learning_rate = 0.1;
};

#endif
