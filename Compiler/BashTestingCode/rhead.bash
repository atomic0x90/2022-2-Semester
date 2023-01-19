#!/bin/bash
# 대상 디렉터리와 모든 하위 디렉터리 내에 있는 파일들의 헤더를 프린트
# 재귀
cd $1
for file in *
do
	if [ -f $file ]
	then
		echo "============ $file ============="
		head $file
	fi
	if [ -d $file ]
	then
	#	/home/yujun/compiler/rhead.bash
		$file
	fi
done
