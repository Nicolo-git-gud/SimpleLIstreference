#!/bin/bash

g++ -fsanitize=undefined,address,leak -O0 -g -o "$1" "$1.cpp"       SimpleListr.cpp
