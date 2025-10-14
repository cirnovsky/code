#!/bin/bash

# Loop through each provided filename
if [ -f "$1" ]; then
    # Run _cp and only run _run if _cp succeeds
    ccp "$1"
    if [ "$?" -eq 0 ]; then
        rrun $@
    else
        echo "Compilation failed. Skipping run."
    fi
else
    echo "$1 is not a valid file."
fi

