#include "../includes/rtv1.h"

int		key_press(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		// system("leaks RTv1");
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int			red_cross(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	// system("leaks RTv1");
	exit(EXIT_SUCCESS);
	return (0);
}

int		expose_hook(t_env *env)
{
	display(env);
	return (1);
}
