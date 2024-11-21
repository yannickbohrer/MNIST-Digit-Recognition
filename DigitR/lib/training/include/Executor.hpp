#pragma once
#include <array>
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

    [[nodiscard]] double Normalize(int) const;
    void Process_Input(std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>&);

    Network& network;
    MNIST_Reader& mnist;
};
