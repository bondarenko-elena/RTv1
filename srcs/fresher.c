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

void	free_tab_list(t_list *list)
{
	while(list)
	{
		free(list->content);
		free(list);
		list = list->next;
	}
}