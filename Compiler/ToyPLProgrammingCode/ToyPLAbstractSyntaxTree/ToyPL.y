%{
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char* kind;

	struct node* bro;
	struct node* son;
}node;


node* root;
node* makeNode(node* bro,node* son,char* data){
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->bro = bro;
	newNode->son = son;
	newNode->kind = data;
	return newNode;
}
void printNODE(node* tree){
	printf("%s ",tree->kind);
	if(tree->son) printNODE(tree->son);
	if(tree->bro) printNODE(tree->bro);
}
%}
%union{
	char* CHAR;
	int INT;
	struct node* NODE;
}
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

%type <NODE> Program Name SubPgmList VarDecl CompStmt DclList Decl VarList Type Var SubPgm
%type <NODE> ProcDecl FuncDecl ProcName FuncName FormParam FuncCall
%type <NODE> Stmt AsgnStmt IfStmt WhileStmt ForStmt CallStmt RtrnStmt Expr Cond StmtList Rel Term Fact
%type <NODE> Number ParamList ExprList

%%

Program : TPROGRAM Name ';' SubPgmList TMAIN VarDecl CompStmt '.'{
		$6->bro = $7;
		root->bro = $4;
		root->son = $6;
	}
VarDecl : TVAR DclList ';'{
		$$ = $2;
	}
	|{
		$$ = makeNode(NULL,NULL,"(VARDECL NULL)");
	}
DclList : DclList ';' Decl{
		node* tmp = $1->son;
		while(tmp->bro){
			tmp = tmp->bro;
		}
		tmp->bro = $3;
		$$ = $1;
	}
	| Decl{
		$$ = makeNode(NULL,$1,"VARDECL");
	}
Decl : VarList ':' Type{
		node* tmp = $1;
		while(tmp->bro){
			tmp = tmp->bro;
		}
		tmp->bro = $3;
		$$ = makeNode(NULL,$1,"DECL");
	}
VarList : VarList ',' Var{
		node* tmp = $1;
		while(tmp->bro){
			tmp = tmp->bro;
		}
		tmp->bro = $3;
		$$ = $1;
	}
	| Var{
		$$ = $1;
	}
Type : TINT{
		$$ = makeNode(NULL,NULL,"INT");
	}
     	| TLONG{
		$$ = makeNode(NULL,NULL,"LONG");
	}
Var : Name{
    		$$ = $1;
	}
SubPgmList : SubPgmList SubPgm{
		node* tmp = $1;
		while(tmp->bro){
			tmp = tmp->bro;
		}
		tmp->bro = $2;
		$$ = $1;
	}
	| SubPgm{
		$$ = $1;
	}
	|{
		$$ = makeNode(NULL,NULL,"(SubPgmList NULL)");
	}
SubPgm : ProcDecl{
		$$ = $1;
	}
       	| FuncDecl{
		$$ = $1;
	}
ProcDecl : TPROC ProcName '(' FormParam ')' VarDecl CompStmt{
		$2->bro = $4;
		$4->bro = $6;
		$6->bro = $7;	
		$4 = makeNode(NULL,$2,"PROC");
	}
FuncDecl : TFUNC FuncName '(' FormParam ')' TRETURNS '(' Type ')' VarDecl CompStmt{
		$2->bro = $8;
		$8->bro = $4;
		$4->bro = $10;
		$10->bro = $11;
		$$ = makeNode(NULL,$2,"FUNC");
	}
FormParam : DclList{
	  	$$ = $1;
	}
	|{
		$$ = makeNode(NULL,NULL,"(FormParam NULL)");
	}

Stmt : AsgnStmt{
		$$ = $1;
	}
     	| IfStmt{
		$$ = $1;
	}
	| WhileStmt{
		$$ = $1;
	}
	| ForStmt{
		$$ = $1;
	}
	| CallStmt{
		$$ = $1;
	}
	| RtrnStmt{
		$$ = $1;
	}
	| CompStmt{
		$$ = $1;
	}
AsgnStmt : Var TASS Expr{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"ASGN");
	}
