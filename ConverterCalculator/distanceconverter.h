#ifndef DISTANCECONVERTER_H
#define DISTANCECONVERTER_H

#include "Converter.h"

class DistanceConverter : public Converter {
public:
	~DistanceConverter() {}
	double toMetric(double value) override;
	double toImperial(double value) override;
	void description() const override;
};

#endif  // DISTANCECONVERTER_H