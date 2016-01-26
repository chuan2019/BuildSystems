#!/bin/bash
gyp gyp00.gyp --depth=. -f make --generator-output=./build/makefiles && make -C ./build/makefiles/
gyp gyp00.gyp --depth=. -f ninja --generator-output=./build/ninja && ninja -C build/ninja/out/Default/
ln -f -s build/makefiles/out/Default/gyp00 gyp00-make
ln -f -s build/ninja/out/Default/gyp00 gyp00-ninja
