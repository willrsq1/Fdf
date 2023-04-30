/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:48 by wruet-su          #+#    #+#             */
/*   Updated: 2023/03/10 20:15:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_fdf_create_matrix(t_fdf *map)
{
	map->line_number = -1;
	map->max_lenght = 0;
	ft_fdf_get_height(map);
	map->fd = open(map->file_path, O_RDONLY);
	if (map->fd < 0)
		ft_fdf_free_exit("open failed (create_matrix())", map);
	map->matrix = malloc(sizeof(int **) * map->height);
	map->colors = malloc(sizeof(char ***) * map->height);
	map->lenght_tab = malloc(sizeof(int) * map->height);
	if (map->matrix == NULL || !map->colors || !map->lenght_tab)
		ft_fdf_free_exit("matrix malloc failed (create_matrix())", map);
	while (++map->line_number < map->height)
	{
		map->line = get_next_line(map->fd);
		map->lenght = ft_fdf_lenght_of_this_line(map->line, map);
		map->lenght_tab[map->line_number] = map->lenght;
		map->matrix[map->line_number] = malloc(sizeof(int) * map->lenght);
		map->colors[map->line_number] = malloc(sizeof(char **) * map->lenght);
		if (!map->matrix[map->line_number] || !map->colors[map->line_number])
			ft_fdf_free_exit("mallox (create_matrix())", map);
		free(map->line);
	}
	close(map->fd);
	ft_fill_the_matrix(map);
}

void	ft_fill_the_matrix(t_fdf *map)
{
	map->line_number = -1;
	map->fd = open(map->file_path, O_RDONLY);
	if (map->fd < 0)
		ft_fdf_free_exit("third open failed (fill_the_matrix())", map);
	while (++map->line_number < map->height)
	{
		map->line = get_next_line(map->fd);
		map->lenght = ft_fdf_lenght_of_this_line(map->line, map);
		ft_fill_a_line(map);
		free(map->line);
	}
	close(map->fd);
}

void	ft_fill_a_line(t_fdf *map)
{
	int		i;
	char	**numbers;
	char	*line;

	line = map->line;
	i = -1;
	numbers = ft_split(line, ' ');
	if (numbers == NULL)
		ft_fdf_free_exit("char * malloc failed (fill_a_line())", map);
	while (++i < map->lenght && numbers[i][0] != '\0')
	{
		map->matrix[map->line_number][i] = ft_atoi(numbers[i]);
		line = ft_atoi_color(numbers[i]);
		map->colors[map->line_number][i] = line;
		if (numbers[i])
			free(numbers[i]);
	}
	if (numbers)
		free(numbers);
}

void	ft_fdf_get_height(t_fdf *map)
{
	char	*line;
	int		write_value;

	map->height = 0;
	map->fd = open(map->file_path, O_RDONLY);
	if (map->fd < 0)
	{
		free(map);
		write_value = write(2, "OPEN ERROR\n", 11);
		exit(0);
	}
	line = get_next_line(map->fd);
	if (!line)
		ft_fdf_free_exit("error first line, (get_height())", map);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(map->fd);
	}
	if (line)
		free(line);
	close(map->fd);
	if (write_value == 1)
		write_value = 1;
}

int	ft_fdf_lenght_of_this_line(char *line, t_fdf *map)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (i > map->max_lenght)
		map->max_lenght = i;
	return (i);
}
