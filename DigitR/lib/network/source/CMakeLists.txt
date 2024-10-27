add_library(network Network.cpp Layer.cpp Neuron.cpp)
target_link_libraries(network PUBLIC cxx_setup)
