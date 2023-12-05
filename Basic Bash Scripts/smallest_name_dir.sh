#!/bin/bash

file_list=$(ls )
sort $file_list
smallest_file=${file_list[0]}
for file in $file_list[@]; do 
	if [ ${#smallest_file} -lt ${#file} ]; then
		smallest_file=$file
	fi
done

echo "The smallest file is $smallest_file"
