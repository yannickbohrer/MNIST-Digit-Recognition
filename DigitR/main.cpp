#include <cstdlib>
#include "lib/mnist/include/MNIST_Reader.hpp"
#include "lib/network/include/Network.hpp"
#include "lib/training/include/Executor.hpp"

int main(const int argc, const char** argv) {
    (void)MNIST_Reader::Get();
    (void)Network::Get();
    Executor::Run();
    return EXIT_SUCCESS;
}
