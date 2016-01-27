#!/bin/bash
#####################################################################################
# To be able to use Qt widgets, one needs to use Qt signal-slot mechanism to
# connect the events and callback functions. Accordingly, moc, the meta-object
# compiler is not avoidable. Therefore, one has to use moc to compile the meta-
# object as follows.
# This script is writen following the instruction from:
# http://stackoverflow.com/questions/10919082/building-with-moc-files-using
# -gyp-instead-of-qmake
#####################################################################################
MOC="/home/chuan/Qt/5.5/gcc_64/bin/moc"
SRC_DIR="include"

$MOC $SRC_DIR/numerickeypad.h -o  $SRC_DIR/moc_numerickeypad.cpp

