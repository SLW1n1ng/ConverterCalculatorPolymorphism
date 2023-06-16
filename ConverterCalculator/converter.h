#ifndef CONVERTER_H
#define CONVERTER_H

class Converter {
public:
	virtual ~Converter() {}
	virtual double toMetric(double value) = 0;
	virtual double toImperial(double value) = 0;
	virtual void description() const = 0;
};

#endif  // CONVERTER_H
