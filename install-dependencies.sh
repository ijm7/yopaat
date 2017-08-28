#!/bin/bash
wget https://github.com/google/gumbo-parser/archive/v0.10.1.tar.gz -O /tmp/gumbo-parser.tar.gz
tar -xvf /tmp/gumbo-parser.tar.gz
cd /tmp/gumbo-parser-0.10.1
./autogen.sh
./configure
make
sudo make install
