#!/bin/sh

if [ "$#" -eq 2 ];then
    while read line 
        do 
            echo "$1"$line"$2"
        done

elif [ "$#" ]

else
    echo "Wrong args"
    exit 1
fi