#!/bin/bash

# Check if at least one filename is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <executable1> [executable2 ...]"
    exit 1
fi

# Loop through each provided filename
for executable in "$@"; do
    # Check if the file exists and is executable
    if [ -x "$executable" ]; then
        echo "Running $executable..."
			/usr/bin/time -f "\nTime: %Es\nMemory: %MkB" ./"$executable"  # Run the executable and measure time/memory
    else
        echo "$executable is not a valid executable."
    fi
done
