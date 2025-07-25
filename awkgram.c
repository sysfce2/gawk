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
#line 26 "awkgram.y"

#ifdef GAWKDEBUG
#define YYDEBUG 12
#endif

#include "awk.h"

#if defined(__STDC__) && __STDC__ < 1	/* VMS weirdness, maybe elsewhere */
#define signed /**/
#endif

static void yyerror(const char *m, ...) ATTRIBUTE_PRINTF_1;
#define  YYERROR_IS_DECLARED	1	/* for bison 3.8. sigh. */
static void error_ln(int line, const char *m, ...) ATTRIBUTE_PRINTF_2;
static void lintwarn_ln(int line, const char *m, ...) ATTRIBUTE_PRINTF_2;
static void warning_ln(int line, const char *m, ...) ATTRIBUTE_PRINTF_2;
static char *get_src_buf(void);
static int yylex(void);
int	yyparse(void);
static INSTRUCTION *snode(INSTRUCTION *subn, INSTRUCTION *op);
static char **check_params(char *fname, int pcount, INSTRUCTION *list);
static int install_function(char *fname, INSTRUCTION *fi, INSTRUCTION *plist);
static NODE *mk_rexp(INSTRUCTION *exp);
static void param_sanity(INSTRUCTION *arglist);
static int parms_shadow(INSTRUCTION *pc, bool *shadow);
#ifndef NO_LINT
static int isnoeffect(OPCODE type);
#endif
static INSTRUCTION *make_assignable(INSTRUCTION *ip);
static void dumpintlstr(const char *str, size_t len);
static void dumpintlstr2(const char *str1, size_t len1, const char *str2, size_t len2);
static bool include_source(INSTRUCTION *file, void **srcfile_p);
static bool load_library(INSTRUCTION *file, void **srcfile_p);
static void set_namespace(INSTRUCTION *ns, INSTRUCTION *comment);
static void change_namespace(const char *new_namespace);
static void next_sourcefile(void);
static char *tokexpand(void);
static NODE *set_profile_text(NODE *n, const char *str, size_t len);
static int check_qualified_special(char *token);
static char *qualify_name(const char *name, size_t len);
static void push_ns_onto_namespace_chain(INSTRUCTION *comment);
static INSTRUCTION *trailing_comment;
static INSTRUCTION *outer_comment;
static INSTRUCTION *interblock_comment;
static INSTRUCTION *pending_comment;
static INSTRUCTION *namespace_chain;

