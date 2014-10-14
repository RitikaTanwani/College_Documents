#!/usr/bin/python
import sys
import re
m=re.match(r'201[^012]|20[^01]\d+|2[^0]\d\d+|[^012]\d\d\d+|\d\d\d\d\d+',sys.argv[1])
if m!=None:
	print "Number is greater than 2012"
else:
	print "Number is less than 2012"
