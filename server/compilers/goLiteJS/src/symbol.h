#ifndef SYMBOL_H
#define SYMBOL_H
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#define HashSize 1024
int dumpsymtab;

typedef struct SymbolTable {
    SYMBOL *table[HashSize];
    struct SymbolTable *next;
} SymbolTable;

SymbolTable *packagelib;
int Hash(char *str);
SymbolTable *initSymbolTable();
SymbolTable *scopeSymbolTable(SymbolTable *s);
SYMBOL *putSymbol(SymbolTable *t, char *name, SymbolKind kind);
SYMBOL *getSymbol(SymbolTable *t, char *name);
int defSymbol(SymbolTable *t, char *name);
int defType(TYPE *t,SymbolTable *sym);
TYPE *getDefinedType(TYPE *type, SymbolTable *symTable);
int defSTRUCT_FIELDS(STRUCT_DECL *st, SymbolTable *sym, SymbolTable *top);
int symSTRUCTIDS(IDENTIFIER *i, SymbolTable *sym, SymbolTable *top, int lineno);
void symPROGRAM(PROGRAM *p);
void symPredeclaredMappings(SymbolTable *lib);
void symTOPDECL(TOP_DECL *t,SymbolTable *lib);
void symFUNCDECL(FUNC_DECL *f, SymbolTable *sym);
void symVARDECL(VAR_DECL *v, SymbolTable *sym);
void symTYPEDECL(TYPE_DECL *t, SymbolTable *sym);
void symIDLIST(IDENTIFIER *i, SymbolTable *sym, int lineno);
void symFORMAL(SymbolTable *sym, IDENTIFIER *params, FUNC_DECL *f);
void symSTATEMENTS(SymbolTable *sym,STATEMENT *s, FUNC_DECL *f);
void symSHORTDECL(IDENTIFIER *ids,SymbolTable *sym, int lineno);
void symEXP(EXP *e, SymbolTable *sym);
void symEXPID(IDENTIFIER *i, SymbolTable *sym, int lineno);
void symIFELSEstmt(SymbolTable *sym, IFELSE *ifelse,FUNC_DECL *f);
void symSWITCHstmt(SymbolTable *sym, SWITCH_STMT *sw,FUNC_DECL *f);
void symCASECLAUSE(SymbolTable *sym, CASE_CLAUSE *cs, FUNC_DECL *f);
void symFORstmt(SymbolTable *sym, FOR_STMT *forstmt, FUNC_DECL *f);
#endif /* !SYMBOL_H */
