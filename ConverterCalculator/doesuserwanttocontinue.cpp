#include "doesuserwanttocontinue.h"
#include "clearInputBuffer.h"
#include <iostream>
#include <string>
#include <algorithm>

void doesUserWantToContinue(bool& continueProgram)
{
    clearInputBuffer();                                             // Clears input buffer
    std::string choice2 = "";
    std::cout << "\nDo you want to continue? (yes/no) or (y/n): ";
    std::getline(std::cin, choice2);                                // User input for choice2
    std::transform(choice2.begin(), choice2.end(), choice2.begin(), ::tolower);
    if (choice2 != "yes" && choice2 != "y") {                        // If choice2 is not "yes" or "y"
        continueProgram = false;
    }
}
