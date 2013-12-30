#! /bin/bash

function gtfo() {
  if [[ ! "$1" ]]; then
    echo "Error"
  fi
  if [[ -f tmp ]]; then
    rm tmp
  fi
}

function pre_test() {
  echo -ne "\e[33m$1\e[0m"
}

function ok_test() {
echo -e "\e[32mOK\e[0m"
}

IMG=data/yoshi.png
EXC="./bin/catimg"
if [[ ! -x $EXC ]]; then
    gtfo && exit 1
fi
if ! ${EXC} $IMG > tmp; then
  echo "Error running catimg"
  exit 1
fi
cat tmp
W=`convert "$IMG" -print "%w\n" /dev/null`
H=`convert "$IMG" -print "%h\n" /dev/null`
echo "$IMG: ${W}x${H}"

# Dimensions test
pre_test "Lines..."
if [[ ! `wc -l < tmp` -eq "$H" ]]; then
  gtfo
  echo "`wc -l < tmp` != $H"
  exit 1
fi
ok_test
pre_test "Columns..."
if [[ ! `sed 's/\[[0-9][0-9;m]* */-/g' < tmp | head -n 1 | wc -c` -eq `expr $W + 2` ]]; then
  gtfo
  echo "`sed 's/\[[0-9][0-9;m]* */-/g' < tmp | head -n 1 | wc -c` != `expr $W + 2` "
  exit 1
fi
ok_test

gtfo 1
