/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser-v2.y"

#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.c"

int g_addr = 100;
int i = 1, lnum1 = 0;
int stack[100],
    index1 = 0,
    end[100],
    arr[10],
    ct, c, b, fl, top=0, fortop = 0,
    label[20], label_num = 0, ltop = 0;

char st1[100][10];
char forvar[100][10];
char temp_count[2] = "0";
int plist[100], flist[100], k = -1, errc = 0, j = 0;
char temp[2]= "t";
char null[2]= " ";

void yyerror(char *s);
int printline();
extern int yylineno;

void print_error()
{
    printf("\033[1;31mError: \033[0m");
}

void print_label()
{
    printf("\033[0;36m");
}

void print_reset()
{
    printf("\033[0m");
}

void scope_start()
{
	stack[index1] = i;
	i++;
	index1++;
	return;
}

void scope_end()
{
	index1--;
	end[stack[index1]] = 1;
	stack[index1] = 0;
	return;
}
void if1()
{
	label_num++;
	strcpy(temp,"t");
	strcat(temp, temp_count);
	printf("\n%s = not %s\n", temp, st1[top]);
 	printf("if %s ", temp);
    print_label();
    printf("goto L%d\n", label_num);
    print_reset();
	temp_count[0]++;
	label[++ltop]=label_num;
}

void if2()
{
	label_num++;
    print_label();
	printf("\ngoto L%d\n", label_num);
	printf("L%d: \n", label[ltop--]);
    print_reset();
	label[++ltop] = label_num;
}

void if3()
{
    print_label();
	printf("\nL%d:\n", label[ltop--]);
    print_reset();
}

void loop1()
{
    label_num++;
    label[++ltop] = label_num;
    print_label();
	printf("\nL%d:\n", label_num);
    print_reset();
}

void loop2()
{
    print_label();
	printf("\ngoto L%d\n", label[ltop--]);
    print_reset();
}

void while1()
{
	label_num++;
	label[++ltop] = label_num;
    print_label();
	printf("\nL%d:\n", label_num);
    print_reset();
}

void while2()
{
	label_num++;
	strcpy(temp, "t");
	strcat(temp, temp_count);
	printf("%s = not %s\n", temp, st1[top--]);
 	printf("\nif %s ", temp);
    print_label();
    printf("goto L%d\n", label_num);
    print_reset();
	temp_count[0]++;
	label[++ltop] = label_num;
}

void while3()
{
	int y = label[ltop--];
    print_label();
	printf("\ngoto L%d\n", label[ltop--]);
	printf("\nL%d:\n",y);
    print_reset();
}

void forin()
{
    printf("\n%s = %s\n", st1[top - 2], st1[top - 1]);
    strcpy(forvar[++fortop], st1[top - 2]);

    label_num++;
	label[++ltop] = label_num;
    print_label();
	printf("\nL%d:\n", label_num);
    print_reset();

    printf("\nt%s = %s < %s\n", temp_count, st1[top - 2], st1[top]);
	temp_count[0]++;
    top -= 2;

    label_num++;
	strcpy(temp, "t");
	strcat(temp, temp_count);
	printf("%s = not %s\n", temp, st1[top]);
 	printf("\nif %s ", temp);
    print_label();
 	printf("goto L%d\n\n", label_num);
    print_reset();
	temp_count[0]++;
	label[++ltop] = label_num;
}

void forinend()
{
    printf("\n%s = %s + 1\n", forvar[fortop], forvar[fortop--]);
    int y = label[ltop--];
    print_label();
	printf("\ngoto L%d\n", label[ltop--]);
	printf("\nL%d:\n",y);
    print_reset();
}

void push(char *a)
{
	strcpy(st1[++top], a);
}

void array1()
{
	strcpy(temp, "t");
	strcat(temp, temp_count);
	printf("\n%s = %s\n", temp, st1[top]);
	strcpy(st1[top], temp);
	temp_count[0]++;
	strcpy(temp, "t");
	strcat(temp, temp_count);
	printf("%s = %s [ %s ] \n", temp, st1[top-1], st1[top]);
	top--;
	strcpy(st1[top], temp);
	temp_count[0]++;
}

void codegen()
{
	strcpy(temp, "t");
	strcat(temp, temp_count);
	printf("\n%s = %s %s %s\n", temp, st1[top-2], st1[top-1], st1[top]);
	top -= 2;
	strcpy(st1[top], temp);
	temp_count[0]++;
}

void codegen_umin()
{
	strcpy(temp, "t");
	strcat(temp, temp_count);
	printf("\n%s = -%s\n", temp, st1[top]);
	top--;
	strcpy(st1[top], temp);
	temp_count[0]++;
}

void codegen_assign()
{
	printf("%s = %s\n", st1[top-2], st1[top]);
	top -= 2;
}


