/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 23 "parse.y" /* yacc.c:1909  */

  Node* node;
  int intNumber;
  long double fltNumber;
  char *id;
  std::vector<Node*>* vectorNode;

#line 150 "parse.tab.h" /* yacc.c:1909  */
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
