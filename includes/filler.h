/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:56:17 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/11 15:11:14 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_game
{
	int			coord_y;
	int			coord_x;
	int			field_y;
	int			field_x;
	int			flea;
	int			finish_y;
	int			finish_x;
	char		champ;
	char		loser;
	char		*line;
	int			**jig;
	char		**picture;
	char		**map;
	int			loser_coord_y;
	int			loser_coord_x;
	int			space_y;
	int			space_x;
	int			time_x;
	int			time_y;
}				t_game;

int				coords_parsing(t_game *param);
void			clearing(t_game *param);
int				distance(t_game *param);
int				field_fix(t_game *param);
void			final_solution(t_game *param, int optimal);
int				jig(t_game *param);
void			init_param(t_game *param);
int				loser_picture(t_game *param);
int				main(void);
int				param_validate(t_game *param);
int				pars_picture_coords(t_game *param);
void			processing(t_game *param);
int				row_parsing(t_game *param);
void			printing(t_game *param);
void			set_route(t_game *param);
int				soil(t_game *param);
int				space_form(t_game *param);
#endif
