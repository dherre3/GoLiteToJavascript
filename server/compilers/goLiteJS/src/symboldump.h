#ifndef SYMBOLDUMP_H
#define SYMBOLDUMP_H

char *get_type_str(TYPE *type);
void dump_symbol_table(SymbolTable *sym_table, int lineno);
void init_dump_symbol_table();
void end_dump_symbol_table();

#endif
