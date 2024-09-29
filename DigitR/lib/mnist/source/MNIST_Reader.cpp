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
    int sample_number = -1, it = 0;

    std::string line;
    char c_at_pos;
    std::string cell;
    while (getline(file, line)) {
        ++sample_number;
        if (sample_number == 0)
            continue;

        label_pos = true;
        int label;
        std::array<int, DR::Constants::pixels_per_number> pixels = {0};

        std::stringstream line_parser(line);
        cell = "";
        it = 0;
        while (line_parser >> c_at_pos) {
            cell += c_at_pos;
            if (line_parser.peek() == ',') {
                if (label_pos) {
                    label = std::stoi(cell);
                    label_pos = false;
                    line_parser.ignore();
                    cell = "";
                    continue;
                }
                pixels.at(it) = std::stoi(cell);
                ++it;
                line_parser.ignore();
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
