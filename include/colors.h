//  opencxx_cli
//  colors.h 
//  Copyright 2024 - hurbIndustries
//  JPD

#ifndef colors_h
#define colors_h

#include <string>

namespace opencxx_cli {
    class CLI {
        public:
        enum colors {
            fgRed = 31,
            fgGreen = 32,
            fgYellow = 33,
            fgBlue = 34,
            fgDefault = 39
        };
        void setColor(colors color);
        void printLnColor(std::string s, colors color);
        void reset();
    };
}

#endif