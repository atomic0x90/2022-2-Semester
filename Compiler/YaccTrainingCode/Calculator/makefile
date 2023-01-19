main : lex.yy.c cal.tab.c
	gcc -o s lex.yy.c cal.tab.c -lfl
lex.yy.c : cal.l
	flex cal.l
cal.tab.c cal.tab.h : cal.y
	bison -d cal.y
