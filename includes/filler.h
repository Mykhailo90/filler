
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
void			row_parser(t_game *param);
int				coords_parser(t_game *param);
int				map_parser(t_game *param);
int			parsing_coords_position(t_game *param);
int			create_map(t_game *param);
int				matrix(t_game *param);
int				enemy_figure(t_game *param);
int				distance(t_game *param);
int				dist_forml(t_game *param);
int				territory(t_game *param);
int				valid_check(t_game *param, int w_m, int h_m);
void			determ_course(t_game *param, int h, int w);
int				ft_final_decision(t_game *param, int optimal,
									int h, int w);
void			ft_output(t_game *param);
void			ft_refreshers(t_game *param);
void			init_param(t_game *param);
#endif
