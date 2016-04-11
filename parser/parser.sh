#!/bin/bash

if (( $# != 1 )); then
    echo "$(basename $0) <Problem ID>"
    exit 1
fi

PID=$1

echo "Downloading problem..."

wget -q "https://www.urionlinejudge.com.br/repository/UOJ_${PID}.html" -O .enum

echo "Parsing problem..."

TITLE="$(grep '<h1>' .enum | awk -F'<h1>' '{print $2}' | awk -F'</h1>' '{print $1}')"
base=$(echo $TITLE | sed 'y/áÁàÀãÃâÂéÉêÊíÍóÓõÕôÔúÚçÇ/aAaAaAaAeEeEiIoOoOoOuUcC/' |\
       tr '[:upper:]' '[:lower:]' | cut -d' ' -f1)

echo "Got problem $PID - $TITLE ($base)."
echo "Parsing sample I/O..."
ncases=$(echo $(cat .enum) | ./parser/geraio)
echo "$ncases case(s) found."

rm -f .enum

echo "Building the file structure..."

dir=${base}${PID}
mkdir -p $dir
for i in $(seq 0 $(( $ncases - 1 )) ); do
    mv in$i out$i $dir
done
cp parser/modelo.cpp ${dir}/${base}.cpp
cp parser/Makefile $dir
cp parser/testa.sh ${dir}
sed -i "s/BASE/${base}/g" ${dir}/testa.sh

echo "Done."

cd ${dir}
vim ${base}.cpp
