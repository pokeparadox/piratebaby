#!/bin/bash
mkdir ./out
mkdir ./out/Caanoo
cp -r ./resources/fonts/ ./out/Caanoo
cp -r ./resources/images/ ./out/Caanoo
cp -r ./resources/strings/ ./out/Caanoo
cp ./resources/icon.png ./out/Caanoo/PirateBaby.png
cp ./bin/Caanoo/PirateBaby_R.gpe ./out/Caanoo/PirateBaby
cp ./resources_caanoo/PirateBaby.gpe ./out/Caanoo
mkdir ./out/Caanoo/config
cp ./resources_caanoo/settings.ini ./out/Caanoo/config
cp ./PirateBaby.readme.txt ./out/Caanoo
mkdir ./out/Caanoo/PenjinTwo
cp ../PenjinTwo/lib/Caanoo/libPenjinTwo.so ./out/Caanoo/PenjinTwo/libPenjinTwo.so
