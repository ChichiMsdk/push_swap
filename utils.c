#include "push_swap.h"

static int	ft_isspace(char c)
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

void	add_node(node *a ,int value, int head)
{
	node	*new_node;
	new_node = malloc(sizeof(node));
	new_node->value = value;
	if (a->next == NULL)
	{
		a->next = new_node;
		new_node->prev = a;
	}
	else if (!head)
	{
		node *tmp;
		tmp = a->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = NULL;
	}
	else if (head)
	{
		node *tmp;
		tmp = a->next;
		a->next = new_node;
		new_node->next = tmp;
		new_node->prev = a;
		tmp->prev = new_node;
	}
}

void	swap(node *a)
{
	if (!a->next || !a->next->next)
		printf("Not enough elements in %s\n", a->name);

	else if (a->next && a->next->next)
	{
		int tmp;
		tmp = a->next->value;
		a->next->value = a->next->next->value;
		a->next->next->value = tmp;
	}
}

void rotate(node *a)
{
	if (a->next == NULL || a->next->next == NULL)
	{
		printf("CANT ROTATE ELEMENTS\n");
		exit(1);
	}
	node *current;
	int last;
	current = a->next;
	current->prev = NULL;
	while ( current->next != NULL )
	{
		current->next->prev = current;
		current = current->next;
	}
	last = current->value;
	while (current->prev != NULL)
	{
		current->value = current->prev->value;
		current = current->prev;
	}
	current->value = last;
}

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
			printf("[%d]       ", u->value);
            u = u->next;
		}
		else
		{
			printf("          ");
		}
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
	printf("==        ==\n");
	printf("a         b\n");

}

void	remove_node(node *remove)
{
	if ( remove == NULL || remove->prev != NULL )
		printf("CANT REMOVE NODE\n");
	node *tmp;
	tmp = remove->next;
	remove->next = remove->next->next;
	free(tmp);
	tmp = NULL;
}

void push(node *dest, node *src)
{
	if (!src->next)
    {
        printf("[CANT PUSH ANYMORE, stack %s IS EMPTY]\n", src->name);
        printf("Maybe you wanted to push stack %s ?\n", dest->name);
    }
    if ( src->next)
    {
        add_node(dest, src->next->value, 1);
        remove_node(src);
    }
}
