/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:51:43 by qmuntada          #+#    #+#             */
/*   Updated: 2015/02/06 18:20:16 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

// debian --> # define ESC 65307
# define ESC 53
# define S 115
# define W 119
# define A 97
# define D 100
# define FOV 2.0
# define GAMMA 1.0
# define HEIGHT 1700
# define WIDTH 1000

typedef struct			s_obj
{
	int					type;
	t_vec3				pos;
	t_vec3				rot;
	t_vec3				color;
	double				size;
	double				power;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_env
{
	void				*mlx_init;
	void				*window;
	int					screen_height;
	int					screen_width;
	t_vec3				cam_pos;
	t_vec3				cam_dir;
	t_vec3				ro;
	t_vec3				rd;
	t_vec3				col;
	t_obj				*obj;
	t_obj				*objs;
	char				*screen_name;
	double				ln;
	double				tmin;
}						t_env;

int						expose_hook(t_env *e);
int						key_press(int keycode, t_env *e);
int						key_release(int keycode, t_env *e);
void					parse_file(t_env *e, t_list *list);
void					get_camera(t_env *e, char *info, int type);
void					get_double(t_obj *obj, char *info, int type);
void					get_objvec(t_vec3 *vec, char *info);
void					init_obj(t_obj *obj);
t_obj					*new_obj(t_obj *obj);
void					obj_push_back(t_env *e, t_obj *obj);
void					pre_init_env(t_env *e);
void					post_init_env(t_env *e);
void					put_pixel(t_env *e, int x, int y);
void					display(t_env *e);
void					get_lighting(t_env *e, t_vec3 *col, t_vec3 *pos);
t_obj					*inter_object(t_env *e, t_vec3 *ro, t_vec3 *rd, \
							double *dmin);
double					inter_shadows(t_env *e, t_vec3 *pos, t_vec3 *lpos);
t_vec3					lambert(t_obj *obj, t_vec3 *nor, t_vec3 *pos);
double					phong(t_obj *obj, t_vec3 *nor, t_vec3 *rd, t_vec3 *pos);
int						red_cross(t_env *env);
int						open_file(t_env *env, char *filename);
void 					exit_w_error(char *msg);
void					get_color(char *content, t_obj *obj);

#endif
