/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:57:20 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/19 18:12:32 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_file(t_env *e, char *filename)
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
	file_reader(e, list);
	return (1);
}

void	parser(t_env *e, int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("rtv1: No parameter found\n", 2);
		exit(EXIT_FAILURE);
	}
	if (get_file(e, av[1]) == 0)
	{
		ft_putstr_fd("rtv1: Incorrect parameter\n", 2);
		exit(EXIT_FAILURE);
	}
}
