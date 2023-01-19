%s BRACE
%s CMT

%%
\{	{ECHO;BEGIN BRACE;}
<BRACE>\}	{ECHO;BEGIN 0;}
<BRACE>"/*"	BEGIN CMT;
<BRACE>(.|\n)	ECHO;
<CMT>"*/"	BEGIN 0;
<CMT>.		;
<CMT>\n		;
(.|\n)	ECHO;
