#!/bin/bash
cd $1
echo REMOVED FILES
find *~
rm -rf *~
exit 0

