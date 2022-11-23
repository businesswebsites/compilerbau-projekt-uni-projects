#include <stdio.h>
#include <stdlib.h>
#include "urlscanner.h"

yystype yylval;

int main(int argc, char* argv[]) {
	int token;

	if (argc != 2) yyin = stdin;
	else {
		yyin = fopen(argv[1], "r");
		if (yyin == 0) {
			fprintf(stderr,
                    "Fehler: Konnte Datei %s nicht zum lesen oeffnen.\n",
                    argv[1]);
			exit(-1);
		}
	}

	while ((token = yylex()) != MYEOF) {
		if (token == TOKEN_URL) {
			printf("Line: %3d\tURL:  %s\n", yylineno, yylval);
		} else if (token == TOKEN_TEXT) {
			printf("Line: %3d\tTEXT: %s\n", yylineno, yylval);
		} else {
			printf("Error\n");
		}
	}
	return 0;
}
