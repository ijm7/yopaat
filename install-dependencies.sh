#!/bin/bash
wget https://github.com/google/gumbo-parser/archive/v0.10.1.tar.gz
tar -xvf v0.10.1.tar.gz
ls
cd ./v0.10.1
./autogen.sh
./configure
make
sudo make install
