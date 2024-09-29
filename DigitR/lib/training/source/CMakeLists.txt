add_library(training Gradient_Descent.cpp Executor.cpp)
target_link_libraries(training PUBLIC cxx_setup)
