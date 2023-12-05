#!/bin/bash
read -p "Enter a number to check if it's a armstrong: " num 

res=0
n=${#num}
onum=$num
for(( i=0;i<n;i++ )); do 
	digit=(`expr $num % 10`)
	num=(`expr $num / 10`)
	up=1
	for((j=0;j<n;j++)); do 
		up=(`expr $up \* $digit`)
	done
	res=(`expr $res + $up`)
done

if [ $res -eq $onum ]; then
	echo "Yes it's a armstrong"
else
	echo "No"
fi
