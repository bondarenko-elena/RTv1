/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:53:24 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:55:48 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		lambert(t_obj *obj, t_vector *nor, t_vector *pos)
{
	t_vector	lambert;
	t_vector	light;
	double		value;
	double		dist;

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

double			phong(t_obj *obj, t_vector *nor, t_vector *rd, t_vector *pos)
{
	double		phong;
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

t_vector		set_normal(t_obj *obj, t_vector *pos)
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

double			get_shadows(t_env *env, t_vector *pos)
{
	t_obj		*obj;
	double		shadow;
	double		tmp;

	obj = env->obj;
	shadow = 1.0;
	while (obj)
	{
		if (obj->type == 4)
		{
			tmp = inter_shadows(env, pos, &obj->pos);
			if (tmp == 1)
				shadow -= (obj->power + env->ln) / 2.0;
		}
		obj = obj->next;
	}
	return (ft_clamp(shadow, 0.0, 1.0));
}

t_vector		get_diff(t_env *env, t_vector *pos, t_vector *normal)
{
	t_obj		*obj;
	t_vector	light;
	t_vector	light_tmp;

	obj = env->obj;
	light = (t_vector){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
		{
			light_tmp = lambert(obj, normal, pos);
			light = vector_add(&light, &light_tmp);
		}
		obj = obj->next;
	}
	light = vector_op_multiply(&light, env->ln);
	vector_clamp(&light, 0.0, 1.0);
	return (light);
}

t_vector		get_spe(t_env *env, t_vector *pos, t_vector *normal)
{
	t_obj		*obj;
	t_vector	spe;

	obj = env->obj;
	spe = (t_vector){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
			spe = vector_op_add(&spe, phong(obj, normal, &env->rd, pos));
		obj = obj->next;
	}
	vector_clamp(&spe, 0.0, 1.0);
	return (spe);
}

void			get_lighting(t_env *light_tmp, t_vector *col, t_vector *pos)
{
	double		shadow;
	t_vector	spe;
	t_vector	light;
	t_vector	normal;

	normal = set_normal(light_tmp->objs, pos);
	shadow = get_shadows(light_tmp, pos);
	light = get_diff(light_tmp, pos, &normal);
	spe = get_spe(light_tmp, pos, &normal);
	light = vector_op_multiply(&light, shadow);
	spe = vector_multiply(&spe, &light);
	*col = vector_add(col, &spe);
	vector_clamp(col, 0.0, 1.0);
	*col = vector_multiply(col, &light);
}
