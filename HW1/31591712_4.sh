#!/bin/bash

# Function to display file contents in chunks of 10 lines
display_file() {
    local filename=$1
    local start_line=1
    local lines_per_page=10
    local total_lines=$(wc -l < "$filename")
    
    while [ $start_line -le $total_lines ]; do
        head -n $((start_line + lines_per_page - 1)) "$filename" | tail -n $lines_per_page
        if [ $((start_line + lines_per_page - 1)) -ge $total_lines ]; then
            break
        fi
        read -p "Do you want to display more lines? (yes/no): " user_choice
        if [ "$user_choice" != "yes" ]; then
            break
        fi
        start_line=$((start_line + lines_per_page))
    done
}

# Function to handle file selection
handle_file_selection() {
    display_file "$1"
}

# Function to search for files modified in the last 24 hours
search_recent_files() {
    for file_item in *; do
        if [ -f "$file_item" ]; then
            mod_time=$(stat -c %Y "$file_item")
            current_time=$(date +%s)
            time_difference=$(( (current_time - mod_time) / 86400 ))
            if [ "$time_difference" -lt 1 ]; then
                echo "$file_item"
            fi
        fi
    done
}

# Function to handle subdirectory selection
handle_directory_selection() {
    cd "$1" || exit
    echo "Searching for files modified in the last 24 hours..."
    recent_files=$(search_recent_files)
    if [ -z "$recent_files" ]; then
        echo "No files modified in the last 24 hours."
    else
        echo "Files modified in the last 24 hours:"
        echo "$recent_files"
        read -p "Enter the name of the file to display: " selected_file
        if [ -f "$selected_file" ]; then
            display_file "$selected_file"
        else
            echo "Invalid file selection."
        fi
    fi
    cd ..
}

# Main loop to prompt user for directory selection
while true; do
    read -p "Enter a directory name: " directory_name
    if [ ! -d "$directory_name" ]; then
        read -p "Directory does not exist. Do you want to create it? (yes/no): " create_dir
        if [ "$create_dir" == "yes" ]; then
            mkdir "$directory_name"
        else
            continue
        fi
    fi

    cd "$directory_name" || exit
    while true; do
        echo "Contents of directory:"
        ls -1  
        read -p "Enter the name of a file or subdirectory (or type 'exit' to quit): " user_selection

        if [ "$user_selection" == "exit" ]; then
            echo "Exiting..."
            exit
        elif [ -d "$user_selection" ]; then
            handle_directory_selection "$user_selection"
        elif [ -f "$user_selection" ]; then
            handle_file_selection "$user_selection"
        else
            echo "Invalid selection. Please try again."
        fi
    done
    cd ..
done
