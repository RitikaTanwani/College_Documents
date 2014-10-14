#!/bin/bash

#$RANDOM can be used to generate pseudo random numbers
echo "A. RANDOM number between 0 and 32767 is $RANDOM"
echo
echo
#How would you generate true / better random numbers than
#pseudo-random numbers?


#Command substitution and quoting
ls `echo a b`     # 2 args: a and b
ls "`echo a b`"   # 1 arg: "a b"
ls `echo`         # no arg
ls "`echo`"       # one empty arg
echo
echo


#$() is preferred over use of ` ` for command substitution
#$() supports quoting. $() also treats \\ differently then ` `
echo "C. `echo \\`"
echo "C. $(echo \\)"
echo "C. $(echo $(echo $(echo \\)))"
echo
echo



#Here documents, can be used to supply values for input stream
#Although we can output whatever input we want to supply to a temporary
#file and then use < to supply values in temporary file as input to
#*most* programs. Here documents allow us to specify input directly
#without requiring temporary files

cat > abc.txt <<Someuncommonsequence
Hi $USER
I know your home folder is $HOME
Write this to abc.txt
Even write this to abc.txt
Keep writing data to abc.txt
Now we have enough data
So we will have line containing just the
special sequence that we have choosen
above to indicate end of here document
Someuncommonsequence

echo "D. Contents of here document are:"
cat abc.txt

#Deleting abc.txt to keep directory clean
rm -f abc.txt
echo
echo "D. Look at 04-create_rm.sh again and write it using here documents"
echo
echo


#There are many variants of here documents which depend upon
#the way we specify the sequence that determines end of
#here document. Some of those variants are:
# 1. If special sequence start with - then leading tabs are suppressed
# 2. Parameter substitution can be turned off by quoting sequence or by
#    starting sequence with \
#    Example: \Someuncommonsequence
#             "Someuncommonsequence"
#             'Someuncommonsequence'

#   And, likewise:


#Displaying on screen, after all cat displays input on output stream
cat <<"SpecialCharTest"

E. Directory listing would follow
   if limit string were not quoted.
`ls -l`

E. Arithmetic expansion would take place
   if limit string were not quoted.
$((5 + 3))

E. A a single backslash would echo
  if limit string were not quoted.
\\

SpecialCharTest
echo
echo



GetPersonalData ()
{
  read firstname
  read lastname
  read address
  read city 
  read state 
  read zipcode
} # This certainly looks like an interactive function, but...


# Supply input to the above function.
GetPersonalData <<RECORD001
Saurabh
Barjatiya
IIIT Hyderabad
Hyderabad
AP
500032
RECORD001


echo "F. $firstname $lastname"
echo "F. $address"
echo "F. $city, $state $zipcode"
echo
echo



#There is also something called here strings
#That allow value of some single string / variable to be used as
#input. Its use is illustrated with below example.

String="This is a string of words."

read -r -a Words <<< "$String"
#  The -a option to "read"
#+ assigns the resulting values to successive members of an array.

echo "G. First word in String is:    ${Words[0]}"   # This
echo "G. Second word in String is:   ${Words[1]}"   # is
echo "G. Third word in String is:    ${Words[2]}"   # a
echo "G. Fourth word in String is:   ${Words[3]}"   # string
echo "G. Fifth word in String is:    ${Words[4]}"   # of
echo "G. Sixth word in String is:    ${Words[5]}"   # words.
echo "G. Seventh word in String is:  ${Words[6]}"   # (null)
                                                 # Past end of $String.
echo
echo



#Blocks of code, such as while, until, and for loops, even if/then 
#test blocks can also incorporate redirection of stdin. Function can
#also use this form of redirection

cat > names.txt <<EOF
Ankur
Parag
Saurabh
EOF
NAMEFILE="names.txt"
while [[ "$name" != "Saurabh" ]] ; do
	read name
	echo "H. Read $name, waiting to find Saurabh"
done < $NAMEFILE  #We could have directly done < names.txt too, but
		  #this is done to demonstrate that input can come
		  #from any file and the file can determinted at
		  #run time based on value of variable
