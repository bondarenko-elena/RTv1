#include "../includes/rtv1.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_env env;

		pre_init_env(&env);
		parser(&env, argc, argv);
		post_init_env(&env);
		mlx_hook(env.win, 2, 1L << 0, key_press, &env);
		mlx_hook(env.win, 17, 1L << 0, red_cross, &env);
		mlx_hook(env.win, 12, 1L << 0, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	else ft_putendl("usage: ./rtv1 scenes/scene");
	return (0);
}
