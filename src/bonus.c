
#include "../includes/filler.h"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

void	ft_bonus(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'O')
			printf("%S ", L"🚴‍♂️");
		else if (line[i] == 'X')
			printf("%S ", L"🏋️‍♂️");
		else if (line[i] == '.' && line[0] != 'l' && line[0] != '$'
			&& line[0] != '#')
			printf(CYN"%S "RESET, L"☀");
		else if (line[i] == '*')
			printf("%S ", L"🤼‍♂️");
		else if ((line[i] == 'o' || line[i] == 'x') &&
			line[0] != '<' && line[0] != '$' && line[0] != '#'
			&& line[0] != 'l')
			printf("%S ", L"🎪");
		else
			printf("%c", line[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_bonus(line);
		free(line);
		line = NULL;
	}
	return (0);
}
