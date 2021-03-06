/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:54:34 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 16:54:35 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector		lambert(t_obj *obj, t_vector *normal, t_vector *pos)
{
	t_vector	lambert;
	t_vector	light;
	double		value;
	double		dist;

	dist = vector_distance(pos, &obj->pos);
	dist = ft_clamp(sqrt(GAMMA / (dist * (1.0 - obj->power))), 0.0, 1.0);
	light = vector_substract(&obj->pos, pos);
	vector_normalization(&light);
	value = ft_clamp(vector_scalar_multiply(normal, &light), 0.0, 1.0);
	if (normal->x == 0.0 && normal->y == 1.0 && normal->z == 0.0)
		value = 1.0;
	lambert = vector_op_multiply(&obj->color, value);
	lambert = vector_op_multiply(&lambert, obj->power);
	lambert = vector_op_multiply(&lambert, dist);
	return (lambert);
}

double			phong(t_obj *obj, t_vector *normal, t_vector *rd, t_vector *pos)
{
	double		phong;
	t_vector	ref;
	t_vector	light;

	light = vector_substract(&obj->pos, pos);
	vector_normalization(&light);
	ref = vector_reflect(rd, normal);
	vector_normalization(&ref);
	phong = ft_clamp(pow(ft_clamp(vector_scalar_multiply(&ref, &light),
					0.0, 1.0), 50.0), 0.0, 1.0);
	phong *= pow(obj->power, 0.5);
	return (phong);
}
