/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fdf.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marvin <marvin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 12:32:22 by marvin			#+#	#+#			 */
/*   Updated: 2023/03/10 12:37:41 by marvin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_structs.h"
# include "fdf_keys.h"

/* ------------------------------ SOURCES ----------------------------------- */

/* ----- MAIN.C ----- */

int		main(int argc, char **argv);
int		ft_close(t_fdf *map);
void	mlx_main(t_fdf *map);

/* ----- MAIN_UTILS.C ----- */

void	main_init(t_fdf *map);
int		ft_fdf_free_exit(char *message, t_fdf *map);
void	ft_fdf_free_colors(t_fdf *map);
void	ft_fdf_free_matrix(int **matrix, t_fdf *map);
void	ft_fdf_free_points(t_fdfpt *point);

/* ------------------------------ HOOK_FUNCTS ------------------------------- */

			/* HOOK_ACTIONS_2.C */

void	ft_rotate_along_y(t_fdf *map);
void	ft_rotate_along_y_neg(t_fdf *map);
void	ft_change_file(t_fdf *map);
void	ft_change_file_p2(t_fdf *map);
void	ft_change_file_p3(t_fdf *map);

			/* HOOK_ACTIONS.C */

void	ft_translate_z(t_fdf *map, int key);
void	ft_change_height(t_fdf *map, int key);
void	ft_view_two_dim(t_fdf *map);
void	ft_reset_view(t_fdf *map);
void	ft_change_zoom(t_fdf *map, int key);

			/* HOOK_MOVE.C */

void	ft_move(t_fdf *map, int key);
void	ft_move_up(t_fdf *map);
void	ft_move_left(t_fdf *map);
void	ft_move_down(t_fdf *map);
void	ft_move_right(t_fdf *map);

			/* HOOKS.C */

int		ft_key_hook(int key, t_fdf *map);
void	ft_expose_hook(t_fdf *map);
void	ft_center(t_fdf *map);

/* ------------------------------ IMAGE ------------------------------------- */

			/* DRAWING_FUNCTS.C */

t_coord	*ft_coords(t_fdfpt *point_a, t_fdfpt *point_b, t_fdf *map);
int		ft_get_color(t_coord *coords, float max_height, int color);
void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color);
void	draw(t_coord *coords, t_data_img *data);
void	ft_do_draw_loop(t_data_img *data, t_coord *coords, t_draw plot);

			/* POINTS_AND_LINES.C */

void	ft_connect_the_points(t_data_img *data, t_fdf *map);
void	ft_data_point_change(t_fdfpt *point, t_fdf *map);
void	ft_data_handling(t_fdf *map);
void	ft_do_multiplicator(t_fdf *map);
void	ft_connect_verticaly(t_fdfpt *point, t_data_img *data, t_fdf *map);

/* ------------------------------ LIBFT ------------------------------------- */

			/* FT_SPLIT_FDF.C */

char	**ft_split(char const *s, char c);

			/* LIBFT_FUNCTIONS_2.C */

char	*ft_atoi_color(const char *str);
void	ft_fdf_putchar(char c);
long	ft_putnbr_x(char *str);

			/* LIBFT_FUNCTIONS.C */

int		ft_atoi(const char *str);
char	*ft_fdf_strjoin(char const *s1, char const *s2);
void	ft_fdf_strlcpy(char *dest, const char *src, size_t size);
int		ft_fdf_strlen(char *s);
int		ft_fdf_stricmp(char *s1, char *s2, int nb);

/* ------------------------------ MAP_CREATION ------------------------------ */

			/* MAP_IN_MATRIC.C */

void	ft_fdf_create_matrix(t_fdf *map);
void	ft_fill_the_matrix(t_fdf *map);
void	ft_fill_a_line(t_fdf *map);
void	ft_fdf_get_height(t_fdf *map);
int		ft_fdf_lenght_of_this_line(char *line, t_fdf *map);

			/* MAP_IN_STRUCTS.C */

void	ft_convert_matrix_to_structs(t_fdf *map);
t_fdfpt	*ft_initiate_data_point(t_fdf *map);
t_fdfpt	*ft_add_point_struct(t_fdfpt *point, int i, int y, t_fdf *map);

/* ------------------------------ HOOKS_NOT_BONUS --------------------------- */

int		ft_key_hook_not_bonus(int key, t_fdf *map);
void	ft_expose_hook_not_bonus(t_fdf *map);

#endif