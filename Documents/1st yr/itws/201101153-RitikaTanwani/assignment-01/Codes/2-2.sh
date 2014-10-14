#!/bin/bash


ps -eo pid,cmd --sort rsz | tail -n 1
exit 0
