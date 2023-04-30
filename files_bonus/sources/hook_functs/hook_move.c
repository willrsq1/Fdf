/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:31 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 13:17:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_move(t_fdf *map, int key)
{
	if (key == UP_ARROW)
		ft_move_up(map);
	else if (key == LEFT_ARROW)
		ft_move_left(map);
	else if (key == DOWN_ARROW)
		ft_move_down(map);
	else if (key == RIGHT_ARROW)
		ft_move_right(map);
}

void	ft_move_up(t_fdf *map)
{
	t_fdfpt	*point;

	point = map->point;
	while (point)
	{
		point->ord -= 10;
		point = point->next;
	}
}

void	ft_move_left(t_fdf *map)
{
	t_fdfpt	*point;

	point = map->point;
	while (point)
	{
		point->abs -= 10;
		point = point->next;
	}
}

void	ft_move_down(t_fdf *map)
{
	t_fdfpt	*point;

	point = map->point;
	while (point)
	{
		point->ord += 10;
		point = point->next;
	}
}

void	ft_move_right(t_fdf *map)
{
	t_fdfpt	*point;

	point = map->point;
	while (point)
	{
		point->abs += 10;
		point = point->next;
	}
}
