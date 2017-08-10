%{
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
extern PROGRAM *program;
int yylex();
extern int yylineno;

%}

%union {
  int intconst;
  float floatconst;
  char *runeconst;
  char *stringconst;
  PACK_DECL *packdecl;
  TYPE *type;
  STRUCT_DECL *structdecl;
  IDENTIFIER *id;
  EXP *exp;
  FOR_STMT *forstmt;
  STATEMENT *stmt;
  BLOCK *block;
  SWITCH_STMT *switchstmt;
  CASE_CLAUSE *caseclause;
  IFELSE *ifelse;
  FUNC_DECL *funcdecl;
  TYPE_DECL *typedecl;
  VAR_DECL *vardecl;
  TOP_DECL *topdecl;
};

/* keywords */
%token tAPPEND tBREAK tCASE tCHAN tCONST tCONTINUE tDEFAULT tDEFER
       tELSE tFALLTHROUGH tFOR tFUNC tGO tGOTO tIF tIMPORT
       tINTERFACE tMAP tPACKAGE tPRINT tPRINTLN tRANGE tRETURN tSELECT
       tSTRUCT tSWITCH tTYPE tVAR

/* operators */
%token tEQUAL tLEQ tGEQ tNEQ tAND tOR tINC tDEC tLSHIFT tRSHIFT
       tLSHIFTEQ tRSHIFTEQ tDECLANDASSIGN tDOTS tRECEIVE tPLUSEQ
       tANDEQ tMINUSEQ tOREQ tMULTEQ tXOREQ tDIVEQ tMODEQ tBITCLEAR tCLEAREQ

%token <intconst> tDECCONST tOCTCONST tHEXCONST
%token <floatconst> tFLOATCONST
%token <runeconst> tRUNECONST
%token <stringconst> tSTRINGCONST tRAWSTRINGCONST tIDENTIFIER

%left tOR
%left tAND
%left tEQUAL tNEQ '<' tLEQ '>' tGEQ
%left '+' '-' '|' '^'
%left '*' '/' '%' tLSHIFT tRSHIFT '&' tBITCLEAR
%left UNARY
%left '.' '[' '('

%type <type> type
%type <structdecl> structfields structfield
%type <intconst> intconst
%type <packdecl> package
%type <id> id ids nonblankids parameter parameters
%type <exp> appendexpr expression binaryexpr unaryexpr litexpr leftexpr leftexprs expressions functioncallexpr
%type <forstmt> forstmt
%type <stmt> simplestatement simplepoststatement statements statement printstmt returnstmt assignmentstmt incrementdecrementstmt shortassignmentstmt expressionstmt
%type <block> block
%type <caseclause> caseclause caseclauses
%type <switchstmt> switchstmt
%type <ifelse> ifstmt
%type <funcdecl> functiondecl
%type <typedecl> typedecl typespecs typespec
%type <vardecl> vardecl varspecs varspec
%type <topdecl> topleveldecls topleveldecl

%%

program: package ';' topleveldecls { program = makePROGRAM($1, $3, @3.last_line); }
  | package ';' topleveldecls ';' { program = makePROGRAM($1, $3, @3.last_line); }
  ;

package: tPACKAGE tIDENTIFIER { $$ = makePACK_DECL($2, @2.first_line); }
  ;

topleveldecls: %empty { $$ = NULL; }
  | topleveldecls topleveldecl ';' { $$ = $2; $$->next = $1; }
  ;

topleveldecl: vardecl { $$ = makeTOPDECLvar($1); }
  | typedecl { $$ = makeTOPDECLtype($1); }
  | functiondecl { $$ = makeTOPDECLfunc($1); }
  ;

vardecl: tVAR varspec { $$ = $2; }
  | tVAR '(' varspecs ')' { $$ = $3; }
  ;

varspecs: %empty { $$ = NULL; }
  | varspecs varspec ';' { $$ = $2; $$->next = $1; }
  ;

