#include "push_swap.h"
void	sort(node *a, node *b, struct DisplayData *display)
{
    numBarsA = 0;
    countBars(a);
    if (numBarsA <= 2)
        return;
    //petit(a);
    //updater(display);
	int pivot;
    pivot= average(a);
    int maxi;
    maxi = find_max(a);
    if (pivot != maxi)
    {
        maxi -= pivot - 1;
        sorter(a, b, maxi - pivot, display);
    }
    else
        sorterB(b,a,pivot, display);
	sort(a, b, display);

    //updater(display);
	//merge(a, b, display);
}

void	sortB(node *b, node *a, struct DisplayData *display)
{
    numBarsB = 0;
    countBars(b);
    if (numBarsB <= 2)
        return;
    //petit(a);
    //updater(display);
	int pivot;
    pivot = average(b);
    int maxiB;
    maxiB = find_max(b);
    if (average != maxiB)
    {
        maxiB -= pivot-1;
        sorterB(b, a, maxiB-pivot, display);
    }
    else
        sorterB(b,a,pivot, display);
	sortB(b, a, display);
    //updater(display);
	//merge(a, b, display);
}

void	sorterB(node *a, node *b, int pivot, struct DisplayData *display)
{
    if (pivot <= 0)
        pivot = average(a);
    int i;
    i = 0;
    int checker;
    checker = 0;
    node *tmp = a->next;
    while (i < numBarsB)
    {
        if (tmp && tmp->next && tmp->value < tmp->next->value )
            swap(a, display);
        if (tmp && tmp->value >= pivot)
        {
            push(b, a, display);
            checker++;
            numBarsB =0;
            countBars(a);
            tmp = a->next;
        }
        else
        {
            rotate(a, display);
        }
        i++;
    }
    if (checker > 1)
        sorterB(a, b, pivot, display);
}

void	sorter(node *a, node *b, int pivot, struct DisplayData *display)
{
    if (pivot <= 0)
        pivot = average(a);
	int i;
	i = 0;
	int checker;
	checker = 0;
    node *tmp = a->next;
	while (i < numBarsA)
	{
        if (tmp && tmp->next && tmp->value > tmp->next->value )
            swap(a, display);
		if (tmp && tmp->value <= pivot)
		{
			push(b, a, display);
			checker++;
            numBarsA =0;
            countBars(a);
            tmp = a->next;
		}
		else
        {
			rotate(a, display);
        }
		i++;
	}
	if (checker > 1)
		sorter(a, b, pivot, display);
}

void	merge(node *a, node *b, struct DisplayData *display)
{
    node *tmp;
    if (!b)
        return;
    if(b->next)
        tmp = b->next;
    else
        return;
    grand(b);
    while (tmp && b->next)
    {
        if (tmp->next && tmp->value < tmp->next->value)
            swap(b, display);
        push(a, b, display);
        updater(display);
        if (b->next)
            tmp = b->next;
    }
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
