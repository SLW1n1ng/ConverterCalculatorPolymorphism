#include <iostream>
#include <algorithm>    // for std::transform
#include <string> 
#include <cstdlib>	
#include <conio.h>		// for _getch()

#include "clearInputBuffer.h"
#include "WeightConverter.h"
#include "DistanceConverter.h"
#include "HeightConverter.h"
#include "BMICalculator.h"
#include "SpeedCalculator.h"
#include "displaymenu.h"
#include "displayUnitSystemMenu.h"
#include "main.h"
#include "getunitsyteminput.h"
#include "getuserinputforvariable.h"
#include "doesuserwanttocontinue.h"
#include "getmenuinput.h"

int main() {
	bool continueProgram = true;					// Flag to control the loop
	while (continueProgram) {

		displayMenu();								// Prints the menu
		int choice;									// local variable for choice
		getMenuInput(choice);						// User input for menu items

		int unitSystem;								// local variable for unitSystem
		int imperial = 1;							// local variable for imperial
		int metric = 2;								// local variable for metric

		switch (choice) {
		case 1: // 1. Convert Weight >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* weightConverter = new WeightConverter();	// New instance of WeightConverter class

			displayUnitSystemMenu();							// Prints the unit system menu
			getUnitSystemInput(unitSystem, imperial, metric);	// User input for unit system

			weightConverter->description();						// Prints "Weight Converter: ..."

			double weight;										// local variable for weight
			getUserInputForVariable("weight", weight);			// User input for weight

			double convertedWeight = 0;							// local variable for converted weight
			if (unitSystem == imperial) {
				convertedWeight = weightConverter->toMetric(weight); // Converts weight to metric
				std::cout << "Weight (metric): " << convertedWeight << " kg" << std::endl;
			}
			else if (unitSystem == metric) {
				convertedWeight = weightConverter->toImperial(weight); // Converts weight to imperial
				std::cout << "Weight (imperial): " << convertedWeight << " lb" << std::endl;
			}

			delete weightConverter;									// Deletes weightConverter instance
			break;
		}
		case 2: // 2. Convert Distance >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* distanceConverter = new DistanceConverter(); // New instance of DistanceConverter class

			displayUnitSystemMenu();								// Prints the unit system menu
			getUnitSystemInput(unitSystem, imperial, metric);		// User input for unit system

			distanceConverter->description();						// Prints "Distance Converter: ...."

			double distance;										// local variable for distance
			getUserInputForVariable("distance", distance);			// User input for distance

			double convertedDistance = 0;							// local variable for converted distance

			if (unitSystem == imperial) {
				convertedDistance = distanceConverter->toMetric(distance); // Converts distance to metric
				std::cout << "Distance (metric): " << convertedDistance << " meters" << std::endl;
			}
			else if (unitSystem == metric) {
				convertedDistance = distanceConverter->toImperial(distance); // Converts distance to imperial
				std::cout << "Distance (imperial): " << convertedDistance << " feet" << std::endl;
			}
			delete distanceConverter;								// Deletes distanceConverter instance
			break;
		}
		case 3: // 3. BMI Calculator >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* weightConverter = new WeightConverter();		// New instance of WeightConverter class
			Converter* heightConverter = new HeightConverter();		// New instance of HeightConverter class 
			Calculator* bmiCalculator = new BMICalculator();		// New instance of BMICalculator class

			displayUnitSystemMenu();							// Prints the unit system menu
			getUnitSystemInput(unitSystem, imperial, metric);	// User input for unit system

			weightConverter->description(); // Prints "Weight Converter: Converts between pounds and kilograms."
			heightConverter->description(); // Prints "Height Converter: Converts between inches and meters."

			double weight, height;                          // local variables for weight and height
			getUserInputForVariable("weight", weight);      // User input for weight
			getUserInputForVariable("height", height);      // User input for height

			double bmiResult = 0;							 // local variable for bmiResult

			if (unitSystem == imperial) {

				double metricWeight = weightConverter->toMetric(weight); // Converts weight to metric
				double metricHeight = heightConverter->toMetric(height); // Converts height to metric

				bmiCalculator->description();	// Prints "BMI Calculator: Calculates ,..."
				bmiResult = bmiCalculator->calculate(metricWeight, metricHeight);///calculate BMI

				delete weightConverter;						// Deletes weightConverter instance
				delete heightConverter;						// Deletes heightConverter instance
			}
			else if (unitSystem == metric) {

				bmiCalculator->description();				// Prints "BMI Calculator:..."
				bmiResult = bmiCalculator->calculate(weight, height);///calculate BMI
			}
			std::cout << "BMI: ";
			bmiCalculator->printResult(bmiResult, unitSystem, imperial, metric, true);	// Prints "Result: <bmiResult>"

			delete bmiCalculator;							// Deletes bmiCalculator instance
			break;											// Breaks out of case 3
		}
		case 4: // 4. Speed Calculator >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Calculator* speedCalculator = new SpeedCalculator();	// New instance of SpeedCalculator class
			Converter* distanceConverter = new DistanceConverter(); //instance of DistanceConverter class

			displayUnitSystemMenu();							// Prints the unit system menu
			getUnitSystemInput(unitSystem, imperial, metric);	// User input for unit system

			speedCalculator->description();						// Prints "Speed Calculator: Calculates speed."
			distanceConverter->description();					// Prints distance converter description

			double distance;									// local variable for distance
			getUserInputForVariable("distance", distance);		// User input for distance

			double time;										// local variable for time
			getUserInputForVariable("time", time);				// User input for time

			if (unitSystem == imperial) {

				double metricDistance = distanceConverter->toMetric(distance);			// Converts distance to metric
				double speedResult = speedCalculator->calculate(metricDistance, time);	// Calculates speed in m/s
				double imperialSpeed = distanceConverter->toImperial(speedResult);		// Converts speed to imperial

				std::cout << "\nSpeed: ";
				speedCalculator->printResult(imperialSpeed, unitSystem, imperial, metric, false);

				std::cout << "Speed (metric units): " << speedResult << " m/s (" << speedResult * 3.6 << " km/hr)" << std::endl;
			}
			else if (unitSystem == metric) {

				double speedResult = speedCalculator->calculate(distance, time); // Calculates speed in m/s

				std::cout << "\nSpeed: ";
				speedCalculator->printResult(speedResult, unitSystem, imperial, metric, false);	

				double imperialSpeed = distanceConverter->toImperial(speedResult);		// Converts speed to imperial
				std::cout << "Speed (imperial units): " << imperialSpeed << "ft/s (" << imperialSpeed * 15 / 22 << " mph)" << std::endl;
			}
			delete distanceConverter;					// Deletes distanceConverter instance
			delete speedCalculator;						// Deletes speedCalculator instance

			break;
		}
		case 5: // 5. Exit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			return 0;
		}
		}												
		doesUserWantToContinue(continueProgram);	// Asks user if they want to continue
	}
	return 0;
}
