word	[^ \t\n]+
%{
	int count = 0;
%}

%%
[0-9]+			printf(" number=>%s(%d) ",yytext,yyleng);
[0-9]+\.[0-9]+		printf(" number=>%s(%d) ",yytext,yyleng);
.	ECHO;
\n	;
{word}	count += 1;

%%
int main(){
	yylex();
	printf("\n%d end\n",count);
}
