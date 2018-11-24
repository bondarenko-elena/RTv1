#include "../includes/rtv1.h"

void	set_cam(t_env *e, double x, double y)
{
	double	u;
	double	v;
	t_vec3	ww;
	t_vec3	uu;
	t_vec3	vv;

	u = (e->screen_width - x * 2.0) / e->screen_height;
	v = (e->screen_height - y * 2.0) / e->screen_height;
	ww = vecsub(&e->cam_dir, &e->cam_pos);
	vecnorm(&ww);
	uu = veccross(&ww, &(t_vec3){0.0, 1.0, 0.0});
	vecnorm(&uu);
	vv = veccross(&uu, &ww);
	e->rd = (t_vec3){u * uu.x + v * vv.x + FOV * ww.x, u * uu.y + v * \
		vv.y + FOV * ww.y, u * uu.z + v * vv.z + FOV * ww.z};
	e->ro = e->cam_pos;
	e->objs = NULL;
}

t_vec3	object_color(t_env *e, t_vec3 *ro, t_vec3 *rd, t_vec3 *col)
{
	t_vec3	pos;

	e->tmin = 10000.0;
	e->objs = inter_object(e, ro, rd, &e->tmin);
	if (e->tmin > 0.0001 && e->objs)
	{
		*col = (t_vec3){e->objs->color.x, e->objs->color.y, e->objs->color.z};
		if (e->tmin < 10000.0)
		{
			pos = (t_vec3){e->ro.x + e->tmin * e->rd.x, e->ro.y + e->tmin * \
				e->rd.y, e->ro.z + e->tmin * e->rd.z};
			get_lighting(e, col, &pos);
		}
	}
	return (*col);
}

t_vec3	ray_tracing(t_env *e, double x, double y)
{
	t_vec3	col;

	set_cam(e, x, y);
	col = (t_vec3){0.0, 0.0, 0.0};
	col = object_color(e, &e->ro, &e->rd, &col);
	return (col);
}

void	display(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->screen_height)
	{
		x = -1;
		while (++x < e->screen_width)
		{
			e->col = ray_tracing(e, x, y);
			e->col.x = pow(e->col.x, GAMMA);
			e->col.y = pow(e->col.y, GAMMA);
			e->col.z = pow(e->col.z, GAMMA);
			vecclamp(&e->col, 0.0, 1.0);
			pixel_put(e, x, y);
		}
	}
}
