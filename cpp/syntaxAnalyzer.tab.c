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
#line 1 "syntaxAnalyzer.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "hashtbl.h"

    extern int lineno;

    extern FILE *yyin;
    extern int yylex();
    extern char *yytext;

    extern void yyterminate();

    HASHTBL * hashtbl;

    extern int lineNum;

    void yyerror(const char *message);

    int syntaxErrors = 0;
    int errorTypeFlag = 0; // 0: Token Error (YYTEXT) || 1: String Error (STRBUF)
    int scope = 0;

#line 97 "syntaxAnalyzer.tab.c"

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

#include "syntaxAnalyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "EOF"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_TYPEDEF = 3,                  /* "typedef"  */
  YYSYMBOL_T_CHAR = 4,                     /* "char"  */
  YYSYMBOL_T_INT = 5,                      /* "int"  */
  YYSYMBOL_T_FLOAT = 6,                    /* "float"  */
  YYSYMBOL_T_CONST = 7,                    /* "const"  */
  YYSYMBOL_T_UNION = 8,                    /* "union"  */
  YYSYMBOL_T_CLASS = 9,                    /* "class"  */
  YYSYMBOL_T_PRIVATE = 10,                 /* "private"  */
  YYSYMBOL_T_PROTECTED = 11,               /* "protected"  */
  YYSYMBOL_T_PUBLIC = 12,                  /* "public"  */
  YYSYMBOL_T_STATIC = 13,                  /* "static"  */
  YYSYMBOL_T_VOID = 14,                    /* "void"  */
  YYSYMBOL_T_LIST = 15,                    /* "list"  */
  YYSYMBOL_T_CONTINUE = 16,                /* "continue"  */
  YYSYMBOL_T_BREAK = 17,                   /* "break"  */
  YYSYMBOL_T_THIS = 18,                    /* "this"  */
  YYSYMBOL_T_IF = 19,                      /* "if"  */
  YYSYMBOL_T_ELSE = 20,                    /* "else"  */
  YYSYMBOL_T_WHILE = 21,                   /* "while"  */
  YYSYMBOL_T_FOR = 22,                     /* "for"  */
  YYSYMBOL_T_RETURN = 23,                  /* "return"  */
  YYSYMBOL_T_LENGTH = 24,                  /* "length"  */
  YYSYMBOL_T_NEW = 25,                     /* "new"  */
  YYSYMBOL_T_CIN = 26,                     /* "cin"  */
  YYSYMBOL_T_COUT = 27,                    /* "cout"  */
  YYSYMBOL_T_MAIN = 28,                    /* "main"  */
  YYSYMBOL_T_OROP = 29,                    /* "||"  */
  YYSYMBOL_T_ANDOP = 30,                   /* "&&"  */
  YYSYMBOL_T_EQUOP = 31,                   /* "== or !="  */
  YYSYMBOL_T_RELOP = 32,                   /* "> or >= or < or <="  */
  YYSYMBOL_T_ADDOP = 33,                   /* "+ or -"  */
  YYSYMBOL_T_MULOP = 34,                   /* "* or / or %"  */
  YYSYMBOL_T_NOTOP = 35,                   /* "!"  */
  YYSYMBOL_T_INCDEC = 36,                  /* "++ or --"  */
  YYSYMBOL_T_SIZEOP = 37,                  /* "sizeof"  */
  YYSYMBOL_T_LPAREN = 38,                  /* "("  */
  YYSYMBOL_T_RPAREN = 39,                  /* ")"  */
  YYSYMBOL_T_SEMI = 40,                    /* ";"  */
  YYSYMBOL_T_DOT = 41,                     /* "."  */
  YYSYMBOL_T_COMMA = 42,                   /* ","  */
  YYSYMBOL_T_ASSIGN = 43,                  /* "="  */
  YYSYMBOL_T_COLON = 44,                   /* ":"  */
  YYSYMBOL_T_LBRACK = 45,                  /* "["  */
  YYSYMBOL_T_RBRACK = 46,                  /* "]"  */
  YYSYMBOL_T_REFER = 47,                   /* "&"  */
  YYSYMBOL_T_LBRACE = 48,                  /* "{"  */
  YYSYMBOL_T_RBRACE = 49,                  /* "}"  */
  YYSYMBOL_T_METH = 50,                    /* "::"  */
  YYSYMBOL_T_INP = 51,                     /* ">>"  */
  YYSYMBOL_T_OUT = 52,                     /* "<<"  */
  YYSYMBOL_T_ID = 53,                      /* "IDENTIFIER"  */
  YYSYMBOL_T_ICONST = 54,                  /* "ICONST"  */
  YYSYMBOL_T_FCONST = 55,                  /* "FCONST"  */
  YYSYMBOL_T_CCONST = 56,                  /* "CCONST"  */
  YYSYMBOL_T_LISTFUNC = 57,                /* "list function"  */
  YYSYMBOL_T_STRING = 58,                  /* "string"  */
  YYSYMBOL_LOWER_THAN_ELSE = 59,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_global_declarations = 62,       /* global_declarations  */
  YYSYMBOL_global_declaration = 63,        /* global_declaration  */
  YYSYMBOL_typedef_declaration = 64,       /* typedef_declaration  */
  YYSYMBOL_typename = 65,                  /* typename  */
  YYSYMBOL_standard_type = 66,             /* standard_type  */
  YYSYMBOL_listspec = 67,                  /* listspec  */
  YYSYMBOL_dims = 68,                      /* dims  */
  YYSYMBOL_dim = 69,                       /* dim  */
  YYSYMBOL_const_declaration = 70,         /* const_declaration  */
  YYSYMBOL_constdefs = 71,                 /* constdefs  */
  YYSYMBOL_constdef = 72,                  /* constdef  */
  YYSYMBOL_init_value = 73,                /* init_value  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_variable = 75,                  /* variable  */
  YYSYMBOL_general_expression = 76,        /* general_expression  */
  YYSYMBOL_assignment = 77,                /* assignment  */
  YYSYMBOL_expression_list = 78,           /* expression_list  */
  YYSYMBOL_constant = 79,                  /* constant  */
  YYSYMBOL_listexpression = 80,            /* listexpression  */
  YYSYMBOL_init_values = 81,               /* init_values  */
  YYSYMBOL_class_declaration = 82,         /* class_declaration  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_class_body = 85,                /* class_body  */
  YYSYMBOL_parent = 86,                    /* parent  */
  YYSYMBOL_members_methods = 87,           /* members_methods  */
  YYSYMBOL_access = 88,                    /* access  */
  YYSYMBOL_member_or_method = 89,          /* member_or_method  */
  YYSYMBOL_member = 90,                    /* member  */
  YYSYMBOL_var_declaration = 91,           /* var_declaration  */
  YYSYMBOL_variabledefs = 92,              /* variabledefs  */
  YYSYMBOL_variabledef = 93,               /* variabledef  */
  YYSYMBOL_anonymous_union = 94,           /* anonymous_union  */
  YYSYMBOL_95_3 = 95,                      /* $@3  */
  YYSYMBOL_96_4 = 96,                      /* $@4  */
  YYSYMBOL_union_body = 97,                /* union_body  */
  YYSYMBOL_fields = 98,                    /* fields  */
  YYSYMBOL_field = 99,                     /* field  */
  YYSYMBOL_method = 100,                   /* method  */
  YYSYMBOL_short_func_declaration = 101,   /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 102,    /* short_par_func_header  */
  YYSYMBOL_func_header_start = 103,        /* func_header_start  */
  YYSYMBOL_parameter_types = 104,          /* parameter_types  */
  YYSYMBOL_pass_list_dims = 105,           /* pass_list_dims  */
  YYSYMBOL_nopar_func_header = 106,        /* nopar_func_header  */
  YYSYMBOL_union_declaration = 107,        /* union_declaration  */
  YYSYMBOL_108_5 = 108,                    /* $@5  */
  YYSYMBOL_109_6 = 109,                    /* $@6  */
  YYSYMBOL_global_var_declaration = 110,   /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 111,        /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 112,         /* init_variabledef  */
  YYSYMBOL_initializer = 113,              /* initializer  */
  YYSYMBOL_func_declaration = 114,         /* func_declaration  */
  YYSYMBOL_full_func_declaration = 115,    /* full_func_declaration  */
  YYSYMBOL_full_par_func_header = 116,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 117,  /* class_func_header_start  */
  YYSYMBOL_func_class = 118,               /* func_class  */
  YYSYMBOL_parameter_list = 119,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 120,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 121,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 122,          /* decl_statements  */
  YYSYMBOL_declarations = 123,             /* declarations  */
  YYSYMBOL_decltype = 124,                 /* decltype  */
  YYSYMBOL_statements = 125,               /* statements  */
  YYSYMBOL_statement = 126,                /* statement  */
  YYSYMBOL_expression_statement = 127,     /* expression_statement  */
  YYSYMBOL_if_statement = 128,             /* if_statement  */
  YYSYMBOL_129_7 = 129,                    /* $@7  */
  YYSYMBOL_130_8 = 130,                    /* $@8  */
  YYSYMBOL_if_tail = 131,                  /* if_tail  */
  YYSYMBOL_132_9 = 132,                    /* $@9  */
  YYSYMBOL_while_statement = 133,          /* while_statement  */
  YYSYMBOL_134_10 = 134,                   /* $@10  */
  YYSYMBOL_for_statement = 135,            /* for_statement  */
  YYSYMBOL_136_11 = 136,                   /* $@11  */
  YYSYMBOL_optexpr = 137,                  /* optexpr  */
  YYSYMBOL_return_statement = 138,         /* return_statement  */
  YYSYMBOL_io_statement = 139,             /* io_statement  */
  YYSYMBOL_in_list = 140,                  /* in_list  */
  YYSYMBOL_in_item = 141,                  /* in_item  */
  YYSYMBOL_out_list = 142,                 /* out_list  */
  YYSYMBOL_out_item = 143,                 /* out_item  */
  YYSYMBOL_comp_statement = 144,           /* comp_statement  */
  YYSYMBOL_main_function = 145,            /* main_function  */
  YYSYMBOL_main_header = 146               /* main_header  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   129,   129,   133,   134,   138,   139,   140,   141,   142,
     143,   147,   151,   152,   156,   157,   158,   159,   163,   164,
     168,   169,   173,   174,   178,   182,   183,   187,   191,   192,
     193,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     219,   220,   221,   222,   223,   227,   228,   232,   233,   234,
     238,   239,   243,   244,   245,   249,   253,   254,   258,   259,
     258,   264,   268,   269,   273,   274,   278,   279,   280,   281,
     282,   286,   287,   291,   292,   296,   300,   301,   305,   306,
     310,   311,   310,   316,   317,   321,   322,   326,   330,   334,
     335,   339,   343,   344,   348,   349,   353,   354,   358,   362,
     363,   362,   368,   372,   373,   377,   381,   382,   386,   387,
     391,   392,   393,   397,   398,   402,   403,   407,   411,   412,
     416,   417,   421,   425,   426,   427,   428,   432,   433,   437,
     438,   442,   443,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   460,   461,   465,   466,   465,   468,   472,
     472,   474,   478,   478,   483,   483,   488,   489,   493,   497,
     498,   502,   503,   507,   511,   512,   516,   517,   521,   525,
     530
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"EOF\"", "error", "\"invalid token\"", "\"typedef\"", "\"char\"",
  "\"int\"", "\"float\"", "\"const\"", "\"union\"", "\"class\"",
  "\"private\"", "\"protected\"", "\"public\"", "\"static\"", "\"void\"",
  "\"list\"", "\"continue\"", "\"break\"", "\"this\"", "\"if\"",
  "\"else\"", "\"while\"", "\"for\"", "\"return\"", "\"length\"",
  "\"new\"", "\"cin\"", "\"cout\"", "\"main\"", "\"||\"", "\"&&\"",
  "\"== or !=\"", "\"> or >= or < or <=\"", "\"+ or -\"",
  "\"* or / or %\"", "\"!\"", "\"++ or --\"", "\"sizeof\"", "\"(\"",
  "\")\"", "\";\"", "\".\"", "\",\"", "\"=\"", "\":\"", "\"[\"", "\"]\"",
  "\"&\"", "\"{\"", "\"}\"", "\"::\"", "\">>\"", "\"<<\"",
  "\"IDENTIFIER\"", "\"ICONST\"", "\"FCONST\"", "\"CCONST\"",
  "\"list function\"", "\"string\"", "LOWER_THAN_ELSE", "$accept",
  "program", "global_declarations", "global_declaration",
  "typedef_declaration", "typename", "standard_type", "listspec", "dims",
  "dim", "const_declaration", "constdefs", "constdef", "init_value",
  "expression", "variable", "general_expression", "assignment",
  "expression_list", "constant", "listexpression", "init_values",
  "class_declaration", "$@1", "$@2", "class_body", "parent",
  "members_methods", "access", "member_or_method", "member",
  "var_declaration", "variabledefs", "variabledef", "anonymous_union",
  "$@3", "$@4", "union_body", "fields", "field", "method",
  "short_func_declaration", "short_par_func_header", "func_header_start",
  "parameter_types", "pass_list_dims", "nopar_func_header",
  "union_declaration", "$@5", "$@6", "global_var_declaration",
  "init_variabledefs", "init_variabledef", "initializer",
  "func_declaration", "full_func_declaration", "full_par_func_header",
  "class_func_header_start", "func_class", "parameter_list",
  "pass_variabledef", "nopar_class_func_header", "decl_statements",
  "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "$@7", "$@8", "if_tail", "$@9",
  "while_statement", "$@10", "for_statement", "$@11", "optexpr",
  "return_statement", "io_statement", "in_list", "in_item", "out_list",
  "out_item", "comp_statement", "main_function", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-205)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-168)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -205,     9,   179,  -205,   162,  -205,     0,  -205,   162,     6,
      39,  -205,    40,  -205,  -205,  -205,    19,  -205,  -205,  -205,
    -205,    73,    96,   155,  -205,  -205,  -205,  -205,   105,   163,
     149,  -205,   188,  -205,   225,   215,   219,  -205,  -205,   233,
     231,   236,    41,   247,     3,  -205,   257,  -205,    17,  -205,
     314,   314,   159,   314,   314,  -205,   267,   256,  -205,    99,
    -205,   254,   277,  -205,  -205,  -205,   283,   193,  -205,  -205,
      27,  -205,  -205,    24,   135,   157,  -205,   289,   294,  -205,
      23,   305,   310,   475,   315,   323,   316,   321,   555,   555,
    -205,   555,   124,  -205,   501,   314,  -205,  -205,  -205,   336,
     191,   218,    46,  -205,  -205,  -205,   330,   359,   186,   404,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,   338,  -205,
      36,   195,   339,   340,  -205,  -205,   171,  -205,   219,   162,
    -205,   337,  -205,   343,   283,   156,  -205,   193,  -205,  -205,
     191,   271,   347,  -205,  -205,   236,   348,  -205,  -205,  -205,
    -205,  -205,   162,  -205,   162,  -205,  -205,   555,  -205,  -205,
    -205,   351,   358,   555,   555,    12,   242,   368,   237,  -205,
     364,   234,   351,   360,   356,   555,   555,   555,   555,   555,
     555,   555,  -205,   501,   357,   268,   555,  -205,  -205,   555,
    -205,   186,   404,    83,    27,  -205,  -205,   348,  -205,  -205,
    -205,   111,   193,  -205,    27,  -205,    48,  -205,   369,  -205,
     371,   345,  -205,   366,  -205,    53,  -205,  -205,   283,    -3,
      36,   243,   555,   555,   475,  -205,   249,   269,   113,    60,
    -205,  -205,   351,    -4,  -205,  -205,  -205,  -205,  -205,   275,
     212,   237,   332,   224,   368,  -205,   379,  -205,  -205,  -205,
     129,  -205,    27,   222,  -205,  -205,  -205,   304,  -205,  -205,
    -205,  -205,  -205,    13,   375,   380,   121,    59,  -205,   193,
    -205,  -205,  -205,  -205,   449,   276,   303,   392,  -205,  -205,
    -205,    12,  -205,   242,  -205,  -205,  -205,   318,  -205,    27,
    -205,  -205,  -205,  -205,  -205,  -205,    59,  -205,   381,    94,
    -205,  -205,  -205,  -205,  -205,  -205,   395,   396,  -205,   415,
     449,   449,   475,  -205,  -205,  -205,  -205,  -205,   254,  -205,
     400,    17,  -205,  -205,  -205,  -205,   403,  -205,    -3,   449,
     415,   527,   405,  -205,  -205,   407,  -205,   449,  -205
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,    14,    15,    16,     0,     0,
       0,    17,     0,    13,     3,     5,     0,    12,     6,     7,
     118,     0,     0,     0,     8,     9,    10,   119,     0,     0,
       0,     2,     0,    15,    19,     0,     0,   109,    68,   103,
       0,     0,    21,   117,     0,   114,     0,    99,     0,   100,
     140,   140,     0,   140,   140,    18,     0,     0,    21,     0,
      26,     0,    73,   127,   126,    21,    89,   140,   115,   112,
       0,   125,   108,    19,     0,     0,   139,     0,     0,    54,
       0,     0,     0,   140,     0,     0,     0,     0,   140,   140,
      40,   140,   140,   152,    61,   140,    63,    64,    62,     0,
      59,    42,     0,    56,    46,    49,     0,   140,     0,   135,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   132,
       0,     0,     0,     0,    21,   180,     0,    24,     0,     0,
     110,     0,    69,     0,    88,     0,    20,   140,    30,   116,
      28,    42,     0,    21,   113,    18,   107,    21,   130,   105,
     129,   101,     0,   124,     0,   150,   151,   140,   155,   162,
     164,   166,     0,   140,   140,   140,   140,    38,    37,    39,
       0,     0,    60,     0,     0,   140,   140,   140,   140,   140,
     140,   140,    41,    61,     0,   140,   140,   154,   153,   140,
     122,     0,   133,    53,     0,   141,   120,     0,   123,   121,
     179,     0,   140,    25,     0,    97,     0,    96,     0,    72,
       0,    80,    23,     0,    67,     0,    53,   131,   106,    19,
       0,     0,   140,   140,   140,   168,     0,     0,   173,     0,
     172,   177,   176,     0,   175,    48,    47,    65,   178,     0,
      31,    32,    33,    34,    35,    36,     0,    51,    58,    57,
       0,    55,     0,     0,    87,    11,    27,     0,    94,    93,
      95,   111,    70,     0,     0,     0,    80,     0,    22,   140,
      29,   107,   104,   128,   140,     0,     0,     0,    44,    45,
     169,   140,   170,   140,    52,    43,    50,     0,   138,     0,
      85,    77,    76,    78,    79,    71,     0,    90,     0,     0,
      75,    81,    83,    84,    82,    98,     0,     0,    66,   161,
     140,   140,   140,   171,   174,   137,    86,    74,     0,   103,
      21,     0,   159,   158,   156,   163,     0,    91,    19,   140,
     161,   140,     0,   160,   157,     0,    92,   140,   165
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,  -205,  -205,  -205,    -2,   355,   414,   -48,  -205,
    -205,  -205,   322,  -134,   -56,   -62,   -79,   266,   270,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,   189,   158,
    -205,  -141,  -186,   -15,  -205,  -205,  -205,   138,  -205,   258,
    -205,   461,  -205,   467,  -205,   259,   477,  -205,  -205,  -205,
    -205,  -205,   410,  -205,  -205,  -205,  -205,  -205,   465,   425,
     263,  -205,   -35,  -205,   -13,   383,  -102,  -205,  -205,  -205,
    -205,   161,  -205,  -205,  -205,  -205,  -205,  -204,  -205,  -205,
    -205,   211,  -205,   213,  -205,  -205,  -205
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    14,    15,   204,    17,   147,    66,   136,
      18,    59,    60,   139,   100,   101,   102,   103,   173,   104,
     105,   215,    19,    62,   210,   132,   133,   266,   267,   300,
     301,   205,   257,   254,   303,   318,   332,   130,   206,   207,
     304,   305,    21,   306,    74,   149,   307,    24,    61,   208,
      25,    44,    45,    68,    26,    27,    28,    29,    40,    75,
     150,    30,   106,   107,   142,   109,   110,   111,   112,   222,
     330,   323,   329,   113,   223,   114,   224,   162,   115,   116,
     229,   230,   233,   234,   117,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    43,    34,   214,   161,   141,    36,   195,   253,     3,
     126,   140,    55,   171,   291,   172,   118,   134,   122,   123,
     277,     5,    33,     7,   157,    76,   141,   141,    35,   141,
      79,    11,   167,   168,    41,   169,   282,   108,   108,   145,
     108,   108,    41,    69,   271,    70,    73,   187,   283,   258,
     120,    41,     5,    33,     7,    43,    72,   292,   148,    37,
     174,   158,    11,     5,    33,     7,   287,   297,   256,    99,
      13,   146,    42,    11,   298,   141,   201,   143,   221,  -102,
     143,   140,   108,   197,   226,   227,   188,   232,   189,   143,
     195,    63,    38,    39,   191,   269,   239,   259,   -13,   218,
     280,    13,   270,   228,   172,   148,   194,   250,   326,    41,
     251,   281,    13,    47,   141,   141,   141,   141,   141,   141,
     240,   241,   242,   243,   244,   245,   302,   335,     5,    33,
       7,   263,   264,   265,    48,   308,   -13,    76,    11,   127,
     141,   128,    79,   275,   276,   161,   140,   320,    84,    85,
     219,   255,   220,    51,   184,   302,   135,    88,   186,    89,
      90,    91,    92,     5,    33,     7,     5,    33,     7,    94,
     295,   189,   309,    11,   151,   286,    11,   152,    96,    97,
      98,    99,     4,     5,     6,     7,     8,     9,    10,   252,
       5,    33,     7,    11,    12,    49,   153,    53,   119,   154,
      11,    52,   212,    50,   232,   148,    76,   141,   324,   325,
     213,    79,    13,   140,   202,    13,   135,    84,    85,   228,
     176,   177,   178,   179,   180,   181,    88,   333,    89,    90,
      91,    92,    13,   161,   198,   338,    54,   154,    94,   193,
      55,   137,   177,   178,   179,   180,   181,    96,    97,    98,
      99,   138,   161,    57,   182,    76,   183,   180,   181,   184,
      79,   185,   288,   186,   289,   299,    84,    85,   178,   179,
     180,   181,    58,   236,   316,    88,   189,    89,    90,    91,
      92,    76,   274,    63,    64,   189,    79,    94,   278,    65,
      67,   189,    84,    85,   299,   125,    96,    97,    98,    99,
     231,    88,   129,    89,    90,    91,    92,   182,   279,   183,
      71,   189,   184,    94,   284,   310,   186,   189,   189,   328,
     124,   131,    96,    97,    98,    99,   248,    76,   135,   155,
      77,    78,    79,    80,   156,    81,    82,    83,    84,    85,
      86,    87,   311,   159,   290,   189,   289,    88,   160,    89,
      90,    91,    92,   163,    93,   263,   264,   265,   315,    94,
     289,   164,    95,  -136,   179,   180,   181,   165,    96,    97,
      98,    99,    76,   166,   175,    77,    78,    79,    80,   190,
      81,    82,    83,    84,    85,    86,    87,   196,   199,   200,
     209,   211,    88,   189,    89,    90,    91,    92,   225,    93,
     216,   217,   181,   235,    94,   238,   237,    95,  -134,   261,
     247,   262,   268,    96,    97,    98,    99,    76,   285,   293,
      77,    78,    79,    80,   294,    81,    82,    83,    84,    85,
      86,    87,   312,   321,   319,   322,    49,    88,  -102,    89,
      90,    91,    92,   331,    93,   336,   337,   170,    56,    94,
     203,   249,    95,   246,   317,   296,   327,  -140,    96,    97,
      98,    99,    76,    20,   260,    77,    78,    79,    80,    22,
      81,    82,    83,    84,    85,    86,    87,   121,   272,    23,
     144,    46,    88,   273,    89,    90,    91,    92,    76,    93,
     192,   334,   313,    79,    94,     0,   314,    95,     0,    84,
      85,     0,     0,    96,    97,    98,    99,     0,    88,     0,
      89,    90,    91,    92,    76,  -167,     0,     0,     0,    79,
      94,     0,     0,     0,     0,    84,    85,     0,     0,    96,
      97,    98,    99,     0,    88,     0,    89,    90,    91,    92,
      76,     0,     0,     0,     0,    79,    94,     0,     0,     0,
       0,    84,    85,     0,  -140,    96,    97,    98,    99,     0,
      88,     0,    89,    90,    91,    92,  -167,     0,    76,     0,
       0,     0,    94,    79,     0,     0,     0,     0,     0,    84,
      85,    96,    97,    98,    99,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99
};

static const yytype_int16 yycheck[] =
{
       2,    16,     4,   137,    83,    67,     8,   109,   194,     0,
      58,    67,    15,    92,     1,    94,    51,    65,    53,    54,
     224,     4,     5,     6,     1,    13,    88,    89,    28,    91,
      18,    14,    88,    89,    15,    91,    40,    50,    51,    15,
      53,    54,    15,    40,    47,    42,    48,     1,    52,     1,
      52,    15,     4,     5,     6,    70,    39,    44,    73,    53,
      95,    38,    14,     4,     5,     6,   252,     8,   202,    57,
      53,    47,    53,    14,    15,   137,   124,    53,   157,    38,
      53,   137,    95,    47,   163,   164,    40,   166,    42,    53,
     192,    50,    53,    53,   107,    42,   175,    49,    15,   147,
      40,    53,    49,   165,   183,   120,   108,   186,   312,    15,
     189,    51,    53,    40,   176,   177,   178,   179,   180,   181,
     176,   177,   178,   179,   180,   181,   267,   331,     4,     5,
       6,    10,    11,    12,    38,   269,    53,    13,    14,    40,
     202,    42,    18,   222,   223,   224,   202,    53,    24,    25,
     152,    40,   154,    48,    41,   296,    45,    33,    45,    35,
      36,    37,    38,     4,     5,     6,     4,     5,     6,    45,
      49,    42,   274,    14,    39,    46,    14,    42,    54,    55,
      56,    57,     3,     4,     5,     6,     7,     8,     9,   191,
       4,     5,     6,    14,    15,    40,    39,    48,    39,    42,
      14,    38,    46,    48,   283,   220,    13,   269,   310,   311,
      54,    18,    53,   269,    43,    53,    45,    24,    25,   281,
      29,    30,    31,    32,    33,    34,    33,   329,    35,    36,
      37,    38,    53,   312,    39,   337,    48,    42,    45,    53,
      15,    48,    30,    31,    32,    33,    34,    54,    55,    56,
      57,    58,   331,    38,    36,    13,    38,    33,    34,    41,
      18,    43,    40,    45,    42,   267,    24,    25,    31,    32,
      33,    34,    53,    39,   289,    33,    42,    35,    36,    37,
      38,    13,    39,    50,    53,    42,    18,    45,    39,    53,
      43,    42,    24,    25,   296,    39,    54,    55,    56,    57,
      58,    33,    48,    35,    36,    37,    38,    36,    39,    38,
      53,    42,    41,    45,    39,    39,    45,    42,    42,   321,
      53,    44,    54,    55,    56,    57,    58,    13,    45,    40,
      16,    17,    18,    19,    40,    21,    22,    23,    24,    25,
      26,    27,    39,    38,    40,    42,    42,    33,    38,    35,
      36,    37,    38,    38,    40,    10,    11,    12,    40,    45,
      42,    38,    48,    49,    32,    33,    34,    51,    54,    55,
      56,    57,    13,    52,    38,    16,    17,    18,    19,    49,
      21,    22,    23,    24,    25,    26,    27,    49,    49,    49,
      53,    48,    33,    42,    35,    36,    37,    38,    40,    40,
      53,    53,    34,    39,    45,    49,    46,    48,    49,    40,
      53,    40,    46,    54,    55,    56,    57,    13,    39,    44,
      16,    17,    18,    19,    44,    21,    22,    23,    24,    25,
      26,    27,    40,    38,    53,    20,    40,    33,    38,    35,
      36,    37,    38,    40,    40,    40,    39,    92,    34,    45,
     128,   185,    48,   183,   296,   266,   318,    53,    54,    55,
      56,    57,    13,     2,   206,    16,    17,    18,    19,     2,
      21,    22,    23,    24,    25,    26,    27,    52,   219,     2,
      70,    16,    33,   220,    35,    36,    37,    38,    13,    40,
     107,   330,   281,    18,    45,    -1,   283,    48,    -1,    24,
      25,    -1,    -1,    54,    55,    56,    57,    -1,    33,    -1,
      35,    36,    37,    38,    13,    40,    -1,    -1,    -1,    18,
      45,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    54,
      55,    56,    57,    -1,    33,    -1,    35,    36,    37,    38,
      13,    -1,    -1,    -1,    -1,    18,    45,    -1,    -1,    -1,
      -1,    24,    25,    -1,    53,    54,    55,    56,    57,    -1,
      33,    -1,    35,    36,    37,    38,    39,    -1,    13,    -1,
      -1,    -1,    45,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    54,    55,    56,    57,    -1,    -1,    -1,    33,    -1,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     3,     4,     5,     6,     7,     8,
       9,    14,    15,    53,    63,    64,    65,    66,    70,    82,
     101,   102,   103,   106,   107,   110,   114,   115,   116,   117,
     121,   145,   146,     5,    65,    28,    65,    53,    53,    53,
     118,    15,    53,    93,   111,   112,   118,    40,    38,    40,
      48,    48,    38,    48,    48,    15,    67,    38,    53,    71,
      72,   108,    83,    50,    53,    53,    68,    43,   113,    40,
      42,    53,    39,    65,   104,   119,    13,    16,    17,    18,
      19,    21,    22,    23,    24,    25,    26,    27,    33,    35,
      36,    37,    38,    40,    45,    48,    54,    55,    56,    57,
      74,    75,    76,    77,    79,    80,   122,   123,   124,   125,
     126,   127,   128,   133,   135,   138,   139,   144,   122,    39,
      65,   119,   122,   122,    53,    39,    68,    40,    42,    48,
      97,    44,    85,    86,    68,    45,    69,    48,    58,    73,
      74,    75,   124,    53,   112,    15,    47,    67,    93,   105,
     120,    39,    42,    39,    42,    40,    40,     1,    38,    38,
      38,    76,   137,    38,    38,    51,    52,    74,    74,    74,
      66,    76,    76,    78,   122,    38,    29,    30,    31,    32,
      33,    34,    36,    38,    41,    43,    45,     1,    40,    42,
      49,   124,   125,    53,    65,   126,    49,    47,    39,    49,
      49,    68,    43,    72,    65,    91,    98,    99,   109,    53,
      84,    48,    46,    54,    73,    81,    53,    53,    68,    65,
      65,    76,   129,   134,   136,    40,    76,    76,    75,   140,
     141,    58,    76,   142,   143,    39,    39,    46,    49,    76,
      74,    74,    74,    74,    74,    74,    78,    53,    58,    77,
      76,    76,    65,    92,    93,    40,    73,    92,     1,    49,
      99,    40,    40,    10,    11,    12,    87,    88,    46,    42,
      49,    47,   105,   120,    39,    76,    76,   137,    39,    39,
      40,    51,    40,    52,    39,    39,    46,    92,    40,    42,
      40,     1,    44,    44,    44,    49,    88,     8,    15,    65,
      89,    90,    91,    94,   100,   101,   103,   106,    73,   126,
      39,    39,    40,   141,   143,    40,    93,    89,    95,    53,
      53,    38,    20,   131,   126,   126,   137,    97,    65,   132,
     130,    40,    96,   126,   131,   137,    40,    39,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    79,    80,    81,    81,    83,    84,
      82,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    91,    92,    92,    93,    93,
      95,    96,    94,    97,    97,    98,    98,    99,   100,   101,
     101,   102,   103,   103,   104,   104,   105,   105,   106,   108,
     109,   107,   110,   111,   111,   112,   113,   113,   114,   114,
     115,   115,   115,   116,   116,   117,   117,   118,   119,   119,
     120,   120,   121,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   129,   130,   128,   128,   132,
     131,   131,   134,   133,   136,   135,   137,   137,   138,   139,
     139,   140,   140,   141,   142,   142,   143,   143,   144,   145,
     146
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     6,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     3,     2,     4,     3,     1,     4,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     2,     1,     4,     4,     4,     1,     3,     3,     1,
       4,     3,     4,     2,     1,     3,     1,     3,     3,     1,
       1,     0,     1,     1,     1,     3,     3,     1,     0,     0,
       6,     4,     2,     0,     3,     2,     2,     2,     2,     2,
       0,     1,     1,     1,     1,     3,     3,     1,     3,     2,
       0,     0,     5,     3,     3,     2,     1,     1,     1,     2,
       2,     4,     2,     2,     4,     2,     2,     1,     3,     0,
       0,     6,     3,     3,     1,     2,     2,     0,     1,     1,
       4,     4,     4,     4,     4,     3,     3,     2,     4,     2,
       1,     2,     3,     2,     1,     1,     0,     5,     4,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     2,     0,     0,     8,     6,     0,
       3,     0,     0,     6,     0,    10,     1,     0,     3,     4,
       4,     3,     1,     1,     3,     1,     1,     1,     3,     4,
       4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
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
  case 4: /* global_declarations: %empty  */
