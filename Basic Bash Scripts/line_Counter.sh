#!/bin/bash
current_file=$1 

line_counter=0
while read -r line;do
	line_counter=$((line_counter+1))
done < "$current_file"

echo "Total lines in the file are $line_counter"

