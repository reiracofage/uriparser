#!/bin/bash

make BASE
if (( $? != 0 )); then
    exit 1
fi
t=0
while [ -e in$t ]; do
    echo "Teste $t..."
    ./BASE < in$t | diff - out$t -y
    (( t++ ))
done
