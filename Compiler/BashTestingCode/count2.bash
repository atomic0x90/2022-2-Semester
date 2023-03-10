#!/bin/bash
# 대상 디렉터리 내의 파일, 서브디렉터리, 기타 개수를 세서 프린트
if [ $# -eq 0 ]
then
	dir="."
else
	dir=$1
fi
if [ ! -d $dir ] 
then
	echo $0\: $dir is not directory
	exit 1
fi

let fcount=0
let dcount=0
let others=0

echo $dir\:
cd $dir
for file in *
do
	if [ -f "${file}" ]
	then
		let fcount++
	elif [ -d "${file}" ]
	then
		let dcount++
	else
		let others++
	fi
done

echo file: $fcount directory: $dcount others: $others