varspec: ids type { $$ = makeDECLvar($1, $2, NULL,@1.first_line); }
  | ids type '=' expressions { $$ = makeDECLvar($1, $2, $4,@1.first_line); }
  | ids '=' expressions { $$ = makeDECLvar($1, NULL, $3,@1.first_line); }
  ;

typedecl: tTYPE typespec { $$ = $2; }
  | tTYPE '(' typespecs ')' { $$ = $3; }
  ;

typespecs: %empty { $$ = NULL; }
  | typespecs typespec ';' { $$ = $2; $$->next = $1; }
  ;

typespec: tIDENTIFIER type { $$ = makeDECLtype($1, $2,@1.first_line); }
  ;

functiondecl: tFUNC tIDENTIFIER '(' parameters ')' type block { $$ = makeDECLfunc($2, $4, $6, $7, @2.first_line); }
  | tFUNC tIDENTIFIER '(' parameters ')' block { $$ = makeDECLfunc($2, $4, NULL, $6,@2.first_line); }
  ;

parameters: %empty { $$ = NULL; }
  | parameter
  | parameters ',' parameter { $$ = $3; while ($3->next) $3 = $3->next; $3->next = $1; }
  ;

parameter: ids type { $$ = $1; assignIDTYPE($$, $2); }
  ;

ids: id
  | ids ',' id { $$ = $3; $$->next = $1; }
  ;

id: tIDENTIFIER { $$ = makeID($1, NULL); }
  | '_' { $$ = makeID("_", NULL); }
  ;

nonblankids: tIDENTIFIER { $$ = makeID($1, NULL); }
  | nonblankids ',' tIDENTIFIER { $$ = makeID($3, NULL); $$->next = $1; }
  ;

statements: %empty { $$ = NULL; }
  | statements ';'
  | statements statement { $$ = $2; $$->next = $1; }
  ;

statement: simplestatement ';'
  | vardecl ';' { $$ = makeSTATEMENTvardecl($1,@1.first_line); }
  | typedecl ';' { $$ = makeSTATEMENTtypedecl($1,@1.first_line); }
  | printstmt ';'
  | returnstmt ';'
  | ifstmt ';' { $$ = makeSTATEMENTifelse($1,@1.first_line); }
  | switchstmt ';' { $$ = makeSTATEMENTswitch($1, @1.first_line); }
  | forstmt ';' { $$ = makeSTATEMENTfor($1,@1.first_line); }
  | block ';' { $$ = makeSTATEMENTblock($1,@1.first_line); }
  | tCONTINUE ';' { $$ = makeSTATEMENTcontinue(@1.first_line); }
  | tBREAK ';' { $$ = makeSTATEMENTbreak(@1.first_line); }
  ;

simplestatement: simplepoststatement
  | shortassignmentstmt
  | expressionstmt
  ;

simplepoststatement: incrementdecrementstmt
  | assignmentstmt
  ;

assignmentstmt: leftexprs '=' expressions { $$ = makeSTATEMENTassign($1, $3, EQ,@2.first_line); }
  | leftexpr tLSHIFTEQ expression { $$ = makeSTATEMENTassign($1, $3, LSHIFTEQ,@2.first_line); }
  | leftexpr tRSHIFTEQ expression { $$ = makeSTATEMENTassign($1, $3, RSHIFTEQ,@2.first_line); }
  | leftexpr tPLUSEQ expression { $$ = makeSTATEMENTassign($1, $3, PLUSEQ,@2.first_line); }
  | leftexpr tANDEQ expression { $$ = makeSTATEMENTassign($1, $3, ANDEQ,@2.first_line); }
  | leftexpr tMINUSEQ expression { $$ = makeSTATEMENTassign($1, $3, MINUSEQ,@2.first_line); }
  | leftexpr tOREQ expression { $$ = makeSTATEMENTassign($1, $3, OREQ,@2.first_line); }
  | leftexpr tMULTEQ expression { $$ = makeSTATEMENTassign($1, $3, MULTEQ,@2.first_line); }
  | leftexpr tXOREQ expression { $$ = makeSTATEMENTassign($1, $3, XOREQ,@2.first_line); }
  | leftexpr tDIVEQ expression { $$ = makeSTATEMENTassign($1, $3, DIVEQ,@2.first_line); }
  | leftexpr tMODEQ expression { $$ = makeSTATEMENTassign($1, $3, MODEQ,@2.first_line); }
  | leftexpr tCLEAREQ expression { $$ = makeSTATEMENTassign($1, $3, CLEAREQ,@2.first_line); }
  ;

