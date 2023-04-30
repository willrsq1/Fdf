/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:32:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 09:09:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "../../mlx_linux/mlx.h"
# include "../sources/gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h> //open
# include <sys/stat.h> //open
# include <fcntl.h> //open
# include <stddef.h> //strlcpy
# include "X11/keysym.h"
# include <math.h> //math

typedef struct s_draw {
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;

}				t_draw;

typedef struct s_coords_draw {
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		height_0;
	int		height_1;
	long	color;
}				t_coord;

typedef struct s_data_img {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			win_width;
	int			win_height;
	float		max_height;
	int			endian;
	int			color;
}				t_data_img;

typedef struct s_data_point {
	float				abs;
	float				ord;
	float				height;
	long				color;
	float				first_abs;
	float				first_ord;
	float				first_height;
	int					line;
	int					column;
	struct s_data_point	*previous;
	struct s_data_point	*next;
}			t_fdfpt;

typedef struct s_list_map
{
	char		file_path[1000];
	int			fd;
	int			lenght;
	int			max_lenght;
	int			height;
	int			line_number;
	char		*line;
	int			**matrix;
	char		***colors;
	int			*lenght_tab;
	float		multiplicator;
	float		angle;
	float		height_coef;
	float		scale;
	int			win_w;
	int			win_height;
	t_fdfpt		*point;
	t_data_img	*img;
	void		*mlx;
	void		*mlx_win;
	char		**argv;
	float		theta;
}			t_fdf;

#endif