#line 290 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    FN = 260,                      /* FN  */
    ID = 261,                      /* ID  */
    NUM = 262,                     /* NUM  */
    REAL = 263,                    /* REAL  */
    IMPORT = 264,                  /* IMPORT  */
    FUNCTION = 265,                /* FUNCTION  */
    RETURN = 266,                  /* RETURN  */
    STRING = 267,                  /* STRING  */
    ARRAY = 268,                   /* ARRAY  */
    PRINT = 269,                   /* PRINT  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    LOOP = 272,                    /* LOOP  */
    WHILE = 273,                   /* WHILE  */
    FOR = 274,                     /* FOR  */
    IN = 275,                      /* IN  */
    RANGE = 276,                   /* RANGE  */
    LE = 277,                      /* LE  */
    GE = 278,                      /* GE  */
    EQ = 279,                      /* EQ  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    NEQ = 282,                     /* NEQ  */
    UMINUS = 283                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define FLOAT 259
#define FN 260
#define ID 261
#define NUM 262
#define REAL 263
#define IMPORT 264
#define FUNCTION 265
#define RETURN 266
#define STRING 267
#define ARRAY 268
#define PRINT 269
#define IF 270
#define ELSE 271
#define LOOP 272
#define WHILE 273
#define FOR 274
#define IN 275
#define RANGE 276
#define LE 277
#define GE 278
#define EQ 279
#define AND 280
#define OR 281
#define NEQ 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 220 "parser-v2.y"

    int ival;
    char *str;

