%{
	#include <stdio.h>
	#include "your_code.h"

// The parser needs to call the scanner to get the next token 
	extern int yylex();

// The error function 
	extern int yyerror(const char *);

// The ASTNode root
    extern ASTNode* gASTRoot;
%}

//Put any initialization code here 
%initial-action 
{

}

%token LE "<="
%token GE ">="
%token EQ "=="
%token NE "!="
%token OR "||"
%token AND "&&"
%token MAIN "main"
%token INT "int"
%token IF "if"
%token ELSE "else"
%token WHILE "while"

//Define the types for the grammar attributes ($$, $1, $2, ...) 
%union 
{
	ASTNode* node; // Most $$ values will be ASTNodes 
	int num; // Integer numbers
	char* string; // Strings for identifiers 
}

//Specify the type for each token. Only needed for IDENT and NUM, because they are the only ones that have actual regexp rules
%token <string> IDENT
%token <num> NUM

//Specify the type for each non-terminal in the grammar. Here are some samples:
%type <node> Statement
%type <node> Assignment
%type <node> Expr
%type <node> Term
%type <node> Factor

// Add the rest of the types for the grammar's symbols
%type <node> Goal
%type <node> StatementList
%type <node> Declaration
%type <node> LHS

%%



// Write the grammar for BabyC, and write an embedded action for each production. Here are some samples for you:

Goal: "main" '(' ')' '{' DeclarationList StatementList '}'	{gASTRoot=$6;} // Store the AST root node in gASTRoot
;
//{$$ = NULL;}  {$$ = CreateDeclarationListNode($1,$2); printf("Adding a declaration to a declaration list \n");}
DeclarationList: | Declaration DeclarationList
;

Declaration: "int" IDENT ';' {AddDeclaration($2); printf("Processing declaration of %s\n", $2);}
;



StatementList: {$$ = NULL;} 
               | Statement StatementList {$$ = CreateStatementListNode($1,$2); printf("Adding a Statement to a Statement list \n");}
;

Statement: Assignment {$$ = $1;}
	     //| IF {$$ = $1;}
	     //| WHILE {$$ = $1;}
;

Assignment: LHS '=' Expr ';' {$$ = CreateAssignmentNode($1, $3); printf("Creating Assignment node\n");}
;

LHS: IDENT {$$ = CreateIdentNode($1); printf("Creating left-hand IDENT node for %s\n", $1);}

Expr: Term {$$ = $1}
	| Expr '+' Term {$$ = CreateAddNode($1, $3); printf("Creating Addition node\n");}
	| Expr '-' Term {$$ = CreateSubtractNode($1, $3); printf("Creating Subtraction node\n");}
;

Term: Factor {$$ = $1}
	| Term '*' Factor {$$ = CreateMultNode($1, $3); printf("Creating Multiplication node\n");}
	| Term '/' Factor {$$ = CreateDivideNode($1, $3); printf("Creating Division node\n");}
;

Factor: IDENT 		{$$ = CreateIdentNode($1); printf("Creating IDENT node for %s\n", $1);}
		| NUM 		{$$ = CreateNumNode($1); printf("Creating NUM node for %d\n", $1);}
		| '('Expr')'	{$$ = $2; printf("Creating Expression node in parentheses\n")}
;


%%
