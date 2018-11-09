
#include "../includes/filler.h"

void	ft_refreshers(t_game *inf)
{
	int h;

	h = 0;
	while (h < inf->pic_y)
	{
		free(inf->figure[h]);
		h++;
	}
	free(inf->figure);
	h = 0;
}
