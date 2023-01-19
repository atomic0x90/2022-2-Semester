%{
#include <stdio.h>
%}
%token TPROGRAM
%token TMAIN
%token TPROC
%token TFUNC
%token TRETURNS
%token TVAR
%token TINT
%token TLONG
%token TIF
%token TTHEN
%token TELSE
%token TWHILE
%token TFOR
%token TTO
%token TCALL
%token TRETURN
%token TBEGIN
%token TEND
%token TASS
%token TAND
%token TOR
%token TNOT
%token TLT
%token TLE
%token TGT
%token TGE
%token TNE
%token TPLUS
%token TMINUS
%token TMUL
%token TDIV
%token TWORD
%token TNUMBER
%%

Program : TPROGRAM Name ';' SubPgmList TMAIN VarDecl CompStmt '.'
VarDecl : TVAR DclList ';' 
	|
DclList : DclList ';' Decl 
	| Decl
Decl : VarList ':' Type
VarList : VarList ',' Var 
	| Var
Type : TINT 
     | TLONG
Var : Name
SubPgmList : SubPgmList SubPgm 
	   |
SubPgm : ProcDecl 
       | FuncDecl
ProcDecl : TPROC ProcName '(' FormParam ')' VarDecl CompStmt
FuncDecl : TFUNC FuncName '(' FormParam ')' TRETURNS '(' Type ')' VarDecl CompStmt
FormParam : DclList 
	  |

Stmt : AsgnStmt
     	| IfStmt
	| WhileStmt
	| ForStmt
	| CallStmt
	| RtrnStmt
	| CompStmt
AsgnStmt : Var TASS Expr
IfStmt : TIF '(' Cond ')' TTHEN Stmt
       	| TIF '(' Cond ')' TTHEN Stmt TELSE Stmt
WhileStmt : TWHILE '(' Cond ')' Stmt
ForStmt : TFOR '(' Var TASS Expr TTO Expr ')' Stmt
CallStmt : TCALL ProcName '(' ParamList ')'
RtrnStmt : TRETURN '(' Expr ')'
CompStmt : TBEGIN StmtList TEND
StmtList : StmtList ';' Stmt
	 | Stmt


Cond : Cond TAND Rel
     	| Cond TOR Rel
	| TNOT Rel
	| Rel
Rel : Expr TLT Expr
    	| Expr TLE Expr
	| Expr TGT Expr
	| Expr TGE Expr
	| Expr TASS Expr
	| Expr TNE Expr
Expr : Expr TPLUS Term
     	| Expr TMINUS Term
	| Term
Term : Term TMUL Fact
     	| Term TDIV Fact
	| Fact
Fact : Var
     	| Number
	| FuncCall
	| TMINUS Fact
	| '(' Expr ')'
FuncCall : FuncName '(' ParamList ')'
ParamList : ExprList
	  |
ExprList : ExprList ',' Expr
	 | Expr


Number : TNUMBER
Name : TWORD
FuncName : Name
ProcName : Name


%%
int main(){
	yyparse();
	return 0;
}
int yywrap() {//return 1 -> parsing stop
	return 1;
}
