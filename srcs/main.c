/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:56:05 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/02 19:34:37 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		expose_hook(t_env *e)
{
	display(e);
	return (1);
}

int		main(int ac, char **av)
{
	t_env e;

	init_env_preparsing(&e);
	parser(&e, ac, av);
	init_env_postparsing(&e);
	mlx_hook(e.win, 2, 1L << 0, &key_press, &e);
	mlx_hook(e.win, 2, 1L << 0, &key_release, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
