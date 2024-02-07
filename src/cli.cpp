//  opencxx_cli
//  cli.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include <string>
#include "../include/cli.h"

using namespace opencxx_cli;

void CLI::addEntry(std::string lhand, std::string shand, std::function<int ()> func) {
    CLI::entry entry;
    entry.lhand = lhand;
    entry.shand = shand;
    entry.func = func;
    CLI::entries.push_back(entry);
}

void CLI::help(CLI::handler handler) {
    std::string string = handler.name + "\n";
    std::cout << string;
}
