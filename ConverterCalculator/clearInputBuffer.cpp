#include "clearInputBuffer.h"
#include <iostream>
#include <limits>

void clearInputBuffer()
{
    std::cin.clear();                                               // Clears error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
}
