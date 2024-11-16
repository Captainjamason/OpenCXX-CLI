#!/usr/bin/env bash

##  opencxx_cli
##  install.sh
##  Copyright 2024 - hurbIndustries
##  JPD


meson setup build
cd build
meson compile 
cd ..
mkdir -pv ./out/include
cp -v ./build/src/libbopencxx-cli.so ./out/
cp -v ./include/*.h ./out/include
cp -v ./build/meson-private/opencxx-cli.pc ./out
nix-build