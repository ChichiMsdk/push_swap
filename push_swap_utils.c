#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long int		result;
	long int		tmp;

	int thereIsInt = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{	
		thereIsInt = 1;
		tmp = result;
		result = (result * 10) + (*str - 48);
		str++;
		if (result < tmp && sign == 1)
			return (-1);
		if (result < tmp && sign == -1)
			return (0);
	}
	if (thereIsInt == 0)
		return (-1);
	return ((int)result * sign);
}

int numBar(node *a)
{
    if ( a->next)
    {
        node *tmp;
        tmp = a->next;
        int count;
        count = 1;
        while (tmp && tmp->next)
        {
            tmp = tmp->next;
            count++;
        }
        return(count);
    }
    return(-1);
}

void * add_node(node *a , int value, int head)
{
	node	*new_node;
	new_node = malloc(sizeof(node));
    if (!new_node)
        return (NULL);
	new_node->value = value;
    new_node->progress = 0;
    if(!a)
        return(a);

	if (a->next == NULL)
	{
		a->next = new_node;
		new_node->prev = a;
        new_node->next = NULL;
        attente = 1;
        return(new_node);
	}
	if (!head)
	{
		node *tmp;
		tmp = a->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = NULL;
	}
	else {
        node *tmp;
        tmp = a->next;
        a->next = new_node;
        new_node->next = tmp;
        new_node->prev = a;
        tmp->prev = new_node;
        attente= 1;
    }
    return(new_node);
}

void	swap(node *a,struct DisplayData *display)
{
	if (!a->next || !a->next->next)
	{
		printf("Error\n");
        iwww=100;
	}
	else if (a->next && a->next->next)
	{
        counter++;
		int tmp;
		tmp = a->next->value;
		a->next->value = a->next->next->value;
		a->next->next->value = tmp;
        attente=2;
        //updater(display);
	}
}

void	r_rotate(node *reverse, struct DisplayData *display)
{
	if (!reverse->next || !reverse->next->next || !reverse->next->next->next )
	{
		printf("Error\n");
        iwww=100;
	}
	else
	{
        counter++;
		node *current;
		int first;

		current = reverse->next;
		first = current->value;
		while ( current->next )
		{
			current->value = current->next->value;
            current->progressi = 0.01;
            current = current->next;
		}
		current->value = first;
        current->progressi = 0.01;
        //updater(display);
	}
}

void	rotate(node *rotate, struct DisplayData *display)
{	
	if (!rotate->next || !rotate->next->next  || !rotate->next->next->next )
	{
		printf("Error\n");
        iwww=100;
	}
	else 
	{
        counter++;
		node *current;
		int last;

		current = rotate->next;
		current->prev = NULL;
		while ( current->next )
		{
			current->next->prev = current;
			current = current->next;
		}
		last = current->value;
		while (current->prev != NULL)
		{
            current->progressi = 0.01;
			current->value = current->prev->value;
			current = current->prev;
		}
        current->progressi = 0.01;
		current->value = last;
        attente=2;
        //updater(display);
		}
}

void	remove_node(node *remove)
{
    if ( remove == NULL || remove->prev != NULL )
    {
        printf("Error\n");
        iwww=100;
	}
    else if (!remove->next->next)
    {
        free(remove->next);
        remove->next = NULL;
    }

    else
	{
		node *tmp;
		tmp = remove->next;
		remove->next = remove->next->next;
		remove->next->prev = remove;
		free(tmp);
		tmp = NULL;
	}
}

void	push(node *dest, node *src, struct DisplayData *display)
{
	if (!src->next)
    {
		printf("Error\n");
        iwww=100;
    }
    if ( src->next)
    {
        add_node(dest, src->next->value, 1);
        remove_node(src);
        counter++;
        int error;
        error = 1;
        //error = updater(display);
        if (error ==0)
            exit(1);
    }
}

void	s_swap(node *a, node *b, struct DisplayData *display)
{
	swap(a, display);
	swap(b, display);
}

void	s_rot(node *a, node *b,  struct DisplayData *display)
{
	rotate(a, display);
	rotate(b,display );
}

void	s_rev(node *a, node *b, struct DisplayData *display)
{
	r_rotate(a, display);
	r_rotate(b, display);
}


double	find_min(node *a)
{
	if (!a){
		printf("Error finding min\n");
		exit(1);
	}
    node *tmp;
    tmp = a->next;
    min = tmp->value;
    while (tmp->next)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    tmp->value < min ? min = tmp->value : 0;
    return (min);
}

double	find_max(node *a)
{
    if (!a){
        printf("Error finding max\n");
        exit(1);
    }
    node *tmp;
    tmp = a->next;
    max = tmp->value;
    while (tmp->next)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    tmp->value > max ? max = tmp->value : 0;
    return (max);
}

node*	init_new_node(int name)
{
    node *new;
    new = malloc(sizeof(node));
    if (!new)
        return(NULL);
    new->prev = NULL;
    new->progress = 0;
    new->progressi = 0.01;
    new->next = NULL;
    new->delay = 0;
    new->name = name;
    new->start_scaled = 0;
    return (new);
}

void	fill_node_a(struct DisplayData *display)
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (display->argc <= 1)
    {
        while ( i < 500)
        {
            add_node(display->a, display->emergency[i] , 0);
            i++;
        }
    }
    while (display->argc > 1 && i < display->argc-1 && j < display->argc )
    {
        if (ft_atoi(display->argv[j])== -1)
        {
            printf("Error\n");
            exit(1);
        }
        add_node(display->a, ft_atoi(display->argv[j]), 0);
        i++;
        j++;
    }
}
