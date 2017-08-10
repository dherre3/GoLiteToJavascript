#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "error.h"
#include "symbol.h"
#include "symboldump.h"
#include "utils.h"

void typeSTATEMENT(STATEMENT *statement);
void typeBLOCK(BLOCK *block);
TYPE *typeEXP(EXP *exp);
int check_types(TYPE *t1, TYPE *t2);
int is_comparable_type(TYPE *type);
void check_for_actual_func(EXP *e);
SymbolTable *cur_sym_table;
TYPE *cur_func_type;

void fatal_error(int lineno) {
  fprintf(stderr, "FATAL ERROR %d\n", lineno);
  exit(1);
}

OP opassign_to_op(ASSIGN_TYPE assign_type) {
  switch (assign_type) {
    case LSHIFTEQ:
      return LSHIFT;
      break;
    case RSHIFTEQ:
      return RSHIFT;
      break;
    case PLUSEQ:
      return PLUS;
      break;
    case ANDEQ:
      return BITAND;
      break;
    case MINUSEQ:
      return MINUS;
      break;
    case OREQ:
      return BITOR;
      break;
    case MULTEQ:
      return MULT;
      break;
    case XOREQ:
      return XOR;
      break;
    case DIVEQ:
      return DIV;
      break;
    case MODEQ:
      return MOD;
      break;
    case CLEAREQ:
      return BITCLEAR;
      break;
    default:
      fatal_error(56);
  }

  fatal_error(57);
  return -1;
}

char *get_op_str(OP operator) {
  return
    operator == PLUS ? "+" :
    operator == MINUS ? "-" :
    operator == BITOR ? "|" :
    operator == XOR ? "^" :
    operator == MULT ? "*" :
    operator == DIV ? "/" :
    operator == MOD ? "%" :
    operator == LSHIFT ? "<<" :
    operator == RSHIFT ? ">>" :
    operator == BITAND ? "&" :
    operator == BITCLEAR ? "&^" :
    operator == EQUAL ? "==" :
    operator == NEQ ? "!=" :
    operator == LT ? "<" :
    operator == LEQ ? "<=" :
    operator == GT ? ">" :
    operator == GEQ ? ">=" :
    operator == AND ? "&&" :
    operator == OR ? "||" :
    operator == NOT ? "!" : 
    "";
}

TYPE *get_root_type(TYPE *type) {
  if (!type)
    return NULL;

  while (type->typeK == idTK || type->typeK == parentK) {
    if (type->typeK == idTK)
      type = type->val.idT.actual_type;
    else
      type = type->val.parenT.type;
  }

  return type;
}

int is_integer_type(TYPE *type) {
  int typeK = type->typeK;
  return typeK == intK || typeK == runeK;
}

int is_numeric_type(TYPE *type) {
  int typeK = type->typeK;
  return typeK == intK || typeK == runeK || typeK == floatK;
}

int is_comparable_struct(TYPE *type) {
  SymbolTable *struct_sym_table = type->val.structT.localsym;

  for (int i = 0; i < HashSize; i++) {
    for (SYMBOL *s = struct_sym_table->table[i]; s; s = s->next) {
      TYPE *field_type = s->val.varS->type;
      if (!is_comparable_type(get_root_type(field_type)))
        return 0;
    }
  }
  
  return 1;
}

int is_comparable_type(TYPE *type) {
  int typeK = type->typeK;

  return 
    typeK == boolK ||
    typeK == intK ||
    typeK == runeK ||
    typeK == floatK ||
    typeK == stringK ||
    (typeK == structK && is_comparable_struct(type)) ||
    (typeK == arrayK && is_comparable_type(get_root_type(type->val.arrayT.array_type)));
}

int is_ordered_type(TYPE *type) {
  int typeK = type->typeK;

  return 
    typeK == intK ||
    typeK == runeK ||
    typeK == floatK ||
    typeK == stringK;
}

int is_castable_type(TYPE *type) {
  int typeK = type->typeK;

  return 
    typeK == intK || 
    typeK == boolK || 
    typeK == floatK || 
    typeK == runeK;
}

int is_base_type(TYPE *type) {
  if (!type) {
    fatal_error(55);
    return 0;
  }
  int typeK = type->typeK;

  int is_base_type = 
    typeK == intK ||
    typeK == runeK ||
    typeK == floatK ||
    typeK == boolK ||
    typeK == stringK;

  return is_base_type;
}

