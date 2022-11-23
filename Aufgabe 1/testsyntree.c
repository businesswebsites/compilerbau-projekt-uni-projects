#include <stdio.h>
#include "syntree.h"

int main()
{
	syntree_t tree;
	syntree_nid id;
	
	syntreeInit(&tree);
	
	id = syntreeNodeTag(&tree, syntreeNodeNumber(&tree, 0));
	for (unsigned int i = 1; i < 10; ++i)
	{
		switch (i % 3)
		{
		case 0:
			id = syntreeNodePair(&tree, syntreeNodeNumber(&tree, i), id);
			break;
			
		case 1:
			id = syntreeNodeAppend(&tree, id, syntreeNodeNumber(&tree, i));
			break;
			
		case 2:
			id = syntreeNodePrepend(&tree, syntreeNodeNumber(&tree, i), id);
			break;
		}
	}
	
	syntreePrint(&tree, id);
	syntreeRelease(&tree);
	
	return 0;
}

/* Erwartete Ausgabe nach Entfernen aller Leerzeichen:
{(9){(8)(6){(5)(3){(2)(0)(1)}(4)}(7)}}

Mit Leerzeichen:
{
    (9)
    {
        (8)
        (6)
        {
            (5)
            (3)
            {
                (2)
                (0)
                (1)
            }
            (4)
        }
        (7)
    }
}
*/
