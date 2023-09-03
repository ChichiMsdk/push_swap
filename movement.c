#include "push_swap.h"
//add function movement between bars
int time = -1;
int counter;
static int son = 3;
double scale_value(double value, double min_value, double max_value, double chart_min, double chart_max)
{
    if ( max_value == min_value )
    {
        printf("Error\nProbably duplicates\n");
        return(1);
    }

    if ( value == min_value-min_value || (min_value == 0 && max_value == 0) )
    {
        printf("0 was caught\n");
        return(599);
    }

    if ( value == min_value)
        return(10);

    double scaled;
    double range = (int)max_value - min_value;
    //make recursive?
    if ( range <= 10)
        range = 10;
    else if (range <= 100)
        range = 100;
    else if (range <=1000)
        range = 1000;
    else if (range <=10000)
        range = 10000;
    else if (range <=100000)
        range = 100000;

    scaled = (value - min_value) / range * (chart_max - chart_min) + chart_min;
    //scaled = (value - min_value) / (max_value - min_value) * (chart_max - chart_min) + chart_min;
    return (scaled);
}

void	scale_bar(node *a)
{
    if (a->next )
    {
        node *tmp;
        tmp = a->next;
        if (tmp && tmp->next)
        {
            while (tmp->next)
            {
                tmp->scaled = tmp->value;
                tmp->scaled = scale_value(tmp->value, min, max, 1, (WINDOW_WIDTH / 2));
                tmp = tmp->next;
            }
        }
            tmp->scaled = tmp->value;
            tmp->scaled = scale_value(tmp->value, min, max, 1, (WINDOW_WIDTH / 2));
    }
}

double  smoothstep(double x)
{
    return 3*x*x - 2*x*x*x;
}

void	window_quit(struct DisplayData *display)
{
	if (display->e.type == SDL_QUIT)
	{
		SDL_DestroyRenderer(display->renderer);
        SDL_DestroyWindow(display->window);
        TTF_CloseFont(display->font);
	}
}

int	event_kb(struct DisplayData *display)
{
	if (display->e.type == SDL_QUIT)
	{
	  	window_quit(display);
	    return 0;
	}
	if (display->e.type == SDL_KEYDOWN)
	{
        switch(display->e.key.keysym.sym)
		{
            case SDLK_s:
                 //iwww=100;
                 //sfx(3, display->soundfx);
                 swap(display->a, display);
                break;
            case SDLK_w:
                rotate(display->a, display);
                break;
            case SDLK_e:
                r_rotate(display->a, display);
                break;
            case SDLK_r:
                push(display->b,display->a, display);
                //updater(display);
                break;
            case SDLK_5:
                sfx(3, display->soundfx);
                son--;
            case SDLK_t:
                //son++;
                sort(display);
                updater(display);
                break;
            case SDLK_o:
                rotate(display->b, display);
                break;
            case SDLK_i:
                r_rotate(display->b, display);
                break;
            case SDLK_u:
                push(display->a, display->b,display);
                //updater(display);
                break;
            case SDLK_l:
                swap(display->b, display);
                break;
            case SDLK_ESCAPE:
                window_quit(display);
                return 0;
//	        case SDLK_d:
//                x = 1000;
//                while (x >0)
//                {
//                    x--;
//                    rotate(display->a, display);
//                }
//                 break;
			case SDLK_a:
				reset(display);
                time = 100;
                fill_node_a(display);
                update_display(display);
				break;
	        }
	}	
	return 1;
}

int fonter(struct DisplayData *display, char *text, int time)
{
    if (time > 0)
    {
        SDL_Color textColor = { 255, 0, 0, 255 };
        SDL_Surface *textSurface = TTF_RenderText_Blended(display->font, text, textColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(display->renderer, textSurface);
        SDL_Rect textLocation = {250, 400 , textSurface->w, textSurface->h};
        //background rectangle for the text;
        SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(display->renderer, &textLocation);
        SDL_RenderCopy(display->renderer, textTexture, NULL, &textLocation);
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);
    }

    else {
        iwww = 0;
    }
	return (0);
}

int sfx(int play, Mix_Chunk *soundfx)
{
    soundfx->volume = son;
    Mix_PlayChannel(-1, soundfx, 0);
    return(1);
}
int    updater(struct DisplayData *display)
{
    int i = 1;
    while (i > 0)
    {
        SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(display->renderer);
//        if (attente == -1)
//            Mix_PlayChannel(-1, soundfx,0);
//        if (attente == -1)
//            Mix_PlayChannel(-1, soundEffect, 0);
//        attente = 0;
        scale_bar(display->a);
        scale_bar(display->b);
        drawing(display);
        drawingB(display);
        drawCounter(display, counter);
        //fonter(display, "ERROR, illegal move", 0);
        SDL_RenderPresent(display->renderer);
        //iwww--;
        i--;
    }
    return(1);
}

int    update_display(struct DisplayData *display)
{
    while(1) {
        SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(display->renderer);
        {
            while (SDL_PollEvent(&display->e)) {
                int error;
                error = event_kb(display);
                if (error == 0)
                    return (0);
            }
        }
        scale_bar(display->a);
        scale_bar(display->b);
        drawing(display);
        drawingB(display);
        drawCounter(display, counter);
 //       fonter(display, "ERROR, illegal move", 0);
        SDL_RenderPresent(display->renderer);
        iwww--;
    }
}

int	sdl_start(struct DisplayData *display)
{
    display->max = find_max(display->a);
    display->min = find_min(display->a);
    display->soundfx = Mix_LoadWAV("media/Pop.mp3");
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s", SDL_GetError());
        return (0);
    }
    countBars(display->a);
    countBars(display->b);
    display->barWidth = MAX_WINDOW_HEIGHT/(numBarsA*2);
    int window_height = 1000;
    display->window = SDL_CreateWindow("Bar Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, window_height, 0);
//    display->renderer = SDL_CreateRenderer(display->window, -1, SDL_RENDERER_ACCELERATED  );
    display->renderer = SDL_CreateRenderer(display->window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    TTF_Init();
    if (TTF_Init() == -1)
        return 0;
    display->font = TTF_OpenFont ("media/fonts/JetBrainsMono.ttf", 64);
    if (display->font == NULL)
        return 0;
    color colora;
    display->a->skin = colora;
    color colorb;
    display->b->skin = colorb;
    int error;
    error = update_display(display);
    if (error == 0)
        return(0);
   return (-1);
}
