#include "DistanceConverter.h"
#include <iostream>

double DistanceConverter::toMetric(double value) {
	return value * 0.3048; // feet to meters
}

double DistanceConverter::toImperial(double value) {
	return value * 3.28084; // meters to feet
}

void DistanceConverter::description() const {
	std::cout << "Distance Converter: Converts between feet and meters." << std::endl;
}

