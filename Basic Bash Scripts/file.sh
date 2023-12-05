#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

file=$1

if [ -e "$file" ]; then
  if [ -f "$file" ]; then
    echo "File type: Regular File"
  elif [ -d "$file" ]; then
    echo "File type: Directory"
  else
    echo "File type: Other"
  fi

  permissions=$(ls -l "$file" | cut -d " " -f 1)
  echo "Permissions: $permissions"
else
  echo "File not found: $file"
fi