echo "H. Found what were looking for :)"
echo
echo
rm -f names.txt
#Although not done in above example both stdin and standard output
#can be redirected. 





#( command1; command2; command3; ... )
# A command list embedded between parentheses runs as a subshell.
# Variables in a subshell are not visible outside the block of code 
# in the subshell. They are not accessible to the parent process, to 
#the shell that launched the subshell. These are, in effect, 
#variables local to the child process.

#Sub-shells start a separate small shell. Normally most external commands
#in a shell script start a separate small sub-shell. We can have nested
#sub-shells. There are even variables ($BASH_SUBSHELL) which tell how deep we are in
#sub-shell nesting. If this is confusing dont watch Inception :)
#

#We can add & at end of sub-shell as (ls; sleep 300; ls) & to make sub-shell
#go into background. This way we can achieve very complex parallel tasks using
#shells where each of the parallel threads has full powers/capabilities of single
#unthreaded shell script




#Process substitution allows use of output of command as filename. 
#This file can be redirected using < or > to allow output of a command
#to become input of another command directly.
#   This also allows output of any command(s) to be used as argument
#to many different commands as filenames (not as arguments, it is not $())
#
#Have a look at process substitution at
#  http://tldp.org/LDP/abs/html/process-sub.html
#to understand details
#
#If one uses process substituion to answer mid-sem 1 nc questions then
#  nc 10.5.1.36 9000 <(gzip -c big_file.iso)
#would work exactly same as
#  gzip -c big_file.iso | nc 10.5.1.36 9000
#<() gets converted to a filename. 
#
#Using process substituion diff <(command1) <(command2)
#gives difference between output of two commands.
#

(
diff <(ls) <(ls -a)
)


#If you want you can
#redirect output of command as input to another command using
# < <() 

while read input1
do
	echo "Read $input1"
done < <(echo "A B C")



#Scopes
#{} can be used to define functions and scopes
#{} without function name is like anonymous function and all
#variables in it have global scope

#When we use function as
function abcd()
{
	local secret='aha'
	other_secret='oho'
}
echo "I.Before call secret is $secret and other_secret is $other_secret"
abcd
echo "I. After call secret is $secret and other_secret is $other_secret"
echo
echo
#Hence unless declared local inside a named function, variable is global


	
#Local variables are must for recursion
#Else you would end up modifying values of variables of parent functions
#in recursive calls. Trying writing a factorial with/without local
#variables and lots of echos to understand this point.





#Shell supports opening of other file descriptors
#other than standard input, output and error. Shell also supports
#closing of opened file descriptors etc. Hence extensive file
#based operations can be done using shell scripts. Most of these
#just make certain very rare tasks easy, but do not make shell more
#powerful than what it already is. Hence we are skipping those
#options. Enthusiastic students are encouraged to learn this and
#other advanced topics like eval, expr etc. on their own. But
#knowledge of these topics is not expected for assignments,
#exams or quizzes. However if you do use any of these things
#and output is correct you would get marks.

#Have a look at http://tldp.org/LDP/abs/html/redirapps.html
#to see what can be achieved with crazy/clever redirections



#In case you are every going to organize shell scripting programming
#contests and going to automate evaluations then have a look at
#http://tldp.org/LDP/abs/html/restricted-sh.html





#Note that following things are part of course
#1. Process substitution using <() or >()
#2. Subshells ()
#3. Redirecting input/output from code blocks
#4. Sending subshells to background using () &
#5. Knowledge of debugging shell scripts with -n, -v, -x, -o etc. (Self learning)
#6. Variable scopes


#Following things are not part of course
#1. Dealing with file descriptors directly except stdin, stdout, stderr 
#   by >, <, 2>, >> etc.
#2. Restricted shells
#3. Indirect references or use of eval, expr
#4. Use of exec to replace script with other process. This is similar
#   to C exec function. This is used very often to deal with file
#   descriptors


#This is end of shell scripting lectures / examples.
#Have a look at http://tldp.org/LDP/abs/html/index.html
#to see what all you have learned in this course so far.



exit 0


