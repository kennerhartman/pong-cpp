#!/bin/zsh
echo 
if [ -d "${PWD}/$1/pong.app" ] 
then
    echo "pong.app already exists.  Overwritting..."
    rm -r "${PWD}/$1/pong.app"
    echo
fi

echo "Creating necessary folders for the app bundle..."
mkdir -p ${PWD}/$1/pongapp/
mkdir -p ${PWD}/$1/pongapp/Contents/
mkdir -p ${PWD}/$1/pongapp/Contents/MacOS/
mkdir -p ${PWD}/$1/pongapp/Contents/Resources/

echo

if [ -f "${PWD}/resources/assets/pong.icns" ]
then
    echo "Copying 'pong.icns' from 'resources/assets' to 'pongapp/Contents/Resources'"
    cp ${PWD}/resources/assets/pong.icns ${PWD}/$1/pongapp/Contents/Resources/
fi

if [ -f "${PWD}/$1/pong" ]
then
    echo "Copying 'pong' executable from $1 to 'pongapp/Contents/MacOS'"
    cp ${PWD}/$1/pong ${PWD}/$1/pongapp/Contents/MacOS/
fi



echo

echo "Writing 'pong' to CFBundleExecutable in ''$1/pongapp/Contents/Info.plist''"
defaults write ${PWD}/$1/pongapp/Contents/Info CFBundleExecutable "pong"

echo "Writing 'pong.icns' to CFBundleIconFile in '$1/pongapp/Contents/Info.plist'"
defaults write ${PWD}/$1/pongapp/Contents/Info CFBundleIconFile "pong.icns"

echo "Writing 'pong' to CFBundleIconName in '$1/pongapp/Contents/Info.plist'"
defaults write ${PWD}/$1/pongapp/Contents/Info CFBundleIconName "pong"

echo "Writing 'pong' to CFBundleName in '$1/pongapp/Contents/Info.plist'"
defaults write ${PWD}/$1/pongapp/Contents/Info CFBundleName "pong"

echo "Writing 'APPL' to CFBundlePackageType in '$1/pongapp/Contents/Info.plist'"
defaults write ${PWD}/$1/pongapp/Contents/Info CFBundlePackageType "APPL"

echo "Writing 'MacOSX' to CFBundlePackageType in '$1/pongapp/Contents/Info.plist'"
defaults write ${PWD}/$1/pongapp/Contents/Info CFBundleSupportedPlatforms -array '("MacOSX")'

echo

echo "Bundling app..."
mv ${PWD}/$1/pongapp ${PWD}/$1/pong.app

echo "Complete!"