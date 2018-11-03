/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:42:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/14 12:44:49 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					main(void)
{
	t_game	param;
	char	*start_row;

	start_row = NULL;
	start_game(&param, start_row);
	return (0);
}
