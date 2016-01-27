#!/bin/bash
gyp hello-gyp.gyp --depth=. -f make --generator-output=build/makefiles
make -C build/makefiles
ln -f -s build/makefiles/out/Default/hello-gyp hello-gyp-make
gyp hello-gyp.gyp --depth=. -f ninja --generator-output=build/ninja
ninja -C build/ninja/out/Default/
ln -f -s build/ninja/out/Default/hello-gyp hello-gyp-ninja
