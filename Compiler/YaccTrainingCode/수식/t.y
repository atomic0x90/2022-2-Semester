%{
#include <stdio.h>
%}
%token	NUMBER
%left '-'
%left '*'
%%
Exp : Exp '-' Exp	{printf("rule 1\n");}
	| Exp '*' Exp	{printf("rule 2\n");}
	| Num		{printf("rule 3\n");};
Num : NUMBER		{printf("rule 4\n");}
    ;
%%
int main(){
	yyparse();
	return 0;
}
int yyerror(char *str){
	printf("Error: %s\n",str);
	yyparse();
	return -1;
}
