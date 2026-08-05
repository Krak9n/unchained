#!/bin/sh

# ensure dependenice: glfw3, glad, opengl, freetype, cmake

cmake -B build -S .
cmake --build build

./build/unchained
