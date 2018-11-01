/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:42:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/14 17:44:49 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void            init_game_param(t_game *param){
    param->coord_x = 0;
	param->coord_y = 0;
	param->width = 0;
	param->height = 0;
	param->line = -1;
	param->finish = 0;
	param->stage_x = 0;
	param->stage_y = 0;
	param->filler_x = -1;
	param->filler_y = -1;
	param->friend_x = 0;
	param->friend_y = 0;
	param->geimer = 0;
	param->friend = 0;
    param->timeVar = 0;
	param->map = NULL;
	param->filler = NULL;
    param->help = NULL;
}