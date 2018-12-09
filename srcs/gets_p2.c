/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:05:09 by olbondar          #+#    #+#             */
/*   Updated: 2018/12/08 16:05:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void			get_double(t_obj *obj, char *content, int check)
{
	if (content)
	{
		if (check == 0)
			obj->size = ft_clamp(ft_atoi(content), 1.0, 10000);
		else if (check == 1)
			obj->power = ft_clamp(ft_atoi(content), 0.0, 99.0);
	}
	free(content);
}

void			get_color(char *content, t_obj *obj)
{
	char		**content_splitted;

	content_splitted = NULL;
	if (content)
	{
		content_splitted = ft_strsplit(content, ' ');
		obj->color.x = ft_clamp(ft_atoi(content_splitted[0]) / 256.0, 0.0, 1.0);
		obj->color.y = ft_clamp(ft_atoi(content_splitted[1]) / 256.0, 0.0, 1.0);
		obj->color.z = ft_clamp(ft_atoi(content_splitted[2]) / 256.0, 0.0, 1.0);
		free_tab_char(content_splitted, 2);
		free(content);
	}
}

void			get_vector(t_vector *vec, char *content)
{
	char		**content_splitted;

	content_splitted = NULL;
	if (content)
	{
		content_splitted = ft_strsplit(content, ' ');
		vec->x = ft_atoi(content_splitted[0]);
		vec->y = ft_atoi(content_splitted[1]);
		vec->z = ft_atoi(content_splitted[2]);
		free_tab_char(content_splitted, 2);
		free(content);
	}
}

void			get_camera(t_env *env, char *content, int check)
{
	char		**content_splitted;

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

void			get_render(t_env *env, char *content)
{
	char		**content_splitted;

	content_splitted = ft_strsplit(content, ' ');
	env->screen_width = ft_clamp(ft_atoi(content_splitted[0]), 10, 5000);
	env->screen_height = ft_clamp(ft_atoi(content_splitted[1]), 10, 5000);
	free_tab_char(content_splitted, 1);
	free(content);
}
