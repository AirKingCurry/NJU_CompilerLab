/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "syntax.y" /* yacc.c:337  */

    #include<stdio.h>
    #include "lex.yy.c"
    #include"tree.h"
    void yyerror(char* msg);
    extern Tree* ROOT;
    int misline[4096]={0};

#line 79 "syntax.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    ID = 260,
    SEMI = 261,
    COMMA = 262,
    ASSIGNOP = 263,
    RELOP = 264,
    PLUS = 265,
    MINUS = 266,
    STAR = 267,
    DIV = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    DOT = 272,
    TYPE = 273,
    LP = 274,
    RP = 275,
    LB = 276,
    RB = 277,
    LC = 278,
    RC = 279,
    STRUCT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    LCOM = 285,
    RCOM = 286,
    LOWER_THAN_ELSE = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "syntax.y" /* yacc.c:352  */

    /*int type_int;
    float type_float;
    double type_double;
    char type_char;
    char* type_string;*/
    struct TREE* type_tree;

#line 164 "syntax.tab.c" /* yacc.c:352  */
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

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

#define YYUNDEFTOK  2
#define YYMAXUTOK   287

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    62,    63,    65,    66,    67,    68,    76,
      83,    90,    97,   104,   111,   119,   120,   122,   123,   125,
     126,   127,   134,   142,   143,   145,   147,   148,   149,   157,
     158,   159,   166,   174,   175,   177,   179,   180,   187,   195,
     196,   198,   199,   200,   201,   203,   204,   211,   212,   219,
     226,   233,   240,   248,   249,   251,   252,   259,   266,   274,
     275,   277,   278,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   305,   312,   319,   326,   333,   340,   347,   354,
     361,   369,   370
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "SEMI", "COMMA",
  "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "NOT",
  "DOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN",
  "IF", "ELSE", "WHILE", "LCOM", "RCOM", "LOWER_THAN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -54

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   108,  -110,    18,    20,  -110,    25,     6,  -110,    29,
    -110,  -110,  -110,    32,    57,    37,    33,    39,  -110,  -110,
    -110,    57,   136,  -110,    66,     1,    57,    79,    53,    59,
      82,    63,  -110,  -110,    59,  -110,  -110,   124,    99,  -110,
    -110,    65,  -110,   124,   110,   127,   130,     8,   115,    63,
    -110,    93,   116,  -110,  -110,   128,   131,  -110,  -110,   125,
    -110,   106,    33,    87,   146,   158,   161,   163,  -110,  -110,
      22,  -110,  -110,   154,   283,   283,   283,   283,    50,    56,
    -110,   153,    93,   295,  -110,  -110,  -110,   165,  -110,   283,
    -110,   124,  -110,  -110,  -110,   155,   151,    -3,   353,   309,
     156,   283,    81,   283,  -110,  -110,  -110,   175,   184,   201,
     210,   227,   236,   253,   262,   176,   279,   395,  -110,   177,
    -110,   324,   162,  -110,  -110,   122,   367,  -110,  -110,   381,
     186,   395,   187,   433,   190,   151,   191,   151,   192,    -3,
     193,    -3,   195,   421,   202,   408,  -110,   168,   338,  -110,
     283,  -110,  -110,   122,   122,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,   179,  -110,   122,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    17,     0,     0,     2,     0,     0,    18,     0,
       9,    10,    11,     0,     0,     0,    25,     0,    20,     1,
       4,     0,     0,     6,    13,    15,     0,     0,     0,     0,
       0,     0,     8,    21,     0,    12,     5,     0,     0,     7,
      32,    23,    30,     0,     0,    34,    23,     0,     0,     0,
      38,     0,     0,    26,    16,     0,     0,    24,    31,    35,
      29,     0,    26,    61,     0,    59,     0,    58,    22,    54,
       0,    79,    80,    78,     0,     0,     0,     0,     0,     0,
      42,    37,     0,    51,    19,    28,    27,    23,    33,     0,
      57,     0,    56,    55,    50,     0,    72,    73,     0,    52,
       0,     0,     0,     0,    36,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    60,     0,
      75,    92,     0,    71,    43,     0,     0,    48,    49,     0,
       0,    63,     0,    66,     0,    67,     0,    68,     0,    69,
       0,    70,     0,    64,     0,    65,    77,     0,     0,    89,
       0,    74,    46,     0,     0,    81,    84,    85,    86,    87,
      88,    82,    83,    90,    76,    91,    44,    47,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   203,  -110,   173,     4,  -110,   213,  -110,    10,
     211,   164,  -110,    89,   137,  -109,   113,  -110,   -42,  -110,
     -74,    72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    24,    47,     8,    13,    18,    63,
      14,    44,    45,    80,    81,    82,    48,    49,    64,    65,
      83,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    97,    98,    99,     7,    67,   -14,    21,    37,    66,
       7,    22,    23,    53,   115,   117,   152,    25,   116,    15,
      19,   121,    38,    16,   -14,    -3,     1,   126,    94,   129,
      27,   -14,    43,   131,   133,   135,   137,   139,   141,   143,
     145,   -23,   148,     2,   166,   167,    50,    25,    28,   118,
       3,   100,   -24,    59,    41,    29,   -24,   102,    30,   169,
      46,    33,    34,   -53,    46,    43,   -53,   -53,   -53,   101,
      57,     2,    36,    42,   -53,   103,   121,     2,     3,   -53,
      31,     2,   -53,   -53,     3,    58,   -53,   -53,     3,   -53,
     -53,   -53,   -53,   -39,    70,    89,    71,    72,    73,    40,
      55,   127,    56,    32,    74,   128,    50,    87,    38,    75,
      35,   -39,    76,     9,    10,    39,    31,   -39,   -39,    77,
      78,   -39,    79,    70,     2,    71,    72,    73,    11,    53,
      60,     3,    12,    74,    61,    62,   -26,    27,    75,    68,
      84,    76,   -26,   -26,    51,    31,    38,    52,    77,    78,
      85,    79,    90,    86,   -26,    28,   119,   -26,    71,    72,
      73,   -26,    69,   111,   112,    91,    74,    92,   115,    93,
      57,    75,   116,    95,    76,   120,   130,   104,    71,    72,
      73,   146,   151,   149,   125,   132,    74,    71,    72,    73,
     163,    75,   155,   156,    76,    74,   157,   158,   159,   160,
      75,   161,   134,    76,    71,    72,    73,   168,   162,    20,
      54,   136,    74,    71,    72,    73,    17,    75,    26,   105,
      76,    74,   165,     0,     0,    88,    75,     0,   138,    76,
      71,    72,    73,     0,     0,     0,     0,   140,    74,    71,
      72,    73,     0,    75,     0,     0,    76,    74,     0,     0,
       0,     0,    75,     0,   142,    76,    71,    72,    73,     0,
       0,     0,     0,   144,    74,    71,    72,    73,     0,    75,
       0,     0,    76,    74,     0,     0,     0,     0,    75,     0,
     147,    76,    71,    72,    73,     0,    71,    72,    73,     0,
      74,     0,     0,     0,    74,    75,     0,     0,    76,    75,
       0,   106,    76,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,     0,     0,   124,   116,   107,   108,   109,
     110,   111,   112,   113,   114,     0,   115,     0,     0,     0,
     116,   150,   107,   108,   109,   110,   111,   112,   113,   114,
       0,   115,     0,     0,     0,   116,   107,   108,   109,   110,
     111,   112,   113,   114,     0,   115,     0,     0,     0,   116,
     164,   107,   108,   109,   110,   111,   112,   113,   114,     0,
     115,     0,     0,   123,   116,   107,   108,   109,   110,   111,
     112,   113,   114,     0,   115,     0,     0,   153,   116,   107,
     108,   109,   110,   111,   112,   113,   114,     0,   115,     0,
       0,   154,   116,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,     0,     0,     0,   116,   108,   109,   110,
     111,   112,   113,     0,     0,   115,     0,     0,     0,   116,
     108,   109,   110,   111,   112,     0,     0,     0,   115,     0,
       0,     0,   116,   109,   110,   111,   112,     0,     0,     0,
     115,     0,     0,     0,   116
};

