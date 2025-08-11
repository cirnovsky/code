#!/bin/bash

# Loop through each provided filename
if [ -f "$1" ]; then
    # Run _cp and only run _run if _cp succeeds
    _cp "$1"
    if [ "$?" -eq 0 ]; then
        _run "${1%.*}"
    else
        echo "Compilation failed. Skipping run."
    fi
else
    echo "$1 is not a valid file."
fi

