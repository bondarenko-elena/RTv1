/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:41 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/01 15:45:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	vector_distance(t_vector *v1, t_vector *v2)
{
	double	distance;

	distance = sqrt((v1->x - v2->x) * (v1->x - v2->x) +
		(v1->y - v2->y) * (v1->y - v2->y) + (v1->z - v2->z) * (v1->z - v2->z));
	return (distance);
}
