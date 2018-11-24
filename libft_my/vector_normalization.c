#include "libft.h"

void	vector_normalization(t_vector *v)
{
	double	n;

	n = 1.0 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x *= n;
	v->y *= n;
	v->z *= n;
}