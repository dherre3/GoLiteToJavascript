#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "memory.h"
#include "error.h"
typedef enum{typeSym, varSym, funcSym, formalSym} SymbolKind;

typedef struct SYMBOL {
    char *name;
    SymbolKind kind;
    union{
        struct FUNC_DECL *funcS;
        struct IDENTIFIER *formalS;
        struct IDENTIFIER *varS;
        struct TYPE *typeS;
    }val;
    struct SYMBOL *next;
} SYMBOL;

typedef enum OP {
    PLUS,
    MINUS,
    BITOR,
    XOR,
    MULT,
    DIV,
    MOD,
    LSHIFT,
    RSHIFT,
    BITAND,
    BITCLEAR,
    EQUAL,
    NEQ,
    LT,
    LEQ,
    GT,
    GEQ,
    AND,
    OR,
    NOT
} OP;

typedef enum ASSIGN_TYPE {
    LSHIFTEQ,
    RSHIFTEQ,
    PLUSEQ,
    ANDEQ,
    MINUSEQ,
    OREQ,
    MULTEQ,
    XOREQ,
    DIVEQ,
    MODEQ,
    CLEAREQ,
    INC,
    DEC,
    EQ
} ASSIGN_TYPE;

typedef struct PROGRAM {
    struct PACK_DECL *pack_decl;
    struct TOP_DECL *top_decl;
    struct SymbolTable *sym;
    int lastlineno;
} PROGRAM;

typedef struct PACK_DECL {
    int lineno;
    char *pack_name;
}PACK_DECL;

typedef struct TOP_DECL {
    struct TOP_DECL *next;
    enum {varK, functionK, typeK} kind;
    union{
        struct VAR_DECL *var_decl;
        struct FUNC_DECL *func_decl;
        struct TYPE_DECL *type_decl; 
    } val;
} TOP_DECL;

typedef struct VAR_DECL {
    int lineno;
    struct IDENTIFIER *ids;
    struct TYPE *type;
    struct EXP *expressions;
    struct VAR_DECL *next;
} VAR_DECL;

typedef struct TYPE_DECL {
    int lineno;
    struct IDENTIFIER *id;
    struct TYPE *type;
    struct TYPE_DECL *next;
} TYPE_DECL;

typedef struct FUNC_DECL {
    int lineno;
    struct SYMBOL *sym;
    struct IDENTIFIER *id;
    struct IDENTIFIER *params;
    struct BLOCK *block;
    struct TYPE *returntype;
} FUNC_DECL;

typedef struct IDENTIFIER {
    char *name;
    struct SYMBOL *sym;
    struct IDENTIFIER *next;
    struct TYPE *type;
    int is_blank;
    int is_defined_in_scope;
    int decl_count;
} IDENTIFIER;

typedef struct EXP {
    int lineno;
    struct EXP *next;
    enum {
        idK, intconstK, floatconstK, stringconstK,
        runeconstK, rawstringconstK, funcK, structfieldK,
        arrayaccessK, appendK, binaryK, unaryK, parenK
    } kind;
    union {
        struct { struct IDENTIFIER *id; } idE;
        struct { struct EXP *func; struct EXP *params; int is_typecast; } funcE;
        struct { struct EXP *structval; struct IDENTIFIER *field; } structfieldE;
        struct { struct EXP *arrayval; struct EXP *index; } arrayaccessE;
        struct { struct EXP *left; struct EXP *right; OP op; } binaryE;
        struct { struct EXP *exp; OP op; } unaryE;
        struct { struct EXP *left; struct EXP *right; } appendE;
        struct { struct EXP *exp; } parenE;

        int intconstE;
        float floatconstE;
        char *runeconstE;
        char *stringconstE;
        char *rawstringconstE;
    } val;

    struct TYPE *type;
} EXP;

