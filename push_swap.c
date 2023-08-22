#include "push_swap.h"

node*	init_new_node(char *name)
{
	node *new;
	new = malloc(sizeof(node));
	new->prev = NULL;
	new->name = name;
	return (new);
}

void	fill_node_a(int argc, node *a, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 1;
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

double	find_max(node *a)
{
	double max;
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

double	find_min(node *a)
{
	double min;
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

double scale_value(double value, double min_value, double max_value, double chart_min, double chart_max)
{
	if ( max_value == min_value )
	{
		printf("Error\nProbably duplicates\n");
		return(1);
	}
	if ( value == min_value )
	{
		return (1);
	}
	if ( value == min_value-min_value || (min_value == 0 && max_value == 0) )
	{
		printf("0 was caught\n");
		return(599);
	}
	double scaled = (value - min_value) / (max_value - min_value) * (chart_max - chart_min) + chart_min;
    return (scaled);
}

void	scale_bar(node *a, double min, double max)
{
	node *tmp;
	tmp = a->next;
	printf("hello ? %d\n", tmp->value);
	while ( tmp->next )
	{
		tmp->scaled = tmp->value;
		tmp->scaled = scale_value(tmp->value, min, max, 1, 500);
		tmp = tmp->next;
	}
	tmp->scaled = tmp->value;
	tmp->scaled = scale_value(tmp->value, min, max, 1, 500);
}

int	sdl_start(int max, int min, node *tmp, node *a, int numBars)
{
	tmp = a->next;
	while ( tmp->next )
	{
		numBars++;
		tmp = tmp->next;
	}
	numBars++;

	SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Bar Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    int barWidth = WINDOW_WIDTH / (numBars * 2);
	scale_bar(a, min, max);
    while (1) 
	{	//switch case would be better here
    	SDL_Event e;
    	while (SDL_PollEvent(&e)) 
		{
        	if (e.type == SDL_QUIT) 
			{
            	SDL_DestroyRenderer(renderer);
            	SDL_DestroyWindow(window);
            	SDL_Quit();
            	return 0;
        	}
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					SDL_DestroyRenderer(renderer);
        			SDL_DestroyWindow(window);
        			SDL_Quit();
        			return 0;
				}
			}
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_r)
				{
					rotate(a);
					scale_bar(a, min, max);
				}
			}	
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_s)
				{
					swap(a);
					scale_bar(a, min, max);
				}
			}
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_e)
				{
					r_rotate(a);
					scale_bar(a, min, max);
				}
			}
    	}
		color color;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    	SDL_RenderClear(renderer);
		int i = 0;
		tmp = a->next;
		node *colors;
		colors = a->next;
		color.r = (max-10)*0.3/max*250;
		color.g = (min + 20)*0.2/max*250;
		color.b = max/2*max*250;
    	while (i < numBars) 
		{
			SDL_SetRenderDrawColor(renderer, color.r*i*0.4, color.g*i*0.1, color.b, 255);
			//SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    		SDL_Rect rect = {i * 2 * barWidth, WINDOW_HEIGHT - tmp->scaled, barWidth, tmp->scaled};
    		SDL_RenderFillRect(renderer, &rect);
			i++;
			tmp = tmp->next;
		}

		SDL_RenderPresent(renderer);
	}

}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Error\n");
		exit(1);
	}
	double max;
	double min;
	int error;
	int numBars = 0;
	node *tmp;

	node *a = init_new_node("a");
	node *b = init_new_node("b");
	fill_node_a(argc, a, argv);
//	print_stack(a, b, argc);
	min = find_min(a);
	max = find_max(a);

	error =	sdl_start(max, min, tmp, a , numBars);
	if ( error == 0 )
		return(0);
		
//	char input;
//
//	int i;
//	while (1)
//	{
//		input = getchar();
//		i = 0;
//		switch(input)
//		{
//			case 'k':
//				s_rev(a, b);
//				print_stack(a, b, argc);
//				break;
//			case 'm':
//				s_rot(a, b);
//				print_stack(a, b, argc);
//				break;
//			case 'o':
//				r_rotate(a);
//				print_stack(a, b, argc);
//				break;
//			case 'b':
//				push(a, b);
//				print_stack(a, b, argc);
//				break;
//			case 'a':
//				push(b, a);
//				print_stack(a,b,argc);
//				break;
//			case 't':
//				rotate(b);
//				print_stack(a, b, argc);
//				break;
//			case 'r':
//				rotate(a);
//				print_stack(a,b, argc);
//				break;
//			case 'f':
//				swap(b);
//				print_stack(a,b, argc);
//				break;
//			case 's':
//				swap(a);
//				print_stack(a,b, argc);
//				break;
//			case 'p':
//				printf("=============\nSTOPPING....\n=============\n");
//				return(0);
//			default:
//				printf("Invalid input\n---------\n");
//				break;
//		}
//		while (getchar() != '\n');
//	}
	return (0);
}
