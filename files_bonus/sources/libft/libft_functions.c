/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:24:14 by root              #+#    #+#             */
/*   Updated: 2023/03/10 19:28:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;
	int				i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result >= 2147483648 && sign == 1)
		return (-1);
	if (result > 2147483648 && sign == -1)
		return (0);
	return (result * sign);
}

void	ft_fdf_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_fdf_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(&str[ft_strlen((char *) s1)], s2, ft_strlen((char *)s2) + 1);
	return (str);
}

int	ft_fdf_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_fdf_stricmp(char *s1, char *s2, int nb)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && i < nb)
		i++;
	if (i == nb)
		return (1);
	return (0);
}
