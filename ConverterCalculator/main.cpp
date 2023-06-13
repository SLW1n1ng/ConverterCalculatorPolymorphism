#include <iostream>

class Converter {
public:
    virtual double toMetric(double value) = 0;
    virtual double toImperial(double value) = 0;
    virtual void description() const = 0;
};

class WeightConverter : public Converter {
public:
    double toMetric(double value) override {
        return value * 0.453592; // pounds to kilograms
    }

    double toImperial(double value) override {
        return value * 2.20462; // kilograms to pounds
    }

    void description() const override {
        std::cout << "Weight Converter: Converts between pounds and kilograms." << std::endl;
    }
};

class DistanceConverter : public Converter {
public:
    double toMetric(double value) override {
        return value * 0.3048; // feet to meters
    }

    double toImperial(double value) override {
        return value * 3.28084; // meters to feet
    }

    void description() const override {
        std::cout << "Distance Converter: Converts between feet and meters." << std::endl;
    }
};

class HeightConverter : public Converter {
public:
    double toMetric(double value) override {
        return value * 0.0254; // inches to meters
    }

    double toImperial(double value) override {
        return value * 39.3701; // meters to inches
    }

    void description() const override {
        std::cout << "Height Converter: Converts between inches and meters." << std::endl;
    }
};

class Calculator {
public:
    virtual double calculate(double val1, double val2) = 0;

    void printResult(double result) {
        std::cout << "Result: " << result << std::endl;
    }

    virtual void description() const = 0;

    void printInterpretation(double result) { // new method added to base class 
        std::cout << "Interpretation: " << interpretResult(result) << std::endl;
    }

protected:
    virtual std::string interpretResult(double result) = 0;
};

class BMICalculator : public Calculator {
public:
    double calculate(double weight, double height) override {
        return weight / (height * height);
    }

    std::string interpretResult(double result) override {
        if (result < 18.5)
            return "Underweight";
        else if (result < 25)
            return "Normal weight";
        else if (result < 30)
            return "Overweight";
        else
            return "Obese";
    }

    void description() const override {
        std::cout << "BMI Calculator: Calculates Body Mass Index (BMI)." << std::endl;
    }
    //> >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    void printInterpretation(double result) {
        std::cout << "Interpretation: " << interpretResult(result) << std::endl;
    }
};

class SpeedCalculator : public Calculator {
public:
    double calculate(double distance, double time) override {
        return distance / time;
    }

    std::string interpretResult(double result) override {
        if (result < 1)
            return "Slow speed";
        else if (result < 5)
            return "Walking speed";
        else if (result < 20)
            return "Running speed";
        else if (result < 40)
            return "Biking speed";
        else
            return "Driving speed";
    }

    void description() const override {
        std::cout << "Speed Calculator: Calculates speed." << std::endl;
    }
};

int main() {
    std::string unitSystem;
    std::cout << "Choose your preferred unit system (imperial or metric): ";
    std::cin >> unitSystem;

    Converter* weightConverter;
    Converter* heightConverter;
    Calculator* bmiCalculator;
    Calculator* speedCalculator;

    if (unitSystem == "imperial") {
        weightConverter = new WeightConverter();
        heightConverter = new HeightConverter();
        bmiCalculator = new BMICalculator();
        speedCalculator = new SpeedCalculator();
    }
    else if (unitSystem == "metric") {
        weightConverter = new WeightConverter();
        heightConverter = new HeightConverter();
        bmiCalculator = new BMICalculator();
        speedCalculator = new SpeedCalculator();
    }
    else {
        std::cout << "Invalid unit system. Program will exit." << std::endl;
        return 0;
    }

    weightConverter->description();
    heightConverter->description();

    double weight, height;
    std::cout << "Enter your weight: ";
    std::cin >> weight;
    std::cout << "Enter your height: ";
    std::cin >> height;

    double metricWeight = weightConverter->toMetric(weight);
    double metricHeight = heightConverter->toMetric(height);

    bmiCalculator->description();
    double bmiResult = bmiCalculator->calculate(metricWeight, metricHeight);

    std::cout << "BMI: ";
    bmiCalculator->printResult(bmiResult);

    bmiCalculator->printInterpretation(bmiResult);

    DistanceConverter* distanceConverter;
    if (unitSystem == "imperial") {
        distanceConverter = new DistanceConverter();

        distanceConverter->description();
        double distance;
        std::cout << "Enter a distance: ";
        std::cin >> distance;

        double metricDistance = distanceConverter->toMetric(distance);

        speedCalculator->description();
        double time;
        std::cout << "Enter a time: ";
        std::cin >> time;

        double speedResult = speedCalculator->calculate(metricDistance, time);

        std::cout << "Speed: ";
        speedCalculator->printResult(speedResult);

        speedCalculator->printInterpretation(speedResult);

        double imperialSpeed = distanceConverter->toImperial(speedResult);
        std::cout << "Speed (imperial units): " << imperialSpeed << std::endl;

        delete distanceConverter;
    }
    else if (unitSystem == "metric") {
        speedCalculator->description();
        double distance, time;
        std::cout << "Enter a distance: ";
        std::cin >> distance;
        std::cout << "Enter a time: ";
        std::cin >> time;

        double speedResult = speedCalculator->calculate(distance, time);

        std::cout << "Speed: ";
        speedCalculator->printResult(speedResult);

        speedCalculator->printInterpretation(speedResult);
    }

    delete weightConverter;
    delete heightConverter;
    delete bmiCalculator;
    delete speedCalculator;

    return 0;
}

