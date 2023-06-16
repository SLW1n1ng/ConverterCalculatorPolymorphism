#ifndef HEIGHTCONVERTER_H
#define HEIGHTCONVERTER_H

#include "Converter.h"

class HeightConverter : public Converter {
public:
	~HeightConverter() {}
	double toMetric(double value) override;
	double toImperial(double value) override;
	void description() const override;
};

#endif  // HEIGHTCONVERTER_H

