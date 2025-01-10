#!/bin/bash

# Check if at least one filename is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <file1.cpp> [file2.cpp ...]"
    exit 1
fi

# Read compilation parameters from parameter.txt
if [ -f param ]; then
    compilation_params=$(<param)
else
    echo "./param not found. Exiting."
    exit 1
fi

# Loop through each provided filename
for file in "$@"; do
    # Check if the file exists and is a regular file
    if [ -f "$file" ]; then
        # Compile the file using g++/gcc

	if [[ $file == *.c ]]; then
		cc="gcc"
	else
		cc="g++-14"
	fi
	cmd="$cc ${file} -o ${file%.*} ${compilation_params}"
	echo -e "\e[1;32;41mCommand\e[0m \e[3;35m$cmd\e[0m"
	eval $cmd

        # Check if compilation was successful
        if [ $? -eq 0 ]; then
            echo "Compiled $file successfully."
        else
            echo "Failed to compile $file."
        fi
    else
        echo "$file is not a valid file."
    fi
done
