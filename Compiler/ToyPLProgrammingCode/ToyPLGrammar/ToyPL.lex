%x	COM
WORD	[a-zA-Z]+([a-zA-Z]|[0-9])*
NUMBER	((\-)?[1-9]+[0-9]*)|0
%%
"/*".*"*/"(\n)?	;
"/*"		BEGIN COM;
<COM>"*/"(\n)?	BEGIN 0;
<COM>.		;
<COM>\n		;
program		printf(" TPROGRAM ");
main		printf(" TMAIN ");
proc		printf(" TPROC ");
func		printf(" TFUNC ");
returns		printf(" TRETURNS ");
var		printf(" TVAR ");
int		printf(" TINT ");
long		printf(" TLONG ");
if		printf(" TIF ");
then		printf(" TTHEN ");
else		printf(" TELSE ");
while		printf(" TWHILE ");
for		printf(" TFOR ");
to		printf(" TTO ");
call		printf(" TCALL ");
return		printf(" TRETURN ");
begin		printf(" TBEGIN ");
end		printf(" TEND ");
\;		printf(";");
\:		printf(":");
\(		printf("(");
\)		printf(")");
\,		printf(",");
\.		printf(".");
\=		printf(" TASS ");
\&		printf(" TAND ");
\|		printf(" TOR ");
\!		printf(" TNOT ");
\<		printf(" TLT ");
\<\=		printf(" TLE ");
\>		printf(" TGT ");
\>\=		printf(" TGE ");
\!\=		printf(" TNE ");
\+		printf(" TPLUS ");
\-		printf(" TMINUS ");
\*		printf(" TMUL ");
\/		printf(" TDIV ");
{WORD}		printf(" TWORD ");
{NUMBER}	printf(" TNUMBER ");
