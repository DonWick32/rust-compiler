/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    DECLARE = 258,
    CHARACTER = 259,
    PRINTFF = 260,
    SCANFF = 261,
    INT = 262,
    BOOL = 263,
    FLOAT = 264,
    CHAR = 265,
    WHILE = 266,
    IF = 267,
    ELSE = 268,
    TRUE = 269,
    FALSE = 270,
    NUMBER = 271,
    FLOAT_NUM = 272,
    ID = 273,
    LE = 274,
    GE = 275,
    EQ = 276,
    NE = 277,
    GT = 278,
    LT = 279,
    AND = 280,
    OR = 281,
    STR = 282,
    ADD = 283,
    MULT = 284,
    DIV = 285,
    SUB = 286,
    RETURN = 287,
    LOG = 288,
    POW = 289
  };
#endif
/* Tokens.  */
#define DECLARE 258
#define CHARACTER 259
#define PRINTFF 260
#define SCANFF 261
#define INT 262
#define BOOL 263
#define FLOAT 264
#define CHAR 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define TRUE 269
#define FALSE 270
#define NUMBER 271
#define FLOAT_NUM 272
#define ID 273
#define LE 274
#define GE 275
#define EQ 276
#define NE 277
#define GT 278
#define LT 279
#define AND 280
#define OR 281
#define STR 282
#define ADD 283
#define MULT 284
#define DIV 285
#define SUB 286
#define RETURN 287
#define LOG 288
#define POW 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:1909  */
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 

#line 129 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
