%option noyywrap
%{
    #include "tree.h"
    #include "y.tab.h"
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    int hasSemicolon = 0;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

%}
%option yylineno
RAW_ESCAPED "\\"[abfnrtv\\]
RAW_DOUBLE_QUOTE "\\"[\"]
RAW_QUOTE "\\"[\']
RAW_STRING_QUOTE [`]
ALPHANUM [a-zA-Z0-9]
LETTER [a-zA-Z_]
DIGIT [0-9]
ASCII [ :;<=>?@!#$%&()*+,-.\[\]^_\{\}|~/]
ESCAPECHAR "\\"
ESCAPED [\a\b\f\r\t]
NEW_LINE [\n]
DOUBLE_QUOTE [\"]
QUOTE  [\']
%option yylineno
%%
[ \t\r]+      /* ignore whitespace */
[\n]          {if(hasSemicolon){hasSemicolon = 0;return ';';}}
"//".*        /* ignore line comments */
\/\*([^*]|[\r\n]|([*]+([^*/]|[\r\n])))*\*+\/  /*ignore comment*/
"break"       {hasSemicolon = 1;return tBREAK;} 
"case"        {hasSemicolon = 0;return tCASE;}
"chan"        {hasSemicolon = 0;return tCHAN;}
"const"       {hasSemicolon = 0;return tCONST;}
"continue"    {hasSemicolon = 1;return tCONTINUE;}
"default"     {hasSemicolon = 0;return tDEFAULT;}
"defer"       {hasSemicolon = 0;return tDEFER;}
"else"        {hasSemicolon = 0;return tELSE;}
"fallthrough" {hasSemicolon = 1;return tFALLTHROUGH;}
"for"         {hasSemicolon = 0;return tFOR;}
"func"        {hasSemicolon = 0;return tFUNC;}
"go"          {hasSemicolon = 0;return tGO;}
"goto"        {hasSemicolon = 0;return tGOTO;}
"if"          {hasSemicolon = 0;return tIF;}
"import"      {hasSemicolon = 0;return tIMPORT;}
"interface"   {hasSemicolon = 0;return tINTERFACE;}
"map"         {hasSemicolon = 0;return tMAP;}
"package"     {hasSemicolon = 0;return tPACKAGE;}
"range"       {hasSemicolon = 0;return tRANGE;}
"return"      {hasSemicolon = 1;return tRETURN;}
"select"      {hasSemicolon = 0;return tSELECT;}
"struct"      {hasSemicolon = 0;return tSTRUCT;}
"switch"      {hasSemicolon = 0;return tSWITCH;}
"type"        {hasSemicolon = 0;return tTYPE;}
"var"         {hasSemicolon = 0;return tVAR;}
"print"       {hasSemicolon = 0;return tPRINT;}
"println"     {hasSemicolon = 0;return tPRINTLN;}
"append"      {hasSemicolon = 0;return tAPPEND;}
"+"         {hasSemicolon = 0;return '+';}           /* operators and delimiters */
"-"         {hasSemicolon = 0;return '-';}
"*"         {hasSemicolon = 0;return '*';}
"/"         {hasSemicolon = 0;return '/';}
"%"         {hasSemicolon = 0;return '%';}
"&"         {hasSemicolon = 0;return '&';}
"|"         {hasSemicolon = 0;return '|';}
"^"         {hasSemicolon = 0;return '^';}
"<<"          {hasSemicolon = 0;return tLSHIFT;}
">>"          {hasSemicolon = 0;return tRSHIFT;}
"&^"          {hasSemicolon = 0;return tBITCLEAR;}
"+="         {hasSemicolon = 0;return tPLUSEQ;}
"-="          {hasSemicolon = 0;return tMINUSEQ;}
"*="          {hasSemicolon = 0;return tMULTEQ;}
"/="          {hasSemicolon = 0;return tDIVEQ;}
"%="          {hasSemicolon = 0;return tMODEQ;}
"&="          {hasSemicolon = 0;return tANDEQ;}
"|="          {hasSemicolon = 0;return tOREQ;}
"^="          {hasSemicolon = 0;return tXOREQ;}
"<<="         {hasSemicolon = 0;return tLSHIFTEQ;}
">>="         {hasSemicolon = 0;return tRSHIFTEQ;}
"&^="         {hasSemicolon = 0;return tCLEAREQ;}
"&&"          {hasSemicolon = 0;return tAND;}
"||"          {hasSemicolon = 0;return tOR;}
"<-"          {hasSemicolon = 0;return tRECEIVE;}
"++"          {hasSemicolon = 1;return tINC;}
"--"          {hasSemicolon = 1;return tDEC;}
"=="          {hasSemicolon = 0;return tEQUAL;}
"<"           {hasSemicolon = 0; return '<';}
">"         {hasSemicolon = 0;return '>';}
"="         {hasSemicolon = 0;return '=';}
"!"         {hasSemicolon = 0;return '!';}
"!="        {hasSemicolon = 0;return tNEQ;}
"<="          {hasSemicolon = 0;return tLEQ;}
">="          {hasSemicolon = 0;return tGEQ;}
":="          {hasSemicolon = 0;return tDECLANDASSIGN;}
"..."         {hasSemicolon = 0;return tDOTS;}
"("         {hasSemicolon = 0;return '(';}
")"         {hasSemicolon = 1;return ')';}
"["         {hasSemicolon = 0;return '[';}
"]"         {hasSemicolon = 1;return ']';}
"{"         {hasSemicolon = 0;return '{';}
"}"         {hasSemicolon = 1;return '}';}
","         {hasSemicolon = 0;return ',';}
"."         {hasSemicolon = 0;return '.';}
";"         {hasSemicolon = 0;return ';';}
":"         {hasSemicolon = 0;return ':';}
"_"         {hasSemicolon = 0;return '_';}
0|[1-9][0-9]*                                  {hasSemicolon = 1;yylval.intconst = atoi(yytext);return tDECCONST;}
0[0-7]*                                 {hasSemicolon = 1;sscanf(yytext, "%o",(int *) &yylval.intconst);return tOCTCONST;}
0[xX][0-9a-fA-F]+                       {hasSemicolon = 1;sscanf(yytext, "%x",(int *) &yylval.intconst);return tHEXCONST;}
(([0-9]*)\.[0-9]*)|(\.[0-9]+)    {hasSemicolon = 1;yylval.floatconst = atof(yytext); return tFLOATCONST;}
"'"(({ALPHANUM}|{DOUBLE_QUOTE}|{RAW_QUOTE}|{RAW_STRING_QUOTE}|{ASCII}|{RAW_ESCAPED}|{ESCAPED}))"'"  {hasSemicolon = 1;yylval.runeconst = (char *) malloc (strlen (yytext) + 1);
                                                                            sprintf (yylval.runeconst, "%s", yytext);return tRUNECONST;}
\"({ALPHANUM}|{RAW_DOUBLE_QUOTE}|{QUOTE}|{RAW_STRING_QUOTE}|{ASCII}|{ESCAPED}|{RAW_ESCAPED})*\"                    {hasSemicolon = 1;yylval.stringconst = (char *) malloc (strlen (yytext) + 1);
                                                                                                        sprintf (yylval.stringconst, "%s", yytext);return tSTRINGCONST;}
\`({ALPHANUM}|{ESCAPECHAR}|{DOUBLE_QUOTE}|{ASCII}|{QUOTE}|{ESCAPED}|{NEW_LINE})*\`    {hasSemicolon = 1;yylval.stringconst = (char *) malloc (strlen (yytext) + 1);
                                                                            sprintf(yylval.stringconst, "%s", yytext);return tRAWSTRINGCONST;}
({LETTER}({LETTER}|{DIGIT})*)             {hasSemicolon = 1;yylval.stringconst = (char *) malloc (strlen(yytext) + 1);
                                                    sprintf (yylval.stringconst, "%s", yytext);return tIDENTIFIER;}

<<EOF>> { static int first_eol = 0; return first_eol++ ? 0 : ';'; }

.                                       {fprintf(stderr, "INVALID Error line %d,  Incorrect character detected: %s\n",yylineno, yytext);exit(1);}
%%

