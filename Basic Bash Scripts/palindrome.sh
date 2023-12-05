#!/bin/bash

echo "The string to be checked"
read str
n=${#str}
mid=$(expr $n / 2)
f=0
for ((i = 0; i < mid; i++))
do
    j=$(expr $n - $i - 1)
    if [ "${str:$i:1}" != "${str:$j:1}" ]; then
	f=1
        break
    fi
done
if [ $f -eq 1 ]
then
	echo "Not a palindrom"
else
	echo "Is a palindrome"
fi