typedef struct TYPE {
    int lineno;
    enum {idTK, arrayK, structK, sliceK, parentK, intK,boolK,floatK,runeK,stringK} typeK;
    union {
        struct { int array_length; struct TYPE *array_type; } arrayT;
        struct { struct STRUCT_DECL *struct_decl;struct SymbolTable *localsym;} structT;
        struct { struct TYPE *slice_type; } sliceT;
        struct { char *name; struct TYPE *actual_type; } idT;
        struct { struct TYPE *type; } parenT;
    } val;
} TYPE;

typedef struct STRUCT_DECL {
    int lineno;
    struct IDENTIFIER *ids;
    struct TYPE *type;
    struct STRUCT_DECL *next;
} STRUCT_DECL;

typedef struct STATEMENT {
    int lineno;
    enum {
        vardeclK, typedeclK, shortassignK, expK,
        assignK, printK, returnK, ifelseK, switchK,
        forK, blockK, continueK, breakK
    } kind;
    struct STATEMENT *next;
    union {
        struct { struct IDENTIFIER *ids; EXP *expressions; } shortassignS;
        struct { EXP *exp; } expS;
        struct { struct ASSIGN *assignment; } assignS; // includes increment and decrement
        struct { VAR_DECL *vardecl; } vardeclS;
        struct { TYPE_DECL *typedecl; } typedeclS;
        struct { int newline; EXP *expressions; } printS;
        struct { struct EXP *expression; } returnS;
        struct { struct IFELSE *ifelse; } ifelseS;
        struct { struct SWITCH_STMT *switchstmt; } switchS;
        struct { struct FOR_STMT *forstmt; } forS;
        struct { struct BLOCK *block; } blockS;
    } val;
} STATEMENT;

typedef struct ASSIGN {
    EXP *left;
    EXP *right;
    /*SYMBOL *sym;*/
    ASSIGN_TYPE assigntype;
} ASSIGN;

typedef struct IFELSE {
    int lineno;
    int lastlineno;
    struct STATEMENT *simplestmt;
    struct EXP *condition;
    struct BLOCK *trueblock;
    struct BLOCK *falseblock;
    struct IFELSE *elseif; // oops, idk why i called it elseif
    struct SymbolTable *symtable;
} IFELSE;

typedef struct SWITCH_STMT {
    int lastlineno;
    struct STATEMENT *simplestmt; 
    struct EXP *expression;
    struct CASE_CLAUSE *caseclauses;
    struct SymbolTable *symtable;
} SWITCH_STMT;

typedef struct CASE_CLAUSE {
    struct CASE_CLAUSE *next;
    int lineno;
    EXP *expressions; // NULL means this is a default clause
    struct BLOCK *block;
    //STATEMENT *statements;
} CASE_CLAUSE;

typedef struct FOR_STMT {
    int lineno;
    int lastlineno;
    struct EXP *expression;
    struct STATEMENT *simplestmt;
    struct STATEMENT *poststmt;
    struct BLOCK *block;
    struct SymbolTable *symtable;
} FOR_STMT;

typedef struct BLOCK {
    struct SymbolTable *localsym;
    STATEMENT *statements;
    int lineno;
    int lastlineno;
} BLOCK;

TYPE BASE_TYPE_INT;
TYPE BASE_TYPE_FLOAT;
TYPE BASE_TYPE_RUNE;
TYPE BASE_TYPE_BOOL;
TYPE BASE_TYPE_STRING;

