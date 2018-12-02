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

void	uf_del_callback(void *d, size_t s)
{
	free(d);
	(void)s;
}