/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     IDENTIFIER = 259,
     FLOAT_CONST = 260,
     INT = 261,
     FLOAT = 262,
     VOID = 263,
     CONST = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     BREAK = 268,
     CONTINUE = 269,
     RETURN = 270,
     ADD = 271,
     SUB = 272,
     MUL = 273,
     DIV = 274,
     MOD = 275,
     EQ = 276,
     NE = 277,
     LT = 278,
     LE = 279,
     GT = 280,
     GE = 281,
     AND = 282,
     OR = 283,
     NOT = 284,
     ASSIGN = 285,
     SEMICOLON = 286,
     COMMA = 287,
     LPAREN = 288,
     RPAREN = 289,
     LBRACKET = 290,
     RBRACKET = 291,
     LBRACE = 292,
     RBRACE = 293,
     UMINUS = 294
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define IDENTIFIER 259
#define FLOAT_CONST 260
#define INT 261
#define FLOAT 262
#define VOID 263
#define CONST 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define BREAK 268
#define CONTINUE 269
#define RETURN 270
#define ADD 271
#define SUB 272
#define MUL 273
#define DIV 274
#define MOD 275
#define EQ 276
#define NE 277
#define LT 278
#define LE 279
#define GT 280
#define GE 281
#define AND 282
#define OR 283
#define NOT 284
#define ASSIGN 285
#define SEMICOLON 286
#define COMMA 287
#define LPAREN 288
#define RPAREN 289
#define LBRACKET 290
#define RBRACKET 291
#define LBRACE 292
#define RBRACE 293
#define UMINUS 294




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

