
#!/bin/bash
a=$(ps -elf | grep -v grep | grep flash | tr -s ' ' | cut -d ' ' -f4)
b=$(ls -la /proc/$a/fd | grep Flash | cut -d ' ' -f8)
# echo $a   $b
cp /proc/$a/fd/$b  ~/$1
echo Video $1 saved succesfully.
exit 0
