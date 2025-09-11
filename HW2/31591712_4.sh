#!/bin/bash

# Function to calculate age from birthdate
calculate_age() {
    birthdate=$1
    birth_year=$(echo "$birthdate" | cut -d'-' -f1)
    current_year=2024
    echo $((current_year - birth_year))
}

# Check if a file argument is provided
if [ -z "$1" ]; then
    echo "Please provide an input file."
    exit 1
fi

# Read file line by line
while IFS=',' read -r name dob city country; do
    name=$(echo "$name" | xargs)
    dob=$(echo "$dob" | xargs)
    city=$(echo "$city" | xargs)

    # Check if city contains two or more words
    if [[ "$city" =~ [A-Za-z]+[[:space:]][A-Za-z]+ ]]; then
        # Calculate age
        age=$(calculate_age "$dob")
        echo "$age $name"
    fi
done < "$1" | sort -nr | awk '{print $2, $3, $1}'

