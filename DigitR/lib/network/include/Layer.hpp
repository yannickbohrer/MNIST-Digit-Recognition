#pragma once

#include <memory>
#include <vector>

#include "Neuron.hpp"

class Layer {
public:
    explicit Layer(unsigned int size);

    [[nodiscard]] unsigned int Size() const;
    void Print_Values() const;

    std::shared_ptr<Neuron> operator[](unsigned int idx);

private:
    std::vector<std::shared_ptr<Neuron>> m_Neurons;
    unsigned int m_Size;
};
