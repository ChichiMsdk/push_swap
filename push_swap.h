#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
//# include "/opt/homebrew/Cellar/sdl2/2.28.2/include/SDL2/SDL.h" //mac
//# include "SDL2/SLD.h"//
//# include <ncurses.h>
#endif
extern int numBarsA;
extern int attente;
#define WINDOW_WIDTH 1200
#define MIN_WINDOW_HEIGHT 300
#define MAX_WINDOW_HEIGHT 1000
extern double max;
extern double min;

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
    struct color    skin;

}node;

double      smoothstep(double x);
int         sdl_start(node *a,node *b, int numBarsB);
void        colorGR(node *tmp);
int			ft_atoi(const char *str);
int			ft_isspace(char c);
void        *add_node(node *a, int value, int head);
void		remove_node(node *remove);
void		swap(node *a);
void		push(node *dest, node *src);
void		rotate(node *rotate);
void		r_rotate(node *reverse);
void		s_swap(node *a, node *b);
void		s_rot(node *a, node *b);
void		s_rev(node *a, node *b);
void		print_stack(node *a, node *b, int argc);
void		print_graph(int value);
void		scale_bar(node *a);
node*	    init_new_node(char *name);

//fail
//
//int			event_listener(SDL_Renderer *renderer, SDL_Window *window, node *a,double min,double max, SDL_Event e);
