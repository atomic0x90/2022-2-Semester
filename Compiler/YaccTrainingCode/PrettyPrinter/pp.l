%{
#include "pp.tab.h"
%}
WORD [a-zA-Z]+
%%
if	return(IF);
then	return(THEN);
while	return(WHILE);
do	return(DO);
end	return(END);
c0	return(C0);
stmt	return(STMT);
\n	;
" "	;
