#!/bin/bash
sudo apt-get install libglib2.0-0
wget https://github.com/google/gumbo-parser/archive/v0.10.1.tar.gz
tar -xvf v0.10.1.tar.gz
ls
cd ./gumbo-parser-0.10.1
./autogen.sh
./configure
make
sudo make install
cd ..
