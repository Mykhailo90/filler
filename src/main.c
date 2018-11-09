
#include "../includes/filler.h"

void	processing(t_game *param)
{
	jig(param);
	soil(param);
	printing(param);
	clearing(param);
}

int		main(void)
{
	t_game param;

	init_param(&param);
	row_parsing(&param);
	processing(&param);
	while (1)
	{
		if (coords_parsing(&param))
			processing(&param);
		else
			return (0);
	}
	return (0);
}
