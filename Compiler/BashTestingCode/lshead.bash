#!/bin/bash
# 함수 사용법
lshead(){
	echo "begin, parameter $1"
	date
	echo "list the first three files in directory $1"
	ls -l $1 | head -4
	echo
	ls -a $1 | tail -2
}
echo "Hello"
lshead /tmp
exit 0
