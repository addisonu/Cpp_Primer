//AUTHOR: NA
//DATE: 11/05/17
//FILE: ToyDecisionTree.cpp
//DESC: Implement ToyDecisionTree class

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "ToyDecisionTree.h"

ToyDecisionTree::ToyDecisionTree()
{

}

std::vector<std::vector<Neuron> > ToyDecisionTree::initialize_network(unsigned n_inputs, unsigned n_hidden, unsigned n_outputs)
{
    srand(time(NULL));

    std::vector<std::vector<Neuron> > network;
    std::vector<Neuron> hidden_layer, output_layer;

    // initialize hidden_layer
    for(unsigned i = 0; i != n_hidden; ++i){
        Neuron new_neuron;
        for(unsigned j = 0; j != n_inputs + 1; ++j){
            new_neuron.weights.push_back(static_cast<double>(rand() % 100) / 100);
        }
        hidden_layer.push_back(new_neuron);
    }
    // initialize output_layer
    for(unsigned i = 0; i != n_outputs; ++i){
        Neuron new_neuron;
        for(unsigned j = 0; j != n_hidden + 1; ++j){
            new_neuron.weights.push_back(static_cast<double>(rand() % 100) / 100);
        }
        output_layer.push_back(new_neuron);
    }
    network.push_back(hidden_layer);
    network.push_back(output_layer);

    return network;
}

double ToyDecisionTree::activate(std::vector<double> weights, std::vector<double> inputs)
{
    double activation = weights[weights.size() - 1];

    for(unsigned i = 0; i != weights.size(); ++i){
        activation += weights[i]*inputs[i];
    }
    return activation;
}

double ToyDecisionTree::transfer(double activation)
{
    return 1.0 / (1.0 + exp(-activation));
}

std::vector<double> ToyDecisionTree::forward_propagate(std::vector<std::vector<Neuron> > &network, std::vector<double> row)
{
    std::vector<double> inputs = row;
    for(auto &layer : network){
        std::vector<double> new_inputs;
        for(auto &neuron : layer){
            auto activation = activate(neuron.weights, inputs);
            neuron.output = transfer(activation);
            new_inputs.push_back(neuron.output);
        }
        inputs = new_inputs;
        //debug start
        /*std::cout << "inputs from forward_propagate" << std::endl;
        for(auto ele : inputs){
            std::cout << ele << ", ";
        }*/
        //debug stop
    }
    return inputs;
}

double ToyDecisionTree::transfer_derivative(double output)
{
    return output * (1.0 - output);
}

void ToyDecisionTree::backward_propagate_error(std::vector<std::vector<Neuron> > &network, std::vector<double> expected)
{
    for(int i = network.size() - 1; i >= 0; --i){
        auto &layer = network[i];
        std::vector<double> errors;
        if(i != network.size() - 1){
            for(auto j = 0; j != layer.size(); ++j){
                double error = 0.0;
                for(auto &neuron : network[i + 1]){
                        error += neuron.weights[j] * neuron.delta;
                }
                errors.push_back(error);
            }
        }
        else{
            for(auto j = 0; j != layer.size(); ++j){
                auto &neuron = layer[j];
                //std::cout << "output layer error is: " << (expected[j] - neuron.output) << std::endl; //debug
                errors.push_back(expected[j] - neuron.output);
            }
        }
        for(auto l = 0; l != layer.size(); ++l){
            auto &neuron = layer[l];
            neuron.delta = static_cast<double>(errors[l] * transfer_derivative(neuron.output));
            //std::cout << "output delta = " << neuron.delta << std::endl;
        }
    }
}

void ToyDecisionTree::update_weights(std::vector<std::vector<Neuron> > &network, std::vector<double> row, double l_rate)
{
    for(auto i = 0; i != network.size(); ++i){
        std::vector<double> inputs;

        if(i != 0){
            for(const auto &neuron : network[i - 1]){
                inputs.push_back(neuron.output);
            }
        }
        else{
            inputs = std::vector<double>(row.cbegin(), row.cend() - 1);//, inputs.begin());
            //debug start
            //std::cout << "row values loaded into inputs" << std::endl;
            //for(auto ele : inputs){
            //    std::cout << ele << ", ";
            //}
            //std::cout << std::endl;
            // debug end
        }
        for(auto &neuron : network[i]){
            for(auto j = 0; j != inputs.size(); ++j){
                neuron.weights[j] += l_rate * neuron.delta * inputs[j];
            }
            neuron.weights[neuron.weights.size() - 1] += l_rate * neuron.delta;// update bias
        }
    }
}

void ToyDecisionTree::train_network(std::vector<std::vector<Neuron> > &network, const std::vector<std::vector<double> > &train, double l_rate, unsigned n_epoch, unsigned n_outputs)
{
    for(auto epoch = 0; epoch != n_epoch; ++epoch){
        double sum_error = 0;
        for(auto row : train){
            auto outputs = forward_propagate(network, row);

            std::vector<double> expected(n_outputs, 0);
            //for(auto ele : outputs){
            //    std::cout << ele << ", ";
            //}
            expected[row[row.size() - 1]] = 1;
            for(auto i = 0; i != expected.size(); ++i){
                sum_error += pow((expected[i] - outputs[i]), 2);
            }
            backward_propagate_error(network, expected);
            update_weights(network, row, l_rate);
        }
        std::cout << ">epoch=" << epoch
            << ", lrate=" << l_rate
            << ", error=" << sum_error
            << std::endl;
    }
}
