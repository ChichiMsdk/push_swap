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
	fill_node_a(argc, a, argv);
	char input;

	print_stack(a, b, argc);
	while (1)
	{
		input = getchar();
		switch(input)
		{
			case 'b':
				push(a, b);
				print_stack(a, b, argc);
				break;
			case 'a':
				push(b, a);
				print_stack(a,b,argc);
				break;
			case 't':
				rotate(b);
				print_stack(a, b, argc);
				break;
			case 'r':
				rotate(a);
				print_stack(a,b, argc);
				break;
			case 'f':
				swap(b);
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
