#include "libft.h"

double	vector_distance(t_vector *v1, t_vector *v2)
{
	double	distance;

	distance = sqrt((v1->x - v2->x) * (v1->x - v2->x) +
		(v1->y - v2->y) * (v1->y - v2->y) + (v1->z - v2->z) * (v1->z - v2->z));
	return (distance);
}
