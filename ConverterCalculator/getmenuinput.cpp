#include "getmenuinput.h"
#include "clearInputBuffer.h"
#include <iostream>

void getMenuInput(int& choice)
{
    std::cout << "Enter your choice: ";                           // User input for choice
    while (!(std::cin >> choice) || choice < 1 || choice > 5) {
        clearInputBuffer();
        std::cout << "\nInvalid input. Enter a number between 1 and 5:";
    }
}
