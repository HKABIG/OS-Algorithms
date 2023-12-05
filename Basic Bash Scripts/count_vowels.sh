#!/bin/bash
fileName=$1
vowel_count=$(grep -io "[aeiou]" $fileName | wc -l)
echo "The vowel count is $vowel_count"
