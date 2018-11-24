#include "../includes/rtv1.h"

int			red_cross()
{
	system("leaks RTv1");
	exit(0);
	return (0);
}

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
	mlx_hook(e.win, 17, 1L << 0, red_cross, &e);
	mlx_loop(e.mlx);
	return (1);
}