#line 134 "syntaxAnalyzer.y"
                { }
#line 1814 "syntaxAnalyzer.tab.c"
    break;

  case 11: /* typedef_declaration: "typedef" typename listspec "IDENTIFIER" dims ";"  */
#line 147 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[-2].str), NULL, scope); }
#line 1820 "syntaxAnalyzer.tab.c"
    break;

  case 13: /* typename: "IDENTIFIER"  */
#line 152 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); }
#line 1826 "syntaxAnalyzer.tab.c"
    break;

  case 19: /* listspec: %empty  */
#line 164 "syntaxAnalyzer.y"
                { }
#line 1832 "syntaxAnalyzer.tab.c"
    break;

  case 21: /* dims: %empty  */
#line 169 "syntaxAnalyzer.y"
                { }
#line 1838 "syntaxAnalyzer.tab.c"
    break;

  case 27: /* constdef: "IDENTIFIER" dims "=" init_value  */
#line 187 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[-3].str), NULL, scope); }
#line 1844 "syntaxAnalyzer.tab.c"
    break;

  case 51: /* variable: variable "." "IDENTIFIER"  */
#line 220 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); }
#line 1850 "syntaxAnalyzer.tab.c"
    break;

  case 53: /* variable: decltype "IDENTIFIER"  */
