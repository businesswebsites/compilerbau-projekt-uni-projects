#ifndef URLSCANNER_H
#define URLSCANNER_H

#define MYEOF      EOF
#define TOKEN_URL  257
#define TOKEN_TEXT 258

#ifndef YYSTYPE
#define YYSTYPE yystype
typedef char* yystype;
#endif

extern int yylex();
extern FILE* yyin;
extern yystype yylval;
extern int yylineno;

#endif
