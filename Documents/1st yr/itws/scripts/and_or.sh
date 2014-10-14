#!/bin/bash

echo "Enter number : "
read Num1

if (( ((Num1 % 2) == 0)  && (Num1 > 10) )); then
	echo "$Num1 is even and greater than 10"
elif  [[ Num1 -le 10 ]]; then
	echo "$Num1 is less than or equal to 10"
else
	echo "$Num1 is not even and greater than 10"
fi

exit 0
		
