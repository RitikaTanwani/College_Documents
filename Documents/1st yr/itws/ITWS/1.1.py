#!/usr/bin/python
import sys
import re
m=re.match(r'^(101)(0*1*)$|^((00)*1(11)*)$',sys.argv[1])
if m!=None:
	print sys.argv[1] + " is valid"
else:
	print sys.argv[1] + " is not valid"
