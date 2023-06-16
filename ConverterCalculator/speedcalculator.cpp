#include "SpeedCalculator.h"
#include <iostream>

double SpeedCalculator::calculate(double distance, double time) {
	return distance / time;
}

std::string SpeedCalculator::interpretResult(double result) {
	if (result < 0.2778)
		return "Slow speed";
	else if (result < 1.3889)
		return "Walking speed";
	else if (result < 5.5556)
		return "Running speed";
	else if (result < 11.1111)
		return "Biking speed";
	else
		return "Driving speed";
}

void SpeedCalculator::description() const {
	std::cout << "\nSpeed Calculator: Calculates speed." << std::endl;
}
