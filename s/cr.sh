#!/bin/bash

# Loop through each provided filename
for file in "$@"; do
    # Check if the file exists and is a regular file
    if [ -f "$file" ]; then
	    _cp $file
	    _run ${file%.*}
    else
        echo "$file is not a valid file."
    fi
done
