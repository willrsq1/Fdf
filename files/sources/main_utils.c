/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:59 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 20:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	main_init(t_fdf *map)
{
	map->scale = 200;
	map->angle = 1.65;
	map->win_w = 1200;
	map->win_height = 900;
	map->theta = 0.782993;
	ft_fdf_create_matrix(map);
	ft_convert_matrix_to_structs(map);
	map->multiplicator = 500 / (map->height + map->max_lenght) + 1;
	map->height_coef = map->multiplicator + 1;
	if (map->point->color != 0)
		map->height_coef = 0;
	ft_do_multiplicator(map);
}

int	ft_fdf_free_exit(char *message, t_fdf *map)
{
	int	return_value_of_write;

	if (message)
		return_value_of_write = write(1, message, ft_fdf_strlen(message));
	if (map->point)
		ft_fdf_free_points(map->point);
	if (map->matrix)
		ft_fdf_free_matrix(map->matrix, map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	if (map->mlx)
		free(map->mlx);
	if (map->img)
		free(map->img);
	if (map->colors || map->lenght_tab)
		ft_fdf_free_colors(map);
	if (map)
		free(map);
	exit(0);
	if (return_value_of_write == 27)
		return_value_of_write = -1;
	return (0);
}

void	ft_fdf_free_colors(t_fdf *map)
{
	int		i;
	int		j;
	char	***colors;

	i = -1;
	if (map->colors)
	{
		colors = map->colors;
		while (++i < map->height)
		{
			j = -1;
			while (++j < map->lenght_tab[i])
				free(colors[i][j]);
			free(colors[i]);
		}
		free(colors);
	}
	if (map->lenght_tab)
		free(map->lenght_tab);
}

void	ft_fdf_free_matrix(int **matrix, t_fdf *map)
{
	int	i;

	i = -1;
	if (matrix)
	{
		while (++i < map->height)
			free(matrix[i]);
	}
	free(matrix);
}

void	ft_fdf_free_points(t_fdfpt *point)
{
	t_fdfpt	*temp;

	while (point->next)
	{
		temp = point->next;
		free (point);
		point = temp;
	}
	free (point);
}
