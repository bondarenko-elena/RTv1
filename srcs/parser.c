#include "../includes/rtv1.h"

int		typeconvert(t_env *e, char *stype)
{
	if (strstr(stype, "plane"))
		return (0);
	else if (strstr(stype, "sphere"))
		return (1);
	else if (strstr(stype, "cylinder"))
		return (2);
	else if (strstr(stype, "cone"))
		return (3);
	else if (strstr(stype, "light"))
	{
		e->ln += 1.0;
		return (4);
	}
	return (-1);
}

void	get_scene(t_env *e, t_list *list)
{
	while (list && !strstr(list->content, "{"))
		list = list->next;
	while (list && !strstr(list->content, "}"))
	{
		if (strstr(list->content, "name"))
			get_name(e, ft_strconc(list->content, '(', ')'));
		else if (strstr(list->content, "cam_pos"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 0);
		else if (strstr(list->content, "cam_dir"))
			get_camera(e, ft_strconc(list->content, '(', ')'), 1);
		else if (strstr(list->content, "render"))
			get_render(e, ft_strconc(list->content, '(', ')'));
		list = list->next;
	}
}

void	get_obj_info(t_list *list, t_obj *obj)
{
	t_vec3	vec;

	if (strstr(list->content, "color"))
		get_color(obj, ft_strconc(list->content, '(', ')'));
	else if (strstr(list->content, "size"))
		get_double(obj, ft_strconc(list->content, '(', ')'), 0);
	else if (strstr(list->content, "pos"))
	{
		get_objvec(&vec, ft_strconc(list->content, '(', ')'));
		obj->pos = vec;
	}
	else if (strstr(list->content, "rot"))
	{
		get_objvec(&vec, ft_strconc(list->content, '(', ')'));
		obj->rot = vec;
	}
	else if (strstr(list->content, "power"))
		get_double(obj, ft_strconc(list->content, '(', ')'), 1);
}

void	get_content(t_env *e, t_list *list)
{
	t_obj	obj;

	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "object"))
		{
			init_obj(&obj);
			obj.type = typeconvert(e, ft_strconc(list->content, '(', ')'));
			while (list && !ft_strstr(list->content, "{"))
				list = list->next;
			while (list && !ft_strstr(list->content, "}"))
			{
				get_obj_info(list, &obj);
				list = list->next;
			}
			obj_push_back(e, &obj);
		}
		list = list->next;
	}
}

void	parse_file(t_env *e, t_list *list)
{
	while (list)
	{
		if (ft_strstr(list->content, "scene"))
			get_scene(e, list);
		else if (ft_strstr(list->content, "content"))
			get_content(e, list);
		list = list->next;
	}
}
