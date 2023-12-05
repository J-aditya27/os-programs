#max of 3 no's



#!/bin/bash

echo "enter  3 no's"
read n1
read n2
read n3

max=$n1

if [ $n2 -gt $max ]; then
	max=$n2
fi

if [ $n3 -gt $max ]; then 
	max=$n3
fi

echo "the max no is : $max"
      
