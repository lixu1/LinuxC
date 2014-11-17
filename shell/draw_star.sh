#!/bin/bash
times=0
time2=0
while [ $times -lt 8 ]; do
while [ $time2 -lt $times ];do
echo -n '*'
let "time2+=1"
done
let time2=0
let "times+=1"
echo #换行
done
exit
