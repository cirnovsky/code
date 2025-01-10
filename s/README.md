# Scripts

Shell scripts for compiling single-file C/C++.

## Usage

Run `ln.sh <username>` to create symlink for scripts into `/home/<username>/bin`. Better to be used with my vim configuration.

Remember to create `parameter.txt` under current working directory.

## Function

1. `_cp file1 file2 ...`: Compile C/C++ files with the arguments named in `parameter.txt`.

2. `_cpdd file1 file2 ...`: The same as `_cp`, but produce extra information for GDB.

3. `_run executable1 executable2 ...`: Run compiled executables and print time and memory consumption.

4. `_cr file1 file2 ...`: CR for Compile and Run. Any more word will be idiotic.
