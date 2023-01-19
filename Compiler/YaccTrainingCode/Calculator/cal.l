%{
#include "cal.tab.h"
%}

%%
[0-9]+(\.[0-9]+)?([eE][0-9]+)?	{yylval.dval = atof(yytext);return(NUMBER);}
\+	return('+');
\*	return('*');
\-	return('-');
\/	return('/');
\(	return('(');
\)	return(')');
\n	;
