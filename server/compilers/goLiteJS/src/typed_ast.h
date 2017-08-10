#ifndef PRETTY_H
#define PRETTY_H
#include <stdio.h>
#include "tree.h"
#include "string.h"
#include "stdlib.h"
#include "tree.h"
#include "file.h"
FILE *prettyFP;
char *filename;
void prettyPROGRAM(PROGRAM *p);
void prettyPACKAGE(PACK_DECL *pack_decl);
void prettyTOPDECL(TOP_DECL* top_decl);
void prettyVARDECL(VAR_DECL *var_decl, int tabs,int newline);
void prettyTYPEDECL(TYPE_DECL *t,int tabs);
void prettyFUNCTDECL(FUNC_DECL *f);
void prettySTATEMENT(STATEMENT *s, int tabs,int printtabs, int newline,int printcode);
void prettyCASE_CLAUSES(CASE_CLAUSE *c, int tabs);
void prettyIFELSE(IFELSE *ifelse,int tabs);
void prettyIDLIST(IDENTIFIER *id);
void prettyASSIGN_TYPE(ASSIGN_TYPE t);
void prettySTRUCT_FIELDS(STRUCT_DECL *st,int tabs);
void prettyTYPE(TYPE *t, int tabs);
void prettyEXP(EXP *e);
void prettyOP(OP op);
void prettyPARAMETERS(IDENTIFIER *id);
void prettyTABS(int tabs);
void prettyEXPTYPED(EXP *e,int tabs, int newcomment);
void prettyPARAMTYPE(EXP *e);
void prettyPARAMIDTYPED(EXP *params,int tabs);
#endif /* !PRETTY_H */
