/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_substract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:12:07 by olbondar          #+#    #+#             */
/*   Updated: 2018/11/25 16:12:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_substract(t_vector *v1, t_vector *v2)
{
	t_vector	*tmp;

	tmp = NULL;
	tmp->x = v1->x - v2->x;
	tmp->y = v1->y - v2->y;
	tmp->z = v1->z - v2->z;
	return (tmp);
}
