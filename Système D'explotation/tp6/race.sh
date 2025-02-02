#!/bin/sh

read line 

$line # Q1

kill -18 $(pgrep -P $PID)
kill -19 $(pgrep -P $PID)

wait -n # Q2

kill $PID $(pgrep -P $PID) # Q3