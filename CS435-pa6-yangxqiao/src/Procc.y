%{
#include "Node.h"
#include <iostream>
#include <string>
extern int yylex();
extern void yyerror(const char* s);

// Global for the program
NProgram* gProgram = nullptr;

// Disable the warnings that Bison creates
#pragma warning(disable: 4065)
%}

/* You should not need to change the union */
%union {
    Node* node;
	NProgram* program;
	NData* data;
	NDecl* decl;
	NBlock* block;
	NStatement* statement;
	NNumeric* numeric;
	NExpr* expr;
	NComparison* comparison;
	std::string* string;
	int token;
}

%error-verbose
	
/* Tokens/Terminal symbols */
%token <token> TDATA TMAIN TLBRACE TRBRACE TSEMI TLPAREN TRPAREN
%token <token> TLBRACKET TRBRACKET TINC TDEC TEQUALS
%token <token> TADD TSUB TMUL TDIV
%token <token> TLESS TISEQUAL
%token <token> TVAR TARRAY
%token <token> TIF TELSE TWHILE
%token <token> TCOMMA TPENUP TPENDOWN TSETPOS TSETCOLOR TFWD TBACK TROT
%token <string> TINTEGER TIDENTIFIER

/* Types/non-terminal symbols */
%type <program> program
%type <data> data decls
%type <decl> decl
%type <block> main block
%type <numeric> numeric
%type <expr> expr
%type <statement> statement
%type <comparison> comparison

/* Operator precedence */
%left TADD TSUB
%left TMUL TDIV

%%

program		: data main 
				{ 
					std::cout << "Program\n";
					gProgram = new NProgram($1, $2);
				}
;

data		: TDATA TLBRACE TRBRACE
				{
					std::cout << "Data (no decls)\n";
					$$ = new NData();
				}
			| TDATA TLBRACE decls TRBRACE
				{
					std::cout << "Data\n";
					$$ = $3;
				}

;

decls		: decl 
				{
					std::cout << "Single decl\n";
					$$ = new NData();
					$$->AddDecl($1);
				}
			| decls decl
				{
					std::cout << "Multiple decls\n";
					$$->AddDecl($2);
				}
;

decl		: TVAR TIDENTIFIER TSEMI
				{
					std::cout << "Var declaration " << *($2) << '\n';
					$$ = new NVarDecl(*($2));
				}
			| TARRAY TIDENTIFIER TLBRACKET numeric TRBRACKET TSEMI
				{
					std::cout << "Array declaration " << *($2) << '\n';
					$$ = new NArrayDecl(*($2), $4);
				}
;

main		: TMAIN TLBRACE TRBRACE
				{
					std::cout << "Main (no stmts)\n";
					$$ = new NBlock();
				}
			| TMAIN TLBRACE block TRBRACE
				{
					std::cout << "Main with stmts\n";
					$$ = $3;
				}
;


block		:  statement
				{
					std::cout << "Single statements\n";		
					$$ = new NBlock();		
					$$->AddStatement($1);
				}
			|  block statement 
				{
					std::cout << "Multiple statements\n";
					$$->AddStatement($2);
				}
;


statement   : TIDENTIFIER TEQUALS expr TSEMI
				{
					std::cout << "Normal statement with equal sign\n";
					$$ = new NAssignVarStmt(*($1), $3);
				}
			| TIDENTIFIER TLBRACKET expr TRBRACKET TEQUALS expr TSEMI
				{
					std::cout << "Assign value to an array\n";
					$$ = new NAssignArrayStmt(*($1), $3, $6);
				}
			| TINC TIDENTIFIER TSEMI
				{
					std::cout << "Increment\n";
					$$ = new NIncStmt(*($2));
				}
			| TDEC TIDENTIFIER TSEMI
				{
					std::cout << "Decrement\n";
					$$ = new NDecStmt(*($2));
				}
			| TIF comparison TLBRACE block TRBRACE
				{
					std::cout << "if statement without else\n";
					$$ = new NIfStmt($2, $4, nullptr);
				}
			| TIF comparison TLBRACE block TRBRACE TELSE TLBRACE block TRBRACE
				{
					std::cout << "if statement with else\n";
					$$ = new NIfStmt($2, $4, $8);
				}
			| TWHILE comparison TLBRACE block TRBRACE
				{
					std::cout << "while loop\n";
					$$ = new NWhileStmt($2, $4);
				}
			| TPENUP TLPAREN TRPAREN TSEMI
				{
					std::cout << "PENUP\n";
					$$ = new NPenUpStmt();
				}
			| TPENDOWN TLPAREN TRPAREN TSEMI
				{
					std::cout << "PENDOWN\n";
					$$ = new NPenDownStmt();
				}
			| TSETPOS TLPAREN expr TCOMMA expr TRPAREN TSEMI
				{
					std::cout << "SETPOS\n";
					$$ = new NSetPosStmt($3, $5);
				}
			| TSETCOLOR TLPAREN expr TRPAREN TSEMI
				{
					std::cout << "SETCOLOR\n";
					$$ = new NSetColorStmt($3);
				}
			| TFWD TLPAREN expr TRPAREN TSEMI
				{
					std::cout << "FWD\n";
					$$ = new NFwdStmt($3);
				}
			| TBACK TLPAREN expr TRPAREN TSEMI
				{
					std::cout << "BACK\n";
					$$ = new NBackStmt($3);
				}
			| TROT TLPAREN expr TRPAREN TSEMI
				{
					std::cout << "ROT\n";
					$$ = new NRotStmt($3);
				} 
;


comparison  : expr TLESS expr
				{
					std::cout << "One expression is less than the other\n";
					$$ = new NComparison($1, $2, $3);
				}
			| expr TISEQUAL expr
				{
					std::cout << "Two expressions are equal to each other\n";
					$$ = new NComparison($1, $2, $3);
				}
;


expr		: numeric
				{
					std::cout << "Numeric expression\n";
					$$ = new NNumericExpr($1);
				}
			| expr TADD expr
				{
					std::cout << "Addition expression\n";
					$$ = new NBinaryExpr($1, $2, $3);
				}
			| expr TSUB expr
				{
					std::cout << "Substraction expression\n";
					$$ = new NBinaryExpr($1, $2, $3);
				}
			| expr TMUL expr
				{
					std::cout << "Multiplication expression\n";
					$$ = new NBinaryExpr($1, $2, $3);
				}
			| expr TDIV expr
				{
					std::cout << "Division expression\n";
					$$ = new NBinaryExpr($1, $2, $3);
				}
			| TLPAREN expr TRPAREN
				{
					std::cout << "Parenthesis expression\n";
					$$ = $2;
				}
			| TIDENTIFIER
				{
					std::cout << "Just one identifier\n";
					$$ = new NVarExpr(*($1));

				}
			| TIDENTIFIER TLBRACKET expr TRBRACKET
				{
					std::cout << "Access one index of an array\n";
					$$ = new NArrayExpr(*($1), $3);
				}
;

numeric		: TINTEGER
				{
					std::cout << "Numeric value of " << *($1) << '\n';
					$$ = new NNumeric(*($1));
				}
;

%%
