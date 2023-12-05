#!/bin/bash

echo "enter the string 1"
read str1
echo "enter the string 2"
read str2
if [ "$str1" == "$str2" ];then
	echo "equal"
elif [ "$str1" \< "$str2" ];then
	echo "1 is less" 
else 
	echo "2 is less"
fi
