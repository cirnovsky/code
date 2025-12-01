#!/bin/bash

# Stop on first error
set -e

echo "Compiling programs..."

# Compile the solver with the -DLOCAL flag
# This enables your local testing code (the cnm array and simulated ask)
g++ -std=c++17 -o solve_local m.cpp -O2 -I .

# Compile the verifier
g++ -std=c++17 -o verify int.cpp -O2 -I .

# Compile the generator
g++ -std=c++17 -o gen g.cpp -O2

echo "Compilation successful. Starting duipai..."

# Run the duipai loop
i=1
while true; do
    ((i++))
    echo -n "Test Case $i: "
    
    # 1. Generate test case
    ./gen > test.in
    
    # 2. Run the local solver
    # We use `cut` to extract the answer after the "!"
    # This correctly handles both "! 0" and "0" (for the q=0 case)
    ./solve_local < test.in | cut -d ' ' -f 2- > solve.out
    
    # 3. Run the verifier (brute force)
    ./verify < test.in > correct.out
    
    # 4. Compare outputs
    if diff -w solve.out correct.out > /dev/null; then
        echo "Accepted"
    else
        echo "Wrong Answer!"
        echo "--- Failing Input (test.in) ---"
        cat test.in
        echo "--- Your Solver's Output (solve.out) ---"
        cat solve.out
        echo "--- Correct Output (correct.out) ---"
        cat correct.out
        
        # Keep the failing test case for debugging
        cp test.in wa_test.in
        echo "Failing test case saved to wa_test.in"
        break
    fi
done

echo "Duipai finished."