#ifdef DEBUG_COMMENTS
static void
debug_print_comment_s(const char *name, INSTRUCTION *comment, int line)
{
	if (comment != NULL)
		fprintf(stderr, "%d: %s: <%.*s>\n", line, name,
				(int) (comment->memory->stlen - 1),
				comment->memory->stptr);
}
#define debug_print_comment(comment) \
	 debug_print_comment_s(# comment, comment, __LINE__)
#endif

#define instruction(t)	bcalloc(t, 1, 0)

static INSTRUCTION *mk_program(void);
static INSTRUCTION *append_rule(INSTRUCTION *pattern, INSTRUCTION *action);
static INSTRUCTION *mk_function(INSTRUCTION *fi, INSTRUCTION *def);
static INSTRUCTION *mk_condition(INSTRUCTION *cond, INSTRUCTION *ifp, INSTRUCTION *true_branch,
		INSTRUCTION *elsep,	INSTRUCTION *false_branch);
static INSTRUCTION *mk_expression_list(INSTRUCTION *list, INSTRUCTION *s1);
static INSTRUCTION *mk_for_loop(INSTRUCTION *forp, INSTRUCTION *init, INSTRUCTION *cond,
		INSTRUCTION *incr, INSTRUCTION *body);
static void fix_break_continue(INSTRUCTION *list, INSTRUCTION *b_target, INSTRUCTION *c_target);
static INSTRUCTION *mk_binary(INSTRUCTION *s1, INSTRUCTION *s2, INSTRUCTION *op);
static INSTRUCTION *mk_boolean(INSTRUCTION *left, INSTRUCTION *right, INSTRUCTION *op);
static INSTRUCTION *mk_assignment(INSTRUCTION *lhs, INSTRUCTION *rhs, INSTRUCTION *op);
static INSTRUCTION *mk_getline(INSTRUCTION *op, INSTRUCTION *opt_var, INSTRUCTION *redir, int redirtype);
static int count_expressions(INSTRUCTION **list, bool isarg);
static INSTRUCTION *optimize_assignment(INSTRUCTION *exp);
static void add_lint(INSTRUCTION *list, LINTTYPE linttype);

enum defref { FUNC_DEFINE, FUNC_USE, FUNC_EXT };
static void func_use(const char *name, enum defref how);
static void check_funcs(void);

static ssize_t read_one_line(int fd, void *buffer, size_t count);
static int one_line_close(int fd);
static void merge_comments(INSTRUCTION *c1, INSTRUCTION *c2);
static INSTRUCTION *make_braced_statements(INSTRUCTION *lbrace, INSTRUCTION *stmts, INSTRUCTION *rbrace);
static void add_sign_to_num(NODE *n, char sign);

static int at_seen = 0;
static bool want_source = false;
static bool want_namespace = false;
static bool want_regexp = false;	/* lexical scanning kludge */
static enum {
	FUNC_HEADER,
	FUNC_BODY,
	DONT_CHECK
} want_param_names = DONT_CHECK;	/* ditto */
static bool in_function;		/* parsing kludge */
static int rule = 0;

const char *const ruletab[] = {
	"?",
	"BEGIN",
	"Rule",
	"END",
	"BEGINFILE",
	"ENDFILE",
};

static bool in_print = false;	/* lexical scanning kludge for print */
static int in_parens = 0;	/* lexical scanning kludge for print */
static int sub_counter = 0;	/* array dimension counter for use in delete */
static char *lexptr;		/* pointer to next char during parsing */
static char *lexend;		/* end of buffer */
static char *lexptr_begin;	/* keep track of where we were for error msgs */
static char *lexeme;		/* beginning of lexeme for debugging */
static bool lexeof;		/* seen EOF for current source? */
static char *thisline = NULL;
static int in_braces = 0;	/* count braces for firstline, lastline in an 'action' */
static int lastline = 0;
static int firstline = 0;
static SRCFILE *sourcefile = NULL;	/* current program source */
static int lasttok = 0;
static bool eof_warned = false;	/* GLOBAL: want warning for each file */
static int break_allowed;	/* kludge for break */
static int continue_allowed;	/* kludge for continue */

#define END_FILE	-1000
#define END_SRC  	-2000

#define YYDEBUG_LEXER_TEXT (lexeme)
static char *tokstart = NULL;
static char *tok = NULL;
static char *tokend;
int errcount = 0;

extern char *source;
extern int sourceline;
extern SRCFILE *srcfiles;
extern INSTRUCTION *rule_list;
extern int max_args;
extern NODE **args_array;

const char awk_namespace[] = "awk";
const char *current_namespace = awk_namespace;
bool namespace_changed = false;

static INSTRUCTION *rule_block[sizeof(ruletab)/sizeof(ruletab[0])];

static INSTRUCTION *ip_rec;
static INSTRUCTION *ip_newfile;
static INSTRUCTION *ip_atexit = NULL;
static INSTRUCTION *ip_end;
static INSTRUCTION *ip_endfile;
static INSTRUCTION *ip_beginfile;
INSTRUCTION *main_beginfile;
static bool called_from_eval = false;

static bool include_use_current_namespace = false;

static inline INSTRUCTION *list_create(INSTRUCTION *x);
static inline INSTRUCTION *list_append(INSTRUCTION *l, INSTRUCTION *x);
static inline INSTRUCTION *list_prepend(INSTRUCTION *l, INSTRUCTION *x);
static inline INSTRUCTION *list_merge(INSTRUCTION *l1, INSTRUCTION *l2);

extern double fmod(double x, double y);

#define YYSTYPE INSTRUCTION *

#line 242 "awkgram.c"

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
    FUNC_CALL = 258,               /* FUNC_CALL  */
    NAME = 259,                    /* NAME  */
    REGEXP = 260,                  /* REGEXP  */
    FILENAME = 261,                /* FILENAME  */
    YNUMBER = 262,                 /* YNUMBER  */
    YSTRING = 263,                 /* YSTRING  */
    TYPED_REGEXP = 264,            /* TYPED_REGEXP  */
    RELOP = 265,                   /* RELOP  */
    IO_OUT = 266,                  /* IO_OUT  */
    IO_IN = 267,                   /* IO_IN  */
    ASSIGNOP = 268,                /* ASSIGNOP  */
    ASSIGN = 269,                  /* ASSIGN  */
    MATCHOP = 270,                 /* MATCHOP  */
    CONCAT_OP = 271,               /* CONCAT_OP  */
    SUBSCRIPT = 272,               /* SUBSCRIPT  */
    LEX_BEGIN = 273,               /* LEX_BEGIN  */
    LEX_END = 274,                 /* LEX_END  */
    LEX_IF = 275,                  /* LEX_IF  */
    LEX_ELSE = 276,                /* LEX_ELSE  */
    LEX_RETURN = 277,              /* LEX_RETURN  */
    LEX_DELETE = 278,              /* LEX_DELETE  */
    LEX_SWITCH = 279,              /* LEX_SWITCH  */
    LEX_CASE = 280,                /* LEX_CASE  */
    LEX_DEFAULT = 281,             /* LEX_DEFAULT  */
    LEX_WHILE = 282,               /* LEX_WHILE  */
    LEX_DO = 283,                  /* LEX_DO  */
    LEX_FOR = 284,                 /* LEX_FOR  */
    LEX_BREAK = 285,               /* LEX_BREAK  */
    LEX_CONTINUE = 286,            /* LEX_CONTINUE  */
    LEX_PRINT = 287,               /* LEX_PRINT  */
    LEX_PRINTF = 288,              /* LEX_PRINTF  */
    LEX_NEXT = 289,                /* LEX_NEXT  */
    LEX_EXIT = 290,                /* LEX_EXIT  */
    LEX_FUNCTION = 291,            /* LEX_FUNCTION  */
    LEX_BEGINFILE = 292,           /* LEX_BEGINFILE  */
    LEX_ENDFILE = 293,             /* LEX_ENDFILE  */
    LEX_GETLINE = 294,             /* LEX_GETLINE  */
    LEX_NEXTFILE = 295,            /* LEX_NEXTFILE  */
    LEX_IN = 296,                  /* LEX_IN  */
    LEX_AND = 297,                 /* LEX_AND  */
    LEX_OR = 298,                  /* LEX_OR  */
    INCREMENT = 299,               /* INCREMENT  */
    DECREMENT = 300,               /* DECREMENT  */
    LEX_BUILTIN = 301,             /* LEX_BUILTIN  */
    LEX_LENGTH = 302,              /* LEX_LENGTH  */
    LEX_EOF = 303,                 /* LEX_EOF  */
    LEX_INCLUDE = 304,             /* LEX_INCLUDE  */
    LEX_EVAL = 305,                /* LEX_EVAL  */
    LEX_LOAD = 306,                /* LEX_LOAD  */
    LEX_NAMESPACE = 307,           /* LEX_NAMESPACE  */
    LEX_NSINCLUDE = 308,           /* LEX_NSINCLUDE  */
    NEWLINE = 309,                 /* NEWLINE  */
    SLASH_BEFORE_EQUAL = 310,      /* SLASH_BEFORE_EQUAL  */
    UNARY = 311                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define FUNC_CALL 258
#define NAME 259
#define REGEXP 260
#define FILENAME 261
#define YNUMBER 262
#define YSTRING 263
#define TYPED_REGEXP 264
#define RELOP 265
#define IO_OUT 266
#define IO_IN 267
#define ASSIGNOP 268
#define ASSIGN 269
#define MATCHOP 270
#define CONCAT_OP 271
#define SUBSCRIPT 272
#define LEX_BEGIN 273
#define LEX_END 274
#define LEX_IF 275
#define LEX_ELSE 276
#define LEX_RETURN 277
#define LEX_DELETE 278
#define LEX_SWITCH 279
#define LEX_CASE 280
#define LEX_DEFAULT 281
#define LEX_WHILE 282
#define LEX_DO 283
#define LEX_FOR 284
#define LEX_BREAK 285
#define LEX_CONTINUE 286
#define LEX_PRINT 287
#define LEX_PRINTF 288
#define LEX_NEXT 289
#define LEX_EXIT 290
#define LEX_FUNCTION 291
#define LEX_BEGINFILE 292
#define LEX_ENDFILE 293
#define LEX_GETLINE 294
#define LEX_NEXTFILE 295
#define LEX_IN 296
#define LEX_AND 297
#define LEX_OR 298
#define INCREMENT 299
#define DECREMENT 300
#define LEX_BUILTIN 301
#define LEX_LENGTH 302
#define LEX_EOF 303
#define LEX_INCLUDE 304
#define LEX_EVAL 305
#define LEX_LOAD 306
#define LEX_NAMESPACE 307
#define LEX_NSINCLUDE 308
#define NEWLINE 309
#define SLASH_BEFORE_EQUAL 310
#define UNARY 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_FUNC_CALL = 3,                  /* FUNC_CALL  */
  YYSYMBOL_NAME = 4,                       /* NAME  */
  YYSYMBOL_REGEXP = 5,                     /* REGEXP  */
  YYSYMBOL_FILENAME = 6,                   /* FILENAME  */
  YYSYMBOL_YNUMBER = 7,                    /* YNUMBER  */
  YYSYMBOL_YSTRING = 8,                    /* YSTRING  */
  YYSYMBOL_TYPED_REGEXP = 9,               /* TYPED_REGEXP  */
  YYSYMBOL_RELOP = 10,                     /* RELOP  */
  YYSYMBOL_IO_OUT = 11,                    /* IO_OUT  */
  YYSYMBOL_IO_IN = 12,                     /* IO_IN  */
  YYSYMBOL_ASSIGNOP = 13,                  /* ASSIGNOP  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_MATCHOP = 15,                   /* MATCHOP  */
  YYSYMBOL_CONCAT_OP = 16,                 /* CONCAT_OP  */
  YYSYMBOL_SUBSCRIPT = 17,                 /* SUBSCRIPT  */
  YYSYMBOL_LEX_BEGIN = 18,                 /* LEX_BEGIN  */
  YYSYMBOL_LEX_END = 19,                   /* LEX_END  */
  YYSYMBOL_LEX_IF = 20,                    /* LEX_IF  */
  YYSYMBOL_LEX_ELSE = 21,                  /* LEX_ELSE  */
  YYSYMBOL_LEX_RETURN = 22,                /* LEX_RETURN  */
  YYSYMBOL_LEX_DELETE = 23,                /* LEX_DELETE  */
  YYSYMBOL_LEX_SWITCH = 24,                /* LEX_SWITCH  */
  YYSYMBOL_LEX_CASE = 25,                  /* LEX_CASE  */
  YYSYMBOL_LEX_DEFAULT = 26,               /* LEX_DEFAULT  */
  YYSYMBOL_LEX_WHILE = 27,                 /* LEX_WHILE  */
  YYSYMBOL_LEX_DO = 28,                    /* LEX_DO  */
  YYSYMBOL_LEX_FOR = 29,                   /* LEX_FOR  */
  YYSYMBOL_LEX_BREAK = 30,                 /* LEX_BREAK  */
  YYSYMBOL_LEX_CONTINUE = 31,              /* LEX_CONTINUE  */
  YYSYMBOL_LEX_PRINT = 32,                 /* LEX_PRINT  */
  YYSYMBOL_LEX_PRINTF = 33,                /* LEX_PRINTF  */
  YYSYMBOL_LEX_NEXT = 34,                  /* LEX_NEXT  */
  YYSYMBOL_LEX_EXIT = 35,                  /* LEX_EXIT  */
  YYSYMBOL_LEX_FUNCTION = 36,              /* LEX_FUNCTION  */
  YYSYMBOL_LEX_BEGINFILE = 37,             /* LEX_BEGINFILE  */
  YYSYMBOL_LEX_ENDFILE = 38,               /* LEX_ENDFILE  */
  YYSYMBOL_LEX_GETLINE = 39,               /* LEX_GETLINE  */
  YYSYMBOL_LEX_NEXTFILE = 40,              /* LEX_NEXTFILE  */
  YYSYMBOL_LEX_IN = 41,                    /* LEX_IN  */
  YYSYMBOL_LEX_AND = 42,                   /* LEX_AND  */
  YYSYMBOL_LEX_OR = 43,                    /* LEX_OR  */
  YYSYMBOL_INCREMENT = 44,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 45,                 /* DECREMENT  */
  YYSYMBOL_LEX_BUILTIN = 46,               /* LEX_BUILTIN  */
  YYSYMBOL_LEX_LENGTH = 47,                /* LEX_LENGTH  */
  YYSYMBOL_LEX_EOF = 48,                   /* LEX_EOF  */
  YYSYMBOL_LEX_INCLUDE = 49,               /* LEX_INCLUDE  */
  YYSYMBOL_LEX_EVAL = 50,                  /* LEX_EVAL  */
  YYSYMBOL_LEX_LOAD = 51,                  /* LEX_LOAD  */
  YYSYMBOL_LEX_NAMESPACE = 52,             /* LEX_NAMESPACE  */
  YYSYMBOL_LEX_NSINCLUDE = 53,             /* LEX_NSINCLUDE  */
  YYSYMBOL_NEWLINE = 54,                   /* NEWLINE  */
  YYSYMBOL_SLASH_BEFORE_EQUAL = 55,        /* SLASH_BEFORE_EQUAL  */
  YYSYMBOL_56_ = 56,                       /* '?'  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '<'  */
  YYSYMBOL_60_ = 60,                       /* '>'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_66_ = 66,                       /* '!'  */
  YYSYMBOL_UNARY = 67,                     /* UNARY  */
  YYSYMBOL_68_ = 68,                       /* '^'  */
  YYSYMBOL_69_ = 69,                       /* '$'  */
  YYSYMBOL_70_ = 70,                       /* '('  */
  YYSYMBOL_71_ = 71,                       /* ')'  */
  YYSYMBOL_72_ = 72,                       /* '@'  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_74_ = 74,                       /* ']'  */
  YYSYMBOL_75_ = 75,                       /* '{'  */
  YYSYMBOL_76_ = 76,                       /* '}'  */
  YYSYMBOL_77_ = 77,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 78,                  /* $accept  */
  YYSYMBOL_program = 79,                   /* program  */
  YYSYMBOL_rule = 80,                      /* rule  */
  YYSYMBOL_source = 81,                    /* source  */
  YYSYMBOL_library = 82,                   /* library  */
  YYSYMBOL_namespace = 83,                 /* namespace  */
  YYSYMBOL_pattern = 84,                   /* pattern  */
  YYSYMBOL_action = 85,                    /* action  */
  YYSYMBOL_func_name = 86,                 /* func_name  */
  YYSYMBOL_lex_builtin = 87,               /* lex_builtin  */
  YYSYMBOL_function_prologue = 88,         /* function_prologue  */
  YYSYMBOL_89_1 = 89,                      /* $@1  */
  YYSYMBOL_regexp = 90,                    /* regexp  */
  YYSYMBOL_91_2 = 91,                      /* $@2  */
  YYSYMBOL_typed_regexp = 92,              /* typed_regexp  */
  YYSYMBOL_a_slash = 93,                   /* a_slash  */
  YYSYMBOL_statements = 94,                /* statements  */
  YYSYMBOL_statement_term = 95,            /* statement_term  */
  YYSYMBOL_statement = 96,                 /* statement  */
  YYSYMBOL_non_compound_stmt = 97,         /* non_compound_stmt  */
  YYSYMBOL_98_3 = 98,                      /* $@3  */
  YYSYMBOL_simple_stmt = 99,               /* simple_stmt  */
  YYSYMBOL_100_4 = 100,                    /* $@4  */
  YYSYMBOL_101_5 = 101,                    /* $@5  */
  YYSYMBOL_opt_simple_stmt = 102,          /* opt_simple_stmt  */
  YYSYMBOL_case_statements = 103,          /* case_statements  */
  YYSYMBOL_case_statement = 104,           /* case_statement  */
  YYSYMBOL_case_value = 105,               /* case_value  */
  YYSYMBOL_print = 106,                    /* print  */
  YYSYMBOL_print_expression_list = 107,    /* print_expression_list  */
  YYSYMBOL_output_redir = 108,             /* output_redir  */
  YYSYMBOL_109_6 = 109,                    /* $@6  */
  YYSYMBOL_if_statement = 110,             /* if_statement  */
  YYSYMBOL_nls = 111,                      /* nls  */
  YYSYMBOL_opt_nls = 112,                  /* opt_nls  */
  YYSYMBOL_input_redir = 113,              /* input_redir  */
  YYSYMBOL_opt_param_list = 114,           /* opt_param_list  */
  YYSYMBOL_param_list = 115,               /* param_list  */
  YYSYMBOL_opt_exp = 116,                  /* opt_exp  */
  YYSYMBOL_opt_expression_list = 117,      /* opt_expression_list  */
  YYSYMBOL_expression_list = 118,          /* expression_list  */
  YYSYMBOL_opt_fcall_expression_list = 119, /* opt_fcall_expression_list  */
  YYSYMBOL_fcall_expression_list = 120,    /* fcall_expression_list  */
  YYSYMBOL_fcall_exp = 121,                /* fcall_exp  */
  YYSYMBOL_opt_fcall_exp = 122,            /* opt_fcall_exp  */
  YYSYMBOL_exp = 123,                      /* exp  */
  YYSYMBOL_assign_operator = 124,          /* assign_operator  */
  YYSYMBOL_relop_or_less = 125,            /* relop_or_less  */
  YYSYMBOL_a_relop = 126,                  /* a_relop  */
  YYSYMBOL_common_exp = 127,               /* common_exp  */
  YYSYMBOL_simp_exp = 128,                 /* simp_exp  */
  YYSYMBOL_simp_exp_nc = 129,              /* simp_exp_nc  */
  YYSYMBOL_non_post_simp_exp = 130,        /* non_post_simp_exp  */
  YYSYMBOL_func_call = 131,                /* func_call  */
  YYSYMBOL_direct_func_call = 132,         /* direct_func_call  */
  YYSYMBOL_opt_variable = 133,             /* opt_variable  */
  YYSYMBOL_delete_subscript_list = 134,    /* delete_subscript_list  */
  YYSYMBOL_delete_subscript = 135,         /* delete_subscript  */
  YYSYMBOL_delete_exp_list = 136,          /* delete_exp_list  */
  YYSYMBOL_bracketed_exp_list = 137,       /* bracketed_exp_list  */
  YYSYMBOL_subscript = 138,                /* subscript  */
  YYSYMBOL_subscript_list = 139,           /* subscript_list  */
  YYSYMBOL_simple_variable = 140,          /* simple_variable  */
  YYSYMBOL_variable = 141,                 /* variable  */
  YYSYMBOL_opt_incdec = 142,               /* opt_incdec  */
  YYSYMBOL_l_brace = 143,                  /* l_brace  */
  YYSYMBOL_r_brace = 144,                  /* r_brace  */
  YYSYMBOL_r_paren = 145,                  /* r_paren  */
  YYSYMBOL_opt_semi = 146,                 /* opt_semi  */
  YYSYMBOL_semi = 147,                     /* semi  */
  YYSYMBOL_colon = 148,                    /* colon  */
  YYSYMBOL_comma = 149                     /* comma  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  359

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
       2,     2,     2,    66,     2,     2,    69,    65,     2,     2,
      70,    71,    63,    61,    58,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    77,
      59,     2,    60,    56,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    76,     2,     2,     2,     2,
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
      55,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   238,   238,   239,   244,   254,   258,   270,   278,   292,
     303,   313,   323,   333,   359,   369,   371,   376,   386,   388,
     393,   395,   397,   403,   407,   412,   442,   454,   466,   472,
     481,   499,   500,   511,   517,   525,   526,   530,   530,   564,
     563,   597,   612,   614,   619,   620,   640,   645,   646,   650,
     661,   666,   673,   781,   832,   882,  1008,  1030,  1051,  1061,
    1071,  1081,  1092,  1105,  1123,  1122,  1139,  1157,  1157,  1259,
    1259,  1292,  1322,  1330,  1331,  1337,  1338,  1345,  1350,  1363,
    1378,  1380,  1388,  1395,  1397,  1405,  1414,  1416,  1425,  1426,
    1434,  1439,  1439,  1452,  1459,  1472,  1476,  1498,  1499,  1505,
    1506,  1515,  1516,  1521,  1526,  1543,  1545,  1547,  1554,  1555,
    1561,  1562,  1567,  1569,  1576,  1578,  1586,  1591,  1602,  1603,
    1608,  1610,  1617,  1619,  1627,  1632,  1642,  1643,  1648,  1649,
    1654,  1661,  1665,  1667,  1669,  1682,  1699,  1709,  1716,  1718,
    1723,  1725,  1727,  1735,  1737,  1742,  1744,  1749,  1751,  1753,
    1810,  1812,  1814,  1816,  1818,  1820,  1822,  1824,  1838,  1843,
    1848,  1874,  1880,  1882,  1884,  1886,  1888,  1890,  1895,  1899,
    1931,  1939,  1945,  1951,  1964,  1965,  1966,  1971,  1976,  1980,
    1984,  1999,  2020,  2025,  2062,  2099,  2100,  2106,  2107,  2112,
    2114,  2121,  2138,  2155,  2157,  2164,  2169,  2175,  2187,  2199,
    2208,  2212,  2217,  2221,  2225,  2229,  2234,  2235,  2239,  2243,
    2247
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
  "\"end of file\"", "error", "\"invalid token\"", "FUNC_CALL", "NAME",
  "REGEXP", "FILENAME", "YNUMBER", "YSTRING", "TYPED_REGEXP", "RELOP",
  "IO_OUT", "IO_IN", "ASSIGNOP", "ASSIGN", "MATCHOP", "CONCAT_OP",
  "SUBSCRIPT", "LEX_BEGIN", "LEX_END", "LEX_IF", "LEX_ELSE", "LEX_RETURN",
  "LEX_DELETE", "LEX_SWITCH", "LEX_CASE", "LEX_DEFAULT", "LEX_WHILE",
  "LEX_DO", "LEX_FOR", "LEX_BREAK", "LEX_CONTINUE", "LEX_PRINT",
  "LEX_PRINTF", "LEX_NEXT", "LEX_EXIT", "LEX_FUNCTION", "LEX_BEGINFILE",
  "LEX_ENDFILE", "LEX_GETLINE", "LEX_NEXTFILE", "LEX_IN", "LEX_AND",
  "LEX_OR", "INCREMENT", "DECREMENT", "LEX_BUILTIN", "LEX_LENGTH",
  "LEX_EOF", "LEX_INCLUDE", "LEX_EVAL", "LEX_LOAD", "LEX_NAMESPACE",
  "LEX_NSINCLUDE", "NEWLINE", "SLASH_BEFORE_EQUAL", "'?'", "':'", "','",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARY", "'^'",
  "'$'", "'('", "')'", "'@'", "'['", "']'", "'{'", "'}'", "';'", "$accept",
  "program", "rule", "source", "library", "namespace", "pattern", "action",
  "func_name", "lex_builtin", "function_prologue", "$@1", "regexp", "$@2",
  "typed_regexp", "a_slash", "statements", "statement_term", "statement",
  "non_compound_stmt", "$@3", "simple_stmt", "$@4", "$@5",
  "opt_simple_stmt", "case_statements", "case_statement", "case_value",
  "print", "print_expression_list", "output_redir", "$@6", "if_statement",
  "nls", "opt_nls", "input_redir", "opt_param_list", "param_list",
  "opt_exp", "opt_expression_list", "expression_list",
  "opt_fcall_expression_list", "fcall_expression_list", "fcall_exp",
  "opt_fcall_exp", "exp", "assign_operator", "relop_or_less", "a_relop",
  "common_exp", "simp_exp", "simp_exp_nc", "non_post_simp_exp",
  "func_call", "direct_func_call", "opt_variable", "delete_subscript_list",
  "delete_subscript", "delete_exp_list", "bracketed_exp_list", "subscript",
  "subscript_list", "simple_variable", "variable", "opt_incdec", "l_brace",
  "r_brace", "r_paren", "opt_semi", "semi", "colon", "comma", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-287)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -287,   317,  -287,  -287,   -46,   -39,  -287,  -287,  -287,  -287,
     280,  -287,  -287,    44,    44,    44,    -7,     9,  -287,  -287,
    -287,  1065,  1065,  -287,  1065,  1094,   827,   279,  -287,   -24,
     -18,  -287,  -287,    22,  1035,   991,   305,   380,  -287,  -287,
    -287,  -287,   346,   749,   827,  -287,    12,  -287,  -287,  -287,
    -287,  -287,    62,    63,  -287,    84,  -287,  -287,  -287,   749,
     749,   145,    87,     5,    87,    87,  1065,   114,  -287,  -287,
      15,   871,    26,    60,    66,    26,  -287,   112,  -287,  -287,
    -287,    22,  -287,   112,  -287,   164,  -287,  -287,  1020,   169,
    1065,  1065,  1065,   112,  -287,  -287,  -287,  1065,  1065,   136,
     305,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,
    1065,  1065,  1065,  -287,   167,  -287,  -287,   163,  1065,  -287,
    -287,  -287,   108,    94,  -287,  1138,     6,  1138,  -287,  -287,
    -287,  -287,  1065,  -287,   108,   108,   871,  -287,  -287,  -287,
    1065,  -287,   148,   856,  -287,  -287,    16,   -23,  -287,    61,
     -23,  -287,    97,   -23,   -23,    22,  -287,   546,  -287,  -287,
    -287,   190,  -287,   278,   250,  1132,  -287,   253,  1138,    44,
     312,   312,    87,    87,    87,    87,   312,   312,    87,    87,
      87,    87,  -287,  -287,  1138,  -287,  1020,   778,  -287,    43,
     305,  -287,  -287,  1138,   169,  -287,  1138,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,   120,  -287,    14,   121,   123,
     112,   125,   -23,   -23,  -287,  -287,   -23,  1065,   -23,   112,
    -287,  -287,   -23,  -287,  -287,  1138,  -287,   119,   112,  1065,
    -287,  -287,  -287,  -287,  -287,  -287,   108,   110,  -287,  1065,
    1020,  -287,   193,  1065,  1065,   666,   901,  -287,  -287,  -287,
     -23,  1138,  -287,  -287,  -287,   595,   546,   112,  -287,  -287,
    1138,   112,  -287,    70,   871,  -287,   -23,   -39,   128,   871,
     871,   174,   -13,  -287,   119,  -287,   827,   195,  -287,   134,
    -287,  -287,  -287,  -287,  -287,   112,  -287,  -287,    99,  -287,
    -287,  -287,   112,   112,   137,   169,   112,    15,  -287,  -287,
     666,  -287,  -287,   -18,   666,  1065,   108,   700,   148,  1065,
     189,  -287,  -287,   871,   112,  1109,   112,   991,   112,   201,
     112,   666,   112,   946,   666,  -287,   342,   157,  -287,   139,
    -287,  -287,   946,   108,  -287,  -287,  -287,   211,   214,  -287,
    -287,   157,  -287,   112,  -287,   108,   112,  -287,  -287,   112,
    -287,   112,   666,  -287,   392,   666,  -287,   469,  -287
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     6,     0,   196,   178,   179,    26,    27,
       0,    28,    29,   185,     0,     0,     0,   173,     5,    95,
      43,     0,     0,    42,     0,     0,     0,     0,     3,     0,
       0,   168,    39,     4,    24,   139,   147,   148,   150,   174,
     182,   198,   175,     0,     0,   193,     0,   197,    32,    31,
      35,    36,     0,     0,    33,    99,   186,   176,   177,     0,
       0,     0,   181,   175,   180,   169,     0,   202,   175,   114,
       0,   112,     0,     0,     0,     0,   183,    97,   208,     7,
       8,    47,    44,    97,     9,     0,    96,   143,     0,     0,
       0,     0,     0,    97,   144,   146,   145,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   140,   158,   159,     0,     0,   122,
      41,   127,     0,     0,   120,   126,     0,   112,   195,   194,
      34,    37,     0,   157,     0,     0,     0,   200,   201,   199,
     115,   205,     0,     0,   170,    16,     0,     0,    19,     0,
       0,    22,     0,     0,     0,    98,   203,     0,    48,    40,
     134,   135,   136,   132,   133,     0,   210,   137,    25,   185,
     155,   156,   152,   153,   154,   151,   166,   167,   163,   164,
     165,   162,   131,   142,   130,   184,   123,     0,   192,     0,
     100,   171,   172,   116,     0,   117,   113,    15,    10,    18,
      12,    21,    13,    11,    46,     0,    64,     0,     0,     0,
      97,     0,     0,     0,    86,    87,     0,   108,     0,    97,
      45,    58,     0,    67,    51,    72,    44,   206,    97,     0,
     161,   124,   125,   121,   105,   103,     0,     0,   160,     0,
     128,    69,     0,     0,     0,     0,    73,    59,    60,    61,
       0,   109,    62,   204,    66,     0,     0,    97,   207,    49,
     138,    97,   106,     0,     0,   129,     0,   187,     0,     0,
       0,     0,   196,    74,     0,    63,     0,    90,    88,     0,
      50,    30,    38,   107,   104,    97,    65,    70,     0,   189,
     191,    71,    97,    97,     0,     0,    97,     0,    91,    68,
       0,   188,   190,     0,     0,     0,     0,     0,    89,     0,
      93,    75,    53,     0,    97,     0,    97,    92,    97,     0,
      97,     0,    97,    73,     0,    77,     0,     0,    76,     0,
      54,    55,    73,     0,    94,    80,    83,     0,     0,    84,
      85,     0,   209,    97,    52,     0,    97,    82,    81,    97,
      44,    97,     0,    44,     0,     0,    57,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -287,  -287,  -287,   147,  -287,  -287,  -287,   194,  -287,  -287,
    -287,  -287,   -92,  -287,   -74,  -287,  -216,   -72,  -168,  -287,
    -287,  -240,  -287,  -287,  -286,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,     7,   -48,  -287,  -287,  -287,  -287,  -287,
     -43,   104,  -287,    -4,  -287,    -1,  -287,  -287,  -287,   -68,
      17,  -287,   228,  -287,    -6,    89,  -287,  -287,   -32,   -37,
    -287,  -287,   -63,    -2,  -287,   -27,  -241,   -66,  -287,   -10,
     -82,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   147,   150,   153,    29,    79,    53,    54,
      30,   189,    31,    85,   121,    32,   157,    80,   220,   221,
     240,   222,   255,   267,   274,   319,   328,   341,   223,   277,
     299,   309,   224,   155,   156,   133,   236,   237,   250,   278,
      70,   122,   123,   124,   266,   225,   118,    96,    97,    35,
      36,    37,    38,    39,    40,    55,   287,   288,   289,    45,
      46,    47,    41,    42,   139,   226,   227,   144,   257,    83,
     343,   143
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   126,    82,    82,   142,    98,   273,   140,    33,   129,
     256,    56,    57,    58,   160,   280,   140,   197,   241,    63,
      63,    76,    63,    68,    43,    71,   162,   145,   295,   128,
      19,    19,   146,    63,    44,   158,    81,   333,    62,    64,
     182,    65,   125,   127,   234,   166,   345,   235,     5,   115,
     116,    77,   100,    78,    78,    76,   185,    77,   125,   125,
      44,   148,   199,    59,    93,   136,   149,   151,   191,   192,
     -14,   283,   152,    93,   284,   198,    86,   271,   200,    60,
     188,   202,   203,   273,   242,    44,   141,   161,   344,   163,
     164,   165,   273,   -14,   187,   186,   167,   168,   201,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,   262,   130,    25,  -101,   -17,   301,   184,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      63,   238,   310,   131,   354,   140,   312,   357,   -17,   193,
     247,   248,   196,   132,   249,  -111,   252,   228,     4,   190,
     254,   -20,    93,   331,    81,   106,   334,    81,   137,   138,
      81,    81,   245,   134,   135,  -119,    19,    56,    93,   159,
     261,   253,    44,     5,   -20,   169,   120,   183,   275,   141,
     259,  -102,   231,   233,   356,   125,   125,   358,  -111,   194,
     239,   243,    93,   244,   286,   246,    78,   268,   285,   291,
      87,   294,   325,   292,   293,  -111,   298,   305,   263,   281,
     318,  -111,   279,   282,   342,   219,   251,   258,   347,    81,
      81,   348,   154,    81,    84,    81,   326,   327,   260,    81,
     290,   308,   306,   297,   339,   228,   265,   300,   264,   125,
     314,   317,   269,   270,   303,   304,   228,   320,   307,    94,
      95,   290,   340,    67,   127,    19,   302,    81,   230,   349,
      87,     0,     0,  -120,   296,    88,   321,   346,   323,     0,
     324,   329,   330,    81,   332,    71,   311,   -97,     0,   351,
       0,     0,     4,    48,    49,     0,     0,     0,    87,     0,
     228,    89,    90,    88,   228,   350,     0,   316,   352,     0,
       0,   353,     0,   355,   313,   322,   315,    63,     0,    94,
      95,   228,  -120,  -120,   228,    63,     0,     2,     3,    89,
       4,     5,     0,     0,     6,     7,    50,    51,    72,     0,
      73,    74,    75,     0,   100,     8,     9,    94,    95,     0,
       0,     0,   228,     0,   228,   228,     0,   228,     0,   335,
     336,   120,    52,    10,    11,    12,    13,     0,     0,   113,
     114,    14,    15,    16,    17,    18,   101,   102,   103,   104,
     105,    19,    20,   106,     0,   103,   104,   105,    21,    22,
     106,    23,     0,    24,     0,     0,    25,    26,     0,    27,
     115,   116,   -23,   204,   -23,     4,     5,    20,     0,     6,
       7,   117,     0,   337,   338,     0,    23,     0,     0,     0,
       0,     0,   205,     0,   206,   207,   208,   -79,   -79,   209,
     210,   211,   212,   213,   214,   215,   216,   217,     0,     0,
       0,    13,   218,     0,     0,     0,    14,    15,    16,    17,
       0,   107,   108,   109,   110,   111,   -79,    20,   112,     0,
       0,     0,     0,    21,    22,     0,    23,     0,    24,     0,
       0,    25,    26,     0,    61,     0,     0,    77,   -79,    78,
     204,     0,     4,     5,     0,     0,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,   206,   207,   208,   -78,   -78,   209,   210,   211,   212,
     213,   214,   215,   216,   217,     0,     0,     0,    13,   218,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,   -78,    20,     0,     0,     0,     0,     0,
      21,    22,     0,    23,     0,    24,     0,     0,    25,    26,
       0,    61,     0,     0,    77,   -78,    78,   204,     0,     4,
       5,     0,     0,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,   206,   207,
     208,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,     0,     0,     0,    13,   218,     0,     0,     0,
      14,    15,    16,    17,     0,     0,    69,     0,     4,     5,
       0,    20,     6,     7,     0,     0,  -110,    21,    22,     0,
      23,     0,    24,     0,     0,    25,    26,     0,    61,     0,
       0,    77,   219,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,  -110,
      20,     0,     0,     0,     0,     0,    21,    22,     0,    23,
       0,    24,     0,     0,    25,   276,  -110,    61,     0,     4,
       5,     0,  -110,     6,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,   206,   207,
     208,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,     0,     4,     5,    13,   218,     6,     7,     0,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,    21,    22,     0,
      23,     0,    24,     0,     0,    25,    26,     0,    61,    13,
       0,    77,     0,    78,    14,    15,    16,    17,     0,     0,
     119,     0,     4,     5,     0,    20,     6,     7,   120,     0,
       0,    21,    22,     0,    23,     0,    24,     0,     0,    25,
      26,     0,    61,     0,     0,     0,     0,    78,     0,   232,
       0,     4,     5,     0,     0,     6,     7,   120,    13,     0,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
      21,    22,     0,    23,     0,    24,     0,    13,    25,    26,
    -118,    61,    14,    15,    16,    17,     0,     0,    69,     0,
       4,     5,     0,    20,     6,     7,     0,     0,     0,    21,
      22,     0,    23,     0,    24,     0,     0,    25,    26,     0,
      61,     0,     0,     0,     0,     0,     0,   195,     0,     4,
       5,     0,     0,     6,     7,     0,    13,     0,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,    87,    20,     0,     0,     0,    88,     0,    21,    22,
       0,    23,     0,    24,     0,    13,    25,    26,     0,    61,
      14,    15,    16,    17,     4,   272,     0,     0,     6,     7,
       0,    20,    89,    90,    91,     0,     0,    21,    22,     0,
      23,     0,    24,     0,   207,    25,    26,    92,    61,     0,
      94,    95,     0,   214,   215,     0,     0,     0,     0,     0,
      13,     0,   141,     0,     0,    14,    15,    16,    17,     4,
       5,     0,     0,     6,     7,     0,    20,     0,     0,     0,
       0,     0,    21,    22,     0,    23,     0,    24,     0,   207,
      25,    26,     0,    61,     0,     0,     0,     0,   214,   215,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
      14,    15,    16,    17,     4,     5,     0,     0,     6,     7,
       0,    20,     0,    99,     0,     0,     0,    21,    22,     0,
      23,     0,    24,     0,     0,    25,    26,     0,    61,     0,
       0,     0,     0,     4,     5,     0,     0,     6,     7,   120,
      13,     0,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,    87,    20,     0,     0,     0,
      88,     0,    21,    22,     0,    23,     0,    24,     0,    13,
      25,    26,     0,    61,    14,    15,    16,    17,     4,     5,
       0,     0,     6,     7,     0,    20,    89,    90,    91,     0,
       0,    21,    22,     0,    23,     0,    24,     0,     0,    25,
      26,    92,    61,    93,    94,    95,     0,     4,     5,     0,
       0,     6,     7,     0,    13,     0,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    87,
      20,     0,     0,     0,    88,     0,    21,    22,     0,    23,
       0,    24,     0,     0,    25,    26,     0,    61,    14,    15,
      16,    17,    87,     0,     0,     0,     0,    88,    87,    20,
      89,    90,    91,    88,     0,    21,    22,     0,    23,     0,
      24,     0,     0,    25,    66,    92,    61,     0,    94,    95,
       0,     0,     0,    89,    90,    91,     0,     0,     0,    89,
      90,    91,     0,     0,     0,     0,    78,     0,    92,   229,
       0,    94,    95,     0,    92,     0,     0,    94,    95
};

static const yytype_int16 yycheck[] =
{
       1,    44,    29,    30,    70,    34,   246,     1,     1,    46,
     226,    13,    14,    15,    88,   256,     1,     1,     4,    21,
      22,    27,    24,    25,    70,    26,    89,     1,    41,    17,
      54,    54,     6,    35,    73,    83,    29,   323,    21,    22,
     114,    24,    43,    44,     1,    93,   332,     4,     4,    44,
      45,    75,    35,    77,    77,    61,   122,    75,    59,    60,
      73,     1,     1,    70,    58,    66,     6,     1,   134,   135,
      54,     1,     6,    58,     4,   147,    54,   245,   150,    70,
      74,   153,   154,   323,    70,    73,    71,    88,   329,    90,
      91,    92,   332,    77,   123,     1,    97,    98,     1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     1,    50,    69,    71,    54,    17,   118,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     132,   194,   300,    70,   350,     1,   304,   353,    77,   140,
     212,   213,   143,    59,   216,    11,   218,   157,     3,   132,
     222,    54,    58,   321,   147,    68,   324,   150,    44,    45,
     153,   154,   210,    59,    60,    71,    54,   169,    58,     5,
     236,   219,    73,     4,    77,    39,     9,    14,   250,    71,
     228,    71,   186,   187,   352,   186,   187,   355,    54,    41,
      70,    70,    58,    70,   266,    70,    77,     4,   264,    71,
      10,    27,     1,   269,   270,    71,    11,    70,   237,   257,
      21,    77,   255,   261,    57,    76,   217,   227,     7,   212,
     213,     7,    75,   216,    30,   218,    25,    26,   229,   222,
     267,   297,   295,   276,   326,   245,   240,   285,   239,   240,
     306,   309,   243,   244,   292,   293,   256,   313,   296,    59,
      60,   288,   326,    25,   255,    54,   288,   250,   169,   341,
      10,    -1,    -1,    10,   274,    15,   314,   333,   316,    -1,
     318,   319,   320,   266,   322,   276,   303,    76,    -1,   345,
      -1,    -1,     3,     3,     4,    -1,    -1,    -1,    10,    -1,
     300,    41,    42,    15,   304,   343,    -1,   307,   346,    -1,
      -1,   349,    -1,   351,   305,   315,   307,   309,    -1,    59,
      60,   321,    59,    60,   324,   317,    -1,     0,     1,    41,
       3,     4,    -1,    -1,     7,     8,    46,    47,    49,    -1,
      51,    52,    53,    -1,   317,    18,    19,    59,    60,    -1,
      -1,    -1,   352,    -1,   354,   355,    -1,   357,    -1,     7,
       8,     9,    72,    36,    37,    38,    39,    -1,    -1,    13,
      14,    44,    45,    46,    47,    48,    61,    62,    63,    64,
      65,    54,    55,    68,    -1,    63,    64,    65,    61,    62,
      68,    64,    -1,    66,    -1,    -1,    69,    70,    -1,    72,
      44,    45,    75,     1,    77,     3,     4,    55,    -1,     7,
       8,    55,    -1,    61,    62,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    61,    62,    63,    64,    65,    54,    55,    68,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,    -1,
      -1,    69,    70,    -1,    72,    -1,    -1,    75,    76,    77,
       1,    -1,     3,     4,    -1,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    64,    -1,    66,    -1,    -1,    69,    70,
      -1,    72,    -1,    -1,    75,    76,    77,     1,    -1,     3,
       4,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,     1,    -1,     3,     4,
      -1,    55,     7,     8,    -1,    -1,    11,    61,    62,    -1,
      64,    -1,    66,    -1,    -1,    69,    70,    -1,    72,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      -1,    66,    -1,    -1,    69,    70,    71,    72,    -1,     3,
       4,    -1,    77,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,     3,     4,    39,    40,     7,     8,    -1,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    -1,    66,    -1,    -1,    69,    70,    -1,    72,    39,
      -1,    75,    -1,    77,    44,    45,    46,    47,    -1,    -1,
       1,    -1,     3,     4,    -1,    55,     7,     8,     9,    -1,
      -1,    61,    62,    -1,    64,    -1,    66,    -1,    -1,    69,
      70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,     1,
      -1,     3,     4,    -1,    -1,     7,     8,     9,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    64,    -1,    66,    -1,    39,    69,    70,
      71,    72,    44,    45,    46,    47,    -1,    -1,     1,    -1,
       3,     4,    -1,    55,     7,     8,    -1,    -1,    -1,    61,
      62,    -1,    64,    -1,    66,    -1,    -1,    69,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,    -1,    -1,     7,     8,    -1,    39,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    55,    -1,    -1,    -1,    15,    -1,    61,    62,
      -1,    64,    -1,    66,    -1,    39,    69,    70,    -1,    72,
      44,    45,    46,    47,     3,     4,    -1,    -1,     7,     8,
      -1,    55,    41,    42,    43,    -1,    -1,    61,    62,    -1,
      64,    -1,    66,    -1,    23,    69,    70,    56,    72,    -1,
      59,    60,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    71,    -1,    -1,    44,    45,    46,    47,     3,
       4,    -1,    -1,     7,     8,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    64,    -1,    66,    -1,    23,
      69,    70,    -1,    72,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,     3,     4,    -1,    -1,     7,     8,
      -1,    55,    -1,    12,    -1,    -1,    -1,    61,    62,    -1,
      64,    -1,    66,    -1,    -1,    69,    70,    -1,    72,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,     7,     8,     9,
      39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    55,    -1,    -1,    -1,
      15,    -1,    61,    62,    -1,    64,    -1,    66,    -1,    39,
      69,    70,    -1,    72,    44,    45,    46,    47,     3,     4,
      -1,    -1,     7,     8,    -1,    55,    41,    42,    43,    -1,
      -1,    61,    62,    -1,    64,    -1,    66,    -1,    -1,    69,
      70,    56,    72,    58,    59,    60,    -1,     3,     4,    -1,
      -1,     7,     8,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      55,    -1,    -1,    -1,    15,    -1,    61,    62,    -1,    64,
      -1,    66,    -1,    -1,    69,    70,    -1,    72,    44,    45,
      46,    47,    10,    -1,    -1,    -1,    -1,    15,    10,    55,
      41,    42,    43,    15,    -1,    61,    62,    -1,    64,    -1,
      66,    -1,    -1,    69,    70,    56,    72,    -1,    59,    60,
      -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    77,    -1,    56,    57,
      -1,    59,    60,    -1,    56,    -1,    -1,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    79,     0,     1,     3,     4,     7,     8,    18,    19,
      36,    37,    38,    39,    44,    45,    46,    47,    48,    54,
      55,    61,    62,    64,    66,    69,    70,    72,    80,    84,
      88,    90,    93,   111,   123,   127,   128,   129,   130,   131,
     132,   140,   141,    70,    73,   137,   138,   139,     3,     4,
      46,    47,    72,    86,    87,   133,   141,   141,   141,    70,
      70,    72,   128,   141,   128,   128,    70,   130,   141,     1,
     118,   123,    49,    51,    52,    53,   132,    75,    77,    85,
      95,   111,   143,   147,    85,    91,    54,    10,    15,    41,
      42,    43,    56,    58,    59,    60,   125,   126,   149,    12,
     128,    61,    62,    63,    64,    65,    68,    61,    62,    63,
      64,    65,    68,    13,    14,    44,    45,    55,   124,     1,
       9,    92,   119,   120,   121,   123,   118,   123,    17,   137,
      50,    70,    59,   113,   119,   119,   123,    44,    45,   142,
       1,    71,   145,   149,   145,     1,     6,    81,     1,     6,
      82,     1,     6,    83,    81,   111,   112,    94,   112,     5,
      92,   123,   140,   123,   123,   123,   112,   123,   123,    39,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,    92,    14,   123,   145,     1,   149,    74,    89,
     128,   145,   145,   123,    41,     1,   123,     1,    95,     1,
      95,     1,    95,    95,     1,    20,    22,    23,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    40,    76,
      96,    97,    99,   106,   110,   123,   143,   144,   147,    57,
     133,   121,     1,   121,     1,     4,   114,   115,   140,    70,
      98,     4,    70,    70,    70,   112,    70,    95,    95,    95,
     116,   123,    95,   112,    95,   100,    94,   146,   147,   112,
     123,   145,     1,   149,   123,   121,   122,   101,     4,   123,
     123,    96,     4,    99,   102,    95,    70,   107,   117,   118,
     144,   112,   112,     1,     4,   145,    95,   134,   135,   136,
     137,    71,   145,   145,    27,    41,   147,   118,    11,   108,
     112,    17,   136,   112,   112,    70,   140,   112,   145,   109,
      96,   143,    96,   123,   145,   123,   147,   127,    21,   103,
     145,   112,   147,   112,   112,     1,    25,    26,   104,   112,
     112,    96,   112,   102,    96,     7,     8,    61,    62,    90,
      92,   105,    57,   148,   144,   102,   145,     7,     7,   148,
     112,   145,   112,   112,    94,   112,    96,    94,    96
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      85,    86,    86,    86,    86,    87,    87,    89,    88,    91,
      90,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    98,    97,    97,   100,    99,   101,
      99,    99,    99,   102,   102,   103,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   107,
     108,   109,   108,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   115,   115,   116,   116,
     117,   117,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   133,   133,   134,   134,   135,
     135,   136,   137,   138,   138,   139,   140,   140,   141,   141,
     142,   142,   142,   143,   144,   145,   146,   146,   147,   148,
     149
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       4,     4,     4,     4,     1,     2,     1,     1,     2,     1,
       1,     2,     1,     0,     1,     3,     1,     1,     1,     1,
       5,     1,     1,     1,     2,     1,     1,     0,     7,     0,
       3,     1,     1,     1,     0,     2,     2,     1,     2,     2,
       3,     1,     9,     6,     8,     8,    12,    11,     1,     2,
       2,     2,     2,     3,     0,     4,     2,     0,     4,     0,
       4,     4,     1,     0,     1,     0,     2,     2,     5,     4,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       0,     0,     3,     6,     9,     1,     2,     0,     1,     0,
       2,     0,     1,     1,     3,     1,     2,     3,     0,     1,
       0,     1,     1,     3,     1,     2,     3,     3,     0,     1,
       1,     3,     1,     2,     3,     3,     1,     1,     0,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       5,     4,     3,     3,     3,     3,     3,     3,     1,     2,
       3,     4,     4,     1,     1,     1,     2,     2,     1,     1,
       2,     2,     1,     2,     4,     0,     1,     0,     2,     1,
       2,     1,     3,     1,     2,     2,     1,     2,     1,     3,
       1,     1,     0,     2,     2,     1,     0,     1,     1,     1,
       2
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
  case 2: /* program: %empty  */
#line 238 "awkgram.y"
          { yyval = NULL; }
#line 1965 "awkgram.c"
    break;

  case 3: /* program: program rule  */
#line 240 "awkgram.y"
          {
		rule = 0;
		yyerrok;
	  }
#line 1974 "awkgram.c"
    break;

  case 4: /* program: program nls  */
#line 245 "awkgram.y"
          {
		if (yyvsp[0] != NULL) {
			if (yyvsp[-1] == NULL)
				outer_comment = yyvsp[0];
			else
				interblock_comment = yyvsp[0];
		}
		yyval = yyvsp[-1];
	  }
#line 1988 "awkgram.c"
    break;

  case 5: /* program: program LEX_EOF  */
#line 255 "awkgram.y"
          {
		next_sourcefile();
	  }
#line 1996 "awkgram.c"
    break;

  case 6: /* program: program error  */
#line 259 "awkgram.y"
          {
		rule = 0;
		/*
		 * If errors, give up, don't produce an infinite
		 * stream of syntax error messages.
		 */
  		/* yyerrok; */
	  }
#line 2009 "awkgram.c"
    break;

  case 7: /* rule: pattern action  */
#line 271 "awkgram.y"
          {
		(void) append_rule(yyvsp[-1], yyvsp[0]);
		if (pending_comment != NULL) {
			interblock_comment = pending_comment;
			pending_comment = NULL;
		}
	  }
#line 2021 "awkgram.c"
    break;

  case 8: /* rule: pattern statement_term  */
#line 279 "awkgram.y"
          {
		if (rule != Rule) {
			msg(_("%s blocks must have an action part"), ruletab[rule]);
			errcount++;
		} else if (yyvsp[-1] == NULL) {
			msg(_("each rule must have a pattern or an action part"));
			errcount++;
		} else {	/* pattern rule with non-empty pattern */
			if (yyvsp[0] != NULL)
				list_append(yyvsp[-1], yyvsp[0]);
			(void) append_rule(yyvsp[-1], NULL);
		}
	  }
#line 2039 "awkgram.c"
    break;

  case 9: /* rule: function_prologue action  */
#line 293 "awkgram.y"
          {
		in_function = false;
		(void) mk_function(yyvsp[-1], yyvsp[0]);
		want_param_names = DONT_CHECK;
		if (pending_comment != NULL) {
			interblock_comment = pending_comment;
			pending_comment = NULL;
		}
		yyerrok;
	  }
#line 2054 "awkgram.c"
    break;

  case 10: /* rule: '@' LEX_INCLUDE source statement_term  */
#line 304 "awkgram.y"
          {
		want_source = false;
		at_seen--;
		if (yyvsp[-1] != NULL && yyvsp[0] != NULL) {
			SRCFILE *s = (SRCFILE *) yyvsp[-1];
			s->comment = yyvsp[0];
		}
		yyerrok;
	  }
#line 2068 "awkgram.c"
    break;

  case 11: /* rule: '@' LEX_NSINCLUDE source statement_term  */
#line 314 "awkgram.y"
          {
		want_source = false;
		at_seen--;
		if (yyvsp[-1] != NULL && yyvsp[0] != NULL) {
			SRCFILE *s = (SRCFILE *) yyvsp[-1];
			s->comment = yyvsp[0];
		}
		yyerrok;
	  }
#line 2082 "awkgram.c"
    break;

  case 12: /* rule: '@' LEX_LOAD library statement_term  */
#line 324 "awkgram.y"
          {
		want_source = false;
		at_seen--;
		if (yyvsp[-1] != NULL && yyvsp[0] != NULL) {
			SRCFILE *s = (SRCFILE *) yyvsp[-1];
			s->comment = yyvsp[0];
		}
		yyerrok;
	  }
#line 2096 "awkgram.c"
    break;

  case 13: /* rule: '@' LEX_NAMESPACE namespace statement_term  */
#line 334 "awkgram.y"
          {
		/*
		 * 1/2022:
		 * We have an interesting isssue here.  This production isn't
		 * reduced until after the token following the statement_term
		 * is seen. As a result, the change in namespace doesn't take
		 * effect until then. That's fine if the first token is 'function'
		 * or BEGIN or some such, but it's a disaster if it's an identifer;
		 * that identifier will be in the previous namespace.
		 * Therefore, the actual setting of the namespace is done immediately
		 * down in the scanner.
		 */

		want_source = false;
		want_namespace = false;
		at_seen--;

		// this frees $3 storage in all cases
		set_namespace(yyvsp[-1], yyvsp[0]);

		yyerrok;
	  }
#line 2123 "awkgram.c"
    break;

  case 14: /* source: FILENAME  */
#line 360 "awkgram.y"
          {
		void *srcfile = NULL;

		if (! include_source(yyvsp[0], & srcfile))
			YYABORT;
		efree(yyvsp[0]->lextok);
		bcfree(yyvsp[0]);
		yyval = (INSTRUCTION *) srcfile;
	  }
#line 2137 "awkgram.c"
    break;

  case 15: /* source: FILENAME error  */
#line 370 "awkgram.y"
          { yyval = NULL; }
#line 2143 "awkgram.c"
    break;

  case 16: /* source: error  */
#line 372 "awkgram.y"
          { yyval = NULL; }
#line 2149 "awkgram.c"
    break;

  case 17: /* library: FILENAME  */
#line 377 "awkgram.y"
          {
		void *srcfile;

		if (! load_library(yyvsp[0], & srcfile))
			YYABORT;
		efree(yyvsp[0]->lextok);
		bcfree(yyvsp[0]);
		yyval = (INSTRUCTION *) srcfile;
	  }
#line 2163 "awkgram.c"
    break;

  case 18: /* library: FILENAME error  */
#line 387 "awkgram.y"
          { yyval = NULL; }
#line 2169 "awkgram.c"
    break;

  case 19: /* library: error  */
#line 389 "awkgram.y"
          { yyval = NULL; }
#line 2175 "awkgram.c"
    break;

  case 20: /* namespace: FILENAME  */
#line 394 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 2181 "awkgram.c"
    break;

  case 21: /* namespace: FILENAME error  */
#line 396 "awkgram.y"
          { yyval = NULL; }
#line 2187 "awkgram.c"
    break;

  case 22: /* namespace: error  */
#line 398 "awkgram.y"
          { yyval = NULL; }
#line 2193 "awkgram.c"
    break;

  case 23: /* pattern: %empty  */
#line 403 "awkgram.y"
          {
		rule = Rule;
		yyval = NULL;
	  }
#line 2202 "awkgram.c"
    break;

  case 24: /* pattern: exp  */
#line 408 "awkgram.y"
          {
		rule = Rule;
	  }
#line 2210 "awkgram.c"
    break;

  case 25: /* pattern: exp comma exp  */
#line 413 "awkgram.y"
          {
		INSTRUCTION *tp;

		add_lint(yyvsp[-2], LINT_assign_in_cond);
		add_lint(yyvsp[0], LINT_assign_in_cond);

		tp = instruction(Op_no_op);
		list_prepend(yyvsp[-2], bcalloc(Op_line_range, !!do_pretty_print + 1, 0));
		yyvsp[-2]->nexti->triggered = false;
		yyvsp[-2]->nexti->target_jmp = yyvsp[0]->nexti;

		list_append(yyvsp[-2], instruction(Op_cond_pair));
		yyvsp[-2]->lasti->line_range = yyvsp[-2]->nexti;
		yyvsp[-2]->lasti->target_jmp = tp;

		list_append(yyvsp[0], instruction(Op_cond_pair));
		yyvsp[0]->lasti->line_range = yyvsp[-2]->nexti;
		yyvsp[0]->lasti->target_jmp = tp;
		if (do_pretty_print) {
			(yyvsp[-2]->nexti + 1)->condpair_left = yyvsp[-2]->lasti;
			(yyvsp[-2]->nexti + 1)->condpair_right = yyvsp[0]->lasti;
		}
		/* Put any comments in front of the range expression */
		if (yyvsp[-1] != NULL)
			yyval = list_append(list_merge(list_prepend(yyvsp[-2], yyvsp[-1]), yyvsp[0]), tp);
		else
			yyval = list_append(list_merge(yyvsp[-2], yyvsp[0]), tp);
		rule = Rule;
	  }
#line 2244 "awkgram.c"
    break;

  case 26: /* pattern: LEX_BEGIN  */
#line 443 "awkgram.y"
          {
		static int begin_seen = 0;

		if (do_lint_old && ++begin_seen == 2)
			lintwarn_ln(yyvsp[0]->source_line,
				_("old awk does not support multiple `BEGIN' or `END' rules"));

		yyvsp[0]->in_rule = rule = BEGIN;
		yyvsp[0]->source_file = source;
		yyval = yyvsp[0];
	  }
#line 2260 "awkgram.c"
    break;

  case 27: /* pattern: LEX_END  */
#line 455 "awkgram.y"
          {
		static int end_seen = 0;

		if (do_lint_old && ++end_seen == 2)
			lintwarn_ln(yyvsp[0]->source_line,
				_("old awk does not support multiple `BEGIN' or `END' rules"));

		yyvsp[0]->in_rule = rule = END;
		yyvsp[0]->source_file = source;
		yyval = yyvsp[0];
	  }
#line 2276 "awkgram.c"
    break;

  case 28: /* pattern: LEX_BEGINFILE  */
#line 467 "awkgram.y"
          {
		yyvsp[0]->in_rule = rule = BEGINFILE;
		yyvsp[0]->source_file = source;
		yyval = yyvsp[0];
	  }
#line 2286 "awkgram.c"
    break;

  case 29: /* pattern: LEX_ENDFILE  */
#line 473 "awkgram.y"
          {
		yyvsp[0]->in_rule = rule = ENDFILE;
		yyvsp[0]->source_file = source;
		yyval = yyvsp[0];
	  }
#line 2296 "awkgram.c"
    break;

  case 30: /* action: l_brace statements r_brace opt_semi opt_nls  */
#line 482 "awkgram.y"
          {
		INSTRUCTION *ip = make_braced_statements(yyvsp[-4], yyvsp[-3], yyvsp[-2]);

		if (yyvsp[-2] != NULL && yyvsp[0] != NULL) {
			merge_comments(yyvsp[-2], yyvsp[0]);
			pending_comment = yyvsp[-2];
		} else if (yyvsp[-2] != NULL) {
			pending_comment = yyvsp[-2];
		} else if (yyvsp[0] != NULL) {
			pending_comment = yyvsp[0];
		}

		yyval = ip;
	  }
#line 2315 "awkgram.c"
    break;

  case 32: /* func_name: FUNC_CALL  */
#line 501 "awkgram.y"
          {
		const char *name = yyvsp[0]->lextok;
		char *qname = qualify_name(name, strlen(name));

		if (qname != name) {
			efree((void *)name);
			yyvsp[0]->lextok = qname;
		}
		yyval = yyvsp[0];
	  }
#line 2330 "awkgram.c"
    break;

  case 33: /* func_name: lex_builtin  */
#line 512 "awkgram.y"
          {
		yyerror(_("`%s' is a built-in function, it cannot be redefined"),
					tokstart);
		YYABORT;
	  }
#line 2340 "awkgram.c"
    break;

  case 34: /* func_name: '@' LEX_EVAL  */
#line 518 "awkgram.y"
          {
		yyval = yyvsp[0];
		at_seen--;
	  }
#line 2349 "awkgram.c"
    break;

  case 37: /* $@1: %empty  */
#line 530 "awkgram.y"
                                     { want_param_names = FUNC_HEADER; }
#line 2355 "awkgram.c"
    break;

  case 38: /* function_prologue: LEX_FUNCTION func_name '(' $@1 opt_param_list r_paren opt_nls  */
#line 531 "awkgram.y"
          {
		INSTRUCTION *func_comment = NULL;
		// Merge any comments found in the parameter list with those
		// following the function header, associate the whole shebang
		// with the function as one block comment.
		if (yyvsp[-2] != NULL && yyvsp[-2]->comment != NULL) {
			if (yyvsp[0] != NULL) {
				merge_comments(yyvsp[-2]->comment, yyvsp[0]);
			}
			func_comment = yyvsp[-2]->comment;
		} else if (yyvsp[0] != NULL) {
			func_comment = yyvsp[0];
		}

		yyvsp[-6]->source_file = source;
		yyvsp[-6]->comment = func_comment;
		if (install_function(yyvsp[-5]->lextok, yyvsp[-6], yyvsp[-2]) < 0)
			YYABORT;
		in_function = true;
		yyvsp[-5]->lextok = NULL;
		bcfree(yyvsp[-5]);
		/* $5 already free'd in install_function */
		yyval = yyvsp[-6];
		want_param_names = FUNC_BODY;
	  }
#line 2385 "awkgram.c"
    break;

  case 39: /* $@2: %empty  */
#line 564 "awkgram.y"
                { want_regexp = true; }
#line 2391 "awkgram.c"
    break;

  case 40: /* regexp: a_slash $@2 REGEXP  */
#line 566 "awkgram.y"
                {
		  NODE *n, *exp;
		  char *re;
		  size_t len;

		  re = yyvsp[0]->lextok;
		  yyvsp[0]->lextok = NULL;
		  len = strlen(re);
		  if (do_lint) {
			if (len == 0)
				lintwarn_ln(yyvsp[0]->source_line,
					_("regexp constant `//' looks like a C++ comment, but is not"));
			else if (re[0] == '*' && re[len-1] == '*')
				/* possible C comment */
				lintwarn_ln(yyvsp[0]->source_line,
					_("regexp constant `/%s/' looks like a C comment, but is not"), re);
		  }

		  exp = make_str_node(re, len, ALREADY_MALLOCED);
		  n = make_regnode(Node_regex, exp);
		  if (n == NULL) {
			unref(exp);
			YYABORT;
		  }
		  yyval = yyvsp[0];
		  yyval->opcode = Op_match_rec;
		  yyval->memory = n;
		}
#line 2424 "awkgram.c"
    break;

  case 41: /* typed_regexp: TYPED_REGEXP  */
#line 598 "awkgram.y"
                {
		  char *re;
		  size_t len;

		  re = yyvsp[0]->lextok;
		  yyvsp[0]->lextok = NULL;
		  len = strlen(re);

		  yyval = yyvsp[0];
		  yyval->opcode = Op_push_re;
		  yyval->memory = make_typed_regex(re, len);
		}
#line 2441 "awkgram.c"
    break;

  case 42: /* a_slash: '/'  */
#line 613 "awkgram.y"
          { bcfree(yyvsp[0]); }
#line 2447 "awkgram.c"
    break;

  case 44: /* statements: %empty  */
#line 619 "awkgram.y"
          { yyval = NULL; }
#line 2453 "awkgram.c"
    break;

  case 45: /* statements: statements statement  */
#line 621 "awkgram.y"
          {
		if (yyvsp[0] == NULL) {
			yyval = yyvsp[-1];
		} else {
			add_lint(yyvsp[0], LINT_no_effect);
			if (yyvsp[-1] == NULL) {
				yyval = yyvsp[0];
			} else {
				yyval = list_merge(yyvsp[-1], yyvsp[0]);
			}
		}

		if (trailing_comment != NULL) {
			yyval = list_append(yyval, trailing_comment);
			trailing_comment = NULL;
		}

		yyerrok;
	  }
#line 2477 "awkgram.c"
    break;

  case 46: /* statements: statements error  */
#line 641 "awkgram.y"
          {	yyval = NULL; }
#line 2483 "awkgram.c"
    break;

  case 47: /* statement_term: nls  */
#line 645 "awkgram.y"
                        { yyval = yyvsp[0]; }
#line 2489 "awkgram.c"
    break;

  case 48: /* statement_term: semi opt_nls  */
#line 646 "awkgram.y"
                        { yyval = yyvsp[0]; }
#line 2495 "awkgram.c"
    break;

  case 49: /* statement: semi opt_nls  */
#line 651 "awkgram.y"
          {
		if (yyvsp[0] != NULL) {
			INSTRUCTION *ip;

			merge_comments(yyvsp[0], NULL);
			ip = list_create(instruction(Op_no_op));
			yyval = list_append(ip, yyvsp[0]);
		} else
			yyval = NULL;
	  }
#line 2510 "awkgram.c"
    break;

  case 50: /* statement: l_brace statements r_brace  */
#line 662 "awkgram.y"
          {
		trailing_comment = yyvsp[0];	// NULL or comment
		yyval = make_braced_statements(yyvsp[-2], yyvsp[-1], yyvsp[0]);
	  }
#line 2519 "awkgram.c"
    break;

  case 51: /* statement: if_statement  */
#line 667 "awkgram.y"
          {
		if (do_pretty_print)
			yyval = list_prepend(yyvsp[0], instruction(Op_exec_count));
		else
			yyval = yyvsp[0];
 	  }
#line 2530 "awkgram.c"
    break;

  case 52: /* statement: LEX_SWITCH '(' exp r_paren opt_nls l_brace case_statements opt_nls r_brace  */
#line 674 "awkgram.y"
          {
		INSTRUCTION *dflt, *curr = NULL, *cexp, *cstmt;
		INSTRUCTION *ip, *nextc, *tbreak;
		const char **case_values = NULL;
		int maxcount = 128;
		int case_count = 0;
		int i;

		tbreak = instruction(Op_no_op);
		cstmt = list_create(tbreak);
		cexp = list_create(instruction(Op_pop));
		dflt = instruction(Op_jmp);
		dflt->target_jmp = tbreak;	/* if no case match and no explicit default */

		if (yyvsp[-2] != NULL) {
			curr = yyvsp[-2]->nexti;
			bcfree(yyvsp[-2]);	/* Op_list */
		}
		/*  else
			curr = NULL; */

		for (; curr != NULL; curr = nextc) {
			INSTRUCTION *caseexp = curr->case_exp;
			INSTRUCTION *casestmt = curr->case_stmt;

			nextc = curr->nexti;
			if (curr->opcode == Op_K_case) {
				if (caseexp->opcode == Op_push_i) {
					/* a constant scalar */
					char *caseval;
					caseval = force_string(caseexp->memory)->stptr;
					for (i = 0; i < case_count; i++) {
						if (strcmp(caseval, case_values[i]) == 0)
							error_ln(curr->source_line,
								_("duplicate case values in switch body: %s"), caseval);
					}

					if (case_values == NULL)
						emalloc(case_values, const char **, sizeof(char *) * maxcount);
					else if (case_count >= maxcount) {
						maxcount += 128;
						erealloc(case_values, const char **, sizeof(char*) * maxcount);
					}
					case_values[case_count++] = caseval;
				} else {
					/* match a constant regex against switch expression. */
					(curr + 1)->match_exp = true;
				}
				curr->stmt_start = casestmt->nexti;
				curr->stmt_end	= casestmt->lasti;
				(void) list_prepend(cexp, curr);
				(void) list_prepend(cexp, caseexp);
			} else {
				if (dflt->target_jmp != tbreak)
					error_ln(curr->source_line,
						_("duplicate `default' detected in switch body"));
				else
					dflt->target_jmp = casestmt->nexti;

				if (do_pretty_print) {
					curr->stmt_start = casestmt->nexti;
					curr->stmt_end = casestmt->lasti;
					(void) list_prepend(cexp, curr);
				} else
					bcfree(curr);
			}

			cstmt = list_merge(casestmt, cstmt);
		}

		if (case_values != NULL)
			efree(case_values);

		ip = yyvsp[-6];
		if (do_pretty_print) {
			// first merge comments
			INSTRUCTION *head_comment = NULL;

			if (yyvsp[-4] != NULL && yyvsp[-3] != NULL) {
				merge_comments(yyvsp[-4], yyvsp[-3]);
				head_comment = yyvsp[-4];
			} else if (yyvsp[-4] != NULL)
				head_comment = yyvsp[-4];
			else
				head_comment = yyvsp[-3];

			yyvsp[-8]->comment = head_comment;

			(void) list_prepend(ip, yyvsp[-8]);
			(void) list_prepend(ip, instruction(Op_exec_count));
			yyvsp[-8]->target_break = tbreak;
			(yyvsp[-8] + 1)->switch_start = cexp->nexti;
			(yyvsp[-8] + 1)->switch_end = cexp->lasti;
			(yyvsp[-8] + 1)->switch_end->comment = yyvsp[0];
		}
		/* else
			$1 is NULL */

		(void) list_append(cexp, dflt);
		(void) list_merge(ip, cexp);
		if (yyvsp[-1] != NULL)
			(void) list_append(cstmt, yyvsp[-1]);
		yyval = list_merge(ip, cstmt);

		break_allowed--;
		fix_break_continue(ip, tbreak, NULL);
	  }
#line 2642 "awkgram.c"
    break;

  case 53: /* statement: LEX_WHILE '(' exp r_paren opt_nls statement  */
#line 782 "awkgram.y"
          {
		/*
		 *    -----------------
		 * tc:
		 *         cond
		 *    -----------------
		 *    [Op_jmp_false tb   ]
		 *    -----------------
		 *         body
		 *    -----------------
		 *    [Op_jmp      tc    ]
		 * tb:[Op_no_op          ]
		 */

		INSTRUCTION *ip, *tbreak, *tcont;

		tbreak = instruction(Op_no_op);
		add_lint(yyvsp[-3], LINT_assign_in_cond);
		tcont = yyvsp[-3]->nexti;
		ip = list_append(yyvsp[-3], instruction(Op_jmp_false));
		ip->lasti->target_jmp = tbreak;

		if (do_pretty_print) {
			(void) list_append(ip, instruction(Op_exec_count));
			yyvsp[-5]->target_break = tbreak;
			yyvsp[-5]->target_continue = tcont;
			(yyvsp[-5] + 1)->while_body = ip->lasti;
			(void) list_prepend(ip, yyvsp[-5]);
		}
		/* else
			$1 is NULL */

		if (yyvsp[-1] != NULL) {
			if (yyvsp[0] == NULL)
				yyvsp[0] = list_create(instruction(Op_no_op));

			yyvsp[-1]->memory->comment_type = BLOCK_COMMENT;
			yyvsp[0] = list_prepend(yyvsp[0], yyvsp[-1]);
		}

		if (yyvsp[0] != NULL)
			(void) list_merge(ip, yyvsp[0]);
		(void) list_append(ip, instruction(Op_jmp));
		ip->lasti->target_jmp = tcont;
		yyval = list_append(ip, tbreak);

		break_allowed--;
		continue_allowed--;
		fix_break_continue(ip, tbreak, tcont);
	  }
#line 2697 "awkgram.c"
    break;

  case 54: /* statement: LEX_DO opt_nls statement LEX_WHILE '(' exp r_paren opt_nls  */
#line 833 "awkgram.y"
          {
		/*
		 *    -----------------
		 * z:
		 *         body
		 *    -----------------
		 * tc:
		 *         cond
		 *    -----------------
		 *    [Op_jmp_true | z  ]
		 * tb:[Op_no_op         ]
		 */

		INSTRUCTION *ip, *tbreak, *tcont;

		tbreak = instruction(Op_no_op);
		tcont = yyvsp[-2]->nexti;
		add_lint(yyvsp[-2], LINT_assign_in_cond);
		if (yyvsp[-5] != NULL)
			ip = list_merge(yyvsp[-5], yyvsp[-2]);
		else
			ip = list_prepend(yyvsp[-2], instruction(Op_no_op));

		if (yyvsp[-6] != NULL)
			(void) list_prepend(ip, yyvsp[-6]);

		if (do_pretty_print)
			(void) list_prepend(ip, instruction(Op_exec_count));

		(void) list_append(ip, instruction(Op_jmp_true));
		ip->lasti->target_jmp = ip->nexti;
		yyval = list_append(ip, tbreak);

		break_allowed--;
		continue_allowed--;
		fix_break_continue(ip, tbreak, tcont);

		if (do_pretty_print) {
			yyvsp[-7]->target_break = tbreak;
			yyvsp[-7]->target_continue = tcont;
			(yyvsp[-7] + 1)->doloop_cond = tcont;
			yyval = list_prepend(ip, yyvsp[-7]);
			bcfree(yyvsp[-4]);
			if (yyvsp[0] != NULL)
				yyvsp[-7]->comment = yyvsp[0];
		}
		/* else
			$1 and $4 are NULLs */
	  }
#line 2751 "awkgram.c"
    break;

  case 55: /* statement: LEX_FOR '(' NAME LEX_IN simple_variable r_paren opt_nls statement  */
#line 883 "awkgram.y"
          {
		INSTRUCTION *ip;
		char *var_name = yyvsp[-5]->lextok;

		if (yyvsp[0] != NULL
				&& yyvsp[0]->lasti->opcode == Op_K_delete
				&& yyvsp[0]->lasti->expr_count == 1
				&& yyvsp[0]->nexti->opcode == Op_push
				&& (yyvsp[0]->nexti->memory->type != Node_var || !(yyvsp[0]->nexti->memory->var_update))
				&& strcmp(yyvsp[0]->nexti->memory->vname, var_name) == 0
		) {

		/*
		 * Efficiency hack.  Recognize the special case of
		 *
		 * 	for (iggy in foo)
		 * 		delete foo[iggy]
		 *
		 * and treat it as if it were
		 *
		 * 	delete foo
		 *
		 * Check that the body is a `delete a[i]' statement,
		 * and that both the loop var and array names match.
		 */
			NODE *arr = NULL;

			ip = yyvsp[0]->nexti->nexti;
			if (yyvsp[-3]->nexti->opcode == Op_push && yyvsp[-3]->lasti == yyvsp[-3]->nexti)
				arr = yyvsp[-3]->nexti->memory;
			if (arr != NULL
					&& ip->opcode == Op_no_op
					&& ip->nexti->opcode == Op_push_array
					&& strcmp(ip->nexti->memory->vname, arr->vname) == 0
					&& ip->nexti->nexti == yyvsp[0]->lasti
			) {
				(void) make_assignable(yyvsp[0]->nexti);
				yyvsp[0]->lasti->opcode = Op_K_delete_loop;
				yyvsp[0]->lasti->expr_count = 0;
				if (yyvsp[-7] != NULL)
					bcfree(yyvsp[-7]);
				efree(var_name);
				bcfree(yyvsp[-5]);
				bcfree(yyvsp[-4]);
				bcfree(yyvsp[-3]);
				if (yyvsp[-1] != NULL) {
					merge_comments(yyvsp[-1], NULL);
					yyvsp[0] = list_prepend(yyvsp[0], yyvsp[-1]);
				}
				yyval = yyvsp[0];
			} else
				goto regular_loop;
		} else {
			INSTRUCTION *tbreak, *tcont;

			/*    [ Op_push_array a       ]
			 *    [ Op_arrayfor_init | ib ]
			 * ic:[ Op_arrayfor_incr | ib ]
			 *    [ Op_var_assign if any  ]
			 *
			 *              body
			 *
			 *    [Op_jmp | ic            ]
			 * ib:[Op_arrayfor_final      ]
			 */
regular_loop:
			ip = yyvsp[-3];
			ip->nexti->opcode = Op_push_array;

			tbreak = instruction(Op_arrayfor_final);
			yyvsp[-4]->opcode = Op_arrayfor_incr;
			yyvsp[-4]->array_var = variable(yyvsp[-5]->source_line, var_name, Node_var);
			yyvsp[-4]->target_jmp = tbreak;
			tcont = yyvsp[-4];
			yyvsp[-5]->opcode = Op_arrayfor_init;
			yyvsp[-5]->target_jmp = tbreak;
			(void) list_append(ip, yyvsp[-5]);

			if (do_pretty_print) {
				yyvsp[-7]->opcode = Op_K_arrayfor;
				yyvsp[-7]->target_continue = tcont;
				yyvsp[-7]->target_break = tbreak;
				(void) list_append(ip, yyvsp[-7]);
			}
			/* else
				$1 is NULL */

			/* add update_FOO instruction if necessary */
			if (yyvsp[-4]->array_var->type == Node_var && yyvsp[-4]->array_var->var_update) {
				(void) list_append(ip, instruction(Op_var_update));
				ip->lasti->update_var = yyvsp[-4]->array_var->var_update;
			}
			(void) list_append(ip, yyvsp[-4]);

			/* add set_FOO instruction if necessary */
			if (yyvsp[-4]->array_var->type == Node_var && yyvsp[-4]->array_var->var_assign) {
				(void) list_append(ip, instruction(Op_var_assign));
				ip->lasti->assign_var = yyvsp[-4]->array_var->var_assign;
			}

			if (do_pretty_print) {
				(void) list_append(ip, instruction(Op_exec_count));
				(yyvsp[-7] + 1)->forloop_cond = yyvsp[-4];
				(yyvsp[-7] + 1)->forloop_body = ip->lasti;
			}

			if (yyvsp[-1] != NULL)
				merge_comments(yyvsp[-1], NULL);

			if (yyvsp[0] != NULL) {
				if (yyvsp[-1] != NULL)
					yyvsp[0] = list_prepend(yyvsp[0], yyvsp[-1]);
				(void) list_merge(ip, yyvsp[0]);
			} else if (yyvsp[-1] != NULL)
				(void) list_append(ip, yyvsp[-1]);

			(void) list_append(ip, instruction(Op_jmp));
			ip->lasti->target_jmp = yyvsp[-4];
			yyval = list_append(ip, tbreak);
			fix_break_continue(ip, tbreak, tcont);
		}

		break_allowed--;
		continue_allowed--;
	  }
#line 2881 "awkgram.c"
    break;

  case 56: /* statement: LEX_FOR '(' opt_simple_stmt semi opt_nls exp semi opt_nls opt_simple_stmt r_paren opt_nls statement  */
#line 1009 "awkgram.y"
          {
		if (yyvsp[-7] != NULL) {
			merge_comments(yyvsp[-7], NULL);
			yyvsp[-11]->comment = yyvsp[-7];
		}
		if (yyvsp[-4] != NULL) {
			merge_comments(yyvsp[-4], NULL);
			if (yyvsp[-11]->comment == NULL) {
				yyvsp[-4]->memory->comment_type = FOR_COMMENT;
				yyvsp[-11]->comment = yyvsp[-4];
			} else
				yyvsp[-11]->comment->comment = yyvsp[-4];
		}
		if (yyvsp[-1] != NULL)
			yyvsp[0] = list_prepend(yyvsp[0], yyvsp[-1]);
		add_lint(yyvsp[-6], LINT_assign_in_cond);
		yyval = mk_for_loop(yyvsp[-11], yyvsp[-9], yyvsp[-6], yyvsp[-3], yyvsp[0]);

		break_allowed--;
		continue_allowed--;
	  }
#line 2907 "awkgram.c"
    break;

  case 57: /* statement: LEX_FOR '(' opt_simple_stmt semi opt_nls semi opt_nls opt_simple_stmt r_paren opt_nls statement  */
#line 1031 "awkgram.y"
          {
		if (yyvsp[-6] != NULL) {
			merge_comments(yyvsp[-6], NULL);
			yyvsp[-10]->comment = yyvsp[-6];
		}
		if (yyvsp[-4] != NULL) {
			merge_comments(yyvsp[-4], NULL);
			if (yyvsp[-10]->comment == NULL) {
				yyvsp[-4]->memory->comment_type = FOR_COMMENT;
				yyvsp[-10]->comment = yyvsp[-4];
			} else
				yyvsp[-10]->comment->comment = yyvsp[-4];
		}
		if (yyvsp[-1] != NULL)
			yyvsp[0] = list_prepend(yyvsp[0], yyvsp[-1]);
		yyval = mk_for_loop(yyvsp[-10], yyvsp[-8], (INSTRUCTION *) NULL, yyvsp[-3], yyvsp[0]);

		break_allowed--;
		continue_allowed--;
	  }
#line 2932 "awkgram.c"
    break;

  case 58: /* statement: non_compound_stmt  */
#line 1052 "awkgram.y"
          {
		if (do_pretty_print)
			yyval = list_prepend(yyvsp[0], instruction(Op_exec_count));
		else
			yyval = yyvsp[0];
	  }
#line 2943 "awkgram.c"
    break;

  case 59: /* non_compound_stmt: LEX_BREAK statement_term  */
#line 1062 "awkgram.y"
          {
		if (! break_allowed)
			error_ln(yyvsp[-1]->source_line,
				_("`break' is not allowed outside a loop or switch"));
		yyvsp[-1]->target_jmp = NULL;
		yyval = list_create(yyvsp[-1]);
		if (yyvsp[0] != NULL)
			yyval = list_append(yyval, yyvsp[0]);
	  }
#line 2957 "awkgram.c"
    break;

  case 60: /* non_compound_stmt: LEX_CONTINUE statement_term  */
#line 1072 "awkgram.y"
          {
		if (! continue_allowed)
			error_ln(yyvsp[-1]->source_line,
				_("`continue' is not allowed outside a loop"));
		yyvsp[-1]->target_jmp = NULL;
		yyval = list_create(yyvsp[-1]);
		if (yyvsp[0] != NULL)
			yyval = list_append(yyval, yyvsp[0]);
	  }
#line 2971 "awkgram.c"
    break;

  case 61: /* non_compound_stmt: LEX_NEXT statement_term  */
#line 1082 "awkgram.y"
          {
		/* if inside function (rule = 0), resolve context at run-time */
		if (rule && rule != Rule)
			error_ln(yyvsp[-1]->source_line,
				_("`next' used in %s action"), ruletab[rule]);
		yyvsp[-1]->target_jmp = ip_rec;
		yyval = list_create(yyvsp[-1]);
		if (yyvsp[0] != NULL)
			yyval = list_append(yyval, yyvsp[0]);
	  }
#line 2986 "awkgram.c"
    break;

  case 62: /* non_compound_stmt: LEX_NEXTFILE statement_term  */
#line 1093 "awkgram.y"
          {
		/* if inside function (rule = 0), resolve context at run-time */
		if (rule == BEGIN || rule == END || rule == ENDFILE)
			error_ln(yyvsp[-1]->source_line,
				_("`nextfile' used in %s action"), ruletab[rule]);

		yyvsp[-1]->target_newfile = ip_newfile;
		yyvsp[-1]->target_endfile = ip_endfile;
		yyval = list_create(yyvsp[-1]);
		if (yyvsp[0] != NULL)
			yyval = list_append(yyval, yyvsp[0]);
	  }
#line 3003 "awkgram.c"
    break;

  case 63: /* non_compound_stmt: LEX_EXIT opt_exp statement_term  */
#line 1106 "awkgram.y"
          {
		/* Initialize the two possible jump targets, the actual target
		 * is resolved at run-time.
		 */
		yyvsp[-2]->target_end = ip_end;	/* first instruction in end_block */
		yyvsp[-2]->target_atexit = ip_atexit;	/* cleanup and go home */

		if (yyvsp[-1] == NULL) {
			yyval = list_create(yyvsp[-2]);
			(void) list_prepend(yyval, instruction(Op_push_i));
			yyval->nexti->memory = dupnode(Nnull_string);
		} else
			yyval = list_append(yyvsp[-1], yyvsp[-2]);
		if (yyvsp[0] != NULL)
			yyval = list_append(yyval, yyvsp[0]);
	  }
#line 3024 "awkgram.c"
    break;

  case 64: /* $@3: %empty  */
#line 1123 "awkgram.y"
          {
		if (! in_function)
			yyerror(_("`return' used outside function context"));
	  }
#line 3033 "awkgram.c"
    break;

  case 65: /* non_compound_stmt: LEX_RETURN $@3 opt_fcall_exp statement_term  */
#line 1126 "awkgram.y"
                                         {
		if (called_from_eval)
			yyvsp[-3]->opcode = Op_K_return_from_eval;

		if (yyvsp[-1] == NULL) {
			yyval = list_create(yyvsp[-3]);
			(void) list_prepend(yyval, instruction(Op_push_i));
			yyval->nexti->memory = dupnode(Nnull_string);
		} else
			yyval = list_append(yyvsp[-1], yyvsp[-3]);
		if (yyvsp[0] != NULL)
			yyval = list_append(yyval, yyvsp[0]);
	  }
#line 3051 "awkgram.c"
    break;

  case 66: /* non_compound_stmt: simple_stmt statement_term  */
#line 1140 "awkgram.y"
          {
		if (yyvsp[0] != NULL)
			yyval = list_append(yyvsp[-1], yyvsp[0]);
		else
			yyval = yyvsp[-1];
	  }
#line 3062 "awkgram.c"
    break;

  case 67: /* $@4: %empty  */
#line 1157 "awkgram.y"
                { in_print = true; in_parens = 0; }
#line 3068 "awkgram.c"
    break;

  case 68: /* simple_stmt: print $@4 print_expression_list output_redir  */
#line 1158 "awkgram.y"
          {
		/*
		 * Optimization: plain `print' has no expression list, so $3 is null.
		 * If $3 is NULL or is a bytecode list for $0 use Op_K_print_rec,
		 * which is faster for these two cases.
		 */

		if (do_optimize && yyvsp[-3]->opcode == Op_K_print &&
			(yyvsp[-1] == NULL
				|| (yyvsp[-1]->lasti->opcode == Op_field_spec
					&& yyvsp[-1]->nexti->nexti->nexti == yyvsp[-1]->lasti
					&& yyvsp[-1]->nexti->nexti->opcode == Op_push_i
					&& yyvsp[-1]->nexti->nexti->memory->type == Node_val)
			)
		) {
			static bool warned = false;
			/*   -----------------
			 *      output_redir
			 *    [ redirect exp ]
			 *   -----------------
			 *     expression_list
			 *   ------------------
			 *    [Op_K_print_rec | NULL | redir_type | expr_count]
			 */

			if (yyvsp[-1] != NULL) {
				NODE *n = yyvsp[-1]->nexti->nexti->memory;

				if ((n->flags & (STRING|STRCUR)) != 0 || ! is_zero(n))
					goto regular_print;

				bcfree(yyvsp[-1]->lasti);			/* Op_field_spec */
				unref(n);				/* Node_val */
				bcfree(yyvsp[-1]->nexti->nexti);		/* Op_push_i */
				bcfree(yyvsp[-1]->nexti);			/* Op_list */
				bcfree(yyvsp[-1]);				/* Op_list */
			} else {
				if (do_lint && (rule == BEGIN || rule == END) && ! warned) {
					warned = true;
					lintwarn_ln(yyvsp[-3]->source_line,
		_("plain `print' in BEGIN or END rule should probably be `print \"\"'"));
				}
			}

			yyvsp[-3]->expr_count = 0;
			yyvsp[-3]->opcode = Op_K_print_rec;
			if (yyvsp[0] == NULL) {    /* no redircetion */
				yyvsp[-3]->redir_type = redirect_none;
				yyval = list_create(yyvsp[-3]);
			} else {
				INSTRUCTION *ip;
				ip = yyvsp[0]->nexti;
				yyvsp[-3]->redir_type = ip->redir_type;
				yyvsp[0]->nexti = ip->nexti;
				bcfree(ip);
				yyval = list_append(yyvsp[0], yyvsp[-3]);
			}
		} else {
			/*   -----------------
			 *    [ output_redir    ]
			 *    [ redirect exp    ]
			 *   -----------------
			 *    [ expression_list ]
			 *   ------------------
			 *    [$1 | NULL | redir_type | expr_count]
			 *
			 */
regular_print:
			if (yyvsp[0] == NULL) {		/* no redirection */
				if (yyvsp[-1] == NULL)	{	/* print/printf without arg */
					yyvsp[-3]->expr_count = 0;
					if (yyvsp[-3]->opcode == Op_K_print)
						yyvsp[-3]->opcode = Op_K_print_rec;
					yyvsp[-3]->redir_type = redirect_none;
					yyval = list_create(yyvsp[-3]);
				} else {
					INSTRUCTION *t = yyvsp[-1];
					yyvsp[-3]->expr_count = count_expressions(&t, false);
					yyvsp[-3]->redir_type = redirect_none;
					yyval = list_append(t, yyvsp[-3]);
				}
			} else {
				INSTRUCTION *ip;
				ip = yyvsp[0]->nexti;
				yyvsp[-3]->redir_type = ip->redir_type;
				yyvsp[0]->nexti = ip->nexti;
				bcfree(ip);
				if (yyvsp[-1] == NULL) {
					yyvsp[-3]->expr_count = 0;
					if (yyvsp[-3]->opcode == Op_K_print)
						yyvsp[-3]->opcode = Op_K_print_rec;
					yyval = list_append(yyvsp[0], yyvsp[-3]);
				} else {
					INSTRUCTION *t = yyvsp[-1];
					yyvsp[-3]->expr_count = count_expressions(&t, false);
					yyval = list_append(list_merge(yyvsp[0], t), yyvsp[-3]);
				}
			}
		}
	  }
#line 3173 "awkgram.c"
    break;

  case 69: /* $@5: %empty  */
#line 1259 "awkgram.y"
                          { sub_counter = 0; }
#line 3179 "awkgram.c"
    break;

  case 70: /* simple_stmt: LEX_DELETE NAME $@5 delete_subscript_list  */
#line 1260 "awkgram.y"
          {
		char *arr = yyvsp[-2]->lextok;

		yyvsp[-2]->opcode = Op_push_array;
		yyvsp[-2]->memory = variable(yyvsp[-2]->source_line, arr, Node_var_new);

		if (! do_posix && ! do_traditional) {
			if (yyvsp[-2]->memory == symbol_table)
				fatal(_("`delete' is not allowed with SYMTAB"));
			else if (yyvsp[-2]->memory == func_table)
				fatal(_("`delete' is not allowed with FUNCTAB"));
		}

		if (yyvsp[0] == NULL) {
			/*
			 * As of September 2012, POSIX has added support
			 * for `delete array'. See:
			 * http://austingroupbugs.net/view.php?id=544
			 *
			 * Thanks to Nathan Weeks for the initiative.
			 *
			 * Thus we no longer warn or check do_posix.
			 * Also, since BWK awk supports it, we don't have to
			 * check do_traditional either.
			 */
			yyvsp[-3]->expr_count = 0;
			yyval = list_append(list_create(yyvsp[-2]), yyvsp[-3]);
		} else {
			yyvsp[-3]->expr_count = sub_counter;
			yyval = list_append(list_append(yyvsp[0], yyvsp[-2]), yyvsp[-3]);
		}
	  }
#line 3216 "awkgram.c"
    break;

  case 71: /* simple_stmt: LEX_DELETE '(' NAME ')'  */
#line 1297 "awkgram.y"
          {
		static bool warned = false;
		char *arr = yyvsp[-1]->lextok;

		if (do_lint && ! warned) {
			warned = true;
			lintwarn_ln(yyvsp[-3]->source_line,
				_("`delete(array)' is a non-portable tawk extension"));
		}
		if (do_traditional) {
			error_ln(yyvsp[-3]->source_line,
				_("`delete(array)' is a non-portable tawk extension"));
		}
		yyvsp[-1]->memory = variable(yyvsp[-1]->source_line, arr, Node_var_new);
		yyvsp[-1]->opcode = Op_push_array;
		yyvsp[-3]->expr_count = 0;
		yyval = list_append(list_create(yyvsp[-1]), yyvsp[-3]);

		if (! do_posix && ! do_traditional) {
			if (yyvsp[-1]->memory == symbol_table)
				fatal(_("`delete' is not allowed with SYMTAB"));
			else if (yyvsp[-1]->memory == func_table)
				fatal(_("`delete' is not allowed with FUNCTAB"));
		}
	  }
#line 3246 "awkgram.c"
    break;

  case 72: /* simple_stmt: exp  */
#line 1323 "awkgram.y"
          {
		yyval = optimize_assignment(yyvsp[0]);
	  }
#line 3254 "awkgram.c"
    break;

  case 73: /* opt_simple_stmt: %empty  */
#line 1330 "awkgram.y"
          { yyval = NULL; }
#line 3260 "awkgram.c"
    break;

  case 74: /* opt_simple_stmt: simple_stmt  */
#line 1332 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3266 "awkgram.c"
    break;

  case 75: /* case_statements: %empty  */
#line 1337 "awkgram.y"
          { yyval = NULL; }
#line 3272 "awkgram.c"
    break;

  case 76: /* case_statements: case_statements case_statement  */
#line 1339 "awkgram.y"
          {
		if (yyvsp[-1] == NULL)
			yyval = list_create(yyvsp[0]);
		else
			yyval = list_prepend(yyvsp[-1], yyvsp[0]);
	  }
#line 3283 "awkgram.c"
    break;

  case 77: /* case_statements: case_statements error  */
#line 1346 "awkgram.y"
          { yyval = NULL; }
#line 3289 "awkgram.c"
    break;

  case 78: /* case_statement: LEX_CASE case_value colon opt_nls statements  */
#line 1351 "awkgram.y"
          {
		INSTRUCTION *casestmt = yyvsp[0];
		if (yyvsp[0] == NULL)
			casestmt = list_create(instruction(Op_no_op));
		if (do_pretty_print)
			(void) list_prepend(casestmt, instruction(Op_exec_count));
		yyvsp[-4]->case_exp = yyvsp[-3];
		yyvsp[-4]->case_stmt = casestmt;
		yyvsp[-4]->comment = yyvsp[-1];
		bcfree(yyvsp[-2]);
		yyval = yyvsp[-4];
	  }
#line 3306 "awkgram.c"
    break;

  case 79: /* case_statement: LEX_DEFAULT colon opt_nls statements  */
#line 1364 "awkgram.y"
          {
		INSTRUCTION *casestmt = yyvsp[0];
		if (yyvsp[0] == NULL)
			casestmt = list_create(instruction(Op_no_op));
		if (do_pretty_print)
			(void) list_prepend(casestmt, instruction(Op_exec_count));
		bcfree(yyvsp[-2]);
		yyvsp[-3]->case_stmt = casestmt;
		yyvsp[-3]->comment = yyvsp[-1];
		yyval = yyvsp[-3];
	  }
#line 3322 "awkgram.c"
    break;

  case 80: /* case_value: YNUMBER  */
#line 1379 "awkgram.y"
          {	yyval = yyvsp[0]; }
#line 3328 "awkgram.c"
    break;

  case 81: /* case_value: '-' YNUMBER  */
#line 1381 "awkgram.y"
          {
		NODE *n = yyvsp[0]->memory;
		(void) force_number(n);
		negate_num(n);
		bcfree(yyvsp[-1]);
		yyval = yyvsp[0];
	  }
#line 3340 "awkgram.c"
    break;

  case 82: /* case_value: '+' YNUMBER  */
#line 1389 "awkgram.y"
          {
		NODE *n = yyvsp[0]->lasti->memory;
		bcfree(yyvsp[-1]);
		add_sign_to_num(n, '+');
		yyval = yyvsp[0];
	  }
#line 3351 "awkgram.c"
    break;

  case 83: /* case_value: YSTRING  */
#line 1396 "awkgram.y"
          {	yyval = yyvsp[0]; }
#line 3357 "awkgram.c"
    break;

  case 84: /* case_value: regexp  */
#line 1398 "awkgram.y"
          {
		if (yyvsp[0]->memory->type == Node_regex)
			yyvsp[0]->opcode = Op_push_re;
		else
			yyvsp[0]->opcode = Op_push;
		yyval = yyvsp[0];
	  }
#line 3369 "awkgram.c"
    break;

  case 85: /* case_value: typed_regexp  */
#line 1406 "awkgram.y"
          {
		assert((yyvsp[0]->memory->flags & REGEX) == REGEX);
		yyvsp[0]->opcode = Op_push_re;
		yyval = yyvsp[0];
	  }
#line 3379 "awkgram.c"
    break;

  case 86: /* print: LEX_PRINT  */
#line 1415 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3385 "awkgram.c"
    break;

  case 87: /* print: LEX_PRINTF  */
#line 1417 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3391 "awkgram.c"
    break;

  case 89: /* print_expression_list: '(' expression_list r_paren  */
#line 1427 "awkgram.y"
          {
		yyval = yyvsp[-1];
	  }
#line 3399 "awkgram.c"
    break;

  case 90: /* output_redir: %empty  */
#line 1434 "awkgram.y"
          {
		in_print = false;
		in_parens = 0;
		yyval = NULL;
	  }
#line 3409 "awkgram.c"
    break;

  case 91: /* $@6: %empty  */
#line 1439 "awkgram.y"
                 { in_print = false; in_parens = 0; }
#line 3415 "awkgram.c"
    break;

  case 92: /* output_redir: IO_OUT $@6 common_exp  */
#line 1440 "awkgram.y"
          {
		if (yyvsp[-2]->redir_type == redirect_twoway
		    	&& yyvsp[0]->lasti->opcode == Op_K_getline_redir
		   	 	&& yyvsp[0]->lasti->redir_type == redirect_twoway)
			yyerror(_("multistage two-way pipelines don't work"));
		if (do_lint && yyvsp[-2]->redir_type == redirect_output && yyvsp[0]->lasti->opcode == Op_concat)
			lintwarn(_("concatenation as I/O `>' redirection target is ambiguous"));
		yyval = list_prepend(yyvsp[0], yyvsp[-2]);
	  }
#line 3429 "awkgram.c"
    break;

  case 93: /* if_statement: LEX_IF '(' exp r_paren opt_nls statement  */
#line 1453 "awkgram.y"
          {
		if (yyvsp[-1] != NULL)
			yyvsp[-5]->comment = yyvsp[-1];
		add_lint(yyvsp[-3], LINT_assign_in_cond);
		yyval = mk_condition(yyvsp[-3], yyvsp[-5], yyvsp[0], NULL, NULL);
	  }
#line 3440 "awkgram.c"
    break;

  case 94: /* if_statement: LEX_IF '(' exp r_paren opt_nls statement LEX_ELSE opt_nls statement  */
#line 1461 "awkgram.y"
          {
		if (yyvsp[-4] != NULL)
			yyvsp[-8]->comment = yyvsp[-4];
		if (yyvsp[-1] != NULL)
			yyvsp[-2]->comment = yyvsp[-1];
		add_lint(yyvsp[-6], LINT_assign_in_cond);
		yyval = mk_condition(yyvsp[-6], yyvsp[-8], yyvsp[-3], yyvsp[-2], yyvsp[0]);
	  }
#line 3453 "awkgram.c"
    break;

  case 95: /* nls: NEWLINE  */
#line 1473 "awkgram.y"
          {
		yyval = yyvsp[0];
	  }
#line 3461 "awkgram.c"
    break;

  case 96: /* nls: nls NEWLINE  */
#line 1477 "awkgram.y"
          {
		if (yyvsp[-1] != NULL && yyvsp[0] != NULL) {
			if (yyvsp[-1]->memory->comment_type == EOL_COMMENT) {
				assert(yyvsp[0]->memory->comment_type == BLOCK_COMMENT);
				yyvsp[-1]->comment = yyvsp[0];	// chain them
			} else {
				merge_comments(yyvsp[-1], yyvsp[0]);
			}

			yyval = yyvsp[-1];
		} else if (yyvsp[-1] != NULL) {
			yyval = yyvsp[-1];
		} else if (yyvsp[0] != NULL) {
			yyval = yyvsp[0];
		} else
			yyval = NULL;
	  }
#line 3483 "awkgram.c"
    break;

  case 97: /* opt_nls: %empty  */
#line 1498 "awkgram.y"
          { yyval = NULL; }
#line 3489 "awkgram.c"
    break;

  case 98: /* opt_nls: nls  */
#line 1500 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3495 "awkgram.c"
    break;

  case 99: /* input_redir: %empty  */
#line 1505 "awkgram.y"
          { yyval = NULL; }
#line 3501 "awkgram.c"
    break;

  case 100: /* input_redir: '<' simp_exp  */
#line 1507 "awkgram.y"
          {
		bcfree(yyvsp[-1]);
		yyval = yyvsp[0];
	  }
#line 3510 "awkgram.c"
    break;

  case 101: /* opt_param_list: %empty  */
#line 1515 "awkgram.y"
          { yyval = NULL; }
#line 3516 "awkgram.c"
    break;

  case 102: /* opt_param_list: param_list  */
#line 1517 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3522 "awkgram.c"
    break;

  case 103: /* param_list: NAME  */
#line 1522 "awkgram.y"
          {
		yyvsp[0]->param_count = 0;
		yyval = list_create(yyvsp[0]);
	  }
#line 3531 "awkgram.c"
    break;

  case 104: /* param_list: param_list comma NAME  */
#line 1527 "awkgram.y"
          {
		if (yyvsp[-2] != NULL && yyvsp[0] != NULL) {
			yyvsp[0]->param_count = yyvsp[-2]->lasti->param_count + 1;
			yyval = list_append(yyvsp[-2], yyvsp[0]);
			yyerrok;

			// newlines are allowed after commas, catch any comments
			if (yyvsp[-1] != NULL) {
				if (yyvsp[-2]->comment != NULL)
					merge_comments(yyvsp[-2]->comment, yyvsp[-1]);
				else
					yyvsp[-2]->comment = yyvsp[-1];
			}
		} else
			yyval = NULL;
	  }
#line 3552 "awkgram.c"
    break;

  case 105: /* param_list: error  */
#line 1544 "awkgram.y"
          { yyval = NULL; }
#line 3558 "awkgram.c"
    break;

  case 106: /* param_list: param_list error  */
#line 1546 "awkgram.y"
          { yyval = yyvsp[-1]; }
#line 3564 "awkgram.c"
    break;

  case 107: /* param_list: param_list comma error  */
#line 1548 "awkgram.y"
          { yyval = yyvsp[-2]; }
#line 3570 "awkgram.c"
    break;

  case 108: /* opt_exp: %empty  */
#line 1554 "awkgram.y"
          { yyval = NULL; }
#line 3576 "awkgram.c"
    break;

  case 109: /* opt_exp: exp  */
#line 1556 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3582 "awkgram.c"
    break;

  case 110: /* opt_expression_list: %empty  */
#line 1561 "awkgram.y"
          { yyval = NULL; }
#line 3588 "awkgram.c"
    break;

  case 111: /* opt_expression_list: expression_list  */
#line 1563 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3594 "awkgram.c"
    break;

  case 112: /* expression_list: exp  */
#line 1568 "awkgram.y"
          {	yyval = mk_expression_list(NULL, yyvsp[0]); }
#line 3600 "awkgram.c"
    break;

  case 113: /* expression_list: expression_list comma exp  */
#line 1570 "awkgram.y"
          {
		if (yyvsp[-1] != NULL)
			yyvsp[-2]->lasti->comment = yyvsp[-1];
		yyval = mk_expression_list(yyvsp[-2], yyvsp[0]);
		yyerrok;
	  }
#line 3611 "awkgram.c"
    break;

  case 114: /* expression_list: error  */
#line 1577 "awkgram.y"
          { yyval = NULL; }
#line 3617 "awkgram.c"
    break;

  case 115: /* expression_list: expression_list error  */
#line 1579 "awkgram.y"
          {
		/*
		 * Returning the expression list instead of NULL lets
		 * snode get a list of arguments that it can count.
		 */
		yyval = yyvsp[-1];
	  }
#line 3629 "awkgram.c"
    break;

  case 116: /* expression_list: expression_list error exp  */
#line 1587 "awkgram.y"
          {
		/* Ditto */
		yyval = mk_expression_list(yyvsp[-2], yyvsp[0]);
	  }
#line 3638 "awkgram.c"
    break;

  case 117: /* expression_list: expression_list comma error  */
#line 1592 "awkgram.y"
          {
		/* Ditto */
		if (yyvsp[-1] != NULL)
			yyvsp[-2]->lasti->comment = yyvsp[-1];
		yyval = yyvsp[-2];
	  }
#line 3649 "awkgram.c"
    break;

  case 118: /* opt_fcall_expression_list: %empty  */
#line 1602 "awkgram.y"
          { yyval = NULL; }
#line 3655 "awkgram.c"
    break;

  case 119: /* opt_fcall_expression_list: fcall_expression_list  */
#line 1604 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3661 "awkgram.c"
    break;

  case 120: /* fcall_expression_list: fcall_exp  */
#line 1609 "awkgram.y"
          {	yyval = mk_expression_list(NULL, yyvsp[0]); }
#line 3667 "awkgram.c"
    break;

  case 121: /* fcall_expression_list: fcall_expression_list comma fcall_exp  */
#line 1611 "awkgram.y"
          {
		if (yyvsp[-1] != NULL)
			yyvsp[-2]->lasti->comment = yyvsp[-1];
		yyval = mk_expression_list(yyvsp[-2], yyvsp[0]);
		yyerrok;
	  }
#line 3678 "awkgram.c"
    break;

  case 122: /* fcall_expression_list: error  */
#line 1618 "awkgram.y"
          { yyval = NULL; }
#line 3684 "awkgram.c"
    break;

  case 123: /* fcall_expression_list: fcall_expression_list error  */
#line 1620 "awkgram.y"
          {
		/*
		 * Returning the expression list instead of NULL lets
		 * snode get a list of arguments that it can count.
		 */
		yyval = yyvsp[-1];
	  }
#line 3696 "awkgram.c"
    break;

  case 124: /* fcall_expression_list: fcall_expression_list error fcall_exp  */
#line 1628 "awkgram.y"
          {
		/* Ditto */
		yyval = mk_expression_list(yyvsp[-2], yyvsp[0]);
	  }
#line 3705 "awkgram.c"
    break;

  case 125: /* fcall_expression_list: fcall_expression_list comma error  */
#line 1633 "awkgram.y"
          {
		/* Ditto */
		if (yyvsp[-1] != NULL)
			yyvsp[-2]->comment = yyvsp[-1];
		yyval = yyvsp[-2];
	  }
#line 3716 "awkgram.c"
    break;

  case 126: /* fcall_exp: exp  */
#line 1642 "awkgram.y"
              { yyval = yyvsp[0]; }
#line 3722 "awkgram.c"
    break;

  case 127: /* fcall_exp: typed_regexp  */
#line 1643 "awkgram.y"
                       { yyval = list_create(yyvsp[0]); }
#line 3728 "awkgram.c"
    break;

  case 128: /* opt_fcall_exp: %empty  */
#line 1648 "awkgram.y"
          { yyval = NULL; }
#line 3734 "awkgram.c"
    break;

  case 129: /* opt_fcall_exp: fcall_exp  */
#line 1649 "awkgram.y"
                    { yyval = yyvsp[0]; }
#line 3740 "awkgram.c"
    break;

  case 130: /* exp: variable assign_operator exp  */
#line 1655 "awkgram.y"
          {
		if (do_lint && yyvsp[0]->lasti->opcode == Op_match_rec)
			lintwarn_ln(yyvsp[-1]->source_line,
				_("regular expression on right of assignment"));
		yyval = mk_assignment(yyvsp[-2], yyvsp[0], yyvsp[-1]);
	  }
#line 3751 "awkgram.c"
    break;

  case 131: /* exp: variable ASSIGN typed_regexp  */
#line 1662 "awkgram.y"
          {
		yyval = mk_assignment(yyvsp[-2], list_create(yyvsp[0]), yyvsp[-1]);
	  }
#line 3759 "awkgram.c"
    break;

  case 132: /* exp: exp LEX_AND exp  */
#line 1666 "awkgram.y"
          {	yyval = mk_boolean(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3765 "awkgram.c"
    break;

  case 133: /* exp: exp LEX_OR exp  */
#line 1668 "awkgram.y"
          {	yyval = mk_boolean(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3771 "awkgram.c"
    break;

  case 134: /* exp: exp MATCHOP typed_regexp  */
#line 1670 "awkgram.y"
          {
		if (yyvsp[-2]->lasti->opcode == Op_match_rec)
			warning_ln(yyvsp[-1]->source_line,
				_("regular expression on left of `~' or `!~' operator"));

		assert(yyvsp[0]->opcode == Op_push_re
			&& (yyvsp[0]->memory->flags & REGEX) != 0);
		/* RHS is @/.../ */
		yyvsp[-1]->memory = yyvsp[0]->memory;
		bcfree(yyvsp[0]);
		yyval = list_append(yyvsp[-2], yyvsp[-1]);
	  }
#line 3788 "awkgram.c"
    break;

  case 135: /* exp: exp MATCHOP exp  */
#line 1683 "awkgram.y"
          {
		if (yyvsp[-2]->lasti->opcode == Op_match_rec)
			warning_ln(yyvsp[-1]->source_line,
				_("regular expression on left of `~' or `!~' operator"));

		if (yyvsp[0]->lasti == yyvsp[0]->nexti && yyvsp[0]->nexti->opcode == Op_match_rec) {
			/* RHS is /.../ */
			yyvsp[-1]->memory = yyvsp[0]->nexti->memory;
			bcfree(yyvsp[0]->nexti);	/* Op_match_rec */
			bcfree(yyvsp[0]);			/* Op_list */
			yyval = list_append(yyvsp[-2], yyvsp[-1]);
		} else {
			yyvsp[-1]->memory = make_regnode(Node_dynregex, NULL);
			yyval = list_append(list_merge(yyvsp[-2], yyvsp[0]), yyvsp[-1]);
		}
	  }
#line 3809 "awkgram.c"
    break;

  case 136: /* exp: exp LEX_IN simple_variable  */
#line 1700 "awkgram.y"
          {
		if (do_lint_old)
			lintwarn_ln(yyvsp[-1]->source_line,
				_("old awk does not support the keyword `in' except after `for'"));
		yyvsp[0]->nexti->opcode = Op_push_array;
		yyvsp[-1]->opcode = Op_in_array;
		yyvsp[-1]->expr_count = 1;
		yyval = list_append(list_merge(yyvsp[-2], yyvsp[0]), yyvsp[-1]);
	  }
#line 3823 "awkgram.c"
    break;

  case 137: /* exp: exp a_relop exp  */
#line 1710 "awkgram.y"
          {
		if (do_lint && yyvsp[0]->lasti->opcode == Op_match_rec)
			lintwarn_ln(yyvsp[-1]->source_line,
				_("regular expression on right of comparison"));
		yyval = list_append(list_merge(yyvsp[-2], yyvsp[0]), yyvsp[-1]);
	  }
#line 3834 "awkgram.c"
    break;

  case 138: /* exp: exp '?' exp ':' exp  */
#line 1717 "awkgram.y"
          { yyval = mk_condition(yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]); }
#line 3840 "awkgram.c"
    break;

  case 139: /* exp: common_exp  */
#line 1719 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3846 "awkgram.c"
    break;

  case 140: /* assign_operator: ASSIGN  */
#line 1724 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3852 "awkgram.c"
    break;

  case 141: /* assign_operator: ASSIGNOP  */
#line 1726 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3858 "awkgram.c"
    break;

  case 142: /* assign_operator: SLASH_BEFORE_EQUAL ASSIGN  */
#line 1728 "awkgram.y"
          {
		yyvsp[0]->opcode = Op_assign_quotient;
		yyval = yyvsp[0];
	  }
#line 3867 "awkgram.c"
    break;

  case 143: /* relop_or_less: RELOP  */
#line 1736 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3873 "awkgram.c"
    break;

  case 144: /* relop_or_less: '<'  */
#line 1738 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3879 "awkgram.c"
    break;

  case 145: /* a_relop: relop_or_less  */
#line 1743 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3885 "awkgram.c"
    break;

  case 146: /* a_relop: '>'  */
#line 1745 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3891 "awkgram.c"
    break;

  case 147: /* common_exp: simp_exp  */
#line 1750 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3897 "awkgram.c"
    break;

  case 148: /* common_exp: simp_exp_nc  */
#line 1752 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 3903 "awkgram.c"
    break;

  case 149: /* common_exp: common_exp simp_exp  */
#line 1754 "awkgram.y"
          {
		int count = 2;
		bool is_simple_var = false;

		if (yyvsp[-1]->lasti->opcode == Op_concat) {
			/* multiple (> 2) adjacent strings optimization */
			is_simple_var = (yyvsp[-1]->lasti->concat_flag & CSVAR) != 0;
			count = yyvsp[-1]->lasti->expr_count + 1;
			yyvsp[-1]->lasti->opcode = Op_no_op;
		} else {
			is_simple_var = (yyvsp[-1]->nexti->opcode == Op_push
					&& yyvsp[-1]->lasti == yyvsp[-1]->nexti); /* first exp. is a simple
					                             * variable?; kludge for use
					                             * in Op_assign_concat.
		 			                             */
		}

		if (do_optimize
			&& yyvsp[-1]->nexti == yyvsp[-1]->lasti && yyvsp[-1]->nexti->opcode == Op_push_i
			&& yyvsp[0]->nexti == yyvsp[0]->lasti && yyvsp[0]->nexti->opcode == Op_push_i
		) {
			NODE *n1 = yyvsp[-1]->nexti->memory;
			NODE *n2 = yyvsp[0]->nexti->memory;
			size_t nlen;

			// 1.5 ""   # can't fold this if program mucks with CONVFMT.
			// See test #12 in test/posix.awk.
			// Also can't fold if one or the other is translatable.
			if ((n1->flags & (NUMBER|NUMINT|INTLSTR)) != 0 || (n2->flags & (NUMBER|NUMINT|INTLSTR)) != 0)
				goto plain_concat;

			n1 = force_string(n1);
			n2 = force_string(n2);
			nlen = n1->stlen + n2->stlen;
			erealloc(n1->stptr, char *, nlen + 1);
			memcpy(n1->stptr + n1->stlen, n2->stptr, n2->stlen);
			n1->stlen = nlen;
			n1->stptr[nlen] = '\0';
			n1->flags &= ~(NUMCUR|NUMBER|NUMINT);
			n1->flags |= (STRING|STRCUR);
			unref(n2);
			bcfree(yyvsp[0]->nexti);
			bcfree(yyvsp[0]);
			yyval = yyvsp[-1];
		} else {
	plain_concat:
			yyval = list_append(list_merge(yyvsp[-1], yyvsp[0]), instruction(Op_concat));
			yyval->lasti->concat_flag = (is_simple_var ? CSVAR : 0);
			yyval->lasti->expr_count = count;
			if (count > max_args)
				max_args = count;
		}
	  }
#line 3961 "awkgram.c"
    break;

  case 151: /* simp_exp: simp_exp '^' simp_exp  */
#line 1813 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3967 "awkgram.c"
    break;

  case 152: /* simp_exp: simp_exp '*' simp_exp  */
#line 1815 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3973 "awkgram.c"
    break;

  case 153: /* simp_exp: simp_exp '/' simp_exp  */
#line 1817 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3979 "awkgram.c"
    break;

  case 154: /* simp_exp: simp_exp '%' simp_exp  */
#line 1819 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3985 "awkgram.c"
    break;

  case 155: /* simp_exp: simp_exp '+' simp_exp  */
#line 1821 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3991 "awkgram.c"
    break;

  case 156: /* simp_exp: simp_exp '-' simp_exp  */
#line 1823 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 3997 "awkgram.c"
    break;

  case 157: /* simp_exp: LEX_GETLINE opt_variable input_redir  */
#line 1825 "awkgram.y"
          {
		/*
		 * In BEGINFILE/ENDFILE, allow `getline [var] < file'
		 */

		if ((rule == BEGINFILE || rule == ENDFILE) && yyvsp[0] == NULL)
			error_ln(yyvsp[-2]->source_line,
				 _("non-redirected `getline' invalid inside `%s' rule"), ruletab[rule]);
		if (do_lint && rule == END && yyvsp[0] == NULL)
			lintwarn_ln(yyvsp[-2]->source_line,
				_("non-redirected `getline' undefined inside END action"));
		yyval = mk_getline(yyvsp[-2], yyvsp[-1], yyvsp[0], redirect_input);
	  }
#line 4015 "awkgram.c"
    break;

  case 158: /* simp_exp: variable INCREMENT  */
#line 1839 "awkgram.y"
          {
		yyvsp[0]->opcode = Op_postincrement;
		yyval = mk_assignment(yyvsp[-1], NULL, yyvsp[0]);
	  }
#line 4024 "awkgram.c"
    break;

  case 159: /* simp_exp: variable DECREMENT  */
#line 1844 "awkgram.y"
          {
		yyvsp[0]->opcode = Op_postdecrement;
		yyval = mk_assignment(yyvsp[-1], NULL, yyvsp[0]);
	  }
#line 4033 "awkgram.c"
    break;

  case 160: /* simp_exp: '(' expression_list r_paren LEX_IN simple_variable  */
#line 1849 "awkgram.y"
          {
		if (do_lint_old) {
		    /* first one is warning so that second one comes out if warnings are fatal */
		    warning_ln(yyvsp[-1]->source_line,
				_("old awk does not support the keyword `in' except after `for'"));
		    lintwarn_ln(yyvsp[-1]->source_line,
				_("old awk does not support multidimensional arrays"));
		}
		yyvsp[0]->nexti->opcode = Op_push_array;
		yyvsp[-1]->opcode = Op_in_array;
		if (yyvsp[-3] == NULL) {	/* error */
			errcount++;
			yyvsp[-1]->expr_count = 0;
			yyval = list_merge(yyvsp[0], yyvsp[-1]);
		} else {
			INSTRUCTION *t = yyvsp[-3];
			yyvsp[-1]->expr_count = count_expressions(&t, false);
			yyval = list_append(list_merge(t, yyvsp[0]), yyvsp[-1]);
		}
	  }
#line 4058 "awkgram.c"
    break;

  case 161: /* simp_exp_nc: common_exp IO_IN LEX_GETLINE opt_variable  */
#line 1875 "awkgram.y"
                {
		  yyval = mk_getline(yyvsp[-1], yyvsp[0], yyvsp[-3], yyvsp[-2]->redir_type);
		  bcfree(yyvsp[-2]);
		}
#line 4067 "awkgram.c"
    break;

  case 162: /* simp_exp_nc: simp_exp_nc '^' simp_exp  */
#line 1881 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 4073 "awkgram.c"
    break;

  case 163: /* simp_exp_nc: simp_exp_nc '*' simp_exp  */
#line 1883 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 4079 "awkgram.c"
    break;

  case 164: /* simp_exp_nc: simp_exp_nc '/' simp_exp  */
#line 1885 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 4085 "awkgram.c"
    break;

  case 165: /* simp_exp_nc: simp_exp_nc '%' simp_exp  */
#line 1887 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 4091 "awkgram.c"
    break;

  case 166: /* simp_exp_nc: simp_exp_nc '+' simp_exp  */
#line 1889 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 4097 "awkgram.c"
    break;

  case 167: /* simp_exp_nc: simp_exp_nc '-' simp_exp  */
#line 1891 "awkgram.y"
          { yyval = mk_binary(yyvsp[-2], yyvsp[0], yyvsp[-1]); }
#line 4103 "awkgram.c"
    break;

  case 168: /* non_post_simp_exp: regexp  */
#line 1896 "awkgram.y"
          {
		yyval = list_create(yyvsp[0]);
	  }
#line 4111 "awkgram.c"
    break;

  case 169: /* non_post_simp_exp: '!' simp_exp  */
#line 1900 "awkgram.y"
          {
		if (yyvsp[0]->opcode == Op_match_rec) {
			yyvsp[0]->opcode = Op_nomatch;
			yyvsp[-1]->opcode = Op_push_i;
			yyvsp[-1]->memory = set_profile_text(make_number(0.0), "0", 1);
			yyval = list_append(list_append(list_create(yyvsp[-1]),
						instruction(Op_field_spec)), yyvsp[0]);
		} else {
			if (do_optimize && yyvsp[0]->nexti == yyvsp[0]->lasti
					&& yyvsp[0]->nexti->opcode == Op_push_i
					&& (yyvsp[0]->nexti->memory->flags & (MPFN|MPZN|INTLSTR)) == 0
			) {
				NODE *n = yyvsp[0]->nexti->memory;
				if ((n->flags & STRING) != 0) {
					n->numbr = (AWKNUM) (n->stlen == 0);
					n->flags &= ~(STRCUR|STRING);
					n->flags |= (NUMCUR|NUMBER);
					efree(n->stptr);
					n->stptr = NULL;
					n->stlen = 0;
				} else
					n->numbr = (AWKNUM) (n->numbr == 0.0);
				bcfree(yyvsp[-1]);
				yyval = yyvsp[0];
			} else {
				yyvsp[-1]->opcode = Op_not;
				add_lint(yyvsp[0], LINT_assign_in_cond);
				yyval = list_append(yyvsp[0], yyvsp[-1]);
			}
		}
	   }
#line 4147 "awkgram.c"
    break;

  case 170: /* non_post_simp_exp: '(' exp r_paren  */
#line 1932 "awkgram.y"
          {
		// Always include. Allows us to lint warn on
		// print "foo" > "bar" 1
		// but not warn on
		// print "foo" > ("bar" 1)
		yyval = list_append(yyvsp[-1], bcalloc(Op_parens, 1, sourceline));
	  }
#line 4159 "awkgram.c"
    break;

  case 171: /* non_post_simp_exp: LEX_BUILTIN '(' opt_fcall_expression_list r_paren  */
#line 1940 "awkgram.y"
          {
		yyval = snode(yyvsp[-1], yyvsp[-3]);
		if (yyval == NULL)
			YYABORT;
	  }
#line 4169 "awkgram.c"
    break;

  case 172: /* non_post_simp_exp: LEX_LENGTH '(' opt_fcall_expression_list r_paren  */
#line 1946 "awkgram.y"
          {
		yyval = snode(yyvsp[-1], yyvsp[-3]);
		if (yyval == NULL)
			YYABORT;
	  }
#line 4179 "awkgram.c"
    break;

  case 173: /* non_post_simp_exp: LEX_LENGTH  */
#line 1952 "awkgram.y"
          {
		static bool warned = false;

		if (do_lint && ! warned) {
			warned = true;
			lintwarn_ln(yyvsp[0]->source_line,
				_("call of `length' without parentheses is not portable"));
		}
		yyval = snode(NULL, yyvsp[0]);
		if (yyval == NULL)
			YYABORT;
	  }
#line 4196 "awkgram.c"
    break;

  case 176: /* non_post_simp_exp: INCREMENT variable  */
#line 1967 "awkgram.y"
          {
		yyvsp[-1]->opcode = Op_preincrement;
		yyval = mk_assignment(yyvsp[0], NULL, yyvsp[-1]);
	  }
#line 4205 "awkgram.c"
    break;

  case 177: /* non_post_simp_exp: DECREMENT variable  */
#line 1972 "awkgram.y"
          {
		yyvsp[-1]->opcode = Op_predecrement;
		yyval = mk_assignment(yyvsp[0], NULL, yyvsp[-1]);
	  }
#line 4214 "awkgram.c"
    break;

  case 178: /* non_post_simp_exp: YNUMBER  */
#line 1977 "awkgram.y"
          {
		yyval = list_create(yyvsp[0]);
	  }
#line 4222 "awkgram.c"
    break;

  case 179: /* non_post_simp_exp: YSTRING  */
#line 1981 "awkgram.y"
          {
		yyval = list_create(yyvsp[0]);
	  }
#line 4230 "awkgram.c"
    break;

  case 180: /* non_post_simp_exp: '-' simp_exp  */
#line 1985 "awkgram.y"
          {
		if (yyvsp[0]->lasti->opcode == Op_push_i
			&& (yyvsp[0]->lasti->memory->flags & STRING) == 0
		) {
			NODE *n = yyvsp[0]->lasti->memory;
			(void) force_number(n);
			negate_num(n);
			yyval = yyvsp[0];
			bcfree(yyvsp[-1]);
		} else {
			yyvsp[-1]->opcode = Op_unary_minus;
			yyval = list_append(yyvsp[0], yyvsp[-1]);
		}
	  }
#line 4249 "awkgram.c"
    break;

  case 181: /* non_post_simp_exp: '+' simp_exp  */
#line 2000 "awkgram.y"
          {
		if (yyvsp[0]->lasti->opcode == Op_push_i
			&& (yyvsp[0]->lasti->memory->flags & STRING) == 0
			&& (yyvsp[0]->lasti->memory->flags & NUMCONSTSTR) != 0) {
			NODE *n = yyvsp[0]->lasti->memory;
			add_sign_to_num(n, '+');
			yyval = yyvsp[0];
			bcfree(yyvsp[-1]);
		} else {
			/*
			 * was: $$ = $2
			 * POSIX semantics: force a conversion to numeric type
			 */
			yyvsp[-1]->opcode = Op_unary_plus;
			yyval = list_append(yyvsp[0], yyvsp[-1]);
		}
	  }
#line 4271 "awkgram.c"
    break;

  case 182: /* func_call: direct_func_call  */
#line 2021 "awkgram.y"
          {
		func_use(yyvsp[0]->lasti->func_name, FUNC_USE);
		yyval = yyvsp[0];
	  }
#line 4280 "awkgram.c"
    break;

  case 183: /* func_call: '@' direct_func_call  */
#line 2026 "awkgram.y"
          {
		/* indirect function call */
		INSTRUCTION *f, *t;
		char *name;
		NODE *indirect_var;
		static bool warned = false;
		const char *msg = _("indirect function calls are a gawk extension");

		if (do_traditional || do_posix)
			yyerror("%s", msg);
		else if (do_lint_extensions && ! warned) {
			warned = true;
			lintwarn("%s", msg);
		}

		f = yyvsp[0]->lasti;
		f->opcode = Op_indirect_func_call;
		name = estrdup(f->func_name, strlen(f->func_name));
		if (is_std_var(name))
			yyerror(_("cannot use special variable `%s' for indirect function call"), name);
		indirect_var = variable(f->source_line, name, Node_var_new);
		t = instruction(Op_push);
		t->memory = indirect_var;

		/* prepend indirect var instead of appending to arguments (opt_expression_list),
		 * and pop it off in setup_frame (eval.c) (left to right evaluation order); Test case:
		 *		f = "fun"
		 *		@f(f="real_fun")
		 */

		yyval = list_prepend(yyvsp[0], t);
		at_seen--;
	  }
#line 4318 "awkgram.c"
    break;

  case 184: /* direct_func_call: FUNC_CALL '(' opt_fcall_expression_list r_paren  */
#line 2063 "awkgram.y"
          {
		NODE *n;
		char *name = yyvsp[-3]->func_name;
		char *qname = qualify_name(name, strlen(name));

		if (qname != name) {
			efree((char *) name);
			yyvsp[-3]->func_name = qname;
		}

		if (! at_seen) {
			n = lookup(yyvsp[-3]->func_name);
			if (n != NULL && n->type != Node_func
			    && n->type != Node_ext_func) {
				error_ln(yyvsp[-3]->source_line,
					_("attempt to use non-function `%s' in function call"),
						yyvsp[-3]->func_name);
			}
		}

		param_sanity(yyvsp[-1]);
		yyvsp[-3]->opcode = Op_func_call;
		yyvsp[-3]->func_body = NULL;
		if (yyvsp[-1] == NULL) {	/* no argument or error */
			(yyvsp[-3] + 1)->expr_count = 0;
			yyval = list_create(yyvsp[-3]);
		} else {
			INSTRUCTION *t = yyvsp[-1];
			(yyvsp[-3] + 1)->expr_count = count_expressions(&t, true);
			yyval = list_append(t, yyvsp[-3]);
		}
	  }
#line 4355 "awkgram.c"
    break;

  case 185: /* opt_variable: %empty  */
#line 2099 "awkgram.y"
          { yyval = NULL; }
#line 4361 "awkgram.c"
    break;

  case 186: /* opt_variable: variable  */
#line 2101 "awkgram.y"
          { yyval = yyvsp[0]; }
#line 4367 "awkgram.c"
    break;

  case 187: /* delete_subscript_list: %empty  */
#line 2106 "awkgram.y"
          { yyval = NULL; }
#line 4373 "awkgram.c"
    break;

  case 188: /* delete_subscript_list: delete_subscript SUBSCRIPT  */
#line 2108 "awkgram.y"
          { yyval = yyvsp[-1]; }
#line 4379 "awkgram.c"
    break;

  case 189: /* delete_subscript: delete_exp_list  */
#line 2113 "awkgram.y"
          {	yyval = yyvsp[0]; }
#line 4385 "awkgram.c"
    break;

  case 190: /* delete_subscript: delete_subscript delete_exp_list  */
#line 2115 "awkgram.y"
          {
		yyval = list_merge(yyvsp[-1], yyvsp[0]);
	  }
#line 4393 "awkgram.c"
    break;

  case 191: /* delete_exp_list: bracketed_exp_list  */
#line 2122 "awkgram.y"
          {
		INSTRUCTION *ip = yyvsp[0]->lasti;
		int count = ip->sub_count;	/* # of SUBSEP-seperated expressions */
		if (count > 1) {
			/* change Op_subscript or Op_sub_array to Op_concat */
			ip->opcode = Op_concat;
			ip->concat_flag = CSUBSEP;
			ip->expr_count = count;
		} else
			ip->opcode = Op_no_op;
		sub_counter++;	/* count # of dimensions */
		yyval = yyvsp[0];
	  }
#line 4411 "awkgram.c"
    break;

  case 192: /* bracketed_exp_list: '[' expression_list ']'  */
#line 2139 "awkgram.y"
          {
		INSTRUCTION *t = yyvsp[-1];
		if (yyvsp[-1] == NULL) {
			error_ln(yyvsp[0]->source_line,
				_("invalid subscript expression"));
			/* install Null string as subscript. */
			t = list_create(instruction(Op_push_i));
			t->nexti->memory = dupnode(Nnull_string);
			yyvsp[0]->sub_count = 1;
		} else
			yyvsp[0]->sub_count = count_expressions(&t, false);
		yyval = list_append(t, yyvsp[0]);
	  }
#line 4429 "awkgram.c"
    break;

  case 193: /* subscript: bracketed_exp_list  */
#line 2156 "awkgram.y"
          {	yyval = yyvsp[0]; }
#line 4435 "awkgram.c"
    break;

  case 194: /* subscript: subscript bracketed_exp_list  */
#line 2158 "awkgram.y"
          {
		yyval = list_merge(yyvsp[-1], yyvsp[0]);
	  }
#line 4443 "awkgram.c"
    break;

  case 195: /* subscript_list: subscript SUBSCRIPT  */
#line 2165 "awkgram.y"
          { yyval = yyvsp[-1]; }
#line 4449 "awkgram.c"
    break;

  case 196: /* simple_variable: NAME  */
#line 2170 "awkgram.y"
          {
		yyvsp[0]->opcode = Op_push;
		yyvsp[0]->memory = variable(yyvsp[0]->source_line, yyvsp[0]->lextok, Node_var_new);
		yyval = list_create(yyvsp[0]);
	  }
#line 4459 "awkgram.c"
    break;

  case 197: /* simple_variable: NAME subscript_list  */
#line 2176 "awkgram.y"
          {
		char *arr = yyvsp[-1]->lextok;

		// Don't use Node_var_array here; breaks rwarray:readall extension.
		yyvsp[-1]->memory = variable(yyvsp[-1]->source_line, arr, Node_var_new);
		yyvsp[-1]->opcode = Op_push_array;
		yyval = list_prepend(yyvsp[0], yyvsp[-1]);
	  }
#line 4472 "awkgram.c"
    break;

  case 198: /* variable: simple_variable  */
#line 2188 "awkgram.y"
          {
		INSTRUCTION *ip = yyvsp[0]->nexti;
		if (ip->opcode == Op_push
			&& ip->memory->type == Node_var
			&& ip->memory->var_update
		) {
			yyval = list_prepend(yyvsp[0], instruction(Op_var_update));
			yyval->nexti->update_var = ip->memory->var_update;
		} else
			yyval = yyvsp[0];
	  }
#line 4488 "awkgram.c"
    break;

  case 199: /* variable: '$' non_post_simp_exp opt_incdec  */
#line 2200 "awkgram.y"
          {
		yyval = list_append(yyvsp[-1], yyvsp[-2]);
		if (yyvsp[0] != NULL)
			mk_assignment(yyvsp[-1], NULL, yyvsp[0]);
	  }
#line 4498 "awkgram.c"
    break;

  case 200: /* opt_incdec: INCREMENT  */
#line 2209 "awkgram.y"
          {
		yyvsp[0]->opcode = Op_postincrement;
	  }
#line 4506 "awkgram.c"
    break;

  case 201: /* opt_incdec: DECREMENT  */
#line 2213 "awkgram.y"
          {
		yyvsp[0]->opcode = Op_postdecrement;
	  }
#line 4514 "awkgram.c"
    break;

  case 202: /* opt_incdec: %empty  */
#line 2217 "awkgram.y"
          { yyval = NULL; }
#line 4520 "awkgram.c"
    break;

  case 203: /* l_brace: '{' opt_nls  */
#line 2221 "awkgram.y"
                      { yyval = yyvsp[0]; }
#line 4526 "awkgram.c"
    break;

  case 204: /* r_brace: '}' opt_nls  */
#line 2225 "awkgram.y"
                        { yyval = yyvsp[0]; yyerrok; }
#line 4532 "awkgram.c"
    break;

  case 205: /* r_paren: ')'  */
#line 2229 "awkgram.y"
              { yyerrok; }
#line 4538 "awkgram.c"
    break;

  case 206: /* opt_semi: %empty  */
#line 2234 "awkgram.y"
          { yyval = NULL; }
#line 4544 "awkgram.c"
    break;

  case 208: /* semi: ';'  */
#line 2239 "awkgram.y"
                { yyerrok; }
#line 4550 "awkgram.c"
    break;

  case 209: /* colon: ':'  */
#line 2243 "awkgram.y"
                { yyval = yyvsp[0]; yyerrok; }
#line 4556 "awkgram.c"
    break;

  case 210: /* comma: ',' opt_nls  */
#line 2247 "awkgram.y"
                        { yyval = yyvsp[0]; yyerrok; }
#line 4562 "awkgram.c"
    break;


#line 4566 "awkgram.c"

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

#line 2249 "awkgram.y"


struct token {
	const char *operator;	/* text to match */
	OPCODE value;			/*  type */
	int class;				/* lexical class */
	unsigned flags;			/* # of args. allowed and compatability */
#	define	ARGS	0xFF	/* 0, 1, 2, 3 args allowed (any combination */
#	define	A(n)	(1<<(n))
#	define	VERSION_MASK	0xFF00	/* old awk is zero */
#	define	NOT_OLD		0x0100	/* feature not in old awk */
#	define	NOT_POSIX	0x0200	/* feature not in POSIX */
#	define	GAWKX		0x0400	/* gawk extension */
#	define	BREAK		0x0800	/* break allowed inside */
#	define	CONTINUE	0x1000	/* continue allowed inside */
#	define	DEBUG_USE	0x2000	/* for use by developers */

	NODE *(*ptr)(int);	/* function that implements this keyword */
	NODE *(*ptr2)(int);	/* alternate arbitrary-precision function */
};

#ifdef USE_EBCDIC
/* tokcompare --- lexicographically compare token names for sorting */

static int
tokcompare(const void *l, const void *r)
{
	struct token *lhs, *rhs;

	lhs = (struct token *) l;
	rhs = (struct token *) r;

	return strcmp(lhs->operator, rhs->operator);
}
#endif

/*
 * Tokentab is sorted ASCII ascending order, so it can be binary searched.
 * See check_special(), which sorts the table on EBCDIC systems.
 * Function pointers come from declarations in awk.h.
 */

#ifdef HAVE_MPFR
#define MPF(F) do_mpfr_##F
#else
#define MPF(F) 0
#endif

static const struct token tokentab[] = {
{"BEGIN",	Op_rule,	 LEX_BEGIN,	0,		0,	0},
{"BEGINFILE",	Op_rule,	 LEX_BEGINFILE,	GAWKX,		0,	0},
{"END",		Op_rule,	 LEX_END,	0,		0,	0},
{"ENDFILE",	Op_rule,	 LEX_ENDFILE,	GAWKX,		0,	0},
#ifdef ARRAYDEBUG
{"adump",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(1)|A(2)|DEBUG_USE,	do_adump,	0},
#endif
{"and",		Op_builtin,    LEX_BUILTIN,	GAWKX,		do_and,	MPF(and)},
{"asort",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2)|A(3),	do_asort,	0},
{"asorti",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2)|A(3),	do_asorti,	0},
{"atan2",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(2),	do_atan2,	MPF(atan2)},
{"bindtextdomain",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2),	do_bindtextdomain,	0},
{"break",	Op_K_break,	 LEX_BREAK,	0,		0,	0},
{"case",	Op_K_case,	 LEX_CASE,	GAWKX,		0,	0},
{"close",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(1)|A(2),	do_close,	0},
{"compl",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(1),	do_compl,	MPF(compl)},
{"continue",	Op_K_continue, LEX_CONTINUE,	0,		0,	0},
{"cos",		Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(1),	do_cos,	MPF(cos)},
{"dcgettext",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2)|A(3),	do_dcgettext,	0},
{"dcngettext",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2)|A(3)|A(4)|A(5),	do_dcngettext,	0},
{"default",	Op_K_default,	 LEX_DEFAULT,	GAWKX,		0,	0},
{"delete",	Op_K_delete,	 LEX_DELETE,	NOT_OLD,	0,	0},
{"do",		Op_K_do,	 LEX_DO,	NOT_OLD|BREAK|CONTINUE,	0,	0},
{"else",	Op_K_else,	 LEX_ELSE,	0,		0,	0},
{"eval",	Op_symbol,	 LEX_EVAL,	0,		0,	0},
{"exit",	Op_K_exit,	 LEX_EXIT,	0,		0,	0},
{"exp",		Op_builtin,	 LEX_BUILTIN,	A(1),		do_exp,	MPF(exp)},
{"fflush",	Op_builtin,	 LEX_BUILTIN,	A(0)|A(1), do_fflush,	0},
{"for",		Op_K_for,	 LEX_FOR,	BREAK|CONTINUE,	0,	0},
{"func",	Op_func, 	LEX_FUNCTION,	NOT_POSIX|NOT_OLD,	0,	0},
{"function",	Op_func, 	LEX_FUNCTION,	NOT_OLD,	0,	0},
{"gensub",	Op_sub_builtin,	 LEX_BUILTIN,	GAWKX|A(3)|A(4), 0,	0},
{"getline",	Op_K_getline_redir,	 LEX_GETLINE,	NOT_OLD,	0,	0},
{"gsub",	Op_sub_builtin,	 LEX_BUILTIN,	NOT_OLD|A(2)|A(3), 0,	0},
{"if",		Op_K_if,	 LEX_IF,	0,		0,	0},
{"in",		Op_symbol,	 LEX_IN,	0,		0,	0},
{"include",	Op_symbol,	 LEX_INCLUDE,	GAWKX,	0,	0},
{"index",	Op_builtin,	 LEX_BUILTIN,	A(2),		do_index,	0},
{"int",		Op_builtin,	 LEX_BUILTIN,	A(1),		do_int,	MPF(int)},
#ifdef SUPPLY_INTDIV
{"intdiv0",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(3),	do_intdiv,	MPF(intdiv)},
#endif
{"isarray",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1),	do_isarray,	0},
{"length",	Op_builtin,	 LEX_LENGTH,	A(0)|A(1),	do_length,	0},
{"load",  	Op_symbol,	 LEX_LOAD,	GAWKX,		0,	0},
{"log",		Op_builtin,	 LEX_BUILTIN,	A(1),		do_log,	MPF(log)},
{"lshift",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(2),	do_lshift,	MPF(lshift)},
{"match",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(2)|A(3), do_match,	0},
{"mkbool",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(1),	do_mkbool,	0},
{"mktime",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2), do_mktime, 0},
{"namespace",  	Op_symbol,	 LEX_NAMESPACE,	GAWKX,		0,	0},
{"next",	Op_K_next,	 LEX_NEXT,	0,		0,	0},
{"nextfile",	Op_K_nextfile, LEX_NEXTFILE,	0,		0,	0},
{"nsinclude",	Op_symbol,	 LEX_NSINCLUDE,	GAWKX,	0,	0},
{"or",		Op_builtin,    LEX_BUILTIN,	GAWKX,		do_or,	MPF(or)},
{"patsplit",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(2)|A(3)|A(4), do_patsplit,	0},
{"print",	Op_K_print,	 LEX_PRINT,	0,		0,	0},
{"printf",	Op_K_printf,	 LEX_PRINTF,	0,		0,	0},
{"rand",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(0),	do_rand,	MPF(rand)},
{"return",	Op_K_return,	 LEX_RETURN,	NOT_OLD,	0,	0},
{"rshift",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(2),	do_rshift,	MPF(rshift)},
{"sin",		Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(1),	do_sin,	MPF(sin)},
{"split",	Op_builtin,	 LEX_BUILTIN,	A(2)|A(3)|A(4),	do_split,	0},
{"sprintf",	Op_builtin,	 LEX_BUILTIN,	0,		do_sprintf,	0},
{"sqrt",	Op_builtin,	 LEX_BUILTIN,	A(1),		do_sqrt,	MPF(sqrt)},
{"srand",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(0)|A(1), do_srand,	MPF(srand)},
#if defined(GAWKDEBUG) || defined(ARRAYDEBUG) /* || ... */
{"stopme",	Op_builtin,	LEX_BUILTIN,	GAWKX|A(0)|DEBUG_USE,	stopme,		0},
#endif
{"strftime",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(0)|A(1)|A(2)|A(3), do_strftime,	0},
{"strtonum",	Op_builtin,    LEX_BUILTIN,	GAWKX|A(1),	do_strtonum, MPF(strtonum)},
{"sub",		Op_sub_builtin,	 LEX_BUILTIN,	NOT_OLD|A(2)|A(3), 0,	0},
{"substr",	Op_builtin,	 LEX_BUILTIN,	A(2)|A(3),	do_substr,	0},
{"switch",	Op_K_switch,	 LEX_SWITCH,	GAWKX|BREAK,	0,	0},
{"system",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(1),	do_system,	0},
{"systime",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(0),	do_systime,	0},
{"tolower",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(1),	do_tolower,	0},
{"toupper",	Op_builtin,	 LEX_BUILTIN,	NOT_OLD|A(1),	do_toupper,	0},
{"typeof",	Op_builtin,	 LEX_BUILTIN,	GAWKX|A(1)|A(2), do_typeof,	0},
{"while",	Op_K_while,	 LEX_WHILE,	BREAK|CONTINUE,	0,	0},
{"xor",		Op_builtin,    LEX_BUILTIN,	GAWKX,		do_xor,	MPF(xor)},
};

