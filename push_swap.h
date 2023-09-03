#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <SDL2/SDL.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
//# include <SDL2/SDL_mixer.h>
//# include <SDL2/SDL_ttf.h>
# include "sdl_mixer/include/SDL2/SDL_mixer.h"
# include "SDL2_ttf\include\SDL2\SDL_ttf.h"
# include "x86_64-w64-mingw32/include/SDL2/SDL.h"
//# include "/opt/homebrew/Cellar/sdl2/2.28.2/include/SDL2/SDL.h" //mac
//# include <ncurses.h>
#endif
extern int numBarsA;
extern int numBarsB;
extern int attente;
extern double max;
extern double min;
extern int iwww;
extern int counter;

#define WINDOW_WIDTH 1200
#define MIN_WINDOW_HEIGHT 300
#define MAX_WINDOW_HEIGHT 1000


typedef	struct color {
    int r;
    int g;
    int b;
} color;

typedef struct DisplayData {
    SDL_Event e;
    struct node *a;
    struct node *b;
    TTF_Font *font;
    SDL_Renderer *renderer;
    int barWidth;
    int argc;
    char **argv;
    Mix_Chunk *soundfx;
    SDL_Window *window;
    int emergency[500];
    struct node *tmp;
    struct node *tmpb;
    int max;
    int min;
} DisplayData;

typedef struct node 
{
    int             index;
	double			scaled;
	double			start_scaled;
	int				value;
	double			progress;
    int 			name;
	struct	node	*next;
    struct  color    skin;
    struct	node	*prev;
	double			progressi;
    double			delay;

} node;

//beginning
struct  node	    *init_new_node(int name);
void                *add_node(node *a, int value, int head);
void	            fill_node_a(struct DisplayData *display);
double	            find_max(node *a);
double	            find_min(node *a);
int		    	    ft_isspace(char c);
int		    	    ft_atoi(const char *str);
//actions
void		        remove_node(node *remove);
void	        	swap(node *a,  struct DisplayData *display);
void	        	push(node *dest, node *src, struct DisplayData *display);
void	        	rotate(node *rotate, struct DisplayData *display);
void	        	r_rotate(node *reverse, struct DisplayData *display);
void	        	s_swap(node *a, node *b,  struct DisplayData *display);
void	        	s_rot(node *a, node *b,  struct DisplayData *display);
void	        	s_rev(node *a, node *b,  struct DisplayData *display);
//sorting

int                 sortCheck(struct DisplayData *display);
void                pusherBig(struct DisplayData *display);
int                 sort(struct DisplayData *display);
void                pusher(struct DisplayData *display);
void                rotate_max(struct DisplayData *display);
void                rotate_min(struct DisplayData *display);
int                 petit(node *a);
int                 duplicate(node *a);
////////////////////////////////////////////////////////////////////////////////////////
//function for gui below
////////////////////////////////////////////////////////////////////////////////////////

int                 updater(struct DisplayData *display);
int                 update_display(struct DisplayData *display);
void	        	reset(struct DisplayData *display);
int                 sfx(int play, Mix_Chunk *soundfx);
void                countBars(node *count);
double              lerp(double a, double b, double f);
void                drawing(struct DisplayData *display);
void                drawingB(struct DisplayData *display);
double              smoothstep(double x);
int                 sdl_start(struct DisplayData *display);
void                colorGR(node *tmp);
void	        	print_graph(int value);
void	        	scale_bar(node *a);
char	            *ft_itoa(int n);
void                *drawCounter(struct DisplayData *display, int counter);

//unused
void                removingB(SDL_Renderer *renderer, node *tmpb, int barWidth);
void	        	print_stack(node *a, node *b, int argc);
int                 fonter(struct DisplayData *display, char *text, int time);
int                 sortb(node *a, node *b, struct DisplayData *display, int pivot);
int                 numBar(node *a);
int                 average(node *a);