#include "libft.h"

void	vector_clamp(t_vector *v, double v1, double v2)
{
	v->x = ft_clamp(v->x, v1, v2);
	v->y = ft_clamp(v->y, v1, v2);
	v->z = ft_clamp(v->z, v1, v2);
}
