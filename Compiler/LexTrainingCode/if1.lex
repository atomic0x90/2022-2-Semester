%{
	int c=0;
%}
word	[a-zA-Z]+
%%
if	c++;
{word}	;
.	;
\n	;
%%
int main(){
	yylex();
	printf("number of IF statements => %d\n",c);
}
