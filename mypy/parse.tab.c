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
#line 2 "parse.y" /* yacc.c:339  */

      #include <iostream>
      #include <string>
      #include <map>
      #include <cmath>
      #include <cstring>
      #include "ast.h"
      #include "SymTabManager.h"
	
	extern int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
	

       PoolOfNodes& pool = PoolOfNodes::getInstance();
	//Node* currentsuite;
	//Node* mainsuite;
  SymTabManager& stm = SymTabManager::getInstance();


#line 87 "parse.tab.c" /* yacc.c:339  */

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
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPERSAND = 258,
    AND = 259,
    AS = 260,
    ASSERT = 261,
    AT = 262,
    BACKQUOTE = 263,
    BAR = 264,
    BREAK = 265,
    CIRCUMFLEX = 266,
    CLASS = 267,
    COLON = 268,
    COMMA = 269,
    CONTINUE = 270,
    DEDENT = 271,
    DEF = 272,
    DEL = 273,
    DOT = 274,
    DOUBLESTAR = 275,
    ELIF = 276,
    ELSE = 277,
    ENDMARKER = 278,
    EQUAL = 279,
    EXCEPT = 280,
    EXEC = 281,
    FINALLY = 282,
    FOR = 283,
    FROM = 284,
    GLOBAL = 285,
    IF = 286,
    IMPORT = 287,
    INDENT = 288,
    LAMBDA = 289,
    LBRACE = 290,
    LPAR = 291,
    LSQB = 292,
    NEWLINE = 293,
    NOT = 294,
    NUMBER = 295,
    OR = 296,
    PASS = 297,
    PRINT = 298,
    RAISE = 299,
    RBRACE = 300,
    RETURN = 301,
    RPAR = 302,
    RSQB = 303,
    SEMI = 304,
    STRING = 305,
    TRY = 306,
    WHILE = 307,
    WITH = 308,
    YIELD = 309,
    MINUS = 310,
    PLUS = 311,
    TILDE = 312,
    STAR = 313,
    SLASH = 314,
    PERCENT = 315,
    DOUBLESLASH = 316,
    LEFTSHIFT = 317,
    RIGHTSHIFT = 318,
    PLUSEQUAL = 319,
    MINEQUAL = 320,
    STAREQUAL = 321,
    SLASHEQUAL = 322,
    PERCENTEQUAL = 323,
    AMPEREQUAL = 324,
    GRLT = 325,
    GREATEREQUAL = 326,
    LESSEQUAL = 327,
    NOTEQUAL = 328,
    EQEQUAL = 329,
    LESS = 330,
    GREATER = 331,
    IS = 332,
    IN = 333,
    VBAREQUAL = 334,
    CIRCUMFLEXEQUAL = 335,
    LEFTSHIFTEQUAL = 336,
    RIGHTSHIFTEQUAL = 337,
    DOUBLESTAREQUAL = 338,
    DOUBLESLASHEQUAL = 339,
    NAME = 340,
    INT = 341,
    FLOAT = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "parse.y" /* yacc.c:355  */

  Node* node;
  int intNumber;
  long double fltNumber;
  char *id;
  std::vector<Node*>* vectorNode;

#line 223 "parse.tab.c" /* yacc.c:355  */
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

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 254 "parse.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   805

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  316
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  480

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    82,    88,    90,    99,   104,   107,   108,
     111,   112,   115,   116,   119,   120,   123,   136,   137,   140,
     141,   144,   145,   148,   149,   152,   153,   156,   157,   160,
     161,   164,   165,   168,   169,   172,   173,   176,   177,   180,
     185,   191,   193,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   207,   254,   270,   271,   274,   289,   297,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   317,   322,   325,   335,   338,   349,   352,   353,   356,
     357,   360,   363,   366,   367,   368,   369,   370,   373,   376,
     379,   385,   394,   397,   398,   401,   402,   405,   406,   409,
     410,   413,   416,   419,   420,   423,   424,   425,   428,   429,
     432,   433,   436,   437,   440,   441,   444,   445,   448,   449,
     452,   455,   456,   459,   460,   463,   464,   467,   468,   469,
     470,   471,   472,   473,   474,   477,   482,   489,   490,   493,
     494,   497,   498,   501,   502,   505,   506,   509,   510,   513,
     514,   517,   520,   521,   524,   525,   528,   529,   532,   533,
     536,   537,   540,   545,   553,   558,   565,   566,   569,   570,
     573,   574,   577,   578,   581,   585,   590,   593,   596,   597,
     600,   601,   604,   605,   608,   609,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   642,   643,   649,
     650,   656,   657,   663,   664,   680,   681,   684,   685,   700,
     701,   704,   705,   728,   729,   730,   731,   734,   749,   753,
     754,   755,   758,   763,   773,   774,   778,   779,   780,   781,
     782,   804,   808,   812,   813,   816,   817,   820,   821,   824,
     825,   828,   829,   832,   833,   836,   837,   840,   844,   850,
     851,   854,   855,   856,   859,   860,   863,   864,   867,   868,
     869,   872,   873,   876,   877,   880,   881,   884,   886,   890,
     891,   894,   895,   898,   899,   902,   903,   906,   907,   910,
     911,   914,   915,   918,   919,   922,   925,   926,   929,   930,
     933,   934,   937,   938,   939,   942,   943,   946,   947,   950,
     951,   954,   955,   958,   959,   962,   963,   966,   967,   970,
     971,   974,   975,   978,   979,   982,   983
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPERSAND", "AND", "AS", "ASSERT", "AT",
  "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX", "CLASS", "COLON", "COMMA",
  "CONTINUE", "DEDENT", "DEF", "DEL", "DOT", "DOUBLESTAR", "ELIF", "ELSE",
  "ENDMARKER", "EQUAL", "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM",
  "GLOBAL", "IF", "IMPORT", "INDENT", "LAMBDA", "LBRACE", "LPAR", "LSQB",
  "NEWLINE", "NOT", "NUMBER", "OR", "PASS", "PRINT", "RAISE", "RBRACE",
  "RETURN", "RPAR", "RSQB", "SEMI", "STRING", "TRY", "WHILE", "WITH",
  "YIELD", "MINUS", "PLUS", "TILDE", "STAR", "SLASH", "PERCENT",
  "DOUBLESLASH", "LEFTSHIFT", "RIGHTSHIFT", "PLUSEQUAL", "MINEQUAL",
  "STAREQUAL", "SLASHEQUAL", "PERCENTEQUAL", "AMPEREQUAL", "GRLT",
  "GREATEREQUAL", "LESSEQUAL", "NOTEQUAL", "EQEQUAL", "LESS", "GREATER",
  "IS", "IN", "VBAREQUAL", "CIRCUMFLEXEQUAL", "LEFTSHIFTEQUAL",
  "RIGHTSHIFTEQUAL", "DOUBLESTAREQUAL", "DOUBLESLASHEQUAL", "NAME", "INT",
  "FLOAT", "$accept", "start", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "opt_COMMA", "fpdef", "fplist", "star_fpdef_notest", "stmt",
  "simple_stmt", "star_SEMI_small_stmt", "small_stmt", "expr_stmt",
  "pick_yield_expr_testlist", "star_EQUAL", "star_EQUAL_R", "augassign",
  "print_stmt", "star_COMMA_test", "opt_test", "plus_COMMA_test",
  "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "pick_dotted_name", "pick_STAR_import", "import_as_name",
  "dotted_as_name", "import_as_names", "star_COMMA_import_as_name",
  "dotted_as_names", "dotted_name", "global_stmt", "star_COMMA_NAME",
  "exec_stmt", "assert_stmt", "compound_stmt", "if_stmt", "star_ELIF",
  "while_stmt", "for_stmt", "try_stmt", "plus_except", "opt_ELSE",
  "opt_FINALLY", "with_stmt", "star_COMMA_with_item", "with_item",
  "except_clause", "pick_AS_COMMA", "opt_AS_COMMA", "suite", "plus_stmt",
  "testlist_safe", "plus_COMMA_old_test", "old_test", "old_lambdef",
  "test", "opt_IF_ELSE", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "star_COMMA_subscript",
  "subscript", "opt_test_only", "opt_sliceop", "sliceop", "exprlist",
  "star_COMMA_expr", "testlist", "dictorsetmaker", "star_test_COLON_test",
  "pick_for_test_test", "pick_for_test", "classdef", "opt_testlist",
  "arglist", "star_argument_COMMA", "star_COMMA_argument",
  "opt_DOUBLESTAR_test", "pick_argument", "argument", "opt_comp_for",
  "list_iter", "list_for", "list_if", "comp_iter", "comp_for", "comp_if",
  "testlist1", "yield_expr", "star_DOT", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -333

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-333)))