#line 401 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_FN = 5,                         /* FN  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_NUM = 7,                        /* NUM  */
  YYSYMBOL_REAL = 8,                       /* REAL  */
  YYSYMBOL_IMPORT = 9,                     /* IMPORT  */
  YYSYMBOL_FUNCTION = 10,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_ARRAY = 13,                     /* ARRAY  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_LOOP = 17,                      /* LOOP  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_IN = 20,                        /* IN  */
  YYSYMBOL_RANGE = 21,                     /* RANGE  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_start = 45,                     /* start  */
  YYSYMBOL_Function = 46,                  /* Function  */
  YYSYMBOL_parameter_list = 47,            /* parameter_list  */
  YYSYMBOL_parameter = 48,                 /* parameter  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_CompoundStmt = 50,              /* CompoundStmt  */
  YYSYMBOL_StmtList = 51,                  /* StmtList  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_if = 53,                        /* if  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_else = 56,                      /* else  */
  YYSYMBOL_loop = 57,                      /* loop  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_while = 59,                     /* while  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_for = 62,                       /* for  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_64_7 = 64,                      /* $@7  */
  YYSYMBOL_assignment = 65,                /* assignment  */
  YYSYMBOL_assignment1 = 66,               /* assignment1  */
  YYSYMBOL_67_8 = 67,                      /* $@8  */
  YYSYMBOL_68_9 = 68,                      /* $@9  */
  YYSYMBOL_69_10 = 69,                     /* $@10  */
  YYSYMBOL_consttype = 70,                 /* consttype  */
  YYSYMBOL_Declaration = 71,               /* Declaration  */
  YYSYMBOL_72_11 = 72,                     /* $@11  */
  YYSYMBOL_73_12 = 73,                     /* $@12  */
  YYSYMBOL_74_13 = 74,                     /* $@13  */
  YYSYMBOL_array = 75,                     /* array  */
  YYSYMBOL_76_14 = 76,                     /* $@14  */
  YYSYMBOL_E = 77,                         /* E  */
  YYSYMBOL_78_15 = 78,                     /* $@15  */
  YYSYMBOL_79_16 = 79,                     /* $@16  */
  YYSYMBOL_80_17 = 80,                     /* $@17  */
  YYSYMBOL_81_18 = 81,                     /* $@18  */
  YYSYMBOL_82_19 = 82,                     /* $@19  */
  YYSYMBOL_83_20 = 83,                     /* $@20  */
  YYSYMBOL_84_21 = 84,                     /* $@21  */
  YYSYMBOL_85_22 = 85,                     /* $@22  */
  YYSYMBOL_86_23 = 86,                     /* $@23  */
  YYSYMBOL_87_24 = 87,                     /* $@24  */
  YYSYMBOL_88_25 = 88,                     /* $@25  */
  YYSYMBOL_89_26 = 89,                     /* $@26  */
  YYSYMBOL_90_27 = 90,                     /* $@27  */
  YYSYMBOL_91_28 = 91,                     /* $@28  */
  YYSYMBOL_92_29 = 92,                     /* $@29  */
  YYSYMBOL_93_30 = 93,                     /* $@30  */
  YYSYMBOL_94_31 = 94,                     /* $@31  */
  YYSYMBOL_95_32 = 95,                     /* $@32  */
  YYSYMBOL_96_33 = 96,                     /* $@33  */
  YYSYMBOL_97_34 = 97,                     /* $@34  */
  YYSYMBOL_T = 98,                         /* T  */
  YYSYMBOL_99_35 = 99,                     /* $@35  */
  YYSYMBOL_100_36 = 100,                   /* $@36  */
  YYSYMBOL_F = 101,                        /* F  */
  YYSYMBOL_102_37 = 102                    /* $@37  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    34,    32,    38,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      28,    30,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   237,   237,   238,   239,   240,   243,   266,   294,   295,
     298,   305,   306,   307,   310,   313,   314,   317,   318,   319,
     320,   321,   322,   323,   329,   330,   337,   338,   339,   342,
     342,   342,   345,   346,   349,   349,   351,   351,   351,   354,
     354,   354,   359,   360,   361,   362,   363,   364,   367,   367,
     367,   367,   385,   390,   391,   396,   400,   401,   404,   404,
     404,   404,   435,   450,   494,   495,   498,   498,   501,   501,
     502,   502,   503,   504,   504,   504,   505,   505,   505,   506,
     506,   506,   507,   507,   507,   508,   508,   508,   509,   509,
     509,   510,   510,   510,   511,   511,   511,   512,   512,   512,
     513,   516,   516,   517,   517,   518,   521,   522,   522,   523,
     524
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "FN",
  "ID", "NUM", "REAL", "IMPORT", "FUNCTION", "RETURN", "STRING", "ARRAY",
  "PRINT", "IF", "ELSE", "LOOP", "WHILE", "FOR", "IN", "RANGE", "LE", "GE",
  "EQ", "AND", "OR", "NEQ", "'<'", "'>'", "'='", "UMINUS", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "','", "'{'", "'}'", "';'", "'['", "']'",
  "$accept", "start", "Function", "parameter_list", "parameter", "Type",
  "CompoundStmt", "StmtList", "stmt", "if", "$@1", "$@2", "else", "loop",
  "$@3", "while", "$@4", "$@5", "for", "$@6", "$@7", "assignment",
  "assignment1", "$@8", "$@9", "$@10", "consttype", "Declaration", "$@11",
  "$@12", "$@13", "array", "$@14", "E", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27",
  "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "T", "$@35",
  "$@36", "F", "$@37", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      37,   -72,   -72,   -72,   -72,    23,   -72,   -72,    37,     7,
      37,    17,   -16,    12,    37,    95,    95,    26,   -72,   -72,
     -72,    -6,   -72,    95,   -72,    -3,   -72,    20,   -72,    15,
     138,    48,   -72,    69,    41,    28,    51,   -72,   112,    87,
      77,    88,   -72,   -72,   106,   -72,    41,   -72,   -72,    91,
     118,   -72,   -72,   -72,    28,   146,   -72,   147,   138,   138,
     117,   138,    41,    97,   125,   136,   137,   133,   139,   140,
     134,   141,   135,    79,   105,   -72,   -72,   -72,   -72,   -72,
      65,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    91,    41,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    79,    79,    79,    79,   -28,    -2,   127,    41,
     -72,   -72,   161,   -72,   -72,   162,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   128,   -11,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   118,   118,   -72,   -72,   142,   130,
     -72,   131,   163,    91,    28,    41,   -72,   132,   -72,   -72,
      91,    91,    91,    91,    91,    91,    91,    91,    91,   143,
     -72,   -72,   144,    28,   -72,    91,   153,   -72,   145,   -72,
      28,    79,   -72,   160,   -72,   156,    28,   -72,    79,   -72,
     -72,    28,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    65,    11,    12,    13,    48,    56,    57,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     3,     1,
       2,    58,    62,     0,     4,    54,    52,     0,    49,     0,
       0,     0,    53,     0,     0,     0,     0,     9,     0,    46,
       0,    47,    59,    64,   109,   107,     0,   110,   100,    50,
      72,   105,    16,     6,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    70,    51,   101,   103,
       0,     7,     8,    42,    43,    44,    63,    45,    60,     0,
      74,    77,    80,    83,    86,    89,    92,    95,    98,   109,
     108,   106,     0,     0,     0,     0,    48,     0,     0,     0,
      34,    36,     0,    14,    26,     0,    28,    15,    18,    20,
      21,    22,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    71,   102,   104,     0,     0,
      24,     0,     0,    29,     0,     0,    39,    58,    61,    67,
      75,    78,    81,    84,    87,    90,    93,    96,    99,     0,
      25,    23,     0,     0,    35,    37,     0,    19,     0,    30,
       0,     0,    27,    33,    38,     0,     0,    31,     0,    32,
      40,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,    43,   -72,   -72,   123,   -26,   -54,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    82,    98,   -72,   -72,   -72,     1,   100,   -72,   -72,
     -72,   -72,   -72,   -34,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,    54,   -72,   -72,   -71,   -72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    36,    37,    11,    53,    80,   117,   118,
     163,   173,   177,   119,   144,   120,   145,   170,   121,   166,
     181,    40,    12,    17,    34,    77,    47,    14,    31,    62,
     123,    48,    63,    49,   102,   103,    64,   125,    65,   126,
      66,   127,    67,   128,    68,   129,    69,   130,    70,   131,
      71,   132,    72,   133,    50,   104,   105,    51,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    13,   100,    38,   139,     6,     7,    19,   138,    13,
      15,    13,    74,   -54,    16,    13,    13,    13,     2,     3,
       4,    75,    76,    21,    13,    22,   116,   -48,    88,    38,
      29,    41,   149,   136,   137,    15,    30,    -5,     1,   140,
       2,     3,     4,     5,     6,     7,     8,    44,     6,     7,
      23,    18,    35,    20,   115,   124,    28,    24,    83,    41,
      41,    15,    41,    33,   -54,    16,     1,    52,     2,     3,
       4,   106,     6,     7,    45,   143,   107,    46,    42,   108,
     109,    13,   110,   111,   112,    99,     6,     7,    54,    55,
     164,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     175,    25,     6,     7,    52,   113,   114,   180,   141,   169,
      43,   165,    45,    26,    27,    46,   174,    57,    56,    58,
      60,    32,   179,    75,    76,    59,    61,   182,   -73,   -76,
     -79,   -85,   -88,   -82,   -91,   -94,   -97,    75,    76,    89,
      84,    85,   101,    87,    39,     6,     7,    90,   -66,     2,
       3,     4,    78,    79,     6,     7,   134,   135,    86,    91,
      93,    92,    96,   142,    94,    98,    95,   146,   147,   148,
      97,   160,   161,   171,    30,   162,   176,   178,    82,   159,
     122,   168,     0,     0,   167,     0,   172
};

static const yytype_int16 yycheck[] =
{
      54,     0,    73,    29,     6,     7,     8,     0,    36,     8,
      38,    10,    46,    41,    42,    14,    15,    16,     3,     4,
       5,    32,    33,     6,    23,    41,    80,    30,    62,    55,
      36,    30,    43,   104,   105,    38,    42,     0,     1,    41,
       3,     4,     5,     6,     7,     8,     9,     6,     7,     8,
      38,     8,    37,    10,    80,    89,    30,    14,    57,    58,
      59,    38,    61,    43,    41,    42,     1,    39,     3,     4,
       5,     6,     7,     8,    33,   109,    11,    36,    30,    14,
      15,    80,    17,    18,    19,     6,     7,     8,    37,    38,
     144,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     171,     6,     7,     8,    39,    40,    41,   178,   107,   163,
      41,   145,    33,    15,    16,    36,   170,    30,     6,    32,
      43,    23,   176,    32,    33,    38,    38,   181,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    32,    33,    42,
      58,    59,    37,    61,     6,     7,     8,    22,    42,     3,
       4,     5,    34,    35,     7,     8,   102,   103,    41,    23,
      27,    24,    28,    36,    25,    30,    26,     6,     6,    41,
      29,    41,    41,    20,    42,    12,    16,    21,    55,    37,
      80,    37,    -1,    -1,    41,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    45,
      46,    49,    66,    70,    71,    38,    42,    67,    45,     0,
      45,     6,    41,    38,    45,     6,    66,    66,    30,    36,
      42,    72,    66,    43,    68,    37,    47,    48,    49,     6,
      65,    70,    30,    41,     6,    33,    36,    70,    75,    77,
      98,   101,    39,    50,    37,    38,     6,    30,    32,    38,
      43,    38,    73,    76,    80,    82,    84,    86,    88,    90,
      92,    94,    96,   102,    77,    32,    33,    69,    34,    35,
      51,    50,    48,    70,    65,    65,    41,    65,    77,    42,
      22,    23,    24,    27,    25,    26,    28,    29,    30,     6,
     101,    37,    78,    79,    99,   100,     6,    11,    14,    15,
      17,    18,    19,    40,    41,    49,    50,    52,    53,    57,
      59,    62,    71,    74,    77,    81,    83,    85,    87,    89,
      91,    93,    95,    97,    98,    98,   101,   101,    36,     6,
      41,    70,    36,    77,    58,    60,     6,     6,    41,    43,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    37,
      41,    41,    12,    54,    50,    77,    63,    41,    37,    50,
      61,    20,    41,    55,    50,   101,    16,    56,    21,    50,
     101,    64,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    49,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    54,
      55,    53,    56,    56,    58,    57,    60,    61,    59,    63,
      64,    62,    65,    65,    65,    65,    65,    65,    67,    68,
      69,    66,    66,    66,    66,    66,    70,    70,    72,    73,
      74,    71,    71,    71,    71,    71,    76,    75,    78,    77,
      79,    77,    77,    80,    81,    77,    82,    83,    77,    84,
      85,    77,    86,    87,    77,    88,    89,    77,    90,    91,
      77,    92,    93,    77,    94,    95,    77,    96,    97,    77,
      77,    99,    98,   100,    98,    98,   101,   102,   101,   101,
     101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     6,     3,     1,
       2,     1,     1,     1,     3,     2,     0,     1,     1,     4,
       1,     1,     1,     3,     2,     3,     1,     5,     1,     0,
       0,     6,     2,     0,     0,     3,     0,     0,     5,     0,
       0,     9,     3,     3,     3,     3,     1,     1,     0,     0,
       0,     6,     3,     3,     1,     1,     1,     1,     0,     0,
       0,     8,     2,     6,     5,     1,     0,     5,     0,     4,
       0,     4,     1,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       1,     0,     4,     0,     4,     1,     3,     0,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* Function: Type ID '(' ')' CompoundStmt  */
