#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

TYPE BASE_TYPE_INT = { .typeK = intK };
TYPE BASE_TYPE_FLOAT = { .typeK = floatK };
TYPE BASE_TYPE_RUNE = { .typeK = runeK };
TYPE BASE_TYPE_BOOL = { .typeK = boolK };
TYPE BASE_TYPE_STRING = { .typeK = stringK };

IDENTIFIER *expsIDsToIDs(EXP *expids);

TYPE *makeTYPEid(char *name) {
  TYPE *type = NEW(TYPE);
  type->typeK = idTK;
  type->val.idT.name = name;  
  return type;
}

TYPE *makeTYPEarray(int length, TYPE *arraytype) {
  TYPE *type = NEW(TYPE);
  type->typeK = arrayK;
  type->val.arrayT.array_length = length;
  type->val.arrayT.array_type = arraytype;
  return type;
}

TYPE *makeTYPEstruct(STRUCT_DECL *struct_decl) {
  TYPE *type = NEW(TYPE);
  type->typeK = structK;
  type->val.structT.struct_decl = struct_decl;
  return type;
}

TYPE *makeTYPEslice(TYPE *slicetype) {
  TYPE *type = NEW(TYPE);
  type->typeK = sliceK;
  type->val.sliceT.slice_type = slicetype;
  return type;
}

TYPE *makeTYPEparen(TYPE *parentype) {
  TYPE *type = NEW(TYPE);
  type->typeK = parentK;
  type->val.parenT.type = parentype;
  return type;
}

IDENTIFIER *makeID(char *name, TYPE *type) {
  IDENTIFIER *id = NEW(IDENTIFIER);
  id->name = name;
  id->type = type;
  id->next = NULL;
  id->is_blank = strcmp(name, "_") == 0;
  id->decl_count = 0;
  return id;
}

EXP *makeEXPint(int intconst, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = intconstK;
  exp->next = NULL;
  exp->val.intconstE = intconst;
  exp->type = &BASE_TYPE_INT;
  return exp;
}

EXP *makeEXPfloat(float floatconst, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = floatconstK;
  exp->next = NULL;
  exp->val.floatconstE = floatconst;
  exp->type = &BASE_TYPE_FLOAT;
  return exp;
}

EXP *makeEXPrune(char *runeconst, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = runeconstK;
  exp->next = NULL;
  exp->val.runeconstE = runeconst;
  exp->type = &BASE_TYPE_RUNE;
  return exp;
}

EXP *makeEXPstring(char *stringconst, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = stringconstK;
  exp->next = NULL;
  exp->val.stringconstE = stringconst;
  exp->type = &BASE_TYPE_STRING;
  return exp;
}

EXP *makeEXPrawstring(char *rawstringconst, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = rawstringconstK;
  exp->next = NULL;
  exp->val.rawstringconstE = rawstringconst;
  exp->type = &BASE_TYPE_STRING;
  return exp;
}

EXP *makeEXPid(char *id,int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = idK;
  exp->next = NULL;
  exp->val.idE.id = makeID(id, NULL);
  exp->type = NULL;
  return exp;
}

EXP *makeEXPfunc(EXP *func, EXP *params, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = funcK;
  exp->next = NULL;
  exp->val.funcE.func = func;
  exp->val.funcE.params = params;
  exp->val.funcE.is_typecast = 0;
  exp->type = NULL;
  return exp;
}

EXP *makeEXPstructfield(EXP *structval, char *field,int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = structfieldK;
  exp->next = NULL;
  exp->val.structfieldE.structval = structval;
  exp->val.structfieldE.field = makeID(field, NULL);
  exp->type = NULL;
  return exp;
}

EXP *makeEXParrayaccess(EXP *arrayval, EXP *index, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = arrayaccessK;
  exp->next = NULL;
  exp->val.arrayaccessE.arrayval = arrayval;
  exp->val.arrayaccessE.index = index;
  exp->type = NULL;
  return exp;
}

EXP *makeEXPbinary(EXP *left, EXP *right, OP op, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = binaryK;
  exp->next = NULL;
  exp->val.binaryE.left = left;
  exp->val.binaryE.right = right;
  exp->val.binaryE.op = op;
  exp->type = NULL;
  return exp;
}

EXP *makeEXPunary(EXP *unaryexp, OP op,int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = unaryK;
  exp->next = NULL;
  exp->val.unaryE.exp = unaryexp;
  exp->val.unaryE.op = op;
  exp->type = NULL;
  return exp;
}

EXP *makeEXPappend(EXP *left, EXP *right, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = appendK;
  exp->next = NULL;
  exp->val.appendE.left = left;
  exp->val.appendE.right = right;
  exp->type = NULL;
  return exp;
}

EXP *makeEXPparen(EXP *parenexp, int lineno) {
  EXP *exp = NEW(EXP);
  exp->lineno = lineno;
  exp->kind = parenK;
  exp->val.parenE.exp = parenexp;
  exp->type = NULL;
  return exp;
}

