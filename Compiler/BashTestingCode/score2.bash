#!/bin/bash
# 점수에 따라 학점을 결정하여 프린트

echo -n '점수 입력: '
read score
let grade=$score/10
echo $grade
case $grade in
	"10"|'9') echo A;;
	"8") echo B;;
	*) echo F;;
esac
