/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:07:00 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 16:07:01 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void			get_content(t_env *env, t_list *list)
{
	t_obj		obj;
	char		*tmp;

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
				get_obj_content(list, &obj);
				list = list->next;
			}
			obj_push_back(env, &obj);
		}
		list = list->next;
	}
}

void			get_scene(t_env *env, t_list *list)
{
	char		*tmp;

	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "name"))
			get_name(env, list->content);
		else if (ft_strstr(list->content, "cam_pos"))
		{
			if ((tmp = ft_strconc(list->content, '(', ')')))
				get_camera(env, tmp, 0);
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

void			get_name(t_env *env, char *content)
{
	char		*tmp;

	if ((tmp = ft_strconc(content, '(', ')')))
	{
		env->screen_name = ft_strdup(tmp);
		free(tmp);
	}
}
