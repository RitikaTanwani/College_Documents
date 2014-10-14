#! /bin/bash

lsout=`ls -l`

for i in $lsout
do
	echo $i" foobar"
done

