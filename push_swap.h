#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
#endif

typedef struct node 
{
	int				value;
	struct	node	*next;
	struct	node	*prev;

}node;