static const yytype_int16 yycheck[] =
{
      74,    75,    76,    77,     0,    47,     0,     1,     7,     1,
       6,     5,     6,     5,    17,    89,   125,     7,    21,     1,
       0,    95,    21,     5,    18,     0,     1,   101,     6,   103,
       1,    25,    28,   107,   108,   109,   110,   111,   112,   113,
     114,    23,   116,    18,   153,   154,    24,    37,    19,    91,
      25,     1,    23,    43,     1,    23,    23,     1,     1,   168,
       1,    24,    23,     0,     1,    61,     3,     4,     5,    19,
       5,    18,     6,    20,    11,    19,   150,    18,    25,    16,
      23,    18,    19,    24,    25,    20,    23,    24,    25,    26,
      27,    28,    29,     0,     1,     8,     3,     4,     5,    20,
       1,    20,     3,    14,    11,    24,    24,     1,    21,    16,
      21,    18,    19,     5,     6,    26,    23,    24,    25,    26,
      27,    28,    29,     1,    18,     3,     4,     5,    20,     5,
      20,    25,    24,    11,     7,     5,     0,     1,    16,    24,
      24,    19,     6,     7,    31,    23,    21,    34,    26,    27,
      22,    29,     6,    22,    18,    19,     1,    21,     3,     4,
       5,    25,    49,    12,    13,     7,    11,     6,    17,     6,
       5,    16,    21,    19,    19,    20,     1,    24,     3,     4,
       5,     5,    20,     6,    28,     1,    11,     3,     4,     5,
      22,    16,     6,     6,    19,    11,     6,     6,     6,     6,
      16,     6,     1,    19,     3,     4,     5,    28,     6,     6,
      37,     1,    11,     3,     4,     5,     3,    16,     7,    82,
      19,    11,   150,    -1,    -1,    61,    16,    -1,     1,    19,
       3,     4,     5,    -1,    -1,    -1,    -1,     1,    11,     3,
       4,     5,    -1,    16,    -1,    -1,    19,    11,    -1,    -1,
      -1,    -1,    16,    -1,     1,    19,     3,     4,     5,    -1,
      -1,    -1,    -1,     1,    11,     3,     4,     5,    -1,    16,
      -1,    -1,    19,    11,    -1,    -1,    -1,    -1,    16,    -1,
       1,    19,     3,     4,     5,    -1,     3,     4,     5,    -1,
      11,    -1,    -1,    -1,    11,    16,    -1,    -1,    19,    16,
      -1,     6,    19,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,     6,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      21,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    -1,    21,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    21,
      22,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    21,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    21,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17,    -1,    -1,    -1,    21,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    21,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    18,    25,    34,    35,    36,    38,    39,     5,
       6,    20,    24,    40,    43,     1,     5,    40,    41,     0,
      35,     1,     5,     6,    37,    42,    43,     1,    19,    23,
       1,    23,    46,    24,    23,    46,     6,     7,    21,    46,
      20,     1,    20,    38,    44,    45,     1,    38,    49,    50,
      24,    49,    49,     5,    37,     1,     3,     5,    20,    42,
      20,     7,     5,    42,    51,    52,     1,    51,    24,    49,
       1,     3,     4,     5,    11,    16,    19,    26,    27,    29,
      46,    47,    48,    53,    24,    22,    22,     1,    44,     8,
       6,     7,     6,     6,     6,    19,    53,    53,    53,    53,
       1,    19,     1,    19,    24,    47,     6,     8,     9,    10,
      11,    12,    13,    14,    15,    17,    21,    53,    51,     1,
      20,    53,    54,    20,     6,    28,    53,    20,    24,    53,
       1,    53,     1,    53,     1,    53,     1,    53,     1,    53,
       1,    53,     1,    53,     1,    53,     5,     1,    53,     6,
       7,    20,    48,    20,    20,     6,     6,     6,     6,     6,
       6,     6,     6,    22,    22,    54,    48,    48,    28,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    37,    37,    38,    38,    39,
      39,    39,    39,    40,    40,    41,    42,    42,    42,    43,
      43,    43,    43,    44,    44,    45,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     3,     2,
       2,     2,     3,     2,     1,     1,     3,     1,     1,     5,
       2,     3,     5,     0,     1,     1,     1,     4,     4,     4,
       3,     4,     3,     3,     1,     2,     4,     3,     2,     0,
       2,     2,     1,     3,     5,     7,     4,     5,     3,     3,
       2,     1,     2,     0,     2,     3,     3,     3,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 60 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Program","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));ROOT=(yyval.type_tree);}
