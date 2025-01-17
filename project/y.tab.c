/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "calc.yacc"
#include <stdio.h>
int regs[26];
int base;
int last;
int yylex();
int yyerror(char *s);
int yywrap();
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 12 "calc.yacc"
typedef union {
  int a;
  char c;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 41 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define DIGIT 257
#define LETTER 258
#define goodbye 259
#define UMINUS 260
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    2,
};
static const YYINT yylen[] = {                            2,
    0,    3,    3,    2,    1,    3,    3,    3,    2,    3,
    2,    3,    3,    2,    3,    3,    2,    3,    2,    1,
    1,    1,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   22,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    3,    0,   20,    0,    0,   19,
    9,   11,    0,    0,    0,    0,    0,    0,    0,    0,
   23,    2,    0,    7,    0,    0,    0,    0,    8,   10,
   12,
};
static const YYINT yydgoto[] = {                          1,
   12,   13,   14,
};
static const YYINT yysindex[] = {                         0,
  -38,   -7,    0,  -47,    0,  -32,  -32,  -32,  -32,  -32,
  -32,   38, -241,   14,    0,  -32,    0,   75,   77,    0,
    0,    0,  -20,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
    0,    0,   38,    0,   56,   75,   77,   77,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,   20,   -9,    0,    0,    0,    0,   31,   10,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   21,    0,    9,   33,   16,   25,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
   81,    0,    0,
};
#define YYTABLESIZE 226
static const YYINT yytable[] = {                          6,
   21,   11,   15,    9,    7,    6,    8,   11,   10,    9,
    7,   20,    8,   16,   10,   31,   30,   25,   18,   14,
   34,   28,   26,   32,   27,   13,   29,   21,   21,    5,
    6,   21,   21,   21,   15,   21,    0,   21,   20,   20,
   17,    0,   16,   20,   20,    0,   20,   14,   20,   18,
   14,    0,   14,   13,   14,    0,   13,    0,   13,    0,
   13,    0,   15,    0,    0,   15,    0,   15,   17,   15,
   16,   17,    0,   16,   30,   25,    0,    0,    0,   28,
   26,    0,   27,    0,   29,    0,   18,   19,   20,   21,
   22,   23,   30,   25,    0,    0,   33,   28,   26,    0,
   27,    0,   29,   24,   35,   36,   37,   38,   39,   40,
   41,   30,    0,   30,   21,    0,   28,   26,   28,   27,
    0,   29,    0,   29,    0,   20,    0,    0,    0,    0,
    0,    0,   18,   14,    0,    0,    0,    0,    0,   13,
    0,    0,    0,    0,    0,    0,    0,    0,   15,    0,
    0,    0,    0,    0,   17,    0,   16,    0,    0,    0,
    0,   24,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,    3,    4,
    5,    0,    0,    0,    3,   17,
};
static const YYINT yycheck[] = {                         38,
   10,   40,   10,   42,   43,   38,   45,   40,   47,   42,
   43,   10,   45,   61,   47,  257,   37,   38,   10,   10,
   41,   42,   43,   10,   45,   10,   47,   37,   38,   10,
   10,   41,   42,   43,   10,   45,   -1,   47,   37,   38,
   10,   -1,   10,   42,   43,   -1,   45,   38,   47,   41,
   41,   -1,   43,   38,   45,   -1,   41,   -1,   43,   -1,
   45,   -1,   38,   -1,   -1,   41,   -1,   43,   38,   45,
   38,   41,   -1,   41,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,    6,    7,    8,    9,
   10,   11,   37,   38,   -1,   -1,   16,   42,   43,   -1,
   45,   -1,   47,  124,   24,   25,   26,   27,   28,   29,
   30,   37,   -1,   37,  124,   -1,   42,   43,   42,   45,
   -1,   47,   -1,   47,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,  124,  124,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,  124,   -1,  124,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,  258,
  259,   -1,   -1,   -1,  257,  258,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 260
#define YYUNDFTOKEN 266
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"DIGIT","LETTER","goodbye","UMINUS",0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : list",
"list :",
"list : list stat '\\n'",
"list : list error '\\n'",
"list : list goodbye",
"stat : expr",
"stat : LETTER '=' expr",
"expr : '(' expr ')'",
"expr : expr '*' expr",
"expr : '*' expr",
"expr : expr '/' expr",
"expr : '/' expr",
"expr : expr '%' expr",
"expr : expr '+' expr",
"expr : '+' expr",
"expr : expr '-' expr",
"expr : expr '&' expr",
"expr : '&' expr",
"expr : expr '|' expr",
"expr : '-' expr",
"expr : LETTER",
"expr : number",
"number : DIGIT",
"number : number DIGIT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 113 "calc.yacc"

int main() {
  return yyparse();
}

int yyerror(char *s) {
  fprintf(stderr, "%s: memory is cleared\n", s);
last = 0;
  return 1;
}

int yywrap() {
  return 1;
}
#line 264 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 3:
#line 30 "calc.yacc"
	{ yyerrok; }
break;
case 4:
#line 31 "calc.yacc"
	{ exit(EXIT_SUCCESS); }
break;
case 5:
#line 33 "calc.yacc"
	{
        printf("%d\n", yystack.l_mark[0].a);
      }
break;
case 6:
#line 36 "calc.yacc"
	{
      regs[yystack.l_mark[-2].c] = yystack.l_mark[0].a;
	/*last = regs[$1];*/
    }
break;
case 7:
#line 41 "calc.yacc"
	{
        yyval.a = yystack.l_mark[-1].a;
	last = yyval.a;
      }
break;
case 8:
#line 45 "calc.yacc"
	{
        yyval.a = yystack.l_mark[-2].a * yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 9:
#line 49 "calc.yacc"
	{
        yyval.a = last * yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 10:
#line 53 "calc.yacc"
	{
        yyval.a = yystack.l_mark[-2].a / yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 11:
#line 57 "calc.yacc"
	{
        yyval.a = last / yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 12:
#line 61 "calc.yacc"
	{
        yyval.a = (int)yystack.l_mark[-2].a % (int)yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 13:
#line 65 "calc.yacc"
	{
        yyval.a = yystack.l_mark[-2].a + yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 14:
#line 69 "calc.yacc"
	{
        yyval.a = last + yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 15:
#line 73 "calc.yacc"
	{
        yyval.a = yystack.l_mark[-2].a - yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 16:
#line 81 "calc.yacc"
	{
        yyval.a = (int)yystack.l_mark[-2].a & (int)yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 17:
#line 85 "calc.yacc"
	{
        yyval.a = (int)last & (int)yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 18:
#line 89 "calc.yacc"
	{
        yyval.a = (int)yystack.l_mark[-2].a | (int)yystack.l_mark[0].a;
	last = yyval.a;
      }
break;
case 19:
#line 94 "calc.yacc"
	{
        yyval.a = -yystack.l_mark[0].a;
      }
break;
case 20:
#line 98 "calc.yacc"
	{
        yyval.a = regs[yystack.l_mark[0].c];
	/*last = $$;*/
      }
break;
case 22:
#line 104 "calc.yacc"
	{
          yyval.a = yystack.l_mark[0].a;
          base = (yystack.l_mark[0].a == 0) ? 8 : 10;
        }
break;
case 23:
#line 108 "calc.yacc"
	{
          yyval.a = base * yystack.l_mark[-1].a + yystack.l_mark[0].a;
        }
break;
#line 594 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
