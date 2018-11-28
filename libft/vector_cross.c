/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:29 by olbondar          #+#    #+#             */
/*   Updated: 2018/11/25 16:14:30 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// veccross
t_vector	vector_cross(t_vector *v1, t_vector *v2)
{
	t_vector tmp;

	tmp.x = v1->y * v2->z - v1->z * v2->y;
	tmp.y = v1->z * v2->x - v1->x * v2->z;
	tmp.z = v1->x * v2->y - v1->y * v2->x;
	return (tmp);
}
