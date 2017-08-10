#ifndef ERROR_H
#define ERROR_H
void yyerror(char *s);

void parserError(char *s, int line);

void reportError(char *s, int lineno);

void reportStrError(char *s, char *name, int lineno);

void reportDoubleStrError(char *s, char *name1, char *name2, int lineno);

void reportTripleStrError(char *s, char *name1, char *name2, char *name3, int lineno);

void reportGlobalError(char *s);

void reportStrGlobalError(char *s, char *name);

void noErrors();

extern int lineno;
#endif /* !ERROR_H */
