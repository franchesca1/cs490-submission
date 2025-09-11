#!/bin/bash

if [ -z "$1" ]; then
    echo "Enter a file or directory:"
    read user_input
else
    user_input="$1"
fi

file_count=0
directory_count=0

function traverse() {
    local fname="$1"
    if [ ! -d "$fname" ]; then
        return
    fi
    if [ "$(ls -A "$fname" | wc -l)" -eq 0 ]; then
        return
    fi

    entries=("$fname"/*)
    for entry in "${entries[@]}"
    do
        if [ -f "$entry" ]; then
            ((file_count++))
        elif [ -d "$entry" ]; then
            ((directory_count++))
            traverse "$entry"
        fi
    done
}

if [ -d "$user_input" ]; then
    if [[ -r "$user_input" && -x "$user_input" ]]; then
        traverse "$user_input"
        echo "Number of files: $file_count"
        echo "Number of directories: $directory_count"
        echo "Listing contents with sizes:"
        ls -lh "$user_input"
    else
        echo "You do not have permissions."
    fi
elif [ -f "$user_input" ]; then
    if [ -r "$user_input" ]; then
        word_count=$(wc -w < "$user_input")
        line_count=$(wc -l < "$user_input")
        char_count=$(wc -m < "$user_input")
        echo "Word count: $word_count"
        echo "Line count: $line_count"
        echo "Character count: $char_count"
        
        if [ "$char_count" -gt 10000 ]; then
            echo "File is Text Heavy"
        elif [ "$char_count" -ge 1000 ]; then
            echo "File is Moderately Sized"
        else
            echo "File is a Light File"
        fi
    else
        echo "You do not have read permissions on this file."
    fi
else
    echo "Invalid input: Not a file or directory."
fi

