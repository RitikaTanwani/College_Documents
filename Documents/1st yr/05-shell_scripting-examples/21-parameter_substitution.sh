#!/bin/bash

#${} can be used to print values of parameters or variables
A[1]='I am A'.
echo "A. HOME is $HOME or ${HOME}"
echo "A. A[1] is ${A[1]} and not $A[1]"
echo 
echo

#${<variable>-[<Value>|`Command`]} can be used to supply values / commands 
#for variables which are not set. A small variation of same with :
#${<variable>:-[<Value>|`Command`]} can be used to supply values / commands 
#for variables which are null. Note that we can use something like
# B=
#so that B is set, but it is set to null


#Here, B is set, C is set to null and D is not set
B=1
C=         #Can also do C='', empty string is null 
#D=
echo "B. \$B is '${B-B without colon}' or \$B is '${B:-B with colon}'"
echo "B. \$C is '${C-C without colon}' or \$C is '${C:-C with colon}'"
echo "B. \$D is '${D-D without colon}' or \$D is '${D:-D with colon}'"
echo
echo


#The :- can be used to give default values for command line parameters
#Environment variables etc.
echo "C. This script will work with file '${1:-default.txt}'"
echo "C. We will use '${HOME:-/root}' as home folder"
USERNAME=''  #Intentionally setting USERNAME to null
echo "C. Current username is ${USERNAME:-`whoami`} and not '$USERNAME'."
echo
echo


#${<variable>=[<value>|`Command`]} can be used to set value if variable
#is not set. Similarly ${<variable>:=[<value>|`Command`]} can be used 
#if variable is null.
D="echo D. hi"
$D
echo "D. Current username is not '$USERNAME'"
: ${USERNAME:=`whoami`}   #Here : is required to avoid running $USERNAME as command.
echo "D. Current username is $USERNAME"
echo
echo


#${<variable>+[<value>|`Command`]} can be used to set value if variable
#is set. Similarly ${<variable>:+[<value>|`Command`]} also exists
#This is very weird operator. I cant think of use cases for this.
E=1
F=
#G=
echo "E. \$E is '${E+E without colon}' or \$E is '${E:+E with colon}'"
echo "E. \$F is '${F+F without colon}' or \$F is '${F:+F with colon}'"
echo "E. \$G is '${G+G without colon}' or \$G is '${G:+G with colon}'"
echo
echo


#${<variable>?<error>} and ${<variable>:?<error>} can be used to
#print error message supplied and exit with status 1.
#
#Refer to 18-special_characters-question_mark.sh again to see the usage
#Not showing here because that would cause script to end.


#So overall so far:
#   1. ${A-a} and ${A:-a} can be read as, if A is not set or if A is null then use 
#      a as value if A
#   2. ${A=a} and ${A:=a} can be read as, if A is not set or if A is null then set
#      a as value of A
#   3. ${A+a} and ${A:+a} can be read as, if A is set or if A is set to null then use
#      a as value of A. In some sense opposite of ${A-a} and ${A:-a}
#   4. ${A?a} and ${A:?a} can be read as, If A is not set or A is null then end script
#      with exit status 1 and print a as error message.



#Now we will use ${} for finding variable length, substring removal/extraction, 
#number of parameters etc.


#  {#variable_name} can be used to find length of variable
#  {#array_name} will give length of first element of array, as should be
#  expected by now
F="This is big string"
G[0]="zero"
G[1]="one"
echo "F. Length of \$F ($F) is ${#F}"
echo "F. Length of \$G ($G) is ${#G}"
echo
echo



#  {#*} and ${#@} give number of positional parameters. For functions
#  this would mean number of arguments and for script it would mean
#  number of command line arguments.
#  We can use the same with array name as ${#array_name[*]} or
#  ${#array_name[@]} to get number of elements in array
echo "G. This script was called with ${#@} (or ${#*}) number of arguments"
echo "G. \$G has ${#G[@]} (or ${#G[*]}) number of elements"
echo
echo


# ${var#pattern} is used to remove shortest possible match of pattern from
# begining of variable. Similarly ${var##pattern} is used to remove longest
# possible pattern from begining of variable
H="This is good string"
echo "H. PWD is $PWD"
echo "H. Last dir in PWD is ${PWD##*/}"
echo "H. Removing parent most dir in PWD we get /${PWD#/*/}"
#If there is no match then value is returned as it is
echo "H. \$H is ${H##bad}"   
echo
echo


# ${var%pattern} and ${var%%pattern} do the same from opposite end
I="This is good string"
echo "I. PWD is $PWD"
echo "I. Parent dir of PWD is ${PWD%/*}"
J=${PWD#/}
echo "I. Parent most dir of PWD is /${J%%/*}"
echo "I. \$I is ${I%%bad}"
echo
echo


echo "J. Have a look at 22-pattern_matching_examples.sh for more examples on pattern matching"
echo "J. Pattern matching is useful in renaming while changing common starting like new_ with"
echo "   old_ keeping everything same. It is also helpful in changing extensions, for example"
echo "   for renaming all .htm files to .html etc."
echo
echo



#Finally
#1. ${<var>:<pos>} can be used to extract value of variable starting from given position
#2. ${<var>:<pos>:<length>} can be used to extract value of variable starting from given position
#          till given length
#3. ${<var>/<pattern>/<replace>} can be used to change first occurence of pattern in variable with
#	<replace>
#4. ${<var>//<pattern>/<replace>} can be used to change all occurences of pattern in variable with
#       <replace>
#5. ${<var>/#<pattern>/<replace>} can be used to change pattern with replacement only if it occurs
#       at begining
#6. ${<var>/%<pattern>/<replace>} can be used to change pattern with replacement only if it occurs
#       at end
#7. ${!varprefix*}, ${!varprefix@} can be used to match names of all previously declared variables
#       begining with specified prefix


K1="This is really big string with abcdef alpabets and 012345 or 4567890 numbers."
K2="The quick brown fox jumps over the lazy dog is famous for its use of many differnet alphabets within same sentence."

L1=${#K1}
echo "K01. K1 is $K1"
echo "K02. Length of K1 is ${L1}"
echo "K03. Last 20 characters of K1 are ${K1:$((L1-20))}"
echo "K04. First 20 characters of K1 are ${K1:0:20}"
echo "K05. Replacing first occurence of is in K1 with IS we get - ${K1/is/IS}"
echo "K06. Replacing all occurences of is in K1 with IS we get - ${K1//is/IS}"
echo
echo
echo "K07. K2 is $K2"
echo "K08. Replacing starting the with OH in K2 we get - ${K2/#[Tt]he/OH}"
echo "K09. Replaceing all the with OH in K2 we get - ${K2//[Tt]he/OH}"
echo
echo
L2=${!K*}
echo "K10. All variables that are starting with K are - $L2"
L3=${L2/ */}
echo "K11. First of these variables is $L3"

#This is very very important
#Here L3 stores variable name K1
#and with ${!L3} we are getting value of variable whose name is stored in L3
#This is called indirect variable reference
echo "K12. Value of $L3 is ${!L3}"
echo
echo


#Kind of unrelated to ${} but has to put it somewhere
#Note that $'\n' is not enclosed in quotes.
echo "L. To print newline \n we can use " $'\n' " to print new lines"
echo
echo

exit 0

