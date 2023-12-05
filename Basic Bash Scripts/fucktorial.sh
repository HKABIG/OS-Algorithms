#!/bin/bash

factorial(){
	if [ "$1" -eq 0 -o "$1" -eq 1 ]
	then
		echo 1
	else
		lcoal sres=$(factorial $(($1-1)))
		echo $(($1*sres))
	fi
}

echo "This program represents the fucktorail of a number"
echo "Enter a numbe to get it's fucktorial"
read num
fnum=$num
ans=1
while [ $num -gt 0 ]
do 
	ans=(`expr $ans \* $num`)
	num=(`expr $num - 1`)
done
echo -e "The Fucktorial of a number is $ans \n"

echo "Now The recurssive fucktorial"
resut=$(factorial $fnum)
echo "The fucktorial of number is $result"
