#include "push_swap.h"

int	sort(struct DisplayData *display)
{
    if (!display->a && !display->b)
        return(-1);
    node *a;
    node *b;
    int checker;
    int i;
    a = display->a;
    b = display->b;
    int valueA;
    int valueB;
    if (!b->next)
    {
        checker = petit(a);
        if ( checker == 0)
            return (0);
        if (checker > numBarsA / 2) {
            i = numBarsA - checker;
            while (i > 0) {
                rotate(a, display);
                updater(display);
                i--;
            }
        } else {
            i = checker;
            while (i > 0) {
                r_rotate(a, display);
                updater(display);
                i--;
            }
        }
    }
    return(0);
}

int petit(node *a)
{
    if (!a){
        printf("Error finding petit\n");
        exit(1);
    }
    int indexCount;
    int i;
    i = 0;
    indexCount = 0;
    node *tmp;
    tmp = a->next;
    int mini = tmp->value;
    while (tmp->next)
    {
        if (tmp->value < mini)
        {
            mini = tmp->value;
            i = indexCount;
        }
        tmp = tmp->next;
        indexCount++;
    }
    if (tmp && tmp->value < mini)
        i= indexCount;
    return (i);
}

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