shortassignmentstmt: leftexprs tDECLANDASSIGN expressions { $$ = makeSTATEMENTshortassign($1, $3,@2.first_line); }
  ;

incrementdecrementstmt: leftexpr tINC { $$ = makeSTATEMENTassign($1, NULL, INC, @2.first_line); }
  | leftexpr tDEC { $$ = makeSTATEMENTassign($1, NULL, DEC,@2.first_line); }
  ;

printstmt: tPRINT '(' expressions ')' { $$ = makeSTATEMENTprint($3, 0,@3.first_line); }
  | tPRINTLN '(' expressions ')' { $$ = makeSTATEMENTprint($3, 1,@3.first_line); }
  | tPRINT '(' ')' { $$ = makeSTATEMENTprint(NULL, 0,@1.first_line); }
  | tPRINTLN '(' ')' { $$ = makeSTATEMENTprint(NULL, 1,@1.first_line); }
  ;

returnstmt: tRETURN { $$ = makeSTATEMENTreturn(NULL,@1.first_line); }
  | tRETURN expression { $$ = makeSTATEMENTreturn($2,@2.first_line); }
  ;

ifstmt: tIF simplestatement ';' expression block { $$ = makeIFELSE($2, $4, $5, NULL, NULL, @1.first_line, @5.last_line); }
  | tIF ';' expression block { $$ = makeIFELSE(NULL, $3, $4, NULL, NULL, @1.first_line, @4.last_line); }
  | tIF expression block { $$ = makeIFELSE(NULL, $2, $3, NULL, NULL, @1.first_line, @3.last_line); }
  | tIF simplestatement ';' expression block tELSE ifstmt { $$ = makeIFELSE($2, $4, $5, NULL, $7, @1.first_line, @7.last_line); }
  | tIF ';' expression block tELSE ifstmt { $$ = makeIFELSE(NULL, $3, $4, NULL, $6, @1.first_line, @6.last_line); }
  | tIF expression block tELSE ifstmt { $$ = makeIFELSE(NULL, $2, $3, NULL, $5, @1.first_line, @5.last_line); }
  | tIF simplestatement ';' expression block tELSE block { $$ = makeIFELSE($2, $4, $5, $7, NULL, @1.first_line, @7.last_line); }
  | tIF ';' expression block tELSE block { $$ = makeIFELSE(NULL, $3, $4, $6, NULL, @1.first_line, @6.last_line); }
  | tIF expression block tELSE block { $$ = makeIFELSE(NULL, $2, $3, $5, NULL, @1.first_line, @5.last_line); }
  ;

switchstmt: tSWITCH simplestatement ';' expression '{' caseclauses '}' { $$ = makeSWITCH($2, $4, $6, @7.last_line); }
  | tSWITCH ';' expression '{' caseclauses '}' { $$ = makeSWITCH(NULL, $3, $5, @6.last_line); }
  | tSWITCH expression '{' caseclauses '}' { $$ = makeSWITCH(NULL, $2, $4, @5.last_line); }
  | tSWITCH simplestatement ';' '{' caseclauses '}' { $$ = makeSWITCH($2, NULL, $5, @6.last_line); }
  | tSWITCH ';' '{' caseclauses '}' { $$ = makeSWITCH(NULL, NULL, $4, @5.last_line); }
  | tSWITCH '{' caseclauses '}' { $$ = makeSWITCH(NULL, NULL, $3, @4.last_line); }
  ;

caseclauses: %empty { $$ = NULL; }
  | caseclauses caseclause { $$ = $2; $$->next = $1; }
  ;

