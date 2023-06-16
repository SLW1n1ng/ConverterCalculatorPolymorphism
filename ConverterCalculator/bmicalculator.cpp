#include "BMICalculator.h"
#include <iostream>

double BMICalculator::calculate(double weight, double height) {
	return weight / (height * height);
}

std::string BMICalculator::interpretResult(double result) {
	if (result < 18.5)
		return "Underweight";
	else if (result < 25)
		return "Normal weight";
	else if (result < 30)
		return "Overweight";
	else
		return "Obese";
}

void BMICalculator::description() const {
	std::cout << "\nBMI Calculator: Calculates Body Mass Index (BMI).\n" << std::endl;
}
