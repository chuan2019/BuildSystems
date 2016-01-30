#!/bin/bash
gyp png_viewer.gyp -f ninja --depth=. --generator-output=build/ninja
ninja -C build/ninja/out/Default/
ln -s -f build/ninja/out/Default/png_viewer pngViewer

