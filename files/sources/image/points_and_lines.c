/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_and_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:39 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 20:27:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_connect_the_points(t_data_img *data, t_fdf *map)
{
	t_fdfpt	*point;
	t_coord	*coords;

	point = map->point;
	while (point->next)
	{
		if (point->line == point->next->line)
		{
			coords = ft_coords(point, point->next, map);
			draw(coords, data);
		}
		point = point->next;
	}
	point = map->point;
	ft_connect_verticaly(point, data, map);
}

void	ft_data_point_change(t_fdfpt *point, t_fdf *map)
{
	float	x;
	float	y;

	x = ((point->first_abs - map->scale) * map->multiplicator) + map->scale;
	y = ((point->first_ord - map->scale) * map->multiplicator) + map->scale;
	point->abs = x * cos(map->theta) - y * sin(map->theta);
	point->ord = x * sin(map->theta) + y * cos(map->theta);
	point->ord -= point->height * map->height_coef;
	if (map->img->max_height < point->height)
		map->img->max_height = point->height;
	point->abs = (point->abs / cos(map->angle)) * cos(map->angle + 0.1);
	point->ord = (point->ord / sin(map->angle)) * sin(map->angle + 0.1);
}

void	ft_data_handling(t_fdf *map)
{
	t_fdfpt	*point;

	point = map->point;
	if (map->height_coef > 40 || map->height_coef < -40)
	{
		if (map->height_coef < -40)
			map->height_coef = -40;
		else
			map->height_coef = 40;
		map->fd = write(1, "You've reached max height.\n", 28);
	}
	while (point)
	{
		ft_data_point_change(point, map);
		point = point->next;
	}
}

void	ft_do_multiplicator(t_fdf *map)
{
	t_fdfpt	*point;

	point = map->point;
	while (point)
	{
		point->first_abs = point->abs;
		point->first_ord = point->ord;
		point->first_height = point->height;
		point = point->next;
	}
}

void	ft_connect_verticaly(t_fdfpt *point, t_data_img *data, t_fdf *map)
{
	t_fdfpt	*temp;
	t_coord	*coords;

	while (point->next)
	{
		temp = point->next;
		while (temp->column != point->column && temp->next)
			temp = temp->next;
		if (temp->next)
		{
			coords = ft_coords(point, temp, map);
			draw(coords, data);
		}
		else if (temp->column == point->column)
		{
			coords = ft_coords(point, temp, map);
			draw(coords, data);
		}
		point = point->next;
	}
}
