#ifndef CODE_H
#define CODE_H
#include <stdio.h>
#include "tree.h"
#include "string.h"
#include "stdlib.h"
#include "tree.h"
#include "file.h"
#include "type.h"
#include "symbol.h"
FILE *codeFP;
char *filename;
void codePROGRAM(PROGRAM *p);
void codePACKAGE(PACK_DECL *pack_decl);
void codeTOPDECL(TOP_DECL* top_decl);
void codeVARDECL(VAR_DECL *v,int tabs);
void codeVARDECLvartemp(IDENTIFIER *id, EXP *e, int tabs);
void codeVARDECLexp(IDENTIFIER *id,EXP *e, int tabs);
void codeVARDECLsimple(IDENTIFIER *id, int tabs);
void codeFUNCTDECL(FUNC_DECL *f);
void codeSTATEMENT(STATEMENT *s, int tabs);
void codeSHORTDECL(IDENTIFIER *id, EXP *e, int tabs);
void codeDECLtempvar(IDENTIFIER *id, EXP *e, int tabs);
void codeDECLlet(IDENTIFIER *id, EXP *e, int tabs);
void codeASSIGN(EXP *left, EXP*right,ASSIGN_TYPE t,int tabs);
void codeASSIGNvartemp(EXP *left, EXP *right,ASSIGN_TYPE t, int countTemp,int tabs);
void codeASSIGNexp(EXP *left,EXP *right,ASSIGN_TYPE t, int countTemp, int tabs);
void codeCASE_CLAUSES(CASE_CLAUSE *c, int tabs);
void codeIFELSE(IFELSE *ifelse,int tabs);
void codeIDLIST(IDENTIFIER *id);
void codeASSIGN_TYPE(ASSIGN_TYPE t);
void codeEXP(EXP *e, int isLHS);
void codeOP(OP op);
void codePARAMETERS(IDENTIFIER *id);
void codeTABS(int tabs);
void initializeType(TYPE *t);
void initializeSTRUCTtype(STRUCT_DECL *struct_decl);
void initializeSTRUCTfields(IDENTIFIER *id);
void copyUtilCode();
void codePREDIFINEDLibrary();
void checkFunctionCasting(EXP *e);
void codeBinary(EXP *left, EXP *right, OP op);
void codeUnary(EXP *e, OP op, int isLHS);
void remove_newline();
#endif /* !CODE_H */
