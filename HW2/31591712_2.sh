#!/bin/bash

# Check if a file argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <C file>"
    exit 1
fi

C_file="$1"

# Check if the file exists
if [ ! -f "$C_file" ]; then
    echo "Error: File '$C_FILE' not found."
    exit 1
fi

# Count the total number of lines in the file
TotalCount=$(wc -l < "$C_file")

# Count and extract lines containing "scanf"
ScanfCount=$(grep -n "scanf" "$C_file" | tee -a scanf_log.txt | wc -l)

# Count and extract lines containing "printf"
PrintfCount=$(grep -n "printf" "$C_file" | tee -a printf_log.txt | wc -l)

# Calculate percentages
ScanfPercentage=$(echo "scale=2; ($ScanfCount/$TotalCount)*100" | bc)
PrintfPercentage=$(echo "scale=2; ($PrintfCount/$TotalCount)*100" | bc)

# Display results
echo "Total lines in '$C_file': $TotalCount"
echo "Lines containing 'scanf': $ScanfCount ($ScanfPercentage%)"
echo "Lines containing 'printf': $PrintfCount ($PrintfPercentage%)"

