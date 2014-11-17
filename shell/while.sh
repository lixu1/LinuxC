#!/bin/bash
cur_file="$(ls)"
cur_file_num="$(ls |wc -l)"
num=0
while [ "$num" -le "$cur_file_num" ]
do
for filein in $cur_file;do
echo "the No.${num} file is $filein"
let "num+=1"
done
done
var=""
echo "do you undesratand this script?"
echo if you do, type Isee to quit
while [ "$var" != Isee ]
do
read var
if [ "$var" != Isee ]
then echo "you input is $var"
else echo "quit"
fi
done
exit
