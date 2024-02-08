//  opencxx_cli
//  cli.cpp
//  Copyright 2024 - hurbIndustries
//  JPD


// Hopefully this section is fairly self explanatory...
#include <iostream>
#include <string>
#include <vector>
#include "../include/cli.h"
#include "../include/colors.h"

using namespace opencxx_cli;
using namespace std;

// Initialize the main 3 debug/error message commands, 
// along with some nice formatting from the color library.
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

// addEntry() will push a new entryData struct (cli.h) into an entries
// vector, which is established application side and a vector is provided.
void CLI::addEntry(string lhand, string shand, int(*func)(), vector<CLI::entryData> *entries) {
    CLI::entryData entry;
    entry.lhand = lhand;
    entry.shand = shand;
    entry.func = func;
    entries -> push_back(entry);
}

// Basic version command, This may not ever be called but is available for
// implementation client side.
void CLI::ver(struct programInfo info) {
    string output;
    output.append("[" + info.name + "]\n");
    output.append(info.version + "\n");
    output.append(info.author + "\n");
    cout << output;
}

// Vectorize allows for a quick function to take argc and argv[] and return
// a vector of arguments... which is mainly used for parse().
vector<string> CLI::vectorize(int argc, char *argv[]) {
    vector<string> args;
    // note: i = 1 due to 0 being the name of the executable itself. 
    for(int i = 1 ; i < argc; i++) {
        args.push_back(argv[i]);
    }
    return args;
}

// TO-DO: Help command, This is hard coded into the library and will
// always be available in the program. This will need to iterate over
// a vector of the entries.
void CLI::help(vector<CLI::entryData> entries) {
    cout << "[opencxx-cli] Help is under construction...\n";
    exit(1);
}

// Here's the big one, This will iterate and parse arguments, along with calling the
// application side function...
void CLI::parse(vector<CLI::entryData> entries, vector<string> args) {
    // if no args then stop, no need to be wasting time.
    if(args.size() == 0) {
        error("No arguments provided... Please use --help");
        exit(1);
    }
    // Iterate over args provided...
    for(int i = 0; i < args.size(); i++) {
        // Hardcoded debugging command. Useful for developers...
        if(args[i] == "--opencxx-cli-debug") {
            debug = true;
            info("OpenCXX-CLI is in debug mode. Arguments will be outputted to terminal...");
        }
        if(debug == true) {
            cout << "[ARGUMENT]=" << i << ": " << args[i] << "\n";
        }

        // Check to see if its the help command (long or short), 
        // Otherwise continue iterating
        if(args[i] == "--help" || args[i] == "-h") {
            help(entries);
        } else {
            for(int j = 0; j < entries.size(); j++) {
                if(args[i] == entries[j].shand) {
                    entries[j].func();
                } else if (args[i] == entries[j].lhand) {
                    entries[j].func();
                } 
                // This specific clause is needed for the debug to work
                // without interrupting the program flow.
                else if (args[i] != "--opencxx-cli-debug") {
                    error("Invalid arguments... Please use --help");
                    exit(1);
                }  
            }
        }
       
    }
} 