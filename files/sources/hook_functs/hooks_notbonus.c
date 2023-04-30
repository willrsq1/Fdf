/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_notbonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:26:14 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 10:26:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_key_hook_not_bonus(int key, t_fdf *map)
{
	if (key == ESC)
		ft_fdf_free_exit("esc was pressed\n", map);
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
