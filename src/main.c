/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <msarapii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:22:06 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/11 15:35:01 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	processing(t_game *param)
{
	jig(param);
	soil(param);
	printing(param);
	clearing(param);
}

int		main(void)
{
	t_game param;

	init_param(&param);
	row_parsing(&param);
	processing(&param);
	while (1)
	{
		if (coords_parsing(&param))
			processing(&param);
		else
		{
			return (0);
		}
	}
	return (0);
}
