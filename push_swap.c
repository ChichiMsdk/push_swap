#include "push_swap.h"

node*	init_new_node(char *name)
{
	node *new;
	new = malloc(sizeof(node));
	new->prev = NULL;
	new->name = name;
	return (new);
}

void	fill_node_a(int argc, node *a, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while ( i < argc-1 && j < argc )
	{
		if (ft_atoi(argv[j])== -1)
		{
			printf("Error\n");
			exit(1);
		}
		add_node(a, ft_atoi(argv[j]), 0);
		i++;
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Error\n");
		exit(1);
	}
	node *a = init_new_node("a");
	node *b = init_new_node("b");
	}
