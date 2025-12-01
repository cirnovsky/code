#!/bin/bash

# Define a dedicated directory for these symlinks
# Using a hidden folder in home keeps your system tidy
LINK_DIR="$HOME/.my_shortcuts"

# Create the directory if it doesn't exist
mkdir -p "$LINK_DIR"

echo "Creating symlinks in $LINK_DIR..."

for file in *.sh; do
    # Skip the script itself and check if file exists
    if [[ -f "$file" && "$file" != "ln.sh" ]]; then
        
        # 1. Logic: Get name without extension
        base_name="${file%.*}"
        
        # 2. Logic: Get first character
        first_char="${base_name:0:1}"
        
        # 3. Logic: Combine (e.g., r + run = rrun)
        link_name="${first_char}${base_name}"

        # Create the link
        # $PWD ensures the link points to the current location of the actual scripts
        ln -sf "$PWD/$file" "$LINK_DIR/$link_name"
        
        # Optional: Ensure the source script is actually executable
        chmod +x "$file"
    fi
done

echo "---------------------------------------------------"
echo "Success! Shortcuts created."
echo "To run them from everywhere, run this command once:"
echo ""
echo "echo 'export PATH=\"$LINK_DIR:\$PATH\"' >> ~/.zshrc && source ~/.zshrc"
echo ""
echo "(Note: Replace .zshrc with .bashrc if you are using Bash)"
