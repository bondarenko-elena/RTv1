/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 19:31:33 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 19:34:31 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	pixel_put(t_env *e, int x, int y)
{
	int		color;

	color = (int)(e->col.z * 256) % 256;
	color += ((int)(e->col.y * 256) % 256) * 256;
	color += ((int)(e->col.x * 256) % 256) * 256 * 256;
	mlx_pixel_put(e->mlx, e->win, x, y, color);
}