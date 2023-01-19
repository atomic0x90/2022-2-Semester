#!/bin/bash
#메뉴에 따라 해당 명령어를 실행한다.

echo menu
stop=0
while (($stop == 0))
do
	cat << MENU
	d : date
	l : ls
	w : who
	q : quit
MENU
echo -n '? '
read reply
case $reply in
	"d") date;;
	"l") ls;;
	"w") who;;
	"q") stop=1;;
	*) echo wrong choice;;
esac
done
