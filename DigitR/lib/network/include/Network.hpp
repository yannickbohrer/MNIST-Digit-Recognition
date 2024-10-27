#pragma once
#include <memory>
#include <vector>
#include "Layer.hpp"

class Network {
public:
    struct Hyperparameters {
        unsigned int number_of_input_neurons;
        unsigned int number_of_hidden_layers;
        unsigned int neurons_per_hidden_layer;
        unsigned int number_of_output_neurons;
    };
    static Network& Get();
    Layer& Input_Layer();
    std::vector<std::shared_ptr<Layer>>& Hidden_Layers();
    Layer& Output_Layer();

    void Iteration();
    void Update_Activations_Of_Hidden_Layer(int);

private:
    explicit Network(const Hyperparameters&);
    Network(const Network&) = delete;
    static Network m_Instance;

    Layer m_Input_layer;
    std::vector<std::shared_ptr<Layer>> m_Hidden_layers;
    Layer m_Output_layer;
};
