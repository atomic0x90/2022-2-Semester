%{
#include "t.tab.h"
%}
%%
[0-9]+	return(NUMBER);
\n	;
\-	return('-');
\*	return('*');
.	;
