
#include "../includes/filler.h"

void	ft_refreshers(t_game *param)
{
	int h;

	h = 0;
	while (h < param->pic_y)
	{
		free(param->figure[h]);
		h++;
	}
	free(param->figure);
	h = 0;
}