#define YYTABLE_NINF -263

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -333,    32,  -333,    29,  -333,   661,   -35,   661,  -333,   -15,
    -333,    56,    89,  -333,    89,    89,  -333,    63,   661,   -35,
     104,   661,   383,   661,  -333,   718,  -333,  -333,   595,   661,
     661,  -333,   140,   661,   661,   661,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,    36,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,    99,   117,  -333,   207,   148,   150,   165,
     127,   169,   197,  -333,    89,  -333,  -333,   128,  -333,   362,
    -333,  -333,   166,  -333,    73,  -333,    79,    20,   146,   148,
    -333,    16,   106,   175,    19,  -333,   184,  -333,   202,   113,
     661,   206,    42,    82,   188,  -333,   209,  -333,   195,  -333,
    -333,   222,   187,  -333,  -333,   661,  -333,  -333,   237,  -333,
     314,   240,  -333,   259,  -333,  -333,  -333,  -333,    52,   251,
     718,   718,  -333,   718,   189,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,   227,  -333,    89,    89,    89,    89,  -333,  -333,
      89,  -333,  -333,    89,  -333,  -333,  -333,  -333,    89,  -333,
     123,  -333,   383,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,   383,   661,   185,
     224,  -333,  -333,   661,   314,   661,   228,   256,   260,   661,
     661,    18,   244,   267,   273,   314,   -35,   208,  -333,   661,
     210,     6,   211,  -333,  -333,   270,   661,    89,   285,  -333,
    -333,  -333,   285,  -333,  -333,    89,   285,  -333,  -333,   286,
     285,   661,  -333,   268,  -333,   142,   314,   214,    89,  -333,
     570,   661,    55,   117,  -333,  -333,  -333,   148,   150,   165,
     127,   169,   197,  -333,   221,    89,   224,   628,  -333,   283,
    -333,  -333,  -333,  -333,  -333,   263,  -333,   115,  -333,  -333,
    -333,   264,  -333,   265,   314,    89,   299,   302,   231,  -333,
     312,  -333,  -333,  -333,   233,  -333,  -333,  -333,  -333,  -333,
    -333,   272,   307,   661,   309,   209,   250,   661,  -333,  -333,
     253,  -333,   661,   319,  -333,  -333,   299,   508,   661,   322,
     111,   323,   315,   314,   661,   148,  -333,  -333,  -333,   661,
    -333,  -333,   291,   320,   328,   294,  -333,   332,  -333,   321,
     661,   661,    21,  -333,   333,   348,  -333,  -333,   148,   661,
    -333,   314,   316,   280,   352,  -333,   226,   353,  -333,   355,
    -333,  -333,    27,  -333,   358,  -333,  -333,   718,   685,  -333,
     661,  -333,  -333,  -333,   446,   108,   314,   360,   349,   364,
     314,   366,  -333,  -333,  -333,  -333,   361,  -333,   367,   661,
    -333,  -333,  -333,   661,  -333,  -333,   335,  -333,   314,  -333,
     363,  -333,  -333,   231,   661,   370,     6,   303,   661,  -333,
     167,   371,   135,   373,  -333,   351,  -333,  -333,  -333,  -333,
    -333,   661,  -333,  -333,   314,   377,  -333,   314,  -333,   314,
    -333,   204,  -333,   381,   382,  -333,  -333,   384,  -333,   385,
     314,  -333,  -333,   389,   685,  -333,  -333,  -333,   685,   390,
     685,  -333,  -333,  -333,   685,   391,  -333,  -333,   314,  -333,
    -333,  -333,   661,  -333,  -333,   652,  -333,   314,   314,  -333,
     661,   168,  -333,   685,   135,  -333,   685,  -333,  -333,  -333,
     661,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    88,     0,
      89,     0,     0,     3,     0,     0,   316,     0,     0,     0,
      24,   242,   238,   240,     4,     0,   233,    82,    76,    94,
      91,   244,     0,     0,     0,   314,   220,   219,   221,   230,
     231,   232,     6,    13,     0,   134,   132,     5,    37,    42,
      43,    44,    45,    46,    47,    83,    84,    85,    87,    86,
      48,    99,   100,    49,    50,    51,    38,   127,   128,   129,
     130,   131,    74,   177,   178,   180,   183,   184,   197,   199,
     201,   203,   207,   211,     0,   218,   225,   234,   175,    58,
     133,    92,   126,   118,     0,   311,     0,     0,     0,   270,
      81,   124,     0,     0,     0,   122,     0,   116,   101,   111,
       0,     0,     0,    74,     0,   241,    74,   237,     0,   236,
     235,    74,     0,   239,   182,     0,    71,    74,    98,    90,
       0,     0,   153,   155,   313,    12,    15,    14,     0,   272,
       0,     0,   174,     0,     0,   191,   189,   190,   192,   188,
     186,   187,   195,   193,     0,     0,     0,     0,   205,   206,
       0,   210,   209,     0,   213,   214,   215,   216,     0,   217,
     223,   243,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    53,    56,     0,     0,     0,
     287,     9,   229,     0,     0,   284,    24,     0,   268,     0,
       0,     0,   315,   103,   120,     0,     0,     0,   250,     0,
       0,     0,     0,    31,    19,    22,     0,     0,    30,   274,
     279,   228,    30,   247,   226,     0,    30,   245,   227,    80,
      30,     0,    93,     0,   162,     0,     0,     0,     0,    40,
       0,   271,     0,   179,   181,   194,   196,   185,   198,   200,
     202,   204,   208,   212,     0,     0,   287,   262,   224,    58,
      55,    54,    52,   125,   119,     0,    10,     0,   312,   282,
     283,     0,    18,     0,     0,   267,    96,     0,     0,   105,
     109,   102,   115,   107,     0,   138,   117,   110,   249,    28,
      36,     0,    26,     0,    30,   276,     0,    29,   280,   248,
       0,   246,     0,    30,    72,    75,    96,     0,   157,     0,
     148,     0,   140,     0,     0,   154,    39,    41,    73,     0,
     253,   222,     0,     0,   259,     0,   257,     0,    57,     0,
       0,     0,   298,   285,    30,     0,    17,    16,   269,     0,
     123,     0,     0,     0,   113,   121,   136,    34,    32,     0,
      27,    21,    23,    20,    30,   273,   277,     0,     0,    78,
      29,    79,    97,   165,     0,   161,     0,     0,   150,     0,
       0,     0,   151,   152,   176,   251,     0,   252,   255,   262,
       8,   294,   289,     0,   295,   297,   286,   292,     0,    95,
     142,   106,   108,   112,     0,     0,    33,     0,    29,   278,
     308,    24,   302,   167,   171,   170,    77,   163,   164,   158,
     159,     0,   156,   144,     0,     0,   143,     0,   146,     0,
     258,   254,   261,   264,   291,   296,   281,     0,   114,     0,
       0,    35,    25,     0,     0,   307,   305,   306,     0,     0,
       0,   301,   299,   300,     0,    30,   160,   147,     0,   145,
     139,   256,   266,   260,   263,     0,   293,     0,     0,   135,
       0,   310,   173,     0,   304,   169,    29,   166,   149,   265,
       0,   288,   141,   137,   275,   309,   172,   303,   168,   290
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -333,  -333,  -333,  -333,  -333,   365,   139,  -333,  -333,   368,
    -333,  -186,  -333,  -333,  -333,  -333,  -196,  -205,  -333,  -333,
    -276,    -2,  -333,   164,  -333,   220,  -333,   149,  -333,  -333,
      93,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,   105,  -333,  -333,  -333,  -333,  -333,  -333,    17,
     215,   136,  -333,  -333,    15,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
     101,   103,  -333,  -333,  -185,  -333,  -333,  -333,  -332,  -333,
      -5,  -333,  -136,   284,    -6,  -333,  -333,    -7,   269,   276,
     277,  -333,   275,  -333,   288,  -333,   -69,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,    28,    57,  -333,  -333,   -12,  -333,    -8,  -333,
    -333,  -333,  -333,   404,  -333,  -333,  -333,  -333,  -333,  -333,
       2,  -333,    -4,   338,  -333,     5,  -102,  -333,  -333,   -10,
    -333
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    42,     3,    43,   265,    44,    45,    46,
     197,   111,   294,   112,   350,   214,   298,   215,   291,   347,
      47,   234,   138,    49,    50,   259,   185,   186,   187,    51,
     139,   126,   303,   304,    52,    53,    54,    55,    56,    57,
      58,    59,   340,   232,    60,    61,    62,   103,   281,   282,
     107,   283,   344,   108,   109,    63,   204,    64,    65,    66,
      67,   346,    68,    69,    70,   310,   368,   416,    71,   237,
     132,   311,   411,   412,   235,   364,   402,   445,   403,   404,
      72,   142,    73,    74,    75,    76,   154,    77,    78,    79,
      80,   160,    81,   163,    82,   168,    83,    84,    85,   170,
      86,   117,   118,   122,   114,    87,   123,   119,    88,   258,
     325,   378,   326,   327,   453,   454,   100,   198,    89,   115,
     354,   355,   219,    90,   271,   266,   267,   424,   456,   333,
     334,   384,   441,   442,   443,   435,   436,   437,    96,    91,
     104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    48,    95,   102,   242,    99,   290,   101,    99,   269,
     273,   220,   120,   106,   223,   169,   113,   116,   121,   124,
     285,    94,   129,   127,   128,   155,   299,   134,   131,   133,
     301,   363,     4,   194,   305,     5,     6,     7,   202,     8,
     -29,     9,   211,     6,    10,   383,    11,    12,     9,   217,
      93,   312,    13,    11,   278,    14,   195,    15,    16,    17,
      18,    19,   210,    20,    21,    22,    23,    24,    25,    26,
      97,    27,    28,    29,   -29,    30,   279,   319,   211,    31,
      32,    33,    34,    35,    36,    37,    38,   192,   408,   337,
     239,   213,   189,   193,   199,   216,   141,     7,   353,   253,
     212,   240,   461,   280,    93,   208,   462,   361,   464,   190,
     217,   191,   465,   409,    39,    40,    41,   110,   207,   203,
     229,   143,   410,     7,    21,    22,    23,   213,   372,    26,
     140,   476,   189,   367,   478,   330,   308,   244,   387,    31,
     141,    98,   254,   255,    36,    37,    38,   247,   105,    20,
      21,    22,    23,   130,    25,    26,   390,   155,   399,   256,
     257,   156,   261,   225,   260,    31,   440,   308,   157,   309,
      36,    37,    38,   331,    39,    40,    41,   261,   171,   260,
     188,   413,   196,   263,   200,   418,   321,   270,   268,   158,
     159,   431,   277,   356,   276,   217,   217,   205,   434,   434,
      39,    40,    41,   426,   288,   296,   218,   201,   141,   222,
      99,   295,     7,   300,   226,   439,   206,  -262,    99,   209,
     230,   400,   405,   323,   161,   162,   306,   313,   314,   447,
     385,   315,   449,   221,   450,   228,   318,   217,    20,    21,
      22,    23,   224,    25,    26,   459,   144,   394,   395,   467,
     225,   231,   324,   236,    31,   164,   165,   166,   167,    36,
      37,    38,   332,   468,   238,   241,   246,   245,   338,   274,
     264,   -11,   472,   473,   275,   272,  -104,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   189,   284,   351,    39,
      40,    41,   318,   287,   293,   289,   292,   359,   405,   297,
     302,   307,   405,   365,   405,    48,   320,   172,   405,   133,
     329,   335,   336,   339,   374,   341,   280,   343,   345,   348,
       5,   349,     7,   352,     8,   381,   382,   405,   357,    10,
     405,   358,    12,   360,   389,   366,   370,   371,   375,   376,
      14,  -261,   377,    16,    17,   379,    19,   386,    20,    21,
      22,    23,   233,    25,    26,   406,    27,    28,    29,   380,
      30,   388,    48,   391,    31,   392,   393,   396,    35,    36,
      37,    38,   398,   414,   422,   397,   415,   417,   425,   419,
     420,   421,   -29,   430,   438,   427,   172,   444,   432,   429,
     448,     7,   141,   433,   452,   322,   455,   457,   458,    39,
      40,    41,   460,   463,   317,   466,   446,   262,   328,   135,
     428,   362,   136,   369,   342,   373,   324,    20,    21,    22,
      23,   286,    25,    26,   248,   243,   173,   174,   175,   176,
     177,   178,   249,    31,   250,   251,   423,    35,    36,    37,
      38,   179,   180,   181,   182,   183,   184,   469,   137,   451,
     332,   252,     5,     6,     7,   474,     8,   471,     9,   227,
     477,    10,   407,    11,    12,   479,   475,     0,    39,    40,
      41,     0,    14,     0,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,     0,    25,    26,     0,    27,    28,
      29,     0,    30,     0,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     0,     8,     0,
       9,     0,     0,    10,     0,    11,    12,     0,     0,     0,
       0,    39,    40,    41,    14,     0,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,     0,    25,    26,     0,
      27,    28,    29,     0,    30,     0,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     7,     0,
       8,     0,     0,     0,     0,    10,     0,     0,    12,     0,
       0,     0,     0,    39,    40,    41,    14,     0,     0,    16,
      17,     0,    19,     7,    20,    21,    22,    23,   316,    25,
      26,     0,    27,    28,    29,     0,    30,     0,     0,     0,
      31,     0,     0,     0,    35,    36,    37,    38,     0,    20,
      21,    22,    23,     0,    25,    26,     7,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,   323,     0,     0,
      36,    37,    38,     0,     0,    39,    40,    41,   125,     0,
       7,     0,    20,    21,    22,    23,     0,    25,    26,     7,
       0,     0,   470,     0,     0,     0,     0,     0,    31,     0,
      39,    40,    41,    36,    37,    38,    20,    21,    22,    23,
       0,    25,    26,     7,     0,    20,    21,    22,    23,     0,
      25,    26,    31,     0,     0,     0,     0,    36,    37,    38,
       0,    31,     0,    39,    40,    41,    36,    37,    38,   401,
      21,    22,    23,     0,    25,    26,     7,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,    39,    40,    41,
      36,    37,    38,     0,     0,     0,    39,    40,    41,     0,
       0,     0,     0,    21,    22,    23,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      39,    40,    41,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,    15,   140,    12,   211,    14,    15,   194,
     196,   113,    22,    18,   116,    84,    21,    22,    23,    25,
     205,     6,    30,    28,    29,     9,   222,    35,    33,    34,
     226,   307,     0,    13,   230,     6,     7,     8,    19,    10,
      13,    12,    36,     7,    15,    24,    17,    18,    12,    28,
      85,   236,    23,    17,    36,    26,    36,    28,    29,    30,
      31,    32,    20,    34,    35,    36,    37,    38,    39,    40,
      85,    42,    43,    44,    47,    46,    58,    22,    36,    50,
      51,    52,    53,    54,    55,    56,    57,     8,   364,   274,
      38,    85,    19,    14,    78,    13,    41,     8,   294,   168,
      58,    49,   434,    85,    85,   110,   438,   303,   440,    36,
      28,    38,   444,     5,    85,    86,    87,    13,     5,   104,
     125,     4,    14,     8,    35,    36,    37,    85,   313,    40,
      31,   463,    19,    22,   466,    20,    25,   143,   334,    50,
      41,    85,    19,    20,    55,    56,    57,   154,    85,    34,
      35,    36,    37,    13,    39,    40,   341,     9,   354,    36,
      37,    11,   172,    28,   172,    50,    31,    25,     3,    27,
      55,    56,    57,    58,    85,    86,    87,   187,    50,   187,
      14,   366,    36,   188,    78,   370,   255,   195,   193,    62,
      63,   396,   200,   295,   199,    28,    28,    13,    31,    31,
      85,    86,    87,   388,   209,   217,   113,    32,    41,   116,
     217,   216,     8,   225,   121,   401,    14,    13,   225,    13,
     127,   357,   358,    19,    55,    56,   231,    13,    14,   414,
     332,   238,   417,    45,   419,    48,   241,    28,    34,    35,
      36,    37,    47,    39,    40,   430,    39,    21,    22,   445,
      28,    14,   257,    13,    50,    58,    59,    60,    61,    55,
      56,    57,   267,   448,     5,    14,    39,    78,   275,    13,
      85,    47,   457,   458,    14,    47,    32,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    19,    14,   293,    85,
      86,    87,   297,    85,    24,    85,    85,   302,   434,    14,
      14,    33,   438,   308,   440,   307,    85,    24,   444,   314,
      47,    47,    47,    14,   319,    13,    85,     5,    85,    47,
       6,    14,     8,    14,    10,   330,   331,   463,    78,    15,
     466,    78,    18,    14,   339,    13,    13,    22,    47,    19,
      26,    13,    48,    29,    30,    13,    32,    14,    34,    35,
      36,    37,    38,    39,    40,   360,    42,    43,    44,    38,
      46,    13,   364,    47,    50,    85,    14,    14,    54,    55,
      56,    57,    14,    13,   379,    20,    27,    13,   383,    13,
      19,    14,    47,    13,    13,    22,    24,    14,    85,   394,
      13,     8,    41,   398,    13,   256,    14,    13,    13,    85,
      86,    87,    13,    13,   240,    14,   411,   187,   259,    44,
     393,   306,    44,   310,   278,   314,   421,    34,    35,    36,
      37,   206,    39,    40,   155,   141,    64,    65,    66,    67,
      68,    69,   156,    50,   157,   160,   379,    54,    55,    56,
      57,    79,    80,    81,    82,    83,    84,   452,    44,   421,
     455,   163,     6,     7,     8,   460,    10,   455,    12,   121,
     464,    15,    16,    17,    18,   470,   461,    -1,    85,    86,
      87,    -1,    26,    -1,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,    37,    -1,    39,    40,    -1,    42,    43,
      44,    -1,    46,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    15,    -1,    17,    18,    -1,    -1,    -1,
      -1,    85,    86,    87,    26,    -1,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    -1,    39,    40,    -1,
      42,    43,    44,    -1,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,     8,    -1,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    85,    86,    87,    26,    -1,    -1,    29,
      30,    -1,    32,     8,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    -1,    46,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    55,    56,    57,    -1,    34,
      35,    36,    37,    -1,    39,    40,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    19,    -1,    -1,
      55,    56,    57,    -1,    -1,    85,    86,    87,    63,    -1,
       8,    -1,    34,    35,    36,    37,    -1,    39,    40,     8,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      85,    86,    87,    55,    56,    57,    34,    35,    36,    37,
      -1,    39,    40,     8,    -1,    34,    35,    36,    37,    -1,
      39,    40,    50,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    50,    -1,    85,    86,    87,    55,    56,    57,    34,
      35,    36,    37,    -1,    39,    40,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    85,    86,    87,
      55,    56,    57,    -1,    -1,    -1,    85,    86,    87,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      85,    86,    87,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     6,     7,     8,    10,    12,
      15,    17,    18,    23,    26,    28,    29,    30,    31,    32,
      34,    35,    36,    37,    38,    39,    40,    42,    43,    44,
      46,    50,    51,    52,    53,    54,    55,    56,    57,    85,
      86,    87,    91,    93,    95,    96,    97,   108,   109,   111,
     112,   117,   122,   123,   124,   125,   126,   127,   128,   129,
     132,   133,   134,   143,   145,   146,   147,   148,   150,   151,
     152,   156,   168,   170,   171,   172,   173,   175,   176,   177,
     178,   180,   182,   184,   185,   186,   188,   193,   196,   206,
     211,   227,   168,    85,   142,   168,   226,    85,    85,   175,
     204,   175,   204,   135,   228,    85,   168,   138,   141,   142,
      13,    99,   101,   168,   192,   207,   168,   189,   190,   195,
     227,   168,   191,   194,   172,    63,   119,   168,   168,   206,
      13,   168,   158,   168,   206,    93,    97,   211,   110,   118,
      31,    41,   169,     4,    39,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   174,     9,    11,     3,    62,    63,
     179,    55,    56,   181,    58,    59,    60,    61,   183,   184,
     187,    50,    24,    64,    65,    66,    67,    68,    69,    79,
      80,    81,    82,    83,    84,   114,   115,   116,    14,    19,
      36,    38,     8,    14,    13,    36,    36,    98,   205,    78,
      78,    32,    19,   142,   144,    13,    14,     5,   168,    13,
      20,    36,    58,    85,   103,   105,    13,    28,   118,   210,
     224,    45,   118,   224,    47,    28,   118,   221,    48,   168,
     118,    14,   131,    38,   109,   162,    13,   157,     5,    38,
      49,    14,   170,   171,   172,    78,    39,   175,   176,   177,
     178,   180,   182,   184,    19,    20,    36,    37,   197,   113,
     206,   227,   113,   168,    85,    94,   213,   214,   168,   162,
     206,   212,    47,    99,    13,    14,   168,   206,    36,    58,
      85,   136,   137,   139,    14,   162,   138,    85,   168,    85,
     105,   106,    85,    24,   100,   168,   204,    14,   104,   104,
     204,   104,    14,   120,   121,   104,   168,    33,    25,    27,
     153,   159,   162,    13,    14,   175,    38,   111,   168,    22,
      85,   184,    94,    19,   168,   198,   200,   201,   115,    47,
      20,    58,   168,   217,   218,    47,    47,   162,   175,    14,
     130,    13,   139,     5,   140,    85,   149,   107,    47,    14,
     102,   168,    14,   104,   208,   209,   224,    78,    78,   168,
      14,   104,   130,   108,   163,   168,    13,    22,   154,   159,
      13,    22,   162,   158,   168,    47,    19,    48,   199,    13,
      38,   168,   168,    24,   219,   224,    14,   104,    13,   168,
     162,    47,    85,    14,    21,    22,    14,    20,    14,   104,
     170,    34,   164,   166,   167,   170,   168,    16,   108,     5,
      14,   160,   161,   162,    13,    27,   155,    13,   162,    13,
      19,    14,   168,   201,   215,   168,   162,    22,   137,   168,
      13,   105,    85,   168,    31,   223,   224,   225,    13,    99,
      31,   220,   221,   222,    14,   165,   168,   162,    13,   162,
     162,   200,    13,   202,   203,    14,   216,    13,    13,   162,
      13,   166,   166,    13,   166,   166,    14,   104,   162,   168,
      20,   218,   162,   162,   168,   223,   166,   220,   166,   168
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   124,   124,   124,   124,   124,   125,   126,
     127,   127,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   134,   135,   135,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   175,   176,
     176,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     181,   182,   182,   183,   183,   183,   183,   184,   184,   185,
     185,   185,   186,   186,   187,   187,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   197,   197,   197,   198,   198,   199,   199,   200,   200,
     200,   201,   201,   202,   202,   203,   203,   204,   204,   205,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   212,   213,   214,   214,   215,   215,
     216,   216,   217,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   226,   226,   227,   227,   228,   228
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     5,     3,     2,     2,
       4,     2,     0,     4,     0,     3,     0,     3,     2,     1,
       0,     1,     3,     3,     2,     3,     0,     1,     1,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     0,     3,     0,     3,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     2,     0,     3,     0,     1,
       1,     2,     4,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     3,     0,     1,     3,     1,     3,
       3,     3,     0,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     4,     2,     1,     3,     1,     3,     2,
       1,     1,     4,     3,     2,     1,     4,     0,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     0,     2,     1,     2,     3,     2,     3,     4,
       3,     3,     3,     2,     3,     2,     3,     0,     3,     1,
       4,     1,     0,     1,     0,     2,     1,     3,     2,     3,
       0,     3,     2,     4,     2,     5,     0,     1,     2,     1,
       2,     7,     4,     1,     0,     2,     3,     0,     3,     0,
       3,     0,     2,     4,     2,     2,     3,     1,     0,     1,
       1,     5,     4,     3,     2,     1,     1,     5,     4,     3,
       2,     1,     3,     2,     1,     2,     0
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
#line 77 "parse.y" /* yacc.c:1646  */
    {
	  //$1->eval();
	}
