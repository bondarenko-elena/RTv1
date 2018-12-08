/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:41:00 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:46:00 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				shadow_sphere(t_obj *obj, t_vector *ro,
	t_vector *rd, double tmin)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		h;

	oc = vector_substract(ro, &obj->pos);
	a = vector_scalar_multiply(rd, rd);
	b = vector_scalar_multiply(&oc, rd);
	c = vector_scalar_multiply(&oc, &oc) - obj->size * obj->size;
	h = b * b - a * c;
	if (h > 0.001)
	{
		h = (-b - sqrt(h)) / a;
		return ((h > 0.001) && (h < tmin));
	}
	return (0);
}

int				shadow_cylinder(t_obj *obj, t_vector *ro,
	t_vector *rd, double tmin)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		h;

	oc = vector_substract(ro, &obj->pos);
	a = rd->x * rd->x + rd->z * rd->z;
	b = (rd->x * oc.x + rd->z * oc.z);
	c = oc.x * oc.x + oc.z * oc.z - obj->size * obj->size;
	h = b * b - a * c;
	if (h > 0.001)
	{
		h = (-b - sqrt(h)) / a;
		return ((h > 0.001) && (h < tmin));
	}
	return (0);
}

int				shadow_cone(t_obj *obj, t_vector *ro, t_vector *rd, double tmin)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		h;

	oc = vector_substract(ro, &obj->pos);
	a = rd->x * rd->x - rd->y * rd->y + rd->z * rd->z;
	b = rd->x * oc.x - rd->y * oc.y + rd->z * oc.z;
	c = oc.x * oc.x + oc.z * oc.z - oc.y * oc.y;
	h = b * b - a * c;
	if (h > 0.001)
	{
		h = (-b - sqrt(h)) / a;
		return ((h > 0.001) && (h < tmin));
	}
	return (0);
}

double			inter_shadows(t_env *env, t_vector *pos, t_vector *lam_pos)
{
	t_obj		*lam_obj;
	int			tmp;
	int			sha;
	t_vector	light;
	double		l;

	lam_obj = env->obj;
	tmp = 0;
	sha = 0;
	light = vector_substract(lam_pos, pos);
	l = vector_length(&light);
	light = vector_op_divide(&light, l);
	while (lam_obj)
	{
		if (lam_obj->type == 1)
			tmp = shadow_sphere(lam_obj, pos, &light, l);
		else if (lam_obj->type == 2)
			tmp = shadow_cylinder(lam_obj, pos, &light, l);
		else if (lam_obj->type == 3)
			tmp = shadow_cone(lam_obj, pos, &light, l);
		sha = (tmp == 1 ? 1 : sha);
		lam_obj = lam_obj->next;
	}
	return (sha);
}