TYPE *get_paren_type(TYPE *type) {
  while (type->typeK == parentK)
    type = type->val.parenT.type;

  return type;
}

int check_struct_types(TYPE *t1, TYPE *t2) {
  STRUCT_DECL *struct_1 = t1->val.structT.struct_decl;
  STRUCT_DECL *struct_2 = t2->val.structT.struct_decl;

  IDENTIFIER *struct_1_id = struct_1->ids;
  IDENTIFIER *struct_2_id = struct_2->ids;

  while (struct_1_id && struct_2_id) {
    if (strcmp(struct_1_id->name, struct_2_id->name) != 0 || !check_types(struct_1_id->type, struct_2_id->type))
      return 0;

    struct_1_id = struct_1_id->next;
    struct_2_id = struct_2_id->next;

    if (!struct_1_id && struct_1->next) {
      struct_1 = struct_1->next;
      struct_1_id = struct_1->ids;
    }
    if (!struct_2_id && struct_2->next) {
      struct_2 = struct_2->next;
      struct_2_id = struct_2->ids;
    }
  }

  if (struct_1_id || struct_2_id) // different number of fields
    return 0;
  else
    return 1;
}

int check_types(TYPE *t1, TYPE *t2) {
  t1 = get_paren_type(t1);
  t2 = get_paren_type(t2);

  if (t1 == t2) {
    return 1;
  } else if (t1->typeK == t2->typeK) {

    switch (t1->typeK) {
      case arrayK:
        return 
          t1->val.arrayT.array_length == t2->val.arrayT.array_length && 
          check_types(t1->val.arrayT.array_type, t2->val.arrayT.array_type);
        break;
      case structK:
        return check_struct_types(t1, t2);
        break;
      case sliceK:
        return check_types(t1->val.sliceT.slice_type, t2->val.sliceT.slice_type);
        break;
      default:
        return 0;
        break;
    }

  } else if (t1->typeK == idTK || t2->typeK == idTK) {

    TYPE *id_actual_type = t1->typeK == idTK ? t1->val.idT.actual_type : t2->val.idT.actual_type;
    TYPE *non_id_type = t1->typeK != idTK ? t1 : t2;
    return is_base_type(id_actual_type) && id_actual_type->typeK == non_id_type->typeK;
    
  }

  return 0;
}

TYPE *typeBINARYEXP(EXP *binary_exp) {
  TYPE *left_exp_type = typeEXP(binary_exp->val.binaryE.left);
  TYPE *right_exp_type = typeEXP(binary_exp->val.binaryE.right);

  OP operator = binary_exp->val.binaryE.op;
  char *op_str = get_op_str(operator);

  if (!check_types(left_exp_type, right_exp_type))
    reportTripleStrError("cannot use %s operator with %s and %s", op_str, get_type_str(left_exp_type), get_type_str(right_exp_type), binary_exp->lineno);
  
  TYPE *root_type = get_root_type(left_exp_type);

  switch (operator) {
    case PLUS:
      if (!is_numeric_type(root_type) && root_type->typeK != stringK)
        reportDoubleStrError("cannot use %s operator with %s (must resolve to a numeric type or string)", op_str, get_type_str(left_exp_type), binary_exp->lineno);
      break;
    case MINUS:
    case MULT:
    case DIV:
      if (!is_numeric_type(root_type))
        reportDoubleStrError("cannot use %s operator with %s (must resolve to a numeric type)", op_str, get_type_str(left_exp_type), binary_exp->lineno);
      break;
    case MOD:
    case BITAND:
    case BITOR:
    case XOR:
    case BITCLEAR:
    case LSHIFT:
    case RSHIFT:
      if (!is_integer_type(root_type))
        reportDoubleStrError("cannot use %s operator with %s (must resolve to an integer type)", op_str, get_type_str(left_exp_type), binary_exp->lineno);
      break;
    case AND:
    case OR:
      if (root_type->typeK != boolK)
        reportDoubleStrError("cannot use %s operator with %s (must resolve to bool)", op_str, get_type_str(left_exp_type), binary_exp->lineno);
      
      return &BASE_TYPE_BOOL;
      break;
    case EQUAL:
    case NEQ:
      if (!is_comparable_type(root_type))
        reportDoubleStrError("cannot use %s operator with %s (must resolve to a comparable type)", op_str, get_type_str(left_exp_type), binary_exp->lineno);

      return &BASE_TYPE_BOOL;
      break;
    case LT:
    case LEQ:
    case GT:
    case GEQ:
      if (!is_ordered_type(root_type))
        reportDoubleStrError("cannot use %s operator with %s (must resolve to an ordered type)", op_str, get_type_str(left_exp_type), binary_exp->lineno);

      return &BASE_TYPE_BOOL;
      break;
    default:
      fatal_error(102);
      break;
  }

  return left_exp_type;
}

