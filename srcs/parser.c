#include "../includes/rtv1.h"

int		convert_obj_type(t_env *e, char *stype)
{
	if (ft_strstr(stype, "plane"))
		return (0);
	else if (ft_strstr(stype, "sphere"))
		return (1);
	else if (ft_strstr(stype, "cylinder"))	
		return (2);
	else if (ft_strstr(stype, "cone"))
		return (3);
	else if (ft_strstr(stype, "light"))
	{
		e->ln += 1.0;
		return (4);
	}
	return (-1);
}

////////////////////////////////////////////////////////////////////////////////////

void	get_vector(t_vector *vec, char *content)
{
	char	**content_splitted;

	content_splitted = NULL;
	if (content)
	{
		content_splitted = ft_strsplit(content, ' ');
		vec->x = ft_atoi(content_splitted[0]);
		vec->y = ft_atoi(content_splitted[1]);
		vec->z = ft_atoi(content_splitted[2]);
		free_tab_char(content_splitted, 2);
	}
}

void	get_double(t_obj *obj, char *content, int check)
{
	if (content)
	{
		if (check == 0)
			obj->size = ft_clamp(ft_atoi(content), 1.0, 50000);
		else if (check == 1)
			obj->power = ft_clamp(ft_atoi(content), 0.0, 99.0);
	}
}

void	get_color(char *content, t_obj *obj)
{
	char **content_splitted;

	content_splitted = NULL;
	if (content)
	{
		content_splitted = ft_strsplit(content, ' ');
		obj->color.x = ft_clamp(ft_atoi(content_splitted[0]) / 256.0, 0.0, 1.0);
		obj->color.y = ft_clamp(ft_atoi(content_splitted[1]) / 256.0, 0.0, 1.0);
		obj->color.z = ft_clamp(ft_atoi(content_splitted[2]) / 256.0, 0.0, 1.0);
		free_tab_char(content_splitted, 2);
	}
}

void	get_obj_info(t_list *list, t_obj *obj)
{
	t_vector	vec;
	char 		*tmp;

	if (ft_strstr(list->content, "color"))
	{
		tmp = ft_strconc(list->content, '(', ')');
		get_color(tmp, obj);
		free(tmp);
	}
	else if (ft_strstr(list->content, "size"))
	{
		tmp = ft_strconc(list->content, '(', ')');
		get_double(obj, tmp, 0);
		free(tmp);
	}
	else if (ft_strstr(list->content, "pos"))
	{
		tmp = ft_strconc(list->content, '(', ')');
		get_vector(&vec, tmp);
		obj->pos = vec;
		free(tmp);
	}
	else if (ft_strstr(list->content, "rot"))
	{
		tmp = ft_strconc(list->content, '(', ')');
		get_vector(&vec, tmp);
		obj->rot = vec;
		free(tmp);
	}
	else if (ft_strstr(list->content, "power"))
	{
		tmp = ft_strconc(list->content, '(', ')');
		get_double(obj, tmp, 1);
		free(tmp);
	}
}

void	get_content(t_env *env, t_list *list)
{
	t_obj	obj;
	char 	*tmp;

	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "object"))
		{
			init_obj(&obj);
			tmp = ft_strconc(list->content, '(', ')');
			obj.type = convert_obj_type(env, tmp);
			free(tmp);
			while (list && !ft_strstr(list->content, "{"))
				list = list->next;
			while (list && !ft_strstr(list->content, "}"))
			{
				get_obj_info(list, &obj);
				list = list->next;
			}
			obj_push_back(env, &obj);
		}
		list = list->next;
	}
}

void	get_camera(t_env *env, char *content, int check)
{
	char	**content_splitted;

	content_splitted = NULL;
	if (content)
	{
		content_splitted = ft_strsplit(content, ' ');
		if (check == 0)
		{
			env->cam_pos.x = ft_atoi(content_splitted[0]);
			env->cam_pos.y = ft_atoi(content_splitted[1]);
			env->cam_pos.z = ft_atoi(content_splitted[2]);
		}
		else if (check == 1)
		{
			env->cam_dir.x = ft_atoi(content_splitted[0]);
			env->cam_dir.y = ft_atoi(content_splitted[1]);
			env->cam_dir.z = ft_atoi(content_splitted[2]);
		}
	}
	free_tab_char(content_splitted, 2);
	free(content);
}

void	get_render(t_env *env, char *content)
{
	char **content_splitted;

	content_splitted = ft_strsplit(content, ' ');
	env->screen_width = ft_clamp(ft_atoi(content_splitted[0]), 10, 5000);
	env->screen_height = ft_clamp(ft_atoi(content_splitted[1]), 10, 5000);
	free_tab_char(content_splitted, 1);
	free(content);
}

void get_name(t_env *env, char *content)
{
	char *tmp;

	if ((tmp = ft_strconc(content, '(', ')')))
	{
		env->screen_name = ft_strdup(tmp);
		free(tmp);
	}
}

void	get_scene(t_env *env, t_list *list)
{
	char *tmp;

	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "name"))
			get_name(env, list->content);
		else if (ft_strstr(list->content, "cam_pos"))
		{
			if ((tmp = ft_strconc(list->content, '(', ')')))
				get_camera(env, list->content, 0);
		}
		else if (ft_strstr(list->content, "cam_dir"))
		{
			if ((tmp = ft_strconc(list->content, '(', ')')))
				get_camera(env, tmp, 1);
		}
		else if (ft_strstr(list->content, "render"))
		{
			if ((tmp = ft_strconc(list->content, '(', ')')))
				get_render(env, tmp);
		}
		list = list->next;
	}
}

void	parse_file(t_env *env, t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strstr(tmp->content, "scene"))
			get_scene(env, tmp);
		else if (ft_strstr(tmp->content, "content"))
			get_content(env, tmp);
		tmp = tmp->next;
	}
}
