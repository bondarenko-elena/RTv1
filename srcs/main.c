#include "../includes/rtv1.h"

void exit_w_error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		exit_w_error("No parameter found. Usage: ./rtv1 scenes/scene.");
	if (argc == 2)
	{
		t_env env;

		pre_init_env(&env);
		if (open_file(&env, argv[1]) == 0)
			exit_w_error("Incorrect parameter.");
		post_init_env(&env);
		mlx_hook(env.win, 2, 1L << 0, key_press, &env);
		mlx_hook(env.win, 17, 1L << 0, red_cross, &env);
		mlx_hook(env.win, 12, 1L << 0, expose_hook, &env);
		mlx_loop(env.mlx_init);
	}
	if (argc > 2)
		exit_w_error("Too many parameters. Usage: ./rtv1 scenes/scene.");
	return (0);
}
