#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
	virtual ~Calculator() {}
	virtual double calculate(double val1, double val2) = 0;
	void printResult(double result, int unitSystem, int imperial, int metric, bool printBMI = false);
	virtual void description() const = 0;

protected:
	virtual std::string interpretResult(double result) = 0;
};

#endif  // CALCULATOR_H
