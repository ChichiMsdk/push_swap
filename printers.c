#include "push_swap.h"

void	print_stack(node *a,node *b, int argc)
{
	int i = 0;
	node *u;
	node *ub;
	ub = b->next;
	u = a->next;
	while(i < argc-1)
	{
		if (u) 
		{
			printf("\n[%d]       ", u->value);
            u = u->next;
		}
	//	else
	//	{
	//		printf("          ");
	//	}
		if (ub)
		{
			printf("[%d]\n", ub->value);
			ub = ub->next;
		}
		else
		{
			printf("\n");
		}
		i++;
	}
	printf("===\n");
	printf("a b\n");

}


