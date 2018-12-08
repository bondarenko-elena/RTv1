/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:40:16 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:40:17 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		ft_lstpushback(&list, line, ft_strlen(line));
		free(line);
	}
	free(line);
	if (!list)
		return (0);
	close(fd);
	parse_file(env, list);
	free_tab_list(list);
	return (1);
}