#line 1899 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "parse.y" /* yacc.c:1646  */
    {
    // SHALL NOT DO ANYTHING!!!
	}
#line 1907 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;//std::cout<< "the newline"<<std::endl;}
}
#line 1914 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "parse.y" /* yacc.c:1646  */
    {
      //std::cout<< "the eval()"<<std::endl;
      (yyvsp[0].node)->eval();
      //catch(std::string str)
        // { std::cout<< <<std::endl;}
    }
#line 1925 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "parse.y" /* yacc.c:1646  */
    { //if ($2!=nullptr)
	  //(*(dynamic_cast<SuiteNode*>(mainsuite)->returnASTTab())).push_back($2);
	  {(yyval.node)=(yyvsp[0].node);}
	}
#line 1934 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 1940 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 124 "parse.y" /* yacc.c:1646  */
    {
          (yyval.node)=new FuncDefNode((yyvsp[-3].id),dynamic_cast<SuiteNode*>((yyvsp[0].node)));
          pool.add((yyval.node));
          delete [] (yyvsp[-3].id);
	  //std::cout<<"in parse.y function ast build"<<std::endl;
	  
	  //add parameter into symboltable {std::cout<<"function ast build start"<<std::endl;} 
	  // funcNode astpointer point at ast of suit ast;{suit will call symboltable creat the symboltable.} 
	  //funcNode symboltable pointer point at symboltable manager  
	}
