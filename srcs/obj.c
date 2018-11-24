/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:31:27 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 19:38:30 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	objinit(t_obj *obj)
{
	t_vec3	normedemerde;

	obj->type = 0;
	obj->size = 100.0;
	obj->power = 50.0;
	normedemerde = (t_vec3){0.0, 1.0, 0.0};
	obj->pos = normedemerde;
	normedemerde = (t_vec3){0.0, 1.0, 1.0};
	obj->rot = normedemerde;
	obj->color.x = 0.9;
	obj->color.y = 0.9;
	obj->color.z = 0.9;
}

t_obj	*objnew(t_obj *obj)
{
	t_obj	*ret;

	ret = malloc(sizeof(t_obj));
	ret->type = obj->type;
	ret->size = obj->size / 100.0;
	ret->power = obj->power / 100.0;
	ret->pos = obj->pos;
	ret->rot = obj->rot;
	ret->color = obj->color;
	return (ret);
}

void	objpushback(t_env *e, t_obj *obj)
{
	t_obj	*cur;

	cur = e->obj;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = objnew(obj);
	}
	else
		e->obj = objnew(obj);
}
