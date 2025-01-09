#!/usr/bin/bash

n_tasks=$(( $RANDOM % 8 ))

echo "[P$BASHPID] doit produire $n_tasks tâches." >&2
for i in $(seq 0 $n_tasks)
do
	task=$RANDOM
	delay="$(( $RANDOM % 4 )).$(( $RANDOM ))"
	sleep $delay
	echo $task
	echo "[P$BASHPID] a produit $task." >&2
done
echo "[P$BASHPID] a fini son travail." >&2