/* Variable containing the current shift state.  */
static mbstate_t cur_mbstate;
/* Ring buffer containing current characters.  */
#define MAX_CHAR_IN_RING_BUFFER 8
#define RING_BUFFER_SIZE (MAX_CHAR_IN_RING_BUFFER * MB_LEN_MAX)
static char cur_char_ring[RING_BUFFER_SIZE];
/* Index for ring buffers.  */
static int cur_ring_idx;
/* This macro means that last nextc() return a singlebyte character
   or 1st byte of a multibyte character.  */
#define nextc_is_1stbyte (cur_char_ring[cur_ring_idx] == 1)

/* getfname --- return name of a builtin function (for pretty printing) */

const char *
getfname(NODE *(*fptr)(int), bool prepend_awk)
{
	int i, j;
	static char buf[100];

	j = sizeof(tokentab) / sizeof(tokentab[0]);
	/* linear search, no other way to do it */
	for (i = 0; i < j; i++) {
		if (tokentab[i].ptr == fptr || tokentab[i].ptr2 == fptr) {
			if (prepend_awk && (tokentab[i].flags & GAWKX) != 0) {
				sprintf(buf, "awk::%s", tokentab[i].operator);
				return buf;
			}
			return tokentab[i].operator;
		}
	}

	return NULL;
}

