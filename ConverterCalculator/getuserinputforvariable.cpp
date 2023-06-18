#include "getuserinputforvariable.h"
#include "clearInputBuffer.h"

#include <iostream>

void getUserInputForVariable(const char* variableName, double& variable)
{
	std::cout << "Enter your " << variableName << ": ";
	while (!(std::cin >> variable) || variable <= 0) { // Check if input is a number and is greater than 0
		clearInputBuffer();
		std::cout << "Invalid " << variableName << " input. Enter a number: ";
	}
}
