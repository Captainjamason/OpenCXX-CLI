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
    // test output messages...
    if(cli.error("testerr") != 0) {
        std::cout << "cli.error() failed!\n";
        return 1;
    }
    if(cli.warn("testwarn") != 0) {
        std::cout << "cli.warn() failed!\n";
        return 1;
    }
    if(cli.info("testinfo") != 0) {
        std::cout << "cli.info() failed!\n";
        return 1;
    }

    //test add entry
    if(cli.addEntry("--test", "-t", testFunc, &entries)) {
        if(entries[0].func != 0) {
            std::cout << "err: entries not stored successfully...\n";
            return 1;
        }
        // Test mutliple entries!
        if(cli.addEntry("--test", "-t", testFunc, &entries)) {
            if(entries[1].func != 0) {
                std::cout << "err: multiple entries not working...\n";
                return 1;
            }
        }

        // Test parsing...
        if(argv[1] != "") {
            if(cli.parse(entries, cli.vectorize(argc, argv)) != 0) {
                std::cout << "err: parse() failed!\n";
                return 1;
            }
        } else {
            std::cout << "info: no args passed, skipping parse()\n";
        }
    }

    // test help()
    if(cli.help(entries) != 0) {
        std::cout << "err: help() failed!\n";
        return 1;
    }
}