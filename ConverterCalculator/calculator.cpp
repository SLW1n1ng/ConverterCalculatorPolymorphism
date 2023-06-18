#include "Calculator.h"
#include <iostream>

void Calculator::printResult(double result, int unitSystem, int imperial, int metric, bool printBMI) {
	if (printBMI) { // If printBMI is true, print the BMI interpretation
		std::cout << "Result: " << result << std::endl;
	}
	else if (unitSystem == imperial) { // 1 = Imperial, 2 = Metric
		std::cout << "Result: " << result << " ft/s (" << result * 15 / 22 << " miles/hr)" << std::endl;
	}
	else if (unitSystem == metric) { // 1 = Imperial, 2 = Metric
		std::cout << "Result: " << result << " m/s (" << result * 3.6 << " km/hr)" << std::endl;
	}
	std::string interpretation = interpretResult(result); // Derived class will implement this function
	std::cout << "Interpretation: " << interpretation << std::endl;
}
