/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:12:30 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/01 15:46:22 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	vector_reflect(t_vector *i, t_vector *n)
{
	t_vector	tmp;

	tmp.x = i->x - 2.0 * vector_scalar_multiply(n, i) * n->x;
	tmp.y = i->y - 2.0 * vector_scalar_multiply(n, i) * n->y;
	tmp.z = i->z - 2.0 * vector_scalar_multiply(n, i) * n->z;
	return (tmp);
}