TYPE *typeUNARYEXP(EXP *unary_exp) {
  TYPE *exp_type = typeEXP(unary_exp->val.unaryE.exp);
  TYPE *root_type = get_root_type(exp_type);
  OP operator = unary_exp->val.unaryE.op; 
  char *op_str = get_op_str(operator);

  switch (operator) {
    case PLUS:
    case MINUS:
      if (!is_numeric_type(root_type))
        reportDoubleStrError("cannot use %s operator with %s", op_str, get_type_str(exp_type), unary_exp->lineno);
      break;
    case NOT:
      if (root_type->typeK != boolK)
        reportDoubleStrError("cannot use %s operator with %s", op_str, get_type_str(exp_type), unary_exp->lineno);
      break;
    case XOR:
      if (!is_integer_type(root_type))
        reportDoubleStrError("cannot use %s operator with %s", op_str, get_type_str(exp_type), unary_exp->lineno);
      break;
    default:
      fatal_error(102);
      break;
  }

  return exp_type;
}

TYPE *typeTYPECAST(TYPE *type, EXP *exp, int lineno) {
  if (lengthEXP(exp) != 1)
    reportError("invalid number of arguments to cast expression", lineno);

  TYPE *root_type = get_root_type(type);
  if (!root_type)
    fatal_error(227);

  if (!is_castable_type(root_type))
    reportError("invalid type cast (can only cast between int, bool, float64, rune and their aliases)", exp->lineno);

  TYPE *exp_type = get_root_type(typeEXP(exp));
  if (!root_type)
    fatal_error(330);

  if (!is_castable_type(exp_type))
    reportError("expression cannot be cast (can only cast between int, bool, float64, rune and their aliases)", exp->lineno);

  return type;
}

TYPE *typeFUNCEXP(EXP *exp, int is_statement) {
  EXP *func_id = exp->val.funcE.func;
  EXP *params = exp->val.funcE.params;

  while (func_id->kind == parenK) {
    func_id = func_id->val.parenE.exp;
  }

  if (func_id->kind != idK)
    reportError("expression is not a function", exp->lineno);

  SYMBOL *func_sym = func_id->val.idE.id->sym;

  if (!func_sym) {
    fatal_error(224); // should be detected by symbol.c
  } else if (func_sym->kind == typeSym) {
    if (is_statement) {
      reportError("Expression statement cannot be a typecast", exp->lineno);
    } else {
      exp->val.funcE.is_typecast = 1;
      return typeTYPECAST(func_sym->val.typeS, params, exp->lineno);
    }
  } else if (func_sym->kind != funcSym) {
    fatal_error(228); // should be detected by symbol.c
  }

  FUNC_DECL *func_decl = func_sym->val.funcS;
  IDENTIFIER *func_decl_params = func_decl->params;

  if (lengthEXP(params) != lengthID(func_decl_params)) {
    reportError("invalid number of arguments in function call", exp->lineno);
  }

  while (params && func_decl_params) {
    TYPE *params_type = typeEXP(params);
    params->type = params_type;
    if (!check_types(params_type, func_decl_params->type))
      reportDoubleStrError("invalid type: expected %s, found %s", get_type_str(func_decl_params->type), get_type_str(params_type), exp->lineno);

    params = params->next;
    func_decl_params = func_decl_params->next;
  }
  
  func_id->type = func_decl->returntype;
  exp->type = func_decl->returntype;
  
  return func_decl->returntype;
}

