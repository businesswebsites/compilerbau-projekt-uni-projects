#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	intstack_t stack;

	stackInit(&stack, 10);
	
	stackPush(&stack, 1);
	stackPush(&stack, 2);
	stackPush(&stack, 3);
	
	while (!stackIsEmpty(&stack))
		printf("%i\n", stackPop(&stack));
	
	stackPop(&stack);
	
	stackRelease(&stack);
	return 0;
}


/* Erwartete Ausgabe:
3
2
1
<<Fehlermeldung, da intstack_t leer>>
*/
