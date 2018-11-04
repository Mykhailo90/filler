
#include "../includes/filler.h"

#include <stdio.h>

int		main(void)
{
	t_game *param;

	param = (t_game *)ft_memalloc(sizeof(t_game));
	init_param(param);
	row_parser(param);
	matrix(param);
	territory(param);
	ft_output(param);
	ft_refreshers(param);
	while (param)
	{
		if (pars_map_xy(param))
		{
			matrix(param);
			territory(param);
			ft_output(param);
			ft_refreshers(param);
		}
		else
			return (0);
	}
	return (0);
}
