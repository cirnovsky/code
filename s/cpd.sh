#!/bin/bash

DIR="$(pwd)/param"

content=$(cat $DIR)

echo "$content -g" > $DIR

_cp "$@"

echo "$content" > $DIR