/* negate_num --- negate a number in NODE */

void
negate_num(NODE *n)
{
#ifdef HAVE_MPFR
	int tval = 0;
#endif

	add_sign_to_num(n, '-');

	if (! is_mpg_number(n)) {
		n->numbr = -n->numbr;
		return;
	}

#ifdef HAVE_MPFR
	if (is_mpg_integer(n)) {
		if (! is_zero(n)) {
			mpz_neg(n->mpg_i, n->mpg_i);
			return;
		}

		/*
		 * 0 --> -0 conversion. Requires turning the MPG integer
		 * into an MPFR float.
		 */

		mpz_clear(n->mpg_i);	/* release the integer storage */

		/* Convert and fall through. */
		tval = mpfr_set_d(n->mpg_numbr, 0.0, ROUND_MODE);
		IEEE_FMT(n->mpg_numbr, tval);
		n->flags &= ~MPZN;
		n->flags |= MPFN;
	}

	/* mpfr float case */
	tval = mpfr_neg(n->mpg_numbr, n->mpg_numbr, ROUND_MODE);
	IEEE_FMT(n->mpg_numbr, tval);
#endif
}

/* add_sign_to_num --- make a constant unary plus or minus for profiling */

static void
add_sign_to_num(NODE *n, char sign)
{
	if ((n->flags & NUMCONSTSTR) != 0) {
		char *s;

		s = n->stptr;
		memmove(& s[1], & s[0], n->stlen + 1);
		s[0] = sign;
		n->stlen++;
	}
}

