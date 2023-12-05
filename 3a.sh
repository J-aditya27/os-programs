
#factorial


#!/bin/bash

echo "enter no"
read n

factorial=1
if [ $n -lt 0 ]; then
	echo "not defined"
elif [ $n -eq 0 ]; then
	echo "1"
else
	for (( i=1; i<=n; i++)); do
		factorial=$((factorial*i))
	done
	echo "fact of $n is $factorial"
fi
