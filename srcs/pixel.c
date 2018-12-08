/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:39:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 14:39:53 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	put_pixel(t_env *e, int x, int y)
{
	int		color;

	color = (int)(e->col.z * 256) % 256;
	color += ((int)(e->col.y * 256) % 256) * 256;
	color += ((int)(e->col.x * 256) % 256) * 256 * 256;
	mlx_pixel_put(e->mlx_init, e->window, x, y, color);
}
