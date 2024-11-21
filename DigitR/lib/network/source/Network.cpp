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

Layer& Network::Input_Layer() {
    return m_Input_layer;
}

std::vector<std::shared_ptr<Layer>>& Network::Hidden_Layers() {
    return m_Hidden_layers;
}

Layer& Network::Output_Layer() {
    return m_Output_layer;
}

void Network::Iteration() {
    //for (unsigned int it = 0; it < m_Hidden_layers.size(); ++it)
    //Update_Activations_Of_Layer(it);
    m_Input_layer.Print_Values();
    Update_Activations_Of_Hidden_Layer(0);
}

void Network::Update_Activations_Of_Hidden_Layer(int layer_number) {
    Layer& layer = *m_Hidden_layers.at(layer_number);
    std::cout << "---------- BEFORE ACTIVATION UPDATES ----------" << std::endl;
    layer.Print_Values();
    Layer& prev_layer = m_Input_layer;
    if (layer_number != 0)
        prev_layer = *m_Hidden_layers.at(layer_number - 1);
    for (unsigned int it_current = 0; it_current < layer.Size(); ++it_current) {
        Neuron& current_neuron = *layer[it_current];
        for (unsigned int it_prev = 0; it_prev < prev_layer.Size(); ++it_prev) {
            current_neuron.Add_To_Linear_Combination(prev_layer[it_prev]->Value(), 1);
        }
        current_neuron.Update_Activation(prev_layer.Size());
    }
    std::cout << "---------- AFTER ACTIVATION UPDATES ----------" << std::endl;
    layer.Print_Values();
}
