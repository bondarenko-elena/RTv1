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

t_vector		set_normal(t_obj *obj, t_vector *pos)
{
	t_vector	normal;

	normal = (t_vector){0.0, 1.0, 0.0};
	if (obj->type == 1)
		normal = vector_substract(pos, &obj->pos);
	else if (obj->type == 2)
		normal = (t_vector){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	else if (obj->type == 3)
		normal = (t_vector){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	vector_normalization(&normal);
	return (normal);
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

t_vector		get_diffuse(t_env *env, t_vector *pos, t_vector *normal)
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

t_vector		get_specular(t_env *env, t_vector *pos, t_vector *normal)
{
	t_obj		*obj;
	t_vector	specular;

	obj = env->obj;
	specular = (t_vector){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
			specular = vector_op_add(&specular,
				phong(obj, normal, &env->rd, pos));
		obj = obj->next;
	}
	vector_clamp(&specular, 0.0, 1.0);
	return (specular);
}

void			get_lighting(t_env *light_tmp, t_vector *col, t_vector *pos)
{
	double		shadow;
	t_vector	specular;
	t_vector	light;
	t_vector	normal;

	normal = set_normal(light_tmp->objs, pos);
	shadow = get_shadows(light_tmp, pos);
	light = get_diffuse(light_tmp, pos, &normal);
	specular = get_specular(light_tmp, pos, &normal);
	light = vector_op_multiply(&light, shadow);
	specular = vector_multiply(&specular, &light);
	*col = vector_add(col, &specular);
	vector_clamp(col, 0.0, 1.0);
	*col = vector_multiply(col, &light);
}
