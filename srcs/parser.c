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

void	get_scene(t_env *e, t_list *list)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "name"))
			get_name(e, ft_strconc(list->content, '(', ')'));
		else if (ft_strstr(list->content, "cam_pos"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 0);
		else if (ft_strstr(list->content, "cam_dir"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 1);
		else if (ft_strstr(list->content, "render"))
			get_render(e, ft_strconc(list->content, '(', ')'));
		list = list->next;
	}
}

void	get_obj_info(t_list *list, t_obj *obj)
{
	t_vec3	vec;

	if (ft_strstr(list->content, "color"))
		get_color(obj, ft_strconc(list->content, '(', ')'));
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
