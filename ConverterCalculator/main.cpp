#include <iostream>
#include <algorithm>    // for std::transform
#include <cmath>		// for std::isnan
#include <string> 
#include <cstdlib>		

#include "WeightConverter.h"
#include "DistanceConverter.h"
#include "HeightConverter.h"
#include "BMICalculator.h"
#include "SpeedCalculator.h"
#include "displaymenu.h"

int main() {
	std::string unitSystem;								// local variable for unitSystem

	bool continueProgram = true; // Flag to control the loop
	while (continueProgram) {
			// User input for unit system
			std::cout << "\nChoose your preferred unit system (imperial or metric / i or m): ";
			std::cin >> unitSystem;

		std::system("cls");									// Clears the screen
		
		std::cout << "Unit System: " << unitSystem << std::endl;//display user unit system choice

		displayMenu();										// Prints the menu
		int choice;											// local variable for choice
		std::cout << "Enter your choice: "; 			   // User input for choice
		std::cin >> choice;

		// Clear input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice) {
		case 1: //Convert Weight >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			break;
		}
		case 2: // Convert Distance >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{

			break;
		}
		case 3: // BMI Calculator >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* weightConverter = new WeightConverter();    // New instance of WeightConverter class
			Converter* heightConverter = new HeightConverter();    // New instance of HeightConverter class 
			Calculator* bmiCalculator = new BMICalculator();		// New instance of BMICalculator class

			// User input validation for case-insensitivity and for i or m input
			std::transform(unitSystem.begin(), unitSystem.end(), unitSystem.begin(), ::tolower);
			if (unitSystem == "imperial" || unitSystem == "metric" || unitSystem == "i" || unitSystem == "m") {

				weightConverter->description(); // Prints "Weight Converter: Converts between pounds and kilograms."
				heightConverter->description(); // Prints "Height Converter: Converts between inches and meters."

				// User input for weight and height 
				double weight, height;                          // local variables for weight and height

				std::cout << "\nEnter your weight (lb/kg): ";
				std::cin >> weight;                             // User input for weight
				std::cout << "Enter your height (feet/meters): ";
				std::cin >> height;							    // User input for height

				double bmiResult = 0;							 // local variable for bmiResult
				std::string bmiInterpretation;				 // local variable for bmiInterpretation

				if ((unitSystem == "imperial" || unitSystem == "i")
					&& (weight > 0 && height > 0)
					&& (!std::isnan(weight) && !std::isnan(height))) {

					double metricWeight = weightConverter->toMetric(weight); // Converts weight to metric
					double metricHeight = heightConverter->toMetric(height); // Converts height to metric

					bmiCalculator->description();
					bmiResult = bmiCalculator->calculate(metricWeight, metricHeight);///calculate BMI
					bmiInterpretation = static_cast<BMICalculator*>(bmiCalculator)->interpretResult(bmiResult);
				}
				else if ((unitSystem == "metric" || unitSystem == "m")
					&& (weight > 0 && height > 0)
					&& (!std::isnan(weight) && !std::isnan(height))) {

					bmiCalculator->description();				// Prints "BMI Calculator: Calculates Body Mass Index (BMI)."
					bmiResult = bmiCalculator->calculate(weight, height);///calculate BMI
					bmiInterpretation = static_cast<BMICalculator*>(bmiCalculator)->interpretResult(bmiResult);
				}
				else {
					std::cout << "\nInvalid inputs. Program will exit." << std::endl;
					delete weightConverter;
					delete heightConverter;
					delete bmiCalculator;
					return 0;
				}
				delete weightConverter;						// Deletes weightConverter instance
				delete heightConverter;						// Deletes heightConverter instance

				std::cout << "BMI: ";
				bmiCalculator->printResult(bmiResult, unitSystem, true);		// Prints "Result: <bmiResult>"
				std::cout << "Interpretation: " << bmiInterpretation << std::endl;

				delete bmiCalculator;						// Deletes bmiCalculator instance
			}
			else {
				std::cout << "Invalid unit system. Program will exit." << std::endl;
				return 0;
			}
			break;											// Breaks out of case 3
		}

		case 4: // Speed Calculator >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			// User input for speed calculation
			Calculator* speedCalculator = new SpeedCalculator();	// New instance of SpeedCalculator class
			Converter* distanceConverter = new DistanceConverter(); //instance of DistanceConverter class

			speedCalculator->description();			    // Prints "Speed Calculator: Calculates speed."
			distanceConverter->description();           // Prints distance converter description

			double distance;                            // local variable for distance
			std::cout << "\nEnter a distance: ";
			std::cin >> distance;

			double time;								// local variable for time
			std::cout << "Enter a time in seconds: ";
			std::cin >> time;

			if ((unitSystem == "imperial" || unitSystem == "i")
				&& (distance > 0 && time > 0)
				&& (!std::isnan(distance) && !std::isnan(time))) {

				double metricDistance = distanceConverter->toMetric(distance); // Converts distance to metric

				double speedResult = speedCalculator->calculate(metricDistance, time); // Calculates speed in m/s
				std::string speedInterpretation = static_cast<SpeedCalculator*>(speedCalculator)->interpretResult(speedResult);

				std::cout << "\nSpeed: ";
				double imperialSpeed = distanceConverter->toImperial(speedResult);		// Converts speed to imperial
				speedCalculator->printResult(imperialSpeed, unitSystem);				// Prints "Result: <speedResult>"
				std::cout << "Interpretation: " << speedInterpretation << std::endl;	// Prints "Interpretation: <speedInterpretation>"

				std::cout << "Speed (metric units): " << speedResult << " m/s (" << speedResult * 3.6 << " km/hr)" << std::endl;
			}
			else if ((unitSystem == "metric" || unitSystem == "m")
				&& (distance > 0 && time > 0)
				&& (!std::isnan(distance) && !std::isnan(time))) {

				double speedResult = speedCalculator->calculate(distance, time); // Calculates speed in m/s
				std::string speedInterpretation = static_cast<SpeedCalculator*>(speedCalculator)->interpretResult(speedResult);

				std::cout << "\nSpeed: ";
				speedCalculator->printResult(speedResult, unitSystem);  // Prints "Result: <speedResult>"
				std::cout << "Interpretation: " << speedInterpretation << std::endl;

				double imperialSpeed = distanceConverter->toImperial(speedResult); // Converts speed to imperial
				std::cout << "Speed (imperial units): " << imperialSpeed << "ft/s (" << imperialSpeed * 15 / 22 << " mph)" << std::endl;
			}
			else {
				std::cout << "\nInvalid inputs. Program will exit." << std::endl;
				delete distanceConverter;
				delete speedCalculator;
				return 0;
			}
			delete distanceConverter;					// Deletes distanceConverter instance
			delete speedCalculator;						// Deletes speedCalculator instance

			break;
		}

		case 5: // Exit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			return 0;
		}
		default: // Invalid input >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			std::cout << "\nInvalid input. Program will exit." << std::endl;
			break;
		}
		}			// End of switch statement

			// Ask the user if they want to continue or quit
		std::string choice2 = "";
		std::cout << "\nDo you want to continue? (yes/no) or (y/n): ";
		std::cin >> choice2;
		std::transform(choice2.begin(), choice2.end(), choice2.begin(), ::tolower); // Converts continue to lowercase
		if (choice2 != "yes" || choice2 != "y") {
			continueProgram = false;
		}
	}				// End of while loop
	return 0;
}					// End of main function
