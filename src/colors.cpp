//  opencxx_cli
//  colors.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include "../include/colors.h"

using namespace opencxx_cli;

// The class colors could likely be expanded for the end user,
// but it is not a high priority.


// Easy function to set a color, Can be used inline since it does *not* have 
// any newlines.
void colors::setColor(colorCode color) {
    std::string string = "\033[";
    std::string colorString = std::to_string(color);
    string.append(colorString);
    string.append("m");
    std::cout << string;
}

// Resets the terminal, Handy...
void colors::reset() {
    colors::setColor(fgDefault);
}

// Quick and dirty function to easily output one line in one color.
void colors::printLnColor(std::string s, colorCode color) {
    colors::setColor(color);
    std::cout << s << "\n";
    colors::setColor(fgDefault);
}
