%{
	int count = 0;
%}

%s CHECK


%%
"("		BEGIN CHECK;
<CHECK>a	count++;
<CHECK>")"	BEGIN 0;
<CHECK>[^a]	;
\n		;
.		;

%%
int main(){
	yylex();
	printf("%d",count);
}

