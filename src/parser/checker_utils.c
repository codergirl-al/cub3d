/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:11 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 02:38:19 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_ending(char *filename)
{
	char	*d_pos;

	if (!filename)
		return (0);
	d_pos = ft_strrchr(filename, '.');
	if (d_pos && !ft_strcmp(d_pos, ".cub\0"))
		return (1);
	return (0);
}

size_t	ft_arrlen(char **arr)
{
	size_t	it;

	it = -1;
	if (arr)
		while (arr[++it])
			;
	return (it);
}

void	ft_arrfree(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_is_number(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_digit_check(char *color)
{
	int	parsed;

	if (!ft_is_number(color))
		return (-1);
	parsed = ft_atoi(color);
	if (parsed < 0 || parsed > 255)
		return (-1);
	return (parsed);
}