/* print_included_from --- print `Included from ..' file names and locations */

static void
print_included_from()
{
	int saveline, line;
	SRCFILE *s;

	/* suppress current file name, line # from `.. included from ..' msgs */
	saveline = sourceline;
	sourceline = 0;

	for (s = sourcefile; s != NULL && (s->stype == SRC_INC || s->stype == SRC_NSINC); ) {
		s = s->next;
		if (s == NULL || s->fd <= INVALID_HANDLE)
			continue;
		line = s->srclines;

		/* if last token is NEWLINE, line number is off by 1. */
		if (s->lasttok == NEWLINE)
			line--;
		msg("%s %s:%d%c",
			s->prev == sourcefile ? "In file included from"
					  : "                 from",
			(s->stype == SRC_INC || s->stype == SRC_NSINC ||
				 s->stype == SRC_FILE) ? s->src : "cmd. line",
			line,
			s->stype != SRC_FILE ? ',' : ':'
		);
	}
	sourceline = saveline;
}

/* warning_ln --- print a warning message with location */

static void
warning_ln(int line, const char *mesg, ...)
{
	va_list args;
	int saveline;

	saveline = sourceline;
	sourceline = line;
	print_included_from();
	va_start(args, mesg);
	err(false, _("warning: "), mesg, args);
	va_end(args);
	sourceline = saveline;
}

/* lintwarn_ln --- print a lint warning and location */

static void
lintwarn_ln(int line, const char *mesg, ...)
{
	va_list args;
	int saveline;

	saveline = sourceline;
	sourceline = line;
	print_included_from();
	va_start(args, mesg);
	if (lintfunc == r_fatal)
		err(true, _("fatal: "), mesg, args);
	else
		err(false, _("warning: "), mesg, args);
	va_end(args);
	sourceline = saveline;
	if (lintfunc == r_fatal)
		gawk_exit(EXIT_FATAL);
}

/* error_ln --- print an error message and location */

static void
error_ln(int line, const char *m, ...)
{
	va_list args;
	int saveline;

	saveline = sourceline;
	sourceline = line;
	print_included_from();
	errcount++;
	va_start(args, m);
	err(false, "error: ", m, args);
	va_end(args);
	sourceline = saveline;
}

/* yyerror --- print a syntax error message, show where */

static void
yyerror(const char *m, ...)
{
	va_list args;
	const char *mesg = NULL;
	char *bp, *cp;
	char *scan;
	char *buf;
	int count;
	static char end_of_file_line[] = "(END OF FILE)";
	static char syntax_error[] = "syntax error";
	static size_t syn_err_len = sizeof(syntax_error) - 1;
	bool generic_error = (strncmp(m, syntax_error, syn_err_len) == 0);

	print_included_from();

	errcount++;
	/* Find the current line in the input file */
	if (lexptr && lexeme) {
		if (thisline == NULL) {
			cp = lexeme;
			if (*cp == '\n') {
				if (cp > lexptr_begin)
					cp--;
				mesg = _("unexpected newline or end of string");
			}
			for (; cp != lexptr_begin && *cp != '\n'; --cp)
				continue;
			if (*cp == '\n')
				cp++;
			thisline = cp;
		}
		/* NL isn't guaranteed */
		bp = lexeme;
		if (bp < thisline)
			bp = thisline + 1;
		while (bp < lexend && *bp && *bp != '\n')
			bp++;
	} else {
		thisline = end_of_file_line;
		bp = thisline + strlen(thisline);
	}

	if (lexeof && mesg == NULL && generic_error) {
		msg("%s", end_of_file_line);
		mesg = _("source files / command-line arguments must contain complete functions or rules");
	} else
		msg("%.*s", (int) (bp - thisline), thisline);

	va_start(args, m);
	if (mesg == NULL)
		mesg = m;

	count = strlen(mesg) + 1;
	if (lexptr != NULL)
		count += (lexeme - thisline) + 2;
	ezalloc(buf, char *, count+1);

	bp = buf;

	if (lexptr != NULL) {
		scan = thisline;
		while (scan < lexeme)
			if (*scan++ == '\t')
				*bp++ = '\t';
			else
				*bp++ = ' ';
		*bp++ = '^';
		*bp++ = ' ';
	}
	strcpy(bp, mesg);
	err(false, "", buf, args);
	va_end(args);
	efree(buf);
	/* we don't use fatal(), that changes the exit status to 2 */
	exit(EXIT_FAILURE);
}

/* mk_program --- create a single list of instructions */

static INSTRUCTION *
mk_program()
{
	INSTRUCTION *cp, *tmp;

#define begin_block         rule_block[BEGIN]
#define end_block           rule_block[END]
#define prog_block          rule_block[Rule]
#define beginfile_block     rule_block[BEGINFILE]
#define endfile_block       rule_block[ENDFILE]

	if (end_block == NULL)
		end_block = list_create(ip_end);
	else
		(void) list_prepend(end_block, ip_end);

	if (! in_main_context()) {
		if (begin_block != NULL && prog_block != NULL)
			cp = list_merge(begin_block, prog_block);
		else
			cp = (begin_block != NULL) ? begin_block : prog_block;

		if (cp != NULL)
			(void) list_merge(cp, end_block);
		else
			cp = end_block;

		(void) list_append(cp, instruction(Op_stop));
		goto out;
	}

	if (endfile_block == NULL)
		endfile_block = list_create(ip_endfile);
	else {
		ip_rec->has_endfile = true;
		(void) list_prepend(endfile_block, ip_endfile);
	}

	if (beginfile_block == NULL)
		beginfile_block = list_create(ip_beginfile);
	else
		(void) list_prepend(beginfile_block, ip_beginfile);

	if (prog_block == NULL) {
		if (end_block->nexti == end_block->lasti
				&& beginfile_block->nexti == beginfile_block->lasti
				&& endfile_block->nexti == endfile_block->lasti
		) {
			/* no pattern-action and (real) end, beginfile or endfile blocks */
			bcfree(ip_rec);
			bcfree(ip_newfile);
			ip_rec = ip_newfile = NULL;

			list_append(beginfile_block, instruction(Op_after_beginfile));
			(void) list_append(endfile_block, instruction(Op_after_endfile));

			if (begin_block == NULL)     /* no program at all */
				cp = end_block;
			else
				cp = list_merge(begin_block, end_block);

			if (interblock_comment != NULL) {
				(void) list_append(cp, interblock_comment);
				interblock_comment = NULL;
			}

			(void) list_append(cp, ip_atexit);
			(void) list_append(cp, instruction(Op_stop));

			/* append beginfile_block and endfile_block for sole use
			 * in getline without redirection (Op_K_getline).
			 */

			(void) list_merge(cp, beginfile_block);
			(void) list_merge(cp, endfile_block);

			if (outer_comment != NULL) {
				cp = list_merge(list_create(outer_comment), cp);
				outer_comment = NULL;
			}

			if (interblock_comment != NULL) {
				(void) list_append(cp, interblock_comment);
				interblock_comment = NULL;
			}

			goto out;

		} else {
			/* install a do-nothing prog block */
			prog_block = list_create(instruction(Op_no_op));
		}
	}

	(void) list_append(endfile_block, instruction(Op_after_endfile));
	(void) list_prepend(prog_block, ip_rec);
	(void) list_append(prog_block, instruction(Op_jmp));
	prog_block->lasti->target_jmp = ip_rec;

	list_append(beginfile_block, instruction(Op_after_beginfile));

	cp = list_merge(beginfile_block, prog_block);
	(void) list_prepend(cp, ip_newfile);
	(void) list_merge(cp, endfile_block);
	(void) list_merge(cp, end_block);
	if (begin_block != NULL)
		cp = list_merge(begin_block, cp);

	if (outer_comment != NULL) {
		cp = list_merge(list_create(outer_comment), cp);
		outer_comment = NULL;
	}

	if (interblock_comment != NULL) {
		(void) list_append(cp, interblock_comment);
		interblock_comment = NULL;
	}

	(void) list_append(cp, ip_atexit);
	(void) list_append(cp, instruction(Op_stop));

out:
	/* delete the Op_list, not needed */
	tmp = cp->nexti;
	bcfree(cp);
	return tmp;

#undef begin_block
#undef end_block
#undef prog_block
#undef beginfile_block
#undef endfile_block
}

/* parse_program --- read in the program and convert into a list of instructions */

int
parse_program(INSTRUCTION **pcode, bool from_eval)
{
	int ret;

	called_from_eval = from_eval;

	/* pre-create non-local jump targets
	 * ip_end (Op_no_op) -- used as jump target for `exit'
	 * outside an END block.
	 */
	ip_end = instruction(Op_no_op);

	if (! in_main_context())
		ip_newfile = ip_rec = ip_atexit = ip_beginfile = ip_endfile = NULL;
	else {
		ip_endfile = instruction(Op_no_op);
		main_beginfile = ip_beginfile = instruction(Op_no_op);
		ip_rec = instruction(Op_get_record); /* target for `next', also ip_newfile */
		ip_newfile = bcalloc(Op_newfile, 2, 0); /* target for `nextfile' */
		ip_newfile->target_jmp = ip_end;
		ip_newfile->target_endfile = ip_endfile;
		(ip_newfile + 1)->target_get_record = ip_rec;
		ip_rec->target_newfile = ip_newfile;
		ip_atexit = instruction(Op_atexit);	/* target for `exit' in END block */
	}

	for (sourcefile = srcfiles->next; sourcefile->stype == SRC_EXTLIB;
			sourcefile = sourcefile->next)
		;

	lexeof = false;
	lexptr = NULL;
	lasttok = 0;
	memset(rule_block, 0, sizeof(rule_block));
	errcount = 0;
	tok = tokstart != NULL ? tokstart : tokexpand();

	ret = yyparse();
	*pcode = mk_program();

	/* avoid false source indications */
	source = NULL;
	sourceline = 0;
	if (ret == 0)	/* avoid spurious warning if parser aborted with YYABORT */
		check_funcs();

	if (do_posix && ! check_param_names())
		errcount++;

	if (args_array == NULL)
		emalloc(args_array, NODE **, (max_args + 2) * sizeof(NODE *));
	else
		erealloc(args_array, NODE **, (max_args + 2) * sizeof(NODE *));

	return (ret || errcount);
}

/* free_srcfile --- free a SRCFILE struct */

void
free_srcfile(SRCFILE *thisfile)
{
	efree(thisfile->src);
	efree(thisfile);
}

/* do_add_srcfile --- add one item to srcfiles */

static SRCFILE *
do_add_srcfile(enum srctype stype, char *src, char *path, SRCFILE *thisfile)
{
	SRCFILE *s;

	ezalloc(s, SRCFILE *, sizeof(SRCFILE));
	s->src = estrdup(src, strlen(src));
	s->fullpath = path;
	s->stype = stype;
	s->fd = INVALID_HANDLE;
	s->next = thisfile;
	s->prev = thisfile->prev;
	thisfile->prev->next = s;
	thisfile->prev = s;
	return s;
}

/* add_srcfile --- add one item to srcfiles after checking if
 *				a source file exists and not already in list.
 */

SRCFILE *
add_srcfile(enum srctype stype, char *src, SRCFILE *thisfile, bool *already_included, int *errcode)
{
	SRCFILE *s;
	struct stat sbuf;
	char *path;
	int errno_val = 0;

	if (already_included)
		*already_included = false;
	if (errcode)
		*errcode = 0;
	if (stype == SRC_CMDLINE || stype == SRC_STDIN)
		return do_add_srcfile(stype, src, NULL, thisfile);

	path = find_source(src, & sbuf, & errno_val, stype == SRC_EXTLIB);
	if (path == NULL) {
		if (errcode) {
			*errcode = errno_val;
			return NULL;
		}
		/* use full messages to ease translation */
		fatal(stype != SRC_EXTLIB
			? _("cannot open source file `%s' for reading: %s")
			: _("cannot open shared library `%s' for reading: %s"),
				src,
				errno_val ? strerror(errno_val) : _("reason unknown"));
	}

	/* N.B. We do not eliminate duplicate SRC_FILE (-f) programs. */
	for (s = srcfiles->next; s != srcfiles; s = s->next) {
		if ((s->stype == SRC_FILE || s->stype == SRC_INC || s->stype == SRC_NSINC || s->stype == SRC_EXTLIB) && files_are_same(path, s)) {
			if (stype == SRC_INC || stype == SRC_EXTLIB) {
				/* eliminate duplicates */
				if ((stype == SRC_INC) && (s->stype == SRC_FILE))
					fatal(_("cannot include `%s' and use it as a program file"), src);

				if (do_lint) {
					int line = sourceline;
					/* Kludge: the line number may be off for `@include file'.
					 * Since, this function is also used for '-f file' in main.c,
					 * sourceline > 1 check ensures that the call is at
					 * parse time.
					 */
					if (sourceline > 1 && lasttok == NEWLINE)
						line--;
					lintwarn_ln(line,
						    stype != SRC_EXTLIB
						      ? _("already included source file `%s'")
						      : _("already loaded shared library `%s'"),
						    src);
				}
				efree(path);
				if (already_included)
					*already_included = true;
				return NULL;
			} else {
				/* duplicates are allowed for -f */
				if (s->stype == SRC_INC)
					fatal(_("cannot include `%s' and use it as a program file"), src);
				/* no need to scan for further matches, since
				 * they must be of homogeneous type */
				break;
			}
		}
	}

	s = do_add_srcfile(stype, src, path, thisfile);
	s->sbuf = sbuf;
	s->mtime = sbuf.st_mtime;
	return s;
}

/* include_source --- read program from source included using `@include' */

static bool
include_source(INSTRUCTION *file, void **srcfile_p)
{
	SRCFILE *s;
	char *src = file->lextok;
	int errcode;
	bool already_included;

	*srcfile_p = NULL;

	if (do_traditional || do_posix) {
		error_ln(file->source_line, _("@include is a gawk extension"));
		return false;
	}

	if (strlen(src) == 0) {
		if (do_lint)
			lintwarn_ln(file->source_line, _("empty filename after @include"));
		return true;
	}

	s = add_srcfile(include_use_current_namespace ? SRC_NSINC : SRC_INC,
		src, sourcefile, &already_included, &errcode);
	if (s == NULL) {
		if (already_included)
			return true;
		error_ln(file->source_line,
			_("cannot open source file `%s' for reading: %s"),
			src, errcode ? strerror(errcode) : _("reason unknown"));
		return false;
	}

	/* save scanner state for the current sourcefile */
	sourcefile->srclines = sourceline;
	sourcefile->lexptr = lexptr;
	sourcefile->lexend = lexend;
	sourcefile->lexptr_begin = lexptr_begin;
	sourcefile->lexeme = lexeme;
	sourcefile->lasttok = lasttok;
	sourcefile->namespace = current_namespace;

	/* included file becomes the current source */
	sourcefile = s;
	lexptr = NULL;
	sourceline = 0;
	source = NULL;
	lasttok = 0;
	lexeof = false;
	eof_warned = false;
	if (! include_use_current_namespace)
		current_namespace = awk_namespace;
	else
		current_namespace = estrdup(current_namespace, strlen(current_namespace));

	include_use_current_namespace = false;	// reset it
	*srcfile_p = (void *) s;
	return true;
}

/* load_library --- load a shared library */

static bool
load_library(INSTRUCTION *file, void **srcfile_p)
{
	SRCFILE *s;
	char *src = file->lextok;
	int errcode;
	bool already_included;

	*srcfile_p = NULL;

	if (do_traditional || do_posix) {
		error_ln(file->source_line, _("@load is a gawk extension"));
		return false;
	}

	if (strlen(src) == 0) {
		if (do_lint)
			lintwarn_ln(file->source_line, _("empty filename after @load"));
		return true;
	}

	if (do_pretty_print && ! do_profile) {
		// create a fake one, don't try to open the file
		s = do_add_srcfile(SRC_EXTLIB, src, src, sourcefile);
	} else {
		s = add_srcfile(SRC_EXTLIB, src, sourcefile, &already_included, &errcode);
		if (s == NULL) {
			if (already_included)
				return true;
			error_ln(file->source_line,
				_("cannot open shared library `%s' for reading: %s"),
				src, errcode ? strerror(errcode) : _("reason unknown"));
			return false;
		}

		load_ext(s->src, s->fullpath);
	}

	*srcfile_p = (void *) s;
	return true;
}

/* next_sourcefile --- read program from the next source in srcfiles */

static void
next_sourcefile()
{
	static int (*closefunc)(int fd) = NULL;

	if (closefunc == NULL) {
		char *cp = getenv("AWKREADFUNC");

		/* If necessary, one day, test value for different functions.  */
		if (cp == NULL)
			closefunc = close;
		else
			closefunc = one_line_close;
	}

	/*
	 * This won't be true if there's an invalid character in
	 * the source file or source string (e.g., user typo).
	 * Previous versions of gawk did not core dump in such a
	 * case.
	 *
	 * assert(lexeof == true);
	 */

	lexeof = false;
	eof_warned = false;
	sourcefile->srclines = sourceline;	/* total no of lines in current file */
	if (sourcefile->fd > INVALID_HANDLE) {
		if (sourcefile->fd != fileno(stdin))  /* safety */
			(*closefunc)(sourcefile->fd);
		sourcefile->fd = INVALID_HANDLE;
	}
	if (sourcefile->buf != NULL) {
		efree(sourcefile->buf);
		sourcefile->buf = NULL;
		sourcefile->lexptr_begin = NULL;
	}

	while ((sourcefile = sourcefile->next) != NULL) {
		if (sourcefile == srcfiles)
			return;
		if (sourcefile->stype != SRC_EXTLIB)
			break;
	}

	if (sourcefile->lexptr_begin != NULL) {
		/* resume reading from already opened file (postponed to process '@include') */
		lexptr = sourcefile->lexptr;
		lexend = sourcefile->lexend;
		lasttok = sourcefile->lasttok;
		lexptr_begin = sourcefile->lexptr_begin;
		lexeme = sourcefile->lexeme;
		sourceline = sourcefile->srclines;
		source = sourcefile->src;
		set_current_namespace(sourcefile->namespace);
	} else {
		lexptr = NULL;
		sourceline = 0;
		source = NULL;
		lasttok = 0;
		set_current_namespace(awk_namespace);
	}
}

/* get_src_buf --- read the next buffer of source program */

static char *
get_src_buf()
{
	int n;
	char *scan;
	bool newfile;
	int savelen;
	struct stat sbuf;

	static ssize_t (*readfunc)(int, void *, size_t) = NULL;

	if (readfunc == NULL) {
		char *cp = getenv("AWKREADFUNC");

		/* If necessary, one day, test value for different functions.  */
		if (cp == NULL)
			/*
			 * cast is to remove warnings on systems with
			 * different return types for read.
			 */
			readfunc = ( ssize_t(*)(int, void *, size_t) ) read;
		else
			readfunc = read_one_line;
	}

	newfile = false;
	if (sourcefile == srcfiles)
		return NULL;

	if (sourcefile->stype == SRC_CMDLINE) {
		if (sourcefile->bufsize == 0) {
			sourcefile->bufsize = strlen(sourcefile->src);
			lexptr = lexptr_begin = lexeme = sourcefile->src;
			lexend = lexptr + sourcefile->bufsize;
			sourceline = 1;
			if (sourcefile->bufsize == 0) {
				/*
				 * Yet Another Special case:
				 *	gawk '' /path/name
				 * Sigh.
				 */
				static bool warned = false;

				if (do_lint && ! warned) {
					warned = true;
					lintwarn(_("empty program text on command line"));
				}
				lexeof = true;
			}
		} else if (sourcefile->buf == NULL  && *(lexptr-1) != '\n') {
			/*
			 * The following goop is to ensure that the source
			 * ends with a newline and that the entire current
			 * line is available for error messages.
			 */
			int offset;
			char *buf;

			offset = lexptr - lexeme;
			for (scan = lexeme; scan > lexptr_begin; scan--)
				if (*scan == '\n') {
					scan++;
					break;
				}
			savelen = lexptr - scan;
			emalloc(buf, char *, savelen + 1);
			memcpy(buf, scan, savelen);
			thisline = buf;
			lexptr = buf + savelen;
			*lexptr = '\n';
			lexeme = lexptr - offset;
			lexptr_begin = buf;
			lexend = lexptr + 1;
			sourcefile->buf = buf;
		} else
			lexeof = true;
		return lexptr;
	}

	if (sourcefile->fd <= INVALID_HANDLE) {
		int fd;
		int l;

		source = sourcefile->src;
		if (source == NULL)
			return NULL;
		fd = srcopen(sourcefile);
		if (fd <= INVALID_HANDLE) {
			char *in;

			/* suppress file name and line no. in error mesg */
			in = source;
			source = NULL;
			error(_("cannot open source file `%s' for reading: %s"),
				in, strerror(errno));
			errcount++;
			lexeof = true;
			return sourcefile->src;
		}

		sourcefile->fd = fd;
		l = optimal_bufsize(fd, &sbuf);
		/*
		 * Make sure that something silly like
		 * 	AWKBUFSIZE=8 make check
		 * works ok.
		 */
#define A_DECENT_BUFFER_SIZE	128
		if (l < A_DECENT_BUFFER_SIZE)
			l = A_DECENT_BUFFER_SIZE;
#undef A_DECENT_BUFFER_SIZE
		sourcefile->bufsize = l;
		newfile = true;
		emalloc(sourcefile->buf, char *, sourcefile->bufsize);
		memset(sourcefile->buf, '\0', sourcefile->bufsize);	// keep valgrind happy
		lexptr = lexptr_begin = lexeme = sourcefile->buf;
		savelen = 0;
		sourceline = 1;
		thisline = NULL;
	} else {
		/*
		 * Here, we retain the current source line in the beginning of the buffer.
		 */
		int offset;
		for (scan = lexeme; scan > lexptr_begin; scan--)
			if (*scan == '\n') {
				scan++;
				break;
			}

		savelen = lexptr - scan;
		offset = lexptr - lexeme;

		if (savelen > 0) {
			/*
			 * Need to make sure we have room left for reading new text;
			 * grow the buffer (by doubling, an arbitrary choice), if the retained line
			 * takes up more than a certain percentage (50%, again an arbitrary figure)
			 * of the available space.
			 */

			if (savelen > sourcefile->bufsize / 2) { /* long line or token  */
				sourcefile->bufsize *= 2;
				erealloc(sourcefile->buf, char *, sourcefile->bufsize);
				scan = sourcefile->buf + (scan - lexptr_begin);
				lexptr_begin = sourcefile->buf;
			}

			thisline = lexptr_begin;
			memmove(thisline, scan, savelen);
			lexptr = thisline + savelen;
			lexeme = lexptr - offset;
		} else {
			savelen = 0;
			lexptr = lexeme = lexptr_begin;
			thisline = NULL;
		}
	}

	n = (*readfunc)(sourcefile->fd, lexptr, sourcefile->bufsize - savelen);
	if (n == -1) {
		error(_("cannot read source file `%s': %s"),
				source, strerror(errno));
		errcount++;
		lexeof = true;
	} else {
		lexend = lexptr + n;
		if (n == 0) {
			static bool warned = false;
			if (do_lint && newfile && ! warned) {
				warned = true;
				sourceline = 0;
				lintwarn(_("source file `%s' is empty"), source);
			}
			lexeof = true;
		}
	}
	return sourcefile->buf;
}

