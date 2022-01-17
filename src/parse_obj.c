/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:26:56 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 19:30:27 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_data *data, char *strv[])
{
	t_obj	*obj;
	t_plane	*pl;
	int		isform;

	// isform = 
	if (!isform)
		ft_error("Invalid 'plane' description");
	obj = (t_obj *)malloc(sizeof(t_obj));
	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!obj || !pl)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str_to_vec(&pl->center, strv[1]);
	str_to_vec(&pl->normal, strv[2]);
	obj->type = TYPE_PL;
	obj->info = pl;
	str_to_color(&obj->color, strv[3]);
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_sphere(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_sphere	*sp;
	int		isform;

	// isform = 
	if (!isform)
		ft_error("Invalid 'sphere' description");
	obj = (t_obj *)malloc(sizeof(t_obj));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !sp)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	str_to_vec(&sp->center, strv[1]);
	sp->diameter = atof(strv[2]);
	sp->radius = sp->diameter / 2;
	obj->type = TYPE_SP;
	obj->info = sp;
	str_to_color(&obj->color, strv[3]);
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	parse_cylinder(t_data *data, char *strv[])
{
	t_obj		*obj;
	t_cylinder	*cy;
	int		isform;

	// isform = 
	if (!isform)
		ft_error("Invalid 'cylinder' description");
	obj = (t_obj *)malloc(sizeof(t_obj));
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!obj || !cy)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	cy->center.i  = atof(strtok(strv[1], ","));
	cy->center.j  = atof(strtok(NULL, ","));
	cy->center.k  = atof(strtok(NULL, ","));
	cy->normal.i  = atof(strtok(strv[2], ","));
	cy->normal.j  = atof(strtok(NULL, ","));
	cy->normal.k  = atof(strtok(NULL, ","));
	cy->diameter = atof(strv[3]);
	cy->height = atof(strv[4]);
	cy->radius = cy->diameter / 2;
	obj->type = TYPE_CY;
	obj->info = cy;
	str_to_color(&obj->color, strv[5]);
	obj->next = NULL;
	add_object_front(&data->first_obj, obj);
}

void	add_object_front(t_obj **first_obj, t_obj *new)
{
	if (*first_obj)
		new->next = *first_obj;
	*first_obj = new;
}
