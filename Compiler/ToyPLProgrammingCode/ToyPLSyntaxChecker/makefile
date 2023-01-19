main : lex.yy.c ToyPL.tab.c
	gcc -o t lex.yy.c ToyPL.tab.c
ToyPL.tab.c ToyPL.tab.h : ToyPL.y
	bison -d ToyPL.y
lex.yy.c : ToyPL.lex
	flex ToyPL.lex
