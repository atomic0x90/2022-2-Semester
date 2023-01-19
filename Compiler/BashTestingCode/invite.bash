#!/bin/bash
# 반복, 배열
invitee=(lee kim choi)
#invitee="lee kim choi"
#invitee=("lee kim choi")
#invitee=("lee" "kim" "choi")
echo ${invitee[*]}
echo ${invitee[@]}
echo ${invitee}
for person in "${invitee[@]}"
do
	echo "$person"
done
