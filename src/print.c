
#include "../includes/filler.h"

int		jig(t_game *param)
{
	int heigt;
	int width;

	param->finish_Y = -1;
	param->finish_X = -1;
	param->flea = 9999;
	if (!(param->jig = (int **)malloc(sizeof(int *) * (param->coord_y + 1))))
		return (0);
	param->jig[param->coord_y + 1] = NULL;
	heigt = 0;
	while (param->coord_y > heigt)
	{
		width = 0;
		if (!(param->jig[heigt] = (int *)malloc(sizeof(int) * (param->coord_x + 1))))
			return (0);
		param->jig[heigt][param->coord_x + 1] = '\0';
		while (param->coord_x > width)
		{
			param->jig[heigt][width] = 9999;
			width++;
		}
		heigt++;
	}
	return (loser_picture(param));
}

int		loser_picture(t_game *param)
{
	param->loser_coord_Y = 0;
	while (param->coord_y > param->loser_coord_Y)
	{
		param->loser_coord_X = 0;
		while (param->coord_x > param->loser_coord_X)
		{
			if (param->map[param->loser_coord_Y][param->loser_coord_X] == param->loser)
				distance(param);
			param->loser_coord_X++;
		}
		param->loser_coord_Y ++;
	}
	return (1);
}

int		distance(t_game *param)
{
	int		distance;

	param->space_Y = 0;
	while (param->coord_y > param->space_Y)
	{
		param->space_X = 0;
		while (param->coord_x > param->space_X)
		{
			if (param->map[param->space_Y][param->space_X] == param->champ)
				param->jig[param->space_Y][param->space_X] = -1;
			else if (param->map[param->space_Y][param->space_X] == param->loser)
				param->jig[param->space_Y][param->space_X] = -2;
			else
			{
				distance = space_form(param);
				if (param->jig[param->space_Y][param->space_X]
					> distance && distance > -1)
					param->jig[param->space_Y][param->space_X] = distance;
			}
			param->space_X++;
		}
		param->space_Y++;
	}
	return (1);
}

int		space_form(t_game* param)
{
	int		distance;
	int		distance2;

	distance = (param->space_Y - param->loser_coord_Y);
	if (distance < 0)
		distance *= -1;
	distance2 = (param->space_X - param->loser_coord_X);
	if (distance2 < 0)
		distance2 *= -1;
	return (distance + distance2);
}
