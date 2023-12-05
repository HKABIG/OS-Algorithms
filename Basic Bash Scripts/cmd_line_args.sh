#!/bin/bash
num=$1
sum=0
while [ $num -gt 0 ]; do
	n=$(expr $num % 10 ) 
	sum=$(expr $sum + $n )
	num=$(expr $num / 10 ) 
done
echo "The sum of digits is $sum"

