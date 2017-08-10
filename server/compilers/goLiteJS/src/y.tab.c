/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "golite.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
extern PROGRAM *program;
int yylex();
extern int yylineno;


#line 76 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 11 "golite.y" /* yacc.c:355  */

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

#line 266 "y.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 297 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  333

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,     2,     2,     2,    72,    73,     2,
      77,    79,    70,    66,    81,    67,    75,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    78,
      64,    80,    65,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    86,    69,    82,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    68,    84,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    77,    80,    83,    84,    87,    88,    89,
      92,    93,    96,    97,   100,   101,   102,   105,   106,   109,
     110,   113,   116,   117,   120,   121,   122,   125,   128,   129,
     132,   133,   136,   137,   140,   141,   142,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   158,   159,
     160,   163,   164,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   181,   184,   185,   188,   189,
     190,   191,   194,   195,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   209,   210,   211,   212,   213,   214,   217,
     218,   221,   222,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   241,   242,   245,
     246,   247,   248,   249,   250,   253,   254,   257,   258,   259,
     260,   263,   264,   265,   266,   269,   270,   271,   272,   273,
     274,   277,   278,   279,   282,   283,   284,   285,   286,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   311,
     312,   315,   316,   319,   320,   321,   322,   323,   326,   327,
     330,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAPPEND", "tBREAK", "tCASE", "tCHAN",
  "tCONST", "tCONTINUE", "tDEFAULT", "tDEFER", "tELSE", "tFALLTHROUGH",
  "tFOR", "tFUNC", "tGO", "tGOTO", "tIF", "tIMPORT", "tINTERFACE", "tMAP",
  "tPACKAGE", "tPRINT", "tPRINTLN", "tRANGE", "tRETURN", "tSELECT",
  "tSTRUCT", "tSWITCH", "tTYPE", "tVAR", "tEQUAL", "tLEQ", "tGEQ", "tNEQ",
  "tAND", "tOR", "tINC", "tDEC", "tLSHIFT", "tRSHIFT", "tLSHIFTEQ",
  "tRSHIFTEQ", "tDECLANDASSIGN", "tDOTS", "tRECEIVE", "tPLUSEQ", "tANDEQ",
  "tMINUSEQ", "tOREQ", "tMULTEQ", "tXOREQ", "tDIVEQ", "tMODEQ",
  "tBITCLEAR", "tCLEAREQ", "tDECCONST", "tOCTCONST", "tHEXCONST",
  "tFLOATCONST", "tRUNECONST", "tSTRINGCONST", "tRAWSTRINGCONST",
  "tIDENTIFIER", "'<'", "'>'", "'+'", "'-'", "'|'", "'^'", "'*'", "'/'",
  "'%'", "'&'", "UNARY", "'.'", "'['", "'('", "';'", "')'", "'='", "','",
  "'_'", "'{'", "'}'", "':'", "']'", "'!'", "$accept", "program",
  "package", "topleveldecls", "topleveldecl", "vardecl", "varspecs",
  "varspec", "typedecl", "typespecs", "typespec", "functiondecl",
  "parameters", "parameter", "ids", "id", "nonblankids", "statements",
  "statement", "simplestatement", "simplepoststatement", "assignmentstmt",
  "shortassignmentstmt", "incrementdecrementstmt", "printstmt",
  "returnstmt", "ifstmt", "switchstmt", "caseclauses", "caseclause",
  "forstmt", "expressions", "expression", "expressionstmt", "leftexprs",
  "leftexpr", "litexpr", "intconst", "unaryexpr", "binaryexpr",
  "functioncallexpr", "appendexpr", "type", "structfields", "structfield",
  "block", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    60,    62,    43,    45,   124,    94,
      42,    47,    37,    38,   319,    46,    91,    40,    59,    41,
      61,    44,    95,   123,   125,    58,    93,    33
};
# endif

#define YYPACT_NINF -273

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-273)))

