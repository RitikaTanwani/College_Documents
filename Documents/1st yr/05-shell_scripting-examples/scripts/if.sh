#!/bin/bash

#Ask user to give integer value
echo -n "Enter some integer : "
#Read value supplied by user in variable Val1
read Val1

#Check if Val1 is greater than 10
if ((Val1 > 10)) ; then
	#if Yes then print
	echo "Value is greater than 10" #Greater
else	#otherwise
	echo "Value is less than or equal to 10"
fi

exit 0
