
#include "../includes/filler.h"

void		clearing(t_game *param)
{
	int 	h;

	h = -1;
	while (++h < param->field_y)
		free(param->picture[h]);
	free(param->picture);
	h = -1;
	while (++h < param->coord_y)
		free(param->map[h]);
	free(param->map);
	h = -1;
	while (++h < param->coord_y)
		free(param->jig[h]);
	free(param->jig);
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

void		final_solution(t_game *param, int optimal)
{
	if (param->flea > optimal)
	{
		param->finish_Y = param->time_y;
		param->finish_X = param->time_x;
		param->flea = optimal;
	}
}
