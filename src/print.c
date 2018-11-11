/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:21:41 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/11 15:21:43 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		jig(t_game *param)
{
	int heigt;
	int width;

	param->finish_y = -1;
	param->finish_x = -1;
	param->flea = 9999;
	if (!(param->jig = (int **)malloc(sizeof(int *) * (param->coord_y + 1))))
		return (0);
	param->jig[param->coord_y + 1] = NULL;
	heigt = 0;
	while (param->coord_y > heigt)
	{
		width = 0;
		if (!(param->jig[heigt] = (int *)malloc(sizeof(int)
			* (param->coord_x + 1))))
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
	param->loser_coord_y = 0;
	while (param->coord_y > param->loser_coord_y)
	{
		param->loser_coord_x = 0;
		while (param->coord_x > param->loser_coord_x)
		{
			if (param->map[param->loser_coord_y][param->loser_coord_x]
				== param->loser)
				distance(param);
			param->loser_coord_x++;
		}
		param->loser_coord_y++;
	}
	return (1);
}

int		distance(t_game *param)
{
	int		distance;

	param->space_y = 0;
	while (param->coord_y > param->space_y)
	{
		param->space_x = 0;
		while (param->coord_x > param->space_x)
		{
			if (param->map[param->space_y][param->space_x] == param->champ)
				param->jig[param->space_y][param->space_x] = -1;
			else if (param->map[param->space_y][param->space_x] == param->loser)
				param->jig[param->space_y][param->space_x] = -2;
			else
			{
				distance = space_form(param);
				if (param->jig[param->space_y][param->space_x]
					> distance && distance > -1)
					param->jig[param->space_y][param->space_x] = distance;
			}
			param->space_x++;
		}
		param->space_y++;
	}
	return (1);
}

int		space_form(t_game *param)
{
	int		distance;
	int		distance2;

	distance = (param->space_y - param->loser_coord_y);
	if (distance < 0)
		distance *= -1;
	distance2 = (param->space_x - param->loser_coord_x);
	if (distance2 < 0)
		distance2 *= -1;
	return (distance + distance2);
}
