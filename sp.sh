
#!/bin/bash

# Check for 3 parameters: gen, std, my
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <generator> <your_solution> <spj>"
    exit 1
fi

GEN=$1
MY=$2
K=$3

while true; do
  echo "Test #$i"
  ./$GEN > in
  ./$MY < in > out
  ./K > /dev/null

  if [ $? -ne 0 ]; then
  	  cat in
  	  cat out
  	  break
  fi
done
