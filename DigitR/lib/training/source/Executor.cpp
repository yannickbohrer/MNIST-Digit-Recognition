#include "../include/Executor.hpp"
#include <array>
#include <vector>

void Executor::Run() {
    Executor& exe = Executor::Get();
}

Executor& Executor::Get() {
    static Executor m_Instance;
    return m_Instance;
}

Executor::Executor() : network(Network::Get()), mnist(MNIST_Reader::Get()) {
    Process_Input(mnist.Training_data().at(0));
}

void Executor::Process_Input(std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>& sample) {
    std::array<int, DR::Constants::pixels_per_number>& pixels = std::get<1>(sample);
    for (unsigned int it = 0; it < DR::Constants::pixels_per_number; ++it)
        network.Input_Layer()[it]->Set_Value(Neuron::Normalize(pixels.at(it)));
    network.Iteration();
}
