#!/bin/bash
i=$1
str=${i##*.}
if [ "$str" = "tar" ];
then
 tar -tf $1 | cut -d "/" -f1 | sort -u
elif [ "$str" = "gz" ];
then
 tar -tf $1 | cut -d "/" -f1 | sort -u
else
echo error: given file is not a tar file
fi

exit 0

