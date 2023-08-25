#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <SDL2/SDL.h>
//# include <SDL2/SDL_mixer.h>
# include "sdl_mixer/include/SDL2/SDL_mixer.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
//# include "/opt/homebrew/Cellar/sdl2/2.28.2/include/SDL2/SDL.h" //mac
//# include "SDL2/SLD.h"//
//# include <ncurses.h>
#endif
extern int numBarsA;
extern int numBarsB;
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
	double			delay;
	double			start_scaled;
	int				value;
	double			progress;
    double			progressi;
	int 			name;
	struct	node	*next;
	struct	node	*prev;
    struct color    skin;

}node;

void        countBars(node *count);
double      lerp(double a, double b, double f);
void        drawing(SDL_Renderer *renderer, node *tmp,node *a, int barWidth);
void        drawingB(SDL_Renderer *renderer, node *tmpb,node *b, int barWidth);
double      smoothstep(double x);
int         sdl_start(node *a,node *b);
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
node	    *init_new_node(int name);
void        removingB(SDL_Renderer *renderer, node *tmpb, int barWidth);
void	    fill_node_a(int argc, node *a, char **argv, int emergency[]);
double	    find_max(node *a);
double	    find_min(node *a);
//fail
//
//int			event_listener(SDL_Renderer *renderer, SDL_Window *window, node *a,double min,double max, SDL_Event e);
