#1 way bin 2 p

#!/bin/bash

pipe_file="my_pipe"
mkfifo $pipe_file

producer_process() {
	for i in {1..10}; do
		echo "P send data $i to Pipe"
		echo "$i">$pipe_file
	sleep 1
	done 
	echo "P finished sending data"
	exit 0
	}

consumer_process() {
while true; do
if read -r line < $pipe_file; then
	echo "C received data: $line"
	fi
done
}

producer_process &
consumer_process &
wait 
run $pipe_file
