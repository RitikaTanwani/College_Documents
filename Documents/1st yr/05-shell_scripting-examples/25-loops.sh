#!/bin/bash

#for loop
#----------
#Shell for loop is for-each type of loop. It is not like C or Java for loop
#where there is some condition for iteration and some increment step. In
#shell for loop we can loop over list of items

for number in 2 3 5 7
do
	echo "A. Current number is $number"
done
echo
echo



#We can use shell patterns to specify list of arguments to for
total_size=0
for file1 in *
do
	current_size=`du -s $file1 | grep -o '^[0-9]*'`
	total_size=$((total_size + current_size))
	#echo "Size of $file1 is $current_size, total size so far is $total_size"
done
echo  "B. Total size of files and folders inside current folder is $total_size KB"
echo
echo


#We can use output of command as argument to for
for file1 in $(grep -l for *)
do
	echo "C. File $file1 contains word for."
done
echo
echo


#while loop
#----------
#while loop is like traditional while loops where loop continues
#till condition is true

counter1=0
while ((counter1<5)) ; do
	((counter1++))
	echo "D. counter1 is $counter1"
done
echo
echo

#The same can probably be done in more Shell-script style as
COUNTER1=0
while [[ "$COUNTER1" -lt 5 ]] ; do
	COUNTER1=$((COUNTER1+1))
	echo "E. COUNTER1 is $COUNTER1"
done
echo
echo


#until loop
#----------
#until is very similar to while loop. While loop iterates till
#condition is true, until loop iterates till condition is false
#Hence until does not gives anything extra, we can always 
#achieve until by adding not (!) to while loop condition

counter1=0
until ((counter1==5)); do
	((counter1++))
	echo "F. counter1 is $counter1"
done
echo
echo


#break and continue
#------------------
#break and continue work just as they work in loops in any other
#language. All three types of loops support break and continue


counter1=2
while ((counter1<20)); do
	counter2=2
	prime=1
	while ((counter2<counter1)); do
		if ((counter1%counter2==0)) ; then
			prime=0
			break   #makes things efficient
		fi
		((counter2++))
	done
	if ((prime==1)) ; then
		echo "G. $counter1 is prime"
	fi
	((counter1++))
done

#You can explore continue on your own	



exit 0



