#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
//# include "/opt/homebrew/Cellar/sdl2/2.28.2/include/SDL2/SDL.h"
//# include "SDL2/SLD.h"
# include "x86_64-w64-mingw32/include/SDL2/SDL.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
//# include <ncurses.h>
#endif

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

typedef	struct color {
			int r;
			int g;
			int b;
}color;

typedef struct node 
{
	double			scaled;
	int				value;
	char			*name;
	struct	node	*next;
	struct	node	*prev;

}node;

int			ft_atoi(const char *str);
int			ft_isspace(char c);
void * add_node(node *a, int value, int head);
void		remove_node(node *remove);
void		swap(node *a);
void		push(node *dest, node *src);
void		rotate(node *rotate);
void		r_rotate(node *reverse);
void		init_node(node *b, int size);
void		s_swap(node *a, node *b);
void		s_rot(node *a, node *b);
void		s_rev(node *a, node *b);
void		print_stack(node *a, node *b, int argc);
void		print_graph(int value);
