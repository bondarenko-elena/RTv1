#include "../includes/rtv1.h"

t_vector	lambert(t_obj *obj, t_vector *nor, t_vector *pos)
{
	t_vector	lambert;
	t_vector	light;
	double	value;
	double	dist;

	dist = vector_distance(pos, &obj->pos);
	dist = ft_clamp(sqrt(GAMMA / (dist * (1.0 - obj->power))), 0.0, 1.0);
	light = vector_substract(&obj->pos, pos);
	vector_normalization(&light);
	value = ft_clamp(vector_scalar_multiply(nor, &light), 0.0, 1.0);
	if (nor->x == 0.0 && nor->y == 1.0 && nor->z == 0.0)
		value = 1.0;
	lambert = vector_op_multiply(&obj->color, value);
	lambert = vector_op_multiply(&lambert, obj->power);
	lambert = vector_op_multiply(&lambert, dist);
	return (lambert);
}

double	phong(t_obj *obj, t_vector *nor, t_vector *rd, t_vector *pos)
{
	double	phong;
	t_vector	ref;
	t_vector	light;

	light = vector_substract(&obj->pos, pos);
	vector_normalization(&light);
	ref = vector_reflect(rd, nor);
	vector_normalization(&ref);
	phong = ft_clamp(pow(ft_clamp(vector_scalar_multiply(&ref, &light), \
					0.0, 1.0), 50.0), 0.0, 1.0);
	phong *= pow(obj->power, 0.5);
	return (phong);
}

t_vector	setnor(t_obj *obj, t_vector *pos)
{
	t_vector	nor;

	nor = (t_vector){0.0, 1.0, 0.0};
	if (obj->type == 1)
		nor = vector_substract(pos, &obj->pos);
	else if (obj->type == 2)
		nor = (t_vector){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	else if (obj->type == 3)
		nor = (t_vector){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	vector_normalization(&nor);
	return (nor);
}

double	get_shadows(t_env *e, t_vector *pos)
{
	t_obj	*obj;
	double	sha;
	double	tmp;

	obj = e->obj;
	sha = 1.0;
	while (obj)
	{
		if (obj->type == 4)
		{
			tmp = inter_shadows(e, pos, &obj->pos);
			if (tmp == 1)
				sha -= (obj->power + e->ln) / 2.0;
		}
		obj = obj->next;
	}
	return (ft_clamp(sha, 0.0, 1.0));
}

t_vector	get_diff(t_env *e, t_vector *pos, t_vector *nor)
{
	t_obj	*obj;
	t_vector	lig;
	t_vector	lig_tmp;

	obj = e->obj;
	lig = (t_vector){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
		{
			lig_tmp = lambert(obj, nor, pos);
			lig = vector_add(&lig, &lig_tmp);
		}
		obj = obj->next;
	}
	lig = vector_op_multiply(&lig, e->ln);
	vector_clamp(&lig, 0.0, 1.0);
	return (lig);
}

t_vector	get_spe(t_env *e, t_vector *pos, t_vector *nor)
{
	t_obj	*obj;
	t_vector	spe;

	obj = e->obj;
	spe = (t_vector){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
			spe = vector_op_add(&spe, phong(obj, nor, &e->rd, pos));
		obj = obj->next;
	}
	vector_clamp(&spe, 0.0, 1.0);
	return (spe);
}


void	get_lighting(t_env *e, t_vector *col, t_vector *pos)
{
	double	sha;
	t_vector	spe;
	t_vector	lig;
	t_vector	nor;

	nor = setnor(e->objs, pos);
	sha = get_shadows(e, pos);
	lig = get_diff(e, pos, &nor);
	spe = get_spe(e, pos, &nor);
	lig = vector_op_multiply(&lig, sha);
	spe = vector_multiply(&spe, &lig);
	*col = vector_add(col, &spe);
	vector_clamp(col, 0.0, 1.0);
	*col = vector_multiply(col, &lig);
}