#line 1535 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 62 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=NULL;}
#line 1541 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 63 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ExtDefList","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1547 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 65 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ExtDef","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1553 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 66 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ExtDef","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1559 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 67 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ExtDef","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1565 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 68 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-2]).first_line-1]==0){
                            misline[(yylsp[-2]).first_line-1]=1;
                        mistake++;
                        printf("Error Type B at Line %d: syntax error.\n", (yylsp[-2]).first_line);
                        
                    }
            }
#line 1578 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 76 "syntax.y" /* yacc.c:1652  */
    {
                         if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1590 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 83 "syntax.y" /* yacc.c:1652  */
    {
                   if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1602 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 90 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1614 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 97 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1626 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 104 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[0]).last_line-1]==0){
                                misline[(yylsp[0]).last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[0]).last_line);
                        }
            }
#line 1638 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 111 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[0]).last_line-1]==0){
                                misline[(yylsp[0]).last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[0]).last_line);
                        }
            }
#line 1650 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 119 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ExtDecList","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1656 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 120 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ExtDecList","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1662 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 122 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Specifier","",1);add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1668 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 123 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Specifier","",1);add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1674 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 125 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("StructSpecifier","",1),add(5,(yyval.type_tree),(yyvsp[-4].type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1680 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 126 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("StructSpecifier","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1686 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 127 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1698 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 134 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-4]).first_line-1]==0){
                                misline[(yylsp[-4]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-4]).first_line);
                        }
            }
