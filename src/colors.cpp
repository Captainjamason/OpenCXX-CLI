//  opencxx_cli
//  colors.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include "../include/colors.h"

using namespace opencxx_cli;

void colors::setColor(colorCode color) {
    std::string string = "\033[";
    std::string colorString = std::to_string(color);
    string.append(colorString);
    string.append("m");
    std::cout << string;
}

void colors::reset() {
    colors::setColor(fgDefault);
}

void colors::printLnColor(std::string s, colorCode color) {
    colors::setColor(color);
    std::cout << s << "\n";
    colors::setColor(fgDefault);
}
