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
	if (tmp == NULL)
		return (-1);
	while (tmp->next != NULL)
	{
		compare = tmp->value;
		if (tmp->next)
		{
			minitmp = tmp->next;
			while ( minitmp -> next )
			{
				if (compare == minitmp->value)
					return (1);
				minitmp = minitmp->next;
			}
		}
		tmp = tmp->next;
	}
	if (compare == tmp->value)
		return(1);
	return(0);
}
