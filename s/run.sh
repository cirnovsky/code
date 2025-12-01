# #!/bin/bash
# 
# # Check for at least one parameter
# if [ "$#" -lt 1 ]; then
#     echo "Usage: $0 <executable> [input_file] [output_file]"
#     exit 1
# fi
# 
# executable="${1%.*}"
# 
# # Check if the executable exists and is executable
# if [ ! -x "$executable" ]; then
#     echo "$executable is not a valid executable."
#     exit 1
# fi
# 
# echo "Running $executable..."
# 
# # Run based on number of arguments
# case "$#" in
#     1)
#         gtime -f "\nTime: %Es\nMemory: %MkB" ./"$executable"
#         ;;
#     2)
#         gtime -f "\nTime: %Es\nMemory: %MkB" ./"$executable" < "$2"
#         ;;
#     3)
#         gtime -f "\nTime: %Es\nMemory: %MkB" ./"$executable" < "$2" > "$3"
#         ;;
#     *)
#         echo "Too many arguments. Usage: $0 <executable> [input_file] [output_file]"
#         exit 1
#         ;;
# esac

#!/bin/bash

# Check for at least one parameter
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <executable> [input_file] [output_file]"
    exit 1
fi

# Strip extension to get the executable name (e.g., main.exe -> main)
executable="${1%.*}"

# Check if the executable exists and is executable
if [ ! -x "$executable" ]; then
    echo "Error: '$executable' is not a valid executable."
    exit 1
fi

# --- OS Detection & Time Command Configuration ---

# 1. Check for 'gtime' (Common on macOS with Homebrew)
if command -v gtime &> /dev/null; then
    TIME_CMD=(gtime -f "\nTime: %Es\nMemory: %MkB")

# 2. Check for Linux (Standard /usr/bin/time is usually GNU time)
elif [[ "$(uname)" == "Linux" ]]; then
    # We use full path to avoid the bash shell builtin 'time'
    TIME_CMD=(/usr/bin/time -f "\nTime: %Es\nMemory: %MkB")

# 3. Fallback for standard macOS (BSD time)
else
    # BSD time doesn't support -f. We use -l to show resource usage.
    echo "Note: GNU time not found. Using standard BSD time (output format differs)."
    TIME_CMD=(/usr/bin/time -l)
fi

echo "Running $executable..."

# --- Execution ---
# We use "${TIME_CMD[@]}" to correctly handle spaces in the format string

case "$#" in
    1)
        "${TIME_CMD[@]}" ./"$executable"
        ;;
    2)
        "${TIME_CMD[@]}" ./"$executable" < "$2"
        ;;
    3)
        "${TIME_CMD[@]}" ./"$executable" < "$2" > "$3"
        ;;
    *)
        echo "Too many arguments. Usage: $0 <executable> [input_file] [output_file]"
        exit 1
        ;;
esac
