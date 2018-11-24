#include "../includes/rtv1.h"

int		key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		// system("leaks RTv1");
		exit(EXIT_SUCCESS);
	}
	return (1);
}
