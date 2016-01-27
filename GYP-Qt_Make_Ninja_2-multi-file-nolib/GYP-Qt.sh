#!/bin/bash
source qt_moc.sh

gyp GYP-Qt.gyp --depth=. -f make --generator-output=build/makefiles
make -C build/makefiles/
ln -s -f build/makefiles/out/Default/NKeyPad NKeyPad-make

gyp GYP-Qt.gyp --depth=. -f ninja --generator-output=build/ninja
ninja -C build/ninja/out/Default/
ln -s -f build/ninja/out/Default/NKeyPad NKeyPad-ninja



