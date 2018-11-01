/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_geimer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:42:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/10 12:44:49 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					search_geimer(char *start_row, t_game *param)
{
	if (start_row[10] == '1')
	{
		param->geimer = 'O';
		param->friend = 'X';
	}
	else if (start_row[10] == '2')
	{
		param->geimer = 'X';
		param->friend = 'O';
	}
}