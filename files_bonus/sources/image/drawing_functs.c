/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 20:38:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_coord	*ft_coords(t_fdfpt *point_a, t_fdfpt *point_b, t_fdf *map)
{
	t_coord	*coords;

	coords = malloc(sizeof(t_coord));
	if (!coords)
		ft_fdf_free_exit("ft_coords", map);
	coords->x0 = point_a->abs;
	coords->y0 = point_a->ord;
	coords->x1 = point_b->abs;
	coords->y1 = point_b->ord;
	coords->height_0 = point_a->height;
	coords->height_1 = point_b->height;
	coords->color = point_a->color;
	if (point_b->height > point_a->height)
		coords->color = point_b->color;
	return (coords);
}

int	ft_get_color(t_coord *coords, float max_height, int color)
{
	if (coords->color != 0)
		return (coords->color);
	if (coords->height_1 == max_height)
		return (0xff0000);
	if (coords->height_0 > 0 || coords->height_1 > 0)
		return (0xe77272);
	else
		return (0xffffff);
	if (color == 2)
		color = 2;
}

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && y < data->win_height && x < data->win_width)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw(t_coord *coords, t_data_img *data)
{
	t_draw	plot;

	plot.x0 = coords->x0;
	plot.y0 = coords->y0;
	plot.x1 = coords->x1;
	plot.y1 = coords->y1;
	plot.dx = abs(plot.x1 - plot.x0);
	plot.dy = -abs(plot.y1 - plot.y0);
	if (plot.x0 < plot.x1)
		plot.sx = 1;
	else
		plot.sx = -1;
	if (plot.y0 < plot.y1)
		plot.sy = 1;
	else
		plot.sy = -1;
	plot.err = plot.dx + plot.dy;
	ft_do_draw_loop(data, coords, plot);
}

void	ft_do_draw_loop(t_data_img *data, t_coord *coords, t_draw plot)
{
	int	color;

	color = 0x0000ff;
	while (1)
	{
		color = ft_get_color(coords, data->max_height, color);
		my_mlx_pixel_put(data, plot.x0, plot.y0, color);
		if (plot.x0 == plot.x1 && plot.y0 == plot.y1)
			break ;
		plot.e2 = 2 * plot.err;
		if (plot.e2 >= plot.dy)
		{
			plot.err = plot.dy + plot.err;
			plot.x0 += plot.sx;
		}
		if (plot.e2 <= plot.dx)
		{
			plot.err += plot.dx;
			plot.y0 += plot.sy;
		}
	}
	free (coords);
}
