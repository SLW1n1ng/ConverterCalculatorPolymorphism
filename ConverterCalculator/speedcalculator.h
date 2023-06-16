#ifndef SPEEDCALCULATOR_H
#define SPEEDCALCULATOR_H

#include "Calculator.h"

class SpeedCalculator : public Calculator {
public:
	~SpeedCalculator() {}
	double calculate(double distance, double time) override;
	std::string interpretResult(double result) override;
	void description() const override;
};

#endif  // SPEEDCALCULATOR_H
#pragma once
