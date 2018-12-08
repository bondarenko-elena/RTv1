/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:39:12 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:39:24 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	init_env_pre(t_env *env)
{
	env->mlx_init = mlx_init();
	env->screen_name = "RTv1@4olbondar";
	env->screen_height = HEIGHT;
	env->screen_width = WIDTH;
	env->cam_pos = (t_vector){0, 1, -5};
	env->cam_dir = (t_vector){0, 1, 0};
	env->obj = NULL;
	env->objs = NULL;
	env->ln = 0;
}

void	init_env_post(t_env *env)
{
	env->window = mlx_new_window(env->mlx_init,
			env->screen_width, env->screen_height, env->screen_name);
	env->ln = 1.0 / env->ln;
}
