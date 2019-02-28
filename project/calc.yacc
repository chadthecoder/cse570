%{
#include <stdio.h>
double regs[26];
int base;
double last;
int yylex();
int yyerror(char *s);
int yywrap();
%}

%start list
%union {
  double a;
  char c;
}
%type <a> expr number DIGIT
%type <c> LETTER
%token DIGIT LETTER
%token goodbye
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

list: /* empty */
    | list stat '\n'
    | list error '\n' { yyerrok; }
    | list goodbye { exit(EXIT_SUCCESS); };

stat: expr {
        printf("%f\n", $1);
      }
    | LETTER '=' expr {
      regs[$1] = $3;
	last = regs[$1];
    };

expr: '(' expr ')' {
        $$ = $2;
	last = $$;
      }
    | expr '*' expr {
        $$ = $1 * $3;
	last = $$;
      }
    | '*' expr {
        $$ = last * $2;
	last = $$;
      }
    | expr '/' expr {
        $$ = $1 / $3;
	last = $$;
      }
    | '/' expr {
        $$ = last / $2;
	last = $$;
      }
    | expr '%' expr {
        $$ = (int)$1 % (int)$3;
	last = $$;
      }
    | expr '+' expr {
        $$ = $1 + $3;
	last = $$;
      }
    | '+' expr {
        $$ = last + $2;
	last = $$;
      }
    | expr '-' expr {
        $$ = $1 - $3;
	last = $$;
      }
    | '-' expr {
        $$ = last - $2;
	last = $$;
      }
    | expr '&' expr {
        $$ = (int)$1 & (int)$3;
	last = $$;
      }
    | '&' expr {
        $$ = (int)last & (int)$2;
	last = $$;
      }
    | expr '|' expr {
        $$ = (int)$1 | (int)$3;
	last = $$;
      }
/*
    | '-' expr %prec UMINUS {
        $$ = -$2;
      }
*/
    | LETTER {
        $$ = regs[$1];
	last = $$;
      }
    | number;

number: DIGIT {
          $$ = $1;
          base = ($1 == 0) ? 8 : 10;
        }
      | number DIGIT {
          $$ = base * $1 + $2;
        };

%%

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
