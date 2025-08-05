#!/bin/bash

# Check for 3 parameters: gen, std, my
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <generator> <std_solution> <your_solution>"
    exit 1
fi

GEN=$1
STD=$2
MY=$3

while true; do
  echo "Test #$i"
  ./$GEN > in
  ./$MY < in > out
  ./$STD < in > std

  if diff -Z out std >/dev/null; then
    echo "🐶"
  else
    echo "😺"
    echo "====input===="
    cat in
    echo "====expected====="
    cat std
    echo "====yours====="
    cat out
    break
  fi
done
