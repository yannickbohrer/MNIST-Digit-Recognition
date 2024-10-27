#include "../include/Neuron.hpp"
#include <iostream>

Neuron::Neuron(double value) : m_linear_combination(0) {
    Set_Value(value);
}

double Neuron::Value() const {
    return m_Value;
}

void Neuron::Set_Value(double value) {
    if (value < 0 || value > 1) {
        std::cerr << "ERROR: Neuron activation value must be e [0.0, 1.0]" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_Value = value;
}

void Neuron::Add_To_Linear_Combination(double prev_activation, double weight) {
    m_linear_combination += (prev_activation * weight);
}

void Neuron::Update_Activation(int number_for_normalization) {
    Set_Value(Normalize(m_linear_combination, number_for_normalization));
}

double Neuron::Normalize(int val, int number_of_inputs) {
    return (double)val / number_of_inputs;
}
