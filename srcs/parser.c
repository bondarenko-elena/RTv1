/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:34:49 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 15:06:07 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				convert_obj_type(t_env *env, char *check)
{
	if (ft_strstr(check, "plane"))
		return (0);
	else if (ft_strstr(check, "sphere"))
		return (1);
	else if (ft_strstr(check, "cylinder"))
		return (2);
	else if (ft_strstr(check, "cone"))
		return (3);
	else if (ft_strstr(check, "light"))
	{
		env->ln += 1.0;
		return (4);
	}
	return (-1);
}

void			get_obj_content(t_list *list, t_obj *obj)
{
	char		*tmp;

	if (ft_strstr(list->content, "color"))
		get_color((tmp = ft_strconc(list->content, '(', ')')), obj);
	else if (ft_strstr(list->content, "size"))
		get_double(obj, (tmp = ft_strconc(list->content, '(', ')')), 0);
	else if (ft_strstr(list->content, "pos"))
		get_vector(&obj->pos, (tmp = ft_strconc(list->content, '(', ')')));
	else if (ft_strstr(list->content, "rot"))
		get_vector(&obj->rot, (tmp = ft_strconc(list->content, '(', ')')));
	else if (ft_strstr(list->content, "power"))
		get_double(obj, (tmp = ft_strconc(list->content, '(', ')')), 1);
}

void			parse_file(t_env *env, t_list *list)
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
