#!/bin/sh

#Ignore use () to create sub-shell
#CDPATH is used to specify set of folders which should be
#searched for sub-folders when cd is used 
(
echo "A. $PWD"
CDPATH=/var/www
cd html
)
echo
echo



#FUNCNAME stores name of current function being executed
foo()
{
	echo "B. Inside foo FUNCNAME IS $FUNCNAME"
}
echo "B. In script FUNCNAME is $FUNCNAME"
foo
echo
echo



#HOME usually stores home folder path for current user
#HOSTNAME usually stores hostname for current system
#USERNAME usually stores current username
#LINENO usually stores current line number when executing shell scripts
#PPID usually stores parent process ID
#PWD usually stores current working directory.
#SECONDS usually stores running time of script in seconds
#$! usually stores PID of last command run in background
#$_ finally stores final argument of last command
#$? usually stores exit status of last command
#$$ usually stored PID of script itself
echo "C. HOME folder for $USERNAME is $HOME on system $HOSTNAME"
echo "C. Current line is $LINENO"
echo "C. Parent process ID is $PPID"
echo "C. Script is running since $SECONDS seconds"
rm -f a b c &
echo "C. PID of last command run in background is $!"
rm -f a b c 
echo "C. Final argument of previous command is $_"
rm -f a b c
echo "C. Exit status of last command is $?"
echo "C. PID of current script is $$"
echo
echo


#IFS stands for internal field separator
#This is what separates word boundaries
#Not changing IFS here, you can experiment in lab time
#with IFS


#PS1 and PS2 are primary and secondary prompts
#Not changing their values here.


#PIPESTATUS is array containing return values of commands
#which were run using pipe.
echo "Going to run ls -1 | sort | uniq | wc | grep 'abcd'"
ls -1 | sort | uniq | wc | grep 'abcd'
status=${PIPESTATUS[*]}
echo "D. Exit status of various commands were $status"
echo
echo


#REPLY is default argument for read
echo -n "E. Enter your name : "
read
echo "E. Your name is $REPLY"
echo
echo


#$1, $2, upto $9 are command line arguments or arguments to function
function print_args1()
{
	echo "F1. Function is given $# command line arguments"
	echo "F2. First three Arguments are : " $1 $2 $3 
	echo "F3. All arguments are : " $*
	echo "F4. All arguments are also : " $@
	echo "F5. Difference between \$* and \$@ is that \$* is affected by IFS"
	IFS=''
	echo "F6. All arguments are : $* or $@"
	echo "F7. Double quotes matter else " $* and $@ "are same"
	IFS=':'
	#Notice : below after are does not gets echoed.
	echo "F8. All arguments are : $* or $@"
	unset IFS
	echo "F9. All arguments are : $* or $@"
	echo
	echo "    Although here all examples are working with function arguments"
	echo "    so that script does not depends on caller for arguments to show"
	echo "    how \$1, \$2, etc. work. But exactly same things when used"
	echo "    outside function work on command-line arguments"
	echo 
	echo "F10. If there are more than 9 parameters then we have to use shift"
	echo "    which left shifts all arguments discarding the first one"
	echo "At present \$1 is $1, \$2 is $2, \$3 is $3 and \$4 is $4"
	shift
	echo "Now after shift \$1 is $1, \$2 is $2, \$3 is $3 and \$4 is $4"
	shift
	echo "Now after anoter shift \$1 is $1, \$2 is $2, \$3 is $3 and \$4 is $4"
	shift
	echo "Now after anoter shift \$1 is $1, \$2 is $2, \$3 is $3 and \$4 is $4"
}
print_args1 a b c d
echo
echo



exit 0


