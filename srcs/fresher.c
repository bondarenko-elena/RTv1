/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:37:19 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:37:44 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (list)
	{
		free(list->content);
		free(list);
		list = list->next;
	}
}