#line 222 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); }
#line 1856 "syntaxAnalyzer.tab.c"
    break;

  case 61: /* expression_list: %empty  */
#line 239 "syntaxAnalyzer.y"
                { }
#line 1862 "syntaxAnalyzer.tab.c"
    break;

  case 68: /* $@1: %empty  */
#line 258 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); scope++;}
#line 1868 "syntaxAnalyzer.tab.c"
    break;

  case 69: /* $@2: %empty  */
#line 259 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1874 "syntaxAnalyzer.tab.c"
    break;

  case 72: /* parent: ":" "IDENTIFIER"  */
#line 268 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); }
#line 1880 "syntaxAnalyzer.tab.c"
    break;

  case 73: /* parent: %empty  */
#line 269 "syntaxAnalyzer.y"
                { }
#line 1886 "syntaxAnalyzer.tab.c"
    break;

  case 77: /* access: "private" error  */
#line 279 "syntaxAnalyzer.y"
                                                                    { yyerror("Error! Missing ':'"); yyerrok; }
#line 1892 "syntaxAnalyzer.tab.c"
    break;

  case 80: /* access: %empty  */
#line 282 "syntaxAnalyzer.y"
                { }
#line 1898 "syntaxAnalyzer.tab.c"
    break;

  case 88: /* variabledef: "list" "IDENTIFIER" dims  */
