
#include "../includes/filler.h"

int		soil(t_game *param)
{
	param->time_y = 0;
	while (param->coord_y - param->field_y + 1 > param->time_y)
	{
		param->time_x = 0;
		while (param->coord_x - param->field_x + 1 > param->time_x)
		{
			if (param_validate(param))
				set_route(param);
			param->time_x++;
		}
		param->time_y++;
	}
	return (1);
}

int		param_validate(t_game *param)
{
	int y;
	int x;
	int flag;

	x = 0;
	flag = 0;
	while (x < param->field_x)
	{
		y = 0;
		while (y < param->field_y)
		{
			if (param->picture[y][x] == '*')
			{
				if (!(flag) && (param->map[y + param->time_y][x + param->time_x]
				 == param->champ))
					flag = 1;
				else if (param->map[param->time_y + y][param->time_x + x] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return ((flag) ? 1 : 0);
}

void	set_route(t_game *param)
{
	int y;
	int x;
	int	opt_turn;

	x = 0;
	opt_turn = 0;
	while (x < param->field_x)
	{
		y = 0;
		while (y < param->field_y)
		{
			if (param->picture[y][x] == '*')
			{
				opt_turn += (param->jig)[y + param->time_y][x + param->time_x];
			}
			y++;
		}
		x++;
	}
	final_solution(param, opt_turn);
}
