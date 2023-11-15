#!/bin/bash

# Define the folder containing PNG files

destination="$PWD"
png_folder="screenshots"

# Specify the output Markdown file
markdown_file="screenshots.md"

# Change to the PNG folder
cd "$png_folder" || exit

# Create or overwrite the Markdown file
echo -e "# PNG Files\n" > "$markdown_file"

count=1
for file in *.png; do
    # Add the file name to the Markdown file
    echo -e "$count. $file\n" >> "$markdown_file"
    
    # Add the screenshots/image tag to the Markdown file
    echo -e "![Screenshot $count](screenshots/$file)\n" >> "$markdown_file"
    
    # Increment the counter
    ((count++))
done

# Move the Markdown file to the destination folder
mv "$markdown_file" "$destination"

echo "Markdown file generated: $markdown_file"