#line 305 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[-1].str), NULL, scope); }
#line 1904 "syntaxAnalyzer.tab.c"
    break;

  case 89: /* variabledef: "IDENTIFIER" dims  */
#line 306 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[-1].str), NULL, scope); }
#line 1910 "syntaxAnalyzer.tab.c"
    break;

  case 90: /* $@3: %empty  */
#line 310 "syntaxAnalyzer.y"
                                                                    { scope++; }
#line 1916 "syntaxAnalyzer.tab.c"
    break;

  case 91: /* $@4: %empty  */
#line 311 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--;  }
#line 1922 "syntaxAnalyzer.tab.c"
    break;

  case 94: /* union_body: "{" fields error  */
#line 317 "syntaxAnalyzer.y"
                                                                    { yyerror("Error! Missing '}'"); yyerrok; }
#line 1928 "syntaxAnalyzer.tab.c"
    break;

  case 99: /* short_func_declaration: short_par_func_header ";"  */
#line 334 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1934 "syntaxAnalyzer.tab.c"
    break;

  case 100: /* short_func_declaration: nopar_func_header ";"  */
#line 335 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1940 "syntaxAnalyzer.tab.c"
    break;

  case 102: /* func_header_start: typename "IDENTIFIER"  */
#line 343 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); scope++; }
#line 1946 "syntaxAnalyzer.tab.c"
    break;

  case 103: /* func_header_start: "list" "IDENTIFIER"  */
