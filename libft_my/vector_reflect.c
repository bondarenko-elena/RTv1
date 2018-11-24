#include "libft.h"

t_vector	*vector_reflect(t_vector *i, t_vector *n)
{
	t_vector	*tmp;

	tmp = NULL;
	tmp->x = i->x - 2.0 * vector_scalar_multiply(n, i) * n->x;
	tmp->y = i->y - 2.0 * vector_scalar_multiply(n, i) * n->y;
	tmp->z = i->z - 2.0 * vector_scalar_multiply(n, i) * n->z;
	return (tmp);
}
