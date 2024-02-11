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

// Namespace declarations here, May rid of in the future.
using namespace opencxx_cli;
using namespace std;

// Global argument return string. I wish this was handled a bit better but for now its good.
string argReturn;

// Initialize the main 3 debug/error message commands, 
// along with some nice formatting from the color library.
int CLI::error(string s) {
    colors color;
    color.setColor(color.fgRed);
    cout << "[ERROR] ";
    color.reset();
    cout << s << "\n";
    return 0;
}
int CLI::warn(string s) {
    colors color;
    color.setColor(color.fgYellow);
    cout << "[WARN] ";
    color.reset();
    cout << s << "\n";
    return 0;
}
int CLI::info(string s) {
    colors color;
    color.setColor(color.fgBlue);
    cout << "[INFO] ";
    color.reset();
    cout << s << "\n";
    return 0;
}

// Small helper function to set the argReturn varaible.
int addArg(string arg) {
    argReturn = arg;
    return 1;
}

// returnArg() *must* be called from a user function if `arg = true`, This will be beneficial for
// any sort of functions that require parameters.
string CLI::returnArg() {
    return argReturn;
}

// addEntry() will push a new entryData struct (cli.h) into an entries
// vector, which is established application side and a vector is provided.
int CLI::addEntry(string lhand, string shand, int(*func)(), vector<CLI::entryData> *entries, bool arg, std::string desc) {
    CLI::entryData entry;
    entry.lhand = lhand;
    entry.shand = shand;
    entry.func = func;
    entry.desc = desc;
    entry.arg = arg;
    entries -> push_back(entry);
    if(CLI::debug == true) {
        cout << entry.shand << "\n";
    }
    return 0;
}

// Basic version command, This may not ever be called but is available for
// implementation client side.
int CLI::ver(struct programInfo info) {
    string output;
    output.append("[" + info.name + "]\n");
    output.append(info.version + "\n");
    output.append(info.author + "\n");
    cout << output;
    return 0;
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

// help() is bound to `--help` by default. May be customizable in the future.
int CLI::help(vector<CLI::entryData> entries) {
    //cout << "[opencxx-cli] Help is under construction...\n";
    CLI::programInfo pgInfo;
    if(pgInfo.name != "") {
        std::cout << "["+pgInfo.name+"]";
    }
    for(int i = 0; i < entries.size(); i++) {
        std::cout << entries[i].lhand << " || " << entries[i].shand << ": " << entries[i].desc << "\n";
    }
    return 0;
}

// Here's the big one, This will iterate and parse arguments, along with calling the
// application side function...
int CLI::parse(vector<CLI::entryData> entries, vector<string> args) {
    // if no args then stop, no need to be wasting time.
    if(args.size() == 0 && debug != true) {
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
            return 0;
        } else {
            for(int j = 0; j < entries.size(); j++) {
                if(CLI::debug == true) {
                    cout << entries[j].lhand << "\n";
                }
                if(args[i] == entries[j].shand) {
                   if(entries[j].arg) {
                        if(args[i+1] != "") {
                            addArg(args[i+1]);
                        } else {
                            error("Please provide an argument...");
                            return 1;
                        }
                    }
                    entries[j].func();
                    return(0);
                } else if (args[i] == entries[j].lhand) {
                    if(entries[j].arg) {
                        if(args[i+1] != "") {
                            addArg(args[i+1]);
                        } else {
                            error("Please provide an argument...");
                            return 1;
                        }
                    }
                    entries[j].func();
                    return 0;
                }
                else if (args[i] != "--opencxx-cli-debug" && j == args.size()) {
                    error("Invalid arguments... Please use --help");
                    exit(1);
                }  
            }
        }
    }
} 