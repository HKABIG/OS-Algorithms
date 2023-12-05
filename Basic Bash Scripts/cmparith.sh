#!/bin/bash
read -p "Enter two number to perform arithmetic operation: " num1 num2 
mul=(`expr $num1 \* $num2`)
div=(`expr $num1 / $num2`)
add=(`expr $num1 + $num2`)
sub=(`expr $num1 - $num2`)

touch arith.txt 

echo "The multiplication is $mul" >> arith.txt
echo "The divisiton is $div" >> arith.txt
echo "The addition is $add" >> arith.txt
echo "The subtraction is $sub" >> arith.txt

echo "The file is saved successfully" 
while read -r char; do 
	echo $char 
done < arith.txt 