int line_num = 1;
ASTNode *root = NULL;
void yyerror(const char *s);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "src/parser.y"
{
    int ival;
    double fval;
    char *sval;
    ASTNode *node;
    ASTNode **node_list;
    int *int_list;
    struct {
        ASTNode **nodes;
        int count;
    } node_list_with_count;
}
/* Line 193 of yacc.c.  */
#line 205 "src/parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 218 "src/parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    18,    25,
      32,    38,    44,    48,    50,    53,    58,    61,    65,    67,
      71,    77,    84,    88,    91,    94,    96,    98,   100,   102,
     104,   106,   109,   112,   115,   118,   121,   123,   129,   137,
     143,   146,   150,   152,   156,   160,   164,   168,   172,   176,
     180,   184,   188,   192,   196,   200,   204,   206,   210,   212,
     215,   218,   221,   223,   228,   232,   234,   236,   238,   242,
     244,   249,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    43,    -1,    43,    -1,
      44,    -1,    47,    31,    -1,    49,    31,    -1,     6,     4,
      33,    45,    34,    50,    -1,     8,     4,    33,    45,    34,
      50,    -1,     6,     4,    33,    34,    50,    -1,     8,     4,
      33,    34,    50,    -1,    45,    32,    46,    -1,    46,    -1,
       6,     4,    -1,     6,     4,    35,    36,    -1,     6,    48,
      -1,     9,     6,    48,    -1,     4,    -1,     4,    30,    57,
      -1,     6,     4,    35,     3,    36,    -1,     9,     6,     4,
      35,     3,    36,    -1,    37,    51,    38,    -1,    37,    38,
      -1,    51,    52,    -1,    52,    -1,    53,    -1,    50,    -1,
      54,    -1,    55,    -1,    56,    -1,    47,    31,    -1,    49,
      31,    -1,    13,    31,    -1,    14,    31,    -1,    57,    31,
      -1,    31,    -1,    10,    33,    57,    34,    52,    -1,    10,
      33,    57,    34,    52,    11,    52,    -1,    12,    33,    57,
      34,    52,    -1,    15,    31,    -1,    15,    57,    31,    -1,
      58,    -1,    57,    28,    57,    -1,    57,    27,    57,    -1,
      57,    21,    57,    -1,    57,    22,    57,    -1,    57,    23,
      57,    -1,    57,    24,    57,    -1,    57,    25,    57,    -1,
      57,    26,    57,    -1,    57,    16,    57,    -1,    57,    17,
      57,    -1,    57,    18,    57,    -1,    57,    19,    57,    -1,
      57,    20,    57,    -1,    59,    -1,    62,    30,    58,    -1,
      60,    -1,    16,    59,    -1,    17,    59,    -1,    29,    59,
      -1,    61,    -1,     4,    33,    63,    34,    -1,     4,    33,
      34,    -1,    62,    -1,     3,    -1,     5,    -1,    33,    57,
      34,    -1,     4,    -1,     4,    35,    57,    36,    -1,    63,
      32,    57,    -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    69,    80,    89,    90,    91,    95,    99,
     103,   106,   112,   122,   131,   134,   141,   144,   151,   154,
     160,   165,   173,   178,   184,   194,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   215,   218,   224,   227,   233,
     239,   242,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   265,   266,   272,   273,
     274,   275,   279,   280,   284,   287,   291,   292,   297,   301,
     304,   312,   322
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "IDENTIFIER", "FLOAT_CONST",
  "INT", "FLOAT", "VOID", "CONST", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "RETURN", "ADD", "SUB", "MUL", "DIV", "MOD", "EQ", "NE",
  "LT", "LE", "GT", "GE", "AND", "OR", "NOT", "ASSIGN", "SEMICOLON",
  "COMMA", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE",
  "UMINUS", "$accept", "program", "comp_unit", "decl", "func_def",
  "func_params", "func_param", "var_decl", "var_def", "array_decl",
  "block_stmt", "stmt_list", "stmt", "expr_stmt", "if_stmt", "while_stmt",
  "return_stmt", "expr", "assign_expr", "unary_expr", "postfix_expr",
  "primary_expr", "lval", "expr_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    62,
      62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     2,     6,     6,
       5,     5,     3,     1,     2,     4,     2,     3,     1,     3,
       5,     6,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     1,     5,     7,     5,
       2,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     2,
       2,     2,     1,     4,     3,     1,     1,     1,     3,     1,
       4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     5,     0,     0,
      18,    16,     0,     0,     1,     3,     6,     7,     0,     0,
       0,     0,    18,    17,    66,    69,    67,     0,     0,     0,
       0,    19,    42,    56,    58,    62,    65,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    59,    65,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    10,     0,
       0,    20,    11,     0,     0,    64,    72,     0,     0,    68,
      51,    52,    53,    54,    55,    45,    46,    47,    48,    49,
      50,    44,    43,    57,     0,     0,     0,     0,     0,     0,
       0,    36,    23,     0,     0,    27,     0,    25,    26,    28,
      29,    30,     0,    12,     8,     9,    21,     0,    63,    70,
      15,    18,     0,     0,    33,    34,    40,     0,    31,    32,
      22,    24,    35,    71,     0,     0,    41,     0,     0,    37,
      39,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    39,    40,   103,    11,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    32,    33,
      34,    35,    36,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
      61,     7,    13,    25,    32,    61,   -74,   -74,    16,    49,
     -12,   -74,    48,    94,   -74,   -74,   -74,   -74,   173,    -5,
     105,    -4,   -11,   -74,   -74,    43,   -74,   173,   173,   173,
     173,    69,   -74,   -74,   -74,   -74,   110,   137,   107,    95,
     -74,   116,   107,   119,   166,   151,   173,   -74,   -74,   -74,
     -74,   212,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   136,    46,   -74,   175,
     107,   -74,   -74,   107,   143,   -74,    69,   131,   191,   -74,
     -15,   -15,   -74,   -74,   -74,   -10,   -10,   141,   141,   141,
     141,    99,   301,   -74,   146,   168,   150,   155,   160,   161,
     170,   -74,   -74,   162,   163,   -74,    97,   -74,   -74,   -74,
     -74,   -74,   269,   -74,   -74,   -74,   -74,   173,   -74,   -74,
     -74,    18,   173,   173,   -74,   -74,   -74,   285,   -74,   -74,
     -74,   -74,   -74,    69,   231,   250,   -74,   133,   133,   184,
     -74,   133,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   192,   -74,   177,   127,    20,   187,    66,
     -16,   -74,   -73,   -74,   -74,   -74,   -74,   -18,   139,    45,
     -74,   -74,   104,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    37,    37,    54,    55,    56,    52,    53,    54,    55,
      56,    10,    51,    59,    60,    61,    62,    12,    18,    18,
       8,    19,    68,    20,    44,     8,    72,    76,    78,    38,
      42,    13,    14,   131,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    16,    18,    24,
      25,    26,    95,    20,   114,     3,    96,   115,    97,    98,
      99,   100,    27,    28,   139,   140,     9,     1,   142,     2,
       3,     9,    47,    49,    50,    29,    45,   101,    46,    30,
      17,    21,   127,    67,   102,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    22,   133,
      24,    25,    26,    95,   134,   135,     3,    96,    41,    97,
      98,    99,   100,    27,    28,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    29,    69,   101,    70,
      30,    48,    48,    48,    67,   130,    24,    25,    26,    95,
      65,    66,     3,    96,    67,    97,    98,    99,   100,    27,
      28,    69,    71,    73,    24,    25,    26,    52,    53,    54,
      55,    56,    29,   117,   101,   118,    30,    27,    28,    74,
      67,    94,   121,    24,    25,    26,    24,    25,    26,   116,
      29,    37,   120,   122,    30,    75,    27,    28,   123,    27,
      28,   124,   125,   128,   129,   141,   113,    15,    43,    29,
      23,   126,    29,    30,    93,     0,    30,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,   119,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,    79,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,   137,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,   138,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
     132,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,   136,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

