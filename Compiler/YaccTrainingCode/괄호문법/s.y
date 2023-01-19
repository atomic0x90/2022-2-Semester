%{
#include <stdio.h>
%}
%%

S : '(' S ')' S
  	|
	;
%%
int yyerror(char* str){
	printf("%s",str);
	return 1;
}
