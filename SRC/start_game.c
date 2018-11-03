/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:42:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/14 12:44:49 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					start_game(t_game *param, char *start_row)
{
	init_game_param(param);
	while (get_next_line(0, &start_row) > 0)
	{
		if (param->geimer == 0)
			search_geimer(start_row, param);
		if (!param->width && !param->height)
			search_map(start_row, param);
		else if (param->line >= 0 && param->line < param->height)
			find_place(start_row, param);
		if (param->line >= param->height)
			search_filler(start_row, param);
		else if (param->line >= 0 && param->line < param->coord_y)
			find_place_filler(start_row, param);
		if (param->finish == 1)
			ft_place_map(param);
		ft_strdel(&start_row);
	}
}