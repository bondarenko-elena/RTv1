/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:40:38 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:40:40 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_obj	*new_obj(t_obj *obj)
{
	t_obj	*ret;

	ret = (t_obj*)malloc(sizeof(t_obj));
	if (ret == NULL)
		exit_w_error("new_obj: malloc error");
	ret->type = obj->type;
	ret->size = obj->size / 100.0;
	ret->power = obj->power / 100.0;
	ret->pos = obj->pos;
	ret->rot = obj->rot;
	ret->color = obj->color;
	return (ret);
}

void	init_obj(t_obj *obj)
{
	obj->type = 0;
	obj->size = 100.0;
	obj->power = 50.0;
	obj->pos = (t_vector){0.0, 1.0, 0.0};
	obj->rot = (t_vector){0.0, 1.0, 1.0};
	obj->color = (t_vector){0.5, 0.5, 0.5};
}

void	obj_push_back(t_env *env, t_obj *obj)
{
	t_obj	*cur;

	cur = env->obj;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new_obj(obj);
	}
	else
		env->obj = new_obj(obj);
}
