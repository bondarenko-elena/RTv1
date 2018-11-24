#include "../includes/rtv1.h"

int		get_file(t_env *env, char *filename)
{
	int		fd;
	char	*line;
	t_list	*list;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	list = NULL;
	while (get_next_line(fd, &line) == 1)
		ft_lstpushback(&list, line, ft_strlen(line));
	if (!list)
		return (0);
	close(fd);
	file_reader(env, list);
	return (1);
}
