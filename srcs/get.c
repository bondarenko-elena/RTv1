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
