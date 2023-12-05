#!/bin/bash
echo "Enter the number of rows for pascal's triangle"
read rows
factorial() {
if [ $1 -le 1 ]; then
echo 1
else
echo $(($1 * $(factorial $(($1-1)))))
fi
}
binomial_coefficient() {
local n=$1
local r=$2
local numerator=$(factorial $n)
local denominator=$(($(factorial $r)*$(factorial $(($n-$r)))))
echo $((numerator / denominator ))
}
for ((i=0;i< rows; i++)); do
for ((j=0; j <= rows- i; j++)); do 
echo -n " "
done
for ((j=0; j<=i; j++)); do
coefficient=$(binomial_coefficient $i $j)
echo -n "$coefficient "
done
echo
done

