/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tAPPEND = 258,
    tBREAK = 259,
    tCASE = 260,
    tCHAN = 261,
    tCONST = 262,
    tCONTINUE = 263,
    tDEFAULT = 264,
    tDEFER = 265,
    tELSE = 266,
    tFALLTHROUGH = 267,
    tFOR = 268,
    tFUNC = 269,
    tGO = 270,
    tGOTO = 271,
    tIF = 272,
    tIMPORT = 273,
    tINTERFACE = 274,
    tMAP = 275,
    tPACKAGE = 276,
    tPRINT = 277,
    tPRINTLN = 278,
    tRANGE = 279,
    tRETURN = 280,
    tSELECT = 281,
    tSTRUCT = 282,
    tSWITCH = 283,
    tTYPE = 284,
    tVAR = 285,
    tEQUAL = 286,
    tLEQ = 287,
    tGEQ = 288,
    tNEQ = 289,
    tAND = 290,
    tOR = 291,
    tINC = 292,
    tDEC = 293,
    tLSHIFT = 294,
    tRSHIFT = 295,
    tLSHIFTEQ = 296,
    tRSHIFTEQ = 297,
    tDECLANDASSIGN = 298,
    tDOTS = 299,
    tRECEIVE = 300,
    tPLUSEQ = 301,
    tANDEQ = 302,
    tMINUSEQ = 303,
    tOREQ = 304,
    tMULTEQ = 305,
    tXOREQ = 306,
    tDIVEQ = 307,
    tMODEQ = 308,
    tBITCLEAR = 309,
    tCLEAREQ = 310,
    tDECCONST = 311,
    tOCTCONST = 312,
    tHEXCONST = 313,
    tFLOATCONST = 314,
    tRUNECONST = 315,
    tSTRINGCONST = 316,
    tRAWSTRINGCONST = 317,
    tIDENTIFIER = 318,
    UNARY = 319
  };
#endif
/* Tokens.  */
#define tAPPEND 258
#define tBREAK 259
#define tCASE 260
#define tCHAN 261
#define tCONST 262
#define tCONTINUE 263
#define tDEFAULT 264
#define tDEFER 265
#define tELSE 266
#define tFALLTHROUGH 267
#define tFOR 268
#define tFUNC 269
#define tGO 270
#define tGOTO 271
#define tIF 272
#define tIMPORT 273
#define tINTERFACE 274
#define tMAP 275
#define tPACKAGE 276
#define tPRINT 277
#define tPRINTLN 278
#define tRANGE 279
#define tRETURN 280
#define tSELECT 281
#define tSTRUCT 282
#define tSWITCH 283
#define tTYPE 284
#define tVAR 285
#define tEQUAL 286
#define tLEQ 287
#define tGEQ 288
#define tNEQ 289
#define tAND 290
#define tOR 291
#define tINC 292
#define tDEC 293
#define tLSHIFT 294
#define tRSHIFT 295
#define tLSHIFTEQ 296
#define tRSHIFTEQ 297
#define tDECLANDASSIGN 298
#define tDOTS 299
#define tRECEIVE 300
#define tPLUSEQ 301
#define tANDEQ 302
#define tMINUSEQ 303
#define tOREQ 304
#define tMULTEQ 305
#define tXOREQ 306
#define tDIVEQ 307
#define tMODEQ 308
#define tBITCLEAR 309
#define tCLEAREQ 310
#define tDECCONST 311
#define tOCTCONST 312
#define tHEXCONST 313
#define tFLOATCONST 314
#define tRUNECONST 315
#define tSTRINGCONST 316
#define tRAWSTRINGCONST 317
#define tIDENTIFIER 318
#define UNARY 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "golite.y" /* yacc.c:1915  */

  int intconst;
  float floatconst;
  char *runeconst;
  char *stringconst;
  PACK_DECL *packdecl;
  TYPE *type;
  STRUCT_DECL *structdecl;
  IDENTIFIER *id;
  EXP *exp;
  FOR_STMT *forstmt;
  STATEMENT *stmt;
  BLOCK *block;
  SWITCH_STMT *switchstmt;
  CASE_CLAUSE *caseclause;
  IFELSE *ifelse;
  FUNC_DECL *funcdecl;
  TYPE_DECL *typedecl;
  VAR_DECL *vardecl;
  TOP_DECL *topdecl;

#line 204 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