static const yytype_int16 yycheck[] =
{
      18,     6,     6,    18,    19,    20,    16,    17,    18,    19,
      20,     4,    30,    23,    24,    25,    26,     4,    30,    30,
       0,    33,    38,    35,    35,     5,    42,    45,    46,    34,
      34,     6,     0,   106,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    31,    30,     3,
       4,     5,     6,    35,    70,     9,    10,    73,    12,    13,
      14,    15,    16,    17,   137,   138,     0,     6,   141,     8,
       9,     5,    27,    28,    29,    29,    33,    31,    35,    33,
      31,    33,   100,    37,    38,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     4,   117,
       3,     4,     5,     6,   122,   123,     9,    10,     3,    12,
      13,    14,    15,    16,    17,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    29,    32,    31,    34,
      33,    27,    28,    29,    37,    38,     3,     4,     5,     6,
      30,     4,     9,    10,    37,    12,    13,    14,    15,    16,
      17,    32,    36,    34,     3,     4,     5,    16,    17,    18,
      19,    20,    29,    32,    31,    34,    33,    16,    17,     3,
      37,    35,     4,     3,     4,     5,     3,     4,     5,    36,
      29,     6,    36,    33,    33,    34,    16,    17,    33,    16,
      17,    31,    31,    31,    31,    11,    69,     5,    21,    29,
      13,    31,    29,    33,    65,    -1,    33,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    34,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    34,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     8,     9,    41,    42,    43,    44,    47,    49,
       4,    48,     4,     6,     0,    43,    31,    31,    30,    33,
      35,    33,     4,    48,     3,     4,     5,    16,    17,    29,
      33,    57,    58,    59,    60,    61,    62,     6,    34,    45,
      46,     3,    34,    45,    35,    33,    35,    59,    62,    59,
      59,    57,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    30,     4,    37,    50,    32,
      34,    36,    50,    34,     3,    34,    57,    63,    57,    34,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    35,     6,    10,    12,    13,    14,
      15,    31,    38,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    46,    50,    50,    36,    32,    34,    36,
      36,     4,    33,    33,    31,    31,    31,    57,    31,    31,
      38,    52,    31,    57,    57,    57,    31,    34,    34,    52,
      52,    11,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 62 "src/parser.y"
    {
        root = (yyvsp[(1) - (1)].node);
        (yyval.node) = (yyvsp[(1) - (1)].node);
    }
    break;

  case 3:
#line 69 "src/parser.y"
    {
        ASTNode **new_decls = (ASTNode**)malloc(sizeof(ASTNode*) * ((yyvsp[(1) - (2)].node)->u.program.decl_count + 1));
        for (int i = 0; i < (yyvsp[(1) - (2)].node)->u.program.decl_count; i++) {
            new_decls[i] = (yyvsp[(1) - (2)].node)->u.program.decls[i];
        }
        new_decls[(yyvsp[(1) - (2)].node)->u.program.decl_count] = (yyvsp[(2) - (2)].node);
        (yyval.node) = create_program(new_decls, (yyvsp[(1) - (2)].node)->u.program.decl_count + 1);
        root = (yyval.node);
        free((yyvsp[(1) - (2)].node)->u.program.decls);
        free((yyvsp[(1) - (2)].node));
    }
    break;

  case 4:
#line 80 "src/parser.y"
    {
        ASTNode **decls = (ASTNode**)malloc(sizeof(ASTNode*));
        decls[0] = (yyvsp[(1) - (1)].node);
        (yyval.node) = create_program(decls, 1);
        root = (yyval.node);
    }
    break;

  case 5:
#line 89 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 90 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 7:
#line 91 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 8:
#line 95 "src/parser.y"
    {
        (yyval.node) = create_func_def((yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].node_list_with_count).nodes, (yyvsp[(4) - (6)].node_list_with_count).count, (yyvsp[(6) - (6)].node));
        free((yyvsp[(4) - (6)].node_list_with_count).nodes);
    }
    break;

  case 9:
