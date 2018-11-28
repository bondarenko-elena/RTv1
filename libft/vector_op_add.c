/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:13:29 by olbondar          #+#    #+#             */
/*   Updated: 2018/11/25 16:13:30 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// vecopplus
t_vector	vector_op_add(t_vector *v, double x)
{
	t_vector tmp;

	tmp.x = v->x + x;
	tmp.y = v->y + x;
	tmp.z = v->z + x;
	return (tmp);
}
