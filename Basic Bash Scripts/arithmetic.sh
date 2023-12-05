#!bin/bash/
read num1
read num2
add = `expr $num1 + $num2`
sub = `expr $num1 - $num2`
mul = `expr $num1 \* $num2`
div = `echo $num1/$num2|bc`
echo "add:$add"
echo "sum:$sub"
echo "mul:$mul"
echo "div:$div"
