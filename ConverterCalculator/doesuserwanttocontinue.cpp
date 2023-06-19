#include "doesuserwanttocontinue.h"
#include "clearInputBuffer.h"
#include <iostream>
#include <string>
#include <algorithm>

void doesUserWantToContinue(bool& continueProgram)
{
    std::string choice2;
    std::cout << "\nDo you want to continue? (yes/no) or (y/n): ";
    // Validate inputs against numerical values and inputs that are not yes/y or No/n
    while (!(std::cin >> choice2) || (choice2 != "yes" && choice2 != "y" && choice2 != "no" && choice2 != "n")) {
        std::cout << "Invalid input. Enter (yes/no) or (y/n):";
        clearInputBuffer();
    }
    if (choice2 == "no" || choice2 == "n" ) {
        continueProgram = false; // Exit the while loop
    }
}
