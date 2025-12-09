/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 140 "src/parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

