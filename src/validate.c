
#include "../includes/filler.h"

int		soil(t_game *param)
{
	int		y;
	int		x;

	y = 0;
	while (param->coord_y - param->field_y + 1 > y)
	{
		x = 0;
		while (param->coord_x - param->field_x + 1 > x)
		{
			if (param_validate(param, y, x))
				set_route(param, y, x);
			x++;
		}
		y++;
	}
	return (1);
}

int		param_validate(t_game *param, int ter_y, int ter_x)
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
				if (!(flag) && (param->map[y + ter_y][x + ter_x] == param->champ))
				{
					flag = 1;
				}
				else if (param->map[ter_y + y][ter_x + x] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return ((flag) ? 1 : 0);
}

void	set_route(t_game *param, int height, int width)
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
				opt_turn += (param->jig)[y + height][x + width];
			}
			y++;
		}
		x++;
	}
	final_solution(param, opt_turn, height, width);
}
