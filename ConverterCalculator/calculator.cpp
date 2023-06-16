#include "Calculator.h"
#include <iostream>

void Calculator::printResult(double result, const std::string& unitSystem, bool printBMI) {
	if (printBMI) {
		std::cout << "Result: " << result << std::endl;
	}
	else if (unitSystem == "imperial" || unitSystem == "i") {
		std::cout << "Result: " << result << " ft/s (" << result * 15 / 22 << " miles/hr)" << std::endl;
	}
	else if (unitSystem == "metric" || unitSystem == "m") {
		std::cout << "Result: " << result << " m/s (" << result * 3.6 << " km/hr)" << std::endl;
	}
}
