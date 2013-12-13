#! /bin/bash

# I usually have this kind of script in my project folder so that I don't have to manually write the configure options everytime I add new dependencies to the project
# This one is what I use in my project InputManager:
# https://github.com/posva/InputManager

if [ "`uname -s`" = "Darwin" ]; then
	./configure.sh -aD -s src -o obj -b bin -c "xcrun clang" -O "-Wall -Wextra" -Isrc -L/usr/local/lib -e c -E sh2d -M Makefile -l "-lm"
elif [ "`uname -s`" = "Linux" ]; then
	./configure.sh -aD -s src -o obj -b bin -c "gcc" -O "-Wall -Wextra -std=c99" -Isrc -L/usr/local/lib -e c -E sh2d -M Makefile -l "-lm"
fi
