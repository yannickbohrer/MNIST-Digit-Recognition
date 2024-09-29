add_library(mnist MNIST_Reader.cpp)
target_link_libraries(mnist PUBLIC cxx_setup)
