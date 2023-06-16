#ifndef BMICALCULATOR_H
#define BMICALCULATOR_H

#include "Calculator.h"

class BMICalculator : public Calculator {
public:
	~BMICalculator() {}
	double calculate(double weight, double height) override;
	std::string interpretResult(double result) override;
	void description() const override;
};

#endif  // BMICALCULATOR_H

