#!/bin/bash
#계속 여부를 입력받아 프린트한다.
echo -n "GO on?"
read reply
if [ $reply == yes ]
then
	echo yyyyyy
elif [ $reply == "no" ]
then
	echo nnnnnn
fi

