#!/bin/bash

ps -elf | grep $1 | grep -v grep
exit 0
