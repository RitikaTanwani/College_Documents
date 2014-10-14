#!/bin/bash

#We can check for some condiation to be true or false using if statement
#and test command 
if test -f 24-if_statement.sh
then
	echo "A. File 24-if_statement.sh exists in current folder."
fi


#The if and then can be put on same line by use of ;
if test -f 24-if_statement.sh ; then
	echo "A. File 24-if_statement.sh exists in current folder."
fi


#Rather than writing test we can also use [[ ]] which also
#test for given condition 
if [[ -f 24-if_statement.sh ]] ; then
	echo "A. File 24-if_statement.sh exists in current folder."
fi
echo
echo
#Avoid use of [ ] which may also work, [ ] is less intuitive then [[ ]]
#for example we cannot use && or || in [ ] but same would work in [[ ]]


#Various different types of tests that can be done are:
#String comparisons
#------------------
#        string1 = string2        -> True if strings are equal
#       string1 != string2        -> True if strings are not equal
#       -n string                 -> True if string is not null
#       -z string                 -> True if string is null
#	string1 < string2         -> True if string1 is ASCII wise less than string2
#       string1 > string2         -> True if string1 is ASCII wise greater than string2
#
#Arithmetic comparisons
#----------------------
#             A -eq B             -> True if A equals B
#             A -ne B             -> True if A is not equal to B
#             A -gt B             -> True if A is greater than B
#             A -ge B             -> True if A is greater than or equal to B
#             A -lt B             -> True if A is less than B
#             A -le B             -> True if A is less than or equal to B
#
#
#Boolean operations
#------------------
#               !A                -> True if A is false
#
#
#Filesystem related tests
#-----------------------
#             -d val1             -> True if val1 is a directory
#             -e val1             -> True if val1 is exists
#             -f val1             -> True if val1 is a file
#             -g file             -> True if set-gid is set on file
#             -r val1             -> True if val1 is readable
#             -s file             -> True if file is not empty
#             -u file             -> True if set-uid is set on file
#             -w val1             -> True if val1 is writable
#             -x val1             -> True if val1 is executable
#	      -p val1             -> True if val1 is pipe
#             -h val1             -> True if val1 is symbolic link
#             -L val1             -> True if val1 is symbolic link
#             -O val1             -> True if we are user owner of val1
#             -G val1             -> True if we are group owner of val1
#             val1 -nt val2       -> True if val1 is newer than val2
#             val1 -ot val2       -> True if val1 is older than val2
#             val1 -ef val2       -> True if val1 and val2 are hard-links
#
#Try each of this cases on your own and understand how they work few special
#cases or caveats are discussed below


#In below example double quotes ("") around B are required to handle
#null value of B, else one will get error "unary operator expected"
#That is because if we write 
#  if [ "name" =  $B ] ; then
#when $B is empty the line becomes
#  if [ "name" =  ] ; then
#and hence we get error "unary operator expected"
#So always enclose variable names in quotes ("") when it is possible for
#them to be null
B=''
if [ "name" = "$B" ] ; then 
	echo "B. \$B contains name"
else
	echo "B. \$B does not contains name"
fi
#Learn else from above if :)
echo
echo


#Use
#    ls -l /sbin | grep -- '-........-.*' | more
#to get name of some executable in /sbin for which others
#do not have execute permission in case you get file or
#command not found error for below example.
#
if [ -x "/sbin/auditd" ] ; then
	echo "C. /sbin/auditd  is executable"
else
	echo "C. /sbin/auditd  is not executable"
fi
#Note that file is executable by root but not by us hence
#test for executable fails. Similarly
if [ -w "/sbin" ] ; then
	echo "C. /sbin is writable"
else
	echo "C. /sbin is not writable"
fi
#Even here tests are conducted based on user who is running
#the shell script 
echo
echo



#There is also elif if we want to create "else if" ladder
if [ -w "/sbin" ] ; then
	echo "D. /sbin is writable"
elif [ -x "/sbin" ] ; then  #Now writing this then without ; on next line 
			    #would be very wierd
	echo "D. /sbin is executable"
else
	echo "D. /sbin is neither writable nor executable"
fi
echo
echo


#&& and || can be used for short-circuit AND or OR operations
if [ -x "/sbin" ] && echo "E. Executable" && [ -w "/sbin" ] && echo "E. Writable" ; then
	echo "E. /sbin is both executable and writable"
else
	echo "E. /sbin is only what got printed above"
fi
echo
echo
#Note echo returns true


#String comparisons
F1="0"
F2="1"
F3="9"
F4="10"
if [[ "$F1" > "$F2" ]] ; then
	echo "F. Alphabetically $F1 is greater than $F2"
else
	echo "F. Alphabetically $F1 is less than $F2"
fi
if [[ "$F3" > "$F4" ]] ; then
	echo "F. Alphabetically $F3 is greater than $F4"
else
	echo "F. Alphabetically $F3 is less than $F4"
fi
if [[ "$F3" -gt "F4" ]] ; then
	echo "F. Numerically $F3 is greather than $F4"
else
	echo "F. Numerically $F3 is less than $F4"
fi
#(( )) will allow use > or < for numeric comparisons
if (($F1 > $F2))  ; then
	echo "F. Numerically $F1 is greater than $F2"
else
	echo "F. Numerically $F2 is greater than $F1"
fi
if (($F3 > $F4)) ; then
	echo "F. Numerically $F3 is greater than $F4"
else
	echo "F. Numerically $F4 is greater than $F3"
fi


exit 0

