#include <iostream>
#include <algorithm>    // for std::transform
#include <cmath>		// for std::isnan
#include <string> 
#include <cstdlib>	

#include "clearInputBuffer.h"
#include "WeightConverter.h"
#include "DistanceConverter.h"
#include "HeightConverter.h"
#include "BMICalculator.h"
#include "SpeedCalculator.h"
#include "displaymenu.h"

int main() {

	bool continueProgram = true; // Flag to control the loop
	while (continueProgram) {

		std::system("cls");									// Clears the screen

		displayMenu();										// Prints the menu

		int choice;										// local variable for choice
		std::cout << "Enter your choice: "; 				// User input for choice
		while (!(std::cin >> choice) || choice < 1 || choice > 5) {
			clearInputBuffer();
			std::cout << "\nInvalid input. Enter a number between 1 and 5:";
		}

		clearInputBuffer();									// Clear input buffer

		std::string unitSystem;								// local variable for unitSystem
		switch (choice) {
		case 1: //Convert Weight >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* weightConverter = new WeightConverter();    // New instance of WeightConverter class
			bool shouldContinue = true;
			while (shouldContinue)
			{
				// User input for unit system
				std::cout << "Choose your preferred unit system (imperial or metric / i or m): ";
				std::cin >> unitSystem;

				// User input validation for case-insensitivity and for i or m input
				std::transform(unitSystem.begin(), unitSystem.end(), unitSystem.begin(), ::tolower);

				if (unitSystem == "imperial" || unitSystem == "metric" || unitSystem == "i" || unitSystem == "m") {

					weightConverter->description(); // Prints "Weight Converter: Converts between pounds and kilograms."

					double weight;                          // local variable for weight

					std::cout << "\nEnter your weight (lb/kg): ";
					while (!(std::cin >> weight) || weight < 0) {
						clearInputBuffer();
						std::cout << "\nInvalid input. Enter a number:";
					}

					double convertedWeight = 0;                     // local variable for converted weight

					if (unitSystem == "imperial" || unitSystem == "i") {
						convertedWeight = weightConverter->toMetric(weight); // Converts weight to metric
						std::cout << "Weight (metric): " << convertedWeight << " kg" << std::endl;
					}
					else if (unitSystem == "metric" || unitSystem == "m") {
						convertedWeight = weightConverter->toImperial(weight); // Converts weight to imperial
						std::cout << "Weight (imperial): " << convertedWeight << " lb" << std::endl;
					}
					shouldContinue = false;
				}
				else {
					std::cout << "Invalid unit system. Try agian." << std::endl;
					clearInputBuffer();
				}
			}										// End of while loop for weight conversion
			delete weightConverter;                 // Deletes weightConverter instance
			break;
		}
		case 2: // Convert Distance >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* distanceConverter = new DistanceConverter();    // New instance of DistanceConverter class

			bool shouldContinue = true;
			while (shouldContinue) {
				// User input for unit system
				std::cout << "Choose your preferred unit system (imperial or metric / i or m): ";
				std::cin >> unitSystem;

				// User input validation for case-insensitivity and for i or m input
				std::transform(unitSystem.begin(), unitSystem.end(), unitSystem.begin(), ::tolower);

				if (unitSystem == "imperial" || unitSystem == "metric" || unitSystem == "i" || unitSystem == "m") {

					distanceConverter->description(); // Prints "Distance Converter: Converts between feet and meters."

					// User input for distance
					double distance;                          // local variable for distance

					std::cout << "\nEnter a distance: ";
					std::cin >> distance;                             // User input for distance
					while (!(std::cin >> distance) || distance < 0) {
						clearInputBuffer();
						std::cout << "\nInvalid input. Enter a number:";
					}

					double convertedDistance = 0;                      // local variable for converted distance

					if (unitSystem == "imperial" || unitSystem == "i") {
						convertedDistance = distanceConverter->toMetric(distance); // Converts distance to metric
						std::cout << "Distance (metric): " << convertedDistance << " meters" << std::endl;
					}
					else if (unitSystem == "metric" || unitSystem == "m") {
						convertedDistance = distanceConverter->toImperial(distance); // Converts distance to imperial
						std::cout << "Distance (imperial): " << convertedDistance << " feet" << std::endl;
					}
					shouldContinue = false;
				}
				else {
					std::cout << "Invalid unit system. Try again." << std::endl;
				}
			}
			delete distanceConverter;                         // Deletes distanceConverter instance
			break;
		}
		case 3: // BMI Calculator >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			Converter* weightConverter = new WeightConverter();    // New instance of WeightConverter class
			Converter* heightConverter = new HeightConverter();    // New instance of HeightConverter class 
			Calculator* bmiCalculator = new BMICalculator();		// New instance of BMICalculator class

			bool shouldContinue = true;
			while (shouldContinue) {
				// User input for unit system
				std::cout << "\nChoose your preferred unit system (imperial or metric / i or m): ";
				std::cin >> unitSystem;
				// User input validation for case-insensitivity and for i or m input
				std::transform(unitSystem.begin(), unitSystem.end(), unitSystem.begin(), ::tolower);

				if (unitSystem == "imperial" || unitSystem == "i" || unitSystem == "metric" || unitSystem == "m") {

					weightConverter->description(); // Prints "Weight Converter: Converts between pounds and kilograms."
					heightConverter->description(); // Prints "Height Converter: Converts between inches and meters."

					// User input for weight and height 
					double weight, height;                          // local variables for weight and height

					std::cout << "\nEnter your weight (lb/kg): ";
					while (!(std::cin >> weight) || weight < 0) {
						clearInputBuffer();
						std::cout << "\nInvalid input. Enter a number:";
					}

					std::cout << "Enter your height (feet/meters): ";
					while (!(std::cin >> height) || height < 0) {
						clearInputBuffer();
						std::cout << "\nInvalid input. Enter a number:";
					}

					double bmiResult = 0;							 // local variable for bmiResult

					if (unitSystem == "imperial" || unitSystem == "i") {

						double metricWeight = weightConverter->toMetric(weight); // Converts weight to metric
						double metricHeight = heightConverter->toMetric(height); // Converts height to metric

						bmiCalculator->description();	// Prints "BMI Calculator: Calculates ,..."
						bmiResult = bmiCalculator->calculate(metricWeight, metricHeight);///calculate BMI

						delete weightConverter;						// Deletes weightConverter instance
						delete heightConverter;						// Deletes heightConverter instance
					}
					else if (unitSystem == "metric" || unitSystem == "m") {

						bmiCalculator->description();				// Prints "BMI Calculator:..."
						bmiResult = bmiCalculator->calculate(weight, height);///calculate BMI
					}

					std::cout << "BMI: ";
					bmiCalculator->printResult(bmiResult, unitSystem, true);		// Prints "Result: <bmiResult>"

					shouldContinue = false;
					delete bmiCalculator;						// Deletes bmiCalculator instance
				}
				else {
					std::cout << "Invalid unit system. Try again" << std::endl;
				}
			}
			break;											// Breaks out of case 3
		}

		case 4: // Speed Calculator >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			// User input for speed calculation
			Calculator* speedCalculator = new SpeedCalculator();	// New instance of SpeedCalculator class
			Converter* distanceConverter = new DistanceConverter(); //instance of DistanceConverter class

			// User input for unit system
			std::cout << "\nChoose your preferred unit system (imperial or metric / i or m): ";
			std::cin >> unitSystem;

			// User input validation for case-insensitivity and for i or m input
			std::transform(unitSystem.begin(), unitSystem.end(), unitSystem.begin(), ::tolower);

			bool shouldContinue = true;
			while (shouldContinue) {

				if (unitSystem == "imperial" || unitSystem == "i" || unitSystem == "metric" || unitSystem == "m") {

					speedCalculator->description();			    // Prints "Speed Calculator: Calculates speed."
					distanceConverter->description();           // Prints distance converter description

					double distance;                            // local variable for distance
					std::cout << "\nEnter a distance: ";
					while (!(std::cin >> distance) || distance < 0) {			// User input for distance
						clearInputBuffer();
						std::cout << "Invalid input. Enter a number: ";
					}

					double time;								// local variable for time
					std::cout << "Enter a time in seconds: ";
					while (!(std::cin >> time) || time < 0) {				// User input for time
						clearInputBuffer();
						std::cout << "Invalid input. Enter a number: ";
					}

					if (unitSystem == "imperial" || unitSystem == "i") {

						double metricDistance = distanceConverter->toMetric(distance); // Converts distance to metric

						double speedResult = speedCalculator->calculate(metricDistance, time); // Calculates speed in m/s
						std::string speedInterpretation = static_cast<SpeedCalculator*>(speedCalculator)->interpretResult(speedResult);

						double imperialSpeed = distanceConverter->toImperial(speedResult);		// Converts speed to imperial

						std::cout << "\nSpeed: ";
						speedCalculator->printResult(imperialSpeed, unitSystem);				// Prints "Result: <speedResult>"
						std::cout << "Interpretation: " << speedInterpretation << std::endl;	// Prints <speedInterpretation>"

						std::cout << "Speed (metric units): " << speedResult << " m/s (" << speedResult * 3.6 << " km/hr)" << std::endl;
					}
					else if (unitSystem == "metric" || unitSystem == "m") {

						double speedResult = speedCalculator->calculate(distance, time); // Calculates speed in m/s
						std::string speedInterpretation = static_cast<SpeedCalculator*>(speedCalculator)->interpretResult(speedResult);

						std::cout << "\nSpeed: ";
						speedCalculator->printResult(speedResult, unitSystem);					// Prints "Result: <speedResult>"
						std::cout << "Interpretation: " << speedInterpretation << std::endl;

						double imperialSpeed = distanceConverter->toImperial(speedResult);		// Converts speed to imperial
						std::cout << "Speed (imperial units): " << imperialSpeed << "ft/s (" << imperialSpeed * 15 / 22 << " mph)" << std::endl;
					}
					shouldContinue = false;
					delete distanceConverter;					// Deletes distanceConverter instance
					delete speedCalculator;						// Deletes speedCalculator instance
				}
				else {
					std::cout << "Invalid unit system." << std::endl;
				}
			}
			break;
		}
		case 5: // Exit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			return 0;
		}
		default: // Invalid input >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		{
			std::cout << "\nInvalid input. Choose again." << std::endl;
		}
		}
		// Ask the user if they want to continue or quit
		clearInputBuffer();
		std::string choice2 = "";
		std::cout << "\nDo you want to continue? (yes/no) or (y/n): ";
		std::getline(std::cin, choice2);
		if (choice2 != "yes" && choice2 != "y") {
			continueProgram = false;
		}
	}
	return 0;
}
