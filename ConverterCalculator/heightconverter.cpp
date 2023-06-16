#include "HeightConverter.h"
#include <iostream>

double HeightConverter::toMetric(double value) {
	return value * 0.3048; // feet to meters
}

double HeightConverter::toImperial(double value) {
	return value * 3.28084; // meters to feet
}

void HeightConverter::description() const {
	std::cout << "Height Converter: Converts between feet and meters." << std::endl;
}