VAR_DECL *makeDECLvar(IDENTIFIER *ids, TYPE *type, EXP *expressions, int lineno) {
  if (expressions && lengthID(ids) != lengthEXP(expressions)) 
    parserError("unbalanced variable declaration", lineno);

  VAR_DECL *vardecl = NEW(VAR_DECL);
  if (type)
    assignIDTYPE(ids, type);

  vardecl->lineno = lineno;
  vardecl->ids = ids;
  vardecl->type = type;
  vardecl->expressions = expressions;
  return vardecl;
}

TYPE_DECL *makeDECLtype(char *typename, TYPE *type, int lineno) {
  TYPE_DECL *typedecl = NEW(TYPE_DECL);
  typedecl->next = NULL;
  typedecl->lineno = lineno;
  typedecl->type = type;
  typedecl->id = makeID(typename, type);
  return typedecl;
}

FUNC_DECL *makeDECLfunc(char *funcname, IDENTIFIER *params, TYPE *returntype, BLOCK *block,int lineno) {
  FUNC_DECL *funcdecl = NEW(FUNC_DECL);
  funcdecl->lineno = lineno;
  funcdecl->id = makeID(funcname, returntype);
  funcdecl->params = params;
  funcdecl->returntype = returntype;
  funcdecl->block = block;
  return funcdecl;
}

TOP_DECL *makeTOPDECLvar(VAR_DECL *vardecl) {
  TOP_DECL *top_decl = NEW(TOP_DECL);
  top_decl->next = NULL;
  top_decl->kind = varK;
  top_decl->val.var_decl = vardecl;
  return top_decl;
}

TOP_DECL *makeTOPDECLfunc(FUNC_DECL *funcdecl) {
  TOP_DECL *top_decl = NEW(TOP_DECL);
  top_decl->next = NULL;
  top_decl->kind = functionK;
  top_decl->val.func_decl = funcdecl;
  return top_decl;
}

TOP_DECL *makeTOPDECLtype(TYPE_DECL *typedecl) {
  TOP_DECL *top_decl = NEW(TOP_DECL);
  top_decl->next = NULL;
  top_decl->kind = typeK;
  top_decl->val.type_decl = typedecl;
  return top_decl;
}

STRUCT_DECL *makeDECLstruct(IDENTIFIER *ids, TYPE *type, int lineno) {
  STRUCT_DECL *structdecl = NEW(STRUCT_DECL);
  structdecl->lineno = lineno;
  structdecl->ids = ids;
  structdecl->type = type;
  assignIDTYPE(structdecl->ids,type);
  return structdecl;
}

STATEMENT *makeSTATEMENTvardecl(VAR_DECL *vardecl, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = vardeclK;
  statement->next = NULL;
  statement->val.vardeclS.vardecl = vardecl;
  return statement;
}

STATEMENT *makeSTATEMENTtypedecl(TYPE_DECL *typedecl, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = typedeclK;
  statement->next = NULL;
  statement->val.typedeclS.typedecl = typedecl;
  return statement;
}

STATEMENT *makeSTATEMENTshortassign(EXP *expids, EXP *expressions, int lineno) {
  if (lengthEXP(expids) != lengthEXP(expressions)) 
    parserError("unbalanced short declaration", lineno);

  IDENTIFIER *ids = expsIDsToIDs(expids);
  if (ids == NULL)
    parserError("cannot short assign to an expression", lineno);

  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = shortassignK;
  statement->next = NULL;
  statement->val.shortassignS.ids = ids;
  statement->val.shortassignS.expressions = expressions;
  return statement;
}

STATEMENT *makeSTATEMENTexp(EXP *expS,int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = expK;
  statement->next = NULL;
  statement->val.expS.exp = expS;
  return statement;
}

STATEMENT *makeSTATEMENTassign(EXP *left, EXP *right, ASSIGN_TYPE assigntype, int lineno) {
  if (assigntype == EQ && lengthEXP(left) != lengthEXP(right))
    parserError("unbalanced assignment", lineno);

  EXP *exp_head = left;
  while (exp_head) {
    if (
      (exp_head->kind == structfieldK && exp_head->val.structfieldE.structval->kind == funcK) ||
      (exp_head->kind == arrayaccessK && exp_head->val.arrayaccessE.arrayval->kind == funcK)
    )
      parserError("not a left expression", lineno);

    exp_head = exp_head->next;
  }
  
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = assignK;
  statement->next = NULL;
  statement->val.assignS.assignment = NEW(ASSIGN);
  statement->val.assignS.assignment->left = left;
  statement->val.assignS.assignment->right = right;
  statement->val.assignS.assignment->assigntype = assigntype;

  return statement;
}

STATEMENT *makeSTATEMENTprint(EXP *expressions, int newline, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = printK;
  statement->next = NULL;
  statement->val.printS.expressions = expressions;
  statement->val.printS.newline = newline;
  return statement;
}

STATEMENT *makeSTATEMENTreturn(EXP *expression, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = returnK;
  statement->next = NULL;
  statement->val.returnS.expression = expression;
  return statement;
}

