/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:31:01 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 19:36:51 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_env_postparsing(t_env *e)
{
	e->win = mlx_new_window(e->mlx, e->screen_width, \
			e->screen_height, e->screen_name);
	e->ln = 1.0 / e->ln;
}

void	init_env_preparsing(t_env *e)
{
	t_vec3	normedemerde;

	e->mlx = mlx_init();
	normedemerde = (t_vec3){0, 1, -5};
	e->cam_pos = normedemerde;
	normedemerde = (t_vec3){0, 1, 0};
	e->cam_dir = normedemerde;
	e->obj = NULL;
	e->objs = NULL;
	e->ln = 0;
	e->screen_name = "RTv1@42";
	e->screen_width = 1000;
	e->screen_height = 1000;
}
