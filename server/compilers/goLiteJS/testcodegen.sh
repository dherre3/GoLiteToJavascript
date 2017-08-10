#!/bin/bash
# usage: ./testcodegen.sh filename.go

./run.sh "$1" 1> /dev/null

if [ $? -eq 0 ]; then
  GO_OUTPUT="$(go run "$1" 2>&1)"
  GO_EXITCODE=$?
  JS_OUTPUT="$(node "$(basename $1 .go).js" 2>&1)"
  JS_EXITCODE=$?

  if [ "$GO_OUTPUT" == "$JS_OUTPUT" ]; then
    echo -e "\033[0;32mVALID"
  elif [[ $GO_EXITCODE -ne 0 && $JS_EXITCODE -ne 0 ]]; then
    echo -e "\033[0;32mVALID (both threw errors)"
    echo "*****************************"
    echo "  Go output:"
    echo "*****************************"
    echo "$GO_OUTPUT"

    echo "*****************************"
    echo "  JS output:"
    echo "*****************************"
    echo "$JS_OUTPUT"
  else
    echo -e "\033[0;31m[fail]"

    echo "*****************************"
    echo "  Go output:"
    echo "*****************************"
    echo "$GO_OUTPUT"

    echo "*****************************"
    echo "  JS output:"
    echo "*****************************"
    echo "$JS_OUTPUT"
    exit 1
  fi
else
  exit 1
fi