TYPE *typeARRAYACCESSEXP(EXP *exp) {
  EXP *arrayval = exp->val.arrayaccessE.arrayval;
  EXP *index = exp->val.arrayaccessE.index;

  TYPE *arrayval_type = get_root_type(typeEXP(arrayval));
  TYPE *index_type = typeEXP(index);

  if (arrayval_type->typeK != arrayK && arrayval_type->typeK != sliceK)
    reportError("indexing can only be done on arrays or slices", exp->lineno);

  if (!is_integer_type(get_root_type(index_type)))
    reportError("index must resolve to an integer (int or rune)", exp->lineno);

  if (arrayval_type->typeK == arrayK)
    return arrayval_type->val.arrayT.array_type;
  else 
    return arrayval_type->val.sliceT.slice_type;
}


TYPE *typeAPPENDEXP(EXP *exp) {
  TYPE *left_type = typeEXP(exp->val.appendE.left);
  TYPE *right_type = typeEXP(exp->val.appendE.right);

  TYPE *left_root_type = get_root_type(left_type);

  if (left_root_type->typeK != sliceK)
    reportError("arg1 must be a slice<T>, arg2 must be a T for append(arg1, arg2) expression", exp->lineno);

  if (!check_types(left_root_type->val.sliceT.slice_type, right_type))
    reportError("arg1 must be a slice<T>, arg2 must be a T for append(arg1, arg2) expression", exp->lineno);

  return left_type;
}

TYPE *typeSTRUCTFIELD(EXP *exp) {
  EXP *struct_exp = exp->val.structfieldE.structval;
  IDENTIFIER *field_id = exp->val.structfieldE.field;

  TYPE *struct_type = get_root_type(typeEXP(struct_exp));

  if (struct_type->typeK != structK)
    reportError("selection can only be done on structs", exp->lineno);

  SymbolTable *struct_table = struct_type->val.structT.localsym;
  SYMBOL *field_symbol = getSymbol(struct_table, field_id->name);

  if (!field_symbol)
    reportStrError("%s is not a field in struct definition", field_id->name, exp->lineno);

  TYPE *field_type = field_symbol->val.varS->type;
  return field_type;
}

TYPE *typeID(EXP *exp) {
  IDENTIFIER *id = exp->val.idE.id;

  SYMBOL *sym = id->sym;
  if (sym->kind != varSym && sym->kind != formalSym)
    reportError(strf("%s cannot be used as a value", id->name), exp->lineno);

  id->type = sym->kind == varSym ? sym->val.varS->type : sym->val.formalS->type;

  return id->type;
}

TYPE *typeEXP(EXP *exp) {  
  TYPE *exp_type = NULL;

  switch (exp->kind) {
    case idK:
      exp_type = typeID(exp);
      break;
    case funcK:
      exp_type = typeFUNCEXP(exp, 0);
      if (!exp_type)
        reportError("expression cannot be void", exp->lineno);
      break;
    case structfieldK:
      exp_type = typeSTRUCTFIELD(exp);
      break;
    case arrayaccessK:
      exp_type = typeARRAYACCESSEXP(exp);
      break;
    case appendK:
      exp_type = typeAPPENDEXP(exp);
      break;
    case binaryK:
      exp_type = typeBINARYEXP(exp);
      break;
    case unaryK:
      exp_type = typeUNARYEXP(exp);
      break;
    case parenK:
      exp_type = typeEXP(exp->val.parenE.exp);
      break;
    case intconstK:
    case floatconstK:
    case stringconstK:
    case runeconstK:
    case rawstringconstK:
      exp_type = exp->type;
      break;
    default:
      break;
  }

  if (!exp_type)
    fatal_error(242);

  exp->type = exp_type;
  return exp_type;
}

void typeSHORTASSIGN(STATEMENT *statement) {
  IDENTIFIER *curID = statement->val.shortassignS.ids;
  EXP *curEXP = statement->val.shortassignS.expressions;

  while (curID) {
    TYPE *exp_type = typeEXP(curEXP);

    if (!curID->is_blank) {
      if (curID->type && !check_types(curID->type, exp_type)) {
        reportDoubleStrError("invalid type: expected %s, found %s", get_type_str(curID->type), get_type_str(exp_type), statement->lineno);
      } else {
        curID->type = exp_type;
      }
    }

    curID = curID->next;
    curEXP = curEXP->next;
  }
}

