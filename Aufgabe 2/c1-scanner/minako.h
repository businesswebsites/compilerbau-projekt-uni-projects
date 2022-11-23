#ifndef MINAKO_H
#define MINAKO_H

#ifndef YYSTYPE
typedef union {
	char* string;
	double floatValue;
	int intValue;
} yystype;
#define YYSTYPE yystype
#endif

#define AND             257
#define OR              258
#define EQ              259
#define NEQ             260
#define LEQ             261
#define GEQ             262
#define LSS             263
#define GRT             264
#define KW_BOOLEAN      265
#define KW_DO           266
#define KW_ELSE         267
#define KW_FLOAT        268
#define KW_FOR          269
#define KW_IF           270
#define KW_INT          271
#define KW_PRINTF       272
#define KW_RETURN       273
#define KW_VOID         274
#define KW_WHILE        275
#define CONST_INT       276
#define CONST_FLOAT     277
#define CONST_BOOLEAN   278
#define CONST_STRING    279
#define ID              280

extern YYSTYPE yylval;
extern int yylex();
extern FILE* yyin;
extern int yylineno;

#endif
