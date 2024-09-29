#include "../include/Neuron.hpp"
#include <iostream>

Neuron::Neuron(double value) {
    if (value >= 0 && value <= 1)
        m_Value = value;
    else {
        std::cerr << "neuron activation value must be e [0.0, 1.0]" << std::endl;
        exit(EXIT_FAILURE);
    }
}

double Neuron::Value() const {
    return m_Value;
}

void Neuron::Set_Value(double value) {
    if (value < 0 || value > 1) {
        std::cerr << "neuron activation value must be e [0.0, 1.0]" << std::endl;
        exit(EXIT_FAILURE);
    }
    m_Value = value;
}