/* tokadd --- add a character to the token buffer */

#define	tokadd(x) (*tok++ = (x), tok == tokend ? tokexpand() : tok)

/* tokexpand --- grow the token buffer */

static char *
tokexpand()
{
	static size_t toksize;
	int tokoffset;

	if (tokstart != NULL) {
		tokoffset = tok - tokstart;
		toksize *= 2;
		erealloc(tokstart, char *, toksize);
		tok = tokstart + tokoffset;
	} else {
		toksize = 60;
		emalloc(tokstart, char *, toksize);
		tok = tokstart;
	}
	tokend = tokstart + toksize;
	return tok;
}

/* check_bad_char --- fatal if c isn't allowed in gawk source code */

/*
 * The error message was inspired by someone who decided to put
 * a physical \0 byte into the source code to see what would
 * happen and then filed a bug report about it.  Sigh.
 */

static void
check_bad_char(int c)
{
	/* allow escapes. needed for autoconf. bleah. */
	switch (c) {
	case '\a':
	case '\b':
	case '\f':
	case '\n':
	case '\r':
	case '\t':
		return;
	default:
		break;
	}

	if (iscntrl(c) && ! isspace(c))
		// This is a PEBKAC error, but we'll be nice and not say so.
		fatal(_("error: invalid character '\\%03o' in source code"), c & 0xFF);
}

/* nextc --- get the next input character */

// For namespaces, -e chunks must be syntactic units.
#define NO_CONTINUE_SOURCE_STRINGS	1

static int
nextc(bool check_for_bad)
{
	if (gawk_mb_cur_max > 1) {
again:
#ifdef NO_CONTINUE_SOURCE_STRINGS
		if (lexeof)
			return END_FILE;
#else
		if (lexeof) {
			if (sourcefile->next == srcfiles)
				return END_FILE;
			else
				next_sourcefile();
		}
#endif
		if (lexptr == NULL || lexptr >= lexend) {
			if (get_src_buf())
				goto again;
			return END_SRC;
		}

		/* Update the buffer index.  */
		cur_ring_idx = (cur_ring_idx == RING_BUFFER_SIZE - 1)? 0 :
			cur_ring_idx + 1;

		/* Did we already check the current character?  */
		if (cur_char_ring[cur_ring_idx] == 0) {
			/* No, we need to check the next character on the buffer.  */
			int idx, work_ring_idx = cur_ring_idx;
			mbstate_t tmp_state;
			size_t mbclen;

			for (idx = 0; lexptr + idx < lexend; idx++) {
				tmp_state = cur_mbstate;
				mbclen = mbrlen(lexptr, idx + 1, &tmp_state);

				if (mbclen == 1 || mbclen == (size_t)-1 || mbclen == 0) {
					/* It is a singlebyte character, non-complete multibyte
					   character or EOF.  We treat it as a singlebyte
					   character.  */
					cur_char_ring[work_ring_idx] = 1;
					break;
				} else if (mbclen == (size_t)-2) {
					/* It is not a complete multibyte character.  */
					cur_char_ring[work_ring_idx] = idx + 1;
				} else {
					/* mbclen > 1 */
					cur_char_ring[work_ring_idx] = mbclen;
					break;
				}
				work_ring_idx = (work_ring_idx == RING_BUFFER_SIZE - 1)?
					0 : work_ring_idx + 1;
			}
			cur_mbstate = tmp_state;

			/* Put a mark on the position on which we write next character.  */
			work_ring_idx = (work_ring_idx == RING_BUFFER_SIZE - 1)?
				0 : work_ring_idx + 1;
			cur_char_ring[work_ring_idx] = 0;
		}
		if (check_for_bad || *lexptr == '\0')
			check_bad_char(*lexptr);

		return (int) (unsigned char) *lexptr++;
	} else {
		do {
#ifdef NO_CONTINUE_SOURCE_STRINGS
			if (lexeof)
				return END_FILE;
#else
			if (lexeof) {
				if (sourcefile->next == srcfiles)
					return END_FILE;
				else
					next_sourcefile();
			}
#endif
			if (lexptr && lexptr < lexend) {
				if (check_for_bad || *lexptr == '\0')
					check_bad_char(*lexptr);
				return ((int) (unsigned char) *lexptr++);
			}
		} while (get_src_buf());
		return END_SRC;
	}
}
#undef NO_CONTINUE_SOURCE_STRINGS

/* pushback --- push a character back on the input */

static inline void
pushback(void)
{
	if (gawk_mb_cur_max > 1)
		cur_ring_idx = (cur_ring_idx == 0)? RING_BUFFER_SIZE - 1 :
			cur_ring_idx - 1;
	(! lexeof && lexptr && lexptr > lexptr_begin ? lexptr-- : lexptr);
}

/*
 * get_comment --- collect comment text.
 * 	Flag = EOL_COMMENT for end-of-line comments.
 * 	Flag = BLOCK_COMMENT for self-contained comments.
 */

static int
get_comment(enum commenttype flag, INSTRUCTION **comment_instruction)
{
	int c;
	int sl;
	char *p1;
	char *p2;

	tok = tokstart;
	tokadd('#');
	sl = sourceline;

	while (true) {
		while ((c = nextc(false)) != '\n' && c != END_FILE) {
			/* ignore \r characters */
			if (c != '\r')
				tokadd(c);
		}
		if (flag == EOL_COMMENT) {
			/* comment at end of line.  */
			if (c == '\n')
				tokadd(c);
			break;
		}
		if (c == '\n') {
			tokadd(c);
			sourceline++;
			do {
				c = nextc(false);
				if (c == '\n') {
					sourceline++;
					tokadd(c);
				}
			} while (c != END_FILE && isspace(c));
			if (c == END_FILE)
				break;
			else if (c != '#') {
				pushback();
				sourceline--;
				break;
			} else
				tokadd(c);
		} else
			break;
	}

	/* remove any trailing blank lines (consecutive \n) from comment */
	p1 = tok - 1;
	p2 = tok - 2;
	while (*p1 == '\n' && *p2 == '\n') {
		p1--;
		p2--;
		tok--;
	}

	(*comment_instruction) = bcalloc(Op_comment, 1, sl);
	(*comment_instruction)->source_file = source;
	(*comment_instruction)->memory = make_str_node(tokstart, tok - tokstart, 0);
	(*comment_instruction)->memory->comment_type = flag;

	return c;
}

/* allow_newline --- allow newline after &&, ||, ? and : */

static void
allow_newline(INSTRUCTION **new_comment)
{
	int c;

	for (;;) {
		c = nextc(true);
		if (c == END_FILE) {
			pushback();
			break;
		}
		if (c == '#') {
			if (do_pretty_print && ! do_profile) {
				/* collect comment byte code iff doing pretty print but not profiling.  */
				c = get_comment(EOL_COMMENT, new_comment);
			} else {
				while ((c = nextc(false)) != '\n' && c != END_FILE)
					continue;
			}
			if (c == END_FILE) {
				pushback();
				break;
			}
		}
		if (c == '\n')
			sourceline++;
		if (! isspace(c)) {
			pushback();
			break;
		}
	}
}

/* newline_eof --- return newline or EOF as needed and adjust variables */

/*
 * This routine used to be a macro, however GCC 4.6.2 warned about
 * the result of a computation not being used.  Converting to a function
 * removes the warnings.
 */

static int
newline_eof()
{
	/* NB: a newline at end does not start a source line. */
	if (lasttok != NEWLINE) {
                pushback();
		if (do_lint && ! eof_warned) {
        		lintwarn(_("source file does not end in newline"));
			eof_warned = true;
		}
		sourceline++;
		return NEWLINE;
	}

	sourceline--;
	eof_warned = false;
	return LEX_EOF;
}

/* yylex --- Read the input and turn it into tokens. */

static int
#ifdef USE_EBCDIC
yylex_ebcdic(void)
#else
yylex(void)
#endif
{
	int c;
	bool seen_e = false;		/* These are for numbers */
	bool seen_point = false;
	bool esc_seen;		/* for literal strings */
	int mid;
	int base;
	static bool did_newline = false;
	char *tokkey;
	bool inhex = false;
	bool intlstr = false;
	AWKNUM d;
	bool collecting_typed_regexp = false;
	static int qm_col_count = 0;

#define GET_INSTRUCTION(op) bcalloc(op, 1, sourceline)

#define NEWLINE_EOF newline_eof()

	yylval = (INSTRUCTION *) NULL;
	if (lasttok == SUBSCRIPT) {
		lasttok = 0;
		return SUBSCRIPT;
	}

	if (lasttok == LEX_EOF)		/* error earlier in current source, must give up !! */
		return 0;

	c = nextc(! want_regexp);
	if (c == END_SRC)
		return 0;
	if (c == END_FILE)
		return lasttok = NEWLINE_EOF;
	pushback();

	lexeme = lexptr;
	thisline = NULL;

collect_regexp:
	if (want_regexp) {
		int in_brack = 0;	/* count brackets, [[:alnum:]] allowed */
		int b_index = -1;
		int cur_index = 0;

		/*
		 * Here is what's ok with brackets:
		 *
		 * [..[..] []] [^]] [.../...]
		 * [...\[...] [...\]...] [...\/...]
		 *
		 * (Remember that all of the above are inside /.../)
		 *
		 * The code for \ handles \[, \] and \/.
		 *
		 * Otherwise, track the first open [ position, and if
		 * an embedded ] occurs, allow it to pass through
		 * if it's right after the first [ or after [^.
		 *
		 * Whew!
		 */

		want_regexp = false;
		tok = tokstart;
		for (;;) {
			c = nextc(false);

			cur_index = tok - tokstart;
			if (gawk_mb_cur_max == 1 || nextc_is_1stbyte) switch (c) {
			case '[':
				if (nextc(false) == ':' || in_brack == 0) {
					in_brack++;
					if (in_brack == 1)
						b_index = tok - tokstart;
				}
				pushback();
				break;
			case ']':
				if (in_brack > 0
				    && (cur_index == b_index + 1
					|| (cur_index == b_index + 2 && tok[-1] == '^')))
					; /* do nothing */
				else {
					in_brack--;
					if (in_brack == 0)
						b_index = -1;
				}
				break;
			case '\\':
				if ((c = nextc(false)) == END_FILE) {
					pushback();
					yyerror(_("unterminated regexp ends with `\\' at end of file"));
					goto end_regexp; /* kludge */
				}
				if (c == '\r')	/* allow MS-DOS files. bleah */
					c = nextc(true);
				if (c == '\n') {
					sourceline++;
					continue;
				} else {
					tokadd('\\');
					tokadd(c);
					continue;
				}
				break;
			case '/':	/* end of the regexp */
				if (in_brack > 0)
					break;
end_regexp:
				yylval = GET_INSTRUCTION(Op_token);
				yylval->lextok = estrdup(tokstart, tok - tokstart);
				if (do_lint) {
					int peek = nextc(true);

					pushback();
					if (peek == 'i' || peek == 's') {
						if (source)
							lintwarn(
						_("%s: %d: tawk regex modifier `/.../%c' doesn't work in gawk"),
								source, sourceline, peek);
						else
							lintwarn(
						_("tawk regex modifier `/.../%c' doesn't work in gawk"),
								peek);
					}
				}
				if (collecting_typed_regexp) {
					collecting_typed_regexp = false;
					lasttok = TYPED_REGEXP;
				} else
					lasttok = REGEXP;

				return lasttok;
			case '\n':
				pushback();
				yyerror(_("unterminated regexp"));
				goto end_regexp;	/* kludge */
			case END_FILE:
				pushback();
				yyerror(_("unterminated regexp at end of file"));
				goto end_regexp;	/* kludge */
			}
			tokadd(c);
		}
	}
retry:

	/* skipping \r is a hack, but windows is just too pervasive. sigh. */
	while ((c = nextc(true)) == ' ' || c == '\t' || c == '\r')
		continue;

	lexeme = lexptr ? lexptr - 1 : lexptr;
	thisline = NULL;
	tok = tokstart;

	if (gawk_mb_cur_max == 1 || nextc_is_1stbyte)
	switch (c) {
	case END_SRC:
		return 0;

	case END_FILE:
		return lasttok = NEWLINE_EOF;

	case '\n':
		sourceline++;
		return lasttok = NEWLINE;

	case '#':		/* it's a comment */
		yylval = NULL;
		if (do_pretty_print && ! do_profile) {
			/*
			 * Collect comment byte code iff doing pretty print
			 * but not profiling.
			 */
			INSTRUCTION *new_comment;

			if (lasttok == NEWLINE || lasttok == 0)
				c = get_comment(BLOCK_COMMENT, & new_comment);
			else
				c = get_comment(EOL_COMMENT, & new_comment);

			yylval = new_comment;

			if (c == END_FILE) {
				pushback();
				return lasttok = NEWLINE;
			}
		} else {
			while ((c = nextc(false)) != '\n') {
				if (c == END_FILE)
					return lasttok = NEWLINE_EOF;
			}
		}
		sourceline++;
		return lasttok = NEWLINE;

	case '@':
		c = nextc(true);
		if (c == '/') {
			want_regexp = true;
			collecting_typed_regexp = true;
			goto collect_regexp;
		}
		pushback();
		at_seen++;
		return lasttok = '@';

	case '\\':
#ifdef RELAXED_CONTINUATION
		/*
		 * This code purports to allow comments and/or whitespace
		 * after the `\' at the end of a line used for continuation.
		 * Use it at your own risk. We think it's a bad idea, which
		 * is why it's not on by default.
		 */
		yylval = NULL;
		if (! do_traditional) {
			INSTRUCTION *new_comment;

			/* strip trailing white-space and/or comment */
			while ((c = nextc(true)) == ' ' || c == '\t' || c == '\r')
				continue;
			if (c == '#') {
				static bool warned = false;

				if (do_lint && ! warned) {
					warned = true;
					lintwarn(
		_("use of `\\ #...' line continuation is not portable"));
				}
				if (do_pretty_print && ! do_profile) {
					c = get_comment(EOL_COMMENT, & new_comment);
					yylval = new_comment;
					return lasttok = c;
				} else {
					while ((c = nextc(false)) != '\n')
						if (c == END_FILE)
							break;
				}
			}
			pushback();
		}
#endif /* RELAXED_CONTINUATION */
		c = nextc(true);
		if (c == '\r')	/* allow MS-DOS files. bleah */
			c = nextc(true);
		if (c == '\n') {
			sourceline++;
			goto retry;
		} else {
			yyerror(_("backslash not last character on line"));
			return lasttok = LEX_EOF;
		}
		break;

	case '?':
		qm_col_count++;
		// fall through
	case ':':
		yylval = GET_INSTRUCTION(Op_cond_exp);
		if (qm_col_count > 0) {
			if (! do_posix) {
				INSTRUCTION *new_comment = NULL;
				allow_newline(& new_comment);
				yylval->comment = new_comment;
			}
			if (c == ':')
				qm_col_count--;
		}
		return lasttok = c;

		/*
		 * in_parens is undefined unless we are parsing a print
		 * statement (in_print), but why bother with a check?
		 */
	case ')':
		in_parens--;
		return lasttok = c;

	case '(':
		in_parens++;
		return lasttok = c;
	case '$':
		yylval = GET_INSTRUCTION(Op_field_spec);
		return lasttok = c;
	case '{':
		if (++in_braces == 1)
			firstline = sourceline;
		/* fall through */
	case ';':
	case ',':
	case '[':
		return lasttok = c;
	case ']':
		c = nextc(true);
		pushback();
		if (c == '[') {
			if (do_traditional)
				fatal(_("multidimensional arrays are a gawk extension"));
			if (do_lint_extensions)
				lintwarn(_("multidimensional arrays are a gawk extension"));
			yylval = GET_INSTRUCTION(Op_sub_array);
			lasttok = ']';
		} else {
			yylval = GET_INSTRUCTION(Op_subscript);
			lasttok = SUBSCRIPT;	/* end of subscripts */
		}
		return ']';

	case '*':
		if ((c = nextc(true)) == '=') {
			yylval = GET_INSTRUCTION(Op_assign_times);
			return lasttok = ASSIGNOP;
		} else if (do_posix) {
			pushback();
			yylval = GET_INSTRUCTION(Op_times);
			return lasttok = '*';
		} else if (c == '*') {
			/* make ** and **= aliases for ^ and ^= */
			static bool did_warn_op = false, did_warn_assgn = false;

			if (nextc(true) == '=') {
				if (! did_warn_assgn) {
					did_warn_assgn = true;
					if (do_lint)
						lintwarn(_("POSIX does not allow operator `%s'"), "**=");
					if (do_lint_old)
						lintwarn(_("operator `%s' is not supported in old awk"), "**=");
				}
				yylval = GET_INSTRUCTION(Op_assign_exp);
				return ASSIGNOP;
			} else {
				pushback();
				if (! did_warn_op) {
					did_warn_op = true;
					if (do_lint)
						lintwarn(_("POSIX does not allow operator `%s'"), "**");
					if (do_lint_old)
						lintwarn(_("operator `%s' is not supported in old awk"), "**");
				}
				yylval = GET_INSTRUCTION(Op_exp);
				return lasttok = '^';
			}
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_times);
		return lasttok = '*';

	case '/':
		if (nextc(false) == '=') {
			pushback();
			return lasttok = SLASH_BEFORE_EQUAL;
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_quotient);
		return lasttok = '/';

	case '%':
		if (nextc(true) == '=') {
			yylval = GET_INSTRUCTION(Op_assign_mod);
			return lasttok = ASSIGNOP;
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_mod);
		return lasttok = '%';

	case '^':
	{
		static bool did_warn_op = false, did_warn_assgn = false;

		if (nextc(true) == '=') {
			if (do_lint_old && ! did_warn_assgn) {
				did_warn_assgn = true;
				lintwarn(_("operator `%s' is not supported in old awk"), "^=");
			}
			yylval = GET_INSTRUCTION(Op_assign_exp);
			return lasttok = ASSIGNOP;
		}
		pushback();
		if (do_lint_old && ! did_warn_op) {
			did_warn_op = true;
			lintwarn(_("operator `%s' is not supported in old awk"), "^");
		}
		yylval = GET_INSTRUCTION(Op_exp);
		return lasttok = '^';
	}

	case '+':
		if ((c = nextc(true)) == '=') {
			yylval = GET_INSTRUCTION(Op_assign_plus);
			return lasttok = ASSIGNOP;
		}
		if (c == '+') {
			yylval = GET_INSTRUCTION(Op_symbol);
			return lasttok = INCREMENT;
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_plus);
		return lasttok = '+';

	case '!':
		if ((c = nextc(true)) == '=') {
			yylval = GET_INSTRUCTION(Op_notequal);
			return lasttok = RELOP;
		}
		if (c == '~') {
			yylval = GET_INSTRUCTION(Op_nomatch);
			return lasttok = MATCHOP;
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_symbol);
		return lasttok = '!';

	case '<':
		if (nextc(true) == '=') {
			yylval = GET_INSTRUCTION(Op_leq);
			return lasttok = RELOP;
		}
		yylval = GET_INSTRUCTION(Op_less);
		pushback();
		return lasttok = '<';

	case '=':
		if (nextc(true) == '=') {
			yylval = GET_INSTRUCTION(Op_equal);
			return lasttok = RELOP;
		}
		yylval = GET_INSTRUCTION(Op_assign);
		pushback();
		return lasttok = ASSIGN;

	case '>':
		if ((c = nextc(true)) == '=') {
			yylval = GET_INSTRUCTION(Op_geq);
			return lasttok = RELOP;
		} else if (c == '>') {
			yylval = GET_INSTRUCTION(Op_symbol);
			yylval->redir_type = redirect_append;
			return lasttok = IO_OUT;
		}
		pushback();
		if (in_print && in_parens == 0) {
			yylval = GET_INSTRUCTION(Op_symbol);
			yylval->redir_type = redirect_output;
			return lasttok = IO_OUT;
		}
		yylval = GET_INSTRUCTION(Op_greater);
		return lasttok = '>';

	case '~':
		yylval = GET_INSTRUCTION(Op_match);
		return lasttok = MATCHOP;

	case '}':
		/*
		 * Added did newline stuff.  Easier than
		 * hacking the grammar.
		 */
		if (did_newline) {
			did_newline = false;
			if (--in_braces == 0)
				lastline = sourceline;
			return lasttok = c;
		}
		did_newline = true;
		--lexptr;	/* pick up } next time */
		return lasttok = NEWLINE;

	case '"':
	string:
		esc_seen = false;
		/*
		 * Allow any kind of junk in quoted string,
		 * so pass false to nextc().
		 */
		while ((c = nextc(false)) != '"') {
			if (c == '\n') {
				pushback();
				yyerror(_("unterminated string"));
				return lasttok = LEX_EOF;
			}
			if ((gawk_mb_cur_max == 1 || nextc_is_1stbyte) &&
			    c == '\\') {
				c = nextc(true);
				if (c == '\r')	/* allow MS-DOS files. bleah */
					c = nextc(true);
				if (c == '\n') {
					if (do_posix)
						fatal(_("POSIX does not allow physical newlines in string values"));
					else if (do_lint)
						lintwarn(_("backslash string continuation is not portable"));
					sourceline++;
					continue;
				}
				esc_seen = true;
				if (! want_source || c != '"')
					tokadd('\\');
			}
			if (c == END_FILE) {
				pushback();
				yyerror(_("unterminated string"));
				return lasttok = LEX_EOF;
			}
			tokadd(c);
		}
		yylval = GET_INSTRUCTION(Op_token);
		if (want_source) {
			yylval->lextok = estrdup(tokstart, tok - tokstart);
			// See the comment in the production for @namespace.
			if (want_namespace)
				change_namespace(yylval->lextok);
			return lasttok = FILENAME;
		}

		yylval->opcode = Op_push_i;
		yylval->memory = make_str_node(tokstart,
					tok - tokstart, esc_seen ? SCAN : 0);
		if (intlstr) {
			yylval->memory->flags |= INTLSTR;
			intlstr = false;
			if (do_intl)
				dumpintlstr(yylval->memory->stptr, yylval->memory->stlen);
		}
		return lasttok = YSTRING;

	case '-':
		if ((c = nextc(true)) == '=') {
			yylval = GET_INSTRUCTION(Op_assign_minus);
			return lasttok = ASSIGNOP;
		}
		if (c == '-') {
			yylval = GET_INSTRUCTION(Op_symbol);
			return lasttok = DECREMENT;
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_minus);
		return lasttok = '-';

	case '.':
		c = nextc(true);
		pushback();
		if (! isdigit(c))
			return lasttok = '.';
		else
			c = '.';
		/* FALL THROUGH */
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		/* It's a number */
		for (;;) {
			bool gotnumber = false;

			tokadd(c);
			switch (c) {
			case 'x':
			case 'X':
				if (do_traditional)
					goto done;
				if (tok == tokstart + 2) {
					int peek = nextc(true);

					if (isxdigit(peek)) {
						inhex = true;
						pushback();	/* following digit */
					} else {
						pushback();	/* x or X */
						goto done;
					}
				}
				break;
			case '.':
				/* period ends exponent part of floating point number */
				if (seen_point || seen_e) {
					gotnumber = true;
					break;
				}
				seen_point = true;
				break;
			case 'e':
			case 'E':
				if (inhex)
					break;
				if (seen_e) {
					gotnumber = true;
					break;
				}
				seen_e = true;
				if ((c = nextc(true)) == '-' || c == '+') {
					int c2 = nextc(true);

					if (isdigit(c2)) {
						tokadd(c);
						tokadd(c2);
					} else {
						pushback();	/* non-digit after + or - */
						pushback();	/* + or - */
						pushback();	/* e or E */
					}
				} else if (! isdigit(c)) {
					pushback();	/* character after e or E */
					pushback();	/* e or E */
				} else {
					pushback();	/* digit */
				}
				break;
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'c':
			case 'C':
			case 'D':
			case 'd':
			case 'f':
			case 'F':
				if (do_traditional || ! inhex)
					goto done;
				/* fall through */
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				break;
			default:
			done:
				gotnumber = true;
			}
			if (gotnumber)
				break;
			c = nextc(true);
		}
		pushback();

		tokadd('\0');
		yylval = GET_INSTRUCTION(Op_push_i);

		base = 10;
		if (! do_traditional) {
			base = get_numbase(tokstart, strlen(tokstart)-1, false);
			if (do_lint) {
				if (base == 8)
					lintwarn("numeric constant `%.*s' treated as octal",
						(int) strlen(tokstart)-1, tokstart);
				else if (base == 16)
					lintwarn("numeric constant `%.*s' treated as hexadecimal",
						(int) strlen(tokstart)-1, tokstart);
			}
		}

#ifdef HAVE_MPFR
		if (do_mpfr) {
			NODE *r;

			if (! seen_point && ! seen_e) {
				r = mpg_integer();
				mpg_strtoui(r->mpg_i, tokstart, strlen(tokstart), NULL, base);
				errno = 0;
			} else {
				int tval;
				r = mpg_float();
				tval = mpfr_strtofr(r->mpg_numbr, tokstart, NULL, base, ROUND_MODE);
				errno = 0;
				IEEE_FMT(r->mpg_numbr, tval);
			}
			yylval->memory = set_profile_text(r, tokstart, strlen(tokstart)-1);
			return lasttok = YNUMBER;
		}
#endif
		if (base != 10)
			d = nondec2awknum(tokstart, strlen(tokstart)-1, NULL);
		else
			d = atof(tokstart);
		yylval->memory = set_profile_text(make_number(d), tokstart, strlen(tokstart) - 1);
		if (d <= INT32_MAX && d >= INT32_MIN && d == (int32_t) d)
			yylval->memory->flags |= NUMINT;
		return lasttok = YNUMBER;

	case '&':
		if ((c = nextc(true)) == '&') {
			yylval = GET_INSTRUCTION(Op_and);
			INSTRUCTION *new_comment = NULL;
			allow_newline(& new_comment);
			yylval->comment = new_comment;

			return lasttok = LEX_AND;
		}
		pushback();
		yylval = GET_INSTRUCTION(Op_symbol);
		return lasttok = '&';

	case '|':
		if ((c = nextc(true)) == '|') {
			yylval = GET_INSTRUCTION(Op_or);
			INSTRUCTION *new_comment = NULL;
			allow_newline(& new_comment);
			yylval->comment = new_comment;

			return lasttok = LEX_OR;
		} else if (! do_traditional && c == '&') {
			yylval = GET_INSTRUCTION(Op_symbol);
			yylval->redir_type = redirect_twoway;

			return lasttok = (in_print && in_parens == 0 ? IO_OUT : IO_IN);
		}
		pushback();
		if (in_print && in_parens == 0) {
			yylval = GET_INSTRUCTION(Op_symbol);
			yylval->redir_type = redirect_pipe;
			return lasttok = IO_OUT;
		} else {
			yylval = GET_INSTRUCTION(Op_symbol);
			yylval->redir_type = redirect_pipein;
			return lasttok = IO_IN;
		}
	}

	if (! is_letter(c)) {
		yyerror(_("invalid char '%c' in expression"), c);
		return lasttok = LEX_EOF;
	}

	/*
	 * Lots of fog here.  Consider:
	 *
	 * print "xyzzy"$_"foo"
	 *
	 * Without the check for ` lasttok != '$' ', this is parsed as
	 *
	 * print "xxyzz" $(_"foo")
	 *
	 * With the check, it is "correctly" parsed as three
	 * string concatenations.  Sigh.  This seems to be
	 * "more correct", but this is definitely one of those
	 * occasions where the interactions are funny.
	 */
	if (! do_traditional && c == '_' && lasttok != '$') {
		if ((c = nextc(true)) == '"') {
			intlstr = true;
			goto string;
		}
		pushback();
		c = '_';
	}

	/* it's some type of name-type-thing.  Find its length. */
	tok = tokstart;
	while (c != END_FILE && is_identchar(c)) {
		tokadd(c);
		c = nextc(true);

		if (! do_traditional && c == ':') {
			int peek = nextc(true);

			if (peek == ':') {	// saw identifier::
				tokadd(c);
				tokadd(c);
				c = nextc(true);
			} else
				pushback();
				// then continue around the loop, c == ':'
		}
	}
	tokadd('\0');
	pushback();

	(void) validate_qualified_name(tokstart);

	/* See if it is a special token. */
	if ((mid = check_qualified_special(tokstart)) >= 0) {
		static int warntab[sizeof(tokentab) / sizeof(tokentab[0])];
		int class = tokentab[mid].class;

		switch (class) {
		case LEX_NSINCLUDE:
		case LEX_EVAL:
		case LEX_INCLUDE:
		case LEX_LOAD:
		case LEX_NAMESPACE:
			if (lasttok != '@')
				goto out;
		default:
			break;
		}

		/* allow parameter names to shadow the names of gawk extension built-ins */
		if ((tokentab[mid].flags & GAWKX) != 0) {
			NODE *f;

			switch (want_param_names) {
			case FUNC_HEADER:
				/* in header, defining parameter names */
				goto out;
			case FUNC_BODY:
				/* in body, name must be in symbol table for it to be a parameter */
				if ((f = lookup(tokstart)) != NULL) {
					if (f->type == Node_builtin_func)
						break;
					else
						goto out;
				}
				/* else
					fall through */
			case DONT_CHECK:
				/* regular code */
				break;
			default:
				cant_happen("bad value %d for want_param_names", (int) want_param_names);
				break;
			}
		}

		if (do_lint) {
			if (do_lint_extensions && (tokentab[mid].flags & GAWKX) != 0 && (warntab[mid] & GAWKX) == 0) {
				lintwarn(_("`%s' is a gawk extension"),
					tokentab[mid].operator);
				warntab[mid] |= GAWKX;
			}
			if ((tokentab[mid].flags & NOT_POSIX) != 0 && (warntab[mid] & NOT_POSIX) == 0) {
				lintwarn(_("POSIX does not allow `%s'"),
					tokentab[mid].operator);
				warntab[mid] |= NOT_POSIX;
			}
		}
		if (do_lint_old && (tokentab[mid].flags & NOT_OLD) != 0
				 && (warntab[mid] & NOT_OLD) == 0
		) {
			lintwarn(_("`%s' is not supported in old awk"),
					tokentab[mid].operator);
			warntab[mid] |= NOT_OLD;
		}

		if ((tokentab[mid].flags & BREAK) != 0)
			break_allowed++;
		if ((tokentab[mid].flags & CONTINUE) != 0)
			continue_allowed++;

		switch (class) {
		case LEX_NSINCLUDE:
			include_use_current_namespace = true;
			goto make_at_token;	// can't fall through
		case LEX_NAMESPACE:
			want_namespace = true;
			// fall through
		case LEX_INCLUDE:
		case LEX_LOAD:
	make_at_token:
			want_source = true;
			break;
		case LEX_EVAL:
			if (in_main_context())
				goto out;
			emalloc(tokkey, char *, tok - tokstart + 1);
			tokkey[0] = '@';
			memcpy(tokkey + 1, tokstart, tok - tokstart);
			yylval = GET_INSTRUCTION(Op_token);
			yylval->lextok = tokkey;
			break;

		case LEX_FUNCTION:
		case LEX_BEGIN:
		case LEX_END:
		case LEX_BEGINFILE:
		case LEX_ENDFILE:
			yylval = bcalloc(tokentab[mid].value, 4, sourceline);
			break;

		case LEX_FOR:
		case LEX_WHILE:
		case LEX_DO:
		case LEX_SWITCH:
			if (! do_pretty_print)
				return lasttok = class;
			/* fall through */
		case LEX_CASE:
			yylval = bcalloc(tokentab[mid].value, 2, sourceline);
			break;

		/*
		 * These must be checked here, due to the LALR nature of the parser,
		 * the rules for continue and break may not be reduced until after
		 * a token that increments the xxx_allowed varibles is seen. Bleah.
		 */
		case LEX_CONTINUE:
			if (! continue_allowed) {
				error_ln(sourceline,
					_("`continue' is not allowed outside a loop"));
				errcount++;
			}
			goto make_instruction;

		case LEX_BREAK:
			if (! break_allowed) {
				error_ln(sourceline,
					_("`break' is not allowed outside a loop or switch"));
				errcount++;
			}
			goto make_instruction;

		default:
make_instruction:
			yylval = GET_INSTRUCTION(tokentab[mid].value);
			if (class == LEX_BUILTIN || class == LEX_LENGTH)
				yylval->builtin_idx = mid;
			break;
		}
		return lasttok = class;
	}
out:
	if (want_param_names == FUNC_HEADER)
		tokkey = estrdup(tokstart, tok - tokstart - 1);
	else
		tokkey = qualify_name(tokstart, tok - tokstart - 1);

	if (*lexptr == '(') {
		yylval = bcalloc(Op_token, 2, sourceline);
		yylval->lextok = tokkey;
		return lasttok = FUNC_CALL;
	} else {
		static bool goto_warned = false;

		yylval = GET_INSTRUCTION(Op_token);
		yylval->lextok = tokkey;

#define SMART_ALECK	1
		if (SMART_ALECK
		    && do_lint
		    && ! goto_warned
		    && tolower(tokkey[0]) == 'g'
		    && strcasecmp(tokkey, "goto") == 0) {
			goto_warned = true;
			lintwarn(_("`goto' considered harmful!"));
		}
		return lasttok = NAME;
	}

#undef GET_INSTRUCTION
#undef NEWLINE_EOF
}

/* It's EBCDIC in a Bison grammar, run for the hills!

   Or, convert single-character tokens coming out of yylex() from EBCDIC to
   ASCII values on-the-fly so that the parse tables need not be regenerated
   for EBCDIC systems.  */
#ifdef USE_EBCDIC
static int
yylex(void)
{
	static char etoa_xlate[256];
	static bool do_etoa_init = true;
	int tok;

	if (do_etoa_init)
	{
		for (tok = 0; tok < 256; tok++)
			etoa_xlate[tok] = (char) tok;
#ifdef HAVE___ETOA_L
		/* IBM helpfully provides this function.  */
		__etoa_l(etoa_xlate, sizeof(etoa_xlate));
#else
# error "An EBCDIC-to-ASCII translation function is needed for this system"
#endif
		do_etoa_init = false;
	}

	tok = yylex_ebcdic();

	if (tok >= 0 && tok <= 0xFF)
		tok = etoa_xlate[tok];

	return tok;
}
#endif /* USE_EBCDIC */

