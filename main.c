#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

struct s_stack
{
	int *stack_a;
	int *stack_b;
	int size;
};

struct s_stack	*init_stack(int size)
{
	struct s_stack *stack;
	in;
	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->stack_a = (int *)malloc(sizeof(int) * size);
	stack->stack_b = (int *)malloc(sizeof(int) * size);
	stack->size = size;
	return (stack);
}

void	push_a(struct s_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		stack->stack_a[i] = stack->stack_b[i];
		i++;
	}
}

void	push_b(struct s_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		stack->stack_b[i] = stack->stack_a[i];
		i++;
	}
}

void	swap_a(struct s_stack *stack)
{
	int tmp;

	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
}

void	swap_b(struct s_stack *stack)
{
	int tmp;

	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
}

void	swap_ab(struct s_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	rotate_a(struct s_stack *stack)
{
	int i;
	int tmp;

	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->size - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i] = tmp;
}

void	rotate_b(struct s_stack *stack)
{
	int i;
	int tmp;

	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->size - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i] = tmp;
}

void	rotate_ab(struct s_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void	reverse_rotate_a(struct s_stack *stack)
{
	int i;
	int tmp;

	i = stack->size - 1;
	tmp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[i] = tmp;
}

void	reverse_rotate_b(struct s_stack *stack)
{
	int i;
	int tmp;

	i = stack->size - 1;
	tmp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[i] = tmp;
}

void	reverse_rotate_ab(struct s_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}


int	ft_atoi(const char *str)
{
	int				sign;
	long int		result;
	long int		tmp;

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
		tmp = result;
		result = (result * 10) + (*str - 48);
		str++;
		if (result < tmp && sign == 1)
			return (-1);
		if (result < tmp && sign == -1)
			return (0);
	}
	return ((int)result * sign);
}


int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Wrong number of arguments\n");
		exit(1);
	}
	//push_swap
	//printf("argc = %d\n", argc);
	int i = 0;
	int j = 1;
	int stack_a[argc];
	int stack_b[argc];
	while(i < argc-1)
	{
		stack_b[i] = i;
		i++;
	}
	i = 0;
	while(i < argc-1 && j < argc)
	{
		if (ft_atoi(argv[j]) == -1)
		{
			printf("Error\n");
			exit(1);
		}
		stack_a[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	//stack_a[i] = 0;
	i = 0;
	while(i < argc-1)
	{
		printf("[%d][%d]\n",stack_a[i], stack_b[i]);
		i++;
	}
	//printf("a         b\n");
}
