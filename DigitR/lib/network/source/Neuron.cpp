#include "../include/Neuron.hpp"
#include <cmath>
#include <iostream>

Neuron::Neuron(double value) : m_Linear_combination(0), m_Bias(0), m_Weights() {
    Set_Activation_Value(value);
}

double Neuron::Value() const {
    return m_Value;
}

std::vector<double>& Neuron::Weights() {
    return m_Weights;
}

void Neuron::Set_Activation_Value(double value) {
    if (value < 0 || value > 1) {
        std::cerr << "ERROR: Neuron activation value must be e [0.0, 1.0]" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_Value = value;
}

void Neuron::Add_To_Linear_Combination(double prev_activation, double weight) {
    m_Linear_combination += (prev_activation * weight);
}

void Neuron::Update_Activation() {
    double linear_combination_including_bias = m_Linear_combination - m_Bias;
    double normalized_linear_combination = Normalize(linear_combination_including_bias, m_Weights.size());
    double new_activation_value = Sigmoid(normalized_linear_combination);
    Set_Activation_Value(new_activation_value);
}

double Neuron::Normalize(double val, int number_of_inputs) {
    return (double)(val / number_of_inputs);
}

double Neuron::Sigmoid(double val) {
    return (double)(1 / (1 + std::exp(-1 * val)));
}