#line 99 "src/parser.y"
    {
        (yyval.node) = create_func_def((yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].node_list_with_count).nodes, (yyvsp[(4) - (6)].node_list_with_count).count, (yyvsp[(6) - (6)].node));
        free((yyvsp[(4) - (6)].node_list_with_count).nodes);
    }
    break;

  case 10:
#line 103 "src/parser.y"
    {
        (yyval.node) = create_func_def((yyvsp[(2) - (5)].sval), NULL, 0, (yyvsp[(5) - (5)].node));
    }
    break;

  case 11:
#line 106 "src/parser.y"
    {
        (yyval.node) = create_func_def((yyvsp[(2) - (5)].sval), NULL, 0, (yyvsp[(5) - (5)].node));
    }
    break;

  case 12:
#line 112 "src/parser.y"
    {
        ASTNode **new_params = (ASTNode**)malloc(sizeof(ASTNode*) * ((yyvsp[(1) - (3)].node_list_with_count).count + 1));
        for (int i = 0; i < (yyvsp[(1) - (3)].node_list_with_count).count; i++) {
            new_params[i] = (yyvsp[(1) - (3)].node_list_with_count).nodes[i];
        }
        new_params[(yyvsp[(1) - (3)].node_list_with_count).count] = (yyvsp[(3) - (3)].node);
        free((yyvsp[(1) - (3)].node_list_with_count).nodes);
        (yyval.node_list_with_count).nodes = new_params;
        (yyval.node_list_with_count).count = (yyvsp[(1) - (3)].node_list_with_count).count + 1;
    }
    break;

  case 13:
#line 122 "src/parser.y"
    {
        ASTNode **params = (ASTNode**)malloc(sizeof(ASTNode*));
        params[0] = (yyvsp[(1) - (1)].node);
        (yyval.node_list_with_count).nodes = params;
        (yyval.node_list_with_count).count = 1;
    }
    break;

  case 14:
#line 131 "src/parser.y"
    {
        (yyval.node) = create_var_decl((yyvsp[(2) - (2)].sval), 0, NULL);
    }
    break;

  case 15:
#line 134 "src/parser.y"
    {
        int dims[] = {0};
        (yyval.node) = create_array_decl((yyvsp[(2) - (4)].sval), dims, 1, 0);
    }
    break;

  case 16:
#line 141 "src/parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (2)].node);
    }
    break;

  case 17:
#line 144 "src/parser.y"
    {
        (yyval.node) = (yyvsp[(3) - (3)].node);
        (yyval.node)->u.var_decl.is_const = 1;
    }
    break;

  case 18:
#line 151 "src/parser.y"
    {
        (yyval.node) = create_var_decl((yyvsp[(1) - (1)].sval), 0, NULL);
    }
    break;

  case 19:
#line 154 "src/parser.y"
    {
        (yyval.node) = create_var_decl((yyvsp[(1) - (3)].sval), 0, (yyvsp[(3) - (3)].node));
    }
    break;

  case 20:
#line 160 "src/parser.y"
    {
        int *dims = (int*)malloc(sizeof(int));
        dims[0] = (yyvsp[(4) - (5)].ival);
        (yyval.node) = create_array_decl((yyvsp[(2) - (5)].sval), dims, 1, 0);
    }
    break;

  case 21:
#line 165 "src/parser.y"
    {
        int *dims = (int*)malloc(sizeof(int));
        dims[0] = (yyvsp[(5) - (6)].ival);
        (yyval.node) = create_array_decl((yyvsp[(3) - (6)].sval), dims, 1, 1);
    }
    break;

  case 22:
#line 173 "src/parser.y"
    {
        (yyval.node) = create_block((yyvsp[(2) - (3)].node_list_with_count).nodes, (yyvsp[(2) - (3)].node_list_with_count).count);
        // 不要释放$2.nodes，因为create_block只是保存了指针
        // free($2.nodes);  // 这会导致悬空指针
    }
    break;

  case 23:
#line 178 "src/parser.y"
    {
        (yyval.node) = create_block(NULL, 0);
    }
    break;

  case 24:
#line 184 "src/parser.y"
    {
        ASTNode **new_stmts = (ASTNode**)malloc(sizeof(ASTNode*) * ((yyvsp[(1) - (2)].node_list_with_count).count + 1));
        for (int i = 0; i < (yyvsp[(1) - (2)].node_list_with_count).count; i++) {
            new_stmts[i] = (yyvsp[(1) - (2)].node_list_with_count).nodes[i];
        }
        new_stmts[(yyvsp[(1) - (2)].node_list_with_count).count] = (yyvsp[(2) - (2)].node);
        free((yyvsp[(1) - (2)].node_list_with_count).nodes);
        (yyval.node_list_with_count).nodes = new_stmts;
        (yyval.node_list_with_count).count = (yyvsp[(1) - (2)].node_list_with_count).count + 1;
    }
    break;

  case 25:
#line 194 "src/parser.y"
    {
        ASTNode **stmts = (ASTNode**)malloc(sizeof(ASTNode*));
        stmts[0] = (yyvsp[(1) - (1)].node);
        (yyval.node_list_with_count).nodes = stmts;
        (yyval.node_list_with_count).count = 1;
    }
    break;

  case 26:
#line 203 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
#line 204 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 28:
#line 205 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 29:
#line 206 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 30:
#line 207 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:
#line 208 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 32:
#line 209 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 33:
#line 210 "src/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 34:
#line 211 "src/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 35:
#line 215 "src/parser.y"
    {
        (yyval.node) = create_expr_stmt((yyvsp[(1) - (2)].node));
    }
    break;

  case 36:
#line 218 "src/parser.y"
    {
        (yyval.node) = NULL;
    }
    break;

  case 37:
