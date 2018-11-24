/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:16:15 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/06 19:48:38 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	setnor(t_obj *obj, t_vec3 *pos)
{
	t_vec3	nor;

	nor = (t_vec3){0.0, 1.0, 0.0};
	if (obj->type == 1)
		nor = vecsub(pos, &obj->pos);
	else if (obj->type == 2)
		nor = (t_vec3){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	else if (obj->type == 3)
		nor = (t_vec3){pos->x - obj->pos.x, 0.0, pos->z - obj->pos.z};
	vecnorm(&nor);
	return (nor);
}

double	get_shadows(t_env *e, t_vec3 *pos)
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

t_vec3	get_diff(t_env *e, t_vec3 *pos, t_vec3 *nor)
{
	t_obj	*obj;
	t_vec3	lig;
	t_vec3	lig_tmp;

	obj = e->obj;
	lig = (t_vec3){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
		{
			lig_tmp = lambert(obj, nor, pos);
			lig = vecadd(&lig, &lig_tmp);
		}
		obj = obj->next;
	}
	lig = vecopx(&lig, e->ln);
	vecclamp(&lig, 0.0, 1.0);
	return (lig);
}

t_vec3	get_spe(t_env *e, t_vec3 *pos, t_vec3 *nor)
{
	t_obj	*obj;
	t_vec3	spe;

	obj = e->obj;
	spe = (t_vec3){0.0, 0.0, 0.0};
	while (obj)
	{
		if (obj->type == 4)
			spe = vecopplus(&spe, phong(obj, nor, &e->rd, pos));
		obj = obj->next;
	}
	vecclamp(&spe, 0.0, 1.0);
	return (spe);
}


void	get_lighting(t_env *e, t_vec3 *col, t_vec3 *pos)
{
	double	sha;
	t_vec3	spe;
	t_vec3	lig;
	t_vec3	nor;

	nor = setnor(e->objs, pos);
	sha = get_shadows(e, pos);
	lig = get_diff(e, pos, &nor);
	spe = get_spe(e, pos, &nor);
	lig = vecopx(&lig, sha);
	spe = vecprod(&spe, &lig);
	*col = vecadd(col, &spe);
	vecclamp(col, 0.0, 1.0);
	*col = vecprod(col, &lig);
}