/* snode --- instructions for builtin functions. Checks for arg. count
             and supplies defaults where possible. */

static INSTRUCTION *
snode(INSTRUCTION *subn, INSTRUCTION *r)
{
	INSTRUCTION *arg;
	INSTRUCTION *ip;
	NODE *n;
	int nexp = 0;
	int args_allowed;
	int idx = r->builtin_idx;

	if (subn != NULL) {
		INSTRUCTION *tp;
		for (tp = subn->nexti; tp; tp = tp->nexti) {
			tp = tp->lasti;
			nexp++;
		}
		assert(nexp > 0);
	}

	/* check against how many args. are allowed for this builtin */
	args_allowed = tokentab[idx].flags & ARGS;
	if (args_allowed && (args_allowed & A(nexp)) == 0) {
		yyerror(_("%d is invalid as number of arguments for %s"),
				nexp, tokentab[idx].operator);
		return NULL;
	}

	/* special processing for sub, gsub and gensub */

	if (tokentab[idx].value == Op_sub_builtin) {
		const char *operator = tokentab[idx].operator;

		r->sub_flags = 0;

		arg = subn->nexti;		/* first arg list */
		(void) mk_rexp(arg);

		if (strcmp(operator, "gensub") != 0) {
			/* sub and gsub */

			if (strcmp(operator, "gsub") == 0)
				r->sub_flags |= GSUB;

			arg = arg->lasti->nexti;	/* 2nd arg list */
			if (nexp == 2) {
				INSTRUCTION *expr;

				expr = list_create(instruction(Op_push_i));
				expr->nexti->memory = set_profile_text(make_number(0.0), "0", 1);
				(void) mk_expression_list(subn,
						list_append(expr, instruction(Op_field_spec)));
			}

			arg = arg->lasti->nexti; 	/* third arg list */
			ip = arg->lasti;
			if (ip->opcode == Op_push_i) {
				if (do_lint)
					lintwarn(_("%s: string literal as last argument of substitute has no effect"),
						operator);
				r->sub_flags |=	LITERAL;
			} else {
				if (make_assignable(ip) == NULL)
					yyerror(_("%s third parameter is not a changeable object"),
						operator);
				else
					ip->do_reference = true;
			}

			r->expr_count = count_expressions(&subn, false);
			ip = subn->lasti;

			(void) list_append(subn, r);

			/* add after_assign code */
			if (ip->opcode == Op_push_lhs && ip->memory->type == Node_var && ip->memory->var_assign) {
				(void) list_append(subn, instruction(Op_var_assign));
				subn->lasti->assign_ctxt = Op_sub_builtin;
				subn->lasti->assign_var = ip->memory->var_assign;
			} else if (ip->opcode == Op_field_spec_lhs) {
				(void) list_append(subn, instruction(Op_field_assign));
				subn->lasti->assign_ctxt = Op_sub_builtin;
				subn->lasti->field_assign = (Func_ptr) 0;
				ip->target_assign = subn->lasti;
			} else if (ip->opcode == Op_subscript_lhs) {
				(void) list_append(subn, instruction(Op_subscript_assign));
				subn->lasti->assign_ctxt = Op_sub_builtin;
			}

			return subn;

		} else {
			/* gensub */

			r->sub_flags |= GENSUB;
			if (nexp == 3) {
				ip = instruction(Op_push_i);
				ip->memory = set_profile_text(make_number(0.0), "0", 1);
				(void) mk_expression_list(subn,
						list_append(list_create(ip), instruction(Op_field_spec)));
			}

			r->expr_count = count_expressions(&subn, false);
			return list_append(subn, r);
		}
	}

#ifdef HAVE_MPFR
	/* N.B.: If necessary, add special processing for alternate builtin, below */
	if (do_mpfr && tokentab[idx].ptr2)
		r->builtin =  tokentab[idx].ptr2;
	else
#endif
		r->builtin = tokentab[idx].ptr;

	/* special case processing for a few builtins */

	if (r->builtin == do_length) {
		if (nexp == 0) {
		    /* no args. Use $0 */

			INSTRUCTION *list;
			r->expr_count = 1;
			list = list_create(r);
			(void) list_prepend(list, instruction(Op_field_spec));
			(void) list_prepend(list, instruction(Op_push_i));
			list->nexti->memory = set_profile_text(make_number(0.0), "0", 1);
			return list;
		} else {
			arg = subn->nexti;
			if (arg->nexti == arg->lasti && arg->nexti->opcode == Op_push)
				arg->nexti->opcode = Op_push_arg;	/* argument may be array */
 		}
	} else if (r->builtin == do_isarray) {
		arg = subn->nexti;
		if (arg->nexti == arg->lasti && arg->nexti->opcode == Op_push)
			arg->nexti->opcode = Op_push_arg_untyped;	/* argument may be untyped */
	} else if (r->builtin == do_typeof) {
		arg = subn->nexti;
		if (arg->nexti == arg->lasti && arg->nexti->opcode == Op_push)
			arg->nexti->opcode = Op_push_arg_untyped;	/* argument may be untyped */
		if (nexp == 2) {	/* 2nd argument there */
			arg = subn->nexti->lasti->nexti;	/* 2nd arg list */
			ip = arg->lasti;
			if (ip->opcode == Op_push)
				ip->opcode = Op_push_array;
		}
#ifdef SUPPLY_INTDIV
	} else if (r->builtin == do_intdiv
#ifdef HAVE_MPFR
		   || r->builtin == MPF(intdiv)
#endif
			) {
		arg = subn->nexti->lasti->nexti->lasti->nexti;	/* 3rd arg list */
		ip = arg->lasti;
		if (ip->opcode == Op_push)
			ip->opcode = Op_push_array;
#endif /* SUPPLY_INTDIV */
	} else if (r->builtin == do_match) {
		static bool warned = false;

		arg = subn->nexti->lasti->nexti;	/* 2nd arg list */
		(void) mk_rexp(arg);

		if (nexp == 3) {	/* 3rd argument there */
			if (do_lint_extensions && ! warned) {
				warned = true;
				lintwarn(_("match: third argument is a gawk extension"));
			}
			if (do_traditional) {
				yyerror(_("match: third argument is a gawk extension"));
				return NULL;
			}

			arg = arg->lasti->nexti; 	/* third arg list */
			ip = arg->lasti;
			if (/*ip == arg->nexti  && */ ip->opcode == Op_push)
				ip->opcode = Op_push_array;
		}
	} else if (r->builtin == do_split) {
		arg = subn->nexti->lasti->nexti;	/* 2nd arg list */
		ip = arg->lasti;
		if (ip->opcode == Op_push)
			ip->opcode = Op_push_array;
		if (nexp == 2) {
			INSTRUCTION *expr;
			expr = list_create(instruction(Op_push));
			expr->nexti->memory = FS_node;
			(void) mk_expression_list(subn, expr);
		}
		arg = arg->lasti->nexti;
		n = mk_rexp(arg);
		if (nexp == 2)
			n->re_flags |= FS_DFLT;
		if (nexp == 4) {
			arg = arg->lasti->nexti;
			ip = arg->lasti;
			if (ip->opcode == Op_push)
				ip->opcode = Op_push_array;
		}
	} else if (r->builtin == do_patsplit) {
		arg = subn->nexti->lasti->nexti;	/* 2nd arg list */
		ip = arg->lasti;
		if (ip->opcode == Op_push)
			ip->opcode = Op_push_array;
		if (nexp == 2) {
			INSTRUCTION *expr;
			expr = list_create(instruction(Op_push));
			expr->nexti->memory = FPAT_node;
			(void) mk_expression_list(subn, expr);
		}
		arg = arg->lasti->nexti;
		n = mk_rexp(arg);
		if (nexp == 4) {
			arg = arg->lasti->nexti;
			ip = arg->lasti;
			if (ip->opcode == Op_push)
				ip->opcode = Op_push_array;
		}
	} else if (r->builtin == do_close) {
		static bool warned = false;
		if (nexp == 2) {
			if (do_lint_extensions && ! warned) {
				warned = true;
				lintwarn(_("close: second argument is a gawk extension"));
			}
			if (do_traditional) {
				yyerror(_("close: second argument is a gawk extension"));
				return NULL;
			}
		}
	} else if (do_intl					/* --gen-po */
			&& r->builtin == do_dcgettext		/* dcgettext(...) */
			&& subn->nexti->lasti->opcode == Op_push_i	/* 1st arg is constant */
			&& (subn->nexti->lasti->memory->flags & STRING) != 0) {	/* it's a string constant */
		/* ala xgettext, dcgettext("some string" ...) dumps the string */
		NODE *str = subn->nexti->lasti->memory;

		if ((str->flags & INTLSTR) != 0)
			warning(_("use of dcgettext(_\"...\") is incorrect: remove leading underscore"));
			/* don't dump it, the lexer already did */
		else
			dumpintlstr(str->stptr, str->stlen);
	} else if (do_intl					/* --gen-po */
			&& r->builtin == do_dcngettext		/* dcngettext(...) */
			&& subn->nexti->lasti->opcode == Op_push_i	/* 1st arg is constant */
			&& (subn->nexti->lasti->memory->flags & STRING) != 0	/* it's a string constant */
			&& subn->nexti->lasti->nexti->lasti->opcode == Op_push_i	/* 2nd arg is constant too */
			&& (subn->nexti->lasti->nexti->lasti->memory->flags & STRING) != 0) {	/* it's a string constant */
		/* ala xgettext, dcngettext("some string", "some plural" ...) dumps the string */
		NODE *str1 = subn->nexti->lasti->memory;
		NODE *str2 = subn->nexti->lasti->nexti->lasti->memory;

		if (((str1->flags | str2->flags) & INTLSTR) != 0)
			warning(_("use of dcngettext(_\"...\") is incorrect: remove leading underscore"));
		else
			dumpintlstr2(str1->stptr, str1->stlen, str2->stptr, str2->stlen);
	} else if (r->builtin == do_asort || r->builtin == do_asorti) {
		arg = subn->nexti;	/* 1st arg list */
		ip = arg->lasti;
		if (ip->opcode == Op_push)
			ip->opcode = Op_push_array;
		if (nexp >= 2) {
			arg = ip->nexti;
			ip = arg->lasti;
			if (ip->opcode == Op_push)
				ip->opcode = Op_push_array;
		}
	}
	else if (r->builtin == do_index) {
		arg = subn->nexti->lasti->nexti;	/* 2nd arg list */
		ip = arg->lasti;
		if (ip->opcode == Op_match_rec || ip->opcode == Op_push_re)
			fatal(_("index: regexp constant as second argument is not allowed"));
	}
#ifdef ARRAYDEBUG
	else if (r->builtin == do_adump) {
		ip = subn->nexti->lasti;
		if (ip->opcode == Op_push)
			ip->opcode = Op_push_array;
	}
#endif

	if (subn != NULL) {
		r->expr_count = count_expressions(&subn, false);
		return list_append(subn, r);
	}

	r->expr_count = 0;
	return list_create(r);
}


/* parms_shadow --- check if parameters shadow globals */

static int
parms_shadow(INSTRUCTION *pc, bool *shadow)
{
	int pcount, i;
	bool ret = false;
	NODE *func, *fp;
	char *fname;

	func = pc->func_body;
	fname = func->vname;
	fp = func->fparms;

#if 0	/* can't happen, already exited if error ? */
	if (fname == NULL || func == NULL)	/* error earlier */
		return false;
#endif

	pcount = func->param_cnt;

	if (pcount == 0)		/* no args, no problem */
		return 0;

	source = pc->source_file;
	sourceline = pc->source_line;
	/*
	 * Use warning() and not lintwarn() so that can warn
	 * about all shadowed parameters.
	 */
	for (i = 0; i < pcount; i++) {
		if (lookup(fp[i].param) != NULL) {
			warning(
	_("function `%s': parameter `%s' shadows global variable"),
					fname, fp[i].param);
			ret = true;
		}
	}

	*shadow |= ret;
	return 0;
}

/* valinfo --- dump var info */

void
valinfo(NODE *n, Func_print print_func, FILE *fp)
{
	if (n == Nnull_string)
		print_func(fp, "uninitialized scalar\n");
	else if ((n->flags & REGEX) != 0)
		print_func(fp, "@/%.*s/\n", n->stlen, n->stptr);
	else if ((n->flags & STRING) != 0) {
		pp_string_fp(print_func, fp, n->stptr, n->stlen, '"', false);
		print_func(fp, "\n");
	} else if ((n->flags & NUMBER) != 0) {
#ifdef HAVE_MPFR
		if (is_mpg_float(n))
			print_func(fp, "%s\n", mpg_fmt("%.17R*g", ROUND_MODE, n->mpg_numbr));
		else if (is_mpg_integer(n))
			print_func(fp, "%s\n", mpg_fmt("%Zd", n->mpg_i));
		else
#endif
		print_func(fp, "%.17g\n", n->numbr);
	} else
		print_func(fp, "?? flags %s\n", flags2str(n->flags));
}


/* dump_vars --- dump the symbol table */

void
dump_vars(const char *fname)
{
	FILE *fp;
	NODE **vars;

	if (fname == NULL)
		fp = stderr;
	else if (strcmp(fname, "-") == 0)
		fp = stdout;
	else if ((fp = fopen(fname, "w")) == NULL) {
		warning(_("could not open `%s' for writing: %s"), fname, strerror(errno));
		warning(_("sending variable list to standard error"));
		fp = stderr;
	}

	vars = variable_list();
	print_vars(vars, fprintf, fp);
	efree(vars);
	if (fp != stdout && fp != stderr && fclose(fp) != 0)
		warning(_("%s: close failed: %s"), fname, strerror(errno));
}

/* dump_funcs --- print all functions */

void
dump_funcs()
{
	NODE **funcs;
	funcs = function_list(true);
	(void) foreach_func(funcs, (int (*)(INSTRUCTION *, void *)) pp_func, (void *) 0);
	efree(funcs);
}


/* shadow_funcs --- check all functions for parameters that shadow globals */

void
shadow_funcs()
{
	static int calls = 0;
	bool shadow = false;
	NODE **funcs;

	if (calls++ != 0)
		fatal(_("shadow_funcs() called twice!"));

	funcs = function_list(true);
	(void) foreach_func(funcs, (int (*)(INSTRUCTION *, void *)) parms_shadow, & shadow);
	efree(funcs);

	/* End with fatal if the user requested it.  */
	if (shadow && lintfunc == r_fatal)
		lintwarn(_("there were shadowed variables"));
}


/* mk_function --- finalize function definition node; remove parameters
 *	out of the symbol table.
 */

static INSTRUCTION *
mk_function(INSTRUCTION *fi, INSTRUCTION *def)
{
	NODE *thisfunc;

	thisfunc = fi->func_body;
	assert(thisfunc != NULL);

	/* add any pre-function comment to start of action for profile.c  */

	if (interblock_comment != NULL) {
		interblock_comment->source_line = 0;
		merge_comments(interblock_comment, fi->comment);
		fi->comment = interblock_comment;
		interblock_comment = NULL;
	}

	/*
	 * Add an implicit return at end;
	 * also used by 'return' command in debugger
	 */

	(void) list_append(def, instruction(Op_push_i));
	def->lasti->memory = dupnode(Nnull_string);
	(void) list_append(def, instruction(Op_K_return));

	if (trailing_comment != NULL) {
		(void) list_append(def, trailing_comment);
		trailing_comment = NULL;
	}

	if (do_pretty_print) {
		if (namespace_chain == NULL)
			push_ns_onto_namespace_chain(NULL);

		fi[3].nexti = namespace_chain;
		namespace_chain = NULL;
		(void) list_prepend(def, instruction(Op_exec_count));
	}

	/* fi->opcode = Op_func */
	(fi + 1)->firsti = def->nexti;
	(fi + 1)->lasti = def->lasti;
	(fi + 2)->first_line = fi->source_line;
	(fi + 2)->last_line = lastline;
	fi->nexti = def->nexti;
	bcfree(def);

	(void) list_append(rule_list, fi + 1);	/* debugging */

	/* update lint table info */
	func_use(thisfunc->vname, FUNC_DEFINE);

	/* remove params from symbol table */
	remove_params(thisfunc);
	return fi;
}

/* push_ns_onto_namespace_chain --- update the namespace chain */

static void
push_ns_onto_namespace_chain(INSTRUCTION *comment)
{
	INSTRUCTION *new_ns = instruction(Op_K_namespace);
	new_ns->comment = comment;
	new_ns->ns_name = estrdup(current_namespace, strlen(current_namespace));
	new_ns->nexti = namespace_chain;
	namespace_chain = new_ns;
}

/*
 * install_function:
 * install function name in the symbol table.
 * Extra work, build up and install a list of the parameter names.
 */

static int
install_function(char *fname, INSTRUCTION *fi, INSTRUCTION *plist)
{
	NODE *r, *f;
	int pcount = 0;

	r = lookup(fname);
	if (r != NULL) {
		error_ln(fi->source_line, _("function name `%s' previously defined"), fname);
		return -1;
	}

	if (plist != NULL)
		pcount = plist->lasti->param_count + 1;
	f = install_symbol(fname, Node_func);
	if (f->vname != fname) {
		// DON'T free fname, it's done later
		fname = f->vname;
	}

	fi->func_body = f;
	f->param_cnt = pcount;
	f->code_ptr = fi;
	f->fparms = NULL;
	if (pcount > 0) {
		char **pnames;
		pnames = check_params(fname, pcount, plist);	/* frees plist */
		f->fparms = make_params(pnames, pcount);
		efree(pnames);
		install_params(f);
	}
	return 0;
}


/* check_params --- build a list of function parameter names after
 *	making sure that the names are valid and there are no duplicates.
 */

static char **
check_params(char *fname, int pcount, INSTRUCTION *list)
{
	INSTRUCTION *p, *np;
	int i, j;
	char *name;
	char **pnames;

	assert(pcount > 0);

	emalloc(pnames, char **, pcount * sizeof(char *));

	for (i = 0, p = list->nexti; p != NULL; i++, p = np) {
		np = p->nexti;
		name = p->lextok;
		p->lextok = NULL;

		if (strcmp(name, fname) == 0) {
			/* check for function foo(foo) { ... }.  bleah. */
			error_ln(p->source_line,
				_("function `%s': cannot use function name as parameter name"), fname);
		} else if (is_std_var(name)) {
			error_ln(p->source_line,
				_("function `%s': parameter `%s': POSIX disallows using a special variable as a function parameter"),
					fname, name);
		} else if (strchr(name, ':') != NULL)
			error_ln(p->source_line,
				_("function `%s': parameter `%s' cannot contain a namespace"),
					fname, name);

		/* check for duplicate parameters */
		for (j = 0; j < i; j++) {
			if (strcmp(name, pnames[j]) == 0) {
				error_ln(p->source_line,
					_("function `%s': parameter #%d, `%s', duplicates parameter #%d"),
					fname, i + 1, name, j + 1);
			}
		}

		pnames[i] = name;
		bcfree(p);
	}
	bcfree(list);

	return pnames;
}


#ifdef HASHSIZE
undef HASHSIZE
#endif
#define HASHSIZE 1021

static struct fdesc {
	char *name;
	short used;
	short defined;
	short extension;
	struct fdesc *next;
} *ftable[HASHSIZE];

/* func_use --- track uses and definitions of functions */

static void
func_use(const char *name, enum defref how)
{
	struct fdesc *fp;
	int len;
	int ind;

	len = strlen(name);
	ind = hash(name, len, HASHSIZE, NULL);

	for (fp = ftable[ind]; fp != NULL; fp = fp->next)
		if (strcmp(fp->name, name) == 0)
			goto update_value;

	/* not in the table, fall through to allocate a new one */

	ezalloc(fp, struct fdesc *, sizeof(struct fdesc));
	emalloc(fp->name, char *, len + 1);
	strcpy(fp->name, name);
	fp->next = ftable[ind];
	ftable[ind] = fp;

update_value:
	if (how == FUNC_DEFINE)
		fp->defined++;
	else if (how == FUNC_EXT) {
		fp->defined++;
		fp->extension++;
	} else
		fp->used++;
}

/* track_ext_func --- add an extension function to the table */

void
track_ext_func(const char *name)
{
	func_use(name, FUNC_EXT);
}

/* check_funcs --- verify functions that are called but not defined */

static void
check_funcs()
{
	struct fdesc *fp, *next;
	int i;

	if (! in_main_context())
		goto free_mem;

	for (i = 0; i < HASHSIZE; i++) {
		for (fp = ftable[i]; fp != NULL; fp = fp->next) {
			if (do_lint && ! fp->extension) {
				/*
				 * Making this not a lint check and
				 * incrementing * errcount breaks old code.
				 * Sigh.
				 */
				if (fp->defined == 0)
					lintwarn(_("function `%s' called but never defined"),
						fp->name);

				if (fp->used == 0)
					lintwarn(_("function `%s' defined but never called directly"),
						fp->name);
			}
		}
	}

free_mem:
	/* now let's free all the memory */
	for (i = 0; i < HASHSIZE; i++) {
		for (fp = ftable[i]; fp != NULL; fp = next) {
			next = fp->next;
			efree(fp->name);
			efree(fp);
		}
		ftable[i] = NULL;
	}
}

/* param_sanity --- look for parameters that are regexp constants */

static void
param_sanity(INSTRUCTION *arglist)
{
	INSTRUCTION *argl, *arg;
	int i = 1;

	if (arglist == NULL)
		return;
	for (argl = arglist->nexti; argl; ) {
		arg = argl->lasti;
		if (arg->opcode == Op_match_rec)
			warning_ln(arg->source_line,
				_("regexp constant for parameter #%d yields boolean value"), i);
		argl = arg->nexti;
		i++;
	}
}

/* variable --- make sure NAME is in the symbol table */

NODE *
variable(int location, char *name, NODETYPE type)
{
	NODE *r;

	if ((r = lookup(name)) != NULL) {
		if (r->type == Node_func || r->type == Node_ext_func )
			error_ln(location, _("function `%s' called with space between name and `(',\nor used as a variable or an array"),
				r->vname);
	} else {
		/* not found */
		return install_symbol(name, type);
	}
	efree(name);
	return r;
}

/* make_regnode --- make a regular expression node */

NODE *
make_regnode(NODETYPE type, NODE *exp)
{
	NODE *n;

	assert(type == Node_regex || type == Node_dynregex);
	getnode(n);
	memset(n, 0, sizeof(NODE));
	n->type = type;
	n->re_cnt = 1;

	if (type == Node_regex) {
		n->re_reg[0] = make_regexp(exp->stptr, exp->stlen, false, true, false);
		if (n->re_reg[0] == NULL) {
			freenode(n);
			return NULL;
		}
		n->re_exp = exp;
		n->re_flags = CONSTANT;
	}
	return n;
}


/* mk_rexp --- make a regular expression constant */

static NODE *
mk_rexp(INSTRUCTION *list)
{
	INSTRUCTION *ip;

	ip = list->nexti;
	if (ip == list->lasti && ip->opcode == Op_match_rec)
		ip->opcode = Op_push_re;
	else if (ip == list->lasti && ip->opcode == Op_push_re)
		; /* do nothing --- @/.../ */
	else {
		ip = instruction(Op_push_re);
		ip->memory = make_regnode(Node_dynregex, NULL);
		ip->nexti = list->lasti->nexti;
		list->lasti->nexti = ip;
		list->lasti = ip;
	}
	return ip->memory;
}

#ifndef NO_LINT
/* isnoeffect --- when used as a statement, has no side effects */

static int
isnoeffect(OPCODE type)
{
	switch (type) {
	case Op_times:
	case Op_times_i:
	case Op_quotient:
	case Op_quotient_i:
	case Op_mod:
	case Op_mod_i:
	case Op_plus:
	case Op_plus_i:
	case Op_minus:
	case Op_minus_i:
	case Op_subscript:
	case Op_concat:
	case Op_exp:
	case Op_exp_i:
	case Op_unary_minus:
	case Op_field_spec:
	case Op_and_final:
	case Op_or_final:
	case Op_equal:
	case Op_notequal:
	case Op_less:
	case Op_greater:
	case Op_leq:
	case Op_geq:
	case Op_match:
	case Op_nomatch:
	case Op_match_rec:
	case Op_not:
	case Op_in_array:
		return true;
	// Additional opcodes that can be part of an expression
	// that has no effect:
	case Op_and:
	case Op_or:
	case Op_push:
	case Op_push_i:
	case Op_push_array:
	case Op_pop:
	case Op_lint_plus:
	case Op_exec_count:
		return true;
	default:
		break;	/* keeps gcc -Wall happy */
	}

	return false;
}
#endif /* NO_LINT */


/* make_assignable --- make this operand an assignable one if posiible */

static INSTRUCTION *
make_assignable(INSTRUCTION *ip)
{
	switch (ip->opcode) {
	case Op_push:
		ip->opcode = Op_push_lhs;
		return ip;
	case Op_field_spec:
		ip->opcode = Op_field_spec_lhs;
		return ip;
	case Op_subscript:
		ip->opcode = Op_subscript_lhs;
		return ip;
	case Op_field_assign:
		// no need to change the opcode, but do need to return
		// a non-NULL pointer.
		return ip;
	default:
		break;	/* keeps gcc -Wall happy */
	}
	return NULL;
}

/* stopme --- for debugging */

NODE *
stopme(int nargs ATTRIBUTE_UNUSED)
{
	return make_number(0.0);
}

/* dumpintlstr --- write out an initial .po file entry for the string */

static void
dumpintlstr(const char *str, size_t len)
{
	char *cp;

	/* See the GNU gettext distribution for details on the file format */

	if (source != NULL) {
		/* ala the gettext sources, remove leading `./'s */
		for (cp = source; cp[0] == '.' && cp[1] == '/'; cp += 2)
			continue;
		printf("#: %s:%d\n", cp, sourceline);
	}

	printf("msgid ");
	pp_string_fp(fprintf, stdout, str, len, '"', true);
	putchar('\n');
	printf("msgstr \"\"\n\n");
	fflush(stdout);
}

/* dumpintlstr2 --- write out an initial .po file entry for the string and its plural */

static void
dumpintlstr2(const char *str1, size_t len1, const char *str2, size_t len2)
{
	char *cp;

	/* See the GNU gettext distribution for details on the file format */

	if (source != NULL) {
		/* ala the gettext sources, remove leading `./'s */
		for (cp = source; cp[0] == '.' && cp[1] == '/'; cp += 2)
			continue;
		printf("#: %s:%d\n", cp, sourceline);
	}

	printf("msgid ");
	pp_string_fp(fprintf, stdout, str1, len1, '"', true);
	putchar('\n');
	printf("msgid_plural ");
	pp_string_fp(fprintf, stdout, str2, len2, '"', true);
	putchar('\n');
	printf("msgstr[0] \"\"\nmsgstr[1] \"\"\n\n");
	fflush(stdout);
}

/* mk_binary --- instructions for binary operators */

static INSTRUCTION *
mk_binary(INSTRUCTION *s1, INSTRUCTION *s2, INSTRUCTION *op)
{
	INSTRUCTION *ip1,*ip2, *lint_plus;
	AWKNUM res;

	ip2 = s2->nexti;
	if (s2->lasti == ip2 && ip2->opcode == Op_push_i) {
	/* do any numeric constant folding */
		ip1 = s1->nexti;
		if (do_optimize
				&& ip1 == s1->lasti && ip1->opcode == Op_push_i
				&& (ip1->memory->flags & (MPFN|MPZN|STRCUR|STRING)) == 0
				&& (ip2->memory->flags & (MPFN|MPZN|STRCUR|STRING)) == 0
		) {
			NODE *n1 = ip1->memory, *n2 = ip2->memory;
			res = force_number(n1)->numbr;
			(void) force_number(n2);
			switch (op->opcode) {
			case Op_times:
				res *= n2->numbr;
				break;
			case Op_quotient:
				if ((n2->flags & NUMBER) != 0 && n2->numbr == 0.0) {
					/* don't fatalize, allow parsing rest of the input */
					error_ln(op->source_line, _("division by zero attempted"));
					goto regular;
				}

				res /= n2->numbr;
				break;
			case Op_mod:
				if ((n2->flags & NUMBER) != 0 && n2->numbr == 0.0) {
					/* don't fatalize, allow parsing rest of the input */
					error_ln(op->source_line, _("division by zero attempted in `%%'"));
					goto regular;
				}
#ifdef HAVE_FMOD
				res = fmod(res, n2->numbr);
#else	/* ! HAVE_FMOD */
				(void) modf(res / n2->numbr, &res);
				res = n1->numbr - res * n2->numbr;
#endif	/* ! HAVE_FMOD */
				break;
			case Op_plus:
				res += n2->numbr;
				break;
			case Op_minus:
				res -= n2->numbr;
				break;
			case Op_exp:
				res = calc_exp(res, n2->numbr);
				break;
			default:
				goto regular;
			}

			op->opcode = Op_push_i;
			// We don't need to call set_profile_text() here since
			// optimizing is disabled when doing pretty printing.
			op->memory = make_number(res);
			unref(n1);
			unref(n2);
			bcfree(ip1);
			bcfree(ip2);
			bcfree(s1);
			bcfree(s2);
			return list_create(op);
		} else {
		/* do basic arithmetic optimisation */
		/* convert (Op_push_i Node_val) + (Op_plus) to (Op_plus_i Node_val) */
			switch (op->opcode) {
			case Op_times:
				op->opcode = Op_times_i;
				break;
			case Op_quotient:
				if ((ip2->memory->flags & NUMBER) != 0 && ip2->memory->numbr == 0.0) {
					/* don't fatalize, allow parsing rest of the input */
					error_ln(op->source_line, _("division by zero attempted"));
					goto regular;
				}

				op->opcode = Op_quotient_i;
				break;
			case Op_mod:
				if ((ip2->memory->flags & NUMBER) != 0 && ip2->memory->numbr == 0.0) {
					/* don't fatalize, allow parsing rest of the input */
					error_ln(op->source_line, _("division by zero attempted in `%%'"));
					goto regular;
				}

				op->opcode = Op_mod_i;
				break;
			case Op_plus:
				if (do_lint)
					goto regular;
				op->opcode = Op_plus_i;
				break;
			case Op_minus:
				op->opcode = Op_minus_i;
				break;
			case Op_exp:
				op->opcode = Op_exp_i;
				break;
			default:
				goto regular;
			}

			op->memory = ip2->memory;
			bcfree(ip2);
			bcfree(s2);	/* Op_list */
			return list_append(s1, op);
		}
	}

regular:
	/* append lists s1, s2 and add `op' bytecode */
	(void) list_merge(s1, s2);
	if (do_lint && op->opcode == Op_plus) {
		lint_plus = instruction(Op_lint_plus);
		(void) list_append(s1, lint_plus);
	}
	return list_append(s1, op);
}

/* mk_boolean --- instructions for boolean and, or */

static INSTRUCTION *
mk_boolean(INSTRUCTION *left, INSTRUCTION *right, INSTRUCTION *op)
{
	INSTRUCTION *tp;
	OPCODE opc, final_opc;

	opc = op->opcode;		/* Op_and or Op_or */
	final_opc = (opc == Op_or) ? Op_or_final : Op_and_final;

	add_lint(right, LINT_assign_in_cond);

	tp = left->lasti;

	if (tp->opcode != final_opc) {	/* x || y */
		list_append(right, instruction(final_opc));
		add_lint(left, LINT_assign_in_cond);
		(void) list_append(left, op);
		left->lasti->target_jmp = right->lasti;

		/* NB: target_stmt points to previous Op_and(Op_or) in a chain;
		 *     target_stmt only used in the parser (see below).
		 */

		left->lasti->target_stmt = left->lasti;
		right->lasti->target_stmt = left->lasti;
	} else {		/* optimization for x || y || z || ... */
		INSTRUCTION *ip;

		op->opcode = final_opc;
		(void) list_append(right, op);
		op->target_stmt = tp;
		tp->opcode = opc;
		tp->target_jmp = op;

		/* update jump targets */
		for (ip = tp->target_stmt; ; ip = ip->target_stmt) {
			assert(ip->opcode == opc);
			assert(ip->target_jmp == tp);
			/* if (ip->opcode == opc &&  ip->target_jmp == tp) */
			ip->target_jmp = op;
			if (ip->target_stmt == ip)
				break;
		}
	}

	return list_merge(left, right);
}

/* mk_condition --- if-else and conditional */

static INSTRUCTION *
mk_condition(INSTRUCTION *cond, INSTRUCTION *ifp, INSTRUCTION *true_branch,
		INSTRUCTION *elsep, INSTRUCTION *false_branch)
{
	/*
	 *    ----------------
	 *       cond
	 *    ----------------
	 * t: [Op_jmp_false f ]
	 *    ----------------
	 *       true_branch
	 *
	 *    ----------------
	 *    [Op_jmp y]
	 *    ----------------
	 * f:
	 *      false_branch
	 *    ----------------
	 * y: [Op_no_op]
	 *    ----------------
	 */

	INSTRUCTION *ip;
	bool setup_else_part = true;

	if (false_branch == NULL) {
		false_branch = list_create(instruction(Op_no_op));
		if (elsep == NULL) {		/* else { } */
			setup_else_part = false;
		}
	} else {
		/* assert(elsep != NULL); */

		/* avoid a series of no_op's: if .. else if .. else if .. */
		if (false_branch->lasti->opcode != Op_no_op)
			(void) list_append(false_branch, instruction(Op_no_op));
	}

	if (setup_else_part) {
		if (do_pretty_print) {
			(void) list_prepend(false_branch, elsep);
			false_branch->nexti->branch_end = false_branch->lasti;
			(void) list_prepend(false_branch, instruction(Op_exec_count));
		} else
			bcfree(elsep);
	}

	(void) list_prepend(false_branch, instruction(Op_jmp));
	false_branch->nexti->target_jmp = false_branch->lasti;

	add_lint(cond, LINT_assign_in_cond);
	ip = list_append(cond, instruction(Op_jmp_false));
	ip->lasti->target_jmp = false_branch->nexti->nexti;

	if (do_pretty_print) {
		(void) list_prepend(ip, ifp);
		(void) list_append(ip, instruction(Op_exec_count));
		ip->nexti->branch_if = ip->lasti;
		ip->nexti->branch_else = false_branch->nexti;
	} else
		bcfree(ifp);

	if (true_branch != NULL)
		list_merge(ip, true_branch);
	return list_merge(ip, false_branch);
}

enum defline { FIRST_LINE, LAST_LINE };

/* find_line -- find the first(last) line in a list of (pattern) instructions */

