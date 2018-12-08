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

void			set_cam(t_env *e, double x, double y)
{
	double		u;
	double		v;
	t_vector	ww;
	t_vector	uu;
	t_vector	vv;

	u = (e->screen_width - x * 2.0) / e->screen_height;
	v = (e->screen_height - y * 2.0) / e->screen_height;
	ww = vector_substract(&e->cam_dir, &e->cam_pos);
	vector_normalization(&ww);
	uu = vector_cross(&ww, &(t_vector){0.0, 1.0, 0.0});
	vector_normalization(&uu);
	vv = vector_cross(&uu, &ww);
	e->rd = (t_vector){u * uu.x + v * vv.x + FOV * ww.x, u * uu.y + v * \
		vv.y + FOV * ww.y, u * uu.z + v * vv.z + FOV * ww.z};
	e->ro = e->cam_pos;
	e->objs = NULL;
}

t_vector		object_color(t_env *e,
		t_vector *ro, t_vector *rd, t_vector *col)
{
	t_vector	pos;

	e->tmin = 10000.0;
	e->objs = inter_object(e, ro, rd, &e->tmin);
	if (e->tmin > 0.0001 && e->objs)
	{
		*col = (t_vector){e->objs->color.x, e->objs->color.y, e->objs->color.z};
		if (e->tmin < 10000.0)
		{
			pos = (t_vector){e->ro.x + e->tmin * e->rd.x, e->ro.y + e->tmin * \
				e->rd.y, e->ro.z + e->tmin * e->rd.z};
			get_lighting(e, col, &pos);
		}
	}
	return (*col);
}

t_vector		ray_tracing(t_env *e, double x, double y)
{
	t_vector	col;

	set_cam(e, x, y);
	col = (t_vector){0.0, 0.0, 0.0};
	col = object_color(e, &e->ro, &e->rd, &col);
	return (col);
}

void			display(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->screen_height)
	{
		x = -1;
		while (++x < e->screen_width)
		{
			e->color = ray_tracing(e, x, y);
			e->color = (t_vector){pow(e->color.x, GAMMA),
				pow(e->color.y, GAMMA), e->color.z = pow(e->color.z, GAMMA)};
			vector_clamp(&e->color, 0.0, 1.0);
			put_pixel(e, x, y);
		}
	}
}
