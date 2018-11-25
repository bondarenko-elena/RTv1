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

void	get_double(t_obj *obj, char *info, int type)
{
	if (info)
	{
		if (type == 0)
			obj->size = ft_clamp(ft_atoi(info), 1.0, 50000);
		else if (type == 1)
			obj->power = ft_clamp(ft_atoi(info), 0.0, 99.0);
	}
	else
		ft_putstr_fd("RTv1: Error while loading an object size\n", 2);
}

void	get_color(char *content, t_obj *obj)
{
	char **content_splitted;

	content_splitted = ft_strsplit(content, ' ');
	if (content)
	{
		obj->color.x = ft_clamp(ft_atoi(content_splitted[0]) / 256.0, 0.0, 1.0);
		obj->color.y = ft_clamp(ft_atoi(content_splitted[1]) / 256.0, 0.0, 1.0);
		obj->color.z = ft_clamp(ft_atoi(content_splitted[2]) / 256.0, 0.0, 1.0);
	}
	else
		obj->color = (t_vec3){138, 43, 226};
}

void	get_obj_info(t_list *list, t_obj *obj)
{
	t_vec3	vec;

	if (ft_strstr(list->content, "color"))
		get_color(ft_strconc(list->content, '(', ')'), obj);
	else if (ft_strstr(list->content, "size"))
		get_double(obj, ft_strconc(list->content, '(', ')'), 0);
	else if (ft_strstr(list->content, "pos"))
	{
		get_objvec(&vec, ft_strconc(list->content, '(', ')'));
		obj->pos = vec;
	}
	else if (ft_strstr(list->content, "rot"))
	{
		get_objvec(&vec, ft_strconc(list->content, '(', ')'));
		obj->rot = vec;
	}
	else if (ft_strstr(list->content, "power"))
		get_double(obj, ft_strconc(list->content, '(', ')'), 1);
}

void	get_content(t_env *env, t_list *list)
{
	t_obj	obj;

	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "object"))
		{
			init_obj(&obj);
			obj.type = convert_obj_type(env, ft_strconc(list->content, '(', ')'));
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
}

void	get_scene(t_env *env, t_list *list)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "name"))
		{
			if (ft_strconc(list->content, '(', ')'))
				env->screen_name = ft_strdup(ft_strconc(list->content, '(', ')'));
		}
		else if (ft_strstr(list->content, "cam_pos"))
			get_camera(env, ft_strconc(list->content, '(', ')'), 0);
		else if (ft_strstr(list->content, "cam_dir"))
			get_camera(env, ft_strconc(list->content, '(', ')'), 1);
		else if (ft_strstr(list->content, "render"))
		{
			if (ft_strconc(list->content, '(', ')'))
			{
				env->screen_width = ft_clamp(ft_atoi(ft_strsplit(ft_strconc(list->content, '(', ')'), ' ')[0]), 10, 5000);
				env->screen_height = ft_clamp(ft_atoi(ft_strsplit(ft_strconc(list->content, '(', ')'), ' ')[1]), 10, 5000);
			}
		}
		list = list->next;
	}
}

void	parse_file(t_env *env, t_list *list)
{
	while (list)
	{
		if (ft_strstr(list->content, "scene"))
			get_scene(env, list);
		else if (ft_strstr(list->content, "content"))
			get_content(env, list);
		list = list->next;
	}
}