#line 224 "src/parser.y"
    {
        (yyval.node) = create_if((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL);
    }
    break;

  case 38:
#line 227 "src/parser.y"
    {
        (yyval.node) = create_if((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
    }
    break;

  case 39:
#line 233 "src/parser.y"
    {
        (yyval.node) = create_while((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    }
    break;

  case 40:
#line 239 "src/parser.y"
    {
        (yyval.node) = create_return(NULL);
    }
    break;

  case 41:
#line 242 "src/parser.y"
    {
        (yyval.node) = create_return((yyvsp[(2) - (3)].node));
    }
    break;

  case 42:
#line 248 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 43:
#line 249 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_OR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 44:
#line 250 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_AND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 45:
#line 251 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_EQ, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 46:
#line 252 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_NE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 47:
#line 253 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_LT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 48:
#line 254 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_LE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 49:
#line 255 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_GT, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 50:
#line 256 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_GE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 51:
#line 257 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_ADD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 52:
#line 258 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_SUB, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 53:
#line 259 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_MUL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 54:
#line 260 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_DIV, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 55:
#line 261 "src/parser.y"
    { (yyval.node) = create_binary_op(OP_MOD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 56:
#line 265 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:
#line 266 "src/parser.y"
    {
        (yyval.node) = create_assign((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    }
    break;

  case 58:
#line 272 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 59:
#line 273 "src/parser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 60:
#line 274 "src/parser.y"
    { (yyval.node) = create_unary_op(OP_NEG, (yyvsp[(2) - (2)].node)); }
    break;

  case 61:
#line 275 "src/parser.y"
    { (yyval.node) = create_unary_op(OP_NOT, (yyvsp[(2) - (2)].node)); }
    break;

  case 62:
#line 279 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 63:
#line 280 "src/parser.y"
    {
        (yyval.node) = create_func_call((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].node_list_with_count).nodes, (yyvsp[(3) - (4)].node_list_with_count).count);
        free((yyvsp[(3) - (4)].node_list_with_count).nodes);
    }
    break;

  case 64:
#line 284 "src/parser.y"
    {
        (yyval.node) = create_func_call((yyvsp[(1) - (3)].sval), NULL, 0);
    }
    break;

  case 65:
#line 287 "src/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 66:
#line 291 "src/parser.y"
    { (yyval.node) = create_integer((yyvsp[(1) - (1)].ival)); }
    break;

  case 67:
#line 292 "src/parser.y"
    {
        double val = atof((char*)(yyvsp[(1) - (1)].sval));
        (yyval.node) = create_float(val);
        free((char*)(yyvsp[(1) - (1)].sval));
    }
    break;

  case 68:
#line 297 "src/parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 69:
#line 301 "src/parser.y"
    {
        (yyval.node) = create_identifier((yyvsp[(1) - (1)].sval));
    }
    break;

  case 70:
#line 304 "src/parser.y"
    {
        ASTNode **indices = (ASTNode**)malloc(sizeof(ASTNode*));
        indices[0] = (yyvsp[(3) - (4)].node);
        (yyval.node) = create_array_access((yyvsp[(1) - (4)].sval), indices, 1);
    }
    break;

  case 71:
#line 312 "src/parser.y"
    {
        ASTNode **new_args = (ASTNode**)malloc(sizeof(ASTNode*) * ((yyvsp[(1) - (3)].node_list_with_count).count + 1));
        for (int i = 0; i < (yyvsp[(1) - (3)].node_list_with_count).count; i++) {
            new_args[i] = (yyvsp[(1) - (3)].node_list_with_count).nodes[i];
        }
        new_args[(yyvsp[(1) - (3)].node_list_with_count).count] = (yyvsp[(3) - (3)].node);
        free((yyvsp[(1) - (3)].node_list_with_count).nodes);
        (yyval.node_list_with_count).nodes = new_args;
        (yyval.node_list_with_count).count = (yyvsp[(1) - (3)].node_list_with_count).count + 1;
    }
    break;

  case 72:
#line 322 "src/parser.y"
    {
        ASTNode **args = (ASTNode**)malloc(sizeof(ASTNode*));
        args[0] = (yyvsp[(1) - (1)].node);
        (yyval.node_list_with_count).nodes = args;
        (yyval.node_list_with_count).count = 1;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2059 "src/parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 330 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Near: %s\n", yytext);
}

int main(int argc, char **argv) {
    FILE *input;
    
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = input;
    } else {
        yyin = stdin;
    }
    
    root = NULL;
    if (yyparse() == 0) {
        printf("Parse successful!\n");
        if (root) {
            printf("\n=== AST ===\n");
            print_ast(root, 0);
            printf("\n");
            free_ast(root);
        }
    } else {
        fprintf(stderr, "Parse failed!\n");
        return 1;
    }
    
    if (input) fclose(input);
    return 0;
}


