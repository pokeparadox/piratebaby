#!/bin/bash
mkdir ./out
mkdir ./out/Wiz
cp -r ./resources/fonts/ ./out/Wiz
cp -r ./resources/images/ ./out/Wiz
cp -r ./resources/strings/ ./out/Wiz
cp ./resources/icon.png ./out/Wiz/PirateBaby.png
cp ./bin/Wiz/PirateBaby_R.gpe ./out/Wiz/PirateBaby
cp ./resources_wiz/PirateBaby.gpe ./out/Wiz
mkdir ./out/Wiz/config
cp ./resources_caanoo/settings.ini ./out/Wiz/config
cp ./PirateBaby.readme.txt ./out/Wiz
mkdir ./out/Wiz/PenjinTwo
cp ../PenjinTwo/lib/Wiz/libPenjinTwo.so ./out/Wiz/PenjinTwo/libPenjinTwo.so
