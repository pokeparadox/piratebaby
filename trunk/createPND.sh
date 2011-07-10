#!/bin/bash
rm ./PirateBaby.pnd
mkdir ./out/Pandora
cp -r ./resources/fonts/ ./out/Pandora
cp -r ./resources/images/ ./out/Pandora
cp ./resources/strings/en_GB.lng ./out/Pandora
cp ./resources/icon.png ./out/Pandora
cp ./resources_pandora/PirateBaby.sh ./out/Pandora
cp ./resources_pandora/PXML.xml ./out/Pandora
cp -r ./resources_pandora/previews/ ./out/Pandora
cp ./resources_pandora/settings.ini ./out/Pandora
cp ./PirateBaby.readme.txt ./out/Pandora
mkdir ./out/Pandora/PenjinTwo
cp ../PenjinTwo/lib/Pandora/libPenjinTwo.so ./out/Pandora/PenjinTwo/libPenjinTwo.so
mksquashfs ./out/Pandora/fonts ./out/Pandora/images ./out/Pandora/en_GB.lng ./out/Pandora/icon.png ./out/Pandora/PirateBaby.sh ./bin/Pandora/PirateBaby.pxf ./out/Pandora/PXML.xml ./out/Pandora/PirateBaby.readme.txt ./out/Pandora/previews ./out/Pandora/PenjinTwo ./out/Pandora/settings.ini PirateBaby.sfs
cat ./PirateBaby.sfs ./out/Pandora/PXML.xml ./out/Pandora/icon.png > PirateBaby.pnd
rm ./PirateBaby.sfs
