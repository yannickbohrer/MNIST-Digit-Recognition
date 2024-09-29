add_executable(DigitR ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/main.cpp)
target_link_libraries(DigitR PUBLIC cxx_setup mnist network training)
