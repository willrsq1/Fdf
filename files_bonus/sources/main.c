/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:57:10 by wruet-su          #+#    #+#             */
/*   Updated: 2023/03/10 20:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*map;

	map = malloc(sizeof(t_fdf));
	if (!map)
		ft_fdf_free_exit("map or fdf malloc failed", map);
	if (argc == 1)
		ft_fdf_strlcpy(map->file_path, "files/test_maps/arbesa.fdf", 100);
	else if (argc == 2)
	{
		map->line = ft_fdf_strjoin("files/test_maps/", argv[1]);
		ft_fdf_strlcpy(map->file_path, map->line, 100);
		free(map->line);
	}
	else
		ft_fdf_free_exit("Too many args", map);
	map->argv = &argv[1];
	main_init(map);
	mlx_main(map);
	ft_fdf_free_exit("end of program", map);
	return (0);
}

int	ft_close(t_fdf *map)
{
	ft_fdf_free_exit("closeeeed", map);
	return (0);
}

void	mlx_main(t_fdf *map)
{
	void		*mlx_win;
	t_data_img	*i;

	map->mlx = mlx_init();
	mlx_win = mlx_new_window(map->mlx, map->win_w, map->win_height, *map->argv);
	i = malloc(sizeof(t_data_img));
	i->img = mlx_new_image(map->mlx, map->win_w, map->win_height);
	if (!map->mlx || !mlx_win || !i || !i->img)
		ft_fdf_free_exit("mlx_main", map);
	map->img = i;
	map->mlx_win = mlx_win;
	i->win_width = map->win_w;
	i->win_height = map->win_height;
	i->addr = mlx_get_data_addr(i->img, &i->bpp, &i->line_length, &i->endian);
	i->color = map->point->color;
	i->max_height = -214748393;
	ft_data_handling(map);
	ft_center(map);
	ft_connect_the_points(i, map);
	mlx_put_image_to_window(map->mlx, mlx_win, i->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img->img);
	mlx_hook(mlx_win, 2, 1L << 0, ft_key_hook, map);
	mlx_hook(mlx_win, 17, 1L << 17, ft_close, map);
	mlx_loop(map->mlx);
}
