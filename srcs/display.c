/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:51:16 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:52:46 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		get_obj_color(t_env *env,
		t_vector *ro, t_vector *rd, t_vector *color)
{
	t_vector	pos;

	env->tmin = 10000.0;
	env->objs = inter_object(env, ro, rd, &env->tmin);
	if (env->tmin > 0.0001 && env->objs)
	{
		*color = (t_vector){env->objs->color.x,
			env->objs->color.y, env->objs->color.z};
		if (env->tmin < 10000.0)
		{
			pos = (t_vector){env->ro.x + env->tmin
				* env->rd.x, env->ro.y + env->tmin *
				env->rd.y, env->ro.z + env->tmin * env->rd.z};
			get_lighting(env, color, &pos);
		}
	}
	return (*color);
}

void			set_camera(t_env *env, double x, double y)
{
	double		u;
	double		v;
	t_vector	ww;
	t_vector	uu;
	t_vector	vv;

	u = (env->screen_width - x * 2.0) / env->screen_height;
	v = (env->screen_height - y * 2.0) / env->screen_height;
	ww = vector_substract(&env->cam_dir, &env->cam_pos);
	vector_normalization(&ww);
	uu = vector_cross(&ww, &(t_vector){0.0, 1.0, 0.0});
	vector_normalization(&uu);
	vv = vector_cross(&uu, &ww);
	env->rd = (t_vector){u * uu.x + v * vv.x + FOV * ww.x, u * uu.y + v
		* vv.y + FOV * ww.y, u * uu.z + v * vv.z + FOV * ww.z};
	env->ro = env->cam_pos;
	env->objs = NULL;
}

t_vector		ray_tracing(t_env *env, double x, double y)
{
	t_vector	color;

	set_camera(env, x, y);
	color = (t_vector){0.0, 0.0, 0.0};
	color = get_obj_color(env, &env->ro, &env->rd, &color);
	return (color);
}

void			display(t_env *env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < env->screen_height)
	{
		x = -1;
		while (++x < env->screen_width)
		{
			env->color = ray_tracing(env, x, y);
			env->color = (t_vector){pow(env->color.x, GAMMA),
				pow(env->color.y, GAMMA),
				env->color.z = pow(env->color.z, GAMMA)};
			vector_clamp(&env->color, 0.0, 1.0);
			put_pixel(env, x, y);
		}
	}
}
