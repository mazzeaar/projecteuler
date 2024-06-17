#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <problem_number>"
    exit 1
fi

# Format the problem number to be three digits long with leading zeros
PPPROBLEM_NUMBER=$(printf "%03d" $1)
PROBLEM_NUMBER=$1
TEMPLATE_FILE="../src/problems/problem_template.txt"
PROBLEM_FILE="../src/problems/problem_${PPPROBLEM_NUMBER}.cpp"

if [ -f "$PROBLEM_FILE" ]; then
    echo "Problem file $PROBLEM_FILE already exists!"
    exit 1
fi

sed "s/{NUMBER}/${PROBLEM_NUMBER}/g" $TEMPLATE_FILE > $PROBLEM_FILE
echo "Created $PROBLEM_FILE"
