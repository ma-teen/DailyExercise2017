#!/bin/bash -e
# Command to build test code.

echo "Compiling Started  ============================"
echo "Running build command."
exec 'g++ -o test.out -std=c++11 test.cpp'

echo "Compiling Finished ============================"
