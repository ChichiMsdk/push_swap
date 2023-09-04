#include "push_swap.h"

void	print_stack(node *a,node *b, int argc)
{
	int i = 0;
	node *u;
	node *ub;
	ub = b->next;
	u = a->next;
	while(i < argc-1)
	{	
		if (u)
		{
//			printf("\n[%d]^       ", u->value);
			print_graph(u->value);
			u = u->next;
		}
	//	if (u) 
	//	{
	//		printf("\n[%d]       ", u->value);
	//		print_graph(u->value);
    //        u = u->next;
	//	}
//		else
//		{
//			printf("          ");
//		}
		//if (ub)
		//{
		//	printf("[%d]\n", ub->value);
		//	print_graph(u->value);
		//	ub = ub->next;
		//}
		//else
		//{
		//	printf("\n");
		//}
		i++;
	}
	//printf("============\n");
	//printf("a          b\n");

}

void	print_graph(int value)
{
	int i = 0;
	while (i < value )
	{
		printf("-");
		i++;
	}
	printf("\n");
}

void	reset(struct DisplayData *display)
{
    //if (!display->a->next && !display->b->next)
     //   iwww = 100; errors????
    if (display->a && display->a->next)
    {
        node *tmp;
        if (display->a->next) {
            tmp = display->a->next;
            while (tmp->next && display->a) {
                tmp = tmp->next;
                free(tmp->prev);
                tmp->prev = NULL;
            }
            display->a->next = NULL;
            free(tmp);
            tmp = NULL;
        }
    }
    if (display->b && display->b->next)
    {
        node *tmp;
        if (display->b->next) {
            tmp = display->b->next;
            while (display->b && tmp->next) {
                tmp = tmp->next;
                free(tmp->prev);
                tmp->prev = NULL;
            }
            display->b->next = NULL;
            free(tmp);
            tmp = NULL;
        }
    }
    counter = 0;
}

void    colorGR(node *tmp)
{
    double t = (double)(tmp->value)/(max-min);
    if (t <= 0.5 )
    {
        tmp->skin.r = 255;
    }
    else
    {
        tmp->skin.r = 255*(1.0 - smoothstep(2.0*(t-0.5)));
    }
    if (t<=0.5)
        tmp->skin.g = 255 * smoothstep(2.0*t);
    else
        tmp->skin.g= 255;
    tmp->skin.b = 0;
}

static char	*ft_char(char *s, unsigned int number, long int len)
{
    while (number > 0)
    {
        s[len--] = 48 + (number % 10);
        number = number / 10;
    }
    return (s);
}

static long int	ft_len(int n)
{
    int	len;

    len = 0;
    if (n <= 0)
        len = 1;
    while (n != 0)
    {
        len++;
        n = n / 10;
    }
    return (len);
}

char	*ft_itoa(int n)
{
    char				*s;
    long int			len;
    unsigned int		number;
    int					sign;

    sign = 1;
    len = ft_len(n);
    s = (char *)malloc(sizeof(char) * (len + 1));
    if (!(s))
        return (NULL);
    s[len--] = '\0';
    if (n == 0)
        s[0] = '0';
    if (n < 0)
    {
        sign *= -1;
        number = n * -1;
        s[0] = '-';
    }
    else
        number = n;
    s = ft_char(s, number, len);
    return (s);
}



void    removingB(SDL_Renderer *renderer, node *tmpb, int barWidth)
{
    int i = 10;
    while (tmpb->progress>0)
    {

        if (tmpb->progress > 0.7)
            tmpb->progress -= 0.03;
        if (tmpb->progress <= 0.7)
            tmpb->progress -= 0.01;
        if (tmpb->progress <= 0)
            tmpb->progress = 0;
        tmpb->scaled = lerp(0, tmpb->scaled, tmpb->progress);

        colorGR(tmpb);
        SDL_SetRenderDrawColor(renderer, tmpb->skin.r, tmpb->skin.g, tmpb->skin.b, 255);
        SDL_Rect rect = {WINDOW_WIDTH - tmpb->scaled, 0 * 2 * barWidth, tmpb->scaled, barWidth};
        SDL_RenderFillRect(renderer, &rect);
    }
}

