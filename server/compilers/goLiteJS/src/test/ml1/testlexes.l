%{
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    int hasSemicolon = 0;
    int yylval;
%}
int hasSemicolon = 0;
%option noyywrap
%option yylineno
RAW_ESCAPED "\\"[abfnrtv\\]
RAW_DOUBLE_QUOTE "\\"[\"]
RAW_QUOTE "\\"[\']
RAW_STRING_QUOTE [`]
ALPHANUM [a-zA-Z0-9]
LETTER [a-zA-Z_]
DIGIT [0-9]
ASCII [ :;<=>?@!#$%&()*+,-.\[\]^_\{\}|~/]
ESCAPED [\a\b\f\n\r\t\b\\]
DOUBLE_QUOTE [\"]
QUOTE  [\']
%x C_COMMENT
%option yylineno
%%
[ \t\r]+      /* ignore whitespace */
[\n]          {if(hasSemicolon){hasSemicolon = 0;printf(";");}}
"//".*        /* ignore line comments */
\/\*([^*]|[\r\n]|([*]+([^*/]|[\r\n])))*\*+\/  {printf("comment");}/*ignore comment*/ 
"break"       {hasSemicolon = 1;printf("tBREAK");} 
"case"        {hasSemicolon = 0;printf("tCASE");}
"chan"        {hasSemicolon = 0;printf("tCHAN");}
"const"       {hasSemicolon = 0;printf("tCONST");}
"continue"    {hasSemicolon = 1;printf("tCONTINUE");}
"default"     {hasSemicolon = 0;printf("tDEFAULT");}
"defer"       {hasSemicolon = 0;printf("tDEFER");}
"else"        {hasSemicolon = 0;printf("tELSE");}
"fallthrough" {hasSemicolon = 1;printf("tFALLTHROUGH");}
"for"         {hasSemicolon = 0;printf("tFOR");}
"func"        {hasSemicolon = 0;printf("tFUNC");}
"go"          {hasSemicolon = 0;printf("tGO");}
"goto"        {hasSemicolon = 0;printf("tGOTO");}
"if"          {hasSemicolon = 0;printf("tIF");}
"import"      {hasSemicolon = 0;printf("tIMPORT");}
"interface"   {hasSemicolon = 0;printf("tINTERFACE");}
"map"         {hasSemicolon = 0;printf("tMAP");}
"package"     {hasSemicolon = 0;printf("tPACKAGE");}
"range"       {hasSemicolon = 0;printf("tRANGE");}
"return"      {hasSemicolon = 1;printf("tRETURN");}
"select"      {hasSemicolon = 0;printf("tSELECT");}
"struct"      {hasSemicolon = 0;printf("tSTRUCT");}
"switch"      {hasSemicolon = 0;printf("tSWITCH");}
"type"        {hasSemicolon = 0;printf("tTYPE");}
"var"         {hasSemicolon = 0;printf("tVAR");}
"print"       {hasSemicolon = 0;printf("tPRINT");}
"println"     {hasSemicolon = 0;printf("tPRINTLN");}
"append"      {hasSemicolon = 0;printf("tAPPEND");}
"+"         {hasSemicolon = 0;printf("+");}           /* operators and delimiters */
"-"         {hasSemicolon = 0;printf("-");}
"*"         {hasSemicolon = 0;printf("*");}
"/"         {hasSemicolon = 0;printf("/");}
"%"         {hasSemicolon = 0;printf("Per");}
"&"         {hasSemicolon = 0;printf("&");}
"|"         {hasSemicolon = 0;printf("|");}
"^"         {hasSemicolon = 0;printf("^");}
"<<"          {hasSemicolon = 0;printf("tLSHIFT");}
">>"          {hasSemicolon = 0;printf("tRSHIFT");}
"&^"          {hasSemicolon = 0;printf("tBITCLEAR");}
"+="         {hasSemicolon = 0;printf("tPLUSEQ");}
"-="          {hasSemicolon = 0;printf("tMINUSEQ");}
"*="          {hasSemicolon = 0;printf("tMULTEQ");}
"/="          {hasSemicolon = 0;printf("tDIVEQ");}
"%="          {hasSemicolon = 0;printf("tMODEQ");}
"&="          {hasSemicolon = 0;printf("tANDEQ");}
"|="          {hasSemicolon = 0;printf("tOREQ");}
"^="          {hasSemicolon = 0;printf("tXOREQ");}
"<<="         {hasSemicolon = 0;printf("tLSHIFTEQ");}
">>="         {hasSemicolon = 0;printf("tRSHIFTEQ");}
"&^="         {hasSemicolon = 0;printf("tCLEAREQ");}
"&&"          {hasSemicolon = 0;printf("tAND");}
"||"          {hasSemicolon = 0;printf("tOR");}
"<-"          {hasSemicolon = 0;printf("tRECEIVE");}
"++"          {hasSemicolon = 1;printf("tINC");}
"--"          {hasSemicolon = 1;printf("tDEC");}
"=="          {hasSemicolon = 0;printf("tEQUAL");}
"<"           {hasSemicolon = 0; printf("<");}
">"         {hasSemicolon = 0;printf(">");}
"="         {hasSemicolon = 0;printf("=");}
"!"         {hasSemicolon = 0;printf("!");}
"!="        {hasSemicolon = 0;printf("tNEQ");}
"<="          {hasSemicolon = 0;printf("tLEQ");}
">="          {hasSemicolon = 0;printf("tGEQ");}
":="          {hasSemicolon = 0;printf("tDECLANDASSIGN");}
"..."         {hasSemicolon = 0;printf("tDOTS");}
"("         {hasSemicolon = 0;printf("(");}
")"         {hasSemicolon = 1;printf(")");}
"["         {hasSemicolon = 0;printf("[");}
"]"         {hasSemicolon = 1;printf("]");}
"{"         {hasSemicolon = 0;printf("{");}
"}"         {hasSemicolon = 1;printf("}");}
","         {hasSemicolon = 0;printf(",");}
"."         {hasSemicolon = 0;printf(".");}
";"         {hasSemicolon = 0;printf(";");}
":"         {hasSemicolon = 0;printf(":");}
"_"         {hasSemicolon = 0;printf("_");}
0|[1-9][0-9]*               {hasSemicolon = 1;printf("tDECCONST: %d",atoi(yytext));}
0[0-7]*                                 {hasSemicolon = 1;sscanf(yytext, "%o",(int *) &yylval);printf("tOCTCONST: %d",yylval );}
0[xX][0-9a-fA-F]+                       {hasSemicolon = 1;sscanf(yytext, "%x",(int *) &yylval);printf("tHEXCONST: %d", yylval);}
(([0-9]*)\.[0-9]*)|(\.[0-9]+)    {hasSemicolon = 1;printf("tFLOATCONST: %f", atof(yytext));}
"'"(({ALPHANUM}|{DOUBLE_QUOTE}|{RAW_QUOTE}|{RAW_STRING_QUOTE}|{ASCII}|{RAW_ESCAPED}))"'"  {hasSemicolon = 1;printf("tRUNECONST: %c",yytext[1]);}
\"({ALPHANUM}|{RAW_DOUBLE_QUOTE}|{QUOTE}|{RAW_STRING_QUOTE}|{ASCII}|{ESCAPED})*\"                    {hasSemicolon = 1;char *na = (char *) malloc (strlen (yytext) + 1);
                                                                                                        sprintf (na, "%s", yytext);printf("tSTRINGCONST: %s",na);}
\`({ALPHANUM}|{RAW_ESCAPED}|{DOUBLE_QUOTE}|{ASCII}|{QUOTE}|{ESCAPED})*\`    {hasSemicolon = 1;char *na = (char *) malloc (strlen (yytext) + 1);
                                                                            sprintf (na, "%s", yytext);printf("tRAWSTRINGCONST: %s",na);}
({LETTER}({LETTER}|{DIGIT})*)             {hasSemicolon = 1;char *na =  (char *) malloc (strlen(yytext) + 1);
                                                    sprintf (na, "%s", yytext);printf("tIDENTIFIER: %s",na);}
.                                       {printf("INVALID Error line %d,  Incorrect character detected: %s",yylineno, yytext);exit(1);}
%%

int main()
{
    yylex();
}