#pragma once
#include <array>
#include <string>
#include <tuple>
#include <vector>
#include "../../../include/DigitR.hpp"

class MNIST_Reader {
public:
    static MNIST_Reader& Get();
    [[nodiscard]] std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>>& Test_data() const;
    [[nodiscard]] std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>>& Training_data()
        const;

private:
    explicit MNIST_Reader();
    MNIST_Reader(const MNIST_Reader&) = delete;
    static MNIST_Reader m_Instance;

    void Parse_csv(std::string&,
                   std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>>&) const;

    std::string m_Test_data_csv_path;
    std::string m_Training_data_csv_path;
    std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>> m_Test_data;
    std::vector<std::tuple<int, std::array<int, DR::Constants::pixels_per_number>>> m_Training_data;
};
