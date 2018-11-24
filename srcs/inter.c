/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:31:15 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/06 19:21:07 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	isphere(t_obj *obj, t_vec3 *ro, t_vec3 *rd)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	h;

	oc = vecsub(ro, &obj->pos);
	a = vecdot(rd, rd);
	b = vecdot(&oc, rd);
	c = vecdot(&oc, &oc) - obj->size * obj->size;
	h = b * b - a * c;
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

double	iplane(t_obj *obj, t_vec3 *ro, t_vec3 *rd)
{
	double	t;

	t = -((vecdot(&obj->rot, ro) - vecdot(&obj->rot, &obj->pos))\
		/ vecdot(&obj->rot, rd));
	if (t < 0.0001)
		return (-1.0);
	return (t);
}

double	icylinder(t_obj *obj, t_vec3 *ro, t_vec3 *rd)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	h;

	oc = vecsub(ro, &obj->pos);
	a = rd->x * rd->x + rd->z * rd->z;
	b = (rd->x * oc.x + rd->z * oc.z);
	c = oc.x * oc.x + oc.z * oc.z - obj->size * obj->size;
	h = b * b - a * c;
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

double	icone(t_obj *obj, t_vec3 *ro, t_vec3 *rd)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	h;

	oc = vecsub(ro, &obj->pos);
	a = rd->x * rd->x - rd->y * rd->y + rd->z * rd->z;
	b = rd->x * oc.x - rd->y * oc.y + rd->z * oc.z;
	c = oc.x * oc.x + oc.z * oc.z - oc.y * oc.y;
	h = b * b - a * c;
	if (h < 0.0001)
		return (-1.0);
	return ((-b - sqrt(h)) / a);
}

t_obj	*inter_object(t_env *e, t_vec3 *ro, t_vec3 *rd, double *dmin)
{
	t_obj	*lobj;
	t_obj	*obj;
	double	tmp;

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
