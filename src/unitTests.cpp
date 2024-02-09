//  opencxx_cli
//  unitTests.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include <vector>
#include "../include/cli.h"

// Some basic initialization...
using namespace opencxx_cli;
std::vector<CLI::entryData> entries;

int testFunc() {
    return 0;
}

int main(int argc, char* argv[]) {
    CLI cli;
    std::string test = argv[1];

    // test output messages...
    if(test == "-err") {

        if(cli.warn("testwarn") != 0) {
            std::cout << "cli.warn() failed!\n";
            return 1;
        }
    }
    if(test == "-info") {
        if(cli.info("testinfo") != 0) {
            std::cout << "cli.info() failed!\n";
            return 1;
        } else {
            return 0;
        }
    }

    if(test == "-addEntryOnce") {
        cli.addEntry("--test", "-t", testFunc, &entries);
        entries[0].func();
    }

    //test add entry
    if(test == "-addEntryTwice") {
        cli.addEntry("--test", "-t", testFunc, &entries);
        cli.addEntry("-test2", "-t2", testFunc, &entries);
        entries[0].func();
        entries[1].func();
    }

    if(test == "-testParse") {
        cli.addEntry("--test", "-t", testFunc, &entries);
        cli.addEntry("--t2", "-t2", testFunc, &entries);
        cli.parse(entries, cli.vectorize(argc, argv));
    }

    // test help()
    if(test == "-help") {
        if(cli.help(entries) != 0) {
            std::cout << "err: help() failed!\n";
            return 1;
        }
    }
}