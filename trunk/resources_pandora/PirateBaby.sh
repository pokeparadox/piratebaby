#!/bin/bash
#Copy default config
if [ ! -d "./config" ]; then
# Control will enter here if $DIRECTORY doesn't exist
mkdir ./config
cp ./settings.ini ./config/settings.ini 
fi
if [ ! -d "./strings" ]; then
# Control will enter here if $DIRECTORY doesn't exist
mkdir ./strings
cp ./en_GB.lng ./strings/en_GB.lng 
fi
#Set PenjinTwo and run PirateBaby
export LD_LIBRARY_PATH=./PenjinTwo
./PirateBaby.pxf

