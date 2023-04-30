/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hook_actions.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marvin <marvin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 12:32:28 by marvin			#+#	#+#			 */
/*   Updated: 2023/03/10 12:32:29 by marvin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_translate_z(t_fdf *map, int key)
{
	if (key == 112)
		map->theta += 0.05;
	if (key == 109)
		map->theta -= 0.05;
	ft_data_handling(map);
	ft_center(map);
}

void	ft_change_height(t_fdf *map, int key)
{
	float	x;
	int		y;
	t_fdfpt	*point;

	x = map->point->abs;
	y = map->point->ord;
	if (key == U)
		map->height_coef += 0.5;
	if (key == D)
		map->height_coef -= 0.5;
	ft_data_handling(map);
	x = map->point->abs - x;
	y = map->point->ord - y;
	point = map->point;
	while (point)
	{
		point->abs -= x;
		point->ord -= y;
		point = point->next;
	}
	ft_center(map);
}

void	ft_view_two_dim(t_fdf *map)
{
	map->theta = 0;
	map->angle = 1;
	map->height_coef = 0;
	ft_data_handling(map);
}

void	ft_reset_view(t_fdf *map)
{
	map->multiplicator = 500 / (map->height + map->max_lenght) + 1;
	map->scale = 200;
	map->theta = 0.782993;
	map->height_coef = map->multiplicator + 1;
	if (map->point->color != 0)
		map->height_coef = 0;
	map->angle = 1.65;
	ft_data_handling(map);
	ft_center(map);
}

void	ft_change_zoom(t_fdf *map, int key)
{
	t_fdfpt	*pt;

	pt = map->point;
	if (key == PLUS)
	{
		while (pt)
		{
			pt->abs *= 1.008;
			pt->ord *= 1.008;
			pt = pt->next;
		}
	}
	if (key == MINUS)
	{
		while (pt)
		{
			pt->abs /= 1.008;
			pt->ord /= 1.008;
			pt = pt->next;
		}
	}
	ft_center(map);
}
