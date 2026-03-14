#pragma once

#include <vector>

class Neuron {
public:
    explicit Neuron(double value = 1.0);
    [[nodiscard]] double Value() const;
    [[nodiscard]] std::vector<double>& Weights();
    void Set_Activation_Value(double);
    void Add_To_Linear_Combination(double, double);
    void Update_Activation();
    [[nodiscard]] static double Normalize(double, int denominator = 255);  // rgb(255) is white
    [[nodiscard]] static double Sigmoid(double);

private:
    double m_Value;
    double m_Linear_combination;
    double m_Bias;
    std::vector<double> m_Weights;
};
