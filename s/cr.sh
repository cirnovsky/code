#!/bin/bash

# Check if at least one filename is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <file1.cpp> [file2.cpp ...]"
    exit 1
fi

# Read compilation parameters from parameter.txt
if [ -f parameter.txt ]; then
    compilation_params=$(<parameter.txt)
else
    echo "parameter.txt not found. Exiting."
    exit 1
fi

# Loop through each provided filename
for file in "$@"; do
    # Check if the file exists and is a regular file
    if [ -f "$file" ]; then
        # Compile the file using g++
        g++-14 $compilation_params "$file" -o "${file%.*}"  # Remove extension for output filename

        # Check if compilation was successful
        if [ $? -eq 0 ]; then
            echo "Compiled $file successfully. Running..."
            /usr/bin/time -f "\nTime: %Es\nMemory: %MkB" ./"${file%.*}"  # Run the executable and measure time/memory
        else
            echo "Failed to compile $file."
        fi
    else
        echo "$file is not a valid file."
    fi
done