#line 243 "parser-v2.y"
                                        {
            if (strcmp((yyvsp[-3].str), "main") != 0)
                printf("goto F%d\n", lnum1);

            if ((yyvsp[-4].ival) != returntype_func(ct)) {
                print_error();
                printf("Type mismatch : Line %d\n", printline());
            }
            if (!(strcmp((yyvsp[-3].str), "printf") && strcmp((yyvsp[-3].str), "scanf") 
                && strcmp((yyvsp[-3].str), "getc") && strcmp((yyvsp[-3].str), "gets") && strcmp((yyvsp[-3].str), "getchar") 
                && strcmp((yyvsp[-3].str), "puts") && strcmp((yyvsp[-3].str), "putchar") && strcmp((yyvsp[-3].str), "clearerr") 
                && strcmp((yyvsp[-3].str), "getw") && strcmp((yyvsp[-3].str), "putw") && strcmp((yyvsp[-3].str), "putc") 
                && strcmp((yyvsp[-3].str), "rewind") && strcmp((yyvsp[-3].str), "sprint") && strcmp((yyvsp[-3].str), "sscanf") 
                && strcmp((yyvsp[-3].str), "remove") && strcmp((yyvsp[-3].str), "fflush"))) 
            {
                print_error();
                printf("Type mismatch in redeclaration of %s : Line %d\n", (yyvsp[-3].str), printline());
            } else {
                insert((yyvsp[-3].str), FUNCTION);
                insert((yyvsp[-3].str), (yyvsp[-4].ival));
                g_addr += 4;
            }
        }
