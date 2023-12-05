#!/bin/bash
echo "Enter 1st string"
read str1
echo "Enter 2nd string"
read str2
if [ $str1 = $str2 ]
then
	echo "strings are same"
else
	echo "Strings are not same"
fi

if [[ $str1 > $str2 ]] 
then
	echo "string1 is max"
else
	echo "string2 is max"
fi

echo "Enter a pattern"
read pat
echo "Enter filename"
read fname
grep $pat $fname
if [ -z pat] 
then
	echo "String entered is empty"
	exit l
fi

if [ $? -eq 0 ]
then 
	echo "pat is found"
else
	echo "pat is not found"
fi

#!/bin/bash

echo -n "Enter a string: "
read input

length=${#input}
is_palindrome=true

for ((i=0; i<length/2; i++)); do
    first_char="${input:i:1}"
    last_char="${input:length-i-1:1}"

    if [ "$first_char" != "$last_char" ]; then
        is_palindrome=false
        break
    fi
done

if [ "$is_palindrome" = true ]; then
    echo "The string is a palindrome."
else
    echo "The string is not a palindrome."
fi
