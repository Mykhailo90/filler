
#include "../includes/filler.h"

void	clearing(t_game *param)
{
	int h;

	h = 0;
	while (h < param->field_y)
	{
		free(param->picture[h]);
		h++;
	}
	free(param->picture);
	h = 0;
}

void	printing(t_game *param)
{
	ft_putnbr(param->finish_Y);
	write(1, " ", 1);
	ft_putnbr(param->finish_X);
	write(1, "\n", 1);
}

void			init_param(t_game *param)
{
	param->coord_x = 0;
	param->coord_y = 0;
	param->field_y = 0;
	param->field_x = 0;
	param->flea = 0;
	param->finish_Y = 0;
	param->finish_X = 0;
}

void		final_solution(t_game *param, int optimal, int height, int width)
{
	if (param->flea > optimal)
	{
		param->finish_Y = height;
		param->finish_X = width;
		param->flea = optimal;
	}
}
