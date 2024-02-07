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

        struct handler {
            std::string version;
            std::string name;
            std::string author;
        };

        // Basic commands that *always* will work
        void help(handler);
        void ver(handler);

        struct entry {
            std::string lhand;
            std::string shand;
            std::function<int()> func;
        };

        std::vector<entry> entries;

        // Add your own entry and handler
        void addEntry(std::string lhand, std::string shand, std::function<int()> func);
    };
}

#endif
