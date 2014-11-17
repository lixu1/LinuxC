#!/bin/bash
num1=0
while [ "$num1" -lt 5 ];do
echo this is $num1
if [ "$num1" -eq 2 ];then
echo "use continue"
let "num1+=1"
continue
fi
if [ "$num1" -eq 3 ];then
echo "use break,current num is $num1"
break
fi
echo "not use continue"
echo "not use break"
let "num1+=1"
done
exit 
