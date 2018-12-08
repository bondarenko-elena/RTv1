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

double			isphere(t_obj *obj, t_vector *ro, t_vector *rd)
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

double			iplane(t_obj *obj, t_vector *ro, t_vector *rd)
{
	double		t;

	t = -((vector_scalar_multiply(&obj->rot, ro) -
				vector_scalar_multiply(&obj->rot, &obj->pos))
			/ vector_scalar_multiply(&obj->rot, rd));
	if (t < 0.0001)
		return (-1.0);
	return (t);
}

double			icylinder(t_obj *obj, t_vector *ro, t_vector *rd)
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

double			icone(t_obj *obj, t_vector *ro, t_vector *rd)
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

t_obj			*inter_object(t_env *e,
		t_vector *ro, t_vector *rd, double *dmin)
{
	t_obj		*lobj;
	t_obj		*obj;
	double		tmp;

	obj = NULL;
	lobj = e->obj;
	tmp = *dmin;
	while (lobj)
	{
		if (lobj->type == 0)
			tmp = iplane(lobj, ro, rd);
		else if (lobj->type == 1)
			tmp = isphere(lobj, ro, rd);
		else if (lobj->type == 2)
			tmp = icylinder(lobj, ro, rd);
		else if (lobj->type == 3)
			tmp = icone(lobj, ro, rd);
		if (tmp > 0.0001 && tmp < *dmin)
		{
			obj = lobj;
			*dmin = tmp;
		}
		lobj = lobj->next;
	}
	return (obj);
}
