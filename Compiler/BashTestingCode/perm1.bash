#!/bin/bash
# 파일의 사용권한과 이름을 프린트한다.

if [ $# -eq 0 ]
then
	echo usage: $0 fileName*
exit 1
fi

echo " permission file"
for file in $*
do
	if [ -f $file ]
	then
		fileinfo=`ls -l $file`
		perm=`echo "$fileinfo" | cut -d' ' -f1`
		echo "$perm $file"
	fi
done

