#include "../include/Network.hpp"
#include <iostream>
#include <memory>
#include "../include/Layer.hpp"

Network& Network::Get() {
    static Network m_Instance;
    return m_Instance;
}

Network::Network(unsigned int input_neuron_count, unsigned int number_of_hidden_layers,
                 unsigned int neurons_per_hidden_layer, unsigned int output_neuron_count) {
    if (input_neuron_count < 1 || number_of_hidden_layers < 1 || number_of_hidden_layers < 1 ||
        output_neuron_count < 1) {
        std::cerr << "failed initializing network: Invalid hyperparameters" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_Input_layer = std::make_unique<Layer>(Layer(input_neuron_count));
    m_Hidden_layers.reserve(number_of_hidden_layers);
    for (size_t i = 0; i < number_of_hidden_layers; i++)
        m_Hidden_layers.emplace_back(std::make_unique<Layer>(Layer(neurons_per_hidden_layer)));

    m_Output_layer = std::make_unique<Layer>(Layer(output_neuron_count));
}