#line 1637 "y.tab.c"
    break;

  case 7: /* Function: Type ID '(' parameter_list ')' CompoundStmt  */
#line 266 "parser-v2.y"
                                                   {
            if ((yyvsp[-5].ival) != returntype_func(ct)) {
                print_error();
                printf(" Type mismatch : Line %d\n", printline()); 
                errc++;
            }

            if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") 
                && strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && strcmp((yyvsp[-4].str),"getchar") 
                && strcmp((yyvsp[-4].str),"puts") && strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") 
                && strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && strcmp((yyvsp[-4].str),"putc") 
                && strcmp((yyvsp[-4].str),"rewind") && strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") 
                && strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush")))
            {
                print_error();
                printf(" Redeclaration of %s : Line %d\n", (yyvsp[-4].str), printline());
                errc++;
            } else {
                insert((yyvsp[-4].str), FUNCTION);
                insert((yyvsp[-4].str), (yyvsp[-5].ival));
                for(j = 0; j <= k; j++) {
                    insertp((yyvsp[-4].str), plist[j]);
                }
                k = -1;
            }
        }
#line 1668 "y.tab.c"
    break;

  case 10: /* parameter: Type ID  */
#line 298 "parser-v2.y"
                    { 
            plist[++k] = (yyvsp[-1].ival);
            insert((yyvsp[0].str), (yyvsp[-1].ival));
            insertscope((yyvsp[0].str), i);
        }
#line 1678 "y.tab.c"
    break;

  case 23: /* stmt: RETURN consttype ';'  */
#line 323 "parser-v2.y"
                               {
            if (!(strspn((yyvsp[-1].str), "0123456789") == strlen((yyvsp[-1].str))))
                storereturn(ct, FLOAT);
            else
                storereturn(ct, INT); ct++;
		}
#line 1689 "y.tab.c"
    break;

  case 24: /* stmt: RETURN ';'  */
#line 329 "parser-v2.y"
                     { storereturn(ct, FN); ct++; }
#line 1695 "y.tab.c"
    break;

  case 25: /* stmt: RETURN ID ';'  */
#line 330 "parser-v2.y"
                        {
            int sct = returnscope((yyvsp[-1].str), stack[top - 1]);	//stack[top-1] - current scope
		    int type = returntype((yyvsp[-1].str), sct);
            if (type == 259) storereturn(ct, FLOAT);
            else storereturn(ct, INT);
            ct++;
        }
#line 1707 "y.tab.c"
    break;

  case 29: /* $@1: %empty  */
#line 342 "parser-v2.y"
           { if1(); }
#line 1713 "y.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 342 "parser-v2.y"
                                   { if2(); }
