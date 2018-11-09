
#include "../includes/filler.h"

int		territory(t_game *param)
{
	int		y;
	int		x;

	y = 0;
	while (param->map_y - param->pic_y + 1 > y)
	{
		x = 0;
		while (param->map_x - param->pic_x + 1 > x)
		{
			if (valid_check(param, y, x))
				determ_course(param, y, x);
			x++;
		}
		y++;
	}
	return (1);
}

int		valid_check(t_game *param, int ter_y, int ter_x)
{
	int y;
	int x;
	int val_fig;

	x = 0;
	val_fig = 0;
	while (x < param->pic_x)
	{
		y = 0;
		while (y < param->pic_y)
		{
			if (param->figure[y][x] == '*')
			{
				if (!(val_fig) && (param->map[y + ter_y][x + ter_x] == param->my_bot))
				{
					val_fig = 1;
				}
				else if (param->map[ter_y + y][ter_x + x] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return ((val_fig) ? 1 : 0);
}

void	determ_course(t_game *param, int h, int w)
{
	int dc_y;
	int dc_x;
	int	opt_turn;

	dc_x = 0;
	opt_turn = 0;
	while (dc_x < param->pic_x)
	{
		dc_y = 0;
		while (dc_y < param->pic_y)
		{
			if (param->figure[dc_y][dc_x] == '*')
			{
				opt_turn += (param->matrix)[dc_y + h][dc_x + w];
			}
			dc_y++;
		}
		dc_x++;
	}
	ft_final_decision(param, opt_turn, h, w);
}

int		ft_final_decision(t_game *param, int optimal, int h, int w)
{
	if (param->mites > optimal)
	{
		param->end_y = h;
		param->end_x = w;
		param->mites = optimal;
	}
	return (1);
}

void	ft_output(t_game *param)
{
	ft_putnbr(param->end_y);
	write(1, " ", 1);
	ft_putnbr(param->end_x);
	write(1, "\n", 1);
}
