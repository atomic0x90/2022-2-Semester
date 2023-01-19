main: lex.yy.c pp.tab.c
	gcc -o pp lex.yy.c pp.tab.c -lfl
lex.yy.c: pp.l
	flex pp.l
pp.tab.c pp.tab.h: pp.y
	bison -d pp.y