#line 344 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); }
#line 1952 "syntaxAnalyzer.tab.c"
    break;

  case 109: /* $@5: %empty  */
#line 362 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); scope++; }
#line 1958 "syntaxAnalyzer.tab.c"
    break;

  case 110: /* $@6: %empty  */
#line 363 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1964 "syntaxAnalyzer.tab.c"
    break;

  case 117: /* initializer: %empty  */
#line 382 "syntaxAnalyzer.y"
                { }
#line 1970 "syntaxAnalyzer.tab.c"
    break;

  case 120: /* full_func_declaration: full_par_func_header "{" decl_statements "}"  */
#line 391 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1976 "syntaxAnalyzer.tab.c"
    break;

  case 121: /* full_func_declaration: nopar_class_func_header "{" decl_statements "}"  */
#line 392 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1982 "syntaxAnalyzer.tab.c"
    break;

  case 122: /* full_func_declaration: nopar_func_header "{" decl_statements "}"  */
#line 393 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 1988 "syntaxAnalyzer.tab.c"
    break;

  case 125: /* class_func_header_start: typename func_class "IDENTIFIER"  */
#line 402 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); scope++; }
#line 1994 "syntaxAnalyzer.tab.c"
    break;

  case 126: /* class_func_header_start: "list" func_class "IDENTIFIER"  */
