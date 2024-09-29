#include "../include/Executor.hpp"

void Executor::Run() {
    Executor& exe = Executor::Get();
}

Executor& Executor::Get() {
    static Executor m_Instance;
    return m_Instance;
}

Executor::Executor() : network(Network::Get()), mnist(MNIST_Reader::Get()) {}
