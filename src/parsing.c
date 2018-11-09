
#include "../includes/filler.h"

void	row_parsing(t_game *param)
{
	if (get_next_line(0, &(param->line)) > 0)
	{
		if (*(param->line + 10) == '1')
			param->champ = 'O';
		else
			param->champ = 'X';
		if (param->champ == 'O')
			param->loser = 'X';
		else
			param->loser = 'O';
	}
	free(param->line);
	coords_parsing(param);
}

int		coords_parsing(t_game *param)
{
	if (get_next_line(0, &(param->line)) > 0)
	{
		param->coord_y = ft_atoi(param->line + 8);
		param->coord_x = ft_atoi(param->line + 10);
		free(param->line);
	}
	else
		return (0);
	field_fix(param);
	return (1);
}

void		field_fix(t_game *param)
{
	int		iter;

	iter = 0;
	get_next_line(0, &param->line);
	free(param->line);
	if (!(param->map = (char **)malloc(sizeof(char *) * (param->coord_y + 1))))
		return;
	while (get_next_line(0, &(param->line)) && iter < param->coord_y)
	{
		param->map[iter] = ft_strsub(param->line, 4, (size_t)param->coord_x);
		free(param->line);
		iter++;
	}
	pars_picture_coords(param);
}

void		pars_picture_coords(t_game *param)
{
	if (param->line)
	{
		param->field_y = ft_atoi(param->line + 6);
		param->field_x = ft_atoi(param->line + 8);
		free(param->line);
	}
	pars_picture(param);
}

void			pars_picture(t_game *param)
{
	int iter;

	if (!(param->picture = (char **)malloc(sizeof(char *) * (param->field_y + 1))))
		return;
	iter = -1;
	while (++iter < param->field_y && get_next_line(0, &param->line))
	{
		param->picture[iter] = ft_strdup(param->line);
		free(param->line);
	}
}