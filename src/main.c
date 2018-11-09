
#include "../includes/filler.h"

int		main(void)
{
	t_game *inf;

	inf = (t_game *)ft_memalloc(sizeof(t_game));
	zero_out(inf);
	pars_line(inf);
	matrix(inf);
	territory(inf);
	ft_output(inf);
	ft_refreshers(inf);
	while (inf)
	{
		if (pars_map_xy(inf))
		{
			matrix(inf);
			territory(inf);
			ft_output(inf);
			ft_refreshers(inf);
		}
		else
			return (0);
	}
	//	free(inf.len);
	return (0);
}