#define YYTABLE_NINF -120

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -33,    58,   -17,  -273,  -273,  -273,    13,    43,   -29,
     -31,  -273,    42,  -273,  -273,  -273,    20,   108,  -273,  -273,
    -273,  -273,  -273,  -273,   129,  -273,  -273,   -28,    49,  -273,
      72,   108,  -273,   -22,    45,   740,   -28,    62,   -76,  -273,
     150,  -273,  -273,  -273,  -273,   108,    63,    74,  -273,    77,
    -273,    83,    85,  -273,  -273,  -273,  -273,  -273,   740,   740,
     740,   740,   740,    84,  1235,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,   740,    71,   -28,  -273,   -51,  -273,
     108,  -273,  -273,  -273,   740,    92,    92,    92,  1235,    93,
      96,   101,   103,   107,   111,    92,   740,   740,   740,   740,
     740,   740,   740,   740,   740,   740,   740,   740,   740,   740,
     740,   740,   740,   740,   740,   740,   128,   740,   512,    84,
    -273,    81,  -273,  -273,  -273,  -273,   192,   126,  -273,  1039,
    -273,  -273,  -273,  -273,  -273,  -273,  1235,  1349,  1349,  1349,
    1349,  1329,  1282,    92,    92,    92,  1349,  1349,   799,   799,
     799,   799,    92,    92,    92,    92,  -273,   779,  -273,   -42,
     282,  -273,   144,  -273,  -273,   740,  -273,  -273,   134,   140,
     382,   447,   146,   147,   740,   415,  -273,  -273,  -273,   151,
     152,  -273,   154,  -273,  -273,  -273,  -273,   155,   156,   157,
     158,   159,   160,   -36,   345,   162,  -273,  1090,  -273,  -273,
     259,   164,   827,  -273,   740,   165,   827,   545,   577,  1235,
     610,  -273,   166,   880,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,   740,   740,   642,  -273,  -273,   740,   740,   740,
     740,   740,   740,   740,   740,   740,   740,   740,  -273,  -273,
     480,  1139,   675,  -273,   827,   740,   217,  -273,    24,  -273,
      34,  -273,   933,     1,   707,  -273,    84,    84,  -273,   -21,
    1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,
    1235,    81,    81,    37,  -273,   480,   480,  1187,   234,   827,
       6,  -273,  -273,     4,  -273,   740,   161,  -273,  -273,  -273,
     986,     9,  -273,  -273,    81,    81,  -273,    81,    81,  -273,
     480,     6,   236,  -273,  -273,  -273,    10,    19,  -273,    11,
    -273,  -273,  -273,  -273,  -273,  -273,    81,    81,  -273,  -273,
    -273,     6,  -273,  -273,   350,  -273,    12,  -273,  -273,  -273,
    -273,   350,  -273
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     1,     5,     2,     0,     0,
       0,     3,     0,     7,     8,     9,     0,     0,    19,    17,
      30,    12,    31,    10,     0,    28,     6,    24,     0,   164,
       0,     0,    21,     0,     0,     0,     0,    14,     0,    25,
       0,   168,   131,   132,   133,     0,     0,     0,    18,     0,
      11,     0,     0,   127,   128,   129,   130,   122,     0,     0,
       0,     0,     0,    16,   107,   109,   110,   111,   126,   112,
     113,   116,   114,    29,     0,     0,     0,    27,     0,   165,
       0,   163,    20,    13,     0,   135,   136,   138,     0,   109,
     110,   111,   112,   113,   114,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      34,     0,    23,    26,    32,   167,     0,     0,   166,     0,
     115,   121,   125,   134,   139,   161,   108,   151,   154,   156,
     152,   157,   158,   147,   148,   150,   153,   155,   140,   141,
     142,   143,   144,   145,   146,   149,   123,     0,   160,     0,
       0,    22,     0,   170,   169,     0,   124,   159,     0,     0,
       0,     0,     0,     0,    72,     0,    35,   118,   171,     0,
       0,    36,     0,    48,    52,    49,    51,     0,     0,     0,
       0,     0,   109,     0,   110,     0,    33,     0,    47,    46,
       0,     0,     0,    93,     0,     0,     0,     0,     0,    73,
       0,    89,     0,     0,    38,    39,    37,    40,    41,    42,
      43,    44,     0,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,   162,
       0,     0,     0,    94,     0,     0,    76,    70,     0,    71,
       0,    89,     0,     0,     0,    89,    65,    53,   120,   110,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,   109,     0,   102,     0,     0,     0,    75,     0,
       0,    68,    69,     0,    89,     0,     0,    88,    90,    89,
       0,     0,    99,   106,     0,   109,   101,     0,   109,   100,
       0,     0,    74,    79,    82,    87,     0,     0,    34,     0,
      89,    85,    96,   104,    97,   105,     0,   109,    98,    78,
      81,     0,    84,    34,    92,    86,     0,    95,   103,    77,
      80,    91,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,  -273,  -273,   241,  -273,   215,   243,  -273,
     221,  -273,  -273,   182,   -23,   223,  -273,  -216,  -273,   -32,
    -154,  -273,  -273,  -273,  -273,  -273,  -272,  -273,  -132,  -273,
    -273,   -63,   -34,   -59,  -150,   -61,   203,   237,   205,   210,
    -273,   213,     7,  -273,  -273,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    12,   179,    34,    23,   180,    33,
      19,    15,    38,    39,    24,    25,   126,   160,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   253,   288,
     191,    63,    88,    65,   193,    66,    67,    68,    69,    70,
      71,    72,    32,    78,   127,   195
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    64,    89,    75,    40,    76,   285,   222,   303,   285,
     286,   119,   124,   286,   285,   285,   285,   285,   286,   286,
     286,   286,  -119,   171,    85,    86,    87,     8,    95,   319,
       4,    37,    20,   125,    17,    20,     1,   167,    47,    96,
      64,    17,     9,    10,   223,   224,    21,    77,    18,   329,
     129,    22,    79,    40,    22,   159,   122,    48,     5,  -119,
    -119,     6,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   121,   157,    64,   287,   271,   128,   305,   120,
     273,    11,   324,   311,   322,   325,   332,    27,    28,   194,
      96,   192,   161,   281,   323,    96,    16,   331,    20,   194,
     194,   192,   192,   282,   194,    96,   192,   223,   224,   283,
      26,   294,   297,   291,    50,   273,   273,    22,    42,    43,
      44,   197,    41,   163,    29,    28,   202,   206,   201,   205,
     209,   213,    74,   212,   248,   250,   316,    30,    31,    80,
     273,   203,   306,    81,   120,    82,    28,   309,    45,   256,
     257,    83,    84,   259,   120,    96,   241,   116,   117,   118,
     244,    29,   130,    64,    64,   131,   252,    28,   326,   194,
     132,   272,   133,   243,    30,    31,   134,   246,    64,    64,
     135,   156,    29,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   164,    30,    31,   196,   277,    35,
      36,   279,   198,    29,   194,   194,   295,   298,   199,    28,
     290,   274,   307,   207,   208,   278,    30,    31,   280,   214,
     215,    36,   216,   217,   218,   219,   220,   221,   -50,   194,
     238,   317,   242,   245,   254,   301,   308,   321,    13,    51,
      14,    64,   292,   293,    49,    29,   296,   299,   123,    73,
     302,   304,    52,   194,    91,   192,    92,    46,    30,    31,
     194,    93,   192,   162,    94,   312,   313,     0,   314,   315,
       0,   318,   320,     0,     0,    52,   168,     0,     0,     0,
     169,     0,     0,     0,     0,   170,     0,   327,   328,   171,
       0,     0,   330,     0,   172,   173,     0,   174,     0,     0,
     175,     9,    10,     0,     0,    42,    43,    44,    53,    54,
      55,    56,    57,     0,     0,    58,    59,     0,    60,     0,
       0,     0,     0,     0,     0,     0,    61,   240,    42,    43,
      44,    53,    54,    55,    56,    57,    62,     0,    58,    59,
       0,    60,     0,    52,   168,     0,     0,     0,   169,    61,
     176,     0,     0,   170,   177,   120,   178,   171,     0,    62,
       0,     0,   172,   173,     0,   174,     0,     0,   175,     9,
      10,     0,   225,   226,     0,    52,   227,   228,  -117,     0,
       0,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,     0,     0,     0,     0,     0,    42,    43,    44,    53,
      54,    55,    56,    57,     0,     0,    58,    59,    52,    60,
       0,     0,     0,     0,     0,  -117,  -117,    61,   176,     0,
       0,     0,   177,   120,     0,     0,     0,    62,    42,    43,
      44,    53,    54,    55,    56,    57,     0,     0,    58,    59,
      52,    60,     0,     0,     0,     0,     0,     0,     0,    61,
     200,     0,     0,     0,   177,   120,     0,     0,     0,    62,
       0,    42,    43,    44,    53,    54,    55,    56,    57,     0,
       0,    58,    59,    52,    60,     0,     0,     0,     0,     0,
       0,     0,    61,   210,     0,     0,     0,   177,   211,     0,
       0,     0,    62,    42,    43,    44,    53,    54,    55,    56,
      57,     0,     0,    58,    59,    52,    60,     0,     0,     0,
       0,     0,     0,     0,    61,   204,     0,     0,     0,   177,
       0,     0,     0,     0,    62,     0,    42,    43,    44,    53,
      54,    55,    56,    57,     0,     0,    58,    59,    52,    60,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,   177,   120,     0,     0,     0,    62,    42,    43,
      44,    53,    54,    55,    56,    57,     0,     0,    58,    59,
      52,    60,     0,     0,     0,     0,     0,     0,     0,    61,
       0,   158,     0,     0,     0,     0,     0,     0,     0,    62,
       0,    42,    43,    44,    53,    54,    55,    56,    57,     0,
       0,    58,    59,    52,    60,     0,     0,     0,     0,     0,
       0,     0,    61,     0,   247,     0,     0,     0,     0,     0,
       0,     0,    62,    42,    43,    44,    53,    54,    55,    56,
      57,     0,     0,    58,    59,    52,    60,     0,     0,     0,
       0,     0,     0,     0,    61,     0,   249,     0,     0,     0,
       0,     0,     0,     0,    62,     0,    42,    43,    44,    53,
      54,    55,    56,    57,     0,     0,    58,    59,    52,    60,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,   251,     0,     0,     0,    62,    42,    43,
      44,    53,    54,    55,    56,    57,     0,     0,    58,    59,
      52,    60,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,   258,     0,     0,     0,     0,    62,
       0,    42,    43,    44,    53,    54,    55,    56,    57,     0,
       0,    58,    59,    52,    60,     0,     0,     0,     0,     0,
       0,     0,    61,   276,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    42,    43,    44,    53,    54,    55,    56,
      57,     0,     0,    58,    59,     0,    60,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
     289,     0,     0,     0,    62,     0,    42,    43,    44,    53,
      54,    55,    56,    57,     0,     0,    58,    59,     0,    60,
      97,    98,    99,   100,   101,   102,     0,    61,   103,   104,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,   103,   104,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   105,   116,   117,   118,     0,    97,    98,
      99,   100,   101,   102,     0,   166,   103,   104,     0,   112,
     113,   114,   115,     0,   116,   117,   118,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   118,     0,     0,     0,     0,     0,
     120,    97,    98,    99,   100,   101,   102,     0,     0,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,   117,   118,     0,     0,
       0,     0,     0,   255,    97,    98,    99,   100,   101,   102,
       0,     0,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   117,
     118,     0,     0,     0,     0,     0,   284,    97,    98,    99,
     100,   101,   102,     0,     0,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   117,   118,     0,     0,     0,     0,     0,   310,
      97,    98,    99,   100,   101,   102,     0,     0,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,     0,     0,     0,
     165,    97,    98,    99,   100,   101,   102,     0,     0,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,   117,   118,     0,   239,
      97,    98,    99,   100,   101,   102,     0,     0,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,   275,    97,    98,
      99,   100,   101,   102,     0,     0,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   118,   300,    97,    98,    99,   100,
     101,   102,     0,     0,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,   117,   118,    97,    98,    99,   100,   101,     0,     0,
       0,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,   117,   118,
      97,    98,    99,   100,     0,     0,     0,     0,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,   103,   104,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   105,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
      61,    35,    61,    79,    27,    81,     5,    43,   280,     5,
       9,    74,    63,     9,     5,     5,     5,     5,     9,     9,
       9,     9,    43,    17,    58,    59,    60,    14,    62,   301,
      63,    24,    63,    84,    63,    63,    21,    79,    31,    81,
      74,    63,    29,    30,    80,    81,    77,    40,    77,   321,
      84,    82,    45,    76,    82,   118,    75,    79,     0,    80,
      81,    78,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    75,   117,   118,    84,   240,    80,    84,    83,
     240,    78,   308,    84,    84,    84,    84,    77,    27,   160,
      81,   160,   121,    79,    85,    81,    63,   323,    63,   170,
     171,   170,   171,    79,   175,    81,   175,    80,    81,   251,
      78,   275,   276,   255,    79,   275,   276,    82,    56,    57,
      58,   165,    83,   126,    63,    27,   170,   171,   170,   171,
     174,   175,    80,   175,   207,   208,   300,    76,    77,    86,
     300,   170,   284,    79,    83,    78,    27,   289,    86,   222,
     223,    78,    77,   224,    83,    81,   200,    75,    76,    77,
     204,    63,    79,   207,   208,    79,   210,    27,   310,   240,
      79,   240,    79,   202,    76,    77,    79,   206,   222,   223,
      79,    63,    63,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,    78,    76,    77,    63,   242,    80,
      81,   245,    78,    63,   275,   276,   275,   276,    78,    27,
     254,   240,   285,    77,    77,   244,    76,    77,    11,    78,
      78,    81,    78,    78,    78,    78,    78,    78,    78,   300,
      78,   300,    78,    78,    78,    11,    85,    11,     7,    34,
       7,   285,   271,   272,    33,    63,   275,   276,    76,    36,
     279,   280,     3,   324,    61,   324,    61,    30,    76,    77,
     331,    61,   331,    81,    61,   294,   295,    -1,   297,   298,
      -1,   300,   301,    -1,    -1,     3,     4,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    13,    -1,   316,   317,    17,
      -1,    -1,   321,    -1,    22,    23,    -1,    25,    -1,    -1,
      28,    29,    30,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    66,    67,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    56,    57,
      58,    59,    60,    61,    62,    63,    87,    -1,    66,    67,
      -1,    69,    -1,     3,     4,    -1,    -1,    -1,     8,    77,
      78,    -1,    -1,    13,    82,    83,    84,    17,    -1,    87,
      -1,    -1,    22,    23,    -1,    25,    -1,    -1,    28,    29,
      30,    -1,    37,    38,    -1,     3,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    66,    67,     3,    69,
      -1,    -1,    -1,    -1,    -1,    80,    81,    77,    78,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    87,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    66,    67,
       3,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    87,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    66,    67,     3,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    82,    83,    -1,
      -1,    -1,    87,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    66,    67,     3,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    87,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    66,    67,     3,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    87,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    66,    67,
       3,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    66,    67,     3,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    66,    67,     3,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    66,    67,     3,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    87,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    66,    67,
       3,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    87,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    66,    67,     3,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    87,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    66,    67,    -1,    69,
      31,    32,    33,    34,    35,    36,    -1,    77,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    54,    75,    76,    77,    -1,    31,    32,
      33,    34,    35,    36,    -1,    86,    39,    40,    -1,    70,
      71,    72,    73,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    77,    -1,    -1,    -1,
      81,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    76,    77,    -1,    79,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    77,    78,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    78,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    75,    76,    77,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    54,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    89,    90,    63,     0,    78,    91,    14,    29,
      30,    78,    92,    93,    96,    99,    63,    63,    77,    98,
      63,    77,    82,    95,   102,   103,    78,    77,    27,    63,
      76,    77,   130,    97,    94,    80,    81,   130,   100,   101,
     102,    83,    56,    57,    58,    86,   125,   130,    79,    98,
      79,    95,     3,    59,    60,    61,    62,    63,    66,    67,
      69,    77,    87,   119,   120,   121,   123,   124,   125,   126,
     127,   128,   129,   103,    80,    79,    81,   130,   131,   130,
      86,    79,    78,    78,    77,   120,   120,   120,   120,   121,
     123,   124,   126,   127,   129,   120,    81,    31,    32,    33,
      34,    35,    36,    39,    40,    54,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    75,    76,    77,   119,
      83,   130,   133,   101,    63,    84,   104,   132,   130,   120,
      79,    79,    79,    79,    79,    79,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,    63,   120,    79,   119,
     105,   133,    81,   130,    78,    81,    86,    79,     4,     8,
      13,    17,    22,    23,    25,    28,    78,    82,    84,    93,
      96,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   118,   121,   122,   123,   133,    63,   120,    78,    78,
      78,   107,   120,   133,    78,   107,   120,    77,    77,   120,
      78,    83,   107,   120,    78,    78,    78,    78,    78,    78,
      78,    78,    43,    80,    81,    37,    38,    41,    42,    46,
      47,    48,    49,    50,    51,    52,    53,    55,    78,    79,
      78,   120,    78,   133,   120,    78,   133,    79,   119,    79,
     119,    83,   120,   116,    78,    83,   119,   119,    82,   123,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   108,   121,   122,   133,    78,    78,   120,   133,   120,
      11,    79,    79,   116,    83,     5,     9,    84,   117,    83,
     120,   116,   133,   133,   108,   121,   133,   108,   121,   133,
      78,    11,   133,   114,   133,    84,   116,   119,    85,   116,
      83,    84,   133,   133,   133,   133,   108,   121,   133,   114,
     133,    11,    84,    85,   105,    84,   116,   133,   133,   114,
     133,   105,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    90,    91,    91,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    96,    96,    97,
      97,    98,    99,    99,   100,   100,   100,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   111,   111,   112,   112,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   120,   120,   120,   120,   121,   121,   122,   122,   122,
     122,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     124,   125,   125,   125,   126,   126,   126,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   130,   130,   131,   131,
     132,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     2,     0,     3,     1,     1,     1,
       2,     4,     0,     3,     2,     4,     3,     2,     4,     0,
       3,     2,     7,     6,     0,     1,     3,     2,     1,     3,
       1,     1,     1,     3,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     4,
       3,     3,     1,     2,     5,     4,     3,     7,     6,     5,
       7,     6,     5,     7,     6,     5,     6,     5,     4,     0,
       2,     4,     3,     2,     3,     7,     6,     6,     6,     5,
       5,     5,     4,     7,     6,     6,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     1,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     6,     3,     1,     3,     4,     4,     0,     3,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 76 "golite.y" /* yacc.c:1661  */
    { program = makePROGRAM((yyvsp[-2].packdecl), (yyvsp[0].topdecl), (yylsp[0]).last_line); }
