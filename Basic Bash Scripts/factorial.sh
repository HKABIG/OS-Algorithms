#!/bin/bash

factorial_recursive(){
	    local num=$1
    if [ $num -eq 0 ]; then
        echo 1
    else
        echo $(( num * $(factorial_recursive $((num - 1))) ))

    fi

}


echo "Enter the number to find factorial"
read n
num=$n
fact=1
while [ $n -gt 0 ] 
do
	fact=$(expr $fact \* $n)
	n=$(expr $n - 1 )

done
echo "The factorial without recurssion is $fact"
echo "The factorial with recursion is $(factorial_recursive $num)"
