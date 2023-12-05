echo "fibo no:"
read n

a=0
b=1

if [ $n -eq 0 ]; then
	echo "no term"
elif [ $n -eq 1 ]; then 
	echo "fibo series"
	echo "$a"
else 
	echo "fibo series"
	echo "$a"
	echo "$b"

for (( i=2; i<n; i++)); do 
	next=$((a+b))
	echo "$next"
	a=$b
	b=$next
done
fi

