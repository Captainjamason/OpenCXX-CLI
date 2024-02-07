//  opencxx_cli
//  cli.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include <string>
#include <vector>
#include "../include/cli.h"

using namespace opencxx_cli;
using namespace std;

void CLI::addEntry(string lhand, string shand, int(*func)(), vector<CLI::entryData> entries) {
    CLI::entryData entry;
    entry.lhand = lhand;
    entry.shand = shand;
    entry.func = func;
    entries.push_back(entry);
}

void CLI::ver(struct programInfo info) {
    string output;
    output.append("[" + info.name + "]\n");
    output.append(info.version + "\n");
    output.append(info.author + "\n");
    cout << output;
}

vector<string> CLI::vectorize(int argc, char *argv[]) {
    vector<string> args;
    // note: i = 1 due to 0 being the name of the executable itself. 
    for(int i = 1 ; i < argc; i++) {
        args.push_back(argv[i]);
    }
    return args;
}

void CLI::parse(vector<CLI::entryData> entries, vector<string> args) {
    for(int i = 0; i < args.size(); i++) {
        cout << "[ARGUMENT]=" << i << ": " << args[i] << "\n";
        if(args[i] == entries[i].lhand) {
            entries[i].func();
        }
    }
} 