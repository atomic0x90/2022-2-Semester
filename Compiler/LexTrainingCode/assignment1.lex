%{
	int c=0;
%}
rop	(==|!=|<=|>=)
ass	(<<=|>>=)
%%
{ass}	c++;
{rop}	;
=	c++;
.	;
\n	;
%%
int main(){
	yylex();
	printf("number of assignment statements => %d]n",c);
}
