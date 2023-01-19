%{
#include <stdio.h>
int sum = 0;
%}
%union{
	double dval;
	int ival;
}
%token <dval> NUMBER
%type <dval> Exp Term Fact Result
%%
Result : Exp	{$$ = $1;printf("Result: %lf\n",$$);}
Exp : Exp '+' Term	{$$ = $1 + $3; printf("1) %lf\n",$$);}
    	| Exp '-' Term	{$$ = $1-$3;printf("2) %lf\n",$$);}
	| Term		{$$ = $1;printf("3) %lf\n",$$);}
Term : Term '*' Fact	{$$ = $1*$3;printf("4) %lf\n",$$);}
     	| Term '/' Fact	{$$ = $1/$3;printf("5) %lf\n",$$);}
	| Fact		{$$ = $1;printf("6) %lf\n",$$);}
Fact : '(' Exp ')'	{$$ = $2;printf("7) %lf\n",$$);}
     	| NUMBER	{$$ = $1;printf("8) %lf\n",$$);}

%%
int main(){
	yyparse();
}
int yyerror(char* str){
	printf("%s",str);
	return 1;
}
