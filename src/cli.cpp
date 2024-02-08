//  opencxx_cli
//  cli.cpp
//  Copyright 2024 - hurbIndustries
//  JPD

#include <iostream>
#include <string>
#include <vector>
#include "../include/cli.h"
#include "../include/colors.h"

using namespace opencxx_cli;
using namespace std;

void CLI::error(string s) {
    colors color;
    color.setColor(color.fgRed);
    cout << "[ERROR] ";
    color.reset();
    cout << s << "\n";
}

void CLI::warn(string s) {
    colors color;
    color.setColor(color.fgYellow);
    cout << "[WARN] ";
    color.reset();
    cout << s << "\n";
}

 void CLI::info(string s) {
    colors color;
    color.setColor(color.fgBlue);
    cout << "[INFO] ";
    color.reset();
    cout << s << "\n";
 }

void CLI::addEntry(string lhand, string shand, int(*func)(), vector<CLI::entryData> *entries) {
    CLI::entryData entry;
    entry.lhand = lhand;
    entry.shand = shand;
    entry.func = func;
    entries -> push_back(entry);
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

void CLI::help(vector<CLI::entryData> entries) {
    cout << "[opencxx-cli] Help is under construction...\n";
    exit(1);
}

void CLI::parse(vector<CLI::entryData> entries, vector<string> args) {
    if(args.size() == 0) {
        error("No arguments provided... Please use --help");
        exit(1);
    }
    for(int i = 0; i < args.size(); i++) {
        cout << "[ARGUMENT]=" << i << ": " << args[i] << "\n";
        if(args[i] == "--help" || args[i] == "-h") {
            help(entries);
        } else {
            for(int j = 0; j < entries.size(); j++) {
                if(args[i] == entries[j].shand) {
                    entries[j].func();
                } else if (args[i] == entries[j].lhand) {
                    entries[j].func();
                } else {
                    error("Invalid arguments provided... Please use --help");
                    exit(1);
                }
            }
        }
       
    }
} 