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
        bool debug = true;
        struct programInfo {
            std::string version;
            std::string name;
            std::string author;
        };

        struct entryData {
            std::string lhand;
            std::string shand;
            int(*func)();
        };

        // Basic commands that *always* will work
        void help(std::vector<entryData> entries);
        void ver(struct programInfo info);

        // Add your own entry and handler
        void addEntry(std::string lhand, std::string shand, int (*func)(), std::vector<CLI::entryData> *entries);

        std::vector<std::string> vectorize(int argc, char *argv[]);
        void parse(std::vector<entryData> entries, std::vector<std::string> args);

        void error(std::string s);
        void warn(std::string s);
        void info(std::string s);
    };
}

#endif
