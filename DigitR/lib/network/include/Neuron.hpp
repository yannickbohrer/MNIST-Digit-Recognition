#pragma once

class Neuron {
public:
    explicit Neuron(double value = 0.0);
    [[nodiscard]] double Value() const;
    void Set_Value(double value);

private:
    double m_Value;
};
