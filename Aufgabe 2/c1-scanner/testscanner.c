#include <stdio.h>
#include <stdlib.h>
#include "minako.h"

yystype yylval;

int main(int argc, char* argv[])
{
	int token;

	if (argc != 2)
		yyin = stdin;
	else
	{
		yyin = fopen(argv[1], "r");
		if (yyin == 0)
		{
			fprintf(stderr, "Fehler: Konnte Datei %s nicht zum lesen oeffnen.\n", argv[1]);
			exit(-1);
		}
	}

	while ((token = yylex()) != EOF)
	{
		printf("Line: %3d\t", yylineno);
		switch (token)
		{
		case ID:
			printf("ID:     %s\n", yylval.string);
			break;
			
		case CONST_BOOLEAN:
			printf("BOOL:   %s\n", yylval.intValue ? "true" : "false");
			break;
			
		case CONST_INT:
			printf("INT:    %d\n", yylval.intValue);
			break;
			
		case CONST_FLOAT:
			printf("FLOAT:  %g\n", yylval.floatValue);
			break;
			
		case CONST_STRING:
			printf("STRING: %s\n", yylval.string);
			break;
			
		default:
			if (token <= 255)
				printf("Token: '%c'\n", token);
			else
				printf("Token: %d\n", token);
		}
	}
	return 0;
}
