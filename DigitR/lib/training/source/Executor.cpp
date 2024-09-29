#include "../include/Executor.hpp"
#include <iostream>

void Executor::Run() {
    std::cout << "Starting Executor\n\n";
    Executor& exe = Executor::Get();
}

Executor& Executor::Get() {
    static Executor m_Instance;
    return m_Instance;
}

Executor::Executor() : network(Network::Get()), mnist(MNIST_Reader::Get()) {
    std::cout << "Executor constructed successfully\n\n";
}
