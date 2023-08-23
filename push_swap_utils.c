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

void * add_node(node *a , int value, int head)
{
	node	*new_node;
	new_node = malloc(sizeof(node));
    if (!new_node)
        return (NULL);
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
	else {
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
	{
		printf("Error\n");
	}
	else if (a->next && a->next->next)
	{
		int tmp;
		tmp = a->next->value;
		a->next->value = a->next->next->value;
		a->next->next->value = tmp;
	}
}

void	r_rotate(node *reverse)
{
	if (!reverse->next || !reverse->next->next || !reverse->next->next->next )
	{
		printf("Error\n");
	}
	else
	{
		node *current;
		int first;

		current = reverse->next;
		first = current->value;
		while ( current->next )
		{
			current->value = current->next->value;
			current = current->next;
		}
		current->value = first;
	}
}

void	rotate(node *rotate)
{	
	if (!rotate->next || !rotate->next->next  || !rotate->next->next->next )
	{
		printf("Error\n");
	}
	else 
	{
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
			current->value = current->prev->value;
			current = current->prev;
		}
		current->value = last;
		}
}

void	remove_node(node *remove)
{
	if ( remove == NULL || remove->prev != NULL )
	{
		printf("Error\n");
	}
	else
	{
		node *tmp;
		tmp = remove->next;
		remove->next = remove->next->next;
		free(tmp);
		tmp = NULL;
	}
}

void	push(node *dest, node *src)
{
	if (!src->next)
    {
		printf("Error\n");
    }
    if ( src->next)
    {
        add_node(dest, src->next->value, 1);
        remove_node(src);
    }
}

void	s_swap(node *a, node *b)
{
	swap(a);
	swap(b);
}

void	s_rot(node *a, node *b)
{
	rotate(a);
	rotate(b);
}

void	s_rev(node *a, node *b)
{
	r_rotate(a);
	r_rotate(b);
}