#line 1955 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 176 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1961 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 177 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1967 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 181 "parse.y" /* yacc.c:1646  */
    {
           (yyval.node)=(yyvsp[-3].node);

          }
#line 1976 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 186 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-2].node);

          }
#line 1984 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 192 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1990 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 193 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 1996 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 196 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2002 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 197 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2008 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 198 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2014 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 199 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2020 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 200 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2026 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 201 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2032 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 202 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2038 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 203 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2044 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 204 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2050 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 208 "parse.y" /* yacc.c:1646  */
    {// do augassign to $1.
            //int x=$2;
	    switch((yyvsp[-1].intNumber))
		{
                  case(PLUSEQUAL):   
				  {Node* temp = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node)); } 
                    break;//$1 is a variable check if it was declared.

                  case(MINEQUAL): 
{Node* temp = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));  pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break;
                  case(STAREQUAL):   
{Node* temp = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));  pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break;
                  case(SLASHEQUAL): 
{Node* temp = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));  pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break;
                  case(PERCENTEQUAL):
{Node* temp = new PercentBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break;
                  case(AMPEREQUAL):
{Node* temp= new AMPERSANDNode((yyvsp[-2].node), (yyvsp[0].node)); pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));}   
                    break;
                  case(VBAREQUAL):
{Node* temp= new BarNode((yyvsp[-2].node), (yyvsp[0].node)); pool.add(temp);(yyvsp[-2].node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));}   
                    break;
                  case(CIRCUMFLEXEQUAL): 
{Node* temp= new CIRCUMFLEXNode((yyvsp[-2].node), (yyvsp[0].node)); pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));}   
                    break;
                  case(LEFTSHIFTEQUAL):  
{Node* temp= new LeftShiftNode((yyvsp[-2].node), (yyvsp[0].node)); pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));}   
                    break;
                  case(RIGHTSHIFTEQUAL): 
{Node* temp= new RightShiftNode((yyvsp[-2].node), (yyvsp[0].node)); pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break;
                  case(DOUBLESTAREQUAL): 
{Node* temp= new PowerBinaryNode((yyvsp[-2].node), (yyvsp[0].node));pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break; 
                  case(DOUBLESLASHEQUAL):
{Node* temp = new DoubleSlaBinaryNode((yyvsp[-2].node), (yyvsp[0].node));pool.add(temp);(yyval.node)=new AsgBinaryNode((yyvsp[-2].node), temp); pool.add((yyval.node));} 
                    break;
		
		  default:break;
		}

          }
