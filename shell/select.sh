#!/bin/bash
select iam in "cat" "dog" "carrot" "tiger" "panda"
do
echo "You think I am $iam."
echo -n "But ......."
sleep 1
echo "..."
if [ "$iam" = "panda" ];then
echo "you are right"
break
else
echo "you are wrong"
fi
echo
done
exit 0
