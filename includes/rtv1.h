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
# define HEIGHT 1680
# define WIDTH 900

typedef struct			s_obj
{
	int					type;
	t_vector			pos;
	t_vector			rot;
	t_vector			color;
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
	t_vector			cam_pos;
	t_vector			cam_dir;
	t_vector			ro;
	t_vector			rd;
	t_vector			color;
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
void					get_vector(t_vector *vec, char *content);
void					init_obj(t_obj *obj);
t_obj					*new_obj(t_obj *obj);
void					obj_push_back(t_env *e, t_obj *obj);
void					init_env_pre(t_env *e);
void					init_env_post(t_env *e);
void					put_pixel(t_env *e, int x, int y);
void					display(t_env *e);
void					get_lighting(t_env *e, t_vector *col, t_vector *pos);
t_obj					*inter_object(t_env *e, t_vector *ro, t_vector *rd, \
							double *dmin);
double					inter_shadows(t_env *e, t_vector *pos, t_vector *lpos);
t_vector				lambert(t_obj *obj, t_vector *nor, t_vector *pos);
double					phong(t_obj *obj, t_vector *nor, t_vector *rd, t_vector *pos);
int						red_cross(t_env *env);
int						open_file(t_env *env, char *filename);
void 					exit_w_error(char *msg);
void					get_color(char *content, t_obj *obj);
void					free_tab_char(char **line, int size);
void					get_render(t_env *env, char *content);
void 					get_name(t_env *env, char *content);
void					get_scene(t_env *env, t_list *list);
void					get_content(t_env *env, t_list *list);
int						convert_obj_type(t_env *env, char *type);
void					get_obj_content(t_list *list, t_obj *obj);

#endif
