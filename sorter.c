static void quicksort(int *arr, int low, int high)
{
    int sw;

    if (low < high)
    {
        sw = partition(arr, low, high);
        quicksort(arr, low, sw - 1);
        quicksort(arr, sw + 1, high);
    }
}
int *sort_stack(t_ps_list *s)
{
    int *k;
    int i;

    k = malloc(sizeof(int) * nodeSize(s));
    if (!k)
        exit(1);
    i = 0;
    while (s)
    {
        k[i++] = s->value;
        s = s->next;
    }
    quicksort(k, 0, i - 1);
    return (k);
}
quick_sor

void    sort_over(node *a, int s, struct DisplayData display)
{
    int j;
    int *k;

    k = sort_stack(a->next);
    j = ft_p_lstsize(a->next) - 1;
    put_to_b(push, s, k);
    while (a->next)
    {
        push(display->b, a,display );
        if (display->b->next < k[j / 2])
            rotate(a, display);
    }
    put_to_a(push, k[j], 0);
    free(k);
}

void	sort(node *a, display)
{
	sort_over(a, 30);
}
static int  partition(int *arr, int low, int high)
{
    int switcher;
    int i;
    int j;

    switcher = arr[high];
    i = (low - 1);
    j = low;
    while (j <= high - 1)
    {
        if (arr[j] <= switcher)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

static void quicksort(int *arr, int low, int high)
{
    int sw;

    if (low < high)
    {
        sw = partition(arr, low, high);
        quicksort(arr, low, sw - 1);
        quicksort(arr, sw + 1, high);
}

int	nodeSize(node *a, struct DisplayData *display)
{
	if (!a || !a->next )
		return(-1);
	int i;
	node *tmp;

	i = 0;
	tmp = a->next;
	//i++;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return(i);
}
