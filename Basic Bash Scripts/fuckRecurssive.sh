factorial(){
    local num=$1
    if [ $num -le 1 ]; then 
        echo 1 
    else 
        echo $((  num * $(factorial $((num - 1)))  ))    
    fi
}

read -p "Ente the number: " num 
result=$(factorial $num)
echo "The factorial is $result"
