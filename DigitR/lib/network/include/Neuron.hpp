#pragma once

class Neuron {
public:
    explicit Neuron(double value = 1.0);
    [[nodiscard]] double Value() const;
    void Set_Value(double);
    void Add_To_Linear_Combination(double, double);
    void Update_Activation(int);
    [[nodiscard]] static double Normalize(int, int number_of_inputs = 255);

private:
    double m_Value;
    double m_linear_combination;
};
