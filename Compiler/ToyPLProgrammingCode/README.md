# ToyPL 문법

## 실행문을 위한 문법
- 프로그래밍 언어에서의 실행문
<Stmt> ::= <AsgnStmt> | <IfStmt> | <WhileStmt> | <ForStmt> | <CallStmt> | <RtrnStmt> | <CompStmt>
<AsgnStmt> ::= <Var> = <Expr>
<IfStmt> ::= if ( <Cond> ) then <Stmt> | if ( <Cond> ) then <Stmt> else <Stmt>
<WhileStmt> ::= while ( <Cond> ) <Stmt>
<ForStmt> ::= for ( <Var> = <Expr> to <Expr> ) <Stmt>
<CallStmt> ::= call <ProcName> ( <ParamList> )
<RtrnStmt> ::= return ( <Expr> )
<CompStmt> ::= begin <StmtList> end
<StmtList> ::= <StmtList> ; <Stmt> | <Stmt>

## 식을 위한 문법
- 프로그래밍 언어에서의 조건식과 수식
<Cond> ::= <Cond> & <Rel> | <Cond> ‘|’ <Rel> | ! <Rel> | <Rel>
<Rel> ::= <Expr> < <Expr> | <Expr> <= <Expr> | <Expr> > <Expr> | <Expr> >= <Expr> | <Expr> = <Expr> | <Expr> != <Expr>
<Expr> ::= <Expr> + <Term> | <Expr> - <Term> | <Term>
<Term> ::= <Term> * <Fact> | <Term> / <Fact> | <Fact>
<Fact> ::= <Var> | <Number> | <FuncCall> | - <Fact> | ( <Expr> )
<FuncCall> ::= <FuncName> ( <ParamList> )
<ParamList> ::= <ExprList> | 
<ExprList> ::= <ExprList> , <Expr> | <Expr>

## ToyPL 언어의 문법
<Program> ::= program <Name> ; <SubPgmList> main <VarDecl> <CompStmt> .
<VarDecl> ::= var <DclList> ; | 
<DclList> ::= <DclList> ; <Decl> | <Decl>
<Decl> ::= <VarList> : <Type>
<VarList> ::= <VarList> , <Var> | <Var>
<Type> ::= int | long
<Var> ::= <Name>
<SubPgmList> ::= <SubPgmList> <SubPgm> |
<SubPgm> ::= <ProcDecl> | <FuncDecl>
<ProcDecl> ::= proc <ProcName> ( <FormParam> ) <VarDecl> <CompStmt>
<FuncDecl> ::= func <FuncName> ( <FormParam> ) returns ( <Type> ) <VarDecl> <CompStmt>
<FormParam> ::= <DclList> |

## 구성요소의 의미
- 형식매개변수(<FormParam>)는 다시 선언될 필요 없음
- 함수선언에서 returns는 반환 값의 형임
- return 문은 함수선언에서만 필요
- 프로그램의 실행은 main부터 시작
- int는 4-byte, long는 8-byte의 정수
- <IfStmt>는 모호


## ToyPL 언어의 어휘
- 키워드
	- program, main, proc, func, returns, var, int, long, if, then, else, while, for, to, call, return, begin, end
- 연산자 및 구분자
	- 연산자: = & | ! < <= > >= != + - * /
	- 구분자: ; : ( ) , .
- 이름과 숫자
	- 이름: 영문자로 시작, 영문자와 숫자가 이어짐
	- 숫자: 정수의 10진수 표기
- 주석
	- /*와 */ 사이의 모든 문자열

