#!/usr/bin/bash

cat "$@" | {
    while IFS='\n' read line
    do 
        num="$(echo "$line" | cut -d: -f1)"
        line="$(echo "$line" | cut -d: -f2)"
        if [ "$num" = "1" ]; then
            echo "$line"
        elif [ "$line" = "2" ]; then
            echo "$line" >2
        fi
    done
}