#!/bin/sh
#명령줄 인수를 하나씩 왼쪽으로 이동한다.
echo the first argument $1, others $*
shift
echo the first argument $1, others $*