#line 2101 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 255 "parse.y" /* yacc.c:1646  */
    { // assign the value for left testlist
            if ((yyvsp[0].node)!=nullptr)         
            {
             (yyval.node)= new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
             //($1)->eval()->print();
             pool.add((yyval.node));}
            else
            {(yyval.node)=(yyvsp[-1].node);//if($1){($1)->eval()->print();}
            //else{std::cout<<"NameError: name \'"<<dynamic_cast<IdentNode*>$1->getIdent()<<"\' is not defined"<<std::endl; }
			}
          }
#line 2117 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 271 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2123 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 275 "parse.y" /* yacc.c:1646  */
    {
           /* //Node* lhs = new IdentNode($1); 
            if($1==NULL)
                { $$=$3;}
            else
            {   
            const_cast<Node*>(dynamic_cast<AsgBinaryNode*>($1)->getRight())=new AsgBinaryNode(const_cast<Node*>(dynamic_cast<AsgBinaryNode*>($1)->getRight()), $3);
            $$=$1;
            }*/
      (yyval.node)=(yyvsp[0].node);
          }
#line 2139 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 290 "parse.y" /* yacc.c:1646  */
    {
          if((yyvsp[0].node)!=nullptr)
		{(yyval.node)=new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
                pool.add((yyval.node));}
	  else
            (yyval.node)=(yyvsp[-1].node);
	}
