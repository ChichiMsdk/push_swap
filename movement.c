#include "push_swap.h"
//add function movement between bars

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
    node *tmp;
    tmp = a->next;
    if(tmp) {
        while (tmp->next) {
            tmp->scaled = tmp->value;
            tmp->scaled = scale_value(tmp->value, min, max, 1, (WINDOW_WIDTH/2));
            tmp = tmp->next;
        }
        tmp->scaled = tmp->value;
        tmp->scaled = scale_value(tmp->value, min, max, 1, (WINDOW_WIDTH/2));
    }
}

double  smoothstep(double x)
{
    return 3*x*x - 2*x*x*x;
}

int	sdl_start(node *a,node *b, int numBarsB)
{

    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s", SDL_GetError());
        return (0);
    }
    node *tmp;
    if (a->next)
        tmp = a->next;
    while ( tmp->next )
    {
        numBarsA++;
        tmp = tmp->next;
    }
    if (a->next)
        numBarsA++;
    int max_bar_width =5;
    int barWidth = MAX_WINDOW_HEIGHT/(numBarsA*2);
    int window_height = 1000;
    SDL_Window *window = SDL_CreateWindow("Bar Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, window_height, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    color colora;
    a->skin = colora;
    node *tmpb;
    color colorb;
    b->skin = colorb;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *soundEffect = Mix_LoadWAV("C:\\Users\\chiha\\Desktop\\moiquicodedesfonctions\\push_swap\\media\\Pop.mp3");
    Mix_Chunk *sfx = Mix_LoadWAV("C:\\Users\\chiha\\Desktop\\moiquicodedesfonctions\\push_swap\\media\\Cartoon.mp3");
    sfx->volume = 2;
    soundEffect->volume = 5;

    SDL_Event e;
    while(1) {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                Mix_FreeChunk(soundEffect);
                Mix_FreeChunk(sfx);
                return 0;
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                {
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    Mix_FreeChunk(soundEffect);
                    Mix_FreeChunk(sfx);
                    return 0;
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_r)
                {
                    rotate(a);
                    scale_bar(a);
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_s)
                {
                    swap(b);
                    scale_bar(b);
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_e)
                {
                    r_rotate(a);
                    scale_bar(a);
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_p)
                {
                    push(b, a);
                    scale_bar(b);
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_l)
                {
                    push(a, b);
                    scale_bar(a);
                }
            }
        }
        if (attente == 1)
            Mix_PlayChannel(-1, sfx,0);
        if (attente == 2)
            Mix_PlayChannel(-1, soundEffect, 0);
        attente = 0;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);
        int i = 0;
        if (a->next)
            tmp = a->next;
        scale_bar(a);
// rendering stack a on the left
        while (tmp)
        {
            colorGR(tmp);
            SDL_SetRenderDrawColor(renderer, tmp->skin.r, tmp->skin.g, tmp->skin.b, 255);
            SDL_Rect rect = {0, i*2*barWidth, tmp->scaled, barWidth} ;
            SDL_RenderFillRect(renderer, &rect);
//            i=i+barWidth;
            i++;
            tmp = tmp->next;
        }
        if (!b->next)
            goto prout;//im just dumb I guess
        int j = 0;
        tmpb = b->next;
        while (tmpb)
        {
            colorGR(tmpb);
            SDL_SetRenderDrawColor(renderer, tmpb->skin.r, tmpb->skin.g, tmpb->skin.b, 255);
            SDL_Rect rect = {WINDOW_WIDTH - tmpb->scaled, j * 2 * barWidth, tmpb->scaled, barWidth};
            SDL_RenderFillRect(renderer, &rect);
            j++;
            tmpb = tmpb->next;
        }
        prout:
        SDL_RenderPresent(renderer);
    }
}