#line 1719 "y.tab.c"
    break;

  case 32: /* else: ELSE CompoundStmt  */
#line 345 "parser-v2.y"
                         {if3();}
#line 1725 "y.tab.c"
    break;

  case 34: /* $@3: %empty  */
#line 349 "parser-v2.y"
            { loop1(); }
#line 1731 "y.tab.c"
    break;

  case 35: /* loop: LOOP $@3 CompoundStmt  */
#line 349 "parser-v2.y"
                                      { loop2(); }
#line 1737 "y.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 351 "parser-v2.y"
              { while1(); }
#line 1743 "y.tab.c"
    break;

  case 37: /* $@5: %empty  */
#line 351 "parser-v2.y"
                                { while2(); }
#line 1749 "y.tab.c"
    break;

  case 38: /* while: WHILE $@4 E $@5 CompoundStmt  */
#line 351 "parser-v2.y"
                                                           { while3(); }
#line 1755 "y.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 354 "parser-v2.y"
             { push((yyvsp[0].str)); }
#line 1761 "y.tab.c"
    break;

  case 40: /* $@7: %empty  */
#line 354 "parser-v2.y"
                                        { forin(); }
#line 1767 "y.tab.c"
    break;

  case 41: /* for: FOR ID $@6 IN F RANGE F $@7 CompoundStmt  */
#line 354 "parser-v2.y"
                                                                  { forinend(); }
#line 1773 "y.tab.c"
    break;

  case 48: /* $@8: %empty  */
#line 367 "parser-v2.y"
                 { push((yyvsp[0].str)); }
#line 1779 "y.tab.c"
    break;

  case 49: /* $@9: %empty  */
#line 367 "parser-v2.y"
                                   { strcpy(st1[++top], "="); }
#line 1785 "y.tab.c"
    break;

  case 50: /* $@10: %empty  */
#line 367 "parser-v2.y"
                                                                  { codegen_assign(); }
#line 1791 "y.tab.c"
    break;

  case 51: /* assignment1: ID $@8 '=' $@9 E $@10  */
#line 368 "parser-v2.y"
        {
            int sct = returnscope((yyvsp[-5].str), stack[index1 - 1]);
            int type = returntype((yyvsp[-5].str), sct);
            if ((!(strspn((yyvsp[-1].str), "0123456789") == strlen((yyvsp[-1].str)))) && type == 258 && fl == 0) {
                print_error();
                printf("Type Mismatch : Line %d\n", printline());
            }
            if (!lookup((yyvsp[-5].str)))
            {
                int currscope = stack[index1 - 1];
                int scope = returnscope((yyvsp[-5].str), currscope);
                if ((scope <= currscope && end[scope] == 0) && !(scope == 0))
                {
                    check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
                }
            }
        }
#line 1813 "y.tab.c"
    break;

  case 52: /* assignment1: ID ',' assignment1  */
#line 385 "parser-v2.y"
                                {
            if (lookup((yyvsp[-2].str)))
                print_error();
                printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
        }
#line 1823 "y.tab.c"
    break;

  case 54: /* assignment1: ID  */
#line 391 "parser-v2.y"
              {
            if (lookup((yyvsp[0].str)))
                print_error();
                printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
		}
#line 1833 "y.tab.c"
    break;

  case 58: /* $@11: %empty  */
#line 404 "parser-v2.y"
                      { push((yyvsp[0].str)); }
#line 1839 "y.tab.c"
    break;

  case 59: /* $@12: %empty  */
#line 404 "parser-v2.y"
                                        { strcpy(st1[++top], "="); }
#line 1845 "y.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 404 "parser-v2.y"
                                                                       { codegen_assign(); }
#line 1851 "y.tab.c"
    break;

  case 61: /* Declaration: Type ID $@11 '=' $@12 E $@13 ';'  */
