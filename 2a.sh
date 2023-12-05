echo "2 nos"
read n1
read n2

echo "operator : [+,-,*,/] : "
read op

case $op in 
+) 
r=$(echo "$n1+$n2" |bc)
	echo "res= $r"
	;;
-)
r=$(echo "$n1-$n2" |bc)
        echo "res= $r"
        ;;
\*)
r=$(echo "$n1*$n2" |bc)
        echo "res= $r"
        ;;
/)
if (($(bc<<<"$n2==0")));then
        echo "error 0"
else 
	r=$(echo "scale=2; $n1/$n2" |bc)
	echo "res= $r"
        fi
	;;
*)
echo "invalid operator"
	;;
esac