#line 1710 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 142 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=NULL;}
#line 1716 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 143 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("OptTag","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1722 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 145 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Tag","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1728 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 147 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("VarDec","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1734 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 148 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("VarDec","",1),add(4,(yyval.type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1740 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 149 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1752 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 157 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("FunDec","",1),add(4,(yyval.type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1758 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 158 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("FunDec","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1764 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 159 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1776 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 166 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1788 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 174 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("VarList","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1794 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 175 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("VarList","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1800 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 177 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("ParamDec","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1806 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 179 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("CompSt","",1),add(4,(yyval.type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1812 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 180 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[0]).last_line-1]==0){
                                misline[(yylsp[0]).last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[0]).last_line);
                        }
            }
#line 1824 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 187 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1836 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 195 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=NULL;}
#line 1842 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 196 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("StmtList","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1848 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 198 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Stmt","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1854 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 199 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Stmt","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 1860 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 200 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Stmt","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1866 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 202 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Stmt","",1),add(5,(yyval.type_tree),(yyvsp[-4].type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1872 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 203 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Stmt","",1),add(7,(yyval.type_tree),(yyvsp[-6].type_tree),(yyvsp[-5].type_tree),(yyvsp[-4].type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1878 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 204 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-2]).first_line-1]==0){
                                misline[(yylsp[-2]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-2]).first_line);
                        }
            }
#line 1890 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 211 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Stmt","",1),add(5,(yyval.type_tree),(yyvsp[-4].type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1896 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 212 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1908 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 219 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1920 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 226 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1932 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 233 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[0]).last_line-1]==0){
                                misline[(yylsp[0]).last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[0]).last_line);
                        }
            }
#line 1944 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 240 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[0]).last_line-1]==0){
                                misline[(yylsp[0]).last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[0]).last_line);
                        }
            }
#line 1956 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 248 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=NULL;}
#line 1962 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 249 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("DefList","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1968 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 251 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Def","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 1974 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 252 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 1986 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 259 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-2]).first_line-1]==0){
                                misline[(yylsp[-2]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-2]).first_line);
                        }
            }
#line 1998 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 266 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[0]).last_line-1]==0){
                                misline[(yylsp[0]).last_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[0]).last_line);
                        }
            }
#line 2010 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 274 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("DecList","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 2016 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 275 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("DecList","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2022 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 277 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Dec","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 2028 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 278 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Dec","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2034 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 280 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2040 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 281 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2046 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 282 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2052 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 283 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2058 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 284 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2064 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 285 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2070 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 286 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2076 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 287 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2082 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 288 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2088 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 289 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2094 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 290 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(2,(yyval.type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2100 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 291 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(4,(yyval.type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2106 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 292 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2112 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 293 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(4,(yyval.type_tree),(yyvsp[-3].type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2118 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 294 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2124 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 295 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 2130 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 296 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 2136 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 297 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Exp","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 2142 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 298 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-3]).first_line-1]==0){
                                misline[(yylsp[-3]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-3]).first_line);
                        }
            }
#line 2154 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 305 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2166 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 312 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-3]).first_line-1]==0){
                                misline[(yylsp[-3]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-3]).first_line);
                        }
            }
#line 2178 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 319 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2190 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 326 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2202 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 333 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2214 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 340 "syntax.y" /* yacc.c:1652  */
    {
                   if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2226 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 347 "syntax.y" /* yacc.c:1652  */
    {
                   if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2238 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 354 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                                misline[(yylsp[-1]).first_line-1]=1;
                                mistake++;
                                printf("Error Type B at Line %d: syntax error.\n", (yylsp[-1]).first_line);
                        }
            }
#line 2250 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 361 "syntax.y" /* yacc.c:1652  */
    {
                    if(misline[(yylsp[-1]).first_line-1]==0){
                        misline[(yylsp[-1]).first_line-1]=1;
                        mistake++;
                        printf("Error Type B at Line %d: wrong expression between \"[\" and \"]\".\n", (yylsp[-1]).first_line);
                    }
            }
#line 2262 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 369 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Args","",1),add(3,(yyval.type_tree),(yyvsp[-2].type_tree),(yyvsp[-1].type_tree),(yyvsp[0].type_tree));}
#line 2268 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 370 "syntax.y" /* yacc.c:1652  */
    {(yyval.type_tree)=create("Args","",1),add(1,(yyval.type_tree),(yyvsp[0].type_tree));}
#line 2274 "syntax.tab.c" /* yacc.c:1652  */
    break;


#line 2278 "syntax.tab.c" /* yacc.c:1652  */
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 372 "syntax.y" /* yacc.c:1918  */

void yyerror(char* msg)
{
        ;
}