#line 405 "parser-v2.y"
        {
            if ( (!(strspn((yyvsp[-2].str), "0123456789") == strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival) == 258 && (fl == 0))
            {
                print_error();
                printf("Type Mismatch : Line %d\n", printline());
                fl = 1;
            }
            if (!lookup((yyvsp[-6].str)))
            {
                int currscope = stack[index1 - 1];
                int previous_scope = returnscope((yyvsp[-6].str), currscope);
                if (currscope == previous_scope) {
                    print_error();
                    printf("Redeclaration of %s : Line %d\n", (yyvsp[-6].str), printline());
                } else {
                    insert_dup((yyvsp[-6].str), (yyvsp[-7].ival), currscope);
                    check_scope_update((yyvsp[-6].str), (yyvsp[-2].str), stack[index1 - 1]);
                    int sg = returnscope((yyvsp[-6].str), stack[index1 - 1]);
                    g_addr += 4;
                }
            }
            else
            {
                int scope = stack[index1 - 1];
                insert((yyvsp[-6].str), (yyvsp[-7].ival));
                insertscope((yyvsp[-6].str), scope);
                check_scope_update((yyvsp[-6].str), (yyvsp[-2].str), stack[index1 - 1]);
                g_addr += 4;
            }
        }
#line 1886 "y.tab.c"
    break;

  case 62: /* Declaration: assignment1 ';'  */
#line 435 "parser-v2.y"
                           {
            if (!lookup((yyvsp[-1].str)))
            {
                int currscope = stack[index1 - 1];
                int scope = returnscope((yyvsp[-1].str),currscope);
                if (!(scope <= currscope && end[scope] == 0) || scope == 0) {
                    print_error();
                    printf("Variable %s out of scope : Line %d\n", (yyvsp[-1].str), printline());
                }
            }
            else {
                print_error();
                printf("Undeclared Variable %s : Line %d\n", (yyvsp[-1].str), printline());
            }
        }
#line 1906 "y.tab.c"
    break;

  case 63: /* Declaration: Type ID '[' assignment ']' ';'  */
#line 450 "parser-v2.y"
                                         {
			int itype;

			if (!(strspn((yyvsp[-2].str), "0123456789") == strlen((yyvsp[-2].str))))
                itype=259;
            else 
                itype = 258;

			if (itype!=258) {
			    print_error();
                printf("Array index must be of type int : Line %d\n", printline());
                errc++;
            }

			if (atoi((yyvsp[-2].str))<=0) { 
                print_error();
                printf("Array index must be of type int > 0 : Line %d\n", printline());
                errc++;
            }

			if (!lookup((yyvsp[-4].str))) {
				int currscope = stack[top - 1];
				int previous_scope = returnscope((yyvsp[-4].str), currscope);
				if (currscope == previous_scope) {
                    print_error();
                    printf("Redeclaration of %s : Line %d\n", (yyvsp[-4].str), printline());
                    errc++;
                } else {
					insert_dup((yyvsp[-4].str), ARRAY, currscope);
				    insert_by_scope((yyvsp[-4].str), (yyvsp[-5].ival), currscope);	//to insert type to the correct identifier in case of multiple entries of the identifier by using scope
					if (itype == 258) {
                        insert_index((yyvsp[-4].str), (yyvsp[-2].str));
                    }
				}
			} else {
				int scope = stack[top - 1];
				insert((yyvsp[-4].str), ARRAY);
				insert((yyvsp[-4].str), (yyvsp[-5].ival));
				insertscope((yyvsp[-4].str), scope);
				if (itype == 258) {
                    insert_index((yyvsp[-4].str), (yyvsp[-2].str));
                }
			}
		}
#line 1955 "y.tab.c"
    break;

  case 66: /* $@14: %empty  */
#line 498 "parser-v2.y"
            { push((yyvsp[0].str)); }
#line 1961 "y.tab.c"
    break;

  case 68: /* $@15: %empty  */
#line 501 "parser-v2.y"
             { strcpy(st1[++top], "+"); }
#line 1967 "y.tab.c"
    break;

  case 69: /* E: E '+' $@15 T  */
#line 501 "parser-v2.y"
                                              { codegen(); }
#line 1973 "y.tab.c"
    break;

  case 70: /* $@16: %empty  */
#line 502 "parser-v2.y"
             { strcpy(st1[++top], "-"); }
#line 1979 "y.tab.c"
    break;

  case 71: /* E: E '-' $@16 T  */
#line 502 "parser-v2.y"
                                              { codegen(); }
#line 1985 "y.tab.c"
    break;

  case 73: /* $@17: %empty  */
#line 504 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 1991 "y.tab.c"
    break;

  case 74: /* $@18: %empty  */
#line 504 "parser-v2.y"
                              { strcpy(st1[++top], "<="); }
#line 1997 "y.tab.c"
    break;

  case 75: /* E: ID $@17 LE $@18 E  */
#line 504 "parser-v2.y"
                                                                { codegen(); }
#line 2003 "y.tab.c"
    break;

  case 76: /* $@19: %empty  */
#line 505 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2009 "y.tab.c"
    break;

  case 77: /* $@20: %empty  */
#line 505 "parser-v2.y"
                              { strcpy(st1[++top], ">="); }
#line 2015 "y.tab.c"
    break;

  case 78: /* E: ID $@19 GE $@20 E  */
#line 505 "parser-v2.y"
                                                                { codegen(); }
#line 2021 "y.tab.c"
    break;

  case 79: /* $@21: %empty  */
#line 506 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2027 "y.tab.c"
    break;

  case 80: /* $@22: %empty  */
#line 506 "parser-v2.y"
                              { strcpy(st1[++top], "=="); }
#line 2033 "y.tab.c"
    break;

  case 81: /* E: ID $@21 EQ $@22 E  */
#line 506 "parser-v2.y"
                                                                { codegen(); }
#line 2039 "y.tab.c"
    break;

  case 82: /* $@23: %empty  */
#line 507 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2045 "y.tab.c"
    break;

  case 83: /* $@24: %empty  */
#line 507 "parser-v2.y"
                              { strcpy(st1[++top], "!="); }
#line 2051 "y.tab.c"
    break;

  case 84: /* E: ID $@23 NEQ $@24 E  */
#line 507 "parser-v2.y"
                                                                { codegen(); }
#line 2057 "y.tab.c"
    break;

  case 85: /* $@25: %empty  */
#line 508 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2063 "y.tab.c"
    break;

  case 86: /* $@26: %empty  */
#line 508 "parser-v2.y"
                              { strcpy(st1[++top], "&&"); }
#line 2069 "y.tab.c"
    break;

  case 87: /* E: ID $@25 AND $@26 E  */
#line 508 "parser-v2.y"
                                                                { codegen(); }
#line 2075 "y.tab.c"
    break;

  case 88: /* $@27: %empty  */
#line 509 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2081 "y.tab.c"
    break;

  case 89: /* $@28: %empty  */
#line 509 "parser-v2.y"
                              { strcpy(st1[++top], "||"); }
#line 2087 "y.tab.c"
    break;

  case 90: /* E: ID $@27 OR $@28 E  */
#line 509 "parser-v2.y"
                                                                { codegen(); }
#line 2093 "y.tab.c"
    break;

  case 91: /* $@29: %empty  */
#line 510 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2099 "y.tab.c"
    break;

  case 92: /* $@30: %empty  */
#line 510 "parser-v2.y"
                              { strcpy(st1[++top],  "<"); }
#line 2105 "y.tab.c"
    break;

  case 93: /* E: ID $@29 '<' $@30 E  */
#line 510 "parser-v2.y"
                                                                { codegen(); }
#line 2111 "y.tab.c"
    break;

  case 94: /* $@31: %empty  */
#line 511 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2117 "y.tab.c"
    break;

  case 95: /* $@32: %empty  */
#line 511 "parser-v2.y"
                              { strcpy(st1[++top],  ">"); }
#line 2123 "y.tab.c"
    break;

  case 96: /* E: ID $@31 '>' $@32 E  */
#line 511 "parser-v2.y"
                                                                { codegen(); }
#line 2129 "y.tab.c"
    break;

  case 97: /* $@33: %empty  */
#line 512 "parser-v2.y"
          { push((yyvsp[0].str)); }
#line 2135 "y.tab.c"
    break;

  case 98: /* $@34: %empty  */
#line 512 "parser-v2.y"
                              { strcpy(st1[++top],  "="); }
#line 2141 "y.tab.c"
    break;

  case 99: /* E: ID $@33 '=' $@34 E  */
#line 512 "parser-v2.y"
                                                                { codegen_assign(); }
#line 2147 "y.tab.c"
    break;

  case 100: /* E: array  */
#line 513 "parser-v2.y"
            {array1();}
#line 2153 "y.tab.c"
    break;

  case 101: /* $@35: %empty  */
#line 516 "parser-v2.y"
             { strcpy(st1[++top], "*"); }
#line 2159 "y.tab.c"
    break;

  case 102: /* T: T '*' $@35 F  */
#line 516 "parser-v2.y"
                                              { codegen(); }
#line 2165 "y.tab.c"
    break;

  case 103: /* $@36: %empty  */
#line 517 "parser-v2.y"
             { strcpy(st1[++top], "/"); }
#line 2171 "y.tab.c"
    break;

  case 104: /* T: T '/' $@36 F  */
#line 517 "parser-v2.y"
                                              { codegen(); }
#line 2177 "y.tab.c"
    break;

  case 106: /* F: '(' E ')'  */
#line 521 "parser-v2.y"
                    { (yyval.str) = (yyvsp[-1].str); }
#line 2183 "y.tab.c"
    break;

  case 107: /* $@37: %empty  */
#line 522 "parser-v2.y"
                    { strcpy(st1[++top], "-"); }
#line 2189 "y.tab.c"
    break;

  case 108: /* F: '-' $@37 F  */
#line 522 "parser-v2.y"
                                                     { codegen_umin(); }
#line 2195 "y.tab.c"
    break;

  case 109: /* F: ID  */
#line 523 "parser-v2.y"
                    { push((yyvsp[0].str)); fl = 1; }
#line 2201 "y.tab.c"
    break;

  case 110: /* F: consttype  */
#line 524 "parser-v2.y"
                    { push((yyvsp[0].str)); }
#line 2207 "y.tab.c"
    break;


#line 2211 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 527 "parser-v2.y"


#include "lex.yy.c"
#include <ctype.h>


int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
	yyparse();
	if (!yyparse()) {
		printf("Parsing done\n");
		print();
	} else {
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

void yyerror(char *s) {
    print_error();
	printf("\nLine %d : %s %s\n", yylineno, s, yytext);
}

int printline() {
	return yylineno;
}
