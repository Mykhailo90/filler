/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:11:36 by msarapii          #+#    #+#             */
/*   Updated: 2018/11/10 15:11:37 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"

typedef struct	s_game
{
	int			coord_x;          // coord_x			x
	int			coord_y;			// coord_y			y
	int			width;			// width			w
	int			height;			// height			h
	int			line;		// line				row
	int			finish;		// finish			done
	int			stage_x;		// stage_x			save_x
	int			stage_y;		// stage_y			save_y
	int			filler_x;	// filler_x			tetri_x
	int			filler_y;	// filler_y			tetri_y
	int			friend_x;	// friend_x			enemy_x
	int			friend_y;	// friend_y			enemy_y
	char		geimer;		// geimer			player
	char		friend;		// friend			enemy
	char		**map;
	char		**filler;	//filler			**tetri
	int			timeVar;	//my_variable******
	char		*help;		//my_variable******
}				t_game;

void			start_game(t_game *param, char *start_row);
void			init_game_param(t_game *param);
void			search_geimer(char *start_row, t_game *param);

#endif
