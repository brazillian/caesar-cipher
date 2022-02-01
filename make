#!/bin/bash

mkdir ./bin/
gcc ./src/cipher.c -o ./bin/cipher
echo "export PATH=\"./bin\":$PATH" >> ~/.$1rc
source ~/.$1rc
