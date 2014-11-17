#!/bin/bash
line_num=35
name='westnorth'
let "num_dec = 40 "
echo "the num_dec is = $num_dec"
let "num_otc=040"
echo "the num_otc is=$num_otc"
let "num_hex=0x40"
echo "the num_hex is=$num_hex"
a1=3+2
echo "$a1"
echo ${a1}not_the_answer
set a2 = 3+2
echo "$a2"
b=$(ls -l)
echo "$b"
