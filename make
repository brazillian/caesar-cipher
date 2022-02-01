#!/bin/bash

mkdir ./bin/ -p
gcc ./src/cipher.c -o ./bin/cipher

current_directory=$(pwd)

if [ $# -eq 1 ]
then
    echo "export PATH=$current_directory/bin:$PATH" >> ~/.$1rc

else 
    echo "please give a shell name"
fi

