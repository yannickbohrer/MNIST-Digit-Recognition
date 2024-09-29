#include <cstdlib>
#include "lib/mnist/include/MNIST_Reader.hpp"
#include "lib/network/include/Network.hpp"

int main(const int argc, const char** argv) {
    const MNIST_Reader& mnist = MNIST_Reader::Get();
    Network::Init();
    return EXIT_SUCCESS;
}
