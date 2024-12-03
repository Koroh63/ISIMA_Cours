#!/usr/bin/bash
cat "$@" | {
	let i=0
	while IFS='\n' read line
	do
		printf '%i:%s\n' $i "$line"
		let i++
	done
}