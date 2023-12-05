#!/bin/bash

#getting current time
current_hour=$(date +"%H")
echo $current_hour
current_year=$(date +"%Y")
echo $current_year
current_date=$(date +"%D")
echo $current_date
echo "Printing greetings based on time"
if (($current_hour < 12 && $current_hour >= 7))
then
        echo "Good Morning"
elif (($current_hour < 17 && $current_hour >= 12))
then
        echo "Good Afternoon"
else
        echo "Good Evening"
fi
