/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KEY = 258,                     /* KEY  */
    AND = 259,                     /* AND  */
    OR = 260,                      /* OR  */
    NOT = 261,                     /* NOT  */
    RELOP = 262,                   /* RELOP  */
    ID = 263,                      /* ID  */
    VAL = 264,                     /* VAL  */
    SC = 265,                      /* SC  */
    CM = 266,                      /* CM  */
    PL = 267,                      /* PL  */
    MI = 268,                      /* MI  */
    MUL = 269,                     /* MUL  */
    DIV = 270,                     /* DIV  */
    POW = 271,                     /* POW  */
    OP = 272,                      /* OP  */
    CL = 273,                      /* CL  */
    AO = 274,                      /* AO  */
    AC = 275,                      /* AC  */
    EQ = 276,                      /* EQ  */
    BO = 277,                      /* BO  */
    BC = 278,                      /* BC  */
    UNR = 279,                     /* UNR  */
    TRUE = 280,                    /* TRUE  */
    FALSE = 281,                   /* FALSE  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    WHILE = 284                    /* WHILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KEY 258
#define AND 259
#define OR 260
#define NOT 261
#define RELOP 262
#define ID 263
#define VAL 264
#define SC 265
#define CM 266
#define PL 267
#define MI 268
#define MUL 269
#define DIV 270
#define POW 271
#define OP 272
#define CL 273
#define AO 274
#define AC 275
#define EQ 276
#define BO 277
#define BC 278
#define UNR 279
#define TRUE 280
#define FALSE 281
#define IF 282
#define ELSE 283
#define WHILE 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 69 "threeaddr.y"

	typedef struct node NODE;
	string *str;
	NODE *node;


#line 132 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
