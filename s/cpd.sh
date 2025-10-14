#!/bin/bash

DIR="$(pwd)/param"

content=$(cat $DIR)

echo "$content -g" > $DIR

ccp "$@"

echo "$content" > $DIR
