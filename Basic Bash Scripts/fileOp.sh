#!/bin/bash

create_file(){
	read -p "Enter the name of the file " file_name
	touch $file_name
	echo "File $file_name created successfully"
}

insert_data(){
	read -p "Enter the id " id
	read -p "Enter the name " name
	read -p "Enter the Grade " grade 

	echo "$id $name $grade" >> $file_name

	echo "record entered successfully"
	echo $(cat $file_name)
}

deleteEntry(){
	read id
	grep -v $id $file_name > temp_file 
	mv temp_file $file_name
	echo "Record Deleted successfully"
	echo $(cat $file_name)
}

deleteFile(){
	rm -f $file_name
	echo "File Deleted Successfully"
}

charby(){
	while read -r -n 1 char; do 
		echo $char 
	done < $file_name
	echo "Successful"
}

lineby(){
	while read -r line; do
		echo $line
	done < $file_name
	echo "Sucessful2"
}

numline(){
	echo $(cat -n $file_name)
}

echo "File operations in Shell Scripting"
echo "Creating a database file"
create_file
echo "Inserting data into the file"
insert_data 
echo "Deleting an entry"
deleteEntry
#echo "Deleting the file"
#deleteFile
echo "Read Char by Char"
charby
echo "Read Line by Line"
lineby
echo "Line by Line with numbering"
numline
