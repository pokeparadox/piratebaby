#!/bin/bash
rm ./PirateBaby.pnd
mkdir ./out
cp -r ./resources/fonts/ ./out/
cp -r ./resources/images/ ./out/
cp ./resources/strings/en_GB.lng ./out/
cp ./resources/icon.png ./out/
cp ./resources_pandora/PirateBaby.sh ./out/
cp ./resources_pandora/PXML.xml ./out/
cp -r ./resources_pandora/previews/ ./out/
cp ./resources_pandora/settings.ini ./out/
cp ./PirateBaby.readme.txt ./out/
mkdir ./out/PenjinTwo
cp ../PenjinTwo/lib/Pandora/libPenjinTwo.so ./out/PenjinTwo/libPenjinTwo.so
mksquashfs ./out/fonts ./out/images ./out/en_GB.lng ./out/icon.png ./out/PirateBaby.sh ./bin/Pandora/PirateBaby.pxf ./out/PXML.xml ./out/PirateBaby.readme.txt ./out/previews ./out/PenjinTwo ./out/settings.ini PirateBaby.sfs
cat ./PirateBaby.sfs ./out/PXML.xml ./out/icon.png > PirateBaby.pnd
rm ./PirateBaby.sfs
