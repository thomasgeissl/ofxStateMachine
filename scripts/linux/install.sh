#!/bin/sh
OFVERSION=0.11.0
GHUSER=thomasgeissl
GHREPO=ofxStateMachine

curl -O https://openframeworks.cc/versions/v${OFVERSION}/of_v${OFVERSION}_linux64gcc6_release.tar.gz
tar -zxf of_v${OFVERSION}_linux64gcc6_release.tar.gz
rm of_v${OFVERSION}_linux64gcc6_release.tar.gz
sudo of_v${OFVERSION}_linux64gcc6_release/scripts/linux/ubuntu/install_dependencies.sh -y
of_v${OFVERSION}_linux64gcc6_release/addons

git clone https://github.com/${GHUSER}/${GHREPO}.git
cd $GHREPO

for d in example*/ ; do
    echo "$d"
    cd $d
    make
    cd ..
done