STATEMENT *makeSTATEMENTifelse(IFELSE *ifelseS, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = ifelseK;
  statement->next = NULL;
  statement->val.ifelseS.ifelse = ifelseS;
  return statement;
}

STATEMENT *makeSTATEMENTswitch(SWITCH_STMT *switchS, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = switchK;
  statement->next = NULL;
  statement->val.switchS.switchstmt = switchS;
  return statement;
}

STATEMENT *makeSTATEMENTfor(FOR_STMT *forS, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = forK;
  statement->next = NULL;
  statement->val.forS.forstmt = forS;
  return statement;
}

STATEMENT *makeSTATEMENTblock(BLOCK *blockS, int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = blockK;
  statement->next = NULL;
  statement->val.blockS.block = blockS;
  return statement;
}

STATEMENT *makeSTATEMENTcontinue(int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = continueK;
  statement->next = NULL;
  return statement;
}

STATEMENT *makeSTATEMENTbreak(int lineno) {
  STATEMENT *statement = NEW(STATEMENT);
  statement->lineno = lineno;
  statement->kind = breakK;
  statement->next = NULL;
  return statement;
}

IFELSE *makeIFELSE(STATEMENT *simplestmt, EXP *condition, BLOCK *trueblock, BLOCK *falseblock, IFELSE *elseif, int lineno, int lastlineno) {
  IFELSE *ifelse = NEW(IFELSE);
  ifelse->lineno = lineno;
  ifelse->lastlineno = lastlineno;
  ifelse->simplestmt = simplestmt;
  ifelse->condition = condition;
  ifelse->trueblock = trueblock;
  ifelse->falseblock = falseblock;
  ifelse->elseif = elseif;
  return ifelse;
}

CASE_CLAUSE *makeCASE(STATEMENT *statements, EXP *expressions,int lineno, int lastlineno) {
  CASE_CLAUSE *caseclause = NEW(CASE_CLAUSE);
  BLOCK *caseblock = NEW(BLOCK);
  caseclause->expressions = expressions;
  caseclause->lineno = lineno;
  caseblock->statements = statements;
  caseblock->lineno = lineno;
  caseblock->lastlineno = lastlineno;
  caseclause->block = caseblock;
  return caseclause;
}

SWITCH_STMT *makeSWITCH(STATEMENT *simplestmt, EXP *expression, CASE_CLAUSE *caseclauses, int lastlineno) {
  SWITCH_STMT *switchstmt = NEW(SWITCH_STMT);
  switchstmt->simplestmt = simplestmt;
  switchstmt->expression = expression;
  switchstmt->caseclauses = caseclauses;
  switchstmt->lastlineno = lastlineno;
  return switchstmt;
}

FOR_STMT *makeFORSTMT(EXP *expression, STATEMENT *simplestmt, STATEMENT *poststmt, BLOCK *block, int lineno, int lastlineno) {
  FOR_STMT *for_stmt = NEW(FOR_STMT);
  for_stmt->expression = expression;
  for_stmt->lineno = lineno;
  for_stmt->lastlineno = lastlineno;
  for_stmt->simplestmt = simplestmt;
  for_stmt->poststmt = poststmt;
  for_stmt->block = block;
  return for_stmt;
}

BLOCK *makeBLOCK(STATEMENT *statements, int lineno, int lastlineno) {
  BLOCK *block = NEW(BLOCK);
  block->lineno = lineno;
  block->lastlineno = lastlineno;
  block->statements = statements;
  return block;
}

PACK_DECL *makePACK_DECL(char *pack_name, int lineno) {
  PACK_DECL *pack_decl  = NEW(PACK_DECL);
  pack_decl->pack_name = pack_name;
  pack_decl->lineno = lineno;
  return pack_decl;
}

PROGRAM *makePROGRAM(PACK_DECL *pack_decl, TOP_DECL *top_decl, int lastlineno) {
  PROGRAM *program = NEW(PROGRAM); 
  program->pack_decl = pack_decl;
  program->top_decl = top_decl;
  program->lastlineno = lastlineno;
  return program;
}

void assignIDTYPE(IDENTIFIER *ids, TYPE *type) {
  while (ids != NULL) {
    ids->type = type;
    ids = ids->next;
  }
}

IDENTIFIER *expsIDsToIDs(EXP *expids) {
  if (expids->kind != idK)
    return NULL;

  IDENTIFIER *ids = expids->val.idE.id;
  IDENTIFIER *curID = ids;
  EXP *nextEXP = expids->next;

  while (nextEXP != NULL) {
    if (nextEXP->kind != idK)
      return NULL;

    curID->next = nextEXP->val.idE.id;
    curID = curID->next;
    nextEXP = nextEXP->next;
  }

  return ids;
}

int lengthID(IDENTIFIER *ids) {
  int len = 0;
  IDENTIFIER *ptr = ids;
  while (ptr != NULL) {
    len++;
    ptr = ptr->next;
  }
  return len;
}

int lengthEXP(EXP *exps) {
  int len = 0;
  EXP *ptr = exps;
  while (ptr != NULL) {
    len++;
    ptr = ptr->next;
  }
  return len;
}
