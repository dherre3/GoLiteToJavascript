#include <stdio.h>
#include "tree.h"
#include "error.h"
#include "symbol.h"
#include "symboldump.h"
#include "utils.h"

FILE *symtab_fp = NULL;
int indent_lvl = 0;

void sym_fatal_error(int lineno) {
  printf("SYMDUMP FATAL ERROR %d\n", lineno);
  exit(1);
}

char *get_indent() {
  int num_spaces = indent_lvl * 2;
  char *indent = malloc(sizeof(char) * num_spaces + 1);

  for (int i = 0; i < num_spaces; i++)
    indent[i] = ' ';

  indent[num_spaces] = '\0';
  return indent;
}

char *get_struct_str(STRUCT_DECL *struct_decl) {
  indent_lvl++;
  char *indent = get_indent();
  char *struct_str = NULL;

  while (struct_decl) {
    char *ids_str = NULL;

    IDENTIFIER *ids = struct_decl->ids;
    while (ids) {
      if (ids_str)
        ids_str = strf("%s, %s", ids->name, ids_str);
      else
        ids_str = strf("%s", ids->name);

      ids = ids->next;
    }

    ids_str = strf("%s %s", ids_str, get_type_str(struct_decl->type));

    if (struct_str)
      struct_str = strf("%s%s\n%s", indent, ids_str, struct_str);
    else
      struct_str = strf("%s%s", indent, ids_str);

    struct_decl = struct_decl->next;
  }

  free(indent);

  indent_lvl--;
  indent = get_indent();
  struct_str = strf("struct {\n%s\n%s}", struct_str, indent);
  free(indent);

  return struct_str;
}

char *get_type_str(TYPE *type) {
  if (!type)
    sym_fatal_error(14);

  char *type_str = NULL;

  switch (type->typeK) {
    case idTK:
      type_str = type->val.idT.name;
      break;
    case arrayK: {
      int array_length = type->val.arrayT.array_length;
      TYPE *array_type = type->val.arrayT.array_type;
      type_str = strf("[%d]%s", array_length, get_type_str(array_type));
      break;
    }
    case structK:
      type_str = get_struct_str(type->val.structT.struct_decl);
      break;
    case sliceK:
      type_str = strf("[]%s", get_type_str(type->val.sliceT.slice_type));
      break;
    case parentK:
      type_str = get_type_str(type->val.parenT.type);
      break;
    case intK:
      type_str = "int";
      break;
    case boolK:
      type_str = "bool";
      break;
    case floatK:
      type_str = "float64";
      break;
    case runeK:
      type_str = "rune";
      break;
    case stringK:
      type_str = "string";
      break;
    default:
      sym_fatal_error(38);
      break;
  }

  if (!type_str)
    sym_fatal_error(59);

  return type_str;
}

char *get_func_type_str(FUNC_DECL *func_decl) {
  char *types_str = NULL;

  IDENTIFIER *func_params = func_decl->params;
  while (func_params) {
    if (types_str)
      types_str = strf("%s, %s", get_type_str(func_params->type), types_str);
    else
      types_str = strf("%s", get_type_str(func_params->type));

    func_params = func_params->next;
  }

  if (!types_str)
    types_str = "";

  if (func_decl->returntype)
    return strf("(%s) -> %s", types_str, get_type_str(func_decl->returntype));
  else
    return strf("(%s)", types_str);
}

char *get_symbol_str(SYMBOL *symbol) {
  if (!symbol)
    sym_fatal_error(18);

  char *name_str = symbol->name;
  char *type_str = NULL;

  switch (symbol->kind) {
    case typeSym:
      if (symbol->val.typeS->typeK != idTK)
        sym_fatal_error(128);

      type_str = get_type_str(symbol->val.typeS->val.idT.actual_type);
      break;
    case varSym:
      type_str = get_type_str(symbol->val.varS->type);
      break;
    case formalSym:
      type_str = get_type_str(symbol->val.formalS->type);
      break;
    case funcSym:
      type_str = get_func_type_str(symbol->val.funcS);
      break;
    default:
      sym_fatal_error(30);
      break;
  }

  if (!type_str)
    sym_fatal_error(157);

  if (symbol->kind == typeSym)
    return strf("%s (type alias) : %s", name_str, type_str);
  else
    return strf("%s : %s", name_str, type_str);
}

void dump_symbol_table(SymbolTable *sym_table, int lineno) {
  if (!dumpsymtab)
    return;

  if (!symtab_fp)
    sym_fatal_error(168);

  for (int i = 0; i < HashSize; i++) {
    for (SYMBOL *s = sym_table->table[i]; s; s = s->next) {
      fprintf(symtab_fp, "%s\n", get_symbol_str(s));
    }
  }

  if (lineno) // if lineno == 0, then don't print it (scope has not exited)
    fprintf(symtab_fp, "*** scope exit at line %d ***\n\n", lineno);
}

void init_dump_symbol_table() {
  if (symtab_fp)
    sym_fatal_error(185);

  if (dumpsymtab)
    symtab_fp = fopen(strf("%s.symtab", filename), "w");
}

void end_dump_symbol_table() {
  if (!dumpsymtab)
    return;

  if (!symtab_fp)
    sym_fatal_error(188);

  fclose(symtab_fp);
}
