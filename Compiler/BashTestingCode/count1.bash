#!/bin/bash
#대상 디렉터리 내의 파일과 서브 디렉터리 개수를 프린트한다
if [ $# -eq 0 ]
then
	dir="."
else
	dir=$1
fi
echo -n $dir : 
ls $dir | wc -l
