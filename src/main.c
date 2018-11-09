
#include "../includes/filler.h"

int		main(void)
{
	t_game *param;

	param = (t_game *)ft_memalloc(sizeof(t_game));
	zero_out(param);
	pars_line(param);
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
	//	free(param.len);
	return (0);
}