#line 403 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); scope++; }
#line 2000 "syntaxAnalyzer.tab.c"
    break;

  case 127: /* func_class: "IDENTIFIER" "::"  */
#line 407 "syntaxAnalyzer.y"
                                                                    { hashtbl_insert(hashtbl, (yyvsp[-1].str), NULL, scope); }
#line 2006 "syntaxAnalyzer.tab.c"
    break;

  case 131: /* pass_variabledef: "&" "IDENTIFIER"  */
#line 417 "syntaxAnalyzer.y"
                                                                      { hashtbl_insert(hashtbl, (yyvsp[0].str), NULL, scope); }
#line 2012 "syntaxAnalyzer.tab.c"
    break;

  case 136: /* decl_statements: %empty  */
#line 428 "syntaxAnalyzer.y"
                { }
#line 2018 "syntaxAnalyzer.tab.c"
    break;

  case 140: /* decltype: %empty  */
#line 438 "syntaxAnalyzer.y"
                { }
#line 2024 "syntaxAnalyzer.tab.c"
    break;

  case 154: /* expression_statement: general_expression error  */
#line 461 "syntaxAnalyzer.y"
                                                                    { yyerror("Error! Missing ';'"); yyerrok; }
#line 2030 "syntaxAnalyzer.tab.c"
    break;

  case 155: /* $@7: %empty  */
