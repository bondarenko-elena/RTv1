#include "libft.h"

t_vector	*vector_op_add(t_vector *v, double x)
{
	t_vector *tmp;

	tmp = NULL;
	tmp->x = v->x + x;
	tmp->y = v->y + x;
	tmp->z = v->z + x;
	return (tmp);
}
