#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <nombre_de_producteurs> <nombre_de_consommateurs>"
    exit 1
fi

n_prod=$1
n_cons=$2

test -p prodcons.pipe \
    || mkfifo prodcons.pipe \
    || exit 
TUBE="tube"

for i in $(seq "$n_prod")
do
    bash producteur.sh 2>&1 > prodcons.pipe | awk '{print "[Producteur] " $0}' &
done 

for i in $(seq "$n_cons")
do
    bash consommateur.sh < prodcons.pipe 2>&1 | awk '{print "[Consommateur] " $0}' & 
done 


wait 
