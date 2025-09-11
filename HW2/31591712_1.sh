#!/bin/bash

# Part A: Count words with at least three 'a's 
ResultofA=$(grep -Eic '(.*[aA].*){3,}' dictionary.txt)
echo $ResultofA

# Part B: Count words with exactly three 'e's, where each 'e' is separated by at least one non-'e' character
ResultofE=$(grep -Eic '^[^eE]*[eE][^eE]+[eE][^eE]+[eE][^eE]*$' dictionary.txt)
echo $ResultofE

# Part C: Find the three most common last three letters of words containing adjacent 'e's
grep -Ei 'ee' dictionary.txt | sed -E 's/^.*(.{3})$/\1/' | sort | uniq -c | sort -nr | head -3
