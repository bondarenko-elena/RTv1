#include "../includes/rtv1.h"

int		open_file(t_env *env, char *filename)
{
	int		fd;
	char	*line;
	t_list	*list;

	list = NULL;
	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
		ft_lstpushback(&list, line, ft_strlen(line));
	if (!list)
		return (0);
	close(fd);
	parse_file(env, list);
	return (1);
}
