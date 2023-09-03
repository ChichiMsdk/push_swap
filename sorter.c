#include "push_swap.h"

//int	sort(display)
//{
//	//quicksort in one time 
//	//care to leaks prolly dont go for recursive 
//}

int	duplicate(node *a)
{
	node *tmp;
	node *minitmp;
	tmp = a->next;
	int compare;
    int goupix;
	if (tmp == NULL)
		return (-1);
	while (tmp->next != NULL)
	{
		compare = tmp->value;
		if (tmp->next)
		{
			minitmp = tmp->next;
			while ( minitmp )
			{
                goupix = minitmp->value;
				if (compare == goupix)
					return (compare);
				minitmp = minitmp->next;
			}
		}
	    	tmp = tmp->next;
	}
	return(0);
}
