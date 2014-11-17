#!/bin/bash
year=2008
if [ "${year}>2000" ]; then
echo "this year is 21th" 
else
echo "this year is not in 21th" 
fi
[ "$year>2000" ] && echo "this year is 21th by second way"

echo "-------------"
num1=35
num2=58
num3=87
num4=12
if [ "$num1" \< "$num2" ] && [ "$num2" \< "$num3" ]; then
echo "they are sorted"
fi
if [ "$num1" \> 50 ] || [ "$num2" \> 50 ]
then echo "there is one num bigger than 50 at least"
fi
