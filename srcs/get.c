#include "../includes/rtv1.h"

void	get_objvec(t_vec3 *vec, char *info)
{
	char	**vec_info;

	if (info)
	{
		vec_info = ft_strsplit(info, ' ');
		vec->x = ft_atoi(vec_info[0]);
		vec->y = ft_atoi(vec_info[1]);
		vec->z = ft_atoi(vec_info[2]);
	}
	else
		ft_putstr_fd("RTv1: Error while loading object vector info\n", 2);
}

void	get_color(t_obj *obj, char *info)
{
	char	**color_info;

	if (info)
	{
		color_info = ft_strsplit(info, ' ');
		obj->color.x = ft_clamp(ft_atoi(color_info[0]) / 256.0, 0.0, 1.0);
		obj->color.y = ft_clamp(ft_atoi(color_info[1]) / 256.0, 0.0, 1.0);
		obj->color.z = ft_clamp(ft_atoi(color_info[2]) / 256.0, 0.0, 1.0);
	}
	else
		ft_putstr_fd("RTv1: Error while loading an object color\n", 2);
}

void	get_double(t_obj *obj, char *info, int type)
{
	if (info)
	{
		if (type == 0)
			obj->size = ft_clamp(ft_atoi(info), 1.0, 50000);
		else if (type == 1)
			obj->power = ft_clamp(ft_atoi(info), 0.0, 99.0);
	}
	else
		ft_putstr_fd("RTv1: Error while loading an object size\n", 2);
}

void	get_name(t_env *e, char *info)
{
	if (info)
		e->screen_name = ft_strdup(info);
	else
		ft_putstr_fd("RTv1: Error while loading scene name\n", 2);
}

void	get_camera(t_env *e, char *info, int type)
{
	char	**cam_info;

	if (info)
	{
		cam_info = ft_strsplit(info, ' ');
		if (type == 0)
		{
			e->cam_pos.x = ft_atoi(cam_info[0]);
			e->cam_pos.y = ft_atoi(cam_info[1]);
			e->cam_pos.z = ft_atoi(cam_info[2]);
		}
		else if (type == 1)
		{
			e->cam_dir.x = ft_atoi(cam_info[0]);
			e->cam_dir.y = ft_atoi(cam_info[1]);
			e->cam_dir.z = ft_atoi(cam_info[2]);
		}
	}
	else
		ft_putstr_fd("RTv1: Error while loading camera info\n", 2);
}
