#!/bin/bash

read -p "Enter the file path" file_path 
file_type=$(file -b $file_path)
echo "The type of file is $file_type"

if [ -b $file_path ]; then 
	echo  "Block Device"
elif [ -f $file_path ]; then
	echo "Regular"
elif [ -c $file_path ]; then
	echo "Character"
else
	echo "Not supported"
fi

permissions=$(stat -c "%A" $file_path)
echo "Permissions $permissions"
