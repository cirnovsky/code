# Scripts

Shell scripts for compiling single-file C/C++.

## Usage

Run `ln.sh <username>` to create symlink for scripts into `/home/<username>/bin`. Better to be used with my vim configuration.

Remember to create `parameter.txt` under current working directory.

## Function

1. `ccp file1 file2 ...`: Compile C/C++ files with the arguments named in `parameter.txt`.

2. `ccpd file1 file2 ...`: The same as `ccp`, but produce extra information for GDB.

3. `crun executable1 executable2 ...`: Run compiled executables and print time and memory consumption.

4. `ccr file1 file2 ...`: CR for Compile and Run. Any more word will be idiotic.
