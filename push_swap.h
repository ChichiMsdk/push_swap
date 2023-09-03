#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <SDL2/SDL.h>
# include "x86_64-w64-mingw32/include/SDL2/SDL.h"
//# include <SDL2/SDL_mixer.h>
//# include <SDL2/SDL_ttf.h>
# include "sdl_mixer/include/SDL2/SDL_mixer.h"
# include "SDL2_ttf\include\SDL2\SDL_ttf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
//# include "/opt/homebrew/Cellar/sdl2/2.28.2/include/SDL2/SDL.h" //mac
//# include "SDL2/SLD.h"
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
extern int iwww;
extern int counter;
typedef	struct color {
			int r;
			int g;
			int b;
}color;

typedef struct DisplayData {
    SDL_Event e;
    int max;
    int min;
    struct node *a;
    struct node *b;
    TTF_Font *font;
    struct node *tmp;
    struct node *tmpb;
    SDL_Renderer *renderer;
    int barWidth;
    int argc;
    char **argv;
    Mix_Chunk *soundfx;
    SDL_Window *window;
    int emergency[500];
} DisplayData;

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

int         duplicate(node *a);
int         sortb(node *a, node *b, struct DisplayData *display, int pivot);
int         numBar(node *a);
int         average(node *a);
int         updater(struct DisplayData *display);
int         update_display(struct DisplayData *display);
int         sort(node *a, node *b, struct DisplayData *display, int pivot);
void		reset(struct DisplayData *display);
int         sfx(int play, Mix_Chunk *soundfx);
int         fonter(struct DisplayData *display, char *text, int time);
void        countBars(node *count);
double      lerp(double a, double b, double f);
void        drawing(struct DisplayData *display);
void        drawingB(struct DisplayData *display);
double      smoothstep(double x);
int         sdl_start(struct DisplayData *display);
void        colorGR(node *tmp);
int			ft_atoi(const char *str);
int			ft_isspace(char c);
void        *add_node(node *a, int value, int head);
void		remove_node(node *remove);
void		swap(node *a,  struct DisplayData *display);
void		push(node *dest, node *src, struct DisplayData *display);
void		rotate(node *rotate, struct DisplayData *display);
void		r_rotate(node *reverse, struct DisplayData *display);
void		s_swap(node *a, node *b,  struct DisplayData *display);
void		s_rot(node *a, node *b,  struct DisplayData *display);
void		s_rev(node *a, node *b,  struct DisplayData *display);
void		print_stack(node *a, node *b, int argc);
void		print_graph(int value);
void		scale_bar(node *a);
node	    *init_new_node(int name);
void        removingB(SDL_Renderer *renderer, node *tmpb, int barWidth);
void	    fill_node_a(struct DisplayData *display);
double	    find_max(node *a);
double	    find_min(node *a);
char	    *ft_itoa(int n);
void        *drawCounter(struct DisplayData *display, int counter);
//fail
//
