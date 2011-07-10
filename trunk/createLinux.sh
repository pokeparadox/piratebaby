#!/bin/bash
mkdir ./out
mkdir ./out/Linux
cp -r ./resources/fonts/ ./out/Linux
cp -r ./resources/images/ ./out/Linux
cp -r ./resources/strings/ ./out/Linux
cp ./resources/icon.png ./out/Linux
cp ./bin/Linux/PirateBaby_R ./out/Linux/PirateBaby
cp ./resources_linux/PirateBaby.sh ./out/Linux
mkdir ./out/Linux/config
cp ./resources/config/settings.ini ./out/Linux/config
cp ./PirateBaby.readme.txt ./out/Linux
mkdir ./out/Linux/PenjinTwo
cp ../PenjinTwo/lib/Linux/libPenjinTwo.so ./out/Linux/PenjinTwo/libPenjinTwo.so
