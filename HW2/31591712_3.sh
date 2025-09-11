#!/bin/bash

# Check if a directory argument is passed
if [ -z "$1" ]; then
  echo "Usage: $0 <directory>"
  exit 1
fi

# Assign the directory to a variable
target_directory="$1"

# Check if the given argument is a valid directory
if [ ! -d "$target_directory" ]; then
  echo "Error: '$target_directory' is not a valid directory."
  exit 1
fi

# Initialize an empty file to store unique emails
email_output_file="unique_email_addresses.txt"
> "$email_output_file"

# Recursive function to process each text file
process_files_in_directory() {
  local current_directory="$1"

  # Loop through each item in the directory
  for item in "$current_directory"/*; do
    if [ -d "$item" ]; then
      # If the item is a directory, recurse into it
      process_files_in_directory "$item"
    elif [ -f "$item" ] && [[ "$item" == *.txt ]]; then
      # If it's a text file, process it
      grep -oP '[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}' "$item" >> "$email_output_file"
    fi
  done
}

# Call the function to start processing
process_files_in_directory "$target_directory"

# Remove duplicate emails and sort them
sort -u "$email_output_file" -o "$email_output_file"

echo "Unique email addresses have been saved to '$email_output_file'."

