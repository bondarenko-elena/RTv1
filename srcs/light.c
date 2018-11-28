#include "../includes/rtv1.h"

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