#line 465 "syntaxAnalyzer.y"
                                                                    { scope++; }
#line 2036 "syntaxAnalyzer.tab.c"
    break;

  case 156: /* $@8: %empty  */
#line 466 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 2042 "syntaxAnalyzer.tab.c"
    break;

  case 158: /* if_statement: "if" error general_expression ")" statement if_tail  */
#line 468 "syntaxAnalyzer.y"
                                                                    { yyerror("Error! Missing '('"); yyerrok; }
#line 2048 "syntaxAnalyzer.tab.c"
    break;

  case 159: /* $@9: %empty  */
#line 472 "syntaxAnalyzer.y"
                                                                    { scope++; }
#line 2054 "syntaxAnalyzer.tab.c"
    break;

  case 160: /* if_tail: "else" $@9 statement  */
#line 473 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 2060 "syntaxAnalyzer.tab.c"
    break;

  case 161: /* if_tail: %empty  */
#line 474 "syntaxAnalyzer.y"
                                     { }
#line 2066 "syntaxAnalyzer.tab.c"
    break;

  case 162: /* $@10: %empty  */
#line 478 "syntaxAnalyzer.y"
                                                                    { scope++; }
#line 2072 "syntaxAnalyzer.tab.c"
    break;

  case 163: /* while_statement: "while" "(" $@10 general_expression ")" statement  */
