#!/bin/sh

if [ "$#" -gt 1 ]; then
    echo "Too many args"
    exit 1
fi

if [ "$#" -lt 1 ]; then
    echo "Too few args"
    exit 1
fi

tmpFile1=$(mktemp)
tmpFile2=$(mktemp)

head -n 1 $1 > $tmpFile1
tail -n +2 $1 > $tmpFile2
echo "E$BASHPID begin writing"
$((1 + $RANDOM % 4))
cat $tmpFile2 > $1

$((1 + $RANDOM % ))
cat $tmpFile1 >> $1
echo "E$BASHPID end writing"