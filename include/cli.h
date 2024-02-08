//  opencxx_cli
//  cli.h
//  Copyright 2024 - hurbIndustries
//  JPD

#ifndef cli_h
#define cli_h

#include <functional>
#include <string>
#include <vector>

namespace opencxx_cli {
    class CLI {
        public: 
        // Debug, This will enable with --opencxx-cli-debug and 
        // allow for library specific output.
        bool debug = false;

        // Struct used for versioning, Not strictly necessary, just to give
        // the option.
        struct programInfo {
            std::string version;
            std::string name;
            std::string author;
        };
        // entryData should *always* be added using addEntry().
        struct entryData {
            std::string lhand;
            std::string shand;
            int(*func)();
        };

        // Basic commands.
        int help(std::vector<entryData> entries);
        int ver(struct programInfo info);

        // addEntry will reference the struct above, Used to add into a vector that
        // is provided from the application.
        int addEntry(std::string lhand, std::string shand, int (*func)(), std::vector<CLI::entryData> *entries);
        
        // Useful function to quickly make an argument vector, this can be run
        // inline.
        std::vector<std::string> vectorize(int argc, char *argv[]);
        int parse(std::vector<entryData> entries, std::vector<std::string> args);

        // CLI output messages.
        int error(std::string s);
        int warn(std::string s);
        int info(std::string s);
    };
}

#endif
