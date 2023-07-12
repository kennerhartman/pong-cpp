#!/bin/zsh
echo

# check if 'pong.app' exists and "$2" != "debug".  If both true, remove 'pong.app' so a new one can take its place
if [ ! "$2" = "debug" ] && [ -d "${PWD}/$1/pong.app" ] 
then
    echo "pong.app already exists.  Overwritting..."
    rm -r "${PWD}/$1/pong.app"
    echo
fi

# check if 'debug_pong.app' exists and "$2" == "debug".  If both true, remove 'debug_pong.app' so a new one can take its place
if [ "$2" = "debug" ] && [ -d "${PWD}/$1/debug_pong.app" ] 
then
    echo "debug_pong.app already exists.  Overwritting..."
    rm -r "${PWD}/$1/debug_pong.app"
    echo
fi

# create all files and directories needed in the app bundle

echo "Creating necessary folders for the app bundle..."

if [ ! "$2" = "debug" ]
then
    appname="pongapp"
    mkdir -p ${PWD}/$1/$appname/
    mkdir -p ${PWD}/$1/$appname/Contents/
    mkdir -p ${PWD}/$1/$appname/Contents/MacOS/
    mkdir -p ${PWD}/$1/$appname/Contents/Resources/
fi

if [ "$2" = "debug" ]
then
    appname="pongdebugapp"
    mkdir -p ${PWD}/$1/$appname/
    mkdir -p ${PWD}/$1/$appname/Contents/
    mkdir -p ${PWD}/$1/$appname/Contents/MacOS/
    mkdir -p ${PWD}/$1/$appname/Contents/Resources/
fi

echo

# copy certain files from project to app bundle

if [ -f "${PWD}/resources/assets/pong.icns" ]
then
    echo "Copying 'pong.icns' from 'resources/assets' to '$appname/Contents/Resources'"
    cp ${PWD}/resources/assets/pong.icns ${PWD}/$1/$appname/Contents/Resources/
fi

if [ ! "$2" = "debug" ]
then
    echo "Copying 'pong' executable from $1 to '$appname/Contents/MacOS'"
    cp ${PWD}/$1/pong ${PWD}/$1/$appname/Contents/MacOS/
fi

if [ "$2" = "debug" ]
then
    echo "Copying 'debug_pong' executable from $1 to '$appname/Contents/MacOS'"
    cp ${PWD}/$1/debug_pong ${PWD}/$1/$appname/Contents/MacOS/
fi

# writing to Info.plist in app bundle

echo

if [ ! "$2" = "debug" ]
then
    echo "Writing 'pong' to CFBundleExecutable in ''$1/$appname/Contents/Info.plist''"
    defaults write ${PWD}/$1/$appname/Contents/Info CFBundleExecutable "pong" 
fi

if [ "$2" = "debug" ]
then
    echo "Writing 'debug_pong' to CFBundleExecutable in ''$1/$appname/Contents/Info.plist''"
    defaults write ${PWD}/$1/$appname/Contents/Info CFBundleExecutable "debug_pong" 
fi

echo "Writing 'pong.icns' to CFBundleIconFile in '$1/$appname/Contents/Info.plist'"
defaults write ${PWD}/$1/$appname/Contents/Info CFBundleIconFile "pong.icns"

echo "Writing 'pong' to CFBundleIconName in '$1/$appname/Contents/Info.plist'"
defaults write ${PWD}/$1/$appname/Contents/Info CFBundleIconName "pong"

echo "Writing 'pong' to CFBundleName in '$1/$appname/Contents/Info.plist'"
defaults write ${PWD}/$1/$appname/Contents/Info CFBundleName "pong"

echo "Writing 'APPL' to CFBundlePackageType in '$1/$appname/Contents/Info.plist'"
defaults write ${PWD}/$1/$appname/Contents/Info CFBundlePackageType "APPL"

echo "Writing 'MacOSX' to CFBundlePackageType in '$1/$appname/Contents/Info.plist'"
defaults write ${PWD}/$1/$appname/Contents/Info CFBundleSupportedPlatforms -array '("MacOSX")'

echo

# "create" app bundle byb renaming directory to {directory_name}.app

if [ ! "$2" = "debug" ]
then
    echo "Bundling app..."
    mv ${PWD}/$1/$appname ${PWD}/$1/pong.app
fi

if [ "$2" = "debug" ]
then
    echo "Bundling app..."
    mv ${PWD}/$1/$appname ${PWD}/$1/debug_pong.app
fi

echo "Complete!"