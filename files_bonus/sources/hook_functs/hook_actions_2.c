/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_actions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:26 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 20:19:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_rotate_along_y(t_fdf *map)
{
	t_fdfpt	*point;

	if (map->angle > 1.65)
		map->angle = 1.5;
	else
	{
		point = map->point;
		while (point)
		{
			point->abs = point->abs / cos(map->angle);
			point->abs = point->abs * cos(map->angle + 0.001);
			point->ord = point->ord / sin(map->angle);
			point->ord = point->ord * sin(map->angle + 0.001);
			point = point->next;
		}
		map->angle += 0.001;
		ft_center(map);
	}
}

void	ft_rotate_along_y_neg(t_fdf *map)
{
	t_fdfpt	*point;

	if (map->angle < 1.5)
		map->angle = 1.65;
	else
	{
		point = map->point;
		while (point)
		{
			point->abs = point->abs / cos(map->angle);
			point->abs = point->abs * cos(map->angle - 0.001);
			point->ord = point->ord / sin(map->angle);
			point->ord = point->ord * sin(map->angle - 0.001);
			point = point->next;
		}
		map->angle -= 0.001;
		ft_center(map);
	}
}

void	ft_change_file(t_fdf *map)
{
	map->line = ft_calloc(100, 1);
	if (!map->line)
		ft_fdf_free_exit("in hook_actions_2/ft_change_file", map);
	map->fd = write(1, "Enter file name here : ", 24);
	map->fd = read(0, map->line, 10);
	if (map->fd == -1)
		return ;
	if (ft_fdf_stricmp("10-70", map->line, 5) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/10-70.fdf", 100);
	else if (ft_fdf_stricmp("20-60", map->line, 5) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/20-60.fdf", 100);
	else
		ft_change_file_p2(map);
	free(map->line);
	ft_fdf_free_matrix(map->matrix, map);
	ft_fdf_free_points(map->point);
	ft_fdf_free_colors(map);
	ft_fdf_create_matrix(map);
	ft_convert_matrix_to_structs(map);
	ft_do_multiplicator(map);
	ft_reset_view(map);
}

void	ft_change_file_p2(t_fdf *map)
{
	if (ft_fdf_stricmp("arbesa", map->line, 6) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/arbesa.fdf", 100);
	else if (ft_fdf_stricmp("42", map->line, 2) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/42.fdf", 100);
	else if (ft_fdf_stricmp("50-4", map->line, 4) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/50-4.fdf", 100);
	else if (ft_fdf_stricmp("100-6", map->line, 5) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/100-6.fdf", 100);
	else if (ft_fdf_stricmp("basictest", map->line, 9) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/basictest.fdf", 100);
	else if (ft_fdf_stricmp("elem-col", map->line, 8) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/elem-col.fdf", 100);
	else if (ft_fdf_stricmp("elem-fract", map->line, 10) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/elem-fract.fdf", 100);
	else if (ft_fdf_stricmp("elem\n", map->line, 5) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/elem.fdf", 100);
	else if (ft_fdf_stricmp("elem2\n", map->line, 6) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/elem2.fdf", 100);
	else
		ft_change_file_p3(map);
}

void	ft_change_file_p3(t_fdf *map)
{
	if (ft_fdf_stricmp("julia", map->line, 5) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/julia.fdf", 100);
	else if (ft_fdf_stricmp("mars", map->line, 4) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/mars.fdf", 100);
	else if (ft_fdf_stricmp("penteneg", map->line, 8) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/pentenegpos.fdf", 100);
	else if (ft_fdf_stricmp("plat", map->line, 4) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/plat.fdf", 100);
	else if (ft_fdf_stricmp("pnp_flat", map->line, 8) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/pnp_flat.fdf", 100);
	else if (ft_fdf_stricmp("pylone", map->line, 6) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/pylone.fdf", 100);
	else if (ft_fdf_stricmp("pyra\n", map->line, 4) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/pyra.fdf", 100);
	else if (ft_fdf_stricmp("pyramide", map->line, 8) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/pyramide.fdf", 100);
	else if (ft_fdf_stricmp("t1\n", map->line, 2) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/t1.fdf", 100);
	else if (ft_fdf_stricmp("t2\n", map->line, 4) == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/t2.fdf", 100);
	else
		map->fd = write(1, "Bad imput\n", 10);
}
