#!bin/bash/
read a
read b
add=`echo $a + $b | bc`
sub=`expr $a - $b`
mul=`expr $a \* $b`
div=`echo $a / $b | bc`
echo "add:$add"
echo "sum:$sub"
echo "mul:$mul"
echo "div:$div"
