
#include "../includes/filler.h"

int		matrix(t_game *param)
{
	int heig;
	int wid;

	if (!(param->matrix = (int **)malloc(sizeof(int *) * (param->map_y + 1))))
		return (0);
	param->matrix[param->map_y + 1] = NULL;
	param->end_y = -1;
	param->end_x = -1;
	param->mites = 9999;
	heig = 0;
	while (param->map_y > heig)
	{
		wid = 0;
		if (!(param->matrix[heig] = (int *)malloc(sizeof(int) * (param->map_x + 1))))
			return (0);
		param->matrix[heig][param->map_x + 1] = '\0';
		while (param->map_x > wid)
		{
			param->matrix[heig][wid] = 9999;
			wid++;
		}
		heig++;
	}
	enemy_figure(param);
	return (1);
}

int		enemy_figure(t_game *param)
{
	param->en_f_y = 0;
	while (param->map_y > param->en_f_y)
	{
		param->en_f_x = 0;
		while (param->map_x > param->en_f_x)
		{
			if (param->map[param->en_f_y][param->en_f_x] == param->bot_enemy)
				distance(param);
			param->en_f_x++;
		}
		param->en_f_y ++;
	}
	return (1);
}

int		distance(t_game *param)
{
	int		distance;

	param->dis_y = 0;
	while (param->map_y > param->dis_y)
	{
		param->dis_x = 0;
		while (param->map_x > param->dis_x)
		{
			if (param->map[param->dis_y][param->dis_x] == param->my_bot)
				param->matrix[param->dis_y][param->dis_x] = -1;
			else if (param->map[param->dis_y][param->dis_x] == param->bot_enemy)
				param->matrix[param->dis_y][param->dis_x] = -2;
			else
			{
				distance = dist_forml(param);
				if (param->matrix[param->dis_y][param->dis_x]
					> distance && distance > -1)
					param->matrix[param->dis_y][param->dis_x] = distance;
			}
			param->dis_x++;
		}
		param->dis_y++;
	}
	return (1);
}

int		dist_forml(t_game* param)
{
	int		distance;
	int		distance2;

	distance = (param->dis_y - param->en_f_y);
	if (distance < 0)
		distance *= -1;
	distance2 = (param->dis_x - param->en_f_x);
	if (distance2 < 0)
		distance2 *= -1;
	return (distance + distance2);
}
