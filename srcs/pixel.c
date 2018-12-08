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

void	put_pixel(t_env *env, int x, int y)
{
	int		color;

	color = (int)(env->color.z * 256) % 256;
	color += ((int)(env->color.y * 256) % 256) * 256;
	color += ((int)(env->color.x * 256) % 256) * 256 * 256;
	mlx_pixel_put(env->mlx_init, env->window, x, y, color);
}