TYPE *makeTYPEid(char *name);
TYPE *makeTYPEarray(int length, TYPE *arraytype);
TYPE *makeTYPEstruct(STRUCT_DECL *struct_decl);
TYPE *makeTYPEslice(TYPE *slicetype);
TYPE *makeTYPEparen(TYPE *parentype);
IDENTIFIER *makeID(char *name, TYPE *type);
EXP *makeEXPint(int intconst, int lineno);
EXP *makeEXPfloat(float floatconst, int lineno);
EXP *makeEXPrune(char *runeconst, int lineno);
EXP *makeEXPstring(char *stringconst, int lineno);
EXP *makeEXPrawstring(char *rawstringconst, int lineno);
EXP *makeEXPid(char *id,int lineno);
EXP *makeEXPfunc(EXP *func, EXP *params, int lineno);
EXP *makeEXPstructfield(EXP *structval, char *field,int lineno);
EXP *makeEXParrayaccess(EXP *arrayval, EXP *index, int lineno);
EXP *makeEXPbinary(EXP *left, EXP *right, OP op, int lineno);
EXP *makeEXPunary(EXP *unaryexp, OP op,int lineno);
EXP *makeEXPappend(EXP *left, EXP *right, int lineno);
EXP *makeEXPparen(EXP *parenexp,int lineno);
STATEMENT *makeSTATEMENTshortassign(EXP *expids, EXP *expressions,int lineno);
STATEMENT *makeSTATEMENTexp(EXP *expS, int lineno);
VAR_DECL *makeDECLvar(IDENTIFIER *ids, TYPE *type, EXP *expressions,int lineno);
TYPE_DECL *makeDECLtype(char *typename, TYPE *type, int lineno);
FUNC_DECL *makeDECLfunc(char *funcname, IDENTIFIER *params, TYPE *returntype, BLOCK *block, int lineno);
STRUCT_DECL *makeDECLstruct(IDENTIFIER *ids, TYPE *type, int lineno);
TOP_DECL *makeTOPDECLvar(VAR_DECL *vardecl);
TOP_DECL *makeTOPDECLfunc(FUNC_DECL *funcdecl);
TOP_DECL *makeTOPDECLtype(TYPE_DECL *typedecl);
STATEMENT *makeSTATEMENTvardecl(VAR_DECL *vardecl, int lineno);
STATEMENT *makeSTATEMENTtypedecl(TYPE_DECL *typedecl, int lineno);
STATEMENT *makeSTATEMENTassign(EXP *left, EXP *right, ASSIGN_TYPE assigntype, int lineno);
STATEMENT *makeSTATEMENTprint(EXP *expressions, int newline, int lineno);
STATEMENT *makeSTATEMENTreturn(EXP *expression, int lineno);
STATEMENT *makeSTATEMENTifelse(IFELSE *ifelseS, int lineno);
STATEMENT *makeSTATEMENTswitch(SWITCH_STMT *switchS, int lineno);
CASE_CLAUSE *makeCASE(STATEMENT *statements, EXP *expressions, int lineno, int lastlineno);
STATEMENT *makeSTATEMENTfor(FOR_STMT *forS, int lineno);
STATEMENT *makeSTATEMENTblock(BLOCK *blockS, int lineno);
STATEMENT *makeSTATEMENTcontinue(int lineno);
STATEMENT *makeSTATEMENTbreak(int lineno);
IFELSE *makeIFELSE(STATEMENT *simplestmt, EXP *condition, BLOCK *trueblock, BLOCK *falseblock, IFELSE *elseif, int lineno, int lastlineno);
SWITCH_STMT *makeSWITCH(STATEMENT *simplestmt, EXP *expression, CASE_CLAUSE *caseclauses, int lastlineno);
FOR_STMT *makeFORSTMT(EXP *expression, STATEMENT *simplestmt, STATEMENT *poststmt, BLOCK *block, int lineno, int lastlineno);
BLOCK *makeBLOCK(STATEMENT *statements, int lineno, int lastlineno);
PROGRAM *makePROGRAM(PACK_DECL *pack_decl, TOP_DECL *top_decl, int lastlineno);
PACK_DECL *makePACK_DECL(char *pack_name, int lineno);
void assignIDTYPE(IDENTIFIER *ids, TYPE *type);

int lengthID(IDENTIFIER *ids);
int lengthEXP(EXP *exps);

#endif /* !TREE_H */
