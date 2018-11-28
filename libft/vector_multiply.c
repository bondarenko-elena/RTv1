/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:13:44 by olbondar          #+#    #+#             */
/*   Updated: 2018/11/25 16:13:45 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// vecprod
t_vector	vector_multiply(t_vector *v1, t_vector *v2)
{
	t_vector	tmp;

	tmp.x = v1->x * v2->x;
	tmp.y = v1->y * v2->y;
	tmp.z = v1->z * v2->z;
	return (tmp);
}
