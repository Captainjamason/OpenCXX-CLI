#!/usr/bin/env bash

meson setup build
cd build
meson compile 
sudo cp src/libopencxx-cli.so /usr/local/lib
sudo mkdir /usr/local/include/opencxx-cli
cd ..
sudo cp ./include/*.h /usr/local/include/opencxx-cli/
sudo cp ./build/meson-private/opencxx-cli.pc /usr/local/libdata/pkgconfig