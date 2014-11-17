#! /bin/bash
let num1=30
let num2=4
echo "num1=${num1} num2=${num2}"
let total_num=${num1}+${num2}
echo "total_num is ${total_num}"
let multi_num=${num1}**${num2}
echo "multi_num is ${multi_num}"
let mod_num=${num1}%${num2}
echo "mod_num is ${mod_num}"
let "num1+= 3"
echo ${num1}
