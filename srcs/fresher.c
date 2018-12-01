#include "../includes/rtv1.h"

void	free_tab_char(char **line, int size)
{
	while (size > -1)
	{
		free(line[size]);
		size--;
	}
	free(line);
}