caseclause: tCASE expressions ':' statements { $$ = makeCASE($4, $2,@1.first_line, @4.last_line); }
  | tDEFAULT ':' statements { $$ = makeCASE($3, NULL,@1.first_line, @3.last_line); }
  ;

forstmt: tFOR block { $$ = makeFORSTMT(NULL, NULL, NULL, $2,@1.first_line, @2.last_line); }
  | tFOR expression block { $$ = makeFORSTMT($2, NULL, NULL, $3,@2.first_line, @3.last_line); }
  | tFOR simplestatement ';' expression ';' simplepoststatement block { $$ = makeFORSTMT($4, $2, $6, $7,@1.first_line, @7.last_line); }
  | tFOR ';' expression ';' simplepoststatement block { $$ = makeFORSTMT($3, NULL, $5, $6,@2.first_line, @6.last_line); }
  | tFOR simplestatement ';' ';' simplepoststatement block { $$ = makeFORSTMT(NULL, $2, $5, $6,@1.first_line, @6.last_line); }
  | tFOR simplestatement ';' expression ';' block { $$ = makeFORSTMT($4, $2, NULL, $6,@1.first_line, @6.last_line); }
  | tFOR ';' ';' simplepoststatement block { $$ = makeFORSTMT(NULL, NULL, $4, $5,@1.first_line, @5.last_line); }
  | tFOR simplestatement ';' ';' block { $$ = makeFORSTMT(NULL, $2, NULL, $5,@1.first_line, @5.last_line); }
  | tFOR ';' expression ';' block { $$ = makeFORSTMT($3, NULL, NULL, $5,@3.first_line, @5.last_line); }
  | tFOR ';' ';' block { $$ = makeFORSTMT(NULL, NULL, NULL, $4,@4.first_line, @4.last_line); }
  | tFOR simplestatement ';' expression ';' expressionstmt block { $$ = makeFORSTMT($4, $2, $6, $7,@4.first_line, @7.last_line); }
  | tFOR ';' expression ';' expressionstmt block { $$ = makeFORSTMT($3, NULL, $5, $6,@3.first_line, @6.last_line); }
  | tFOR simplestatement ';' ';' expressionstmt block { $$ = makeFORSTMT(NULL, $2, $5, $6,@2.first_line, @6.last_line); }
  | tFOR ';' ';' expressionstmt block { $$ = makeFORSTMT(NULL, NULL, $4, $5,@1.first_line, @5.last_line); }
  ;

expressions: expression
  | expressions ',' expression { $$ = $3; $$->next = $1; }
  ;

expression: expressionstmt { $$ = $1->val.expS.exp; }
  | leftexpr
  | litexpr
  | unaryexpr
  | binaryexpr
  | appendexpr
  ;

expressionstmt: '(' expressionstmt ')' { $$ = $2; }
  | functioncallexpr { $$ = makeSTATEMENTexp($1,@1.first_line); }
  ;

leftexprs: leftexpr
  | '_' { $$ = makeEXPid("_",@1.first_line); }
  | leftexprs ',' leftexpr { $$ = $3; $$->next = $1; }
  | leftexprs ',' '_' { $$ = makeEXPid("_",@1.first_line); $$->next = $1; }
  ;

leftexpr: '(' leftexpr ')' { $$ = makeEXPparen($2,@2.first_line); }
  | tIDENTIFIER { $$ = makeEXPid($1,@1.first_line); }
  | expression '.' tIDENTIFIER { $$ = makeEXPstructfield($1, $3,@2.first_line); }
  | expression '[' expression ']' { $$ = makeEXParrayaccess($1, $3,@3.first_line); }
  ;

litexpr: '(' litexpr ')' { $$ = makeEXPparen($2,@2.first_line); }
  | intconst { $$ = makeEXPint($1, @1.first_line); }
  | tFLOATCONST { $$ = makeEXPfloat($1,@1.first_line); }
  | tRUNECONST { $$ = makeEXPrune($1,@1.first_line); }
  | tSTRINGCONST { $$ = makeEXPstring($1,@1.first_line); }
  | tRAWSTRINGCONST { $$ = makeEXPrawstring($1,@1.first_line); }
  ;

