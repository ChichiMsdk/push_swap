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

void	add_node(node *a ,int value)
{
	node	*new_node;
	new_node = malloc(sizeof(node));
	new_node->value = value;
	if (a->next == NULL)
	{
		a->next = new_node;
	}
	else
	{
		node *tmp;
		tmp = a->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	new_node->next = NULL;
}

void	init_node(node *b, int size)
{
	while (size >0)
	{
		add_node(b,0);
		size--;
	}
}

void	swap(node *a)
{
	if (a->next == NULL || a->next->next == NULL)
	{
		printf("CANT SWAP ELEMENTS, ONE PROBABLY DOESNT EXIST\n");
		exit(1);
	}

	int tmp;
	tmp = a->next->value;
	a->next->value = a->next->next->value;
	a->next->next->value = tmp;
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
	ub = b;
	u = a;
	while(i < argc-1 && u->next != NULL)
	{
		u = u->next;
		printf("[%d]       [%d]\n", u->value, ub->value );
		i++;
	}
	printf("-----------\n");

}

void push(node *dest, node *src)
{
	if (src->next == NULL || dest->next == NULL)
	{
		exit(1);
	}
	//copy value from src to dest and then delete (free) src and rotate dest
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Error\n");
		exit(1);
	}
	int i = 0;
	int j = 1;
	//int size = argc -1;
	node *a = malloc(sizeof(node));
	node *b = malloc(sizeof(node));
	while(i < argc-1 && j < argc)
	{
		if (ft_atoi(argv[j]) == -1)
		{
			printf("Error\n");
			exit(1);
		}
		add_node(a,ft_atoi(argv[j]));
		i++;
		j++;
	}
	//init_node(b, size);
	char input;

	print_stack(a,b, argc);
	while (1)
	{
		input = getchar();
		switch(input)
		{
			case 'r':
				rotate(a);
				print_stack(a,b, argc);
				break;
			case 'f':
				print_stack(a,b, argc);
				break;
			case 's':
				swap(a);
				print_stack(a,b, argc);
				break;
			case 'p':
				printf("=============\nSTOPPING....\n=============\n");
				return(0);
			default:
				printf("Invalid input\n---------\n");
				break;
		}
		while (getchar() != '\n');
	}
}
