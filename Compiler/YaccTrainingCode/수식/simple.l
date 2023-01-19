%{
#include "simple.tab.h"
%}
%x TMP
%%
[0-9]+	return(NUMBER);
[ \t]	;
\n	return(0);
\+	return('+');
\*	return('*');
\$	exit(-1);
.	{printf("'%c': illegal character\n",yytext[0]); BEGIN TMP;}
<TMP>.	;
<TMP>\n	{BEGIN 0;return(0);}

%%
/*
int yyerror(char *str){
	printf("Error: %s %s\n",str,yytext);
	return -1;
}
*/
