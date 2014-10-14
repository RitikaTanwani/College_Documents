#!/bin/bash

mkdir -p $HOME/backup
cp -r $HOME/.emacs.d $HOME/backup
cp $HOME/.emacs $HOME/backup
tar cjf backup.tar.bz2 $HOME/backup
rm -rf $HOME/backup

exit 0