intconst: tDECCONST
  | tOCTCONST
  | tHEXCONST
  ;

unaryexpr: '(' unaryexpr ')' { $$ = makeEXPparen($2,@2.first_line); }
  | '+' expression %prec UNARY { $$ = makeEXPunary($2, PLUS,@1.first_line); }
  | '-' expression %prec UNARY { $$ = makeEXPunary($2, MINUS,@1.first_line); }
  | '!' expression %prec UNARY { $$ = makeEXPunary($2, NOT,@1.first_line); }
  | '^' expression %prec UNARY { $$ = makeEXPunary($2, XOR,@1.first_line); }
  ;

binaryexpr: '(' binaryexpr ')' { $$ = makeEXPparen($2,@2.first_line); }
  | expression '+' expression { $$ = makeEXPbinary($1, $3, PLUS,@2.first_line); }
  | expression '-' expression { $$ = makeEXPbinary($1, $3, MINUS,@2.first_line); }
  | expression '|' expression { $$ = makeEXPbinary($1, $3, BITOR,@2.first_line); }
  | expression '^' expression { $$ = makeEXPbinary($1, $3, XOR,@2.first_line); }
  | expression '*' expression { $$ = makeEXPbinary($1, $3, MULT,@2.first_line); }
  | expression '/' expression { $$ = makeEXPbinary($1, $3, DIV,@2.first_line); }
  | expression '%' expression { $$ = makeEXPbinary($1, $3, MOD,@2.first_line); }
  | expression tLSHIFT expression { $$ = makeEXPbinary($1, $3, LSHIFT,@2.first_line); }
  | expression tRSHIFT expression { $$ = makeEXPbinary($1, $3, RSHIFT,@2.first_line); }
  | expression '&' expression { $$ = makeEXPbinary($1, $3, BITAND,@2.first_line); }
  | expression tBITCLEAR expression { $$ = makeEXPbinary($1, $3, BITCLEAR,@2.first_line); }
  | expression tEQUAL expression { $$ = makeEXPbinary($1, $3, EQUAL,@2.first_line); }
  | expression tNEQ expression { $$ = makeEXPbinary($1, $3, NEQ,@2.first_line); }
  | expression '<' expression { $$ = makeEXPbinary($1, $3, LT,@2.first_line); }
  | expression tLEQ expression { $$ = makeEXPbinary($1, $3, LEQ,@2.first_line); }
  | expression '>' expression { $$ = makeEXPbinary($1, $3, GT,@2.first_line); }
  | expression tGEQ expression { $$ = makeEXPbinary($1, $3, GEQ,@2.first_line); }
  | expression tAND expression { $$ = makeEXPbinary($1, $3, AND,@2.first_line); }
  | expression tOR expression { $$ = makeEXPbinary($1, $3, OR,@2.first_line); }
  ;

functioncallexpr: expression '(' expressions ')' { $$ = makeEXPfunc($1, $3,@1.first_line); }
  | expression '(' ')' { $$ = makeEXPfunc($1, NULL, @1.first_line); }
  ;

appendexpr: '(' appendexpr ')' { $$ = makeEXPparen($2,@2.first_line); }
  | tAPPEND '(' expression ',' expression ')' { $$ = makeEXPappend($3, $5,@1.first_line); }
  ;

type: '(' type ')' { $$ = makeTYPEparen($2); }
  | tIDENTIFIER { $$ = makeTYPEid($1); }
  | '['']' type { $$ = makeTYPEslice($3); }
  | '[' intconst ']' type { $$ = makeTYPEarray($2, $4); }
  | tSTRUCT '{' structfields '}' { $$ = makeTYPEstruct($3); }
  ;

structfields: %empty { $$ = NULL; }
  | structfields structfield ';' { $$ = $2; $$->next = $1; }
  ;

structfield: nonblankids type { $$ = makeDECLstruct($1, $2, @1.first_line); }
  ;

block: '{' statements '}' { $$ = makeBLOCK($2, @2.first_line, @2.last_line); }
  ;

%%
