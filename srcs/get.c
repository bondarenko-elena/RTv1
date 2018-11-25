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
