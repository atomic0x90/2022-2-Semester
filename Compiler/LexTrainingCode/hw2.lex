%{
	#include <string.h>
%}

%%
\{[^}]*\}	{
	size_t length = strlen(yytext);
	char* end = yytext + length;
	char* iter = yytext;
	while(iter != end){
		if(strstr(iter,"/*") == iter){
			char* tmp = strstr(iter,"*/");
			if(tmp != NULL) iter = tmp + 2;
			else printf("%c",*iter++);
		}
		else printf("%c",*iter++);
	}
}
.	ECHO;
\n	ECHO;
