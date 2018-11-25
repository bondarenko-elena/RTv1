/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_multiply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:13:03 by olbondar          #+#    #+#             */
/*   Updated: 2018/11/25 16:13:05 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_op_multiply(t_vector *v, double x)
{
	t_vector	*tmp;

	tmp = NULL;
	tmp->x = v->x * x;
	tmp->y = v->y * x;
	tmp->z = v->z * x;
	return (tmp);
}