#line 1934 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 77 "golite.y" /* yacc.c:1661  */
    { program = makePROGRAM((yyvsp[-3].packdecl), (yyvsp[-1].topdecl), (yylsp[-1]).last_line); }
#line 1940 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 80 "golite.y" /* yacc.c:1661  */
    { (yyval.packdecl) = makePACK_DECL((yyvsp[0].stringconst), (yylsp[0]).first_line); }
#line 1946 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 83 "golite.y" /* yacc.c:1661  */
    { (yyval.topdecl) = NULL; }
#line 1952 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 84 "golite.y" /* yacc.c:1661  */
    { (yyval.topdecl) = (yyvsp[-1].topdecl); (yyval.topdecl)->next = (yyvsp[-2].topdecl); }
#line 1958 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 87 "golite.y" /* yacc.c:1661  */
    { (yyval.topdecl) = makeTOPDECLvar((yyvsp[0].vardecl)); }
#line 1964 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 88 "golite.y" /* yacc.c:1661  */
    { (yyval.topdecl) = makeTOPDECLtype((yyvsp[0].typedecl)); }
#line 1970 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 89 "golite.y" /* yacc.c:1661  */
    { (yyval.topdecl) = makeTOPDECLfunc((yyvsp[0].funcdecl)); }
#line 1976 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 92 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = (yyvsp[0].vardecl); }
#line 1982 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 93 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = (yyvsp[-1].vardecl); }
#line 1988 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 96 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = NULL; }
#line 1994 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 97 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = (yyvsp[-1].vardecl); (yyval.vardecl)->next = (yyvsp[-2].vardecl); }
#line 2000 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 100 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = makeDECLvar((yyvsp[-1].id), (yyvsp[0].type), NULL,(yylsp[-1]).first_line); }
#line 2006 "y.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 101 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = makeDECLvar((yyvsp[-3].id), (yyvsp[-2].type), (yyvsp[0].exp),(yylsp[-3]).first_line); }
#line 2012 "y.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 102 "golite.y" /* yacc.c:1661  */
    { (yyval.vardecl) = makeDECLvar((yyvsp[-2].id), NULL, (yyvsp[0].exp),(yylsp[-2]).first_line); }
