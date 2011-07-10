#!/bin/bash
mkdir ./out
mkdir ./out/W32
cp -r ./resources/fonts/ ./out/W32
cp -r ./resources/images/ ./out/W32
cp -r ./resources/strings/ ./out/W32
cp ./resources/icon.png ./out/W32
cp ./bin/W32/PirateBaby_R ./out/W32/PirateBaby.exe
mkdir ./out/W32/config
cp ./resources/config/settings.ini ./out/W32/config
cp ./PirateBaby.readme.txt ./out/W32
mkdir ./out/W32/PenjinTwo
cp ../PenjinTwo/lib/W32/libPenjinTwo.dll ./out/W32/libPenjinTwo.dll
