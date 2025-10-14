# Create symlink for all file in the current directory that has an extension of .sh to /home/<user>/bin, and remove the extension, add the underscore prefix

for file in *.sh; do
	if [ $file != "ln.sh" ]; then
		ln -s $(realpath $file) ../c${file%.*}
	fi
done
