#pragma once
#include "../../mnist/include/MNIST_Reader.hpp"
#include "../../network/include/Network.hpp"

class Executor {
public:
    static void Run();

private:
    Executor();
    Executor(const Executor&) = delete;
    static Executor m_Instance;
    [[nodiscard]] static Executor& Get();

    Network& network;
    MNIST_Reader& mnist;
};
