
#include "../includes/filler.h"

int			create_map(t_game *param)
{
	int 	iter;

	if (!(param->figure = (char **)malloc(sizeof(char *) * (param->pic_y + 1))))
		return (0);
	
		iter = -1;
		while (++iter < param->pic_y && get_next_line(0, &param->line))
		{
			param->figure[iter] = ft_strdup(param->line);
			free(param->line);
		}
		return (1);
	
}

int		parsing_coords_position(t_game *param)
{
	if (param->line)
	{
		param->pic_y = ft_atoi(param->line + 6);
		param->pic_x = ft_atoi(param->line + 8);
		free(param->line);
	}
	create_map(param);
	return (1);
}

int		map_parser(t_game *param)
{
	int		iter;

	iter = 0;
	get_next_line(0, &param->line);
	free(param->line);
	if (!(param->map = (char **)malloc(sizeof(char *) * (param->map_y + 1))))
		return (0);
	
		while (get_next_line(0, &(param->line)) && (iter < param->map_y))
		{
			param->map[iter] = ft_strsub(param->line, 4, (size_t)param->map_x);
			free(param->line);
			iter++;
		}
		parsing_coords_position(param);
		return (1);
}

int		coords_parser(t_game *param)
{
	if (get_next_line(0, &(param->line)) > 0)
	{
		param->map_y = ft_atoi(param->line + 8);
		param->map_x = ft_atoi(param->line + 10);
		free(param->line);
		map_parser(param);
		return (1);
	}
	return (0);
}

void	row_parser(t_game *param)
{
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
	coords_parser(param);
}
