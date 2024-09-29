#include <cstdlib>
#include "include/DigitR.hpp"
#include "lib/mnist/include/MNIST_Reader.hpp"
#include "lib/network/include/Network.hpp"

#define NUMBER_OF_HIDDEN_LAYERS 4    // Can be adjusted
#define NEURONS_PER_HIDDEN_LAYER 16  // Can be adjusted

int main(const int argc, const char** argv) {
    const MNIST_Reader& mnist = MNIST_Reader::Get();

    Network::Hyperparameters hyper_params = {DR::Constants::pixels_per_number, NUMBER_OF_HIDDEN_LAYERS,
                                             NEURONS_PER_HIDDEN_LAYER, DR::Constants::number_of_output_neurons};
    const Network& network = Network::Get(hyper_params);
    return EXIT_SUCCESS;
}
