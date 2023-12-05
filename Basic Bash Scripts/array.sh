swap(){
    local temp=${nos[$1]}
    nos[$1]=${nos[$2]}
    nos[$2]=$temp
}


echo "Enter array size"
read n
echo "enter array Elements"
i=0
while [ $i -lt $n ]
do
    read nos[$i]
    i=`expr $i + 1`
done
i=0
mx=0
mn=${nos[0]}
average=0
echo "Your array Elements"
while [ $i -lt $n ]
do
	echo ${nos[$i]}
	if [ ${nos[$i]} -gt $mx ]; then
		mx=${nos[$i]}
	fi
	if [ ${nos[$i]} -lt $mn]; then
		mn=${nos[$i]}
	fi
	average=$(expr $average + ${nos[$i]})
	i=$(expr $i + 1)
done

i=0
for (( i=0;i<n;i++))
do
	for(( j=$i+1;j<n;j++))
	do
		if(( ${nos[$i]} > ${nos[$j]} ))
		then
			swap $j $i
		fi
	done
done

echo "The sorted array is like"
for((i=0;i<n;i++))
do
	echo ${nos[$i]}
done

echo "The max element is $mx"
echo "The min element is $mn"
echo "The avrage is $(expr $average / $n)"
