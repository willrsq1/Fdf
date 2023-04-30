/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:33 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 10:30:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_key_hook(int key, t_fdf *map)
{
	if (key == ESC)
		ft_fdf_free_exit("esc was pressed\n", map);
	else if (key == 96 || key == 178)
		ft_change_file(map);
	else if (key == UP_ARROW || key == DOWN_ARROW || key == LEFT_ARROW || \
		key == RIGHT_ARROW)
		ft_move(map, key);
	else if (key == F)
		ft_rotate_along_y(map);
	else if (key == PLUS || key == MINUS)
		ft_change_zoom(map, key);
	else if (key == U || key == D)
		ft_change_height(map, key);
	else if (key == 32)
		ft_reset_view(map);
	else if (key == TWO_DIM)
		ft_view_two_dim(map);
	else if (key == C)
		ft_center(map);
	else if (key == 112 || key == 109)
		ft_translate_z(map, key);
	else if (key == 103)
		ft_rotate_along_y_neg(map);
	ft_expose_hook(map);
	return (0);
}

void	ft_expose_hook(t_fdf *map)
{
	t_data_img	*i;

	i = map->img;
	i->img = mlx_new_image(map->mlx, map->win_w, map->win_height);
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_length, &i->endian);
	ft_connect_the_points(map->img, map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img->img);
}

void	ft_center(t_fdf *map)
{
	t_fdfpt	*point;
	int		center_column;
	int		center_line;
	int		diff_x;
	int		diff_y;

	point = map->point;
	center_column = map->max_lenght / 2;
	center_line = map->height / 2;
	while (point && !(point->column == center_column && \
		point->line == center_line))
		point = point->next;
	diff_x = (point->abs - (map->win_w / 2));
	diff_y = (point->ord - (map->win_height / 2));
	point = map->point;
	while (point)
	{
		point->abs -= diff_x;
		point->ord -= diff_y;
		point = point->next;
	}
}
