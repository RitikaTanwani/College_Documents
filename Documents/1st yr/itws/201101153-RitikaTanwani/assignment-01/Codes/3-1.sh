#!/bin/bash
du -hk `find $1 -maxdepth 2 -type f` | sort -rn -k1,1 | head -1 | awk '{print $2}'
exit 0
