#include "push_swap.h"

node*	init_new_node(char *name)
{
	node *new;
	new = malloc(sizeof(node));
    if (!new)
        return(NULL);
	new->prev = NULL;
	new->next = NULL;
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

double	find_max(node *a)
{
	double max;
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

double	find_min(node *a)
{
	double min;
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


double max;
double min;
int numBarsB = 0;
int numBarsA = 0;
int attente;
int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Error\n");
		exit(1);
	}


    int error;
	node *a = init_new_node("a");
    if (!a) {
        return (-1);
    }
	node *b = init_new_node("b");
    if (!b)
        return(-1);
	fill_node_a(argc, a, argv);
//	print_stack(a, b, argc);
	min = find_min(a);
	max = find_max(a);

	error =	sdl_start(a , b,  numBarsB);
	if ( error == 0 )
	{	
		return(0);
	}
    return(0);
}