#line 2018 "y.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 105 "golite.y" /* yacc.c:1661  */
    { (yyval.typedecl) = (yyvsp[0].typedecl); }
#line 2024 "y.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 106 "golite.y" /* yacc.c:1661  */
    { (yyval.typedecl) = (yyvsp[-1].typedecl); }
#line 2030 "y.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 109 "golite.y" /* yacc.c:1661  */
    { (yyval.typedecl) = NULL; }
#line 2036 "y.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 110 "golite.y" /* yacc.c:1661  */
    { (yyval.typedecl) = (yyvsp[-1].typedecl); (yyval.typedecl)->next = (yyvsp[-2].typedecl); }
#line 2042 "y.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 113 "golite.y" /* yacc.c:1661  */
    { (yyval.typedecl) = makeDECLtype((yyvsp[-1].stringconst), (yyvsp[0].type),(yylsp[-1]).first_line); }
#line 2048 "y.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 116 "golite.y" /* yacc.c:1661  */
    { (yyval.funcdecl) = makeDECLfunc((yyvsp[-5].stringconst), (yyvsp[-3].id), (yyvsp[-1].type), (yyvsp[0].block), (yylsp[-5]).first_line); }
#line 2054 "y.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 117 "golite.y" /* yacc.c:1661  */
    { (yyval.funcdecl) = makeDECLfunc((yyvsp[-4].stringconst), (yyvsp[-2].id), NULL, (yyvsp[0].block),(yylsp[-4]).first_line); }
