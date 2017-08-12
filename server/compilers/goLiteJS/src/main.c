#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "file.h"
#include "error.h"
#include "weed.h"
#include "memory.h"
#include "tree.h"
#include "pretty.h"
#include "symbol.h"
#include "type.h"
#include "codeJavascript.h"
#include <getopt.h>

extern FILE *yyin;
PROGRAM *program;
extern char *filename;
int getJavascriptTarget();
int pptype = 0;
int dumpsymtab = 0;
int verbose = 0;

int main(int argc, char *argv[])
{
   int option;

   while (1) {
     static struct option long_options[] = {
       {"dumpsymtab", no_argument, &dumpsymtab, 1},
       {"pptype",     no_argument, &pptype, 1},
       {"verbose",    no_argument, &verbose, 1},
     };

     // getopt_long stores the option index here
     int option_index = 0;

     option = getopt_long(argc, argv, "hv", long_options, &option_index);

     // Detect the end of the options
     if (option == -1)
       break;

     switch (option) {
       // flags are automatically set for long options

       case 'h':
         printf(
           "Usage: golitec [options] <filename>\n"
           "  -h              show this message\n"
           "  -v              print version number\n"
           "  --verbose       turn on verbose mode\n"
           "  --dumpsymtab    output the symbol table to a file named <filename>.symtab during typechecking phase\n"
           "  --pptype        pretty print the program with expression types to file <filename>.pptype.go\n"
         );
         exit(0);
         break;

       case 'v':
         printf("golitec v5.2.0\n");
         exit(0);
         break;

       case '?': // invalid option
         exit(1);
         break;

       default:
         break;
     }
   }

   if (optind >= argc) {
     // no more arguments beyond the options
     fprintf(stderr, "Error: No input file provided\n");
     exit(1);
   } else {
     yyin = fopen(argv[optind], "r");
     if (!yyin) {
       perror(argv[1]);
       exit(1);
     }
     filename = cleanFileName(argv[optind]);
   }

   if (verbose) printf("Current phase: parsing\n");
   yyparse();
   noErrors();

   if (verbose) printf("Current phase: weeding\n");
   weedPROGRAM(program);
   noErrors();

   if (verbose) printf("Current phase: typechecking\n");
   symPROGRAM(program);
   noErrors();

   typePROGRAM(program);
   noErrors();

   if(pptype) prettyPROGRAM(program);

   if (verbose) printf("Current phase: code generation\n");
   codePROGRAM(program);

   printf("VALID\n");

  return 0;
}

int getJavascriptTarget()
{
  filename = "temp";
  yyparse();
  weedPROGRAM(program);
  noErrors();
  // if (verbose) printf("Current phase: typechecking\n");
  symPROGRAM(program);
  noErrors();
  typePROGRAM(program);
  noErrors();
  prettyPROGRAM(program);
  codePROGRAM(program);
  // if (verbose) printf("Current phase: code generation\n");
  //char *target =  codePROGRAM(program);
  return 0;
  //return  target;
}
