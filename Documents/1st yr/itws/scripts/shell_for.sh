#!/bin/sh

for A in foo bar aha blah
do
	echo "Value is " $A
done

for A in *
do
	echo "File name is " $A
done

exit 0