#line 2151 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 298 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;
	 }
#line 2158 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=PLUSEQUAL;}
#line 2164 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 304 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=MINEQUAL;}
#line 2170 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 305 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=STAREQUAL;}
#line 2176 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 306 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=SLASHEQUAL;}
#line 2182 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 307 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=PERCENTEQUAL;}
#line 2188 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 308 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=AMPEREQUAL;}
#line 2194 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 309 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=VBAREQUAL;}
#line 2200 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 310 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=CIRCUMFLEXEQUAL;}
#line 2206 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 311 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=LEFTSHIFTEQUAL;}
#line 2212 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 312 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=RIGHTSHIFTEQUAL;}
#line 2218 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 313 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=DOUBLESTAREQUAL;}
#line 2224 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 314 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=DOUBLESLASHEQUAL;}
#line 2230 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 318 "parse.y" /* yacc.c:1646  */
    {//$$=$2;//$2->eval()->print();
	  (yyval.node)=new PrintNode((yyvsp[0].vectorNode));
          pool.add((yyval.node));
	}
#line 2239 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 322 "parse.y" /* yacc.c:1646  */
    { (yyval.node)=nullptr;}
#line 2245 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 326 "parse.y" /* yacc.c:1646  */
    {
      if((yyvsp[-2].vectorNode)) {
        (yyvsp[-2].vectorNode) -> push_back((yyvsp[0].node));
      }
      else {
        (yyval.vectorNode) = new std::vector<Node*>();
        (yyval.vectorNode) -> push_back((yyvsp[0].node));
      }
    }
