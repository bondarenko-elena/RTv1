/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:46:29 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:50:43 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double			inter_sphere(t_obj *obj, t_vector *ro, t_vector *rd)
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
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

double			inter_plane(t_obj *obj, t_vector *ro, t_vector *rd)
{
	double		t;

	t = -((vector_scalar_multiply(&obj->rot, ro) -
				vector_scalar_multiply(&obj->rot, &obj->pos))
			/ vector_scalar_multiply(&obj->rot, rd));
	if (t < 0.0001)
		return (-1.0);
	return (t);
}

double			inter_cylinder(t_obj *obj, t_vector *ro, t_vector *rd)
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
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

double			inter_cone(t_obj *obj, t_vector *ro, t_vector *rd)
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
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

t_obj			*inter_object(t_env *env,
		t_vector *ro, t_vector *rd, double *dmin)
{
	t_obj		*lam_obj;
	t_obj		*obj;
	double		tmp;

	obj = NULL;
	lam_obj = env->obj;
	tmp = *dmin;
	while (lam_obj)
	{
		if (lam_obj->type == 0)
			tmp = inter_plane(lam_obj, ro, rd);
		else if (lam_obj->type == 1)
			tmp = inter_sphere(lam_obj, ro, rd);
		else if (lam_obj->type == 2)
			tmp = inter_cylinder(lam_obj, ro, rd);
		else if (lam_obj->type == 3)
			tmp = inter_cone(lam_obj, ro, rd);
		if (tmp > 0.0001 && tmp < *dmin)
		{
			obj = lam_obj;
			*dmin = tmp;
		}
		lam_obj = lam_obj->next;
	}
	return (obj);
}
