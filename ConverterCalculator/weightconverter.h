#ifndef WEIGHTCONVERTER_H
#define WEIGHTCONVERTER_H

#include "Converter.h"

class WeightConverter : public Converter {
public:
	~WeightConverter() {}
	double toMetric(double value) override;
	double toImperial(double value) override;
	void description() const override;
};

#endif  // WEIGHTCONVERTER_H