#line 2259 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 335 "parse.y" /* yacc.c:1646  */
    {(yyval.vectorNode)=nullptr;}
#line 2265 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 339 "parse.y" /* yacc.c:1646  */
    {
      if((yyvsp[-1].vectorNode)) {
        (yyvsp[-1].vectorNode) -> insert((yyvsp[-1].vectorNode)->begin(), (yyvsp[-2].node));
        (yyval.vectorNode) = (yyvsp[-1].vectorNode);
      }
      else {
        (yyval.vectorNode) = new std::vector<Node*>();
        (yyval.vectorNode) -> push_back((yyvsp[-2].node));
      }
    }
#line 2280 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 349 "parse.y" /* yacc.c:1646  */
    {(yyval.vectorNode)=nullptr;}
#line 2286 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 366 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2292 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 367 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2298 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 368 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2304 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 369 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2310 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 370 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2316 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 380 "parse.y" /* yacc.c:1646  */
    {
           (yyval.node)=new ReturnNode((yyvsp[0].node));
           std::cout<<"creat ruturn node"<<std::endl;
           pool.add((yyval.node));
        }
#line 2326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 386 "parse.y" /* yacc.c:1646  */
    {
           NONELiteral* none = new NONELiteral();
           pool.add(none);
           (yyval.node)=new ReturnNode(none);
           pool.add((yyval.node));
        }
#line 2337 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 467 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2343 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 468 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2349 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 469 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2355 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 470 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2361 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 471 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2367 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 472 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2373 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 473 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2379 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 474 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2385 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 478 "parse.y" /* yacc.c:1646  */
    {
           (yyval.node)=new IfNode((yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[0].node));
           pool.add((yyval.node));
        }
#line 2394 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 483 "parse.y" /* yacc.c:1646  */
    {
           (yyval.node)=new IfNode((yyvsp[-3].node),(yyvsp[-1].node));
           pool.add((yyval.node));
        }
#line 2403 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 541 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.node)= new SuiteNode((yyvsp[0].node));
          pool.add((yyval.node));
	}
#line 2412 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 546 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.node)= new SuiteNode((yyvsp[-1].vectorNode));
    delete (yyvsp[-1].vectorNode);
          pool.add((yyval.node));
	}
#line 2422 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 554 "parse.y" /* yacc.c:1646  */
    {
	      (yyval.vectorNode) = (yyvsp[-1].vectorNode);
	      (yyval.vectorNode) -> push_back((yyvsp[0].node));
	    }
#line 2431 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 559 "parse.y" /* yacc.c:1646  */
    {
	  (yyval.vectorNode) = new std::vector<Node*>(); (yyval.vectorNode) -> push_back((yyvsp[0].node)); 
          // have a try if we need pool.add($$);
	}
#line 2440 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 582 "parse.y" /* yacc.c:1646  */
    { 
          (yyval.node)=(yyvsp[-1].node);//I just have the or_test part.
          }
#line 2448 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 586 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;//do nothing with lambdef
        }
#line 2455 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 591 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);//I don't know this kind of grammer so I haven't deal with this kind of grammer 
        }
#line 2462 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 593 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;}
#line 2468 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 596 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2474 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 600 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2480 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 604 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;/*do nothing with not*/}
#line 2486 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 605 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2492 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 608 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2498 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 610 "parse.y" /* yacc.c:1646  */
    {
           switch ((yyvsp[-1].intNumber))
		   {
		      case (LESS):
			  {(yyval.node)= new LesserBinaryNode((yyvsp[-2].node),(yyvsp[0].node)); pool.add((yyval.node));break;}
			  case (GREATER):
			  {(yyval.node)= new BiggerBinaryNode((yyvsp[-2].node),(yyvsp[0].node));pool.add((yyval.node));break;}
			  case (EQEQUAL):
			  {(yyval.node)= new EqEqBinaryNode((yyvsp[-2].node),(yyvsp[0].node));pool.add((yyval.node));break;}
			  case (GREATEREQUAL):
			  {(yyval.node)= new BgEqBinaryNode((yyvsp[-2].node),(yyvsp[0].node));pool.add((yyval.node));break;}
			  case (LESSEQUAL):
			  {(yyval.node)= new LsEqBinaryNode((yyvsp[-2].node),(yyvsp[0].node));pool.add((yyval.node));break;} 
			  default:{(yyval.node)=nullptr;break;}
		   }
	      
          }
