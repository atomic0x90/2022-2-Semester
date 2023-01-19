%{
	char *c1="",*c2="",*c3="";
%}
%s BRACE
%x CMT

%%
"{"		{BEGIN BRACE;ECHO;}
<BRACE>"/*"	{BEGIN CMT;c1 += '/'+'*';}
<BRACE>"}"	{if(strlen(c1)==2 && strlen(c3)==2){}else{printf("%s%s%s",c1,c2,c3);};BEGIN 0;ECHO;}
<BRACE>.	ECHO;
<BRACE>\n	{BEGIN 0;printf("%s%s%s",c1,c2,c3);}
<CMT>"*/"	{BEGIN 0;c3 += '*'+'/';}
<CMT>.		c2 += yytext[0];
<CMT>\n		BEGIN 0;

\n	ECHO;
.	ECHO;
