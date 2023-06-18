#include "getunitsyteminput.h"
#include "clearInputBuffer.h"

#include <iostream>

void getUnitSystemInput(int& unitSystem, int& imperial, int& metric)
{
	// User input for unit system
	std::cout << "Choose your preferred unit system (imperial or metric), (1 or 2): ";
	while (!(std::cin >> unitSystem) || !(unitSystem == imperial || unitSystem == metric)) {
		clearInputBuffer();
		std::cout << "Invalid input. Enter a number, 1 or 2: ";
	}
}