#line 2520 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 629 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=LESS; }
#line 2526 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 630 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=GREATER; }
#line 2532 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 631 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= EQEQUAL; }
#line 2538 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 632 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= GREATEREQUAL; }
#line 2544 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 633 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= LESSEQUAL; }
#line 2550 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 634 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= GRLT; }
#line 2556 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 635 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= NOTEQUAL; }
#line 2562 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 636 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= IN ; }
#line 2568 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 637 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= IN; }
#line 2574 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 638 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= IS; }
#line 2580 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 639 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= IS; }
#line 2586 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 642 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2592 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 644 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = new BarNode((yyvsp[-2].node), (yyvsp[0].node)); 
          //std::cout<<"|called"<<std::endl;
                             pool.add((yyval.node));}
#line 2600 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 649 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2606 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 651 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = new CIRCUMFLEXNode((yyvsp[-2].node), (yyvsp[0].node)); 
          //std::cout<<"^called"<<std::endl;
                             pool.add((yyval.node));}
#line 2614 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 656 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2620 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 658 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = new AMPERSANDNode((yyvsp[-2].node), (yyvsp[0].node)); 
           //std::cout<<"&called"<<std::endl;
                             pool.add((yyval.node));}
#line 2628 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 663 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2634 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 665 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].intNumber)==LEFTSHIFT)
            {(yyval.node) = new LeftShiftNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node));}
            else 
            {
               if ((yyvsp[-1].intNumber)==RIGHTSHIFT)
               {(yyval.node) = new RightShiftNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node));}
   
             } 
          }
#line 2651 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 680 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=LEFTSHIFT;}
#line 2657 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 681 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=RIGHTSHIFT;}
#line 2663 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 684 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2669 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 686 "parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].intNumber)==PLUS)
            {(yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node));}
            else 
            {
               if ((yyvsp[-1].intNumber)==MINUS)
               {(yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node));}
   
             } 
          }
#line 2686 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 700 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=PLUS;}
#line 2692 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 701 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=MINUS;}
#line 2698 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 704 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2704 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 706 "parse.y" /* yacc.c:1646  */
    {
           if((yyvsp[-1].intNumber)==STAR)
             { (yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node));}
           if((yyvsp[-1].intNumber)==SLASH)
             {(yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node)); 
             }

           if((yyvsp[-1].intNumber)==DOUBLESLASH)
             {(yyval.node) = new DoubleSlaBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node)); 
             }

           if((yyvsp[-1].intNumber)==PERCENT)
             {(yyval.node) = new PercentBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
                             pool.add((yyval.node)); 
             }           

          }
#line 2729 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 728 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= STAR;}
#line 2735 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 729 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= SLASH;}
#line 2741 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 730 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= PERCENT;}
#line 2747 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 731 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= DOUBLESLASH;}
#line 2753 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 735 "parse.y" /* yacc.c:1646  */
    {//0+-x
            if ((yyvsp[-1].intNumber)==PLUS)
            {(yyval.node)=(yyvsp[0].node);}
            else 
            { if((yyvsp[-1].intNumber)==MINUS)
              {IntLiteral* temp0=new IntLiteral(0);
              (yyval.node) = new SubBinaryNode(temp0, (yyvsp[0].node)); 
              pool.add((yyval.node));
              pool.add(temp0);}
              else
              {(yyval.node)= new TildeUnaryNode((yyvsp[0].node));pool.add((yyval.node));}
   
             } 
          }
#line 2772 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 749 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2778 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 753 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber) = PLUS;}
#line 2784 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 754 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)= MINUS;}
#line 2790 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 755 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=TILDE;}
#line 2796 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 759 "parse.y" /* yacc.c:1646  */
    {// left the a[1][2]**4
           (yyval.node) = new PowerBinaryNode((yyvsp[-3].node), (yyvsp[0].node)); 
           pool.add((yyval.node));
          }
#line 2805 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 764 "parse.y" /* yacc.c:1646  */
    {//$$=$1; 
      if((yyvsp[0].intNumber)){
			  (yyval.node)=new FuncCallNode(static_cast<IdentNode*>((yyvsp[-1].node)) -> getIdent());
                          std::cout<<"new a functon call node"<<std::endl;
			  pool.add((yyval.node));
      }  
    }
#line 2817 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 773 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=(yyvsp[0].intNumber);}
#line 2823 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 775 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=0;}
#line 2829 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 778 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2835 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 779 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2841 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 780 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2847 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 781 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2853 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 782 "parse.y" /* yacc.c:1646  */
    {  std::string tempb=(yyvsp[0].id);
                 if(tempb=="True")
                    {
                      (yyval.node) = new BoolLiteral(1);         
                      delete [] (yyvsp[0].id);
                      pool.add((yyval.node));
                    }
                 else 
                   if(tempb=="False")
                    {
                      (yyval.node) = new BoolLiteral(0);         
                      delete [] (yyvsp[0].id);
                      pool.add((yyval.node));
                    }
                   else
                    {
                    (yyval.node) = new IdentNode((yyvsp[0].id));         
                     delete [] (yyvsp[0].id);
                     pool.add((yyval.node));
                     //std::cout<<"variable"<<std::endl;
                    }
              }
#line 2880 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 804 "parse.y" /* yacc.c:1646  */
    {
               (yyval.node) = new IntLiteral((yyvsp[0].intNumber));        
               pool.add((yyval.node));
             }
#line 2889 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 808 "parse.y" /* yacc.c:1646  */
    {
               (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));        
               pool.add((yyval.node));
               }
#line 2898 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 812 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=nullptr;/*do nothing with other number*/}
#line 2904 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 813 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2910 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 816 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2916 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 817 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2922 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 820 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2928 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 821 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2934 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 841 "parse.y" /* yacc.c:1646  */
    {//leave the comp, just keep test in() 
           (yyval.node)=(yyvsp[-1].node);
          }
#line 2942 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 845 "parse.y" /* yacc.c:1646  */
    {//leave the (a,b,c), just keep test in() 
           (yyval.node)=(yyvsp[-2].node);
          }
#line 2950 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 854 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=1;}
#line 2956 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 855 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=1;}
#line 2962 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 856 "parse.y" /* yacc.c:1646  */
    {(yyval.intNumber)=1;}
#line 2968 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 885 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node);}
#line 2974 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 887 "parse.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2980 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 894 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-2].node);}
#line 2986 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 895 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2992 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 978 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2998 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 979 "parse.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 3004 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3008 "parse.tab.c" /* yacc.c:1646  */
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
#line 986 "parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}

