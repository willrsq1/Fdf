/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:56 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 20:13:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_convert_matrix_to_structs(t_fdf *map)
{
	int		i;
	int		y;
	int		lenght;
	t_fdfpt	*point;

	i = -1;
	map->fd = open(map->file_path, O_RDONLY);
	point = ft_initiate_data_point(map);
	map->point = point;
	while (++i < map->height)
	{
		map->line = get_next_line(map->fd);
		lenght = ft_fdf_lenght_of_this_line(map->line, map);
		if (map->line)
			free(map->line);
		y = -1;
		if (i == 0)
			y = 0;
		while (++y < lenght)
			point = ft_add_point_struct(point, i, y, map);
	}
	point->next = NULL;
	close(map->fd);
}

t_fdfpt	*ft_initiate_data_point(t_fdf *map)
{
	t_fdfpt	*point;

	point = malloc(sizeof(t_fdfpt));
	if (!point)
		ft_fdf_free_exit("ft_initiate data point", map);
	point->abs = 0 + map->scale;
	point->ord = 0 + map->scale;
	point->height = map->matrix[0][0];
	if (map->colors[0][0])
		point->color = ft_putnbr_x(map->colors[0][0]);
	else
		point->color = 0;
	point->line = 0;
	point->column = 0;
	point->previous = NULL;
	point->next = NULL;
	return (point);
}

t_fdfpt	*ft_add_point_struct(t_fdfpt *point, int i, int y, t_fdf *map)
{
	t_fdfpt	*temp;

	temp = malloc(sizeof(t_fdfpt));
	if (!temp)
		ft_fdf_free_exit("ft_add_point_struct", map);
	temp->abs = y + map->scale;
	temp->ord = i + map->scale;
	temp->height = map->matrix[i][y];
	if (map->colors[i][y])
		temp->color = ft_putnbr_x(map->colors[i][y]);
	else
		temp->color = 0;
	temp->line = i;
	temp->column = y;
	temp->next = NULL;
	temp->previous = point;
	point->next = temp;
	return (temp);
}
