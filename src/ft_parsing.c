
#include "../includes/filler.h"

void			zero_out(t_game *param)
{
	param->map_x = 0;
	param->map_y = 0;
	param->pic_y = 0;
	param->pic_x = 0;
	param->mites = 0;
	param->end_y = 0;
	param->end_x = 0;
}

void	pars_line(t_game *param)
{
	//	param->fd = open("test", O_RDONLY);
	if (get_next_line(0, &(param->line)) > 0)
	{
		if (*(param->line + 10) == '1')
			param->my_bot = 'O';
		else
			param->my_bot = 'X';
		if (param->my_bot == 'O')
			param->bot_enemy = 'X';
		else
			param->bot_enemy = 'O';
	}
	free(param->line);
	pars_map_xy(param);
}

int		pars_map_xy(t_game *param)
{
	if (get_next_line(0, &(param->line)) > 0)
	{
		param->map_y = ft_atoi(param->line + 8);
		param->map_x = ft_atoi(param->line + 10);
		free(param->line);
	}
	else
		return (0);
	save_map(param);
	return (1);
}

int		save_map(t_game *param)
{
	int		i_map_y;

	i_map_y = 0;
	get_next_line(0, &param->line);
	free(param->line);
	if (!(param->map = (char **)malloc(sizeof(char *) * (param->map_y + 1))))
		return (0);
	while (get_next_line(0, &(param->line)) && i_map_y < param->map_y)
	{
		param->map[i_map_y] = ft_strsub(param->line, 4, (size_t)param->map_x);
		free(param->line);
		i_map_y++;
	}
	pars_figure_xy(param);
	return (1);
}
//
int		pars_figure_xy(t_game *param)
{
	if (param->line)
	{
		param->pic_y = ft_atoi(param->line + 6);
		param->pic_x = ft_atoi(param->line + 8);
		free(param->line);
	}
	pars_figure(param);
	return (1);
}

//

int			pars_figure(t_game *param)
{
	int i_fig_y;

	if (!(param->figure = (char **)malloc(sizeof(char *) * (param->pic_y + 1))))
		return (0);
	i_fig_y = -1;
	while (++i_fig_y < param->pic_y && get_next_line(0, &param->line))
	{
		param->figure[i_fig_y] = ft_strdup(param->line);
		free(param->line);
	}
	return (1);
}
