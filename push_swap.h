#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <ncurses.h>
#endif

typedef struct node 
{
	int				value;
	char			*name;
	struct	node	*next;
	struct	node	*prev;

}node;

int			ft_atoi(const char *str);
int			ft_isspace(char c);
void		add_node(node *a, int value, int head);
void		remove_node(node *remove);
void		swap(node *a);
void		push(node *dest, node *src);
void		rotate(node *rotate);
void		reverse_rotate(node *reverse);
void		init_node(node *b, int size);
void		s_swap(node *a, node *b);
void		s_rot(node *a, node *b);
void		s_rev(node *a, node *b);
