#include "../include/Layer.hpp"
#include <iostream>
#include <memory>
#include "../include/Neuron.hpp"

Layer::Layer(unsigned int size) {
    m_Size = size;
    m_Neurons.reserve(size);
    for (unsigned int it = 0; it < size; ++it)
        m_Neurons.emplace_back(std::make_shared<Neuron>(Neuron()));
}

unsigned int Layer::Size() const {
    return m_Size;
}

std::shared_ptr<Neuron> Layer::at(unsigned int index) const {
    return m_Neurons.at(index);
}

void Layer::Print_Values() const {
    for (unsigned int it = 0; it < m_Size; ++it)
        std::cout << it << ". value = " << m_Neurons.at(it)->Value() << "\n";
}
