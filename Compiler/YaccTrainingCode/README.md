## yacc 사용법

1. % vi simple.l simple.y
2. % flex simple.l
3. % bison -d simple.y
4. % gcc -o sim lex.yy.c simple.tab.c -lfl

