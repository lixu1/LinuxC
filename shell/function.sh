#! /bin/bash
#opt_func.sh
get_bigger()
{
if [ $1 -gt $2 ];then
return 111
else
return 222
fi
exit
}
echo input number 1:
read var1
echo input number 2:
read var2
get_bigger "$var1" "$var2"
if [ "$?" -eq 111 ];then
echo "the number 1 is bigger"
else
echo "the number 2 is bigger"
fi
exit