void typeASSIGN(STATEMENT *statement) {
  ASSIGN *assignment = statement->val.assignS.assignment;
  EXP *cur_left_exp = assignment->left;
  EXP *cur_right_exp = assignment->right;

  if (assignment->assigntype == EQ) { // normal assign

    while (cur_left_exp) {
      int is_blank_id = cur_left_exp->kind == idTK && cur_left_exp->val.idE.id->is_blank;

      TYPE *right_exp_type = typeEXP(cur_right_exp);

      if (!is_blank_id) {
        TYPE *left_exp_type = typeEXP(cur_left_exp);
        if (!check_types(left_exp_type, right_exp_type)) {
          reportDoubleStrError("invalid type: expected %s, found %s", get_type_str(left_exp_type), get_type_str(right_exp_type), statement->lineno);
        }
      }

      cur_left_exp = cur_left_exp->next;
      cur_right_exp = cur_right_exp->next;
    }

  } else if (cur_right_exp) { // op assign
    // typecheck as binary expression
    EXP *binary_exp = makeEXPbinary(cur_left_exp, cur_right_exp, opassign_to_op(assignment->assigntype), statement->lineno);

    typeBINARYEXP(binary_exp);
  } else { // increment/decrement

    TYPE *left_exp_type = typeEXP(cur_left_exp);
    if (!is_numeric_type(get_root_type(left_exp_type)))
      reportError("++/-- operator requires a numeric argument", statement->lineno);

  }
}

void typePRINT(STATEMENT *statement) {
  EXP *print_exps = statement->val.printS.expressions;
  while (print_exps) {
    TYPE *print_exp_type = typeEXP(print_exps);
    if (!is_base_type(get_root_type(print_exp_type))) {
      reportError("expression in print statement must resolve to a base type", statement->lineno);
    }

    print_exps = print_exps->next;
  }
}

void typeFOR(FOR_STMT *for_stmt) {
  if (!for_stmt)
    return;

  SymbolTable *prev_table = cur_sym_table;
  cur_sym_table = for_stmt->symtable;

  typeSTATEMENT(for_stmt->simplestmt);

  if (for_stmt->expression) {
    TYPE *exp_type = typeEXP(for_stmt->expression);
    if (get_root_type(exp_type)->typeK != boolK) {
      reportStrError("invalid type: expected a type that resolves to bool, found %s", get_type_str(exp_type), for_stmt->lineno);
    }
  }

  typeSTATEMENT(for_stmt->poststmt);
  typeBLOCK(for_stmt->block);

  dump_symbol_table(cur_sym_table, for_stmt->lastlineno);

  cur_sym_table = prev_table;
}

void typeIFELSE(IFELSE *if_stmt) {
  if (!if_stmt)
    return;

  SymbolTable *prev_table = cur_sym_table;
  cur_sym_table = if_stmt->symtable;
  
  typeSTATEMENT(if_stmt->simplestmt);

  TYPE *exp_type = typeEXP(if_stmt->condition);
  if (get_root_type(exp_type)->typeK != boolK) {
    reportStrError("invalid type: expected a type that resolves to bool, found %s", get_type_str(exp_type), if_stmt->lineno);
  }

  typeBLOCK(if_stmt->trueblock);
  typeBLOCK(if_stmt->falseblock);
  typeIFELSE(if_stmt->elseif);

  dump_symbol_table(cur_sym_table, if_stmt->lastlineno);

  cur_sym_table = prev_table;
}

void typeCASECLAUSE(CASE_CLAUSE *caseclause, TYPE *expected_type) {
  if (caseclause) {
    typeCASECLAUSE(caseclause->next, expected_type);

    EXP *expression = caseclause->expressions;
    while (expression) {
      TYPE *exp_type = typeEXP(expression);
      if (!check_types(exp_type, expected_type))
        reportDoubleStrError("invalid type: expected %s, found %s", get_type_str(expected_type), get_type_str(exp_type), caseclause->lineno);

      expression = expression->next;
    }

    typeBLOCK(caseclause->block);
  }
}