static int
find_line(INSTRUCTION *pattern, enum defline what)
{
	INSTRUCTION *ip;
	int lineno = 0;

	for (ip = pattern->nexti; ip; ip = ip->nexti) {
		if (what == LAST_LINE) {
			if (ip->source_line > lineno)
				lineno = ip->source_line;
		} else {	/* FIRST_LINE */
			if (ip->source_line > 0
					&& (lineno == 0 || ip->source_line < lineno))
				lineno = ip->source_line;
		}
		if (ip == pattern->lasti)
			break;
	}
	assert(lineno > 0);
	return lineno;
}

/* append_rule --- pattern-action instructions */

static INSTRUCTION *
append_rule(INSTRUCTION *pattern, INSTRUCTION *action)
{
	/*
	 *    ----------------
	 *       pattern
	 *    ----------------
	 *    [Op_jmp_false f ]
	 *    ----------------
	 *       action
	 *    ----------------
	 * f: [Op_no_op       ]
	 *    ----------------
	 */

	INSTRUCTION *rp;
	INSTRUCTION *tp;
	INSTRUCTION *ip;

	if (rule != Rule) {
		rp = pattern;
		if (do_pretty_print) {
			rp[3].nexti = namespace_chain;
			namespace_chain = NULL;
			(void) list_append(action, instruction(Op_no_op));
		}
		(rp + 1)->firsti = action->nexti;
		(rp + 1)->lasti = action->lasti;
		(rp + 2)->first_line = pattern->source_line;
		(rp + 2)->last_line = lastline;
		ip = list_prepend(action, rp);
		if (interblock_comment != NULL) {
			ip = list_prepend(ip, interblock_comment);
			interblock_comment = NULL;
		}
	} else {
		rp = bcalloc(Op_rule, 4, 0);
		rp->in_rule = Rule;
		rp->source_file = source;
		tp = instruction(Op_no_op);

		if (do_pretty_print) {
			rp[3].nexti = namespace_chain;
			namespace_chain = NULL;
		}

		if (pattern == NULL) {
			/* assert(action != NULL); */
			if (do_pretty_print)
				(void) list_prepend(action, instruction(Op_exec_count));
			(rp + 1)->firsti = action->nexti;
			(rp + 1)->lasti = tp;
			(rp + 2)->first_line = firstline;
			(rp + 2)->last_line = lastline;
			rp->source_line = firstline;
			ip = list_prepend(list_append(action, tp), rp);
		} else {
			(void) list_append(pattern, instruction(Op_jmp_false));
			pattern->lasti->target_jmp = tp;
			(rp + 2)->first_line = find_line(pattern, FIRST_LINE);
			rp->source_line = (rp + 2)->first_line;
			if (action == NULL) {
				(rp + 2)->last_line = find_line(pattern, LAST_LINE);
				action = list_create(instruction(Op_K_print_rec));
				if (do_pretty_print)
					action = list_prepend(action, instruction(Op_exec_count));
			} else
				(rp + 2)->last_line = lastline;

			if (interblock_comment != NULL) {	// was after previous action
				pattern = list_prepend(pattern, interblock_comment);
				interblock_comment = NULL;
			}

			if (do_pretty_print) {
				pattern = list_prepend(pattern, instruction(Op_exec_count));
				action = list_prepend(action, instruction(Op_exec_count));
			}

 			(rp + 1)->firsti = action->nexti;
			(rp + 1)->lasti = tp;
			ip = list_append(
					list_merge(list_prepend(pattern, rp),
						action),
					tp);
		}
	}

	list_append(rule_list, rp + 1);

	if (rule_block[rule] == NULL)
		rule_block[rule] = ip;
	else
		(void) list_merge(rule_block[rule], ip);

	return rule_block[rule];
}

/*
 * 3/2023:
 * mk_assignment() is called when an assignment statement is seen,
 * as an expression.  optimize_assignment() is called when an expression
 * is seen as statement (inside braces).
 *
 * When a field assignment is seen, it needs to be optizimed into
 * Op_store_field_exp or Op_store_field to avoid memory management
 * issues. Thus, the Op_field_spec_lhs -> Op_store_field_expr
 * change is done in mk_assignment. (Consider foo && $0 = $1, the
 * assignment is part of an expression.)
 *
 * If the assignment is in a statement, then optimize_assignment()
 * turn Op_store_field_expr into Op_store_field.
 */

/* mk_assignment --- assignment bytecodes */

static INSTRUCTION *
mk_assignment(INSTRUCTION *lhs, INSTRUCTION *rhs, INSTRUCTION *op)
{
	INSTRUCTION *tp;
	INSTRUCTION *ip;

	tp = lhs->lasti;
	switch (tp->opcode) {
	case Op_field_spec:
		tp->opcode = Op_field_spec_lhs;
		break;
	case Op_subscript:
		tp->opcode = Op_subscript_lhs;
		break;
	case Op_push:
	case Op_push_array:
		tp->opcode = Op_push_lhs;
		break;
	case Op_field_assign:
		yyerror(_("cannot assign a value to the result of a field post-increment expression"));
		break;
	default:
		yyerror(_("invalid target of assignment (opcode %s)"),
				opcode2str(tp->opcode));
		break;
	}

	tp->do_reference = (op->opcode != Op_assign);	/* check for uninitialized reference */

	if (rhs != NULL)
		ip = list_merge(rhs, lhs);
	else
		ip = lhs;

	if (tp->opcode != Op_field_spec_lhs || op->opcode != Op_assign)
		(void) list_append(ip, op);

	if (tp->opcode == Op_push_lhs
			&& tp->memory->type == Node_var
			&& tp->memory->var_assign
	) {
		tp->do_reference = false; /* no uninitialized reference checking
		                           * for a special variable.
		                           */
		(void) list_append(ip, instruction(Op_var_assign));
		ip->lasti->assign_var = tp->memory->var_assign;
	} else if (tp->opcode == Op_field_spec_lhs) {
		if (op->opcode == Op_assign) {
			bcfree(op);
			tp->opcode = Op_store_field_exp;
		} else {
			(void) list_append(ip, instruction(Op_field_assign));
			ip->lasti->field_assign = (Func_ptr) 0;
			tp->target_assign = ip->lasti;
		}
	} else if (tp->opcode == Op_subscript_lhs) {
		(void) list_append(ip, instruction(Op_subscript_assign));
	}

	return ip;
}

/* optimize_assignment --- peephole optimization for assignment */

static INSTRUCTION *
optimize_assignment(INSTRUCTION *exp)
{
	INSTRUCTION *i1, *i2, *i3;

	/*
	 * Optimize assignment statements array[subs] = x; var = x; $n = x;
	 * string concatenation of the form s = s t.
	 *
	 * 1) Array element assignment array[subs] = x:
	 *   Replaces Op_push_array + Op_subscript_lhs + Op_assign + Op_pop
	 *   with single instruction Op_store_sub.
	 *	 Limitation: 1 dimension and sub is simple var/value.
	 *
	 * 2) Simple variable assignment var = x:
	 *   Replaces Op_push_lhs + Op_assign + Op_pop with Op_store_var.
	 *
	 * 3) Field assignment $n = x:
	 *   Replaces Op_field_spec_lhs + Op_assign + Op_field_assign + Op_pop
	 *   with Op_store_field.
	 *
	 * 4) Optimization for string concatenation:
	 *   For cases like x = x y, uses realloc to include y in x;
	 *   also eliminates instructions Op_push_lhs and Op_pop.
	 */

	/*
	 * N.B.: do not append Op_pop instruction to the returned
	 * instruction list if optimized. None of these
	 * optimized instructions pushes the r-value of assignment
	 * onto the runtime stack.
	 */

	i2 = NULL;
	i1 = exp->lasti;

	if (i1->opcode == Op_store_field_exp) {
		i1->opcode = Op_store_field;
		return exp;
	}

	if (   i1->opcode != Op_assign
	    && i1->opcode != Op_field_assign)
		return list_append(exp, instruction(Op_pop));

	for (i2 = exp->nexti; i2 != i1; i2 = i2->nexti) {
		switch (i2->opcode) {
		case Op_concat:
			if (i2->nexti->opcode == Op_push_lhs    /* l.h.s is a simple variable */
				&& (i2->concat_flag & CSVAR) != 0   /* 1st exp in r.h.s is a simple variable;
				                                     * see Op_concat in the grammer above.
				                                     */
				&& i2->nexti->memory == exp->nexti->memory	 /* and the same as in l.h.s */
				&& i2->nexti->nexti == i1
				&& i1->opcode == Op_assign
			) {
				/* s = s ... optimization */

				/* avoid stuff like x = x (x = y) or x = x gsub(/./, "b", x);
				 * check for l-value reference to this variable in the r.h.s.
				 * Also, avoid function calls in general to guard against
				 * global variable assignment.
				 */

				for (i3 = exp->nexti->nexti; i3 != i2; i3 = i3->nexti) {
					if ((i3->opcode == Op_push_lhs && i3->memory == i2->nexti->memory)
							|| i3->opcode == Op_func_call)
						return list_append(exp, instruction(Op_pop)); /* no optimization */
				}

				/* remove the variable from r.h.s */
				i3 = exp->nexti;
				exp->nexti = i3->nexti;
				bcfree(i3);

				if (--i2->expr_count == 1)	/* one less expression in Op_concat */
					i2->opcode = Op_no_op;

				i3 = i2->nexti;
				assert(i3->opcode == Op_push_lhs);
				i3->opcode = Op_assign_concat;	/* change Op_push_lhs to Op_assign_concat */
				i3->nexti = NULL;
				bcfree(i1);          /* Op_assign */
				exp->lasti = i3;     /* update Op_list */
				return exp;
			}
			break;

		case Op_push_array:
			if (i2->nexti->nexti->opcode == Op_subscript_lhs) {
				i3 = i2->nexti->nexti;
				if (i3->sub_count == 1
						&& i3->nexti == i1
						&& i1->opcode == Op_assign
				) {
					/* array[sub] = .. */
					i3->opcode = Op_store_sub;
					i3->memory = i2->memory;
					i3->expr_count = 1;  /* sub_count shadows memory,
                                          * so use expr_count instead.
				                          */
					i3->nexti = NULL;
					i2->opcode = Op_no_op;
					bcfree(i1);          /* Op_assign */
					exp->lasti = i3;     /* update Op_list */
					return exp;
				}
			}
			break;

		case Op_push_lhs:
			if (i2->nexti == i1
					&& i1->opcode == Op_assign
			) {
				/* var = .. */
				i2->opcode = Op_store_var;
				i2->nexti = NULL;
				bcfree(i1);          /* Op_assign */
				exp->lasti = i2;     /* update Op_list */

				i3 = exp->nexti;
				if (i3->opcode == Op_push_i
					&& (i3->memory->flags & INTLSTR) == 0
					&& i3->nexti == i2
				) {
					/* constant initializer */
					i2->initval = i3->memory;
					bcfree(i3);
					exp->nexti = i2;
				} else
					i2->initval = NULL;

				return exp;
			}
			break;

		default:
			break;
		}
	}

	/* no optimization  */
	return list_append(exp, instruction(Op_pop));
}


/* mk_getline --- make instructions for getline */

static INSTRUCTION *
mk_getline(INSTRUCTION *op, INSTRUCTION *var, INSTRUCTION *redir, int redirtype)
{
	INSTRUCTION *ip;
	INSTRUCTION *tp;
	INSTRUCTION *asgn = NULL;

	/*
	 *  getline [var] < [file]
	 *
	 *  [ file (simp_exp)]
	 *  [ [ var ] ]
	 *  [ Op_K_getline_redir|NULL|redir_type|into_var]
	 *  [ [var_assign] ]
	 *
	 */

	if (redir == NULL) {
		int sline = op->source_line;
		bcfree(op);
		op = bcalloc(Op_K_getline, 2, sline);
		(op + 1)->target_endfile = ip_endfile;
		(op + 1)->target_beginfile = ip_beginfile;
	}

	if (var != NULL) {
		tp = make_assignable(var->lasti);
		assert(tp != NULL);

		/* check if we need after_assign bytecode */
		if (tp->opcode == Op_push_lhs
				&& tp->memory->type == Node_var
				&& tp->memory->var_assign
		) {
			asgn = instruction(Op_var_assign);
			asgn->assign_ctxt = op->opcode;
			asgn->assign_var = tp->memory->var_assign;
		} else if (tp->opcode == Op_field_spec_lhs) {
			asgn = instruction(Op_field_assign);
			asgn->assign_ctxt = op->opcode;
			asgn->field_assign = (Func_ptr) 0;   /* determined at run time */
			tp->target_assign = asgn;
		} else if (tp->opcode == Op_subscript_lhs) {
			asgn = instruction(Op_subscript_assign);
			asgn->assign_ctxt = op->opcode;
		}

		if (redir != NULL) {
			ip = list_merge(redir, var);
			(void) list_append(ip, op);
		} else
			ip = list_append(var, op);
	} else if (redir != NULL)
		ip = list_append(redir, op);
	else
		ip = list_create(op);
	op->into_var = (var != NULL);
	op->redir_type = (redir != NULL) ? redirtype : redirect_none;

	return (asgn == NULL ? ip : list_append(ip, asgn));
}


/* mk_for_loop --- for loop bytecodes */

static INSTRUCTION *
mk_for_loop(INSTRUCTION *forp, INSTRUCTION *init, INSTRUCTION *cond,
				INSTRUCTION *incr, INSTRUCTION *body)
{
	/*
	 *   ------------------------
	 *        init                 (may be NULL)
	 *   ------------------------
	 * x:
	 *        cond                 (Op_no_op if NULL)
	 *   ------------------------
	 *    [ Op_jmp_false tb      ]
	 *   ------------------------
	 *        body                 (may be NULL)
	 *   ------------------------
	 * tc:
	 *    incr                      (may be NULL)
	 *    [ Op_jmp x             ]
	 *   ------------------------
	 * tb:[ Op_no_op             ]
	 */

	INSTRUCTION *ip, *tbreak, *tcont;
	INSTRUCTION *jmp;
	INSTRUCTION *pp_cond;
	INSTRUCTION *ret;

	tbreak = instruction(Op_no_op);

	if (cond != NULL) {
		add_lint(cond, LINT_assign_in_cond);
		pp_cond = cond->nexti;
		ip = cond;
		(void) list_append(ip, instruction(Op_jmp_false));
		ip->lasti->target_jmp = tbreak;
	} else {
		pp_cond = instruction(Op_no_op);
		ip = list_create(pp_cond);
	}

	if (init != NULL)
		ip = list_merge(init, ip);

	if (do_pretty_print) {
		(void) list_append(ip, instruction(Op_exec_count));
		(forp + 1)->forloop_cond = pp_cond;
		(forp + 1)->forloop_body = ip->lasti;
	}

	if (body != NULL)
		(void) list_merge(ip, body);

	jmp = instruction(Op_jmp);
	jmp->target_jmp = pp_cond;
	if (incr == NULL)
		tcont = jmp;
	else {
		tcont = incr->nexti;
		(void) list_merge(ip, incr);
	}

	(void) list_append(ip, jmp);
	ret = list_append(ip, tbreak);
	fix_break_continue(ret, tbreak, tcont);

	if (do_pretty_print) {
		forp->target_break = tbreak;
		forp->target_continue = tcont;
		ret = list_prepend(ret, forp);
	}
	/* else
		forp is NULL */

	return ret;
}

/* add_lint --- add lint warning bytecode if needed */

static void
add_lint(INSTRUCTION *list, LINTTYPE linttype)
{
#ifndef NO_LINT
	INSTRUCTION *ip;
	bool no_effect = true;

	switch (linttype) {
	case LINT_assign_in_cond:
		ip = list->lasti;
		if (ip->opcode == Op_var_assign || ip->opcode == Op_field_assign) {
			assert(ip != list->nexti);
			for (ip = list->nexti; ip->nexti != list->lasti; ip = ip->nexti)
				;
		}

		if (ip->opcode == Op_assign || ip->opcode == Op_assign_concat) {
			list_append(list, instruction(Op_lint));
			list->lasti->lint_type = linttype;
		}
		break;

	case LINT_no_effect:
		if (list->lasti->opcode == Op_pop && list->nexti != list->lasti) {
			int line = 0;

			// Get down to the last instruction ...
			for (ip = list->nexti; ip->nexti != list->lasti; ip = ip->nexti) {
				// ... along the way track line numbers, we will use the line
				// closest to the opcode if that opcode doesn't have one
				if (ip->source_line != 0)
					line = ip->source_line;

				// And check each opcode for no effect
				no_effect = no_effect && isnoeffect(ip->opcode);
			}

			// check the last one also
			no_effect = no_effect && isnoeffect(ip->opcode);

			// Only if all the traversed opcodes have no effect do we
			// produce a warning. This avoids warnings for things like
			// a == b && b = c.
			if (do_lint) {		/* parse-time warning */
				if (no_effect) {
					if (ip->source_line != 0)
						line = ip->source_line;
					lintwarn_ln(line, _("statement has no effect"));
				}
			}

			// We no longer place a run-time warning also. One warning
			// at parse time is enough.
		}
		break;

	default:
		break;
	}
#endif
}

/* mk_expression_list --- list of bytecode lists */

static INSTRUCTION *
mk_expression_list(INSTRUCTION *list, INSTRUCTION *s1)
{
	INSTRUCTION *r;

	/* we can't just combine all bytecodes, since we need to
	 * process individual expressions for a few builtins in snode() (-:
	 */

	/* -- list of lists     */
	/* [Op_list| ... ]------
	 *                       |
	 * [Op_list| ... ]   --  |
	 *  ...               |  |
	 *  ...       <-------   |
	 * [Op_list| ... ]   --  |
	 *  ...               |  |
	 *  ...               |  |
	 *  ...       <------- --
	 */

	assert(s1 != NULL && s1->opcode == Op_list);
	if (list == NULL) {
		list = instruction(Op_list);
		list->nexti = s1;
		list->lasti = s1->lasti;
		return list;
	}

	/* append expression to the end of the list */

	r = list->lasti;
	r->nexti = s1;
	list->lasti = s1->lasti;
	return list;
}

/* count_expressions --- fixup expression_list from mk_expression_list.
 *                       returns no of expressions in list. isarg is true
 *                       for function arguments.
 */

static int
count_expressions(INSTRUCTION **list, bool isarg)
{
	INSTRUCTION *expr;
	INSTRUCTION *r = NULL;
	int count = 0;

	if (*list == NULL)	/* error earlier */
		return 0;

	for (expr = (*list)->nexti; expr; ) {
		INSTRUCTION *t1, *t2;
		t1 = expr->nexti;
		t2 = expr->lasti;
		if (isarg && t1 == t2 && t1->opcode == Op_push)
			t1->opcode = Op_push_param;
		if (++count == 1)
			r = expr;
		else
			(void) list_merge(r, expr);
		expr = t2->nexti;
	}

	assert(count > 0);
	if (! isarg && count > max_args)
		max_args = count;
	bcfree(*list);
	*list = r;
	return count;
}

/* fix_break_continue --- fix up break & continue codes in loop bodies */

static void
fix_break_continue(INSTRUCTION *list, INSTRUCTION *b_target, INSTRUCTION *c_target)
{
	INSTRUCTION *ip;

	list->lasti->nexti = NULL;	/* just to make sure */

	for (ip = list->nexti; ip != NULL; ip = ip->nexti) {
		switch (ip->opcode) {
		case Op_K_break:
			if (ip->target_jmp == NULL)
				ip->target_jmp = b_target;
			break;

		case Op_K_continue:
			if (ip->target_jmp == NULL)
				ip->target_jmp = c_target;
			break;

		default:
			/* this is to keep the compiler happy. sheesh. */
			break;
		}
	}
}

static inline INSTRUCTION *
list_create(INSTRUCTION *x)
{
	INSTRUCTION *l;

	l = instruction(Op_list);
	l->nexti = x;
	l->lasti = x;
	return l;
}

static inline INSTRUCTION *
list_append(INSTRUCTION *l, INSTRUCTION *x)
{
#ifdef GAWKDEBUG
	if (l->opcode != Op_list)
		cant_happen("unexpected value %s for opcode", opcode2str(l->opcode));
#endif
	l->lasti->nexti = x;
	l->lasti = x;
	return l;
}

static inline INSTRUCTION *
list_prepend(INSTRUCTION *l, INSTRUCTION *x)
{
#ifdef GAWKDEBUG
	if (l->opcode != Op_list)
		cant_happen("unexpected value %s for opcode", opcode2str(l->opcode));
#endif
	x->nexti = l->nexti;
	l->nexti = x;
	return l;
}

static inline INSTRUCTION *
list_merge(INSTRUCTION *l1, INSTRUCTION *l2)
{
#ifdef GAWKDEBUG
	if (l1->opcode != Op_list)
		cant_happen("unexpected value %s for opcode", opcode2str(l1->opcode));
	if (l2->opcode != Op_list)
		cant_happen("unexpected value %s for opcode", opcode2str(l2->opcode));
#endif
	l1->lasti->nexti = l2->nexti;
	l1->lasti = l2->lasti;
	bcfree(l2);
	return l1;
}

/* See if name is a special token. */

int
check_special(const char *name)
{
	int low, high, mid;
	int i;
	int non_standard_flags = 0;
#ifdef USE_EBCDIC
	static bool did_sort = false;

	if (! did_sort) {
		qsort((void *) tokentab,
				sizeof(tokentab) / sizeof(tokentab[0]),
				sizeof(tokentab[0]), tokcompare);
		did_sort = true;
	}
#endif

	if (do_traditional)
		non_standard_flags |= GAWKX;
	if (do_posix)
		non_standard_flags |= NOT_POSIX;

	low = 0;
	high = (sizeof(tokentab) / sizeof(tokentab[0])) - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		i = *name - tokentab[mid].operator[0];
		if (i == 0)
			i = strcmp(name, tokentab[mid].operator);

		if (i < 0)		/* token < mid */
			high = mid - 1;
		else if (i > 0)		/* token > mid */
			low = mid + 1;
		else {
			if ((tokentab[mid].flags & non_standard_flags) != 0)
				return -1;
			return mid;
		}
	}
	return -1;
}

/*
 * This provides a private version of functions that act like VMS's
 * variable-length record filesystem, where there was a bug on
 * certain source files.
 */

static FILE *fp = NULL;

/* read_one_line --- return one input line at a time. mainly for debugging. */

static ssize_t
read_one_line(int fd, void *buffer, size_t count)
{
	char buf[BUFSIZ];

	/* Minor potential memory leak here. Too bad. */
	if (fp == NULL) {
		fp = fdopen(fd, "r");
		if (fp == NULL) {
			fprintf(stderr, "ugh. fdopen: %s\n", strerror(errno));
			gawk_exit(EXIT_FAILURE);
		}
	}

	if (fgets(buf, sizeof buf, fp) == NULL)
		return 0;

	memcpy(buffer, buf, strlen(buf));
	return strlen(buf);
}

/* one_line_close --- close the open file being read with read_one_line() */

static int
one_line_close(int fd)
{
	int ret;

	if (fp == NULL || fd != fileno(fp))
		fatal("debugging read/close screwed up!");

	ret = fclose(fp);
	fp = NULL;
	return ret;
}


/* lookup_builtin --- find a builtin function or return NULL */

builtin_func_t
lookup_builtin(const char *name)
{
	if (strncmp(name, "awk::", 5) == 0)
		name += 5;

	int mid = check_special(name);

	if (mid == -1)
		return NULL;

	switch (tokentab[mid].class) {
	case LEX_BUILTIN:
	case LEX_LENGTH:
		break;
	default:
		return NULL;
	}

	/* And another special case... */
	if (tokentab[mid].value == Op_sub_builtin)
		return (builtin_func_t) do_sub;

#ifdef HAVE_MPFR
	if (do_mpfr && tokentab[mid].ptr2 != NULL)
		return tokentab[mid].ptr2;
#endif

	return tokentab[mid].ptr;
}

/* install_builtins --- add built-in functions to FUNCTAB */

void
install_builtins(void)
{
	int i, j;
	int flags_that_must_be_clear = DEBUG_USE;

	if (do_traditional)
		flags_that_must_be_clear |= GAWKX;

	if (do_posix)
		flags_that_must_be_clear |= NOT_POSIX;


	j = sizeof(tokentab) / sizeof(tokentab[0]);
	for (i = 0; i < j; i++) {
		if (   (tokentab[i].class == LEX_BUILTIN
		        || tokentab[i].class == LEX_LENGTH)
		    && (tokentab[i].flags & flags_that_must_be_clear) == 0) {
			(void) install_symbol(tokentab[i].operator, Node_builtin_func);
		}
	}
}

/*
 * 9/2014: Gawk cannot use <ctype.h> isalpha or isalnum when
 * parsing the program since that can let through non-English
 * letters.  So, we supply our own. !@#$%^&*()-ing locales!
 */

/* is_alpha --- return true if c is an English letter */

/*
 * The scene of the murder was grisly to look upon.  When the inspector
 * arrived, the sergeant turned to him and said, "Another programmer stabbed
 * in the back. He never knew what happened."
 *
 * The inspector replied, "Looks like the MO of isalpha, and his even meaner
 * big brother, isalnum. The Locale brothers."  The sergeant merely
 * shuddered in horror.
 */

bool
is_alpha(int c)
{
	switch (c) {
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
	case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
	case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
	case 's': case 't': case 'u': case 'v': case 'w': case 'x':
	case 'y': case 'z':
	case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
	case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
	case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
	case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
	case 'Y': case 'Z':
		return true;
	}
	return false;
}

/* is_alnum --- return true for alphanumeric, English only letters */

bool
is_alnum(int c)
{
	/* digit test is good for EBCDIC too. so there. */
	return (is_alpha(c) || ('0' <= c && c <= '9'));
}


/*
 * is_letter --- function to check letters
 *	isalpha() isn't good enough since it can look at the locale.
 * Underscore counts as a letter in awk identifiers
 */

bool
is_letter(int c)
{
	return (is_alpha(c) || c == '_');
}

/* is_identchar --- return true if c can be in an identifier */

bool
is_identchar(int c)
{
	return (is_alnum(c) || c == '_');
}

/* set_profile_text --- make a number that can be printed when profiling */

static NODE *
set_profile_text(NODE *n, const char *str, size_t len)
{
	if (do_pretty_print) {
		// two extra bytes: one for NUL termination, and another in
		// case we need to add a leading minus sign in add_sign_to_num
		emalloc(n->stptr, char *, len + 2);
		memcpy(n->stptr, str, len);
		n->stptr[len] = '\0';
		n->stlen = len;
		// Set STRCUR and n->stfmt for use when profiling
		// (i.e., actually running the program) so that
		// force_string() on this item will work ok.
		// Thanks and a tip of the hatlo to valgrind.
		n->flags |= (NUMCONSTSTR|STRCUR);
		n->stfmt = STFMT_UNUSED;
#ifdef HAVE_MPFR
		n->strndmode = MPFR_round_mode;
#endif
	}

	return n;
}

/*
 * merge_comments --- merge c2 into c1 and free c2 if successful.
 *	Allow c2 to be NULL, in which case just merged chained
 *	comments in c1.
 */

static void
merge_comments(INSTRUCTION *c1, INSTRUCTION *c2)
{
	assert(c1->opcode == Op_comment);

	if (c1->comment == NULL && c2 == NULL)	// nothing to do
		return;

	size_t total = c1->memory->stlen;
	if (c1->comment != NULL)
		total += 1 /* \n */ + c1->comment->memory->stlen;

	if (c2 != NULL) {
		assert(c2->opcode == Op_comment);
		total += 1 /* \n */ + c2->memory->stlen;
		if (c2->comment != NULL)
			total += c2->comment->memory->stlen + 1;
	}

	char *buffer;
	emalloc(buffer, char *, total + 1);

	strcpy(buffer, c1->memory->stptr);
	if (c1->comment != NULL) {
		strcat(buffer, "\n");
		strcat(buffer, c1->comment->memory->stptr);
	}

	if (c2 != NULL) {
		strcat(buffer, c2->memory->stptr);
		if (c2->comment != NULL) {
			strcat(buffer, "\n");
			strcat(buffer, c2->comment->memory->stptr);
		}

		unref(c2->memory);
		if (c2->comment != NULL) {
			unref(c2->comment->memory);
			bcfree(c2->comment);
			c2->comment = NULL;
		}
		bcfree(c2);
	}

	c1->memory->comment_type = BLOCK_COMMENT;
	free(c1->memory->stptr);
	c1->memory->stptr = buffer;
	c1->memory->stlen = strlen(buffer);

	// now free everything else
	if (c1->comment != NULL) {
		unref(c1->comment->memory);
		bcfree(c1->comment);
		c1->comment = NULL;
	}
}

/* make_braced_statements --- handle `l_brace statements r_brace' with comments */

static INSTRUCTION *
make_braced_statements(INSTRUCTION *lbrace, INSTRUCTION *stmts, INSTRUCTION *rbrace)
{
	INSTRUCTION *ip;

	if (stmts == NULL)
		ip = list_create(instruction(Op_no_op));
	else
		ip = stmts;

	if (lbrace != NULL) {
		INSTRUCTION *comment2 = lbrace->comment;
		if (comment2 != NULL) {
			ip = list_prepend(ip, comment2);
			lbrace->comment = NULL;
		}
		ip = list_prepend(ip, lbrace);
	}

	return ip;
}

/* validate_qualified_name --- make sure that a qualified name is built correctly */

/*
 * This routine returns upon first error, no need to produce multiple, possibly
 * conflicting / confusing error messages.
 */

bool
validate_qualified_name(char *token)
{
	char *cp, *cp2;

	// no colon, by definition it's well formed
	if ((cp = strchr(token, ':')) == NULL)
		return true;

	if (do_traditional || do_posix) {
		error_ln(sourceline, _("identifier %s: qualified names not allowed in traditional / POSIX mode"), token);
		return false;
	}

	if (cp[1] != ':') {	// could happen from command line
		error_ln(sourceline, _("identifier %s: namespace separator is two colons, not one"), token);
		return false;
	}

	if (! is_letter(cp[2])) {
		error_ln(sourceline,
				_("qualified identifier `%s' is badly formed"),
				token);
		return false;
	}

	if ((cp2 = strchr(cp+2, ':')) != NULL) {
		error_ln(sourceline,
			_("identifier `%s': namespace separator can only appear once in a qualified name"),
			token);
		return false;
	}

	return true;
}

/* check_qualified_special --- decide if a name is special or not */

static int
check_qualified_special(char *token)
{
	char *cp;

	if ((cp = strchr(token, ':')) == NULL && current_namespace == awk_namespace)
		return check_special(token);

	/*
	 * Now it's more complicated.  Here are the rules.
	 *
	 * 1. Namespace name cannot be a standard awk reserved word or function.
	 * 2. Subordinate part of the name cannot be a standard awk reserved word or function.
	 * 3. If the namespace part is explicitly "awk", return the result of check_special().
	 * 4. Else return -1 (gawk extensions allowed, we check standard awk in step 2).
	 */

	const struct token *tok;
	int i;
	if (cp == NULL) {	// namespace not awk, but a simple identifier
		i = check_special(token);
		if (i < 0)
			return i;

		tok = & tokentab[i];
		if ((tok->flags & GAWKX) != 0 && tok->class == LEX_BUILTIN)
			return -1;
		else
			return i;
	}

	char *ns, *end, *subname;
	ns = token;
	*(end = cp) = '\0';	// temporarily turn it into standalone string
	subname = end + 2;

	// First check the namespace part
	i = check_special(ns);
	if (i >= 0 && (tokentab[i].flags & GAWKX) == 0) {
		error_ln(sourceline, _("using reserved identifier `%s' as a namespace is not allowed"), ns);
		goto done;
	}

	// Now check the subordinate part
	i = check_special(subname);
	if (i >= 0 && (tokentab[i].flags & GAWKX) == 0 && strcmp(ns, awk_namespace) != 0) {
		error_ln(sourceline, _("using reserved identifier `%s' as second component of a qualified name is not allowed"), subname);
		goto done;
	}

	if (strcmp(ns, awk_namespace) == 0) {
		i = check_special(subname);
		if (i >= 0) {
			if ((tokentab[i].flags & GAWKX) != 0 && tokentab[i].class == LEX_BUILTIN)
				;	// gawk additional builtin function, is ok
			else
				error_ln(sourceline, _("using reserved identifier `%s' as second component of a qualified name is not allowed"), subname);
		}
	} else
		i = -1;
done:
	*end = ':';
	return i;
}

/* set_namespace --- update namespace data structures */

static void
set_namespace(INSTRUCTION *ns, INSTRUCTION *comment)
{
	if (ns == NULL)
		return;

	if (do_traditional || do_posix) {
		error_ln(ns->source_line, _("@namespace is a gawk extension"));
		efree(ns->lextok);
		bcfree(ns);
		return;
	}

	if (! is_valid_identifier(ns->lextok)) {
		error_ln(ns->source_line, _("namespace name `%s' must meet identifier naming rules"), ns->lextok);
		efree(ns->lextok);
		bcfree(ns);
		return;
	}

	int mid = check_special(ns->lextok);

	if (mid >= 0) {
		error_ln(ns->source_line, _("using reserved identifier `%s' as a namespace is not allowed"), ns->lextok);
		efree(ns->lextok);
		bcfree(ns);
		return;
	}

	// Actual changing of namespace is done earlier.
	// See comments in the production and in yylex().

	efree(ns->lextok);

	// save info and push on front of list of namespaces seen
	push_ns_onto_namespace_chain(comment);

	ns->lextok = NULL;
	bcfree(ns);

	return;
}

/* change_namespace --- change the current namespace */

static void
change_namespace(const char *new_namespace)
{
	/* error messages will come from set_namespace(), above */

	if (! is_valid_identifier(new_namespace))
		return;

	int mid = check_special(new_namespace);

	if (mid >= 0)
		return;

	if (strcmp(new_namespace, current_namespace) == 0)
		;	// nothing to do
	else if (strcmp(new_namespace, awk_namespace) == 0) {
		set_current_namespace(awk_namespace);
	} else {
		set_current_namespace(estrdup(new_namespace, strlen(new_namespace)));
	}

	namespace_changed = true;
}

/* qualify_name --- put name into namespace */

static char *
qualify_name(const char *name, size_t len)
{
	if (strchr(name, ':') != NULL)	// already qualified
		return estrdup(name, len);

	NODE *p = lookup(name);
	if (p != NULL && p->type == Node_param_list)
		return estrdup(name, len);

	if (current_namespace != awk_namespace && ! is_all_upper(name)) {
		size_t length = strlen(current_namespace) + 2 + len + 1;
		char *buf;

		emalloc(buf, char *, length);
		sprintf(buf, "%s::%s", current_namespace, name);

		return buf;
	}

	return estrdup(name, len);
}
