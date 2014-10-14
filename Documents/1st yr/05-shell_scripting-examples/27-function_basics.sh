#!/bin/bash

#Sub-routines
function A()
{
	echo "A. Inside $FUNCNAME"
}  #This must be on separate line or separate this
   #and last command by ;


#Calling function / sub-routine is just like running commands
A
echo
echo



#Sub-routines with parameters
function B()
{
	echo "B. $FUNCNAME called with $# parameters"
	for param1 in $@
	do
		echo "B. $param1"
	done
}

B a b c
echo
B 
echo
echo


#Functions that return values
function C()
{
	echo "C. $FUNCNAME called with $# parameters"
	sum=0
	for param1 in $@
	do
		sum=$((sum+param1))
	done
	return $sum  #Note $ sign, return takes value as argument
		     #and not variable name like read
}


C 3 4 5
total=$?
echo "C. Sum of 3 4 5 is $total"
echo
echo



#Cant return strings using return
function D()
{
	return "abcd"
}
	
D
value1=$?
echo "D. D function returned $value1"
echo
echo



#How do we return strings then
function E()
{
	echo -n "abcd"
}

E1=`E`
echo "E. Output of function E is $E1"
echo
echo
#There is also possbility of dereferencing using
#expr and eval combinations, but that is considerably
#comples then simply outputing the value and storing
#output of function in variable


exit 0


