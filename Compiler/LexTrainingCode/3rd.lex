%{
	int count = 0;
%}
word	[^ \t\n]+
eol	\n
%%
{word}	count = count + 1;
{eol}	{count = count + 1; printf("%d\n",count);}
.	ECHO;
