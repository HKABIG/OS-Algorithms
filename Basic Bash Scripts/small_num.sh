read num 
ans=1000000007
while [ $num -gt 0 ]; do 
    digit=(`expr $num % 10`)
    echo $digit
    if [ $digit -le $ans ]; then 
        ans=$digit
    fi
    num=(`expr $num / 10`)
done
echo "The smallest digit is $ans from number"