IfStmt : TIF '(' Cond ')' TTHEN Stmt{
		$3->bro = $6;
		$$ = makeNode(NULL,$3,"IF");
	}
       	| TIF '(' Cond ')' TTHEN Stmt TELSE Stmt{
		$3->bro = $6;
		$6->bro = $8;
		$$ = makeNode(NULL,$3,"IF");
	}
WhileStmt : TWHILE '(' Cond ')' Stmt{
		$3->bro = $5;
		$$ = makeNode(NULL,$3,"WHILE");
	}
ForStmt : TFOR '(' Var TASS Expr TTO Expr ')' Stmt{
		$3->bro = $5;
		$5->bro = $7;
		$7->bro = $9;
		$$ = makeNode(NULL,$3,"FOR");
	}
CallStmt : TCALL ProcName '(' ParamList ')'{
		$2->bro = $4;
		$$ = makeNode(NULL,$2,"PCALL");
	}
RtrnStmt : TRETURN '(' Expr ')'{
		$$ = makeNode(NULL,$3,"RETURN");
	}
CompStmt : TBEGIN StmtList TEND{
		$$ = makeNode(NULL,$2,"COMP");
	}
StmtList : StmtList ';' Stmt{
		node* tmp = $1;
		while(tmp->bro){
			tmp = tmp->bro;
		}
		tmp->bro = $3;
		$$ = $1;
	}
	| Stmt{
		$$ = $1;
	}


Cond : Cond TAND Rel{
     		$1->bro = $3;
		$$ = $1;
	}
     	| Cond TOR Rel{
		$1->bro = $3;
		$$ = $1;
	}
	| TNOT Rel{
		$$ = $2;
	}
	| Rel{
		$$ = $1;
	}
Rel : Expr TLT Expr{
    		$1->bro = $3;
		$$ = makeNode(NULL,$1,"LT");
	}
    	| Expr TLE Expr{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"LE");
	}
	| Expr TGT Expr{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"GT");
	}
	| Expr TGE Expr{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"GE");
	}
	| Expr TASS Expr{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"EQ");
	}
	| Expr TNE Expr{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"NE");
	}
Expr : Expr TPLUS Term{
  		$1->bro = $3;
		$$ = makeNode(NULL,$1,"PLUS");
	}
     	| Expr TMINUS Term{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"MINUS");
	}
	| Term{
		$$ = $1;
	}
Term : Term TMUL Fact{
    		$1->bro = $3;
		$$ = makeNode(NULL,$1,"TIMES");
	}
     	| Term TDIV Fact{
		$1->bro = $3;
		$$ = makeNode(NULL,$1,"DIVIDE");
	}
	| Fact{
		$$ = $1;
	}
Fact : Var{
	     	$$ = $1;
	}
     	| Number{
		$$ = $1;
	}
	| FuncCall{
		$$ = $1;
	}
	| TMINUS Fact{
		$$ = $2;
	}
	| '(' Expr ')'{
		$$ = $2;
	}
FuncCall : FuncName '(' ParamList ')'{
	 	$1->bro = $3;
		$$ = makeNode(NULL,$1,"FCALL");
	}
ParamList : ExprList{
	  	$$ = $1;
	}
	|{
		$$ = makeNode(NULL,NULL,"(ParamList NULL)");
	}
ExprList : ExprList ',' Expr{
		node* tmp = $1;
		while(tmp->bro){
			tmp = tmp->bro;
		}
	 	tmp->bro = $3;
		$$ = $1;
	}
	| Expr{
		$$ = $1;
	}


Number : TNUMBER{$$ = makeNode(NULL,NULL,"NUMBER");}
Name : TWORD{$$ = makeNode(NULL,NULL,"NAME");}
FuncName : Name{$$ = $1;}
ProcName : Name{$$ = $1;}


%%


int main(){
	root = makeNode(NULL,NULL,"MAIN");
	yyparse();
	printNODE(root);

	return 0;
}
int yywrap() {//return 1 -> parsing stop
	return 1;
}
