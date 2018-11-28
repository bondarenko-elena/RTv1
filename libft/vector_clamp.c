/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:14:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/11/25 16:14:53 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// vecclamp
void	vector_clamp(t_vector *v, double v1, double v2)
{
	v->x = ft_clamp(v->x, v1, v2);
	v->y = ft_clamp(v->y, v1, v2);
	v->z = ft_clamp(v->z, v1, v2);
}