//draw the count of operations on the screen

void	*drawCounter(struct DisplayData *display, int counter)
{
    SDL_Color color = {255, 255, 255, 255};
    char *str_count = ft_itoa(counter);
    if (!str_count)
    {
        return (NULL);
    }
    if (display->font && display->renderer)
    {
        SDL_Surface *surface = TTF_RenderText_Solid(display->font,str_count, color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(display->renderer, surface);
        SDL_Rect rect = {WINDOW_WIDTH - 100, 900, 100, 100};
        SDL_RenderCopy(display->renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
    free (str_count);
}

void    drawing(struct DisplayData *display)
{
    if (display->a->next) {
        node *tmp;
        tmp = display->a->next;
        int i = 0;
        while (i < numBarsA && tmp) {
//            if (tmp->progress < 1)
//            {
//                if (tmp->progress < 0.7)
//                    tmp->progress += 0.03;
//                if (tmp->progress >= 0.7)
//                    tmp->progress += 0.01;
//                if (tmp->progress >= 1)
//                    tmp->progress = 1;
//                tmp->scaled = lerp(tmp->start_scaled, tmp->scaled, tmp->progress);
//            }
        colorGR(tmp);
        SDL_SetRenderDrawColor(display->renderer, tmp->skin.r, tmp->skin.g, tmp->skin.b, 255);
        SDL_Rect rect = {0, i * 2 * display->barWidth, tmp->scaled, display->barWidth};
        SDL_RenderFillRect(display->renderer, &rect);
        i++;
        tmp = tmp->next;
    }
}
}

void    drawingB(struct DisplayData *display)
{
    countBars(display->b);
    if (display->b->next)
    {
        node *tmpb;
        tmpb = display->b->next;
        int i = 0;
        while (tmpb && i < numBarsB)
        {
//            if (tmpb->progress < 1)
//            {
//                if (tmpb->progress < 0.7)
//                    tmpb->progress += 0.03;
//                if (tmpb->progress >= 0.7)
//                    tmpb->progress += 0.01;
//                if (tmpb->progress >= 1)
//                    tmpb->progress = 1;
//                tmpb->scaled = lerp(tmpb->start_scaled, tmpb->scaled, tmpb->progress);
//            }
            colorGR(tmpb);
            SDL_SetRenderDrawColor(display->renderer, tmpb->skin.r, tmpb->skin.g, tmpb->skin.b, 255);
            SDL_Rect rect = {WINDOW_WIDTH - tmpb->scaled, i * 2 * display->barWidth, tmpb->scaled, display->barWidth};
            SDL_RenderFillRect(display->renderer, &rect);
            i++;
            int s = 0;
            tmpb = tmpb->next;
        }
    }
}

double   lerp(double a, double b, double f)
{
    return (a + f * (b - a));
}

void    countBars(node *count)
{
    node *tmp;
    if (count && count->next)
    {
        tmp = count->next;
        while(tmp->next) {
            if(count->name == 1)
                numBarsA++;
            if (count->name == 2 )
                numBarsB++;
            tmp = tmp->next;
        }
        if(count->name == 1)
            numBarsA++;
        if (count->name == 2 )
            numBarsB++;
    }
}

void    caller(int prout)
{
    if (prout == 1)
        exit(1);
}

int average(node *a)
{
    if (a->next)
    {
        node *tmp;
        int count;
        int average;

        count = 1;
        average = 0;
        tmp = a->next;
        if (tmp && !tmp->next)
        {
            average += tmp->value;
            return(average);
        }
        while ( tmp && tmp->next )
        {
            average = average + tmp->value;
            count++;
            tmp = tmp->next;
        }
        average += tmp->value;
        if (count == 0)
            return (-1);
        return (average/count);
    }
    return (-1);
}