#line 479 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 2078 "syntaxAnalyzer.tab.c"
    break;

  case 164: /* $@11: %empty  */
#line 483 "syntaxAnalyzer.y"
                                                                    { scope++; }
#line 2084 "syntaxAnalyzer.tab.c"
    break;

  case 165: /* for_statement: "for" "(" $@11 optexpr ";" optexpr ";" optexpr ")" statement  */
#line 484 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope); scope--; }
#line 2090 "syntaxAnalyzer.tab.c"
    break;

  case 167: /* optexpr: %empty  */
#line 489 "syntaxAnalyzer.y"
                { }
#line 2096 "syntaxAnalyzer.tab.c"
    break;

  case 179: /* main_function: main_header "{" decl_statements "}"  */
#line 526 "syntaxAnalyzer.y"
                                                                    { hashtbl_get(hashtbl, scope);  scope--; }
#line 2102 "syntaxAnalyzer.tab.c"
    break;

  case 180: /* main_header: "int" "main" "(" ")"  */
#line 530 "syntaxAnalyzer.y"
                                                                    { scope++; }
#line 2108 "syntaxAnalyzer.tab.c"
    break;


#line 2112 "syntaxAnalyzer.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 533 "syntaxAnalyzer.y"



int main(int argc, char *argv[]) {

    if(!(hashtbl = hashtbl_create(10, NULL))) {
        puts("Error, failed to initialize hashtable!\n");
        exit(EXIT_FAILURE);
    }

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL) {
            perror("Error opening file!\n");
            return -1;
        }
    }

    yyparse();

    hashtbl_get(hashtbl, scope);

    hashtbl_destroy(hashtbl);
    fclose(yyin);

    if(syntaxErrors > 0){
        printf("Syntax Analysis failed due to %d errors\n", syntaxErrors);
    }else{
        printf("Syntax Analysis completed successfully.\n");
    }

    return 0;
}

void yyerror(const char * message) {
    syntaxErrors++;

    printf("Error at line %d caused by %s: %s\n", lineNum, yytext, message);

    if(syntaxErrors == 5) {
        printf("Too many errors! Exitting...\n"); 
        exit(1);
    }
}
