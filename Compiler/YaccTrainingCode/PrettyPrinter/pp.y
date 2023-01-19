%{
#include <stdio.h>
int i,j;
%}
%token IF THEN WHILE DO END C0 STMT
%%
S : If
  	| While
	| STMT 	{for(j = 0;j < i;j++)printf(" ");printf("stmt\n");}
If : 	IF	{for(j = 0;j < i;j++)printf(" ");printf("if ");}
   	Cond 
	THEN	{printf("then\n"); i = i+4;}
	S	{i = i-4;}
While : WHILE	{for(j = 0;j < i;j++)printf(" ");printf("while ");}
      	Cond
	DO	{printf("do\n");i = i+4;}
	S	
	END	{i = i-4;for(j = 0;j < i;j++)printf(" ");printf("end\n");}
Cond : C0	{printf("c0 ");}
%%
int yyerror(char *str){
	printf("%s\n",str);
}
int main(){
	yyparse();
}
