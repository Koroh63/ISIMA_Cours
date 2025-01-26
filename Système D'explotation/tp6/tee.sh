#!/bin/sh

if [ "$1" = "-e" ]; then
    shift
    tee $@ >&2
else
    tee $@
fi

