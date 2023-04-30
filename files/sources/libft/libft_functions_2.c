/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:28:38 by marvin            #+#    #+#             */
/*   Updated: 2023/03/10 19:28:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static char	*ft_atoi_color_2(const char *str, int i, char *result)
{
	int	y;

	y = 0;
	i++;
	if (!str[i])
		return (free(result), NULL);
	i++;
	if (!str[i])
		return (free(result), NULL);
	i++;
	if (!str[i])
		return (free(result), NULL);
	while (str[i])
	{
		result[y] = str[i];
		i++;
		y++;
	}
	result[y] = '\0';
	return (result);
}

char	*ft_atoi_color(const char *str)
{
	int		i;
	char	*result;

	if (!str || str[0] == '\0' || !(str[0] > '0' && str[0] < '9'))
		return (NULL);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	result = malloc(10);
	if (!result)
		return (NULL);
	if (str[i] == '\0' || str[0] == 5)
	{
		free (result);
		return (NULL);
	}
	return (ft_atoi_color_2(str, i, result));
}

static int	ft_fdf_base(char c)
{
	char	base_hex_min[16];
	int		i;

	ft_fdf_strlcpy(base_hex_min, "0123456789abcdef", 18);
	i = 0;
	while (base_hex_min[i] && c != base_hex_min[i])
		i++;
	return (i);
}

long	ft_putnbr_x(char *str)
{
	int	i;
	int	multi;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
		i++;
	i--;
	multi = 1;
	while (i > -1)
	{
		nb = nb + (ft_fdf_base(str[i]) * multi);
		multi *= 16;
		i--;
	}
	return (nb);
}