#line 2060 "y.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 120 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = NULL; }
#line 2066 "y.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 122 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = (yyvsp[0].id); while ((yyvsp[0].id)->next) (yyvsp[0].id) = (yyvsp[0].id)->next; (yyvsp[0].id)->next = (yyvsp[-2].id); }
#line 2072 "y.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 125 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = (yyvsp[-1].id); assignIDTYPE((yyval.id), (yyvsp[0].type)); }
#line 2078 "y.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 129 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = (yyvsp[0].id); (yyval.id)->next = (yyvsp[-2].id); }
#line 2084 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 132 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = makeID((yyvsp[0].stringconst), NULL); }
#line 2090 "y.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 133 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = makeID("_", NULL); }
#line 2096 "y.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 136 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = makeID((yyvsp[0].stringconst), NULL); }
#line 2102 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 137 "golite.y" /* yacc.c:1661  */
    { (yyval.id) = makeID((yyvsp[0].stringconst), NULL); (yyval.id)->next = (yyvsp[-2].id); }
#line 2108 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 140 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = NULL; }
#line 2114 "y.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 142 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = (yyvsp[0].stmt); (yyval.stmt)->next = (yyvsp[-1].stmt); }
#line 2120 "y.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 146 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTvardecl((yyvsp[-1].vardecl),(yylsp[-1]).first_line); }
#line 2126 "y.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 147 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTtypedecl((yyvsp[-1].typedecl),(yylsp[-1]).first_line); }
#line 2132 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 150 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTifelse((yyvsp[-1].ifelse),(yylsp[-1]).first_line); }
#line 2138 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 151 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTswitch((yyvsp[-1].switchstmt), (yylsp[-1]).first_line); }
#line 2144 "y.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 152 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTfor((yyvsp[-1].forstmt),(yylsp[-1]).first_line); }
#line 2150 "y.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 153 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTblock((yyvsp[-1].block),(yylsp[-1]).first_line); }
#line 2156 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 154 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTcontinue((yylsp[-1]).first_line); }
#line 2162 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 155 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTbreak((yylsp[-1]).first_line); }
#line 2168 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 167 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), EQ,(yylsp[-1]).first_line); }
#line 2174 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 168 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), LSHIFTEQ,(yylsp[-1]).first_line); }
#line 2180 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 169 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), RSHIFTEQ,(yylsp[-1]).first_line); }
#line 2186 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 170 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), PLUSEQ,(yylsp[-1]).first_line); }
#line 2192 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 171 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), ANDEQ,(yylsp[-1]).first_line); }
#line 2198 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 172 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), MINUSEQ,(yylsp[-1]).first_line); }
#line 2204 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 173 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), OREQ,(yylsp[-1]).first_line); }
#line 2210 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 174 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), MULTEQ,(yylsp[-1]).first_line); }
#line 2216 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 175 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), XOREQ,(yylsp[-1]).first_line); }
#line 2222 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 176 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), DIVEQ,(yylsp[-1]).first_line); }
#line 2228 "y.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 177 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), MODEQ,(yylsp[-1]).first_line); }
#line 2234 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 178 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-2].exp), (yyvsp[0].exp), CLEAREQ,(yylsp[-1]).first_line); }
#line 2240 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 181 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTshortassign((yyvsp[-2].exp), (yyvsp[0].exp),(yylsp[-1]).first_line); }
#line 2246 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 184 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-1].exp), NULL, INC, (yylsp[0]).first_line); }
#line 2252 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 185 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTassign((yyvsp[-1].exp), NULL, DEC,(yylsp[0]).first_line); }
#line 2258 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 188 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTprint((yyvsp[-1].exp), 0,(yylsp[-1]).first_line); }
#line 2264 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 189 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTprint((yyvsp[-1].exp), 1,(yylsp[-1]).first_line); }
#line 2270 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 190 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTprint(NULL, 0,(yylsp[-2]).first_line); }
#line 2276 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 191 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTprint(NULL, 1,(yylsp[-2]).first_line); }
#line 2282 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 194 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTreturn(NULL,(yylsp[0]).first_line); }
#line 2288 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 195 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTreturn((yyvsp[0].exp),(yylsp[0]).first_line); }
#line 2294 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 198 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE((yyvsp[-3].stmt), (yyvsp[-1].exp), (yyvsp[0].block), NULL, NULL, (yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2300 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 199 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE(NULL, (yyvsp[-1].exp), (yyvsp[0].block), NULL, NULL, (yylsp[-3]).first_line, (yylsp[0]).last_line); }
#line 2306 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 200 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE(NULL, (yyvsp[-1].exp), (yyvsp[0].block), NULL, NULL, (yylsp[-2]).first_line, (yylsp[0]).last_line); }
#line 2312 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 201 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE((yyvsp[-5].stmt), (yyvsp[-3].exp), (yyvsp[-2].block), NULL, (yyvsp[0].ifelse), (yylsp[-6]).first_line, (yylsp[0]).last_line); }
#line 2318 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 202 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE(NULL, (yyvsp[-3].exp), (yyvsp[-2].block), NULL, (yyvsp[0].ifelse), (yylsp[-5]).first_line, (yylsp[0]).last_line); }
#line 2324 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 203 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE(NULL, (yyvsp[-3].exp), (yyvsp[-2].block), NULL, (yyvsp[0].ifelse), (yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2330 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 204 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE((yyvsp[-5].stmt), (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), NULL, (yylsp[-6]).first_line, (yylsp[0]).last_line); }
#line 2336 "y.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 205 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE(NULL, (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), NULL, (yylsp[-5]).first_line, (yylsp[0]).last_line); }
#line 2342 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 206 "golite.y" /* yacc.c:1661  */
    { (yyval.ifelse) = makeIFELSE(NULL, (yyvsp[-3].exp), (yyvsp[-2].block), (yyvsp[0].block), NULL, (yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2348 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 209 "golite.y" /* yacc.c:1661  */
    { (yyval.switchstmt) = makeSWITCH((yyvsp[-5].stmt), (yyvsp[-3].exp), (yyvsp[-1].caseclause), (yylsp[0]).last_line); }
#line 2354 "y.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 210 "golite.y" /* yacc.c:1661  */
    { (yyval.switchstmt) = makeSWITCH(NULL, (yyvsp[-3].exp), (yyvsp[-1].caseclause), (yylsp[0]).last_line); }
#line 2360 "y.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 211 "golite.y" /* yacc.c:1661  */
    { (yyval.switchstmt) = makeSWITCH(NULL, (yyvsp[-3].exp), (yyvsp[-1].caseclause), (yylsp[0]).last_line); }
#line 2366 "y.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 212 "golite.y" /* yacc.c:1661  */
    { (yyval.switchstmt) = makeSWITCH((yyvsp[-4].stmt), NULL, (yyvsp[-1].caseclause), (yylsp[0]).last_line); }
#line 2372 "y.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 213 "golite.y" /* yacc.c:1661  */
    { (yyval.switchstmt) = makeSWITCH(NULL, NULL, (yyvsp[-1].caseclause), (yylsp[0]).last_line); }
#line 2378 "y.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 214 "golite.y" /* yacc.c:1661  */
    { (yyval.switchstmt) = makeSWITCH(NULL, NULL, (yyvsp[-1].caseclause), (yylsp[0]).last_line); }
#line 2384 "y.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 217 "golite.y" /* yacc.c:1661  */
    { (yyval.caseclause) = NULL; }
#line 2390 "y.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 218 "golite.y" /* yacc.c:1661  */
    { (yyval.caseclause) = (yyvsp[0].caseclause); (yyval.caseclause)->next = (yyvsp[-1].caseclause); }
#line 2396 "y.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 221 "golite.y" /* yacc.c:1661  */
    { (yyval.caseclause) = makeCASE((yyvsp[0].stmt), (yyvsp[-2].exp),(yylsp[-3]).first_line, (yylsp[0]).last_line); }
#line 2402 "y.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 222 "golite.y" /* yacc.c:1661  */
    { (yyval.caseclause) = makeCASE((yyvsp[0].stmt), NULL,(yylsp[-2]).first_line, (yylsp[0]).last_line); }
#line 2408 "y.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 225 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, NULL, NULL, (yyvsp[0].block),(yylsp[-1]).first_line, (yylsp[0]).last_line); }
#line 2414 "y.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 226 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-1].exp), NULL, NULL, (yyvsp[0].block),(yylsp[-1]).first_line, (yylsp[0]).last_line); }
#line 2420 "y.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 227 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-3].exp), (yyvsp[-5].stmt), (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-6]).first_line, (yylsp[0]).last_line); }
#line 2426 "y.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 228 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-3].exp), NULL, (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2432 "y.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 229 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, (yyvsp[-4].stmt), (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-5]).first_line, (yylsp[0]).last_line); }
#line 2438 "y.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 230 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-2].exp), (yyvsp[-4].stmt), NULL, (yyvsp[0].block),(yylsp[-5]).first_line, (yylsp[0]).last_line); }
#line 2444 "y.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 231 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, NULL, (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2450 "y.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 232 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, (yyvsp[-3].stmt), NULL, (yyvsp[0].block),(yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2456 "y.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 233 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-2].exp), NULL, NULL, (yyvsp[0].block),(yylsp[-2]).first_line, (yylsp[0]).last_line); }
#line 2462 "y.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 234 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, NULL, NULL, (yyvsp[0].block),(yylsp[0]).first_line, (yylsp[0]).last_line); }
#line 2468 "y.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 235 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-3].exp), (yyvsp[-5].stmt), (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-3]).first_line, (yylsp[0]).last_line); }
#line 2474 "y.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 236 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT((yyvsp[-3].exp), NULL, (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-3]).first_line, (yylsp[0]).last_line); }
#line 2480 "y.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 237 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, (yyvsp[-4].stmt), (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2486 "y.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 238 "golite.y" /* yacc.c:1661  */
    { (yyval.forstmt) = makeFORSTMT(NULL, NULL, (yyvsp[-1].stmt), (yyvsp[0].block),(yylsp[-4]).first_line, (yylsp[0]).last_line); }
#line 2492 "y.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 242 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = (yyvsp[0].exp); (yyval.exp)->next = (yyvsp[-2].exp); }
#line 2498 "y.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 245 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = (yyvsp[0].stmt)->val.expS.exp; }
#line 2504 "y.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 253 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 2510 "y.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 254 "golite.y" /* yacc.c:1661  */
    { (yyval.stmt) = makeSTATEMENTexp((yyvsp[0].exp),(yylsp[0]).first_line); }
#line 2516 "y.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 258 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPid("_",(yylsp[0]).first_line); }
#line 2522 "y.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 259 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = (yyvsp[0].exp); (yyval.exp)->next = (yyvsp[-2].exp); }
#line 2528 "y.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 260 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPid("_",(yylsp[-2]).first_line); (yyval.exp)->next = (yyvsp[-2].exp); }
#line 2534 "y.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 263 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPparen((yyvsp[-1].exp),(yylsp[-1]).first_line); }
#line 2540 "y.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 264 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPid((yyvsp[0].stringconst),(yylsp[0]).first_line); }
#line 2546 "y.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 265 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPstructfield((yyvsp[-2].exp), (yyvsp[0].stringconst),(yylsp[-1]).first_line); }
#line 2552 "y.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 266 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXParrayaccess((yyvsp[-3].exp), (yyvsp[-1].exp),(yylsp[-1]).first_line); }
#line 2558 "y.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 269 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPparen((yyvsp[-1].exp),(yylsp[-1]).first_line); }
#line 2564 "y.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 270 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPint((yyvsp[0].intconst), (yylsp[0]).first_line); }
#line 2570 "y.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 271 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPfloat((yyvsp[0].floatconst),(yylsp[0]).first_line); }
#line 2576 "y.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 272 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPrune((yyvsp[0].runeconst),(yylsp[0]).first_line); }
#line 2582 "y.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 273 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPstring((yyvsp[0].stringconst),(yylsp[0]).first_line); }
#line 2588 "y.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 274 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPrawstring((yyvsp[0].stringconst),(yylsp[0]).first_line); }
#line 2594 "y.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 282 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPparen((yyvsp[-1].exp),(yylsp[-1]).first_line); }
#line 2600 "y.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 283 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPunary((yyvsp[0].exp), PLUS,(yylsp[-1]).first_line); }
#line 2606 "y.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 284 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPunary((yyvsp[0].exp), MINUS,(yylsp[-1]).first_line); }
#line 2612 "y.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 285 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPunary((yyvsp[0].exp), NOT,(yylsp[-1]).first_line); }
#line 2618 "y.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 286 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPunary((yyvsp[0].exp), XOR,(yylsp[-1]).first_line); }
#line 2624 "y.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 289 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPparen((yyvsp[-1].exp),(yylsp[-1]).first_line); }
#line 2630 "y.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 290 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), PLUS,(yylsp[-1]).first_line); }
#line 2636 "y.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 291 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), MINUS,(yylsp[-1]).first_line); }
#line 2642 "y.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 292 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), BITOR,(yylsp[-1]).first_line); }
#line 2648 "y.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 293 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), XOR,(yylsp[-1]).first_line); }
#line 2654 "y.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 294 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), MULT,(yylsp[-1]).first_line); }
#line 2660 "y.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 295 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), DIV,(yylsp[-1]).first_line); }
#line 2666 "y.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 296 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), MOD,(yylsp[-1]).first_line); }
#line 2672 "y.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 297 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), LSHIFT,(yylsp[-1]).first_line); }
#line 2678 "y.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 298 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), RSHIFT,(yylsp[-1]).first_line); }
#line 2684 "y.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 299 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), BITAND,(yylsp[-1]).first_line); }
#line 2690 "y.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 300 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), BITCLEAR,(yylsp[-1]).first_line); }
#line 2696 "y.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 301 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), EQUAL,(yylsp[-1]).first_line); }
#line 2702 "y.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 302 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), NEQ,(yylsp[-1]).first_line); }
#line 2708 "y.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 303 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), LT,(yylsp[-1]).first_line); }
#line 2714 "y.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 304 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), LEQ,(yylsp[-1]).first_line); }
#line 2720 "y.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 305 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), GT,(yylsp[-1]).first_line); }
#line 2726 "y.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 306 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), GEQ,(yylsp[-1]).first_line); }
#line 2732 "y.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 307 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), AND,(yylsp[-1]).first_line); }
#line 2738 "y.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 308 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPbinary((yyvsp[-2].exp), (yyvsp[0].exp), OR,(yylsp[-1]).first_line); }
#line 2744 "y.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 311 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPfunc((yyvsp[-3].exp), (yyvsp[-1].exp),(yylsp[-3]).first_line); }
#line 2750 "y.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 312 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPfunc((yyvsp[-2].exp), NULL, (yylsp[-2]).first_line); }
#line 2756 "y.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 315 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPparen((yyvsp[-1].exp),(yylsp[-1]).first_line); }
#line 2762 "y.tab.c" /* yacc.c:1661  */
    break;

  case 162:
#line 316 "golite.y" /* yacc.c:1661  */
    { (yyval.exp) = makeEXPappend((yyvsp[-3].exp), (yyvsp[-1].exp),(yylsp[-5]).first_line); }
#line 2768 "y.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 319 "golite.y" /* yacc.c:1661  */
    { (yyval.type) = makeTYPEparen((yyvsp[-1].type)); }
#line 2774 "y.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 320 "golite.y" /* yacc.c:1661  */
    { (yyval.type) = makeTYPEid((yyvsp[0].stringconst)); }
#line 2780 "y.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 321 "golite.y" /* yacc.c:1661  */
    { (yyval.type) = makeTYPEslice((yyvsp[0].type)); }
#line 2786 "y.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 322 "golite.y" /* yacc.c:1661  */
    { (yyval.type) = makeTYPEarray((yyvsp[-2].intconst), (yyvsp[0].type)); }
#line 2792 "y.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 323 "golite.y" /* yacc.c:1661  */
    { (yyval.type) = makeTYPEstruct((yyvsp[-1].structdecl)); }
#line 2798 "y.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 326 "golite.y" /* yacc.c:1661  */
    { (yyval.structdecl) = NULL; }
#line 2804 "y.tab.c" /* yacc.c:1661  */
    break;

  case 169:
#line 327 "golite.y" /* yacc.c:1661  */
    { (yyval.structdecl) = (yyvsp[-1].structdecl); (yyval.structdecl)->next = (yyvsp[-2].structdecl); }
#line 2810 "y.tab.c" /* yacc.c:1661  */
    break;

  case 170:
#line 330 "golite.y" /* yacc.c:1661  */
    { (yyval.structdecl) = makeDECLstruct((yyvsp[-1].id), (yyvsp[0].type), (yylsp[-1]).first_line); }
#line 2816 "y.tab.c" /* yacc.c:1661  */
    break;

  case 171:
#line 333 "golite.y" /* yacc.c:1661  */
    { (yyval.block) = makeBLOCK((yyvsp[-1].stmt), (yylsp[-1]).first_line, (yylsp[-1]).last_line); }
#line 2822 "y.tab.c" /* yacc.c:1661  */
    break;


#line 2826 "y.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 336 "golite.y" /* yacc.c:1906  */

