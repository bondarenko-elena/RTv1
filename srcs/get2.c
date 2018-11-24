/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:14:38 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/05 17:14:40 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_render(t_env *e, char *info)
{
	char	**render_info;

	if (info)
	{
		render_info = ft_strsplit(info, ' ');
		e->screen_width = ft_clamp(ft_atoi(render_info[0]), 10, 5000);
		e->screen_height = ft_clamp(ft_atoi(render_info[1]), 10, 5000);
	}
	else
		ft_putstr_fd("RTv1: Error while loading rendering info\n", 2);
}
