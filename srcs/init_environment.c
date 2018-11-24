#include "../includes/rtv1.h"

void	pre_init_env(t_env *env)
{
	// t_vec3	tmp;

	env->mlx = mlx_init();
	// tmp = (t_vec3){0, 1, -5};
	env->cam_pos = (t_vec3){0, 1, -5};
	// tmp = (t_vec3){0, 1, 0};
	env->cam_dir = (t_vec3){0, 1, 0};
	env->obj = NULL;
	env->objs = NULL;
	env->ln = 0;
	env->screen_name = "RTv1@4olbondar";
	env->screen_height = HEIGHT;
	env->screen_width = WIDTH;
}

void	post_init_env(t_env *env)
{
	env->win = mlx_new_window(env->mlx, env->screen_width, \
			env->screen_height, env->screen_name);
	env->ln = 1.0 / env->ln;
}
