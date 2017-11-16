//AUTHOR: NA
//DATE: 11/05/17
//FILE: TestToyDecisionTree.h
//DESC: Test individual functions of ToyDecisionTree class

#ifndef TEST_TOY_DECISION_TREE_H
#define TEST_TOY_DECISION_TREE_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include "ToyDecisionTree.h"

class TestToyDecisionTree{

    public:
        TestToyDecisionTree() = default;

        void initialize_test(std::vector<double> &row, double &hidden_n, double &output_n, std::vector<std::vector<Neuron> > &network)
        {
            std::vector<double> test_inputs{0.34893, 0.2328, 0.5986};
            row = test_inputs;
            hidden_n = 1;
            output_n = 2;
            network = tdt.initialize_network(test_inputs.size(), hidden_n, output_n);
        }

        void print_network(const std::vector<std::vector<Neuron> > &network)
        {
                for(auto layer : network){
                std::cout << std::string(30, '-') << "\nnext layer:"
                    << std::endl;
                for(auto neuron : layer){
                    std::cout << "\nnext neuron:"
                        << "\noutput = " << neuron.output
                        << "\ndelta = " << neuron.delta
                        << std::endl;
                    for(auto weight : neuron.weights){
                        std::cout << weight << ", ";
                    }
                    std::cout << std::endl;
                }
            }
        }

        void Test_initialize_network()
        {
            std::cout << "Running Test_initialize_network" << std::endl;// debug
            auto network = tdt.initialize_network(2,1,2);
            for(auto layer : network){
                std::cout << std::string(30, '-') << "\nnext layer:"
                    << std::endl;
                for(auto neuron : layer){
                    std::cout << "\nnext neuron:"
                        << "\noutput = " << neuron.output
                        << std::endl;
                    for(auto weight : neuron.weights){
                        std::cout << weight << ", ";
                    }
                    std::cout << std::endl;
                }
            }
        }

        void Test_activate()
        {
            std::vector<double> test_inputs{0.34893, 0.2328, 0.5986};
            unsigned hidden_n = 1;
            unsigned output_n = 2;
            auto network = tdt.initialize_network(test_inputs.size(), hidden_n, output_n);
            for(auto layer : network){
                std::cout << std::string(30, '-') << "\nnext layer:"
                    << std::endl;
                for(auto neuron : layer){
                    std::cout << "\nnext neuron:"
                        << "\noutput = " << neuron.output
                        << std::endl;
                    for(auto weight : neuron.weights){
                        std::cout << weight << ", ";
                    }
                    std::cout << std::endl;
                }
            }
            std::cout << "\nactivate = "
                << tdt.activate(test_inputs, network[0][0].weights)
                << std::endl;
        }

        void Test_transfer()
        {
            double activation = 3;
            std::cout << "transfer = " << tdt.transfer(activation)
                << std::endl;
        }

        void Test_foward_propagate()
        {
            /* auto initialize test
            std::vector<double> row;
            double hidden_n;
            double output_n;
            std::vector<std::vector<Neuron> > network;

            initialize_test(row, hidden_n, output_n, network);
            */
            // manual initialize test
            std::vector<double> row = {1, 0, 0};
            std::vector<std::vector<Neuron> > network(2);

            Neuron hid_0;
            std::vector<double> tmp_hid_weights = {0.13436424411240122, 0.8474337369372327, 0.763774618976614};
            hid_0.weights = tmp_hid_weights;
            network[0].push_back(hid_0);

            Neuron out_0, out_1;
            std::vector<double> tmp_out_0_weights = {0.2550690257394217, 0.49543508709194095};
            out_0.weights = tmp_out_0_weights;
            std::vector<double> tmp_out_1_weights = {0.4494910647887381, 0.651592972722763};
            out_1.weights = tmp_out_1_weights;
            network[1].push_back(out_0);
            network[1].push_back(out_1);

            print_network(network);
            std::cout << std::flush;
            std::cout << std::endl;// weirdest buy of different values to standard output depending on number of print statements, sometime 1, 0, .9<something>, 0.725316

            auto outputs = tdt.forward_propagate(network, row);

            std::cout << "outputs: " << std::endl;
            for(auto output : outputs){
                std::cout << output << ", ";
            }
            std::cout << std::endl;
        }

        void Test_transfer_derivative()
        {
            double output = 7;
            std::cout << "transfer_derivative = "
                << tdt.transfer_derivative(output) << std::endl;
        }

        void Test_backward_propagate_error()
        {
             std::vector<double> row = {1, 0, 0};
            std::vector<std::vector<Neuron> > network(2);

            Neuron hid_0;
            hid_0.output = 0.7105668883115941;
            std::vector<double> tmp_hid_weights = {0.13436424411240122, 0.8474337369372327, 0.763774618976614};
            hid_0.weights = tmp_hid_weights;
            network[0].push_back(hid_0);

            Neuron out_0, out_1;
            out_0.output = 0.6213859615555266;
            out_1.output = 0.6573693455986976;
            std::vector<double> tmp_out_0_weights = {0.2550690257394217, 0.49543508709194095};
            out_0.weights = tmp_out_0_weights;
            std::vector<double> tmp_out_1_weights = {0.4494910647887381, 0.651592972722763};
            out_1.weights = tmp_out_1_weights;
            network[1].push_back(out_0);
            network[1].push_back(out_1);

//           print_network(network);
            std::vector<double> expected{0, 1};
            tdt.backward_propagate_error(network, expected);
            print_network(network);
        }

        void Test_train_network()
        {
            std::vector<std::vector<double> > dataset =
                {{2.7810836,2.550537003,0},
                {1.465489372,2.362125076,0},
                {3.396561688,4.400293529,0},
                {1.38807019,1.850220317,0},
                {3.06407232,3.005305973,0},
                {7.627531214,2.759262235,1},
                {5.332441248,2.088626775,1},
                {6.922596716,1.77106367,1},
                {8.675418651,-0.242068655,1},
                {7.673756466,3.508563011,1}};

            auto n_inputs = dataset[0].size() - 1;
            std::set<int> classes;
            for(auto ele : dataset){
                classes.insert(ele[ele.size() - 1]);
            }
            auto n_outputs = classes.size();
            //std::cout << "num of classes = " << n_outputs << std::endl;

            std::vector<std::vector<Neuron> > network = tdt.initialize_network(n_inputs, 2, n_outputs);

            double l_rate = 0.5;
            unsigned n_epoch = 1;//20;

            tdt.train_network(network, dataset, l_rate, n_epoch, n_outputs);
            print_network(network);
        }

    private:
        ToyDecisionTree tdt;
};
#endif
