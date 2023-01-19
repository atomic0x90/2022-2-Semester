%{
#include <stdio.h>
%}
%token	NUMBER
%%
Exp : Exp '+' Term	{printf("rule 1\n");}
    | Term		{printf("rule 2\n");}
	;
Term : Term '*' Num	{printf("rule 3\n");}
     | Num		{printf("rule 4\n");}
	;
Num : NUMBER		{printf("rule 5\n");}
    ;
%%
int main(){
	while(1) yyparse();
	return 0;
}
int yyerror(char *str){
	printf("Error: %s\n",str);
	yyparse();
	return -1;
}
