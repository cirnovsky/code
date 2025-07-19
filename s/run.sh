#!/bin/bash

# Check for at least one parameter
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <executable> [input_file] [output_file]"
    exit 1
fi

executable="$1"

# Check if the executable exists and is executable
if [ ! -x "$executable" ]; then
    echo "$executable is not a valid executable."
    exit 1
fi

echo "Running $executable..."

# Run based on number of arguments
case "$#" in
    1)
        /usr/bin/time -f "\nTime: %Es\nMemory: %MkB" ./"$executable"
        ;;
    2)
        /usr/bin/time -f "\nTime: %Es\nMemory: %MkB" ./"$executable" < "$2"
        ;;
    3)
        /usr/bin/time -f "\nTime: %Es\nMemory: %MkB" ./"$executable" < "$2" > "$3"
        ;;
    *)
        echo "Too many arguments. Usage: $0 <executable> [input_file] [output_file]"
        exit 1
        ;;
esac
