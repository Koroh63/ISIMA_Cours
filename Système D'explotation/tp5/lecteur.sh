#!/usr/bin/bash
sleep $((1 + $RANDOM % 5))
echo "R$BASHPID begin reading"
sed -n -e '1p' -e '2i...' -e '$p' "${1:--}"
echo "R$BASHPID end reading"
