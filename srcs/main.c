#include "../includes/rtv1.h"

int			red_cross()
{
	// system("leaks RTv1");
	exit(EXIT_SUCCESS);
	return (0);
}

int		expose_hook(t_env *env)
{
	display(env);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env env;

	init_env_preparsing(&env);
	parser(&env, argc, argv);
	init_env_postparsing(&env);
	mlx_hook(env.win, 2, 1L << 0, &key_press, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_hook(env.win, 17, 1L << 0, red_cross, &env);
	mlx_loop(env.mlx);
	return (1);
}
