#!/bin/sh

mkdir -p ~/backup
RESULT=$?
if [[ "$RESULT" -eq "0" ]] ; then
	echo "Mkdir succedded"
else
	echo "Mkdir failed"
fi

rmdir /root >/dev/null 2>&1 
RESULT=$?
if [[ "$RESULT" -eq "0" ]] ; then
	echo "Rmdir succedded"
else
	echo "Rmdir failed"
fi

exit 0

