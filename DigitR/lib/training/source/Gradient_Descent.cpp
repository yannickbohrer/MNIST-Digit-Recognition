#include <math.h>
#include <iostream>
#include <vector>

std::vector<double>* Gradient(std::vector<double>& x, double (*function)(std::vector<int>& pos)) {
    std::vector<double> grad(x.size());
    double h = 1e-8;
    double functionX = function(x);

    for (int i = 0; i < x.size(); i++) {
        std::vector<double> gradTmp(x.size());
        gradTmp = x;
        gradTmp[i] += h;

        double tmp = (function(gradTmp) - functionX) / h;
        grad[i] = tmp;
    }
    return grad;
}

void Gradient_Descendt(std::vector<double>& xVector, double (*function)(std::vector<double>& pos), double lambda = 1.0,
                       int counter = 0, bool log = false) {
    std::vector<double> grad = Gradient(xVector, function);
    std::vector<double> vectorStep = xVector + (grad * lambda);

    double xValue = function(xVector);
    double valueAtFirstStep = function(vectorStep);
    double valueAtStep;
    double gradLength = grad.getLength();

    if (counter == 25) {  // max 25 steps
        if (log) {
            std::cout << "Ende wegen Schrittzahl = 25 bei" << std::endl;
            std::cout << "\tx = " << xVector << std::endl;
            std::cout << "\tlambda = " << lambda << std::endl;
            std::cout << "\tf(x) = " << xValue << std::endl;
            std::cout << "\tgrad f(x) = " << grad << std::endl;
            std::cout << "\t||grad f(x)|| = " << gradLength << std::endl << std::endl;
        }
        return;
    }

    if (gradLength < 1e-5) {  // gradient length < 0.00001 -> desired accuracy
        if (log) {
            std::cout << "Ende wegen ||grad f(x)|| < 1e-5 bei" << std::endl;
            std::cout << "\tx = " << xVector << std::endl;
            std::cout << "\tlambda = " << lambda << std::endl;
            std::cout << "\tf(x) = " << xValue << std::endl;
            std::cout << "\tgrad f(x) = " << grad << std::endl;
            std::cout << "\t||grad f(x)|| = " << gradLength << std::endl << std::endl;
        }
        return;
    }

    if (log) {
        std::cout << "Schritt " << counter << ":" << std::endl;
        std::cout << "\tx = " << xVector << std::endl;
        std::cout << "\tlambda = " << lambda << std::endl;
        std::cout << "\tf(x) = " << xValue << std::endl;
        std::cout << "\tgrad f(x) = " << grad << std::endl;
        std::cout << "\t||grad f(x)|| = " << gradLength << std::endl;
        std::cout << std::endl;
        std::cout << "\tx_neu = " << vectorStep << std::endl;
        std::cout << "\tf(x_neu) = " << valueAtFirstStep << std::endl;
        std::cout << std::endl;
    }

    if (valueAtFirstStep <= xValue) {
        valueAtStep = valueAtFirstStep;
        while (valueAtStep <= xValue) {
            lambda = lambda / 2;
            vectorStep = x + (grad * lambda);
            valueAtStep = function(vectorStep);
            if (log) {
                std::cout << "\t halbiere Schrittweite (lambda = " << lambda << "):" << std::endl;
                std::cout << "\tx_neu = " << vectorStep << std::endl;
                std::cout << "\tf(x_neu) = " << valueAtStep << std::endl << std::endl;
            }
        }
        Gradient_Descendt(vectorStep, function, lambda, ++counter);
        return;
    }

    std::vector<int> vectorTest = x + (grad * lambda * 2);
    double valueAtTest = function(vectorTest);

    if (log) {
        std::cout << "\tTest mit doppelter Schrittweite (lambda = " << lambda * 2 << "):" << std::endl;
        std::cout << "\tx_test = " << vectorTest << std::endl;
        std::cout << "\tf(x_test) = " << valueAtTest << std::endl;
    }

    if (valueAtTest > valueAtFirstStep) {
        if (log) {
            std::cout << "\tverdoppele Schrittweite!" << std::endl << std::endl;
        }
        Gradient_Descendt(vectorTest, function, lambda * 2, ++counter);
        return;
    }

    if (log) {
        std::cout << "\tbehalte alte Schrittweite!" << std::endl << std::endl;
    }
    Gradient_Descendt(vectorStep, function, lambda, ++counter);
}

/**
 
int main() {
    int eingabe;

    std::vector<int> vectorfunction1(2);
    vectorfunction1.setComponent(0, 0.2);
    vectorfunction1.setComponent(1, -2.1);

    std::vector<int> vectorfunction2(3);
    vectorfunction2.setComponent(0, 0);
    vectorfunction2.setComponent(1, 0);
    vectorfunction2.setComponent(2, 0);

    if (log) {
        std::cout << "Zu welcher function soll das Verfahren gemacht werden?\n1) oder 2)\n";
    }

    do {
        std::cout << "> ";
        std::cin >> eingabe;
    } while (eingabe < 1 || eingabe > 2);
    std::cout << std::endl << std::endl;

    switch (eingabe) {
        case 1:
            Gradient_Descendt(vectorfunction1, function1);
            break;
        case 2:
            Gradient_Descendt(vectorfunction2, function2, 0.1);
            break;
    }
}

**/
