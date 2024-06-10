#!/bin/bash

# GENERATED USING GPT4o, I can not write bash :,)

# Function to display usage instructions
usage() {
    echo "Usage: $0 <problem_number>"
    exit 1
}

# Check if a problem number was provided
if [ -z "$1" ]; then
    echo "Error: No problem number provided."
    usage
fi

# Check if the provided argument is a number
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Error: Problem number must be a numeric value."
    usage
fi

PROBLEM_NUMBER=$1

# Compile the project
make || { echo "Error: Compilation failed."; exit 1; }

# Run the executable with the specified problem number
./main "$PROBLEM_NUMBER" || { echo "Error: Execution failed."; exit 1; }