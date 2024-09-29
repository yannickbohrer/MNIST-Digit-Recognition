#pragma once

#include <memory>
#include <vector>
#include "../../../include/DigitR.hpp"
#include "Layer.hpp"

class Network {
public:
    static void Init();

private:
    explicit Network(unsigned int input_neuron_count = DR::Constants::pixels_per_number,
                     unsigned int number_of_hidden_layers = 4, unsigned int neurons_per_hidden_layer = 16,
                     unsigned int output_neuron_count = 10);
    Network(const Network&) = delete;
    static Network m_Instance;

    std::unique_ptr<Layer> m_Input_layer;
    std::vector<std::unique_ptr<Layer>> m_Hidden_layers;
    std::unique_ptr<Layer> m_Output_layer;
};
