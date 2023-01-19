%{
#include"ToyPL.tab.h"
%}
%x	COM
WORD	[a-zA-Z]+([a-zA-Z]|[0-9])*
NUMBER	((\-)?[1-9]+[0-9]*)|0
%%
"/*".*"*/"(\n)?	;
"/*"		BEGIN COM;
<COM>"*/"(\n)?	BEGIN 0;
<COM>.		;
<COM>\n		;
program		return(TPROGRAM);
main		return(TMAIN);
proc		return(TPROC);
func		return(TFUNC);
returns		return(TRETURNS);
var		return(TVAR);
int		return(TINT);
long		return(TLONG);
if		return(TIF);
then		return(TTHEN);
else		return(TELSE);
while		return(TWHILE);
for		return(TFOR);
to		return(TTO);
call		return(TCALL);
return		return(TRETURN);
begin		return(TBEGIN);
end		return(TEND);
\;		return(';');
\:		return(':');
\(		return('(');
\)		return(')');
\,		return(',');
\.		return('.');
\=		return(TASS);
\&		return(TAND);
\|		return(TOR);
\!		return(TNOT);
\<		return(TLT);
\<\=		return(TLE);
\>		return(TGT);
\>\=		return(TGE);
\!\=		return(TNE);
\+		return(TPLUS);
\-		return(TMINUS);
\*		return(TMUL);
\/		return(TDIV);
\n	;
" "	;
\t	;
{WORD}		{return(TWORD);}
{NUMBER}	{return(TNUMBER);}

%%
int yyerror(char *std){
	printf("Error: %s %s\n",std,yytext);
	return -1;
}
