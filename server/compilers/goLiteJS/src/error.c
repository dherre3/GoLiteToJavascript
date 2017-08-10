#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"

extern char *yytext;

extern int yylineno;

int errors = 0;

void yyerror(char *s)
{ 
  fprintf(stderr,"INVALID: %s",s);
  fprintf(stderr," before %s at line %i\n",
                 yytext,yylineno);
  exit(1);
}
void parserError(char *s, int lineno)
{
    fprintf(stderr,"INVALID: %s at line %i\n",s,lineno);
    exit(1);
}
void reportError(char *s, int lineno)
{ 
  fprintf(stderr, "INVALID: %s at line %i\n",s,lineno);
  errors++;
  noErrors();
}
void reportDoubleStrError(char *s, char *name1, char *name2, int lineno)
{
    fprintf(stderr, "INVALID: ");
    fprintf(stderr, s,name1, name2);
    fprintf(stderr, " at line %i\n",lineno);
    errors++;
    noErrors();

}
void reportTripleStrError(char *s, char *name1, char *name2, char *name3, int lineno)
{
    fprintf(stderr, "INVALID: ");
    fprintf(stderr, s,name1, name2, name3);
    fprintf(stderr, " at line %i\n",lineno);
    errors++;
    noErrors();
}
void reportStrError(char *s, char *name, int lineno)
{ 
  fprintf(stderr, "INVALID: ");
  fprintf(stderr, s,name);
  fprintf(stderr, " at line %i\n",lineno);
  errors++;
  noErrors();
}

void reportGlobalError(char *s)
{ fprintf(stderr, "INVALID: %s\n",s);
  errors++;
  noErrors();
}

void reportStrGlobalError(char *s, char *name)
{ fprintf(stderr, "INVALID: ");
  fprintf(stderr, s,name);
  fprintf(stderr, "\n");
  noErrors();
  errors++;
}

void noErrors()
{ if (errors!=0) {
     exit(1);
  }
}
