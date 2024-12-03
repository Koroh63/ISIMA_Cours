#!/usr/bin/bash

test $# -ne 2 \
	&& echo "Erreur: deux arguments attendus; $# ont été donnés." >&2 \
	&& exit 1
for file in "$1" "$2"
do
	! test -f "$file" -a -r "$file" \
		&& echo "Erreur: le fichier '$file' n'existe pas ou n'est pas lisible." >&2 \
		&& exit 1
done

{
	read -u3 ligne1 && flag1=true || flag1=false
	read -u4 ligne2 && flag2=true || flag2=false
	while $flag1 && $flag2
	do
		if [[ $ligne1 < $ligne2 ]]
		then
			printf '%s\n' "$ligne1"
			read -u3 ligne1 || flag1=false
		else
			printf '%s\n' "$ligne2"
			read -u4 ligne2 || flag2=false
		fi
	done
	$flag1 && cat <&3 || cat <&4
} 3<"$1" 4<"$2"

