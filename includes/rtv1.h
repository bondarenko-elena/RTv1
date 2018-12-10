/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:13:39 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 17:13:40 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

// debian --> # define ESC 65307
# define ESC 53
# define FOV 2.0
# define GAMMA 1.0
# define HEIGHT 900
# define WIDTH 1680

typedef struct		s_obj
{
	int				type;
	t_vector		pos;
	t_vector		rot;
	t_vector		color;
	double			size;
	double			power;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_env
{
	void			*mlx_init;
	void			*window;
	char			*screen_name;
	int				screen_height;
	int				screen_width;
	t_obj			*obj;
	t_obj			*objs;
	t_vector		color;
	t_vector		cam_pos;
	t_vector		cam_dir;
	t_vector		ro;
	t_vector		rd;
	double			ln;
	double			tmin;
}					t_env;

int					convert_obj_type(t_env *env, char *type);
void				display(t_env *env);
int					expose_hook(t_env *env);
void				exit_w_error(char *msg);
void				free_tab_char(char **line, int size);
void				free_tab_list(t_list *list);
t_vector			get_obj_color(t_env *env,
						t_vector *ro, t_vector *rd, t_vector *color);
void				get_double(t_obj *obj, char *content, int check);
void				get_color(char *content, t_obj *obj);
void				get_vector(t_vector *vec, char *content);
void				get_camera(t_env *env, char *content, int check);
void				get_render(t_env *env, char *content);
void				get_content(t_env *env, t_list *list);
void				get_scene(t_env *env, t_list *list);
void				get_name(t_env *env, char *content);
double				get_shadows(t_env *env, t_vector *pos);
t_vector			get_diffuse(t_env *env, t_vector *pos, t_vector *normal);
t_vector			get_specular(t_env *env, t_vector *pos, t_vector *normal);
void				get_lighting(t_env *light_tmp,
						t_vector *col, t_vector *pos);
void				get_obj_content(t_list *list, t_obj *obj);
t_obj				*inter_object(t_env *env,
						t_vector *ro, t_vector *rd, double *dmin);
t_obj				*new_obj(t_obj *obj);
void				init_env_pre(t_env *env);
void				init_env_post(t_env *env);
double				inter_sphere(t_obj *obj, t_vector *ro, t_vector *rd);
double				inter_plane(t_obj *obj, t_vector *ro, t_vector *rd);
double				inter_cylinder(t_obj *obj, t_vector *ro, t_vector *rd);
double				inter_cone(t_obj *obj, t_vector *ro, t_vector *rd);
void				init_obj(t_obj *obj);
double				inter_shadows(t_env *env, t_vector *pos, t_vector *lam_pos);
int					key_press(int keycode, t_env *env);
t_vector			lambert(t_obj *obj, t_vector *nor, t_vector *pos);
int					main(int argc, char **argv);
void				obj_push_back(t_env *env, t_obj *obj);
int					open_file(t_env *env, char *filename);
double				phong(t_obj *obj,
						t_vector *nor, t_vector *rd, t_vector *pos);
void				parse_file(t_env *env, t_list *list);
void				put_pixel(t_env *env, int x, int y);
t_vector			ray_tracing(t_env *env, double x, double y);
int					red_cross(t_env *env);
void				set_camera(t_env *env, double x, double y);
t_vector			set_normal(t_obj *obj, t_vector *pos);
int					shadow_sphere(t_obj *obj,
						t_vector *ro, t_vector *rd, double tmin);
int					shadow_cylinder(t_obj *obj,
						t_vector *ro, t_vector *rd, double tmin);
int					shadow_cone(t_obj *obj,
						t_vector *ro, t_vector *rd, double tmin);

#endif
