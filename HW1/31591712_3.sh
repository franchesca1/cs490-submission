#!/bin/bash

if [ "$#" -lt 3 ]; then
    echo "Warning Error: You must provide at least three filenames."
    exit 1
fi

date_stamp=$(date +"%Y%m%d")
backup_folder="backup_$date_stamp"

mkdir -p "$backup_folder"
echo "Backup directory created: $backup_folder"

log_path="$backup_folder/backup_log.txt"
touch "$log_path"

for item in "$@"; do
    if [ ! -f "$item" ]; then
        echo "Warning: File '$item' does not exist. Skipping..."
        echo "Warning: File '$item' does not exist. Skipping..." >> "$log_path"
        continue
    fi

    cp "$item" "$backup_folder/"
    orig_filename=$(basename "$item")
    new_file_name="${orig_filename}_${date_stamp}"
    mv "$backup_folder/$orig_filename" "$backup_folder/$new_file_name"

    echo "Original: $orig_filename, Backup: $new_file_name" >> "$log_path"
done

echo "Backup process completed. Backup files are in '$backup_folder'."
echo "Log file created: $log_path"
