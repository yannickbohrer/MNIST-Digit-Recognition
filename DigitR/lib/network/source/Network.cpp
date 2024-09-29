#include "../include/Network.hpp"
#include <iostream>
#include <memory>
#include "../../../include/DigitR.hpp"
#include "../include/Layer.hpp"

Network& Network::Get() {
    static Network m_Instance(DR::Constants::hyper_params);
    return m_Instance;
}

Network::Network(const Hyperparameters& hyper_params)
    : m_Input_layer(Layer(hyper_params.number_of_input_neurons)),
      m_Output_layer(Layer(hyper_params.number_of_output_neurons)) {
    if (hyper_params.number_of_input_neurons < 1 || hyper_params.number_of_hidden_layers < 1 ||
        hyper_params.number_of_hidden_layers < 1 || hyper_params.number_of_output_neurons < 1) {
        std::cerr << "ERROR: Failed initializing network: Invalid Hyperparameters" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_Hidden_layers.reserve(hyper_params.number_of_hidden_layers);
    for (size_t i = 0; i < hyper_params.number_of_hidden_layers; i++)
        m_Hidden_layers.emplace_back(std::make_unique<Layer>(Layer(hyper_params.neurons_per_hidden_layer)));
}
