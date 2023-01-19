%s CMT
%%
"/*".*"*/"	;
"/*"		BEGIN CMT;
<CMT>"*/"	BEGIN 0;
<CMT>.		;
<CMT>\n		;
.		ECHO;

