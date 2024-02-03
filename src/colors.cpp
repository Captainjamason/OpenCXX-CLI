//  opencxx_cli
//  colors.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include "../include/colors.h"

using namespace opencxx_cli;

void CLI::setColor(colors color) {
    std::string string = "\033[";
    std::string colorS = std::to_string(color);
    string.append(colorS);
    string.append("m");
    std::cout << string;
}

void CLI::reset() {
    CLI::setColor(fgDefault);
}

void CLI::printLnColor(std::string s, colors color) {
    CLI::setColor(color);
    std::cout << s << "\n";
    CLI::setColor(fgDefault);
}