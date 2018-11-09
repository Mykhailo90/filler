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
#include <stdio.h>

typedef struct	s_game
{
	int			fd;
	int			map_y;
	int			map_x;
	int			pic_y;
	int			pic_x;
	int			mites;
	int			end_y;
	int			end_x;
	char		my_bot;
	char		bot_enemy;
	char		*line;
	int			**matrix;
	char		**figure;
	char		**map;
/*
** --------------------------iterator in enemy_figure--------------------
*/
	int			en_f_y;
	int			en_f_x;
/*
** --------------------------iterator in distance --------------------
*/
	int			dis_y;
	int			dis_x;
}				t_game;

int				main(void);
void			pars_line(t_game *inf);
int				pars_map_xy(t_game *inf);
int				save_map(t_game *inf);
int				pars_figure_xy(t_game *inf);
int				pars_figure(t_game *inf);
int				matrix(t_game *inf);
int				enemy_figure(t_game *inf);
int				distance(t_game *inf);
int				dist_forml(t_game *inf);
int				territory(t_game *inf);
int				valid_check(t_game *inf, int w_m, int h_m);
void			determ_course(t_game *inf, int h, int w);
int				ft_final_decision(t_game *inf, int optimal, int h, int w);
void			ft_output(t_game *inf);
void			ft_refreshers(t_game *inf);
void			zero_out(t_game *inf);
#endif
