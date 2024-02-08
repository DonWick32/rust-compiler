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
    K_INT = 258,
    K_FLOAT = 259,
    K_CHAR = 260,
    K_STRING = 261,
    LET = 262,
    CONST = 263,
    FUNCTION = 264,
    MAIN = 265,
    PRINT = 266,
    FOR = 267,
    WHILE = 268,
    ELSE = 269,
    IF = 270,
    SWITCH = 271,
    CASE = 272,
    RETURN = 273,
    CONTINUE = 274,
    BREAK = 275,
    DEFAULT = 276,
    INTEGER = 277,
    FLOAT = 278,
    CHARACTER = 279,
    STRING = 280,
    IDENTIFIER = 281,
    AND = 282,
    OR = 283,
    GE = 284,
    LE = 285,
    EQ = 286,
    NE = 287,
    EOF_TOKEN = 288,
    ERROR = 289
  };
#endif
/* Tokens.  */
#define K_INT 258
#define K_FLOAT 259
#define K_CHAR 260
#define K_STRING 261
#define LET 262
#define CONST 263
#define FUNCTION 264
#define MAIN 265
#define PRINT 266
#define FOR 267
#define WHILE 268
#define ELSE 269
#define IF 270
#define SWITCH 271
#define CASE 272
#define RETURN 273
#define CONTINUE 274
#define BREAK 275
#define DEFAULT 276
#define INTEGER 277
#define FLOAT 278
#define CHARACTER 279
#define STRING 280
#define IDENTIFIER 281
#define AND 282
#define OR 283
#define GE 284
#define LE 285
#define EQ 286
#define NE 287
#define EOF_TOKEN 288
#define ERROR 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "parser.y" /* yacc.c:1909  */

    int iValue;
    float fValue;
    char* sValue;
    IdStruct id;
    char cValue;

#line 130 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
