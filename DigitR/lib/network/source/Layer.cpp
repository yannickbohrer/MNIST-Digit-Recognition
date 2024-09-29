#include "../include/Layer.hpp"
#include <iostream>
#include <memory>

Layer::Layer(unsigned int size) {
    m_Size = size;
    m_Neurons.reserve(size);
    for (unsigned int i = 0; i < size; i++)
        m_Neurons.emplace_back(std::make_shared<Neuron>(Neuron()));
}

unsigned int Layer::Size() const {
    return m_Size;
}

void Layer::Print_Values() const {
    for (const std::shared_ptr<Neuron> neuron : m_Neurons)
        std::cout << neuron->Value() << (neuron == m_Neurons.back() ? "\n\n" : ", ");
}

std::shared_ptr<Neuron> Layer::operator[](unsigned int idx) {
    return m_Neurons.at(idx);
}
