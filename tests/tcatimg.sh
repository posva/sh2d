#! /bin/bash

IMG=data/yoshi.png
./bin/sh2d $IMG > tmp
W=`convert "$IMG" -print "%w\n" /dev/null`
H=`convert "$IMG" -print "%h\n" /dev/null`
echo "$IMG: ${W}x${H}"

function gtfo() {
  if [[ ! "$1" ]]; then
    echo "Error"
  fi
  if [[ -f tmp ]]; then
    rm tmp
  fi
}

# Dimensions test
[[ `wc -l < tmp` -eq "$H" ]] || ( gtfo && exit 1)
[[ `sed 's/\[[0-9][0-9;m]* */-/g' < tmp | head -n 1 | wc -c` -eq `expr $W + 2` ]] || ( gtfo && exit 1)

gtfo 1
