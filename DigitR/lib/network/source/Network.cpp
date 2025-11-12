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
    for (unsigned int it_hidden_layers = 0; it_hidden_layers < hyper_params.number_of_hidden_layers;
         ++it_hidden_layers) {
        m_Hidden_layers.emplace_back(std::make_unique<Layer>(Layer(hyper_params.neurons_per_hidden_layer)));

        Layer prev_layer = m_Input_layer;
        if (it_hidden_layers != 0)
            prev_layer = *m_Hidden_layers.at(it_hidden_layers - 1);

        Layer& layer = *m_Hidden_layers.at(it_hidden_layers);
        for (unsigned int it_neurons = 0; it_neurons < hyper_params.neurons_per_hidden_layer; ++it_neurons) {
            Neuron& neuron = *layer[it_neurons];
            neuron.Weights().reserve(prev_layer.Size());
            for (unsigned int it_weights = 0; it_weights < prev_layer.Size(); ++it_weights)
                neuron.Weights().emplace_back(1);
        }
    }
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
    double sum_of_all_input_values = 0;
    for (unsigned int it = 0; it < m_Input_layer.Size(); ++it)
        sum_of_all_input_values += m_Input_layer[it]->Value();
    std::cout << "sum_of_all_input_values = " << sum_of_all_input_values << std::endl;

    for (unsigned int it_layer = 0; it_layer < m_Hidden_layers.size(); ++it_layer)
        Update_Activations_Of_Hidden_Layer(it_layer);

    //m_Input_layer.Print_Values();
    //for (const std::shared_ptr<Layer> layer : m_Hidden_layers)
    //  layer->Print_Values();
    //m_Output_layer.Print_Values();
}

void Network::Update_Activations_Of_Hidden_Layer(int layer_number) {
    Layer& layer = *m_Hidden_layers.at(layer_number);
    std::cout << "\n---------- LAYER " << layer_number + 1 << std::endl;
    std::cout << "---------- BEFORE ACTIVATION UPDATES ----------" << std::endl;
    layer.Print_Values();
    Layer prev_layer = m_Input_layer;
    if (layer_number != 0)
        prev_layer = *m_Hidden_layers.at(layer_number - 1);
    for (unsigned int it_current = 0; it_current < layer.Size(); ++it_current) {
        Neuron& current_neuron = *layer[it_current];
        for (unsigned int it_prev = 0; it_prev < prev_layer.Size(); ++it_prev) {
            current_neuron.Add_To_Linear_Combination(prev_layer[it_prev]->Value(),
                                                     current_neuron.Weights().at(it_prev));
        }
        current_neuron.Update_Activation();
    }
    std::cout << "---------- AFTER ACTIVATION UPDATES ----------" << std::endl;
    layer.Print_Values();
}
