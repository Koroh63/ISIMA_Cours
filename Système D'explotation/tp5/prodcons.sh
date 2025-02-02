#!/bin/bash

if [ "$#" -gt 2 ]; then
    echo "Too many args"
    exit 1
fi

if [ "$#" -lt 1 ]; then
    n_prod=4
    n_cons=8
fi
if [ "$#" -eq 1 ]; then
    n_prod=1
    n_cons=$1
fi

if [ "$#" -eq 2 ]; then
    n_prod=$1
    n_cons=$2
fi



test -p prodcons.pipe \
    || mkfifo prodcons.pipe \
    || exit 


for i in $(seq "$n_prod")
do
    bash producteur.sh 2>&1 > prodcons.pipe | awk '{print "[Producteur] " $0}' &
done 

for i in $(seq "$n_cons")
do
    bash consommateur.sh < prodcons.pipe 2>&1 | awk '{print "[Consommateur] " $0}' & 
done 


wait 
