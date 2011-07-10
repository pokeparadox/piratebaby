#!/bin/bash
mkdir ./out
mkdir ./out/GP2X
cp -r ./resources/fonts/ ./out/GP2X
cp -r ./resources/images/ ./out/GP2X
cp -r ./resources/strings/ ./out/GP2X
cp ./resources/icon.png ./out/GP2X
cp ./bin/GP2X/PirateBaby_R.gpe ./out/GP2X/PirateBaby
cp ./resources_gp2x/PirateBaby.gpe ./out/GP2X
mkdir ./out/GP2X/config
cp ./resources_caanoo/settings.ini ./out/GP2X/config
cp ./PirateBaby.readme.txt ./out/GP2X
mkdir ./out/GP2X/PenjinTwo
cp ../PenjinTwo/lib/GP2X/libPenjinTwo.so ./out/GP2X/PenjinTwo/libPenjinTwo.so
