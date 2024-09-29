#pragma once
#include <string>
#include "../lib/network/include/Network.hpp"

#define NUMBER_OF_HIDDEN_LAYERS 4    // Can be adjusted
#define NEURONS_PER_HIDDEN_LAYER 16  // Can be adjusted

namespace DR {

namespace Constants {

inline const std::string assets_dir = std::string(ASSETS_DIR);
inline const int pixels_per_number = 784;
inline const int number_of_output_neurons = 10;
inline const Network::Hyperparameters hyper_params = {DR::Constants::pixels_per_number, NUMBER_OF_HIDDEN_LAYERS,
                                                      NEURONS_PER_HIDDEN_LAYER,
                                                      DR::Constants::number_of_output_neurons};

}  // namespace Constants

}  // namespace DR
