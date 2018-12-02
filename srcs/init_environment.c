#include "../includes/rtv1.h"

void	pre_init_env(t_env *env)
{
	env->mlx_init = mlx_init();
	env->screen_name = "RTv1@4olbondar";
	env->screen_height = HEIGHT;
	env->screen_width = WIDTH;
	env->cam_pos = (t_vector){0, 1, -5};
	env->cam_dir = (t_vector){0, 1, 0};
	env->obj = NULL;
	env->objs = NULL;
	env->ln = 0;
}

void	post_init_env(t_env *env)
{
	env->window = mlx_new_window(env->mlx_init, env->screen_width, env->screen_height, env->screen_name);
	env->ln = 1.0 / env->ln;
}
