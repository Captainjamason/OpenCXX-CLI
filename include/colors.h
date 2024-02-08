//  opencxx_cli
//  colors.h 
//  Copyright 2024 - hurbIndustries
//  JPD

#ifndef colors_h
#define colors_h

#include <string>

namespace opencxx_cli {
    class colors {
        public:
        // Some basic terminal color integers, This is used for
        // setting the color in different functions...
        enum colorCode {
            fgRed = 31,
            fgGreen = 32,
            fgYellow = 33,
            fgBlue = 34,
            fgDefault = 39
        };
        void setColor(colorCode color);
        void printLnColor(std::string s, colorCode color);
        void reset();
    };
}

#endif
