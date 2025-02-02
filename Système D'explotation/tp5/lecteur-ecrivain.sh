#!/bin/sh

if [ "$#" -gt 3 ]; then
    echo "Too many args"
    exit 1
fi

if [ "$#" -lt 3 ]; then
    echo "Too few args"
    exit 1
fi

n_writ=$1
n_read=$2

for i in $(seq "$n_writ")
do
    bash ecrivain.sh $3 2>&1 | awk '{print "[Ecrivain] " $0}' &
done

for i in $(seq "$n_read")
do
    bash lecteur.sh $3 2>&1 | awk '{print "[Lecteur] " $0}' &
done

wait