#!/bin/bash

number=$1

template_file="src/euler_template.cpp"
target_file="src/problems/euler$number.cpp"

if [ -f "$target_file" ]; then
  echo "Error: File already exists: $target_file"
  exit 1
fi

cp "$template_file" "$target_file"
awk -v num="$number" -v desc="$description" '{gsub("{NUMBER}", num); gsub("{DESCRIPTION}", desc); print}' "$template_file" > "$target_file"

echo "Created Euler problem file: $target_file"