void typeSWITCH(SWITCH_STMT *switch_stmt) {
  if (!switch_stmt)
    return;
  
  SymbolTable *prev_table = cur_sym_table;
  cur_sym_table = switch_stmt->symtable;

  typeSTATEMENT(switch_stmt->simplestmt);

  if (switch_stmt->expression) {
    TYPE *exp_type = typeEXP(switch_stmt->expression);
    typeCASECLAUSE(switch_stmt->caseclauses, exp_type);
  } else {
    typeCASECLAUSE(switch_stmt->caseclauses, &BASE_TYPE_BOOL);
  }

  dump_symbol_table(cur_sym_table, switch_stmt->lastlineno);

  cur_sym_table = prev_table;
}

void typeVARDECL(VAR_DECL *var_decl) {
  if (!var_decl)
    return;

  typeVARDECL(var_decl->next);

  IDENTIFIER *curID = var_decl->ids;
  EXP *curEXP = var_decl->expressions;

  TYPE *var_decl_type = var_decl->type;

  while (curID) {
    SYMBOL *sym = curID->sym;

    if (curEXP) {

      TYPE *exp_type = typeEXP(curEXP);
      
      if (var_decl_type && !check_types(var_decl_type, exp_type))
        reportDoubleStrError("invalid type: expected %s, found %s", get_type_str(var_decl_type), get_type_str(exp_type), var_decl->lineno);

      if (!curID->is_blank) {
        curID->type = exp_type;
        sym->val.varS->type = curID->type;
      }

      curEXP = curEXP->next;

    } else if (!curID->is_blank) {

      curID->type = var_decl_type;
      sym->val.varS->type = curID->type;

    }

    curID = curID->next;
  }
}

void typeRETURN(STATEMENT *statement) {
  if (!statement)
    return;

  EXP *exp = statement->val.returnS.expression;

  if (!cur_func_type && !exp)
    return;

  if (!cur_func_type && exp)
    reportError("function must not return a value", statement->lineno);
  if (cur_func_type && !exp)
    reportError("function must return a value", statement->lineno);

  TYPE *exp_type = typeEXP(exp);
  if (!check_types(cur_func_type, exp_type))
    reportDoubleStrError("invalid return type: expected %s, found %s", get_type_str(cur_func_type), get_type_str(exp_type), statement->lineno);
}

void typeSTATEMENT(STATEMENT *statement) {
  if (!statement)
    return;

  typeSTATEMENT(statement->next);

  switch (statement->kind) {
    case vardeclK:
      typeVARDECL(statement->val.vardeclS.vardecl);
      break;
    case shortassignK:
      typeSHORTASSIGN(statement);
      break;
    case expK:
      typeFUNCEXP(statement->val.expS.exp, 1);
      break;
    case assignK:
      typeASSIGN(statement);
      break;
    case printK:
      typePRINT(statement);
      break;
    case returnK:
      typeRETURN(statement);
      break;
    case ifelseK:
      typeIFELSE(statement->val.ifelseS.ifelse);
      break;
    case switchK:
      typeSWITCH(statement->val.switchS.switchstmt);
      break;
    case forK:
      typeFOR(statement->val.forS.forstmt);
      break;
    case blockK:
      typeBLOCK(statement->val.blockS.block);
      break;
    case typedeclK:
    case continueK:
    case breakK:
    default:
      break;
  }
}

void typeBLOCK(BLOCK *block) {
  if (!block)
    return;

  SymbolTable *prev_table = cur_sym_table;
  cur_sym_table = block->localsym;

  typeSTATEMENT(block->statements);

  dump_symbol_table(cur_sym_table, block->lastlineno);

  cur_sym_table = prev_table;
}

void typeFUNCDECL(FUNC_DECL *func_decl) {
  cur_func_type = func_decl->returntype;
  typeBLOCK(func_decl->block);
  cur_func_type = NULL;
}

void typeTOPDECL(TOP_DECL *top_decl) {
  if (!top_decl)
    return;

  typeTOPDECL(top_decl->next);

  switch (top_decl->kind) {
    case varK:
      typeVARDECL(top_decl->val.var_decl);
      break;
    case functionK:
      typeFUNCDECL(top_decl->val.func_decl);
      break;
    case typeK:
    default:
      break;
  }
}

void typePROGRAM(PROGRAM *program) {
  init_dump_symbol_table();  

  cur_sym_table = program->sym;
  typeTOPDECL(program->top_decl);
  dump_symbol_table(cur_sym_table, program->lastlineno);

  end_dump_symbol_table();
}
