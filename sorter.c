#include "push_swap.h"

int	sort(struct DisplayData *display)
{
    if (!display->a && !display->b)
        return(-1);

    node *a;
    node *b;
    int sorted;
    int valueA;
    int valueB;
    int i;

    a = display->a;
    b = display->b;
    sorted = sortCheck(display);

    while (sorted != 0)
    {
        sorted = sortCheck(display);
        if (!b->next && a->next)
            rotate_min(display);
        if (a->next && b)
            pusher(display);
        if (!a->next && b->next)
            rotate_max(display); //USELESS HAHAHAA
        if (b->next && a)
            pusherBig(display);
        //updater(display);
    }

    return(0);
}

int sortCheck(struct DisplayData *display)
{
    if (!display->a->next || display->b->next )
        return(0);
    node *tmp;
    tmp = display->a->next;
    while (tmp)
    {
        if (tmp->next && tmp->value > tmp->next->value)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    pusherBig(struct DisplayData *display)
{
    node *tmp;

    tmp = display->b->next;
    while(tmp)
    {
        if (tmp && !tmp->next)
        {
            push(display->a, display->b, display);
            tmp = display->b->next;
        }
        if (tmp && tmp->value > tmp->next->value)
        {
            push(display->a, display->b, display);
            tmp = display->b->next;
        }
        else
            swap(display->b, display);
    }
    updater(display);
}

void    pusher(struct DisplayData *display)
{
        node *tmp;

        tmp = display->a->next;
        while(tmp)
        {
            if (tmp && !tmp->next)
            {
                push(display->b, display->a, display);
                tmp = display->a->next;
            }
            if (tmp && tmp->value < tmp->next->value)
            {
                push(display->b, display->a, display);
                tmp = display->a->next;
            }

            else
                swap(display->a, display);
        }
}

int grand(node *b)
{
    if (!b){
        printf("Error finding grand\n");
        exit(1);
    }
    int indexCount;
    int i;
    i = 0;
    indexCount = 0;
    node *tmp;
    tmp = b->next;
    int maxi = tmp->value;
    while (tmp->next)
    {
        if (tmp->value > maxi)
        {
            maxi = tmp->value;
            i = indexCount;
        }
        tmp = tmp->next;
        indexCount++;
    }
    if (tmp && tmp->value > maxi)
        i= indexCount;
    return (i);
}

void    rotate_max(struct DisplayData *display)
{
    int i;
    int checker;
    {
        checker = grand(display->b);
        if (checker !=0 && checker > numBarsA / 2) {
            i = numBarsA - checker;
            while (i > 0) {
                rotate(display->b, display);
                updater(display);
                i--;
            }
        }
        else
        {
            i = checker;
            while (i > 0) {
                r_rotate(display->b, display);
                updater(display);
                i--;
            }
        }
    }
}

void    rotate_min(struct DisplayData *display)
{
    int i;
    int checker;
    {
        checker = petit(display->a);
        if (checker !=0 && checker > numBarsA / 2) {
            i = numBarsA - checker;
            while (i > 0) {
                rotate(display->a, display);
                updater(display);
                i--;
            }
        }
        else
        {
            i = checker;
            while (i > 0) {
                r_rotate(display->a, display);
                updater(display);
                i--;
            }
        }
    }
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
