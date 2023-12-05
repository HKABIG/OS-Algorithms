#!/bin/bash

substr=$1
read str 

num=$(grep -o $1 <<< $str | wc -l )

echo "Thr occurence of $substr in $str is $num"
