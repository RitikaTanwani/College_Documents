#!/bin/bash

#Syntax of case statement is
#case <string> in
# pattern1 | pattern2 | ... )
#			statement1
#			statement2
#			statement3
#			;;
# pattern3 | pattern4 | ... )
#			statement4
#			statement5
#			statement6
#			;;
#esac

#Using one large example below to explain different
#ways of using case

echo "Following program can recognize text as one of following :"
echo "1. Odd / Even numbers"
echo "2. yes / no"
echo "3. end / exit / quit"
echo "4. Number 2"
echo "5. Word hello"
echo "6. Anything else"
echo
echo -n "Enter some test to be recognized : "
read value1

case "$value1" in
2 )  #Should be before test for even numbers :)
	echo "You entered number 2"
	;;

*[02468])  
	echo "If $value1 is number, then it is even"
	;;

*[13579] )
	echo "If $value1 is number, then it is odd"
	;;

[Yy]es )
	echo "You entered yes"
	;;

[Nn]o  )
	echo "You entered no"
	;;

[Qq]uit | [Ee]xit | [Ee]nd )
	echo "You entered either quit or exit or end"
	;;

hello )
	echo "You entered hello"
	;;

*)  	#Matches everything, hence default case is not required
	echo "You entered something else - $value1"
	;;
esac

exit 0

