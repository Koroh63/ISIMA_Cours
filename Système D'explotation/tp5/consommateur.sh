#!/usr/bin/bash

while read task
do
	delay="$(( $RANDOM % 4 )).$RANDOM"
	echo "[C$BASHPID] traite la tâche $task ($delay secondes)."
	sleep $delay
	echo "[C$BASHPID] a fini de traiter la tâche $task."
done
echo "[C$BASHPID] a fini son travail (plus de tâches à traiter)."

