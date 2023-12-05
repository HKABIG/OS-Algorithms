#!/bin/bash
echo "Enter a number to check if it is a prime number"
read num
if [ $num -lt 2 ] 
then
	echo "The $num is not a prime number"
fi

for (( i=2;i*i<=num;i++ )); do 
	if [ $((num%i)) -eq 0 ]; then
		echo "The $num is not a prime"
		exit
	fi
done
echo "The $num is a prime"

