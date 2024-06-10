#!/bin/bash

if [ -z "$1" ]; then
  read -p "Enter Euler problem number: " number
else
  number=$1
fi

template_file="src/euler_template.cpp"
target_file="src/problems/euler$number.cpp"

if [ -f "$target_file" ]; then
  echo "Error: File already exists: $target_file"
  exit 1
fi

cp "$template_file" "$target_file"
awk -v num="$number" '{gsub("{NUMBER}", num); print}' "$template_file" > "$target_file"

echo "Created Euler problem file: $target_file"
code $target_file
