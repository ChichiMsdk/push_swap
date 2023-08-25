#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long int		result;
	long int		tmp;

	int thereIsInt = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{	
		thereIsInt = 1;
		tmp = result;
		result = (result * 10) + (*str - 48);
		str++;
		if (result < tmp && sign == 1)
			return (-1);
		if (result < tmp && sign == -1)
			return (0);
	}
	if (thereIsInt == 0)
		return (-1);
	return ((int)result * sign);
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

void * add_node(node *a , int value, int head)
{
	node	*new_node;
	new_node = malloc(sizeof(node));
    if (!new_node)
        return (NULL);
	new_node->value = value;
    new_node->progress = 0;
    if(!a)
        return(a);

	if (a->next == NULL)
	{
		a->next = new_node;
		new_node->prev = a;
        new_node->next = NULL;
        attente = 1;
        return(new_node);
	}
	if (!head)
	{
		node *tmp;
		tmp = a->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = NULL;
	}
	else {
        node *tmp;
        tmp = a->next;
        a->next = new_node;
        new_node->next = tmp;
        new_node->prev = a;
        attente= 1;
    }
    return(new_node);
}

void	swap(node *a)
{
	if (!a->next || !a->next->next)
	{
		printf("Error\n");
	}
	else if (a->next && a->next->next)
	{
		int tmp;
		tmp = a->next->value;
		a->next->value = a->next->next->value;
		a->next->next->value = tmp;
        attente=2;
	}
}

void	r_rotate(node *reverse)
{
	if (!reverse->next || !reverse->next->next || !reverse->next->next->next )
	{
		printf("Error\n");
	}
	else
	{
		node *current;
		int first;

		current = reverse->next;
		first = current->value;
		while ( current->next )
		{
			current->value = current->next->value;
            current->progressi = 0.01;
            current = current->next;
		}
		current->value = first;
        current->progressi = 0.01;
	}
}

void	rotate(node *rotate)
{	
	if (!rotate->next || !rotate->next->next  || !rotate->next->next->next )
	{
		printf("Error\n");
	}
	else 
	{
		node *current;
		int last;

		current = rotate->next;
		current->prev = NULL;
		while ( current->next )
		{
			current->next->prev = current;
			current = current->next;
		}
		last = current->value;
		while (current->prev != NULL)
		{
            current->progressi = 0.01;
			current->value = current->prev->value;
			current = current->prev;
		}
        current->progressi = 0.01;
		current->value = last;
        attente=2;
		}
}

void	remove_node(node *remove)
{
    if ( remove == NULL || remove->prev != NULL )
    {
        printf("Error\n");
	}
    else if (!remove->next->next)
    {
        free(remove->next);
        remove->next = NULL;
    }

    else
	{
		node *tmp;
		tmp = remove->next;
		remove->next = remove->next->next;
		remove->next->prev = remove;
		free(tmp);
		tmp = NULL;
	}
}

void	push(node *dest, node *src)
{
	if (!src->next)
    {
		printf("Error\n");
    }
    if ( src->next)
    {
        add_node(dest, src->next->value, 1);
        remove_node(src);
    }
}

void	s_swap(node *a, node *b)
{
	swap(a);
	swap(b);
}

void	s_rot(node *a, node *b)
{
	rotate(a);
	rotate(b);
}

void	s_rev(node *a, node *b)
{
	r_rotate(a);
	r_rotate(b);
}

void    drawing(SDL_Renderer *renderer, node *tmp,node *a, int barWidth)
{
    if (a->next) {
        tmp = a->next;
        int i = 0;
        while (i < numBarsA && tmp) {
            if ( tmp->progress < 1)
            {
                if (tmp->progress < 0.7)
                    tmp->progress += 0.03;
                if (tmp->progress >= 0.7)
                    tmp->progress += 0.01;
                if (tmp->progress >= 1)
                    tmp->progress = 1;
                tmp->scaled = lerp(tmp->start_scaled, tmp->scaled, tmp->progress);
            }
            colorGR(tmp);
            SDL_SetRenderDrawColor(renderer, tmp->skin.r, tmp->skin.g, tmp->skin.b, 255);
            SDL_Rect rect = {0, i * 2 * barWidth, tmp->scaled, barWidth};
            SDL_RenderFillRect(renderer, &rect);
            i++;
            tmp = tmp->next;
        }
    }
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
void    drawingB(SDL_Renderer *renderer, node *tmpb, node *b, int barWidth)
{
    countBars(b);
    if (b->next)
    {
        tmpb= b->next;
        int i = 0;
        while (tmpb && i < numBarsB)
        {
            if ( tmpb->progress < 1)
            {
                if (tmpb->progress < 0.7)
                    tmpb->progress += 0.03;
                if (tmpb->progress >= 0.7)
                    tmpb->progress += 0.01;
                if (tmpb->progress >= 1)
                    tmpb->progress = 1;
                tmpb->scaled = lerp(tmpb->start_scaled, tmpb->scaled, tmpb->progress);
            }
            colorGR(tmpb);
            SDL_SetRenderDrawColor(renderer, tmpb->skin.r, tmpb->skin.g, tmpb->skin.b, 255);
            SDL_Rect rect = {WINDOW_WIDTH - tmpb->scaled, i * 2 * barWidth, tmpb->scaled, barWidth};
            SDL_RenderFillRect(renderer, &rect);
            i++;
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

double	find_min(node *a)
{
    node *tmp;
    tmp = a->next;
    min = tmp->value;
    while (tmp->next)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    tmp->value < min ? min = tmp->value : 0;
    return (min);
}

double	find_max(node *a)
{
    if (!a){
        printf("Error finding max NULL\n");
        exit(1);
    }
    node *tmp;
    tmp = a->next;
    max = tmp->value;
    while (tmp->next)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    tmp->value > max ? max = tmp->value : 0;
    return (max);
}

node*	init_new_node(int name)
{
    node *new;
    new = malloc(sizeof(node));
    if (!new)
        return(NULL);
    new->prev = NULL;
    new->progress = 0;
    new->progressi = 0.01;
    new->next = NULL;
    new->delay = 0;
    new->name = name;
    new->start_scaled = 0;
    return (new);
}

void	fill_node_a(int argc, node *a, char **argv, int emergency[])
{
    int i;
    int j;

    i = 0;
    j = 1;
    if (argc <= 1)
    {
        while ( i < 500)
        {
            add_node(a, emergency[i] , 0);
            i++;
        }
    }
    while ( i < argc-1 && j < argc )
    {
        if (ft_atoi(argv[j])== -1)
        {
            printf("Error\n");
            exit(1);
        }
        add_node(a, ft_atoi(argv[j]), 0);
        i++;
        j++;
    }
}
