#include "WeightConverter.h"
#include <iostream>

double WeightConverter::toMetric(double value) {
    return value * 0.453592; // pounds to kilograms
}

double WeightConverter::toImperial(double value) {
    return value * 2.20462; // kilograms to pounds
}

void WeightConverter::description() const {
    std::cout << "\nWeight Converter: Converts between pounds and kilograms." << std::endl;
}
