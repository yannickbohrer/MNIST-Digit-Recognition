#include "../include/MNIST_Reader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include "../../../include/DigitR.hpp"

MNIST_Reader& MNIST_Reader::Get() {
    static MNIST_Reader m_Instance;
    return m_Instance;
}

MNIST_Reader::MNIST_Reader()
    : m_Test_data_csv_path(std::string(DR::Constants::assets_dir + "mnist_test.csv")),
      m_Training_data_csv_path(std::string(DR::Constants::assets_dir + "mnist_train.csv")) {
    Parse_csv(m_Test_data_csv_path, m_Test_data);
    Parse_csv(m_Training_data_csv_path, m_Training_data);
}

void MNIST_Reader::Parse_csv(
    std::string& file_path,
    std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>>& data_container) const {
    std::cout << "parsing " << file_path << "   | START" << std::endl;

    std::fstream file(file_path, std::ios::in);

    bool label_pos = true;
    int sample_number = -1;

    std::string line;
    while (getline(file, line)) {
        ++sample_number;

        // first line in .csv file contains table headers
        if (sample_number == 0)
            continue;

        label_pos = true;
        int label;
        std::array<int, DR::Constants::pixels_per_number> pixels = {0};

        std::stringstream line_sstream(line);
        std::string cell = "";
        int it = 0;
        char char_at_it;
        while (line_sstream >> char_at_it) {
            cell += char_at_it;
            if (line_sstream.peek() == ',') {
                if (label_pos) {
                    label = std::stoi(cell);
                    label_pos = false;
                } else {
                    pixels.at(it) = std::stoi(cell);
                    ++it;
                }
                line_sstream.ignore();
                cell = "";
            }
        }
        data_container.emplace_back(std::tuple(label, pixels));
    }
    file.close();
    std::cout << "parsing " << file_path << "   | DONE" << std::endl;
}

std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>>& MNIST_Reader::Test_data() const {
    return MNIST_Reader::Get().m_Test_data;
}

std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>>& MNIST_Reader::Training_data() const {
    return MNIST_Reader::Get().m_Training_data;
}
